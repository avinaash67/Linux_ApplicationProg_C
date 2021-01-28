Queue - Used for IPC(Inter process communication)
		
	A message queue is a linked list of messages stored within the kernel and identified by a message queue identifier. A new queue is created or an existing queue opened by msgget(). 

	Why message queue?
		As understood, once the message is received by a process it would be no longer available for any other process. Whereas in shared memory, the data is available for multiple processes to access.

	Steps 
		- Requires a key to open a queue, Key is generated using ftok() which represents file to key
		- Use key to generate message ID
		- Use key and messageID to send message through the queue

	Linux System calls
		ftok(): is use to generate a unique key.
		msgget(): either returns the message queue identifier for a newly created message queue or returns the identifiers for a queue which exists with the same key value.
		msgsnd(): Data is placed on to a message queue by calling msgsnd().
		msgrcv(): messages are retrieved from a queue.
		msgctl(): It performs various operations on a queue. Generally it is use to destroy message queue.


**Further information : https://www.tutorialspoint.com/inter_process_communication/inter_process_communication_message_queues.htm**