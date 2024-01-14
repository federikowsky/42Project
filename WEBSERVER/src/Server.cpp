#include "../include/Server.hpp"
#include "../include/Request.hpp"
#include "../include/Logger.hpp"

using namespace std;

// curl -v --parallel http://192.168.205.138:9043 http://192.168.205.138:9042 http://192.168.205.138:9042 http://192.168.205.138:9042 http://192.168.205.138:9042 http://192.168.205.138:9042 http://192.168.205.138:9042 http://192.168.205.138:9042 http://192.168.205.138:9042 http://192.168.205.138:9042 http://192.168.205.138:9042 http://192.168.205.138:9042 http://192.168.205.138:9042 http://192.168.205.138:9042 http://192.168.205.138:9042 http://192.168.205.138:9042 http://192.168.205.138:9042 http://192.168.205.138:9042 http://192.168.205.138:9042 http://192.168.205.138:9042 http://192.168.205.138:9042 http://192.168.205.138:9042 http://192.168.205.138:9042 http://192.168.205.138:9042 http://192.168.205.138:9042 http://192.168.205.138:9042 http://192.168.205.138:9042 http://192.168.205.138:9042 http://192.168.205.138:9042 http://192.168.205.138:9042 http://192.168.205.138:9042 http://192.168.205.138:9042 http://192.168.205.138:9042 http://192.168.205.138:9042 http://192.168.205.138:9042

Server::Server(const char *config_file)
{
	this->i = this->rc = this->sockfd = this->max_sd =
		this->new_sd = this->desc_ready = this->end_server =
			this->close_conn = 0;
	this->reusable = 1;
	if ((config_file_content = saveconf(config_file)) == "")
		exit(EXIT_FAILURE);
}

Server::~Server()
{
	close(sockfd);
}

std::vector<std::string> Server::server_blocks(string const &file_content)
{
	std::istringstream file_stream(file_content);
	std::string line;

	std::vector<std::string> server_blocks;
	while (std::getline(file_stream, line))
	{
		// Ignorare le linee di commento e vuote
		if (!line.empty() && line.find('#') == string::npos)
		{
			// Trovato un inizio di blocco server
			if (line.find("server {") != string::npos)
			{
				std::string server_block = "server {\n";
				int brace_count = 1; // Contatore per tracciare le graffe aperte e chiuse

				// Continua a leggere fino a quando non si trovano tutte le graffe chiuse
				while (brace_count > 0 && std::getline(file_stream, line))
				{
					if (!line.empty() && line.find('#') == string::npos)
					{
						server_block += line + "\n";

						// Aggiorna il contatore delle graffe
						brace_count += std::count(line.begin(), line.end(), '{');
						brace_count -= std::count(line.begin(), line.end(), '}');
					}
				}

				server_blocks.push_back(server_block);
			}
		}
	}
	return server_blocks;
}

int Server::is_socket(int fd)
{
	std::vector<int>::const_iterator it = std::find(sockets.begin(), sockets.end(), fd);

	if (it != sockets.end())
		return 1;
	else
		return 0;
}

string Server::saveconf(const char *file_name)
{
	stringstream buffer;
	ifstream file(file_name);
	if (!file.is_open())
	{
		logMsg(RED, "[!] (Server) Errore nell'apertura del file: %s", file_name);
		return "";
	}

	buffer << file.rdbuf();
	file.close();
	config_file_content = buffer.str();

	return config_file_content;
}

int Server::send_back(int connfd, string sreq)
{
	Request Burp(sreq);
	Burp.set_parser(&sockfd_map[client_map[connfd]]);

	int rc;
	// Data was received
	if (Burp.get_req_param("Connection") == "keep-alive")
		close_conn = 0;

	logMsg(YELLOW, "[>>] Request [<<]\n%s\n", Burp.req.c_str());

	string method = Burp.get_req_param("method");
	string response = Burp.req_handler(method);
	logMsg(CYAN, "[<<] Response [>>]\n%s\n", response.c_str());
	rc = send(connfd, response.c_str(), response.length(), 0);
	if (rc <= 0)
	{
		logMsg(RED, "[!] send() failed");
		close_conn = 1;
	}
	return rc;
}

void Server::handle_request(int connfd)
{
	char buffer[MAX_BUF];
	bzero(buffer, MAX_BUF);

	close_conn = 0;
	do
	{
		rc = recv(connfd, buffer, sizeof(buffer), MSG_DONTWAIT);
		if (rc < 0)
		{
			// EWOULDBLOCK error code means we have read all the data
			// from the socket and are done with the recv() call.
			if (errno != EWOULDBLOCK)
			{
				logMsg(RED, "[!] recv() failed");
				close_conn = 1;
			}
			break;
		}
		// Check connection closed by the client
		if (rc == 0)
		{
			// logMsg(MAGENTA, "[-] Connection %d closed\n", connfd);
			close_conn = 1;
			break;
		}
	} while (1);

	// If the close_conn flag was turned on, we need
	// to clean up this active connection.  This
	// clean up process includes removing the
	// descriptor from the master set and
	// determining the new maximum descriptor value
	// based on the bits that are still turned on in
	// the master set.
	if (close_conn)
	{
		close(i);
		logMsg(MAGENTA, "[-] Connection %d closed\n", i);
		FD_CLR(i, &master_set);
		if (pending_connections.find(i) != pending_connections.end())
		{
			pending_connections.erase(i);
		}
		if (i == max_sd)
		{
			while (FD_ISSET(max_sd, &master_set) == 0)
				max_sd -= 1;
		}
		return;
	}

	logMsg(YELLOW, "Received Request from client %d", i);
	string sreq(buffer);
	rc = send_back(connfd, sreq);
}

void Server::handle_new_connection(int sockfd)
{
	// Accept all incoming connections that are
	// queued up on the listening socket before we
	// loop back and call select again.
	do
	{
		// Accept each incoming connection.  If
		// accept fails with EWOULDBLOCK, then we
		// have accepted all of them.  Any other
		// failure on accept will cause us to end the
		// server.
		new_sd = accept(sockfd, NULL, NULL);
		client_map[new_sd] = sockfd;
		if (new_sd < 0)
		{
			if (errno != EWOULDBLOCK)
			{
				logMsg(RED, "[!] accept() failed");
				end_server = 1;
			}
			break;
		}

		// Add the new incoming connection to the
		// master read set
		pending_connections[new_sd] = time(NULL);
		logMsg(GREEN, "\nNew incoming connection - Assigned socket %d", new_sd);
		FD_SET(new_sd, &master_set);
		if (new_sd > max_sd)
			max_sd = new_sd;

		// Loop back up and accept another incoming
		// connection
	} while (new_sd != -1);
}

void Server::close_pending_connections()
{
	// Check to see if the time out expired. If so, close the connection
	time_t now = time(NULL);
	map<int, time_t>::iterator it = pending_connections.begin();

	while (it != pending_connections.end())
	{
		map<int, time_t>::iterator erase_it = it;
		++it;
		if (now - erase_it->second >= TIMEOUT_LIMIT)
		{
			logMsg(RED, "[!] Connection %d timed out, closing...", erase_it->first);
			close(erase_it->first);
			client_map.erase(erase_it->first);
			FD_CLR(erase_it->first, &master_set);

			if (erase_it->first == max_sd)
			{
				while (FD_ISSET(max_sd, &master_set) == 0)
					max_sd -= 1;
			}

			pending_connections.erase(erase_it);
		}
	}
}

void Server::set_socket(string config_block)
{
	Parser parser;
	int sockfd;
	unsigned int port;
	// socket create and verification
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
	{
		logMsg(RED, "[!] socket() failed");
		exit(-1);
	}

	parser.set_file_content(config_block);
	sockfd_map[sockfd] = parser;
	port = atoi(parser.get_conf_param("server", "listen").c_str());

	// set socket to be reusable
	if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &reusable, sizeof(reusable)) == -1)
	{
		logMsg(RED, "[!] setsockopt() failed");
		close(sockfd);
		exit(-1);
	}

	// set socket to non-blocking
	rc = fcntl(sockfd, F_SETFL, O_NONBLOCK);
	if (rc < 0)
	{
		logMsg(RED, "[!] fcntl() failed");
		close(sockfd);
		exit(-1);
	}

	// Binding newly created socket to given IP and verification
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	if (parser.get_conf_param("server", "host") == "localhost")
		// servaddr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
		servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	else
		servaddr.sin_addr.s_addr = inet_addr(parser.get_conf_param("server", "host").c_str());

	if (servaddr.sin_addr.s_addr == INADDR_NONE)
	{
		logMsg(RED, "[!] inet_addr() failed");
		exit(-1);
	}
	servaddr.sin_port = htons(port);

	if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
	{
		logMsg(RED, "[!] bind() failed");
		close(sockfd);
		exit(-1);
	}

	// Now server is ready to listen and verification
	if (listen(sockfd, MAX_PENDING) < 0)
	{
		logMsg(RED, "[!] listen() failed");
		close(sockfd);
		exit(-1);
	}

	if (!strcmp(inet_ntoa(servaddr.sin_addr), "0.0.0.0"))
		logMsg(ORANGE, "\tURL : http://localhost:%d", ntohs(servaddr.sin_port));
	else
		logMsg(ORANGE, "\tURL : http://%s:%d", inet_ntoa(servaddr.sin_addr), ntohs(servaddr.sin_port));

	// initialize the master fd_set
	max_sd = sockfd;
	FD_SET(sockfd, &master_set);

	sockets.push_back(sockfd);
}

int Server::run()
{
	vector<string> blocks = server_blocks(config_file_content);

	logMsg(ORANGE, "[+] Server listening on {");

	// Initialize the socket and master fd_set
	FD_ZERO(&master_set);
	for (unsigned long int i = 0; i < blocks.size(); ++i)
		set_socket(blocks[i]);

	// Loop waiting for incoming connects or for incoming data
	// on any of the connected sockets.
	logMsg(ORANGE, "    } with Timeout %d sec for inactive connections", TIMEOUT_LIMIT);

	do
	{
		// Initialize the timeval struct to TIMEOUT_LIMIT minutes.
		timeout.tv_sec = TIMEOUT_LIMIT;
		timeout.tv_usec = 0;

		// Copy the master fd_set over to the working fd_set.
		memcpy(&working_set, &master_set, sizeof(master_set));

		// Call select() and wait 5 minutes for it to complete.
		rc = select(max_sd + 1, &working_set, NULL, NULL, &timeout);

		// Check to see if the select call failed.
		if (rc < 0)
		{
			logMsg(RED, "[!] select() failed");
			break;
		}

		// Check to see if the TIMEOUT_LIMIT minute time out expired.
		if (rc == 0)
		{
			close_pending_connections();
			continue;
		}

		// One or more descriptors are readable.  Need to
		// determine which ones they are.
		desc_ready = rc;
		for (i = 0; i <= max_sd && desc_ready > 0; ++i)
		{
			// Check to see if this descriptor is ready
			if (FD_ISSET(i, &working_set))
			{
				// A descriptor was found that was readable - one
				// less has to be looked for.  This is being done
				// so that we can stop looking at the working set
				// once we have found all of the descriptors that
				// were ready.
				desc_ready -= 1;

				// Check to see if this is the listening socket
				if (is_socket(i))
					handle_new_connection(i);

				// This is not the listening socket, therefore an
				// existing connection must be readable
				else
					handle_request(i);
				// End of existing connection is readable
			} // End of if (FD_ISSET(i, &working_set))
		}	  // End of loop through selectable descriptors
	} while (end_server == 0);

	// Clean up all of the sockets that are open
	for (i = 0; i <= max_sd; ++i)
	{
		if (FD_ISSET(i, &master_set))
			close(i);
	}

	return 0;
}
