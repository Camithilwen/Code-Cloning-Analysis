// ALDS1_13_A
#include <bits/stdc++.h>
#define endl "\n"
#define rep(i,n) for(int i=0;i<int(n);i++)
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v)
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
namespace you {
    std::string to_string(char val) {
        return std::string(1, val);
        // return std::string{val};
        // you::to_string(char)
    }
}

vector<int> x;
vector<int> y;
vector<int> vx={-1,1,1,-1};
vector<int> vy={-1,1,-1,1};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(12);

    int k;
    cin>>k;
    rep(i,k){
        int xx,yy;
        cin>>xx>>yy;
        x.push_back(xx);
        y.push_back(yy);
    }
    vector<int> kind(8);
    rep(i,8) kind[i]=i;
    do{
        vector<vector<bool>> ban(8,vector<bool>(8,false)); //falseが. trueがQ
        rep(i,k){
            ban[x[i]][y[i]]=true;
        }
        int numq=k;
        rep(i,8){
            if(ban[i][kind[i]]==false){
                ban[i][kind[i]]=true;
                numq+=1;
            }
        }
        int okq=0;
        if(numq!=8) continue; //Qを8個以上おいてるときは無視
        else{  
            //cout<<kind<<endl;
            rep(i,8){ //8個のQについてみる。
                int ny=i,nx=kind[i];
                bool flag=true;
                rep(j,4){ //左右上下斜め方向の確認
                    int newx=nx+vx[j],newy=ny+vy[j];
                    while(0<=newx&&newx<=7&&0<=newy&&newy<=7){
                        if(ban[newy][newx]==true){
                            flag=false;
                            break;
                        }
                        newx+=vx[j];
                        newy+=vy[j];
                    }
                    if(!(flag)) break;
                }
                if(flag) okq+=1;
            }
        }
        //cout<<okq<<endl;
        if(okq==8) break;
    }while(next_permutation(all(kind))); 
    //cout<<kind<<endl;

    vector<vector<bool>> ans(8,vector<bool>(8,false));
    rep(i,8) ans[i][kind[i]]=true;
    rep(i,8){
        rep(j,8){
            if(ans[i][j]) cout<<"Q";
            else cout<<".";
        }
        cout<<endl;
    }
    return 0;
}
