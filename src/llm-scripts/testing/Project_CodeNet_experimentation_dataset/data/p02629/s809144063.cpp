#include <iostream>
#include <vector>
#include <string>
#define rep(i,N) for(int i=0;i<(N);i++)
using namespace std;

int main(){
	long long N,i=0;
	cin>>N;
	vector<long long> p;

	while(N!=0){
		N=N-1;
		p.push_back(N % 26);
		N = N / 26;
		i++;
	}
	string res = "";
	for(int i = p.size() -1 ; i >= 0 ; i-- )res += (char)('a' +p[i]);
	cout<<res<<endl;
}