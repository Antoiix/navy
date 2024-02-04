# Navy

Welcome to this documentation of navy project with local multiplayer between two linux terminal instances, using signals.

## A project example
```py
$> ./my_navy ./maps/player1_navy.txt
my_pid: 1464

waiting for enemy...

enemy connected

my navy:
 |A B C D E F G H
-+---------------
1|. . 2 . . . . .
2|. . 2 . . . . .
3|. . . . . . . .
4|. . . 3 3 3 . .
5|. 4 . . . . . .
6|. 4 . . . . . .
7|. 4 . 5 5 5 5 5
8|. 4 . . . . . .

enemy navy:
 |A B C D E F G H
-+---------------
1|. . . . . . . .
2|. . . . . . . .
3|. . . . . . . .
4|. . . . . . . .
5|. . . . . . . .
6|. . . . . . . .
7|. . . . . . . .
8|. . . . . . . .

attack: B2

result: B2:missed

waiting for enemy's attack...

result: D5:missed
```
# Signals

In computing, inter-process communication (IPC) allows different processes to communicate with each other. Signals are one form of IPC that processes can use to communicate with each other in Unix-like operating systems. Here's an explanation of signals and their use in inter-process communication:

## What are Signals?
Signals are software interrupts delivered to a process to notify it that a specific event has occurred. These events can include various things, such as the process receiving a particular instruction, an error occurring, or another process wanting to communicate with it.

## Common Signals:
- `SIGTERM (15)`: Termination signal. This is a generic signal used to terminate a process gracefully. The process can perform cleanup operations before exiting.

- `SIGKILL (9)`: Kill signal. This is a forceful termination signal that immediately kills a process without allowing it to perform any cleanup operations.

- `SIGINT (2)`: Interrupt signal. Sent by pressing Ctrl+C in the terminal. It typically prompts a process to gracefully terminate.

- `SIGHUP (1)`: Hangup signal. Historically used for terminal hangup detection, it's often used to instruct daemons to reload their configuration.

- `SIGUSR1 (10)` and `SIGUSR2 (12)`: User-defined signals. These signals can be used by applications for custom purposes.

## Signal Handling:
Processes can handle signals using signal handlers, which are functions that get executed in response to a specific signal. The signal() function in C can be used to define custom signal handlers. Alternatively, the sigaction() function provides a more advanced and reliable way to handle signals.

## Inter-Process Communication using Signals:
Signals can be used for simple communication between processes. For example:

- Signaling Another Process: A process can send a signal to another process using system calls like kill() in Unix. The receiving process can then handle the signal to perform a specific action.

- Handling Termination Gracefully: Sending a SIGTERM signal to a process requests it to terminate gracefully, allowing it to perform cleanup operations before exiting.

- Custom Communication: Processes can define custom signals (such as SIGUSR1 and SIGUSR2) for communication purposes. One process can send a signal to another to convey a message or trigger a specific action.

## Limitations:
- Limited Data: Signals are not suitable for passing large amounts of data between processes. They are more suited for simple notifications or triggers.

- No Guarantee of Delivery Order: There's no guarantee of the order in which signals are delivered.

- Asynchronous Nature: Signals are asynchronous, meaning they can arrive at any time. This can lead to race conditions if not handled carefully.

- While signals provide a lightweight form of communication, for more complex data exchange or synchronization between processes, other IPC mechanisms like pipes, sockets, and message queues may be more suitable.
