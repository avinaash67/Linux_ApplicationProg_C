/* Filename: msgq_send.c */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define PERMISSION 0644

struct msg_buf
{
	long mtype; //Message type
	char mtext[100]; //Message text
};

int main(void){

struct msg_buf buf; //Instance of the message structure created
int msgqid; 		//Id of the message queue created
int len;
key_t key; 			//Key to open message queue 	

system("touch msgq.txt"); //System call to create a message queue


if((key=ftok("msgq.txt",'B'))==-1){
	perror("File to key: ftok()\n");
	exit(1);
}

if((msgqid=msgget(key,PERMISSION | IPC_CREAT))==-1){
	perror("Error getting id for msg queue: mssget()\n");
	exit(1);
}

printf("Message queue has been set\n");
printf("Enter the line that you want to send\n");

/**fgets():**/
/*The C library function char *fgets(char *str, int n, FILE *stream) reads a line from the specified 
stream and stores it into the string pointed to by str. It stops when either (n-1) characters are read,
the newline character is read, or the end-of-file is reached, whichever comes first.*/

/*Return Value
On success, the function returns the same str parameter. If the End-of-File is encountered and no characters
have been read, the contents of str remain unchanged and a null pointer is returned*/

while(fgets(buf.mtext, sizeof(buf.mtext), stdin) != NULL)
{
	len = strlen(buf.mtext);
	if (buf.mtext[len-1] == '\n')
	{ 
		buf.mtext[len-1] = '\0';

	}
	if(msgsnd(msgqid, &buf, len+1, 0)==-1)
	{
		perror("msgsnd(): Message sending failed");
	}
}
	printf("User pressed ctrl+D\n");
	strcpy(	buf.mtext, "end");
	len = strlen(buf.mtext);
	if(msgsnd(msgqid, &buf, len+1, 0)==-1)
	{
		perror("msgsnd(): Message sending failed");
	}

   if (msgctl(msgqid, IPC_RMID, NULL) == -1) {
      perror("msgctl");
      exit(1);
   }
  printf("message queue: done sending messages.\n");
   
return 0;
}


