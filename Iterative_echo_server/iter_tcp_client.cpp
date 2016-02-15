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

//if(argc!=2) {cout<<"Improper Adress inputted\n";exit(1);}

struct sockaddr_in serv_addr;
char snd[MAX_LEN],rcv[MAX_LEN];

// creation of  a socket for client
int sfd = socket(AF_INET,SOCK_STREAM,0); 

// creation of the socket address
 memset(&serv_addr, 0, sizeof(serv_addr));
 serv_addr.sin_family = AF_INET;
 serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
 serv_addr.sin_port = htons(serv_port);

// connection of client to the server
if(connect(sfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr))<0)
perror("Unable to connect to the server\n");

//cout<<"1";
while(1){
fgets(snd,MAX_LEN,stdin);
send(sfd,snd,strlen(snd),0);
//cout<<sfd;
if(recv(sfd,rcv,MAX_LEN,0)==0){
perror("server terminated\n");
}
cout<<"string recieved from the server is ::";fputs(rcv,stdout);
}
}



