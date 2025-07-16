#include<iostream> //53~70
using namespace std;

int main(){
	int a[1000];
	int b[1000];
	int t[1000];
	int n=0;
	int m=0;
	int i=0;
	int j=0;
	int k=0;
	
	cin>>n;
	cin>>m;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	for(i=0;i<m;i++){
		cin>>b[i];
	}
	for(i=0;i<1000;i++){
		t[i]=0;
	}
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(b[i]>=a[j]){
				t[j]++;
				break;
			}
		}
	}
	for(i=0;i<n;i++){
		if(t[k]<t[i]){
			k=i;
		}
	}
	k++;
	cout<<k<<endl;
}