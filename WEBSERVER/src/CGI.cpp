#include "../include/CGI.hpp"
#include "../include/Response.hpp"

CGI::CGI(Request *cgi_req_pt)
{
    this->cgi_req_pt = cgi_req_pt;
}

CGI::~CGI() {}

char **env_get(Request *cgi_req_pt)
{
    char **env = new char *[13];
    stringstream ss;

    string path = cgi_req_pt->get_req_param("path");
    string query = cgi_req_pt->find_query(path);
    cgi_req_pt->erase_string(path, "?" + query);
    ss << query.length();

    if (cgi_req_pt->get_req_param("Content-Type") == "")
        env[0] = strdup("CONTENT_TYPE=application/x-www-form-urlencoded");
    else
        env[0] = strdup(("CONTENT_TYPE=" + cgi_req_pt->get_req_param("Content-Type")).c_str());
    env[1] = strdup(("REQUEST_METHOD=" + cgi_req_pt->get_req_param("method")).c_str());
    env[2] = strdup(("QUERY_STRING=" + query).c_str());
    env[3] = strdup(("CONTENT_LENGTH=" + ss.str()).c_str());
    env[4] = strdup("REDIRECT_STATUS=200");
    env[5] = strdup(("SCRIPT_FILENAME=" + cgi_req_pt->parser->get_root() + path).c_str());
    env[6] = strdup("SERVER_PROTOCOL=HTTP/1.1");
    env[7] = strdup(("REMOTE_HOST=" + cgi_req_pt->get_req_param("Host")).c_str());
    env[8] = strdup(("HTTP_ACCEPT=" + cgi_req_pt->get_req_param("Accept")).c_str());
    env[9] = strdup(("PATH_INFO=" + path).c_str());
    env[10] = strdup(("GATEWAY_INTERFACE=CGI/1.1"));
    env[11] = strdup(("CGI_GET_DATA=" + query).c_str());
    ;
    env[12] = NULL;
    return env;
}

char **env_post(Request *cgi_req_pt)
{
    char **env = new char *[13];
    stringstream ss;
    ss << atoi(cgi_req_pt->get_req_param("Content-Length").c_str());
    env[0] = strdup(("CONTENT_TYPE=" + cgi_req_pt->get_req_param("Content-Type")).c_str());
    env[1] = strdup(("REQUEST_METHOD=" + cgi_req_pt->get_req_param("method")).c_str());
    env[2] = strdup(("QUERY_STRING=" + cgi_req_pt->get_req_param("body")).c_str());
    env[3] = strdup(("CONTENT_LENGTH=" + ss.str()).c_str());
    env[4] = strdup("REDIRECT_STATUS=200");
    env[5] = strdup(("SCRIPT_FILENAME=" + cgi_req_pt->parser->get_root() + cgi_req_pt->get_req_param("path")).c_str());
    env[6] = strdup("SERVER_PROTOCOL=HTTP/1.1");
    env[7] = strdup(("REMOTE_HOST=" + cgi_req_pt->get_req_param("Host")).c_str());
    env[8] = strdup(("HTTP_ACCEPT=" + cgi_req_pt->get_req_param("Accept")).c_str());
    env[9] = strdup(("PATH_INFO=" + cgi_req_pt->get_req_param("path")).c_str());
    env[10] = strdup(("GATEWAY_INTERFACE=CGI/1.1"));
    env[11] = strdup(("CGI_POST_DATA=" + cgi_req_pt->get_req_param("body")).c_str());
    ;
    env[12] = NULL;
    return env;
}

char **CGI::cgi_env()
{
    if (cgi_req_pt->get_req_param("method") == "POST")
        return env_post(cgi_req_pt);
    else
        return env_get(cgi_req_pt);
}

char **cgi_get_args(Request *cgi_req_pt)
{
    char **args = new char *[3];
    string path = cgi_req_pt->get_req_param("path");
    string query = cgi_req_pt->find_query(path);
    cgi_req_pt->erase_string(path, "?" + query);

#ifdef __APPLE__
    args[0] = strdup(cgi_req_pt->parser->get_conf_param("server", "mac_php_cgi").c_str());
#else
    args[0] = strdup(cgi_req_pt->parser->get_conf_param("server", "php_cgi_bin_path").c_str());
#endif
    args[1] = strdup((cgi_req_pt->parser->get_root() + path).c_str());
    args[2] = NULL;
    return args;
}

char **cgi_post_args(Request *cgi_req_pt)
{
    char **args = new char *[3];
#ifdef __APPLE__
    args[0] = strdup(cgi_req_pt->parser->get_conf_param("server", "mac_php_cgi").c_str());
#else
    args[0] = strdup(cgi_req_pt->parser->get_conf_param("server", "php_cgi_bin_path").c_str());
#endif
    args[1] = strdup((cgi_req_pt->parser->get_root() + cgi_req_pt->get_req_param("path")).c_str());
    args[2] = NULL;
    return args;
}

char **CGI::cgi_args()
{
    if (cgi_req_pt->get_req_param("method") == "POST")
        return cgi_post_args(cgi_req_pt);
    else
        return cgi_get_args(cgi_req_pt);
}

void print_env(char **env)
{
    for (int i = 0; env[i] != NULL; i++)
    {
        printf("%s\n", env[i]);
    }
}

string CGI::throw_server_error()
{
    return Response::get_response2(500, cgi_req_pt->parser->get_root() + cgi_req_pt->parser->get_conf_param("server", "500"));
}

string CGI::exec_cgi()
{
    char **env = cgi_env();
    char **args = cgi_args();

    // cout << endl;
    // print_env(env);
    // cout << endl;
    // print_env(args);
    // cout << endl;

    int child_to_parent_pipefd[2];
    int parent_to_child_pipefd[2];

    if (pipe(child_to_parent_pipefd) == -1 || pipe(parent_to_child_pipefd) == -1)
    {
        perror("pipe");
        return throw_server_error();
    }

    pid_t pid = fork();
    if (pid == -1)
    {
        perror("fork");
        return throw_server_error();
    }
    else if (pid == 0)
    {
        close(parent_to_child_pipefd[1]);
        // redirect stdin to the pipe
        dup2(parent_to_child_pipefd[0], STDIN_FILENO);
        // close the read end of the pipe
        close(parent_to_child_pipefd[0]);
        // then the parent will receive the output of the php-cgi binary
        close(child_to_parent_pipefd[0]);
        // redirect stdout to the pipe
        dup2(child_to_parent_pipefd[1], STDOUT_FILENO);
        // close the write end of the pipe
        close(child_to_parent_pipefd[1]);
// printf("execve: %s\n", requestedPath);
#ifdef __APPLE__
        execve(cgi_req_pt->parser->get_conf_param("server", "mac_php_cgi").c_str(), args, env);
#else
        execve(cgi_req_pt->parser->get_conf_param("server", "php_cgi_bin_path").c_str(), args, env);
#endif
        perror("execve");
        exit(EXIT_FAILURE);
    }
    else
    {
        // send the cgi_req_pt body to the child
        close(parent_to_child_pipefd[0]);
        if (cgi_req_pt->get_req_param("method") == "POST")
        {
            string content = cgi_req_pt->get_req_param("body");
            if (write(parent_to_child_pipefd[1], content.c_str(), content.length()) == -1)
            {
                perror("write");
            }
        }
        close(parent_to_child_pipefd[1]);
        // read the response from the child
        close(child_to_parent_pipefd[1]);
        char buffer[IO_CHUNK_SIZE];
        int bytesRead = 0;
        while ((bytesRead = read(child_to_parent_pipefd[0], buffer, IO_CHUNK_SIZE)) > 0)
            cgi_response += string(buffer, bytesRead);

        close(child_to_parent_pipefd[0]);
        if (bytesRead == -1)
        {
            perror("read");
            return throw_server_error();
        }
    }
    return parse_cgi_response();
}

string CGI::parse_cgi_response()
{
    string header;
    string body;
    char timeBuffer[80];
    stringstream response;
    time_t now = time(0);
    tm *timeinfo = gmtime(&now);
    strftime(timeBuffer, 80, "%a, %d %b %Y %H:%M:%S GMT", timeinfo);

    header = cgi_response.substr(0, cgi_response.find("\r\n\r\n"));
    body = cgi_response.substr(cgi_response.find("\r\n\r\n") + 4, cgi_response.length());

    if (header.find("Status") != string::npos)
        response << "HTTP/1.1 " << header.substr(header.find("Status") + 8, header.find("\r\n") - header.find("Status") - 8) << "\r\n";
    else
        response << "HTTP/1.1 200 OK" << "\r\n";
    response << "Date: " << timeBuffer << "\r\n";
    response << "Server: MyServer\r\n";
    if (header.find("Content-type") != string::npos)
        response << "Content-Type: " << header.substr(header.find("Content-type") + 14, header.find("\r\n") - header.find("Content-type") - 14) << "\r\n";
    else
        response << "Content-Type: text/html\r\n";
    response << "Content-Length: " << body.length() << "\r\n";
    response << "\r\n";
    response << body;

    return response.str();
}