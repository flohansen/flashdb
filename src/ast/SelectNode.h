#pragma once

#include <vector>
#include <string>

#include "Node.h"

namespace flashdb
{
    class SelectNode : public Node
    {
    private:
        std::vector<std::string> m_Columns;
        std::string m_TableName;
    public:
        std::vector<std::string> GetColumns() const;
        std::string GetTableName() const;
        void AddColumn(std::string column);
        void SetTableName(std::string name);
        std::string ToString() const;
    };

}
