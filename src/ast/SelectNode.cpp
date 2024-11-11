#include "SelectNode.h"

namespace flashdb
{
    std::vector<std::string> SelectNode::GetColumns() const
    {
        return m_Columns;
    }

    std::string SelectNode::GetTableName() const
    {
        return m_TableName;
    }

    void SelectNode::AddColumn(std::string column)
    {
        m_Columns.push_back(column);
    }

    void SelectNode::SetTableName(std::string name)
    {
        m_TableName = name;
    }

    std::string SelectNode::ToString() const
    {
        std::string output = "select:\n";
        output += "  columns: [";

        for (size_t i = 0; i < m_Columns.size(); i++)
        {
            output += m_Columns[i];

            if (i < m_Columns.size() - 1)
            {
                output += ", ";
            }
        }

        output += "]\n";
        output += "  table: " + m_TableName;

        return output;
    }
}
