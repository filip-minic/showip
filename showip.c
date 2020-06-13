//
// Created by fminic on 13.06.20.
//

/**
 * Command line utility to retrieve TCP IP addresses for the given domain name or address.
 */

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    struct addrinfo hints;
    struct addrinfo *result;
    struct addrinfo *addressInfo;

    int status;

    if (argc != 2) {
        fprintf(stderr, "Usage: showip hostname\n");
        return EXIT_FAILURE;
    }

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((status = getaddrinfo(argv[1], NULL, &hints, &result)) != 0) {
        fprintf(stderr, "getaddrinfo() call failed: %s\n", gai_strerror(status));
    }

    printf("IP addresses for %s:\n\n", argv[1]);

    for (addressInfo = result; addressInfo != NULL; addressInfo = addressInfo->ai_next) {
        if (addressInfo->ai_family == AF_INET) {
            struct sockaddr_in *ipv4 = (struct sockaddr_in *) addressInfo->ai_addr;
            void *addr = &(ipv4->sin_addr);
            char ipstr[INET_ADDRSTRLEN];

            inet_ntop(addressInfo->ai_family, addr, ipstr, sizeof(ipstr));

            printf("IPv4: %s\n", ipstr);
        } else {
            struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *) addressInfo->ai_addr;
            void *addr = &(ipv6->sin6_addr);
            char ipstr[INET6_ADDRSTRLEN];

            inet_ntop(addressInfo->ai_family, addr, ipstr, sizeof(ipstr));

            printf("IPv6: %s\n", ipstr);
        }
    }

    freeaddrinfo(result);

    return EXIT_SUCCESS;
}

