#ifndef __CGI_HPP__
#define __CGI_HPP__

#include <iostream>
#include <sstream>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <cstring>
#include <map>
#include <stdlib.h>

#include "Logger.hpp"
#include "Request.hpp"

using namespace std;

#define IO_CHUNK_SIZE 4096

class CGI
{
private:
    Request *cgi_req_pt;
    string cgi_response;
    char **cgi_env();
    char **cgi_args();
    string throw_server_error();
    string parse_cgi_response();

public:
    CGI(Request *cgi_req_pt);
    ~CGI();
    string exec_cgi();
};

#endif
