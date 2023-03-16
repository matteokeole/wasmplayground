#include <stdio.h>
#ifdef __WIN32__
	#include <winsock2.h>
#else
	#include <sys/socket.h>
#endif

int main() {
	// int sockfd;
	struct hostent *server;

	char url[] = "https://jsonplaceholder.typicode.com/todos/1";
	char message[] = "GET %s HTTP/1.0\r\n\r\n";
	char request[512];

	// sprintf(request, message, url);
	// printf("%s", request);

	int sockfd = socket(AF_INET, SOCK_STREAM, 0);

	printf("%d", sockfd);

	// server = gethostbyname("jsonplaceholder.typicode.com");

	return 0;
}