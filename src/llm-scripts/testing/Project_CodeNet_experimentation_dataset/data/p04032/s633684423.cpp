#include<bits/stdc++.h>
#define ll long long int
using namespace std;


int main(){
	
	string s;
	cin>>s;
	unordered_map<char,int>mp;
	unordered_map<char,vector<pair<int,int>>>store;
	int n=s.size();
	int st,ed,flag=0;
	for(int i=0;i<n;i++){
		mp[s[i]]++;
		store[s[i]].push_back({i,mp[s[i]]});
	}
	for(auto x:store){
		
		if((int)x.second.size()>=2){
			//cout<<x.first<<endl;
			
			int temp_sz=0;
			int cnt=0;
			int i=0,j=1,sz=(int)x.second.size();
			while(j<sz){
				int temp;
				temp_sz=x.second[j].first-x.second[i].first+1;
				temp=temp_sz/2;
				cnt=x.second[j].second;
				if(i>0){
					cnt-=x.second[i-1].second;
				}
				if(cnt>temp){
					flag=1;
					st=x.second[i].first,ed=x.second[j].first;
				}
				i++;
				j++;
				if(flag){
					break;
				}
			}
			
		}
		if(flag){
					break;
				}
	}
	if(flag==0){
		cout<<"-1 -1\n";
	}
	else{
		cout<<st+1<<" "<<ed+1<<endl;
	}
	return 0;
}
