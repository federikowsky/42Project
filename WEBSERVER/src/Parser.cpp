#include "../include/Parser.hpp"
#include "../include/Logger.hpp"

Parser::Parser()
{
    this->root = get_conf_param("server", "root");
}

Parser::~Parser() {}

string Parser::get_file_content()
{
    return this->file_content;
}

string Parser::get_root()
{
    return this->root;
}

int Parser::set_file_content(string file_content)
{
    this->file_content = file_content;
    this->root = get_conf_param("server", "root");
    return 0;
}

string Parser::saveconf(const char *file_name)
{
    stringstream buffer;
    ifstream file(file_name);
    if (!file.is_open())
    {
        logMsg(RED, "\n[!] (Parser) Errore nell'apertura del file: %s\n", file_name);
        return "";
    }

    buffer << file.rdbuf();
    file.close();
    file_content = buffer.str();

    return file_content;
}

string Parser::clean(string const &s)
{
    string::size_type pos = min(s.find_first_of(";") - 1, s.find_first_of("{}"));
    size_t start = s.find_first_not_of(" \t\n");
    if (!s.empty() && s[start] == '#')
        return "";
    if (pos <= s.length())
        return s.substr(start, pos - start + 1);
    else
        return s;
}

int Parser::is_location_empty(string location)
{
    if (entry_conf_exist(location, "*") == "")
        return 1;
    return 0;
}

int Parser::location_exist(string location)
{
    if (entry_conf_exist(location, "?") == "")
        return 0;
    return 1;
}

string Parser::get_key_conf(string const &line, string key)
{
    string key_conf;
    size_t start = 0;
    size_t space_pos = line.find(' ');
    while ((key_conf = line.substr(start, space_pos - start)) != key)
    {
        start = space_pos + 1;
        space_pos = line.find(' ', start);
        if (space_pos == string::npos)
            return "";
    }
    size_t valueStart = line.find_first_not_of(' ', space_pos);
    string value = line.substr(valueStart);
    size_t valueEnd = value.find_last_not_of(" ;\t\r\n");
    value = value.substr(0, valueEnd + 1);
    return value;
}

string Parser::entry_conf_exist(string location, string const key)
{
    string temp;
    string s;
    int brackets = 0;
    if (location != "server")
        location = "location " + location;
    location = location + " {";
    if (file_content != "")
    {
        stringstream filestream(file_content);
        while (getline(filestream, temp))
        {
            temp = clean(temp);
            // the "*" key used to check if the location is empty, if not return the first value
            if (key == "*" && (temp != "" && temp != "}") && brackets)
                return temp;
            // the "?" key used to check if the location exist
            if (temp == location && key == "?")
                return temp;
            
            if (temp == location)
                ++brackets;
            if (brackets == 1 && temp.find(key) != string::npos)
                return temp.substr(temp.find(key), temp.find(key) + key.length() + 1);
            if (temp == "}" && brackets)
                --brackets;
        }
    }
    return "";
}

string Parser::get_conf_param(string path, string key_conf)
{
    string temp;
    string s;
    int brackets = 0;
    if (path != "server")
        path = "location " + path;
    path = path + " {";
    if (file_content != "")
    {
        stringstream filestream(file_content);
        while (getline(filestream, temp))
        {
            temp = clean(temp);
            if (temp == path)
                ++brackets;
            if (brackets == 1 && (s = get_key_conf(temp, key_conf)) != "")
                return s;
            if (temp == "}" && brackets)
                --brackets;
        }
    }
    return "";
}
