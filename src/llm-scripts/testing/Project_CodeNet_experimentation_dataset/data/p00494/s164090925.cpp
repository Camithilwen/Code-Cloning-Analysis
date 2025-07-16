#include <iostream>
#include <string>

using namespace std;

string S;
int N;

int main(void)
{
	cin >> S;
	N = S.length();
	int offset = 0;
	int result = 0;
	while(offset < N)
	{
		if(S[offset] == 'O')
		{
			int of = offset;
			int c_O = 0;
			while(S[of] == 'O')
			{
				of++;
				c_O++;
			}
			bool OK = true;
			for(int i = offset - 1;i >= offset - c_O;i--)
			{
				if(i >= 0)
				{
					if(S[i] != 'J')
					{
						OK = false;
						break;
					}
				}
				else
				{
					OK = false;
					break;
				}
			}
			for(int i = of;i < of + c_O;i++)
			{
				if(i < N)
				{
					if(S[i] != 'I')
					{
						OK = false;
						break;
					}
				}
				else
				{
					OK = false;
					break;
				}
			}
			if(OK)
			{
				result = max(result,c_O);
			}
			offset = of;
		}
		else
			offset++;
	}
	cout << result << endl;
	return 0;
}