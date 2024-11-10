#include <unistd.h>

#include "TcpStream.h"

namespace flashdb
{
    TcpStream::TcpStream(int fd)
        : m_Fd(fd)
    {
    }

    int TcpStream::Read(char* buf, size_t size)
    {
        return ::read(m_Fd, buf, size-1);
    }

    int TcpStream::Write(char* buf, size_t size)
    {
        return ::write(m_Fd, buf, size);
    }

    void TcpStream::Close()
    {
        ::close(m_Fd);
    }
}
