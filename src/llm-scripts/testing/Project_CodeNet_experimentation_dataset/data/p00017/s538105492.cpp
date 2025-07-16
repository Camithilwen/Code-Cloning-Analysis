#include <iostream>
#include <cctype>
#include <string>
using namespace std;

string tar[] = { "the", "this", "that" };

int main()
{
	string in;
	while (getline(cin, in))
	{
		string ans;
		for (int i=0; i<26; i++)
		{
			ans = in;
			for (int k=0; k<ans.size(); k++)
			{
				if (islower(ans[k]))
				{
					int r = i - ('z' - ans[k]);
					if (r > 0)
						ans[k] = (char) ((int) 'a' + r - 1);
					else
						ans[k] = (char) ((int) ans[k] + i);
				}
			}
			if (	   ans.find(tar[0], 0) != string::npos
				|| ans.find(tar[1], 0) != string::npos
				|| ans.find(tar[2], 0) != string::npos)
				break;
		}

		cout << ans << endl;
	}
}