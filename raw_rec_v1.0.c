#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>	//For memset()
#include<netdb.h>	//For getaddrinfo()
int main(){
	struct sockaddr_storage their_addr;
	socklen_t addr_size;
	struct addrinfo hints,*res;
	memset(&hints,0,sizeof(hints));
	getaddrinfo("127.0.0.1","5000",&hints,&res);
	int s,b,l,new_s;
	char msg[20];
	s=socket(AF_INET,SOCK_STREAM,0);
	if(s==-1){
		printf("Error unable to create socket");
	}
	b=bind(s,res->ai_addr,res->ai_addrlen);
	if(b==-1){
		printf("Error unable to bind socket");
	}
	l=listen(s,10);
	if(l==-1){
		printf("Error not listening error");
	}
	addr_size-sizeof their_addr;
	new_s=accept(s,(struct sockaddr*)&their_addr,&addr_size);
	if(new_s==-1){
		printf("Error 2nd socket failed!");
	}
	send(new_s,"Enter you name:",16,0);
	recv(new_s,msg,20,0);
	send(new_s,"Hi,",3,0);
	send(new_s,msg,20,0);

}
