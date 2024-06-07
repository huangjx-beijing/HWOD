#include <iostream>
#include <sstream>
#include <vector>
#include <string>

struct Person
{
    int value;
    Person* child1;
    Person* child2;
};

int main()
{
    int n = 0; // 人数
    std::cin >> n;

    // 创建n个人
    std::vector<Person> persons(n);

    std::string line;
    std::vector<int> numbers;

    std::getline(std::cin, line);

    // 使用字符串流解析这一行输入
    std::istringstream iss(line);
    int number;

    // 逐个读取整数并存入向量
    while (iss >> number)
    {
        numbers.push_back(number);
    }

    // 初始化每个人的金钱
    for (int i = 0; i < n; i++)
    {
        persons[i].value = numbers[i];
        persons[i].child1 = NULL;
        persons[i].child2 = NULL;
    }

    // 创建关系
    for (int i = 0; i < n - 1; i++)
    {
        int p = 0;
        int c = 0;
        std::cin >> p >> c;

        if (!persons[p - 1].child1)
        {
            persons[p - 1].child1 = &persons[c - 1];
        }
        else if (!persons[p - 1].child2)
        {
            persons[p - 1].child2 = &persons[c - 1];
        }
    }

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int temp = persons[i].value;

        if (persons[i].child1)
        {
            temp += persons[i].child1->value;
        }

        if (persons[i].child2)
        {
            temp += persons[i].child2->value;
        }

        if (temp > sum)
        {
            sum = temp;
        }
    }

    std::cout << sum << std::endl;

    return 0;
}