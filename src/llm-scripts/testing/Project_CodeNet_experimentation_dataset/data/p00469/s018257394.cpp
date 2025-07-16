#include<iostream>
#include<set>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>

using namespace std;
int a, b;
int num[15];


int bind(int p,int q){
	if(q<10){
		return 10*p+q;
	}
	else return 100*p+q;
}


int main(void){
	while(1){
		cin >> a >> b;
		if(a == 0 && b == 0){
			return 0;
		}
		set <int> S;
		for(int i=0;i<a;i++){
			cin >> num[i];
		}
		for(int i=0;i<a;i++){
			for(int j=0;j<a;j++){
				for(int k=0;k<a;k++){
					for(int l=0;l<a;l++){
						
						if(b==4){
							if(i != j && i != k && i != l && j != k && j != l && k != l){ 
							int c = bind(bind(bind(num[i],num[j]),num[k]),num[l]);
							S.insert(c);
							}
						}
						if(b==3){
							if(j != k && j != l && k != l){
							int c = bind(bind(num[j],num[k]),num[l]);
							S.insert(c);
							}
						}
						if(b==2){
							if(k != l){
							int c = bind(num[k],num[l]);
							S.insert(c);
							}
						}	
					}
				}
			}
		}
		cout << S.size() <<endl;
		S.clear();
	}
}