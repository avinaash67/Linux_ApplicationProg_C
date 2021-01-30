File locking is a method to lock a file. This is used to prevent other processes from accessing the file when one process is using it.
This method avoids race condition.

This is like mutex but done using a unix based system call fcntl()

refer more about fcntl by typing "man fcntl" command in terminal.


