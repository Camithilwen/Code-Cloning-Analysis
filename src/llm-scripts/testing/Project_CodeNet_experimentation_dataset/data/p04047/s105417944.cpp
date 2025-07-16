#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define FOR(i,a,n) for(int (i) = (a);i < (n);i++)

int main()
{
    int n = 0, i = 0, output = 0;
    cin >> n;
    vector<int> skewer(2 * n, 0);

    for(i = 0;i < 2*n; i++)
    {
        int temp = 0;
        cin >> temp;
        skewer.push_back(temp);
    }
    sort(skewer.begin(), skewer.end());
    i = 0;
    while(i < skewer.size())
    {
        output = output + skewer[i];
        i = i + 2;
    }
    cout << output;
	return 0;
}
