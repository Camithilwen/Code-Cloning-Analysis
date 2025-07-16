#include <iostream>
#include<algorithm>
using namespace std;
int g[100],jyunni[100];
int n;
void katimake(int a,int b,int c,int d){
	if(c>d){g[a-1]+=3;}
	else if(d>c){g[b-1]+=3;}
	else{
		g[a-1]++;
		g[b-1]++;
	}
	}
int main() {
	cin>>n;
	for(int i = 0;i<100;i++){
		g[i]=0;
	}
	int p,q,r,s;
	while(cin>>p>>q>>r>>s){katimake(p,q,r,s);}
	int jyu = 1;
	int saidai=0;
	for(int i= 0;i<n;i++){saidai=max(saidai,g[i]);}
	for(int p=saidai;saidai>=0;saidai--){
		int y=0;
		for(int i =0;i<n;i++){
		if(g[i]==saidai){
			jyunni[i]=jyu;
			y++;
			}
		}
		jyu+=y;
	}
	for(int i = 0;i<n;i++){
		cout<<jyunni[i]<<endl;
	}
	return 0;
}