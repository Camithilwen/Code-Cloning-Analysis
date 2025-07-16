#include<bits/stdc++.h>
using namespace std;
int n,a=-1,b=-1,mp[1005][1005];
int mex(vector<int> a){
	sort(a.begin(),a.end());
	int now=1;
	for(auto x:a){
		if(x>now)return now;
		else if(x==now)++now;
	}
	return now;
}
void p21(int x,int y){
	vector<int>t;
	if(mp[x-1][y])t.push_back(mp[x-1][y]);
	if(mp[x][y-1])t.push_back(mp[x][y-1]);
	if(mp[x][y+1])t.push_back(mp[x][y+1]);
	if(mp[x+1][y-1])t.push_back(mp[x+1][y-1]);
	if(mp[x+1][y+1])t.push_back(mp[x+1][y+1]);
	if(mp[x+2][y])t.push_back(mp[x+2][y]);
	mp[x][y]=mp[x+1][y]=mex(t);
}
void p12(int x,int y){
	vector<int>t;
	if(mp[x][y-1])t.push_back(mp[x][y-1]);
	if(mp[x-1][y])t.push_back(mp[x-1][y]);
	if(mp[x+1][y])t.push_back(mp[x+1][y]);
	if(mp[x-1][y+1])t.push_back(mp[x-1][y+1]);
	if(mp[x+1][y+1])t.push_back(mp[x+1][y+1]);
	if(mp[x][y+2])t.push_back(mp[x][y+2]);
	mp[x][y]=mp[x][y+1]=mex(t);
}
void p44(int x,int y){
	p12(x,y);
	p12(x+1,y);
	p12(x+2,y+2);
	p12(x+3,y+2);
	p21(x+2,y);
	p21(x+2,y+1);
	p21(x,y+2);
	p21(x,y+3);
}
void p55(int x,int y){
	p12(x,y+1);
	p12(x,y+3);
	p12(x+1,y+1);
	p12(x+4,y);
	p12(x+4,y+2);
	p21(x,y);
	p21(x+1,y+4);
	p21(x+2,y);
	p21(x+2,y+3);
	p21(x+3,y+4);
}
void p45(int x,int y){
	p12(x,y+1);
	p12(x,y+3);
	p12(x+1,y+3);
	p12(x+2,y);
	p12(x+3,y);
	p12(x+3,y+2);
	p21(x,y);
	p21(x+1,y+2);
	p21(x+2,y+4);
}
void p54(int x,int y){
	p21(x+1,y);
	p21(x+3,y);
	p21(x+3,y+1);
	p21(x,y+2);
	p21(x,y+3);
	p21(x+2,y+3);
	p12(x,y);
	p12(x+2,y+1);
	p12(x+4,y+2);
}
void p33(int x,int y){
	p12(x,y);
	p21(x+1,y+2);
}
const char s7[7][8]={".aaeeff","b..gghh","b..iijj","cko....","cko....","dpq....","dpq...."};
int main(){
	cin>>n;
	if(n<=2){puts("-1");return 0;}
	if(n==7){
		for(int i=0;i<7;++i)puts(s7[i]);
		return 0;
	}
	if(n==11){
		for(int i=1;i<=7;++i)for(int j=1;j<=7;++j)mp[i][j]=s7[i-1][j-1]-'a'+1;
		p44(8,8);
	}
	if(n%3==0){
		for(int i=1;i<=n;i+=3){
			for(int j=1;j<=n;j+=3){
				p33(i,j);
			}
		}
	}else{
		for(int i=0;i*5<=n;++i){
			if((n-i*5)%4==0){
				a=i,b=(n-i*5)/4;
			}
		}
		for(int i=0;i<a;++i){
			for(int j=0;j<a;++j){
				p55(i*5+1,j*5+1);
			}
		}
		for(int i=0;i<b;++i){
			for(int j=0;j<b;++j){
				p44(i*4+a*5+1,j*4+a*5+1);
			}
		}
		for(int i=0;i<a;++i){
			for(int j=0;j<b;++j){
				p54(i*5+1,j*4+a*5+1);
			}
		}
		for(int i=0;i<b;++i){
			for(int j=0;j<a;++j){
				p45(i*4+a*5+1,j*5+1);
			}
		}
	}
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j){
		putchar(mp[i][j]?mp[i][j]+'a'-1:'.');
		if(j==n)putchar('\n');
	}
	return 0;
}