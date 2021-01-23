Steps to create a Daemon
	-fork
	-setsid
	-catch signals
	-fork again
	-chdir 
		change the working directory of the daemon
	-umask
	-close
