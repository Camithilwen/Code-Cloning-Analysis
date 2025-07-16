#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<queue>
using namespace std;

#define MP make_pair
#define PB push_back

int main(int argc,char* argv[]){
  multimap<int,vector<int> > tab;
  vector<int> vec;
  int a,b,c,x,i,j,count,n;
  int flag[400];

  while(cin>>a>>b>>c){
    if(a==0 && b==0 && c==0) break;
    for(i=0;i<400;i++) flag[i]=2;
    tab.clear();
    
    cin>>n;
    for(i=0;i<n;i++){
      vec.clear();
      for(j=0;j<3;j++){
	cin>>x;
	vec.PB(x);
      }
      cin>>x;
      if(x==1) tab.insert(MP(0,vec));
      else tab.insert(MP(1,vec));
    }

    multimap<int,vector<int> >::iterator itr;
    for(itr=tab.begin();itr!=tab.end();itr++){
      if((*itr).first==0){
	vector<int>::iterator it;
	for(it=(*itr).second.begin();it!=(*itr).second.end();it++){
	  flag[(*it)]=1;
	}
      }
      else{
	vec.clear();
	count=0;
	vector<int>::iterator it;
	for(it=(*itr).second.begin();it!=(*itr).second.end();it++){
	  if(flag[(*it)]==1) count++;
	  else{
	    vec.PB((*it));
	  }
	}
	if(count==2){
	  flag[vec.back()]=0;
	}
      }
    }
    for(i=1;i<=a+b+c;i++){
      cout<<flag[i]<<endl;
    }
  }
  return 0;
}