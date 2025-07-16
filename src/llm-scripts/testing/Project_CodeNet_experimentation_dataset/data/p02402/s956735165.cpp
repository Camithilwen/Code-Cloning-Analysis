#include <iostream>

int main(int argc, char** argv)
{
	int n;
	std::cin >> n;

	int min = 1000000;
	int max = -1000000;
	long long sum = 0;
	
	for (int i = 0; i < n; ++i)
	{
		int a;
		std::cin >> a;

		if (min > a)
		{
			min = a;
		}
		if (max < a)
		{
			max = a;
		}

		sum += a;
	}

	std::cout << min << " " << max << " " << sum << std::endl;
}
