#ifndef __RESPONSE_HPP__
#define __RESPONSE_HPP__

#include <iostream>
#include <sstream>
#include <string>
#include <map>

using namespace std;

class Response
{
private:
    std::map<std::string, std::string> mime_types;
    std::map<int, std::string> http_codes;
    int status_code;
    string file_name;
	string http_value;

    string get_http_code_msg();
    string get_content_type(string extension);
    string get_file_ext(string path);
    string get_file_content(const char *file_name);

public:
    Response();
    ~Response();
    string get_http_response();
	static string get_response2(int code, string path);
    void set_header(string key, string value);
    void set_response(int code, string file);
};

#endif