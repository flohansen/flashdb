#pragma once

#include <string>

namespace flashdb
{
    class Node
    {
    public:
        virtual std::string ToString() const = 0;
    };
}
