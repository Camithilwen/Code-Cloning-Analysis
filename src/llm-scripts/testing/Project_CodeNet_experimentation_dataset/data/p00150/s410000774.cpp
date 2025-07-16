#include <algorithm>
#include <cmath>
#include <iostream>
#include <list>
#include <vector>

constexpr bool divisible(const std::size_t n, const std::size_t m)
{
    return (0 == n % m);
}

std::vector<std::size_t> prime_table = {2};

bool prime(const std::size_t n)
{
    const std::size_t found_last_prime = prime_table.back();
    if(found_last_prime < n)
    {
        std::list<std::size_t> undefined_table;

        for(std::size_t i = found_last_prime + 1; i <= n; ++i)
        {
            undefined_table.push_back(i);
        }

        const std::size_t sn = std::sqrt(n);
        for(std::size_t p = 0; !undefined_table.empty() && p < prime_table.size(); ++p)
        {
            for(auto u = undefined_table.begin(); u != undefined_table.end();)
            {
                if(divisible(*u, prime_table.at(p)))
                {
                    u = undefined_table.erase(u);
                }
                else
                {
                    ++u;
                }
            }
            if(!undefined_table.empty() && found_last_prime <= prime_table.at(p))
            {
                prime_table.push_back(undefined_table.front());
                undefined_table.pop_front();
                if(sn < prime_table.back())
                {
                    break;
                }
            }
        }
        prime_table.insert(prime_table.end(), undefined_table.begin(), undefined_table.end());
    }
    return std::binary_search(prime_table.begin(), prime_table.end(), n);
}

std::pair<std::size_t, std::size_t> find_twin_prime(const std::size_t limit, const bool next_skip = false)
{
    return prime(limit) ?
        prime(limit - 2) ?
        std::make_pair(limit - 2, limit) :
        find_twin_prime(limit - (next_skip ? 3 : 1), true) :
        find_twin_prime(limit - (next_skip ? 2 : 1), false);
}

int main()
{
    std::size_t n;

    while(std::cin >> n, n != 0)
    {
        const auto&& t = find_twin_prime(n);
        std::cout << t.first << " " << t.second << std::endl;
    }
}