#include "bgm/sql.hpp"

#include <sstream>
#include <algorithm>
#include <string>
#include <functional>
#include <numeric>
#include <vector>

BEGIN_BGM_NS

std::string Sql::Column::printColumn() const
{
    std::ostringstream ss;
    ss << name << " " << sqlType;
    return ss.str();
}

Sql::Column::Column(const std::string& _name,
               const std::string& _sqlType)
    : name(_name), sqlType(_sqlType)
{}

Sql::Column::Column(const Column& other)
    : Column(other.name, other.sqlType)
{}

Sql::Column::~Column() {}

const std::string Sql::integerType = "INTEGER NOT NULL";
const std::string Sql::dateType = "DATETIME NOT NULL";
const std::string Sql::textType = "TEXT NOT NULL";


std::string Sql::getTableName()
{
    return std::string("ProgramInfo");
}

std::vector<Sql::Column> Sql::getColumns()
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
    std::vector<std::string> empty;

    const std::string divider = ", ";
    const auto reduceF = 
        [divider](std::vector<std::string>& acc,
           const Column& a)
        {
            acc.emplace_back(a.printColumn());
            acc.emplace_back(divider);
            return acc;
        };

    const std::vector<Column> columns = getColumns();
    std::vector<std::string> accumulatedStrings = 
        std::accumulate(columns.cbegin(),
            columns.cend(), empty, reduceF);
    
    //remove the last divider
    if(accumulatedStrings.size() > 0 &&
            accumulatedStrings.back() == divider)
    {
        accumulatedStrings.pop_back();
    }

    //combine the strings
    std::ostringstream ss;
    for(const auto& x : accumulatedStrings)
    {
        ss << x;
    }

    return ss.str();
}

std::string Sql::getCreateTableString()
{
    std::ostringstream ss;

    ss << "CREATE TABLE " << getTableName() << "("
       << getColumnString()
       << ");";

    return ss.str();
}

END_BGM_NS
