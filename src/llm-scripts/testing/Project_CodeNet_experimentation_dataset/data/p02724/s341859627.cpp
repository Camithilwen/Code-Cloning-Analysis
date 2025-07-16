#include<iostream>
#include<vector>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;

int main(){
	long long int x;
	cin>>x;
	long long int sum;
	sum = (x/500)*1000;
	x -= (x/500)*500;
	sum += (x/5)*5;
	cout<<sum<<endl;
	return 0;
}