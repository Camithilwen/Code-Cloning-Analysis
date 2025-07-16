#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	int n, x;
	cin >> n >> x;
	vector<int> a;
	int i, count = 0;
	for(i=0; i<n; i++){
		int p;
		cin >> p;
		a.push_back(p);
	}
	sort(a.begin(), a.end());
	for(i=0; i<n; i++){
		if(a[i]>x){
			x = 0;
			break;
		}
		else{
			count++;
			x = x-a[i];
		}
	}
	if(x) count = count - 1;
	cout << count << endl;
	return 0;
}
