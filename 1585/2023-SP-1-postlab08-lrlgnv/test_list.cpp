#include "catch.hpp"
#include "list.h"

TEST_CASE("List Constructors", "[List]")
{
    List<int> list;
    SECTION("List is empty")
    {
        CHECK(list.length() == 0);
        CHECK(list.empty() == true);
    }

    for(int i =0; i < 5; i++)
    {
        list.append(i);
    }

    SECTION("Size of list changes")
    {
        CHECK(list.length() == 5);
        list.prepend(2);
        CHECK(list.length() == 6);
        list.pop();
        CHECK(list.length() == 5);
    }
    
    List<int> list2(list);
    SECTION("Is copied correctly")
    {
        for(int i = 0; i < list2.length(); i++)
        {
            CHECK(list2.head() == i);
            list2.pop();
        }
    }
}

TEST_CASE("Pop", "[List]")
{
    List<int> list;
    for(int i =0; i < 5; i++)
    {
        list.append(i);
    }
    List<int> list2(list);

    SECTION("Pop removes the first element")
    {
        list.pop();
        CHECK(list.head()==1);
    }


}

