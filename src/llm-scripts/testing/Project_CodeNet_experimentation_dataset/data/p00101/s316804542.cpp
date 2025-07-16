#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	int n, i, j, k, c, x;
	char s[1001], r[1001], t[8] = "Hoshino";
	cin >> n;
	cin.ignore(1024, '\n');
	for (i = 0; i < n; i++)
	{
		cin.getline(s, sizeof(s));
		c = 0;
		for (j = 0; j < strlen(s); j++)
		{
			r[c] = s[j];
			c++;
			if (s[j] == 'H')
			{
				for (k = j+1, x = 0; k < j+7; k++, c++)
				{
					if (s[k] == t[k-j])
					{
						if (k == j+6)
							r[c] = 'a';
						else
							r[c] = t[k-j];
						x++;
					}
					else
					{
						r[c] = s[k];
						break;
					}
				}
				j+=x;
			}
		}
		r[strlen(s)] = '\0';
		cout << r << endl;
	}
}