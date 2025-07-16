//C
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int main(){
	string d="";
	d.resize(52);
	for(int i=0;i<26;i++)d[i]='a'+i;
	for(int i=0;i<26;i++)d[i+26]='A'+i;
	int num;
	//cout<<d<<endl;
	while(true){
	cin>>num;
	if(num==0)break;
	string ans="",next;
	int key[200];
	for(int i=0;i<num;i++)cin>>key[i];
	cin>>next;
	for(int i=0;i<next.size();i++){
		int tmp;
		for(int j=0;j<52;j++)if(d[j]==next[i])tmp=j;
		int index;
		if(i==0)index=0;
		else index=i%num;
		tmp-=key[index];
		if(tmp<0)tmp+=52;
		cout<<d[tmp];
	}
	cout<<endl;
	}
	return 0;
}