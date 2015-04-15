#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>


int main()
{
    int listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(listen_socket < 0)
    {
        write(2, "Error: socket.\n", 15);
        return 1;
    }

    int error;
    struct sockaddr_in local;
    local.sin_family = AF_INET;
    local.sin_port = htons(7500);//7500 - порт, по которому собираемся общаться
    local.sin_addr.s_addr = htonl(INADDR_ANY);

    error = bind(listen_socket, (struct sockaddr*)&local, sizeof(local));
    if(error)
    {
       write(2, "Error: bind.\n", 13);
       return 1;
    }

    error = listen(listen_socket, 5);
    if(error <= 0)
    {
        write(2, "Error: listen.\n", 15);
        return 1;
    }

    int a_socket = accept(listen_socket, NULL, NULL);

    return 0;
}
