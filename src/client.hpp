#ifndef CLIENT
#define CLIENT
#include "chat.hpp"
#include <netinet/in.h>
#include <string>

class Client {
public:
    Client(int port, Chat* chat);
    Chat* chat;
    void send_msg(std::string msg);
    void wait_for_msgs();
private:
    int sock;
    struct sockaddr_in broadcast_addr;
    struct sockaddr_in local_addr;
};

#endif
