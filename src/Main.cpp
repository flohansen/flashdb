#include <cstdio>
#include <future>
#include <memory>

#include "TcpListener.h"
#include "TcpStream.h"

void handle_connection(std::unique_ptr<flashdb::TcpStream> client)
{
    client->Close();
}

int main()
{
    flashdb::TcpListener listener;

    while (true) {
        auto client = std::make_unique<flashdb::TcpStream>(listener.Accept());
        auto f = std::async(std::launch::async, handle_connection, std::move(client));
    }
}

