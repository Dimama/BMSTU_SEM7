#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdio.h>


#define PORT 8080
#define SERVER_NAME "localhost"
#define MAX 20
#define MESSAGE "This message show example of sending message from clien to server using sockets with TCP"

int main(int argc, char* argv[])
{

	struct sockaddr_in server_addr;
	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	inet_pton(AF_INET, (char*) SERVER_NAME, &server_addr.sin_addr);
    server_addr.sin_port = htons(PORT);

    int s;
	if((s = socket(AF_INET, SOCK_STREAM,0)) < 0)
	{
		perror("Error of opening socket");
		return -1;
	}

	if( connect(s, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0)
	{
		perror("Error of connect");
		return -1;
	}

	int count = 0;
	char buf[MAX];
	for(unsigned int i = 0; i < strlen(MESSAGE); i += MAX)
	{
		memset(buf, 0, MAX);
		for(unsigned int j = 0; (j < MAX - 1) && (j < strlen(MESSAGE)); j++)
		{
			buf[j] = MESSAGE[i+j];
		}
		if (write(s, buf, strlen(buf)) < 0)
		{
			perror("Error of sending message");
			return -1;	
		}
		else
		{
			count++;
			printf("Part #%d of message was send\n", count);
	
		}
	}
	

	close(s);
	return 1;
}