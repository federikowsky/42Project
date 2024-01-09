#include "../include/Server.hpp"
#include "../include/Parser.hpp"
#include "../include/Response.hpp"

using namespace std;

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        Server server("configuration_file/full_nginx_example.conf");
        server.run();
    }
    else
    {
        Server server(argv[1]);
        server.run();
    }
    return 0;
}
