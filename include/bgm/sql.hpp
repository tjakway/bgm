#pragma once

#include <string>
#include <vector>

#include "bgm/NamespaceDefines.hpp"


BEGIN_BGM_NS

class Sql
{
    class Column
    {
        std::string name, sqlType;
    public:
        Column(const std::string&, const std::string&);
        Column(const Column&);

        std::string printColumn() const;

        virtual ~Column();
    };

    static const std::string integerType, dateType, textType;

    static std::vector<Column> getColumns();
    static std::string getColumnString();
    static std::string getTableName();
public:
    static std::string getCreateTableString();
};

END_BGM_NS
