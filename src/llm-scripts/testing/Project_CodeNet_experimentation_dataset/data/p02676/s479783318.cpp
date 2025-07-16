#include<bits/stdc++.h>
#define lint long long
#define st first
#define nd second
#define INF 0x3f3f3f3f

using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int k; cin>>k;
	string s; cin>>s;
	for(int i=0; i<min(k, (int)s.size());i++)	cout<<s[i];
	
	if((int)s.size() > k)	
		cout<<"...";
	cout<<"\n";
	return 0;	
}
