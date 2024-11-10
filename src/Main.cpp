#include "TcpListener.h"
#include "TcpStream.h"
#include <future>
#include <memory>

void handle_connection(std::unique_ptr<flashdb::TcpStream> client)
{
}

int main()
{
    flashdb::TcpListener listener;

    while (true) {
        auto client = std::make_unique<flashdb::TcpStream>(listener.Accept());
        auto f = std::async(std::launch::async, handle_connection, std::move(client));
    }
}

