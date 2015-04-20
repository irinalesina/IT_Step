#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#define MAX_STR 1024


int main()
{
    //создаем сокет
    int aSocket = socket(AF_INET, SOCK_STREAM, 0);
    if(aSocket < 0)
    {
        write(2, "Error: socket.\n", 15);
        return 1;
    }

    int error;
    struct sockaddr_in peer;
    peer.sin_family = AF_INET;
    peer.sin_port = htons(7501); //7500 - порт, по которому будем общаться

    char server_ip[16] = {0};
    printf("Enter IP: ");
    fgets(server_ip, 16, stdin);
    peer.sin_addr.s_addr = inet_addr(server_ip);

    error = connect(aSocket, (struct sockaddr *)&peer, sizeof(peer));
    if(error)
    {
        write(2, "Error: connect.\n", 16);
        return 1;
    }



    char buf[MAX_STR] = {0};
    do
    {
        memset(buf, 0, strlen(buf));
        write(1, "<< ", 3);
        fgets(buf, MAX_STR, stdin);

        error = write(aSocket, buf, MAX_STR);
        if(error <= 0)
        {
            write(2, "Error: write.\n", 14);
            return 1;
        }

        if(!strcmp(buf, "exit\n"))
            break;

        memset(buf, 0, strlen(buf));

        error = read(aSocket, buf, MAX_STR);
        if(error <= 0)
        {
            write(2, "Error: read.\n", 13);
            return 1;
        }
        else
        {
            if(!strcmp(buf, "exit\n"))
            {
                printf("Your partner exited!\n");
                break;
            }

            write(1, ">> ", 3);
            write(1, buf, strlen(buf));
        }
    }
    while(1);


    return 0;
}








