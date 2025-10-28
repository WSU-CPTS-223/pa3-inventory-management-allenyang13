#include <cassert>
#include <iostream>
#include "Hash.h"

void testInsertFind()
{
    std::cout << "Running Insert and Find Test\n";

    HashTable<std::string, int> testTable;

    testTable.insert("apple", 10);
    testTable.insert("banana", 20);
    assert(testTable.find("apple") != nullptr && *testTable.find("apple") == 10);
    assert(testTable.find("banana") != nullptr && *testTable.find("banana") == 20);

    assert(testTable.find("badapple") == nullptr);

    std::cout << "Insert and Find Success\n";
}

void testOverwrite()
{
    std::cout << "Running Overwrite Test\n";

    HashTable<std::string, int> testTable;

    testTable.insert("apple", 10);
    testTable.insert("apple", 20);

    assert(testTable.find("apple") != nullptr && *testTable.find("apple") == 20);

    std::cout << "Overwrite Passed\n";
}

void testCallback()
{
    std::cout << "Running call all function test\n";

    HashTable<std::string, int> testTable;

    testTable.insert("apple", 1);
    testTable.insert("banana", 2);
    testTable.insert("kiwi", 3);

    int sum = 0;
    testTable.functionCallAll([&](const std::string &, const int &value)
    {
        sum += value; 
    });

    assert(sum == 6);

    HashTable<std::string, int> emptyTable;
    int count = 0;
    emptyTable.functionCallAll([&](const std::string&, const int&) {
        count++;
    });

    assert(count == 0);

    std::cout << "Callbacks success\n";

}

int main()
{
    testInsertFind();
    testOverwrite();
    testCallback();

    std::cout << "All tests passed\n";
    return 0;
}