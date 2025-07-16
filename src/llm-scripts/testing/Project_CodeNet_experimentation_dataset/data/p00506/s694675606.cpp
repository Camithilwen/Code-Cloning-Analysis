#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int gcd(int a,int b){
	while(b){
		a%=b;
		swap(a,b);
	}
	return a;
}
int main(){
	int n;
	cin>>n;
	vector<int> line(n);
	for(int i=0;i<n;++i){
		cin>>line[i];
	}
	int man = line[0];
	for(int i=1;i<n;++i){
		man = gcd(man,line[i]);
	}
	vector<int> front;
	vector<int> back;
	for(int i=1;i*i<=man;++i){
		if(i*i==man){
			front.push_back(i);
			break;
		}
		if(man%i==0){
			front.push_back(i);
			back.push_back(man/i);
		}
	}
	for(int i=0;i<front.size();++i){
		cout<<front[i]<<endl;
	}
	for(int i=back.size()-1;i>=0;--i){
		cout<<back[i]<<endl;
	}
	return 0;
}
