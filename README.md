# Minitalk

Minitalk is a simple communication project between a client and a server using UNIX signals. The server receives messages sent by the client and displays the received text. The project also includes a bonus version that confirms the reception of each message.

## Table of Contents

- [Installation](#installation)
- [Usage](#usage)
- [How it Works](#how-it-works)
- [Bonus](#bonus)
- [Troubleshooting](#troubleshooting)
- [Authors](#authors)

## Installation

1. Clone this repository to your local machine:
    ```bash
    git clone https://github.com/antg01/Minitalk.git
    ```

2. Navigate to the project directory:
    ```bash
    cd minitalk
    ```

3. Compile the client and server executables:
    ```bash
    make
    ```

4. To compile the bonus versions:
    ```bash
    make bonus
    ```

## Usage

1. Start the server:
    ```bash
    ./server
    ```

2. The server will display its PID (Process ID), for example:
    ```
    Server PID: 12345
    ```

3. In another terminal window, use the client to send a message to the server using the displayed PID:
    ```bash
    ./client 12345 "Hello, world!"
    ```

4. The server will display the received message:
    ```
    Hello, world!
    ```

## How it Works

The program uses UNIX signals to communicate between the client and the server. The signals used are `SIGUSR1` and `SIGUSR2` to represent bits 1 and 0, respectively.

### File Details

- `client.c`: Contains the code for the client that sends characters one by one as bits to the server.
- `server.c`: Contains the code for the server that receives the bits, reconstructs the characters, and displays them.
- `client_bonus.c`: Enhanced version of the client that waits for confirmation of message reception.
- `server_bonus.c`: Enhanced version of the server that sends a confirmation signal to the client after receiving each message.
- `Makefile`: File to automate the compilation of executables.

### Functionality of Main Functions

#### Client

- `ft_atoi`: Converts a string to an integer.
- `send_char_as_bits`: Sends a character to the server using signals for each bit.
- `main`: Handles command line arguments, converts the message to bits, and sends them to the server.

#### Server

- `receive_bit`: Signal handler to receive bits from the client and reconstruct the characters.
- `main`: Initializes the server, displays the PID, and waits for signals to receive and display messages.

## Bonus

The bonus version enhances the program by adding confirmation of message reception. The server sends a `SIGUSR2` signal to the client after receiving each message.

### Functionality of Bonus Functions

#### Client Bonus

- `message_confirmed`: Signal handler to confirm message reception.
- `main`: Similar to the standard client, but adds a wait for the reception confirmation.

#### Server Bonus

- `receive_bit`: Enhanced to send a reception confirmation to the client.
- `main`: Uses `sigaction` to handle signals and provide more contextual information.

## Troubleshooting

- **The client fails to send a message**:
  - Ensure the server is running and the PID used is correct.
  - Check that the signals are not blocked or filtered by the system.

- **The server does not receive messages**:
  - Add debugging messages in the signal handlers to confirm signal reception.
  - Increase the sleep duration (`usleep`) between sending bits to avoid signal loss.

