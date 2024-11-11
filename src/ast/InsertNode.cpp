#include "InsertNode.h"
namespace flashdb
{
    void InsertNode::SetTableName(const std::string& name)
    {
        m_TableName = name;
    }

    void InsertNode::AddColumn(const std::string& column)
    {
        m_Columns.push_back(column);
    }

    void InsertNode::AddValue(const std::string& name)
    {
        m_Values.push_back(name);
    }

    std::string InsertNode::ToString() const
    {
        std::string output = "insert:\n";
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
        output += "  values: [";

        for (size_t i = 0; i < m_Values.size(); i++)
        {
            output += m_Values[i];

            if (i < m_Values.size() - 1)
            {
                output += ", ";
            }
        }

        output += "]\n";
        output += "  table: " + m_TableName;

        return output;
    }
}
