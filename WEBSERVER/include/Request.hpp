#ifndef __REQUEST_HPP__
#define __REQUEST_HPP__

#include <iostream>
#include <sstream>
#include <sys/stat.h>
#include <dirent.h>

#include "Parser.hpp"

using namespace std;

class Request
{
private:
	string Post();
	string Get();
	string Delete();
	string Options();
	bool file_exist(const string filename);
	string get_response(int code, string path);
	string clean_req_header(string param);
	string get_location(string path);
	string get_dir_content(string dir);
	string list_response(string path);
	string default_action();

public:
	Parser *parser;
	string req;
	Request(string req);
	void set_parser(Parser *parser);
	string req_handler(string method);
	string get_req_param(string key);
	void erase_string(string& path, const string& query);
	string find_query(string path);

};

#endif
