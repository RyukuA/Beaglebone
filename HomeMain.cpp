#include <string.h>
#include <fstream>
#include <iostream>
#include "Pwm.hpp"
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#define BUFLEN 512
#define SRV_IP "192.168.7.2"
using namespace std;

int main() {
	struct sockaddr_in my_addr, cli_addr;
	int sockfd, i;
	socklen_t slen=sizeof(cli_addr);
	char buf[BUFLEN];

	if ((sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP))==-1)
	cout << "socket" << endl;
	else
  		printf("Server : Socket() successful\n");

	bzero(&my_addr, sizeof(my_addr));
	my_addr.sin_family = AF_INET;
	my_addr.sin_port = htons(45786);
	my_addr.sin_addr.s_addr = htonl(INADDR_ANY);

	if (bind(sockfd, (struct sockaddr* ) &my_addr, sizeof(my_addr))==-1)
		cout << "bind" << endl;
	else
		printf("Server : bind() successful\n");

	while(1)
	{
		if (recvfrom(sockfd, buf, BUFLEN, 0, (struct sockaddr*)&cli_addr, &slen)==-1) {
			cout << "recvfrom()" << endl;
			printf("Received packet from %s:%d\nData: %s\n\n",
			inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port), buf);
		}


	}
	close(sockfd);
	return 0;
}
