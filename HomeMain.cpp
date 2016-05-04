#include <string.h>
#include <cmath>
#include <string>
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
	Pwm P8_19;
	Pwm P9_14;
	char period[] = "2000000";
	//char period[9] = {'2', '0', '0', '0', '0', '0', '0', '0', '\0'};
	P8_19.SetPeriod(19, period, 12, 8);
	P9_14.SetPeriod(14, period, 13, 9);
//	P9_22.SetPeriod(0, period);

	struct sockaddr_in my_addr, cli_addr;
	string buffer;
	string x_axis;
	double x, y;
	string y_axis;
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
		//cout << "Buf is: " << buf << endl;
		buffer = string(buf);
		//cout << "Buffer is: " << buffer << endl;
		std::string::size_type pos = buffer.find(',');
		if (pos != std::string::npos) {
			//cout << "X Axis: " << buffer.substr(0, pos) << endl;
			//cout << "Errthing else: " << buffer.substr(pos+1, std::string::npos) << endl;
			x = stod((buffer.substr(0,pos)).c_str(), nullptr);
			y = stod((buffer.substr(pos+1, std::string::npos)).c_str(), nullptr);
			cout << "X: " << abs(x) << "\tY: " << abs(y) << endl;
		}
		P8_19.SetDuty(19, abs(x*100000), 12, 8);
		//usleep(10000);
		P9_14.SetDuty(14, abs(y*100000), 13, 9);

	}
	close(sockfd);
	return 0;
}
