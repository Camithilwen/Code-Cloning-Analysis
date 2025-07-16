#include <iostream>
#include <algorithm>
#include <set>

std::set <int> s;

int main()
{
    int n;
    std::cin >> n;
    for(int i = 1;i <= n;i++)
    {
        int x;
        std::cin >> x;
        if(s.find(x) != s.end())
        {
            s.erase(x);
        }
        else
        {
            s.insert(x);
        }
    }
    std::cout << s.size();
    // system("pause");
    return 0;
}