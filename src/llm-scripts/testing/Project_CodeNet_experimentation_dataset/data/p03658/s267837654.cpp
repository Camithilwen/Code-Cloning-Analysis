#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int LLI;

int main()
{
	int a, b, ans = 0;
	cin >> a >> b;
	int arr[a];
	for(int i = 0; i < a; i++)
		cin >> arr[i];
	sort(arr,arr+a);
	for(int i = a - b; i < a; i++)
		ans += arr[i];
	cout << ans;
}