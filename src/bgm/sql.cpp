#include "bgm/sql.hpp"

#include <sstream>

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


std::string Sql::getTableName()
{
    return std::string("ProgramInfo");
}

std::vector<Column> Sql::getColumns()
{
    return std::vector<Column> {
        Column("id",       "INTEGER PRIMARY KEY"),
        Column("pid",      "INTEGER NOT NULL"),
        Column("exitCode", "INTEGER NOT NULL"),
        Column("")
    };
}

std::string Sql::getCreateTableString()
{
    ostringstream ss;

    ss << "CREATE TABLE " << getTableName() << "("
       << ""
       << ")";

    return ss.str();
}

END_BGM_NS
