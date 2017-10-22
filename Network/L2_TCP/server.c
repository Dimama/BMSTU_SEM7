#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdio.h>

#define PORT 8080
#define ADRESS "127.0.0.1"
#define MAX 22

int main(int argc, char* argv[])
{

	struct sockaddr_in server_addr, client_addr;
	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

	int s;
	if((s = socket(AF_INET, SOCK_STREAM,0)) < 0)
	{
		perror("Error of opening socket");
		return -1;
	}

	if(bind(s, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0)
	{
		perror("Error of binding");
		return -1;
	}


	listen(s, 1);
	socklen_t len = sizeof(client_addr);
	int s_new = accept(s, (struct sockaddr*) &client_addr, &len);

	char buf[MAX];
	while (1)
	{
		memset(buf, 0, MAX);
		if(recv(s_new, buf, MAX, 0) < 0)
		{
			perror("Error of reading");
			return -1;
		} 
		else if (strlen(buf) > 0)
		{
			printf("Message from client: %s\n", buf);
		}
	}
	
	close(s);
	close(s_new);
	return 1;
}