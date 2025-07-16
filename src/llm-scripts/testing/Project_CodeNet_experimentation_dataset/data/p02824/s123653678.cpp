#include <bits/stdc++.h>
using namespace std;
#define oo 1000000010
#define mod 1000000007
const int N = 100010;
int n , m , arr[N] , v , p;

bool check(int mid){
	int val = arr[mid] + m;
	if(arr[n - p] > val)
		return false;
	long long all = 0;
	for(int i = 0 ;i < n - p + 1;i++){
		all += min(m , max(0 , val - arr[i]));
	}
	all /= m;
	if(all >= v - (p - 1))
		return true;
	return false;
}

int main(){
	scanf("%d%d%d%d",&n,&m,&v,&p);
	for(int i = 0 ;i < n;i++){
		scanf("%d",&arr[i]);
	}
	sort(arr,arr+n);
	int low = 0 , high = n - 1 , res = n , mid;
	while(high >= low){
		mid = (low + high) / 2;
		if(check(mid))
			res = mid , high = mid - 1;
		else
			low = mid + 1;
	}
	cout << n - res << endl;
	return 0;
}
