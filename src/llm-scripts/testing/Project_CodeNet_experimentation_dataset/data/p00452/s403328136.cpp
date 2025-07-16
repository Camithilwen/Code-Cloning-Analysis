#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
    int n,m;
    int P[1010],Q[1000000];

    while(true){
	cin >> n >> m;
	if(n==0&&m==0) break;
	
	P[0]=0;
	for(int i=1;i<=n;i++) scanf("%d",&P[i]);

	int num=0;
	for(int i=0;i<=n;i++){
	    for(int j=i;j<=n;j++){
		Q[num++]=P[i]+P[j];
	    }
	}

	sort(Q,Q+num);

	int key,index,ans=0;
	int *pos;
	for(int i=0;i<num;i++){
	    key=m-Q[i];
	    if(key<0) break;

	    pos=lower_bound(Q,Q+num,key);
	    index=distance(Q,pos)-1;

	    ans=max(ans,Q[i]+Q[index]);
	}
 	cout << ans << endl;
	
    }
    return 0;
}