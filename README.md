# showip ip address command line utility

Command line utility for finding an ip address of a given hostname.

## Prerequisites

Tested Operating Systems: Ubuntu 20.04

Software: [GCC](https://gcc.gnu.org/), [Cmake](https://cmake.org/cmake/help/v3.14/manual/cmake.1.html), make

## Building

Go into the build directory in your terminal and run:
```shell
cmake .
make
```

## Usage and example
In order to use the software you can go to the bin directory and execute:

```shell
./showip google.com
```

Sample output:
```shell
IP addresses for google.com:

IPv4: 216.58.212.174
IPv6: 2a00:1450:4001:821::200e
```