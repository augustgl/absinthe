# Absinthe

MBR virus, with infect count panel. 

### 1/7/2021

It's been a little under a year since I made this repo. I had known the whole "overwrite the MBR with 512 bytes of 0" trick for a while, but it's kinda lame to just brick the computer. 

So I did more research... and found some code to overwrite it with a custom message. But that wasn't enough. 

Originally, you ran the program, it wrote our own code to the master boot record, and the user had to restart for it to take affect. That's lame.
so I added these features

1. Forced reboot via BSoD (force a Blue Screen of Death forcing the computer to crash and restart, automatically running our code that shows the message)
2. Sends an HTTP GET request to our panel, to log a successful infect. 
3. Panel, for viewing the infect count, and IPs of the infected bots. 

There are also instructions in the main cpp file for how to set it up. It isn't hard. 

hugs are worth more than handshakes

EDUCATIONAL PURPOSES ONLY! I AM NOT RESPONSIBLE FOR WHAT YOU DO WITH THIS

## Getting Started

Make a pull request, or download as a zip

### Prerequisites

Visual Studio 2017 is required. This application has been tested in x64 

## Built With

* [Microsoft Windows API](https://msdn.microsoft.com/en-us/library/aa383723(VS.85).aspx)

## Authors

* **August G.L** - *Initial work*

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details
