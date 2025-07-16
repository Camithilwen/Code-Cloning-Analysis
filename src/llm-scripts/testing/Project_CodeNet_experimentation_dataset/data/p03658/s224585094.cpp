#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
	int n,k;
	cin>>n>>k;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	sort(arr,arr+n,greater<int>());
	int result{};
	for(int i=0;i<k;i++)
		result += arr[i];
	cout<<result;
	return 0;
}