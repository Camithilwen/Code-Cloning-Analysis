#include <algorithm>
#include <iostream>
#include <cstdio>
#include <queue>

const int MAXN = 1e6 + 10;

class no_solution: std::exception
{
public:
	const char * what() const noexcept
	{
		return "There is no solution under such constrains";
	}
};

int len;
char a[MAXN], b[MAXN];

auto findSolution() -> std::deque<int>::size_type
{
	std::deque<int>::size_type answer = 0;
	std::deque<int> DQ;
	DQ.push_back(len + 1);

	int k = len + 1, offset = 0;
	for (int i = len; i > 0; i--)
	{
		int t = k;
		k = std::min(i, k);
		while (k && a[k] != b[i])
			k--;
		if (k <= 0)
			throw no_solution();

		if (k == t)
		{
			while (!DQ.empty() && DQ.back() + offset >= i)
				DQ.pop_back();
			DQ.push_back(i - offset);
		}
		else
		{
			offset--;
			if (i != k)
				answer = std::max(answer, DQ.size()), DQ.push_front(k - offset);
		}
	}
	return answer;
}

int main()
{
	std::cin >> len >> (a+1) >> (b+1) ;

	try
	{
		std::cout << findSolution() << std::endl ;
	}
	catch(no_solution & x)
	{
		std::cout << "-1" << std::endl ;
		std::cerr << x.what() << std::endl ;
	}

	return 0;
}
