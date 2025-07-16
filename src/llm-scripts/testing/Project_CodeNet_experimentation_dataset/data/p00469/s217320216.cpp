#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;


void solve()
{
	int n, k;
	while (cin >> n >> k, n || k)
	{
		vector<string> card(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> card[i];
		}
		set<string> S;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (k == 2)
				{
					if (i != j)
					{
						S.insert(card[i] + card[j]);
						S.insert(card[j] + card[i]);
					}
				}
				else
				{
					if (k == 3)
					{
						for (int a = 0; a < n; ++a)
						{
							if (i != j && j != a && i != a)
							{
								S.insert(card[i] + card[j] + card[a]);
								S.insert(card[i] + card[a] + card[j]);
								S.insert(card[j] + card[i] + card[a]);
								S.insert(card[j] + card[a] + card[i]);
								S.insert(card[a] + card[i] + card[j]);
								S.insert(card[a] + card[j] + card[i]);
							}
						}
					}
					else
					{
						for (int a = 0; a < n; ++a)
						{
							for (int b = 0; b < n; ++b)
							{
								if (i != j && i != a && i != b &&
									j != a && j != b &&
									a != b)
								{
									S.insert(card[i] + card[j] + card[a] + card[b]);
									S.insert(card[i] + card[j] + card[b] + card[a]);
									S.insert(card[i] + card[a] + card[b] + card[j]);
									S.insert(card[i] + card[a] + card[j] + card[b]);
									S.insert(card[i] + card[b] + card[a] + card[j]);
									S.insert(card[i] + card[b] + card[j] + card[a]);
									
									S.insert(card[j] + card[i] + card[a] + card[b]);
									S.insert(card[j] + card[i] + card[b] + card[a]);
									S.insert(card[j] + card[a] + card[b] + card[i]);
									S.insert(card[j] + card[a] + card[i] + card[b]);
									S.insert(card[j] + card[b] + card[a] + card[i]);
									S.insert(card[j] + card[b] + card[i] + card[a]);

									S.insert(card[a] + card[i] + card[b] + card[j]);									
									S.insert(card[a] + card[i] + card[j] + card[b]);
									S.insert(card[a] + card[j] + card[b] + card[i]);
									S.insert(card[a] + card[j] + card[i] + card[b]);
									S.insert(card[a] + card[b] + card[i] + card[j]);
									S.insert(card[a] + card[b] + card[j] + card[i]);

									S.insert(card[b] + card[i] + card[a] + card[j]);
									S.insert(card[b] + card[i] + card[j] + card[a]);
									S.insert(card[b] + card[a] + card[i] + card[j]);
									S.insert(card[b] + card[a] + card[j] + card[i]);
									S.insert(card[b] + card[j] + card[a] + card[i]);
									S.insert(card[b] + card[j] + card[i] + card[a]);
								}
							}
						}
					}
				}
			}
		}
		cout << S.size() << endl;
	}
}

int main()
{
	solve();
	return(0);
}