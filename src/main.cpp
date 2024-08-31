#include <iostream>
#include <thread>
#include <unistd.h>
#include "client.hpp"

#define PORT 8000

int main(){
    try{
        Chat chat = Chat();
        Client client = Client(PORT, &chat);
        std::thread twait(&Client::wait_for_msgs, &client);
        while (true){
            client.send_msg("Hello");
            sleep(1);
            client.send_msg("Hello2");
            sleep(1);
        }
        twait.detach();
    } catch (std::exception& e){
        std::cerr << e.what();
        perror(" :");
    }
    return 0;
}
