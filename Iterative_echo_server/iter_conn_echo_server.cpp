#include<bits/stdc++.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

#define serv_port 3000 // portno
#define max_clients 5 
#define MAX_LEN 2048 

using namespace std;

int main(int argc,char **argv){

struct sockaddr_in clie_addr, serv_addr;
int sfd,nsfd;

// creation of  a socket
sfd = socket(AF_INET,SOCK_STREAM,0); // connection oriented/tcp

// socket address prep
// htonl(INADDR_ANY)
// inet_addr(argv[1])
 serv_addr.sin_family = AF_INET;
 serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);// 32 bit
 serv_addr.sin_port = htons(serv_port); // 16 bit

// binding the server address with the fd
bind(sfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr));

// listen for the client requests
listen(sfd,max_clients);

cout<<"Server Running .. Waiting On Client\n";

while(1){
socklen_t clie_len = sizeof(clie_addr);
// client getting connected to the Server
//cout<<1;
nsfd = accept(sfd,(struct sockaddr *)&clie_addr,&clie_len);
cout<<"Recieved Request\n";
//cout<<nsfd;

int n;char buf[MAX_LEN];
while(1){
n=recv(nsfd,buf,MAX_LEN,0);
cout<<"String Recieved From Client is ::"<<buf<<"\n";
strcpy(buf,"");
if(fgets(buf,MAX_LEN,stdin)!=NULL)
send(nsfd,buf,n,0);
}
if(n==-1)
perror("Error\n");
close(nsfd);
}
close(sfd);
}

