#include <stdio.h>
#include <malloc.h>

struct Person
{
    int value;
    struct Person* child1;
    struct Person* child2;
};

int main()
{
    int n = 0; // 人数
    
    scanf("%d", &n);

    // 创建n个人
    struct Person* persons = (struct Person*)malloc(n * sizeof(struct Person));

    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &(persons[i].value));
    }
    
    // 创建关系
    for (int i = 0; i < n - 1; i++)
    {
        int p = 0;
        int c = 0;
        scanf("%d %d", &p, &c);

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

    printf("%d\r\n", sum);

    free(persons);

    return 0;
}