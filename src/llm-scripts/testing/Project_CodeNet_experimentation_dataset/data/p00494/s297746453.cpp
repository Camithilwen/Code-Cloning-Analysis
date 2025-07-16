#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<char,int> P;

int main(){
	char s[1000005];
	scanf("%s",s);
	vector<P> d;//(?¨????,??°)
	int count=1; char before=s[0];
	for(int i=1;s[i]!=0;i++){
		if(s[i]!=before){
			d.push_back(P(before,count));
			before=s[i];
			count=1;
		}else count++;
	}
	d.push_back(P(before,count));
	int res=0;
	if(d.size()==1||d.size()==2) printf("0\n");
	else{
		for(int i=0;i<d.size()-2;i++)
			if(d[i].first=='J'&&d[i+1].first=='O'&&d[i+2].first=='I')
				if(d[i].second>=d[i+1].second&&d[i+1].second<=d[i+2].second) res=max(res,d[i+1].second);
		printf("%d\n",res);
	}
}