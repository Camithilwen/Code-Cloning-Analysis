#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
	int a,b,c;
	
	while(cin>>a>>b>>c && (a||b||c)){
		int i,n;
		cin>>n;
		
		int res[a+b+c+1];
		int tmp[n][3];
		fill(res,res+a+b+c+1,2);
		
		for(i=0;i<n;i++){
			int I,J,K,R;
			cin>>I>>J>>K>>R;
			if(R == 1){
				res[I] = res[J] = res[K] = 1;
				i--;
				n--;
			}
			else{
				tmp[i][0] = I;
				tmp[i][1] = J;
				tmp[i][2] = K;
			}
		}
		int size = i;
		for(i=0;i<size;i++){
			if(res[tmp[i][0]] == 1 && res[tmp[i][1]] == 1) res[tmp[i][2]] = 0;
			else if(res[tmp[i][0]] == 1 && res[tmp[i][2]] == 1) res[tmp[i][1]] = 0;
			else if(res[tmp[i][1]] == 1 && res[tmp[i][2]] == 1) res[tmp[i][0]] = 0;
		}
		for(i=1;i<=a+b+c;i++){
			cout<<res[i]<<endl;
		}
	}
	
	return 0;
}