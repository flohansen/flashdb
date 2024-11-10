#include <stdexcept>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#include "TcpListener.h"

namespace flashdb
{
    TcpListener::TcpListener()
    {
        m_Sock = socket(AF_INET, SOCK_STREAM, 0);
        if (m_Sock < 0)
        {
            throw std::runtime_error("Could not open socket");
        }

        struct sockaddr_in serv_addr = {0};
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(8080);
        serv_addr.sin_addr.s_addr = INADDR_ANY;

        if (bind(m_Sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0)
        {
            throw std::runtime_error("Could not bind socket to address");
        }

        listen(m_Sock, 5);
    }

    TcpListener::~TcpListener()
    {
    }

    TcpStream TcpListener::Accept() const
    {
        struct sockaddr_in client_addr = {0};
        unsigned int len = sizeof(client_addr);

        int conn = accept(m_Sock, (struct sockaddr*)&client_addr, &len);
        if (conn < 0)
        {
            throw std::runtime_error("Could not accept new connection");
        }

        return TcpStream(conn);
    }
}
