# Networking
Networking library based on Sockets C API, built using UNIX libraries. It uses TCP/IP Sockets.    
This library consists of:
- Client
- Server

Client & Server wrap Unix Sockets.  User can easly send and receive data by calling Client/Server API.  

Communication is being validated, functions take care of
- checking if the size is correct, otherwise `std::invalid_argument` error is thrown 
- data fragmentation, making sure that the entire message is sent out and received back
- connection loss, throwing `networking::EndConnection` error to indicate that the connection was lost

The entire library is contained inside `networking` namespace.  
Before starting communication both Client and Server must use the same `MESSAGE_HEADER_SIZE` which can be defined inside `config.hpp`

## Building
In order to build the project you have to run unix-like OS, because this networking library is based on unix libraries.  
There is configuration parameter `VERBOSE` which you can set inside `networking-src/networking/config.hpp`
