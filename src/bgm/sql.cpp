#include "bgm/sql.hpp"

#include <sstream>

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


std::string Sql::getTableName()
{
    return std::string("ProgramInfo");
}

std::vector<Sql::Column> Sql::getColumns()
{
    return std::vector<Column> {
        Column("id",       "INTEGER PRIMARY KEY"),
        Column("pid",      "INTEGER NOT NULL"),
        Column("exitCode", "INTEGER NOT NULL")
    };
}

std::string Sql::getCreateTableString()
{
    std::ostringstream ss;

    ss << "CREATE TABLE " << getTableName() << "("
       << ""
       << ")";

    return ss.str();
}

END_BGM_NS
