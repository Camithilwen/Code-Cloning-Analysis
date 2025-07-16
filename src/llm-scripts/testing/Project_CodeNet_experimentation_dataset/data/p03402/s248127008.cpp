#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int A,B; cin >> A >> B; // Aが白

    bool changed = false;
    if (A>B){
        swap(A,B);
        changed = true;
    }

    vector<vector<int>> T(100,vector<int>(100,0));

    
    int b = 1;
    while(b<=B){
        int yoko = (b-1)%25;
        yoko *= 4;
        int tate = (b-1)/25;
        tate *= 4;

        T[tate][yoko] = 1;
        T[tate][yoko+1] = 1;
        T[tate][yoko+2] = 1;
        T[tate+1][yoko] = 1;
        T[tate+1][yoko+1] = 1;
        T[tate+1][yoko+2] = 1;
        T[tate+2][yoko] = 1;
        T[tate+2][yoko+1] = 1;
        T[tate+2][yoko+2] = 1;    

        b++;
    }

    int a = 1;
    while(a<=A-1){
        int yoko = (a-1)%25;
        yoko *= 4;
        int tate = (a-1)/25;
        tate *= 4;

        
        T[tate+1][yoko+1] = 0;   

        a++;
    }

    cout << 100 << " " << 100 << endl;
    REP(i,100){
        REP(j,100){
            if(!changed){
                if(T[i][j]==0)cout << ".";
                else cout << "#";
            }else{
                if(T[i][j]==0)cout << "#";
                else cout << ".";
            }
            
        }
        cout << endl;
    }

    


    return 0;
}