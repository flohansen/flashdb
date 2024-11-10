#pragma once

#include <vector>

namespace flashdb
{
    class TcpStream
    {
    private:
        int m_Fd;
    public:
        TcpStream(int fd);
    public:
        int Read(char* buf, size_t size);
        int Write(char* buf, size_t size);
        void Close();
    };
}
