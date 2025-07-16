#include <iostream>
#include <string>
#include <algorithm>
int main(void)
{
    std::string str1;
    std::string str2;
    std::cin >> str1 >> str2;
    int l1 = str1.size();
    int l2 = str2.size();
    int A[l1 + 1][l2 + 1] = {};
    for (int i = 0; i <= l1; i++)
    {
        for (int j = 0; j <= l2; j++)
        {
            if (i == 0)
            {
                A[i][j] = j;
            }
            else if (j == 0)
            {
                A[i][j] = i;
            }
            else
            {
                A[i][j] = std::min(A[i - 1][j] + 1, A[i][j - 1] + 1);
                if (str1[i - 1] == str2[j - 1])
                {
                    A[i][j] = std::min(A[i - 1][j - 1], A[i][j]);
                }
                else
                {
                    A[i][j] = std::min(A[i - 1][j - 1] + 1, A[i][j]);
                }
            }
            //std::cout << A[i][j] << " ";
        }
        //std::cout << "\n";
    }
    std::cout << A[l1][l2] << "\n";
    return 0;
}
