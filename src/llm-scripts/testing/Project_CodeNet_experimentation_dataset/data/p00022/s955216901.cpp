#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	
	int n = 1;
	std::cin >> n;


	while (n)
	{
		std::vector<int32_t> num_list{};

		while (n--)
		{
			int tmp = 0;
			std::cin >> tmp;
			num_list.push_back(tmp);
		}

		std::vector<int32_t> comfarm_list{};
		std::vector<int32_t> sum_list{};
		for( auto num : num_list )
		{
			for (auto& sum : sum_list)
			{
				if (num < 0)
				{
					comfarm_list.push_back(sum);
				}
				sum += num;
			}
			sum_list.push_back(num);
		}

		for (auto sum : sum_list)
		{
			comfarm_list.push_back(sum);
		}

		int32_t max_sum = *( std::max_element(comfarm_list.begin(),comfarm_list.end()) );
		std::cout << max_sum << std::endl;
	
		std::cin >> n;
	}

	return 0;
}