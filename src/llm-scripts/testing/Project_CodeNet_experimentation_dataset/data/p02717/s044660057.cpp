#include <bits/stdc++.h>
#define rep(i, s, n) for (int i = s; i < n; i++)
#define rp(i,n) for (int i=0;i<n;i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define all_acc(x) (x).begin(), (x).end(), 0LL
#define int long long
#define absSort(v) sort(a.begin(), a.end(), [](int i, int j) -> bool { return abs(i) < abs(j); });
using namespace std;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
using ll = long long;
double pi=3.14159265359;

//出力するよ
void output_tate(vector<int> s){
    int n = s.size();
    for (int i = 0; i < n; i++){
        //if (i != 0)
        //    cout << " ";
        cout << s[i]<<endl;
    }
    //cout << endl;
}

void output_yoko(vector<int> s){
    int n = s.size();
    for (int i = 0; i < n; i++){
        if (i != 0)
            cout << " ";
        cout << s[i];//<<endl;
    }
    cout << endl;
}

int MOD = pow(10, 9) + 7;

int kaijou(int n){
    if(n==0) return 1;
    else{
        return ((n%MOD)*(kaijou(n-1)%MOD))%MOD;
    }
}

bool ispow(int n){
    int rn=sqrt(n);
    if(rn*rn==n) return true;
    else return false;
}

/*
vector<int> fn(1000+1);

int f(int n){
    //if(n%2==1) return 
    n*=2;
    double sqrtNum=sqrt(n);
    set<tuple<int,int,int>> ans;
    
    
    for(int X=1;X<=n;X++){
        for(int Y=1;Y<=n-X;Y++){
            int Z=n-X-Y;
            //cout<<X<<" "<<Y<<" "<<Z<<endl;
            if(Z<0) continue;

            if(ispow(X) && ispow(Y) && ispow(Z)){
                int rx=sqrt(X),ry=sqrt(Y),rz=sqrt(Z);
                int x=(rx-ry+rz);
                int y=(rx+ry-rz);
                int z=(-rx+ry+rz);

                if(x%2==0 && y%2==0 && z%2==0 && x>0 && y>0 && z>0){
                    x/=2;
                    y/=2;
                    z/=2;
                    ans.insert({x,y,z});
                    //cout<<x<<" "<<y<<" "<<z<<endl;
                }
            }else continue;

        }
    }

    for(int X=1;X<=sqrtNum;X++){
        for(int Y=1;Y<=sqrtNum;Y++){
            int Z2=n-X*X-Y*Y;
            if(Z2<0 || ispow(Z2)==false) continue;

            int Z=sqrt(Z2);
            int x=(X-Y+Z);
            int y=(X+Y-Z);
            int z=(-X+Y+Z);

            if(x%2==0 && y%2==0 && z%2==0 && x>0 && y>0 && z>0){
                    x/=2;
                    y/=2;
                    z/=2;
                    ans.insert({x,y,z});
                    //cout<<x<<" "<<y<<" "<<z<<endl;
            }
        }
    }
    

    
    for(int x=2;x<=sqrtNum;x++){
        for(int y=2;y<=sqrtNum;y++){
            int z2=n-x*x-y*y;
            
            //if((z2&(z2-1))!=0) break;
            int z=sqrt(z2);
            if((z*z)!=z2) break;
            cout<<z2<<endl;
            
            if(z<2||z>sqrtNum) break;
            cout<<x<<" "<<y<<" "<<z<<endl;
            cout<<x*x+y*y+z*z<<endl;

            if((x-y+z)%2!=0||(x+y-z)%2!=0||(-x+y+z)%2!=0) break;
            int x_t=(x-y+z)/2;
            int y_t=(x+y-z)/2;
            int z_t=(-x+y+z)/2;

            if((x_t)<1||(y_t)<1||(z_t)<1) break;

            
            
            cout<<x_t<<" "<<y_t<<" "<<z_t<<endl;
            ans.insert({x_t,y_t,z_t});
        }
    }

    return ans.size();
}*/

signed main() {
    int x,y,z; cin>>x>>y>>z;
    cout<<z<<" "<<x<<" "<<y<<endl;
}
