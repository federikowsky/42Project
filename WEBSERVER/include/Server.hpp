#ifndef __SERVER_HPP__
#define __SERVER_HPP__

#include <stdio.h> 
#include <netdb.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> // read(), write(), close()
#include <sstream>
#include <fcntl.h>
#include <ctime>
#include <map>
#include <netinet/in.h> 
#include <sys/socket.h> 
#include <sys/types.h> 
#include <arpa/inet.h>
#include <algorithm>
#include <vector>

#include "Parser.hpp"


#define MAX_BUF 8192
#define MAX_PENDING 1000
#define TIMEOUT_LIMIT 60 // seconds
#define SA struct sockaddr 

using namespace std;

class Server
{
private:
    int i, rc, reusable;
	int sockfd, max_sd, new_sd;
	int desc_ready, end_server;
	int close_conn;
	struct sockaddr_in servaddr;
	struct timeval timeout;
	fd_set master_set, working_set;


    string config_file_content;
    vector<int> sockets;
    map<int, time_t> pending_connections;
    map<int, Parser> sockfd_map;
    map<int, int> client_map;

    void handle_new_connection(int i);
    void close_pending_connections();
    int send_back(int connfd, string sreq);

    void set_socket(string config_block);
    string saveconf(const char *file_name);
    vector<string> server_blocks(string const &file_content);
    int is_socket(int fd);

public:
    Server(const char *config_file);
    ~Server();
    int run();
    void handle_request(int connfd);
};

#endif
