#include "../include/Response.hpp"
#include "../include/Logger.hpp"

using namespace std;

Response::Response()
{
    this->http_value = "";
    this->status_code = -1;
    this->file_name = "";

    mime_types[".html"] = "text/html";
    mime_types[".css"] = "text/css";
    mime_types[".js"] = "application/javascript";
    mime_types[".json"] = "application/json";
    mime_types[".xml"] = "application/xml";
    mime_types[".jpg"] = "image/jpeg";
    mime_types[".jpeg"] = "image/jpeg";
    mime_types[".png"] = "image/png";
    mime_types[".gif"] = "image/gif";
    mime_types[".svg"] = "image/svg+xml";
    mime_types[".ico"] = "image/x-icon";
    mime_types[".ttf"] = "font/ttf";
    mime_types[".otf"] = "font/otf";
    mime_types[".woff"] = "font/woff";
    mime_types[".woff2"] = "font/woff2";
    mime_types[".txt"] = "text/plain";
    mime_types[".mp4"] = "video/mp4";
    mime_types[".mp3"] = "audio/mpeg";
    mime_types[".wav"] = "audio/wav";
    mime_types[".pdf"] = "application/pdf";
    mime_types[".zip"] = "application/zip";
    mime_types[".tar"] = "application/x-tar";
    mime_types[".gz"] = "application/x-gzip";
    mime_types[".bz2"] = "application/x-bzip2";
    mime_types[".rar"] = "application/x-rar-compressed";
    mime_types[".7z"] = "application/x-7z-compressed";
    mime_types[".doc"] = "application/msword";
    mime_types[".docx"] = "application/vnd.openxmlformats-officedocument.wordprocessingml.document";
    mime_types[".xls"] = "application/vnd.ms-excel";
    mime_types[".xlsx"] = "application/vnd.openxmlformats-officedocument.spreadsheetml.sheet";
    mime_types[".ppt"] = "application/vnd.ms-powerpoint";
    mime_types[".pptx"] = "application/vnd.openxmlformats-officedocument.presentationml.presentation";
    mime_types[".csv"] = "text/csv";

    http_codes[100] = "Continue";
    http_codes[101] = "Switching Protocols";
    http_codes[102] = "Processing";
    http_codes[103] = "Early Hints";
    http_codes[200] = "OK";
    http_codes[201] = "Created";
    http_codes[202] = "Accepted";
    http_codes[203] = "Non-Authoritative Information";
    http_codes[204] = "No Content";
    http_codes[205] = "Reset Content";
    http_codes[206] = "Partial Content";
    http_codes[207] = "Multi-Status";
    http_codes[208] = "Already Reported";
    http_codes[226] = "IM Used";
    http_codes[300] = "Multiple Choices";
    http_codes[301] = "Moved Permanently";
    http_codes[302] = "Found";
    http_codes[303] = "See Other";
    http_codes[304] = "Not Modified";
    http_codes[305] = "Use Proxy";
    http_codes[306] = "Switch Proxy";
    http_codes[307] = "Temporary Redirect";
    http_codes[308] = "Permanent Redirect";
    http_codes[400] = "Bad Request";
    http_codes[401] = "Unauthorized";
    http_codes[402] = "Payment Required";
    http_codes[403] = "Forbidden";
    http_codes[404] = "Not Found";
    http_codes[405] = "Method Not Allowed";
    http_codes[406] = "Not Acceptable";
    http_codes[407] = "Proxy Authentication Required";
    http_codes[408] = "Request Timeout";
    http_codes[409] = "Conflict";
    http_codes[410] = "Gone";
    http_codes[411] = "Length Required";
    http_codes[412] = "Precondition Failed";
    http_codes[413] = "Payload Too Large";
    http_codes[414] = "URI Too Long";
    http_codes[415] = "Unsupported Media Type";
    http_codes[416] = "Range Not Satisfiable";
    http_codes[417] = "Expectation Failed";
    http_codes[418] = "I'm a teapot";
    http_codes[421] = "Misdirected Request";
    http_codes[422] = "Unprocessable Entity";
    http_codes[423] = "Locked";
    http_codes[424] = "Failed Dependency";
    http_codes[425] = "Too Early";
    http_codes[426] = "Upgrade Required";
    http_codes[428] = "Precondition Required";
    http_codes[429] = "Too Many Requests";
    http_codes[431] = "Request Header Fields Too Large";
    http_codes[451] = "Unavailable For Legal Reasons";
    http_codes[500] = "Internal Server Error";
    http_codes[501] = "Not Implemented";
    http_codes[502] = "Bad Gateway";
    http_codes[503] = "Service Unavailable";
    http_codes[504] = "Gateway Timeout";
    http_codes[505] = "HTTP Version Not Supported";
    http_codes[506] = "Variant Also Negotiates";
    http_codes[507] = "Insufficient Storage";
    http_codes[508] = "Loop Detected";
    http_codes[510] = "Not Extended";
    http_codes[511] = "Network Authentication Required";
}

Response::~Response() {}

string Response::get_response2(int code, string path)
{
    Response response;
    response.set_response(code, path);
    return response.get_http_response();
}

string Response::get_file_ext(string path)
{
    size_t ext_start = path.find_last_of(".");
    if (ext_start != string::npos)
        return path.substr(ext_start);
    return "";
}

string Response::get_http_code_msg()
{
    std::map<int, std::string>::const_iterator it = http_codes.find(status_code);
    return (it != http_codes.end()) ? it->second.c_str() : "Undefined";
}

string Response::get_content_type(string extension)
{
    std::map<std::string, std::string>::const_iterator it = mime_types.find(extension);
    return (it != mime_types.end()) ? it->second.c_str() : "application/octet-stream";
}

string Response::get_file_content(const char *file_name)
{
    stringstream buffer;
    ifstream file(file_name);
    if (!file.is_open())
    {
        logMsg(RED, "\n[!] (Response) Errore nell'apertura del file: %s\n", file_name);
        return "";
    }

    buffer << file.rdbuf();
    file.close();
    return buffer.str();
}

void Response::set_header(string key, string value)
{
    http_value += key + ": " + value + "\r\n";
}

void Response::set_response(int code, string file)
{
    this->status_code = code;
    this->file_name = file;
}

string Response::get_http_response()
{
    stringstream response;
    string body;
    char timeBuffer[80];
    time_t now = time(0);
    tm *timeinfo = gmtime(&now);
    strftime(timeBuffer, 80, "%a, %d %b %Y %H:%M:%S GMT", timeinfo);
    body = get_file_content(file_name.c_str());

    response << "HTTP/1.1 " << status_code << " " << get_http_code_msg() << "\r\n";
    if (http_value != "")
        response << http_value;
    response << "Date: " << timeBuffer << "\r\n";
    response << "Server: MyServer\r\n";
    response << "Content-Type: " << get_content_type(get_file_ext(file_name)) << "\r\n";
    response << "Content-Length: " << body.length() << "\r\n";
    response << "\r\n";
    response << body;

    return response.str();
}