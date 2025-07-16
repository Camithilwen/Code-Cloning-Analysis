#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define PB push_back

using namespace std;

class cond{
public:
	cond(int x, int y, int z, int t){a=x;b=y;c=z;r=t;chked=false;}
	int a,b,c,r;
	bool chked;
};

int main(void){
	int a,b,c;

	while(cin >> a >> b >> c){
		if((a|b|c) == 0) break;
		vector<cond> v;
		bool changed = true;
		int state[a+b+c+1];
		int x,y,z,r;

		//at first, every state are unknown
		fill(state,state+a+b+c+1,2);

		//read data
		int n; //# of conditions
		cin >> n;
		for(int i=0;i<n;i++){
			cin >> x >> y >> z >> r;
			v.PB(cond(x,y,z,r));
		}
		while(changed){
			changed = false;
			//for all conditions
			for(int i=0;i<n;i++){
				if(v[i].chked) continue; //do not check which is determined
				if(v[i].r == 1){          //in case work well
					state[v[i].a] = 1;
					state[v[i].b] = 1;
					state[v[i].c] = 1;
					v[i].chked = true;
					changed = true;
				}else{
					if(state[v[i].a] == 1 && state[v[i].b] == 1){
						state[v[i].c] = 0;
						changed = true;
						v[i].chked = true;
					}else if(state[v[i].a] == 1 && state[v[i].c] == 1){
						state[v[i].b] = 0;
						changed = true;
						v[i].chked = true;
					}else if(state[v[i].b] == 1 && state[v[i].c] == 1){
						state[v[i].a] = 0;
						changed = true;
						v[i].chked = true;
					}
				}
			}
		}
		for(int i=1;i<=a+b+c;i++){
			cout << state[i] << endl;
		}
	}
}