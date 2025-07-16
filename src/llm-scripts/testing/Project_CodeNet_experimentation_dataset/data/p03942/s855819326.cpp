#include <cstdio>
#include <cstring>
#include <vector>
#include <deque>
#define MAXN 1000010
using namespace std;

int n;
char s1[MAXN],s2[MAXN];
vector<int> S[30];
int p[MAXN];

struct Queue{
	deque<int> Q;
	int d;

	void push_back(int x){ Q.push_back(x-d); }
	void push_front(int x){ Q.push_front(x-d); }
	int back(){ return Q.back()+d; }
	void pop_back(){ Q.pop_back(); }
	void pop_front(){ Q.pop_front(); }
	bool empty(){ return Q.empty(); }
	int size(){ return Q.size(); }
}Q;

int main(){
#ifdef DEBUG
	freopen("F.in","r",stdin);
#endif
	scanf("%d",&n);
	scanf("%s%s",s1+1,s2+1);
	n=strlen(s1+1);
	for(int i=1;i<=n;i++) S[s1[i]-'a'].push_back(i);
	int ans=0;
	p[n+1]=n+1;
	for(int i=n;i>=1;i--){
		if(s2[i]==s2[i+1] && i>=p[i+1]){
			p[i]=p[i+1];
		}else{
			while(!S[s2[i]-'a'].empty() && S[s2[i]-'a'].back()>=p[i+1])
				S[s2[i]-'a'].pop_back();
			if(S[s2[i]-'a'].empty()){
				puts("-1");
				return 0;
			}
			p[i]=S[s2[i]-'a'].back();
			if(i>=p[i+1]){
				Q.d--;
				Q.push_front(p[i+1]-1);
				while(Q.back()>=i) Q.pop_back();
				Q.push_back(i);
			}else{
				while(!Q.empty()) Q.pop_back();
				if(p[i]<i) Q.push_back(i);
			}
			ans=max(ans,(int)Q.size());
		}
	}
	printf("%d\n",ans);
}
