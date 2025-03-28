#include "toralize.h"

Req* request(const char* dstip, const int dstport) {
    Req* req;
    req = malloc(reqsize);
    
    req->vn = 4;
    req->cd = 1;
    req-dstport = htons(dstport);
    req->dstip = inet_addr(dstip);
    strcpy(req->username, USERNAME, 8);

    return req;    
}

int main(int argc, char* argv[]) {
    char* host;
    int port, s;
    struct sockaddr_in sock;
    Req* request;    


    if (argc < 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]); 
        return -1;
    }

    host = argv[1];
    port = atoi(argv[2]);
    
    s = socket(AF_INET, SOCK_STREAM, 0);
    if (s < 0) {
        perror("socket");
        return -1;
    }

    sock.sin_family = AF_INET;
    sock.sin_port = htons(PROXYPORT);
    sock.sin_addr.s_addr = inet_addr(PROXY);

    if (connect(s, (struct sockaddr *)&sock, sizeof(sock))) {
        perror("connect");
        return -1;
    }

    printf("\nConnected to a proxy\n");
    req = request(host, port);
    write(s, req, reqsize);     


    close(s);
    return 0;
}
