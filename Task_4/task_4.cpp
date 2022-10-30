#include <iostream>
#include <string>
#include <cmath>

void Hanoi(int disk, std::string source, std::string dest, std::string aux);
std::string left_parenthesis_appender(std::string str);
std::string right_parenthesis_appender(std::string str);

int task_1(int n)
{
    if (n == 1 || n == 0)
        return 1;
    return task_1(n - 1) + task_1(n - 2);
}

int task_2(int n, int k)
{
    if (k == 0 || k == n)
        return 1;
    return task_2(n - 1, k - 1) + task_2(n - 1, k);
}

void task_3(int n)
{
    Hanoi(n, "1", "3", "2");
}

std::string task_4(std::string str)
{
    std::string left_substr = left_parenthesis_appender(str.substr(0, ceil((double)str.length() / 2)));
    std::string right_substr = right_parenthesis_appender(str.substr(floor((double)str.length() / 2)));
    std::string result = left_substr + right_substr;
    if (str.length() % 2 == 1) {
        result.erase(str.length(), 1);
    }
    return result;
}

std::string task_5(std::string str)
{
    if (str.length() == 1)
        return str;
    if (str.length() == 2) {
        if (str.substr(0, 1) == str.substr(str.length() - 1)) {
            return "";
        }
        return str;
    }
    if (str.substr(0, 1) == str.substr(str.length() - 1)) {
        return task_5(str.substr(1, str.length() - 2));
    }

    return str.substr(0, 1) + task_5(str.substr(1, str.length() - 2)) + str.substr(str.length() - 1);
}

void test_task_1(int n)
{
    std::cout << "test task 1 : " << std::endl;
    std::cout << task_1(n) << std::endl;
}

void test_task_2(int n, int k)
{
    std::cout << "test task 2 : " << std::endl;
    std::cout << task_2(n, k) << std::endl;
}

void test_task_3(int n)
{
    std::cout << "test task 3 : " << std::endl;
    task_3(n);
}

void test_task_4(std::string str)
{
    std::cout << "test task 4 : " << std::endl;
    std::cout << task_4(str) << std::endl;
}

void test_task_5(std::string str)
{
    std::cout << "test task 5 : " << std::endl;
    std::cout << task_5(str) << std::endl;
}

void Hanoi(int disk, std::string source, std::string aux, std::string dest)
{
    if (disk == 1) {
        std::cout << "move Disk 1 from " + source + " to " + dest << std::endl;
    }
    else {
        Hanoi(disk - 1, source, dest, aux);
        std::cout << "move Disk " + std::to_string(disk) + " from " + source + " to " + dest << std::endl;
        Hanoi(disk - 1, aux, source, dest);
    }
}

std::string left_parenthesis_appender(std::string str)
{
    if (str.length() == 1)
        return "(" + str;
    return "(" + str.substr(0, 1) + left_parenthesis_appender(str.substr(1));
}

std::string right_parenthesis_appender(std::string str)
{
    if (str.length() == 1)
        return str + ")";
    return str.substr(0, 1) + ")" + right_parenthesis_appender(str.substr(1));
}

int main()
{
    test_task_1(4);
    test_task_2(5, 2);
    test_task_3(2);
    test_task_4("abcd");
    test_task_4("abcde");
    test_task_5("aabac");
    test_task_5("abbc");
    test_task_5("abbcdefbg");
    test_task_5("abbccfbg");

    return 0;
}

