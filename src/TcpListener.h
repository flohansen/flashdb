#pragma once

#include "TcpStream.h"

namespace flashdb
{
    class TcpListener
    {
    private:
        int m_Sock;
    public:
        TcpListener();
        ~TcpListener();
    public:
        TcpStream Accept() const;
    };
}
