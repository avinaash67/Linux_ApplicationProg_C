Pipe
	Creating 2 processes
		-Parent
		-Child
	Communicating between the two processes using pipes

	Pipe has 2 ends hence 2 file descriptors are needed;  fd[2]; 
		-read end
		-write end

Disadavantage :
	Pipes can be used to communicate only through the same heirarchy. For example Forking.
	File descriptors of the pipe is copied to the child process, hence the same File descriptors (fd) are used to communicate within the same heirarchy.