#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>


#define PERMISSION 0777

//Creating the message structure
struct msg_buf
{
	long mtype;
	char mtext[100];
};

int main(int argc, char const *argv[])
{
	struct  msg_buf buf; // Instance of message buf
	int msgqid;  // message queue ID
	int toend; // end receiving; Used in later parts
	key_t key;  //key to open msg queue


	if ((key = ftok("msgq.txt", 'B')) == -1) {
      perror("ftok");
      exit(1);
   }
	printf("Got key from text file = %d\n",key );

	if((msgqid = msgget(key,PERMISSION))==-1){   /*Connecting to msg queue*/
		perror("msgget(): Getting queue id failed");
		exit(1);
	}

	printf("message queue: ready to receive messages.\n");

	while(1){
		if(msgrcv(msgqid, &buf, sizeof(buf.mtext), 0, 0) == -1)
		{
			printf("msgrcv(): Error receiving messages\n");
			exit(1);
		}
		// msgrcv(msgqid, &buf, sizeof(buf.mtext), 0, 0);
		printf("Hello\n");
		printf("%s\"\n", buf.mtext);
		toend = strcmp(buf.mtext,"end");
      	
      	if (toend == 0)	
      		{
      			break;
      		}
	}

	printf("message queue: done receiving messages.\n");
   	system("rm msgq.txt");

	return 0;
}