#include <bits/stdc++.h>
using namespace std;


bool upd[(1<<18)];
int val[(1<<18)];

void Set(int a,int b,int x,int k=0,int l=0,int r=(1<<17)){
	if(b<=l || r<=a)return;

	if( r-l>1 && upd[k] ){
		upd[k*2+1] = upd[k*2+2] = 1;  
		val[k*2+1] = val[k*2+2] = val[k];
	}
	upd[k]=0;

	if(a<=l && r<=b){
		upd[k]=1;
		val[k]=x;
	}
	else{
		Set(a,b,x,k*2+1,l,(l+r)/2);
		Set(a,b,x,k*2+2,(l+r)/2,r);
		val[k]=min(val[k*2+1],val[k*2+2]);
	}
}
int Find(int a,int b,int k=0,int l=0,int r=(1<<17)){
	if(b<=l || r<=a)return INT_MAX;

	if( r-l>1 && upd[k] ){
		upd[k*2+1] = upd[k*2+2] = 1;  
		val[k*2+1] = val[k*2+2] = val[k];
	}
	upd[k]=0;

	if(a<=l && r<=b) return val[k];
	else{
		int L = Find(a,b,k*2+1,l,(l+r)/2);
		int R = Find(a,b,k*2+2,(l+r)/2,r);
		return min(L,R);
	}
}

int n,m,a,b,c,d;

int main(){
	memset(upd,0,sizeof(upd));
	fill(val,val+(1<<18),INT_MAX);
	cin>>n>>m;
	while(m--){
		cin>>a>>b;
		if(a){
			cout<<Find(b,b+1)<<endl;
		}
		else{
			cin>>c>>d;
			Set(b,c+1,d);
		}
	}
}
