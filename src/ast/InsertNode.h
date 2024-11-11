#pragma once

#include <vector>
#include <string>

#include "Node.h"

namespace flashdb
{
    class InsertNode : public Node
    {
    private:
        std::string m_TableName;
        std::vector<std::string> m_Columns;
        std::vector<std::string> m_Values;
    public:
        void SetTableName(const std::string& name);
        void AddColumn(const std::string& column);
        void AddValue(const std::string& value);
        std::string ToString() const override;
    };
}
