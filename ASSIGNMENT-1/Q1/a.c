#include <stdio.h>
#include <unistd.h>

int main()
{
        pid_t id;
        id=fork();

        if(id==0)
        {
                while(1)
                {
                        printf("Child process: %d\n",getpid());
                }
        }

        else
        {
                while(1)
                {
                          printf("Parent Process: %d\n",getpid());
                }
        }

        return 0;
}

// a)

tanmoy@tanmoy:~/DOS$ ps -a -l

F S   UID     PID    PPID  C PRI  NI ADDR SZ WCHAN  TTY          TIME CMD

0 S  1000    1661    1652  0  80   0 - 57921 do_pol tty2     00:00:00 gnome-session-b

0 R  1000    3270    2755 48  80   0 -   693 -      pts/1    00:00:09 a.out

1 R  1000    3271    3270 48  80   0 -   693 -      pts/1    00:00:09 a.out

0 R  1000    3273    3245  0  80   0 -  5331 -      pts/2    00:00:00 ps

// b)

tanmoy@tanmoy:~/DOS$ kill 3270

tanmoy@tanmoy:~/DOS$ ps -a -l

F S   UID     PID    PPID  C PRI  NI ADDR SZ WCHAN  TTY          TIME CMD

0 S  1000    1661    1652  0  80   0 - 57921 do_pol tty2     00:00:00 gnome-session-b

1 R  1000    3271    1592 49  80   0 -   693 -      pts/1    00:00:45 a.out

0 R  1000    3275    3245  0  80   0 -  5331 -      pts/2    00:00:00 ps

// c)

tanmoy@tanmoy:~/DOS$ ps -a -l

F S   UID     PID    PPID  C PRI  NI ADDR SZ WCHAN  TTY          TIME CMD

0 S  1000    1661    1652  0  80   0 - 57921 do_pol tty2     00:00:00 gnome-session-b

0 S  1000    3296    3283 30  80   0 -   693 wait_w pts/0    00:00:03 a.out

1 S  1000    3297    3296 28  80   0 -   693 do_tty pts/0    00:00:03 a.out

0 R  1000    3298    3245  0  80   0 -  5331 -      pts/2    00:00:00 ps

tanmoy@tanmoy:~/DOS$ kill 3297

tanmoy@tanmoy:~/DOS$ ps -a -l

F S   UID     PID    PPID  C PRI  NI ADDR SZ WCHAN  TTY          TIME CMD

0 S  1000    1661    1652  0  80   0 - 57921 do_pol tty2     00:00:00 gnome-session-b

0 R  1000    3296    3283 38  80   0 -   693 -      pts/0    00:00:14 a.out

1 Z  1000    3297    3296 34  80   0 -     0 -      pts/0    00:00:12 a.out <defunct>

0 R  1000    3301    3245  0  80   0 -  5331 -      pts/2    00:00:00 ps

tanmoy@tanmoy:~/DOS$ ps -a -l

F S   UID     PID    PPID  C PRI  NI ADDR SZ WCHAN  TTY          TIME CMD

0 S  1000    1661    1652  0  80   0 - 57921 do_pol tty2     00:00:00 gnome-session-b

0 R  1000    3313    3283 30  80   0 -   693 -      pts/0    00:00:04 a.out

1 R  1000    3314    3313 30  80   0 -   693 -      pts/0    00:00:04 a.out

0 R  1000    3315    3245  0  80   0 -  5331 -      pts/2    00:00:00 ps

// d)

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
        pid_t id;
        id=fork();
  
        if(id==0)
        {
                while(1)
                {
                        printf("Child process: %d\n",getpid());

                }
        }

        else
        {
                while(1)
                {
                          printf("Parent Process: %d\n",getpid());
                }

                wait(NULL);
        }

        return 0;
}

tanmoy@tanmoy:~/DOS$ ps -a -l

F S   UID     PID    PPID  C PRI  NI ADDR SZ WCHAN  TTY          TIME CMD

0 S  1000    1661    1652  0  80   0 - 57921 do_pol tty2     00:00:00 gnome-session-b

0 R  1000    3313    3283 30  80   0 -   693 -      pts/0    00:00:04 a.out

1 R  1000    3314    3313 30  80   0 -   693 -      pts/0    00:00:04 a.out

0 R  1000    3315    3245  0  80   0 -  5331 -      pts/2    00:00:00 ps

tanmoy@tanmoy:~/DOS$ kill 3313

tanmoy@tanmoy:~/DOS$ ps -a -l

F S   UID     PID    PPID  C PRI  NI ADDR SZ WCHAN  TTY          TIME CMD

0 S  1000    1661    1652  0  80   0 - 57921 do_pol tty2     00:00:00 gnome-session-b

1 R  1000    3314    1592 40  80   0 -   693 -      pts/0    00:00:26 a.out

0 R  1000    3316    3245  0  80   0 -  5331 -      pts/2    00:00:00 ps
