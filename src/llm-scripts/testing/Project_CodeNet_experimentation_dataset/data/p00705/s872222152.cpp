#include<vector>
using namespace std;

int N, Q;
int num[110];
int mnum, mday;

int main(){
	while(cin>>N>>Q, N||Q){
		for(int i = 0; i < 110; i++)num[i] = 0;
		
		for(int n = 0; n < N; n++){
			int M;
			cin>>M;
			for(int m = 0; m < M; m++){
				int tmp;
				cin>>tmp;
				num[tmp] += 1;
			}
		}
		int i;
		mday = 110, mnum = 0;
		for(i = 0; i < 110; i++){
			if(num[i] >= Q ){
				if(mnum < num[i]){
					mnum = num[i];
					mday = i;
				}
			}
		}
		cout<<(mnum?mday:0)<<endl;
	}
	return 0;
}