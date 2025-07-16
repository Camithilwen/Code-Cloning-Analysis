#include<iostream>
#include<vector>
#include<string>
#include<sstream>
int main()
{
	std::vector<std::string>result;
	for (std::string s; std::getline(std::cin, s);)
	{
		int delta = 0;
		std::stringstream ss;
		ss << s;
		while (!ss.eof())
		{
			std::string temp;
			ss >> temp;
			if (temp.length() == 3 && temp[0] != '.' && temp[1] != '.' && temp[2] != '.')
			{
				int d1 = temp[0] - 't';
				int d2 = temp[1] - 'h';
				int d3 = temp[2] - 'e';
				for (auto i : { &d1,&d2,&d3 })
				{
					if (*i < 0)
					{
						*i += 26;
					}
				}
				if (d1 == d2 && d2 == d3)
				{
					delta = temp[0] - 't';
					break;
				}
			}
			else if (temp.length() == 4 && temp[0] != '.' && temp[1] != '.' && temp[2] != '.' && temp[3] != '.')
			{
				int d1 = temp[0] - 't';
				int d2 = temp[1] - 'h';
				int d3 = temp[2] - 'i';
				int d4 = temp[3] - 's';
				for (auto i : { &d1,&d2,&d3,&d4 })
				{
					if (*i < 0)
					{
						*i += 26;
					}
				}
				if (d1 == d2 && d2 == d3 && d3 == d4)
				{
					delta = temp[0] - 't';
					break;
				}
				d1 = temp[0] - 't';
				d2 = temp[1] - 'h';
				d3 = temp[2] - 'a';
				d4 = temp[3] - 't';
				for (auto i : { &d1,&d2,&d3,&d4 })
				{
					if (*i < 0)
					{
						*i += 26;
					}
				}
				if (d1 == d2 && d2 == d3 && d3 == d4)
				{
					delta = temp[0] - 't';
					break;
				}
			}
		}
		result.push_back(std::string(s.length(), 'a'));
		for (int i = 0; i < s.length(); i++)
		{
			result.back()[i] = 'a' <= s[i] && s[i] <= 'z' ? (s[i] - delta - 'a') % 26 + 'a' : s[i];
		}
	}
	for (auto i : result)
	{
		std::cout << i << std::endl;
	}
	return 0;
}
