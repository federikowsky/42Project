#include "../include/Request.hpp"
#include "../include/Logger.hpp"
#include "../include/Response.hpp"
#include "../include/CGI.hpp"

using namespace std;

Request::Request(string req)
{
    this->req = req;
}

void Request::set_parser(Parser *parser)
{
    this->parser = parser;
}

string Request::find_query(string path)
{
    if (path.find("?") != string::npos)
        return path.substr(path.find("?") + 1);
    return "";
}

void Request::erase_string(string& path, const string& query)
{
    size_t pos = path.find(query);

    if (pos != string::npos)
    {
        path.erase(pos, query.length());

        if (pos > 0 && (path[pos - 1] == '?' || path[pos - 1] == '&'))
            path.erase(pos - 1, 1);

        if (path.length() > pos && path[pos] == '&')
            path.erase(pos, 1);
    }
}

string Request::clean_req_header(string param)
{
    // elminia tutti gli spazi bianchi e i tab all'inizio e alla fine della stringa param
    param.erase(0, param.find_first_not_of(" \r\t\n"));
    param.erase(param.find_last_not_of(" \r\t\n") + 1);

    // elimina tutti gli spazi bianchi e i tab doppi
    size_t pos = 0;
    while ((pos = param.find("  ")) != string::npos)
        param.erase(pos, 1);

    return param;
}

string Request::get_location(string path)
{
    size_t last_slash = path.find_last_of("/");
    size_t question_mark;
    
    // Controllo se ci sono slash nel percorso
    if (last_slash != string::npos)
    {
        if (last_slash == 0 && path.find('.') != string::npos)
            return "/"; 
        else if ((question_mark = path.find_last_of("?")) != string::npos)
            return path.substr(0, question_mark);
        else if (path.find('.') == string::npos)
            return path;
        else
            return path.substr(0, last_slash + 1);
    }
    return path;
}

string Request::get_req_param(string key)
{
    string temp;
    string method;
    string path;
    string version;
    size_t body_start;
    stringstream req_stream(req);

    getline(req_stream, method, ' ');
    getline(req_stream, path, ' ');
    getline(req_stream, version, '\n');

    if (key == "method")
        return method;
    if (key == "path")
        return path;
    if (key == "version")
        return version;
    if (key == "body" && (body_start = req.find("\r\n\r\n")) != string::npos)
        return clean_req_header(req.substr(body_start + 4));
    while (getline(req_stream, temp))
    {
        if (temp.find(key) != string::npos)
            return clean_req_header(temp.substr(temp.find(key) + key.length() + 2));
    }
    return "";
}

string Request::get_dir_content(string dir)
{
    stringstream response;
    DIR *dp;
    struct dirent *dirp;
    string path = dir;
    string relink;

    size_t pos = path.find(parser->get_root());

    // Se x è presente in s, rimuovi x da s
    if (pos != string::npos)
        path.erase(pos, parser->get_root().length());

    if ((dp = opendir(dir.c_str())) == NULL)
    {
        logMsg(RED, "\n[!] (Response) Errore nell'apertura della directory: %s\n", dir.c_str());
        return "";
    }

    response << "<!DOCTYPE html>\n";
    response << "<html>\n";
    response << "<head>\n";
    response << "<title>Directory listing for " << dir << "</title>\n";
    response << "</head>\n";
    response << "<body>\n";
    response << "<h2>Directory listing for " << dir << "</h2>\n";
    response << "<hr>\n";
    while ((dirp = readdir(dp)) != NULL)
    {
        relink = "http://" + get_req_param("Host") + path + dirp->d_name;
        if (dirp->d_type == DT_DIR)
            relink += "/";
        response << "<a href=\"" << relink << "\">" << dirp->d_name << "</a><br>\n";
    }
    response << "</body>\n";
    response << "</html>\n";
    closedir(dp);

    return response.str();
}

string Request::list_response(string body)
{
    stringstream response;
    char timeBuffer[80];
    time_t now = time(0);
    tm *timeinfo = gmtime(&now);
    strftime(timeBuffer, 80, "%a, %d %b %Y %H:%M:%S GMT", timeinfo);

    response << "HTTP/1.1 200 OK"
             << "\r\n";
    response << "Date: " << timeBuffer << "\r\n";
    response << "Server: MyServer\r\n";
    response << "Content-Type: text/html\r\n";
    response << "Content-Length: " << body.length() << "\r\n";
    response << "\r\n";
    response << body;

    return response.str();
}

bool Request::file_exist(const string filename)
{
    struct stat buffer;
    return (stat(filename.c_str(), &buffer) == 0);
}

string Request::get_response(int code, string path)
{
    Response response;
    if (code == 302)
    {
        response.set_response(code, parser->get_root() + "/redirect/redirect.html");
        response.set_header("Location", path);
    }
    else
        response.set_response(code, parser->get_root() + path);
    return response.get_http_response();
}

string Request::default_action()
{
    string host = get_req_param("Host");
    return get_response(302, "http://" + host + parser->get_conf_param("server", "default"));
}

string Request::req_handler(string method)
{
    string (Request::*command[4])(void) = {&Request::Post, &Request::Get, &Request::Delete, &Request::Options};
    string commands[4] = {"POST", "GET", "DELETE", "OPTIONS"};
    int index = -1;

    if (get_req_param("body").length() > static_cast<unsigned long int>(atol(parser->get_conf_param("server", "body_size").c_str())))
        return get_response(413, parser->get_conf_param("server", "413"));

    for (int i = 0; i < 4; i++)
    {
        if (method == commands[i])
        {
            index = i;
            break;
        }
    }
    switch (index)
    {
    case 0:
        return (this->*command[index])();
        break;
    case 1:
        return (this->*command[index])();
        break;
    case 2:
        return (this->*command[index])();
        break;
    case 3:
        return (this->*command[index])();
        break;
    default:
        return get_response(405, parser->get_conf_param("server", "405"));
    }
}

string Request::Post()
{
    logMsg(BLUE, "[Post]");
    string query = get_req_param("body");
    CGI cgi(this);
    return cgi.exec_cgi();
}

string Request::Get()
{
    logMsg(BLUE, "[Get]");
    string path = get_req_param("path");
    string query = find_query(path);
    erase_string(path, "?" + query);
    string location = get_location(path);
    string file_requested = path;

    // cout << "path: " << path << endl;
    // cout << "query: " << query << endl;
    // cout << "location: " << location << endl;

    if (!parser->location_exist(location))
        return get_response(404, parser->get_conf_param("server", "404"));

    if (parser->is_location_empty(location))
        return default_action();

    // se nel config file il metodo è diverso da GET ritorna 405
    if (parser->get_conf_param(location, "method") != "" && parser->get_conf_param(location, "method") != "GET")
        return get_response(405, parser->get_conf_param("server", "405"));

    // se nel config file é settato il parametro cgi a on o se il file richiesto é un file php esegue il cgi
    if (parser->get_conf_param(location, "cgi") == "on" || path.find(".php") != string::npos)
    {
        CGI cgi(this);
        return cgi.exec_cgi();
    }

    // se nel config file é settato il parametro redirect allora esegue il redirect
    if (parser->get_conf_param(location, "redirect") != "")
        return get_response(302, parser->get_conf_param(location, "redirect"));

    // se nel config file é settato il parametro autoindex verifica se é settato il parametro index e ritorna il contenuto del file
    // altrimenti ritorna il contenuto della directory
    if (location == path && parser->get_conf_param(location, "autoindex") == "on")
    {
        if (parser->get_conf_param(location, "index") != "")
            return get_response(200, location + parser->get_conf_param(location, "index"));
        else
            return list_response(get_dir_content(parser->get_root() + path));
    }

    // if (location + parser->get_conf_param(location, "index") == path)
    file_requested.erase(0, location.length());
    if (parser->entry_conf_exist(location, file_requested) != "" && file_exist(parser->get_root() + path))
        return get_response(200, path);
    
    return get_response(404, parser->get_conf_param("server", "404"));
}

string Request::Delete()
{
    logMsg(BLUE, "[Delete]");
    if (!file_exist(parser->get_root() + get_req_param("path")))
        return get_response(404, parser->get_conf_param("server", "404"));
    if (get_location(get_req_param("path")) == "/forbidden")
        return get_response(403, parser->get_conf_param("server", "403"));
    if (remove((parser->get_root() + get_req_param("path")).c_str()) != 0)
        return get_response(500, parser->get_conf_param("server", "500"));
    return get_response(200, parser->get_conf_param("server", "200"));
}

string Request::Options()
{
    logMsg(BLUE, "[Options]");
    return "";
}
