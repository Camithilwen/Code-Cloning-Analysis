#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef struct _dot{
    int x;
    int y;
}Dot;
bool Check(vector<Dot> list,int Assumption[]){
    
    for(int i=0;i<list.size();i++){
        if(Assumption[list[i].x ] != list[i].y) return false;
    }
    return true;
}
int main(){
    
    int N; cin >> N;
    vector<vector<Dot>> list(N);
    
    for(int i=0;i<N;i++){
        int k; cin >> k;
        for(int j=0;j<k;j++){
            int x,y; cin >> x >> y;
            Dot k; k.x = x-1; k.y = y;
            list.at(i).push_back(k);
        }
    }
    
    
    int ans = 0;
    int size = pow(2,N) - 1;
    for (int bits = size;bits >=0; bits--) {
        
        int Assumption[N];
        int num = 0;
        for(int i=0;i<N;i++){
            int mask = 1 << i;
            if(bits & mask){Assumption[i] = 1;num++;}
            else{Assumption[i] = 0;}
        }
        for (int i=0;i<N;i++) {
            int mask = 1 << i;
            if (bits & mask) {
            
                if(Check(list.at(i),Assumption) == false) break;
            }
            if(i== N-1 && ans < num) ans = num;
        }
 
    }
    cout << ans << endl;
}