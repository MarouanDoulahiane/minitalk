# minitalk

## About
The `minitalk` project involves coding a small data exchange program using UNIX signals. This project provides an opportunity to gain a deeper understanding of inter-process communication (IPC) through signal handling in the UNIX environment.

For more detailed information, refer to the [subject of this project](https://github.com/Surfi89/42cursus/tree/main/Subject%20PDFs).

## Usage

### Requirements
To compile and use the program, ensure you have the following:
- `cc` compiler
- Standard C libraries

### Instructions

1. **Compiling:**

Navigate to the project directory and execute:
```shell
$ make
```
Testing
To test the program, follow these steps:

Launch the "server" in one shell tab:
```shell
$ ./server
```
This will display your PID and wait to receive a message from the client.

In another shell tab, launch the "client" with the server's PID and a message string:
```shell
$ ./client "PID" "Your message string"
```
