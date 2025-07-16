#include<stdio.h>
#include<map>
#include<algorithm>
using namespace std;
typedef pair<int,int> P;
P s[101];
int r[100];
int main(){
	int n;
	scanf("%d",&n);
	int i,j;
	for(i=0;i<n;i++)s[i]=P(0,i);
	for(i=0;i<n*(n-1)/2;i++){
		int a,b,c,d;
		scanf("%d %d %d %d",&a,&b,&c,&d);
		a--;b--;
		if(c>d)s[a].first+=3;
		if(c<d)s[b].first+=3;
		if(c==d){
			s[a].first+=1;
			s[b].first+=1;
		}
	}
	s[n]=P(-1,-1);
	sort(s,s+n);
	reverse(s,s+n);
	int p=0;
	int pr=0;
	while(p<n){
		r[s[p].second]=pr;
		while(s[p].first==s[p+1].first){
			p++;
			r[s[p].second]=pr;
		}
		p++;
		pr=p;
	}
	for(i=0;i<n;i++)printf("%d\n",r[i]+1);
	return 0;
}