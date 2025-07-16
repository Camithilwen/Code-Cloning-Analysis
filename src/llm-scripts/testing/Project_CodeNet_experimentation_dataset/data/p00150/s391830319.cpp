#include <iostream>
#include <vector>

constexpr bool divisible(const std::size_t n, const std::size_t m)
{
	return (0 == n % m);
}

constexpr bool help_prime(const std::size_t n, const std::size_t m)
{
	return (m * m <= n) ?
        !divisible(n, m) && help_prime(n, m + 1) :
        true;
}

constexpr bool prime(const std::size_t n)
{
	return (n <= 1) ?
        false :
        help_prime(n, 2);
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
    std::vector<std::size_t> ns;
    std::size_t n;
    
    while(std::cin >> n, n != 0)
    {
        ns.push_back(n);
    }

    for(const auto a : ns)
    {
        const auto&& t = find_twin_prime(a);
        std::cout << t.first << " " << t.second << std::endl;
    }
}