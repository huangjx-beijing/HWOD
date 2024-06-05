#include <iostream>
#include <array>

int main()
{
    int count; // 数字个数
    int row;   // 行数

    std::cin >> count >> row;

    if (count <= 0 || row <= 0)
    {
        return 1;
    }

    // 计算列数
    int col = count / row + ((0 == count % row) ? 0 : 1);

    // 矩阵
    int* mat = new int[row * col] { 0 };

    int i = 1;  // 当前数字
    int r = 0;  // 当前行数
    int c = 0;  // 当前列数
    while (i <= count)
    {
        while (c < col && mat[r * col + c] == 0 && i <= count)
        {
            mat[r * col + c] = i;
            c++;
            i++;
        }

        r++;
        c--;

        while (r < row && mat[r * col + c] == 0 && i <= count)
        {
            mat[r * col + c] = i;
            r++;
            i++;
        }

        r--;
        c--;

        while (c >= 0 && mat[r * col + c] == 0 && i <= count)
        {
            mat[r * col + c] = i;
            c--;
            i++;
        }

        r--;
        c++;

        while (r >= 0 && mat[r * col + c] == 0 && i <= count)
        {
            mat[r * col + c] = i;
            r--;
            i++;
        }

        r++;
        c++;
    }

    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            int value = mat[i * col + j];
            if (value > 0)
            {
                std::cout << mat[i * col + j] << " ";
            }
            else
            {
                std::cout << "* ";
            }
        }
        std::cout << std::endl;
    }

    delete[]mat;
}