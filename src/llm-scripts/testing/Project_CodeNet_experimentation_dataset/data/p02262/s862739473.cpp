#include<iostream>
using namespace std;

int x[10000000];
int G[20];
int v;
int w;
int cnt=0;
int m;
int n;

void sort1(int x[],int n,int g){
	for(int i=g;i<n;i++){
		v=x[i];
		w=i-g;
		while(w>=0 && x[w]>v){
			x[w+g]=x[w];
			w=w-g;
			cnt++;
		}
		x[w+g]=v;
	}
}

void sort2(int x[],int n){
	cnt=0;
	for(int h=0;h<20;h++){
		if(G[h]>n){
			m=h;
			break;
		}
	}
	cout<<m<<endl;
	for(int h=m-1;h>=0;h--){
		cout<<G[h];
		if(h){
			cout<<' ';
		}
		sort1(x,n,G[h]);
	}
	cout<<endl;
}

int main(){
	G[0]=1;
	for(int i=1;i<20;i++){
		G[i]=G[i-1]*3+1;
	}
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x[i];
	}
	sort2(x,n);
	cout<<cnt<<endl;
	for(int i=0;i<n;i++){
		cout<<x[i]<<endl;
	}
	return 0;
}