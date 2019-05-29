#include <gtest/gtest.h>

#include <iostream>

#include "bgm/NamespaceDefines.hpp"
#include "bgm/sql.hpp"

BEGIN_BGM_NS

class TestSql : public testing::Test
{
public:
    Sql sql;
};

TEST_F(TestSql, testCreateTableString)
{
   //TODO 
    std::cout << "Sql::getColumnString: " <<
        sql.getCreateTableString() << std::endl;
}

END_BGM_NS
