#include <iostream>
#include <vector>

int main()
{
    long long N;
    std::cin >> N;
    long long n_r = 0, n_g = 0, n_b = 0;
    std::vector<char> S(N);
    for (long long i = 0; i < N; i++)
    {
        char c;
        std::cin >> c;
        S[i] = c;
        if (c == 'R')
        {
            n_r++;
        }
        else if (c == 'G')
        {
            n_g++;
        }
        else if (c == 'B')
        {
            n_b++;
        }
        else
        {
            return -1;
        }
    }

    long long count = 0;
    for (long long j = 1; j < N - 1; j++)
    {
        for (long long diff = 1; j - diff >= 0 && j + diff < N; diff++)
        {
            long long i = j - diff;
            long long k = j + diff;
            if (S[i] != S[j] && S[j] != S[k] && S[k] != S[i])
            {
                count++;
            }
        }
    }
    std::cout << n_r * n_g * n_b - count << std::endl;
}