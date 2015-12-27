#include <stdio.h>
#include <string.h>    //strlen
#include <stdlib.h>    //strlen
#include <sys/socket.h>
#include <arpa/inet.h> //inet_addr
#include <unistd.h>    //write
#include <pthread.h> //for threading , link with lpthread
#define	MAX_BUFFER 6000

//the thread function
void *connection_handler(void *);
 
int main(int argc , char *argv[])
{
    int socket_desc , client_sock , c;
    struct sockaddr_in server , client;
     
    //Create socket
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1)
    {
        printf("Could not create socket");
    }
    puts("Socket created");
     
    //Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( 50006 );
     
    //Bind
    if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
    {
        //print the error message
        perror("bind failed. Error");
        return 1;
    }
    puts("bind done");
     
    //Listen
    listen(socket_desc , 255);
     
    //Accept and incoming connection
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);
	pthread_t thread_id;
	
    while( (client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c)) )
    {
        puts("Connection accepted");
         
        if( pthread_create( &thread_id , NULL ,  connection_handler , (void*) &client_sock) < 0)
        {
            perror("could not create thread");
            return 1;
        }
         
        //Now join the thread , so that we dont terminate before the thread
        //pthread_join( thread_id , NULL);
        puts("Handler assigned");
    }
     
    if (client_sock < 0)
    {
        perror("accept failed");
        return 1;
    }
     
    return 0;
}
 
/*
 * This will handle connection for each client
 * */
void *connection_handler(void *socket_desc)
{
    //Get the socket descriptor
    int sock = *(int*)socket_desc;
    int read_size;
    char *message , client_message[2000];
    
    // ################# Create connection to send to Database ################# 
		struct sockaddr_in to_php_server;
		char php_message[MAX_BUFFER];
		char server_reply[MAX_BUFFER];
		int http_port = 80;
		int socket_to_php = socket(AF_INET , SOCK_STREAM , 0);
		if (socket_to_php == -1){
			printf("Could not create socket");
		}
	 
		to_php_server.sin_addr.s_addr = inet_addr("127.0.0.1");
		to_php_server.sin_family = AF_INET;
		to_php_server.sin_port = htons( http_port );
		//Connect to remote server
		if (connect(socket_to_php , (struct sockaddr *)&to_php_server , sizeof(to_php_server)) < 0){
			puts("connect error");
			   pthread_exit(0);
		}	
		// ################# Create connection to send to Database ################# 

		while( (read_size = recv(sock , client_message , 2000 , 0)) > 0 ){
			client_message[read_size] = '\0';
			
			puts("Reply received\n");
			puts(server_reply);
			
			puts("Data Send\n");
     
			printf("Character Received : %d\n",read_size);
			printf("%s\n",client_message);	
			write(sock , client_message , strlen(client_message));		
		}
		
		// ######### Send to Database ######### 
		sprintf(php_message,"GET /mikon.php?%s HTTP/1.1\r\nHost: 127.0.0.1\r\nContent-Type: application/x-www-form-urlencoded\r\n\r\n",client_message);
		if( write(socket_to_php , php_message , strlen(php_message)) < 0){
				puts("Send failed");
				pthread_exit(0);
		}
		else{
			puts("Send PHP success");
			printf("%d\n",(int)strlen(php_message));
		}
		close(socket_to_php);
		// ######### Send to Database ######### 
		
		if(read_size == 0){
			puts("Client disconnected");
			fflush(stdout);
		}
		else if(read_size == -1){
			perror("recv failed");
		}
	
	pthread_exit(0);
} 
