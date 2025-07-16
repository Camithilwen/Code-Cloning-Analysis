#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> mato;
vector<int> a;

int main(){
	int n,m;
	int self;
	while(scanf("%d %d",&n,&m) && n && m){
		mato.clear();
		a.clear();
		
		for(int i=0;i<n;i++){
			scanf("%d",&self);
			mato.push_back(self);
		}
		mato.push_back(0);
		sort(mato.begin(),mato.end());
		mato.erase(unique(mato.begin(),mato.end()),mato.end());
		int size = mato.size();
		for(int i=0;i<size;i++){
			for(int j=0;j<size;j++){
				a.push_back(mato[i] + mato[j]);
			}
		}
		sort(a.begin(),a.end());
		a.erase(unique(a.begin(),a.end()),a.end());
		int max = 0;
		size = a.size();
		int s,ss;
		for(int i=0;i<size;i++){
			s = m - a[i];
			if(s > 0){
				ss = *(lower_bound(a.begin(),a.end(),s) - 1);
				//printf("find:%d -> %d\n",s,ss);
				if(a[i] + ss > max){ max = a[i] + ss; }
			}
		}
		printf("%d\n",max);
	}
}