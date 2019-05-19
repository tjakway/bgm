#include "bgm/sql.hpp"

#include <sstream>
#include <algorithm>
#include <string>
#include <functional>

BEGIN_BGM_NS

std::string Column::printColumn() const
{
    std::ostringstream ss;
    ss << name << " " << sqlType;
    return ss.str();
}

Column::Column(const std::string& _name,
               const std::string& _sqlType)
    : name(_name), sqlType(_sqlType)
{}

Column::Column(const Column& other)
    : Column(other.name, other.sqlType)
{}

Column::~Column() {}

const std::string Sql::integerType = "INTEGER NOT NULL";
const std::string Sql::dateType = "DATETIME NOT NULL";
const std::string Sql::textType = "TEXT NOT NULL";


std::string Sql::getTableName()
{
    return std::string("ProgramInfo");
}

std::vector<Column> Sql::getColumns()
{
    return std::vector<Column> {
        Column("id",          "INTEGER PRIMARY KEY"),
        Column("pid",         integerType),
        Column("exitCode",    integerType),
        Column("timeStarted", dateType),
        Column("timeExited",  "DATETIME"),
        Column("stdout",      textType),
        Column("stderr",      textType),
        Column("program",     textType),
        Column("args",        textType)
    };
}

std::string Sql::getColumnString()
{
    const auto reduceF = 
        [](const Column& a,
           const Column& b)
        {
            std::ostringstream ss;
            ss << a.printColumn() << ", " << b.printColumn();
            return ss.str();
        };

    const std::vector<Column> columns = getColumns();
    const std::string res = std::reduce(columns::cbegin(),
            columns::cend(), reduceF);
    return res;
}

std::string Sql::getCreateTableString()
{
    ostringstream ss;

    ss << "CREATE TABLE " << getTableName() << "("
       << getColumnString()
       << ");";

    return ss.str();
}

END_BGM_NS
