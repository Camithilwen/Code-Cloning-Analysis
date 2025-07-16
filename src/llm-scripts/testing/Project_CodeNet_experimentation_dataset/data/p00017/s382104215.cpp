#include <cctype>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	string S; int C = 0;

	while (getline(cin, S))
	{
		for (int i = 0; i < 26; i++)
		{
			if (!(S.find("this") == string::npos && S.find("that") == string::npos && S.find("the") == string::npos))
			{
				cout << S << endl;

				goto Exit;
			}

			for (string::size_type j = 0; j < S.size(); j++)
			{
				if (isalpha(static_cast<int>(S[j])))
				{
					if (S[j] == 'z')
					{
						S[j] = 'a';
					}
					else
					{
						S[j]++;
					}
				}
			}
		}

	Exit:;

	}

	return 0;
}