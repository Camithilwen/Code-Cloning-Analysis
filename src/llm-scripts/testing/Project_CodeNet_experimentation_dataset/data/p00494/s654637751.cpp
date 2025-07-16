#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
	int x,y,z;
	int ans=0;
	x=y=z=0;
	char c='\0';
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		bool f=true;
		if(s[i]=='J'){
			if(c=='J')x++;
			else {
				x=1;
				y=z=0;
			}
		}else if(s[i]=='O'){
			if(c=='J' || c=='O')y++;
			else f=false;
		}else{
			if(c=='O' || c=='I'){
				z++;
				if(y<=x && y<=z)ans=max(ans,y);
			}
			else f=false;
		}
		if(f)c=s[i];
		else c='\0';
	}
	cout<<ans<<endl;
	return 0;
}