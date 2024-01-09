#ifndef PARSER_HPP
#define PARSER_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>

using namespace std;

class Parser
{
private:
    string file_content;
    string root;

    string clean(string const &s);
    string saveconf(const char *file_name);

public:
    ~Parser();
    Parser();
    string get_root();
    string get_file_content();
    int set_file_content(string file_content);
    string get_key_conf(string const &line, string key);
    string get_conf_param(string path, string key_conf);
    int is_location_empty(string location);
    string entry_conf_exist(string location, string const key);
    int location_exist(string location);
};

#endif
