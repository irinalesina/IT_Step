#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>


/*
int socket(int domain, int type, int protocol) - возвращает сокет, если его получилось создать и -1, если нет
domain: F_INET
type: SOCK_STREAM
protocol: 0
*/

/*
int connect(int __fd, __CONST_SOCKADDR_ARG __addr, socklen_t __len)
fd - сокет
CONST_SOCKADDR_ARG __addr-указатель на структуру, которыая содержит, куда коннектимся
socklen_t __len - размер в байтах структуры
*/


int main()
{
    int a_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(a_socket < 0)
    {
        write(2, "Error: socket.\n", 15);
        return 1;
    }
    int error;
    struct sockaddr_in peer;
    peer.sin_family = AF_INET;
    peer.sin_port = htons(7500);//7500 - порт, по которому собираемся общаться
    peer.sin_addr.s_addr = inet_addr("127.0.0.1");

    error = connect(a_socket, (struct sockaddr *)&peer, sizeof(peer));
    if(error)
    {
       write(2, "Error: connect.\n", 16);
       return 1;
    }
    error = write(a_socket, "123", 3);
    if(error <= 0)
    {
        write(2, "Error: write.\n", 14);
        return 1;
    }
    char buf[3];
    error = read(a_socket, buf, 3);
    if(error <= 0)
    {
        write(2, "Error: read.\n", 13);
        return 1;
    }
    else
    {
        write(1, buf, 3);
        write(1,"\n", 1);
    }

    return 0;
}
