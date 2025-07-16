#include<iostream>
using namespace std;

class meb{
public:
	int num;
	unsigned long long tanka;
	unsigned long long count;
	unsigned long long sum;
};

int main(){
	int n;
	while(1){
		int cc=0;
		cin>>n;
		meb st[n];
		if(n==0)break;
		for(int i=0;i<n;i++){
			cin>>st[i].num>>st[i].tanka>>st[i].count;
		}
		for(int k=0;k<n;k++){
			st[k].sum=st[k].tanka*st[k].count;
		}
		for(int j=0;j<n;j++){
			for(int l=j+1;l<n;l++){
				if(st[j].num==st[l].num){
					(st[j].sum)=(st[j].sum)+(st[l].sum);
					st[l].sum=0;
				}
			}
		}
		for(int a=0;a<n;a++){
			if(st[a].sum>=1000000)cout<<st[a].num<<endl;
			else cc++;
		}
		if(cc==n)cout<<"NA"<<endl;
	}
	return 0;
}