#include <iostream>
#include <ctime>
#include <forward_list>

class Test
{
public:
bool operator < (const Test& t)
{
    return a < t.a;
}
bool operator == (const Test& t)
{
    return a == t.a;
}

int a;
};

int main(int, char**){
    Test a, b;
    a.a = 1;
    b.a = 2;
    std::forward_list<int> test_list;
    std::cout << (a < b) << std::endl;
    std::cout << (a == b) << std::endl;
}
