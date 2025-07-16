#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    int n;
    cin >> n;
    string s,sf,sl;
    vector <int> m(n,0);
    cout << 0 << endl;
    cin >> s;
    if(s=="Vacant"){
        exit(0);

    }
    else{
        /*if(s=="Male"){
            m[0]=1;
        }
        else{
            m[0]=-1;
        }*/
        sf=s;
    

    cout << n-1 << endl;
    cin >> s;
    if(s=="Vacant"){
        exit(0);
    }
    else{
        /*if(s=="Male"){
            m[n-1]=1;
        }
        else{
            m[n-1]=-1;
        }*/

        sl=s;


        int mi,r,l;
        r=n-1;
        l=0;
        while(r-l!=1){
            mi=(r+l)/2;
            cout << mi << endl;
            cin >> s;
            if(s=="Vacant"){
                exit(0);
        
                //break;
            }
            else{
                if(s==sf){
                    if((mi-l)%2==0){
                        l=mi;
                    }
                    else{
                        r=mi+1;
                    }
                }
                else{
                    if((mi-l)%2==0){
                        r=mi;
                    }
                    else{
                        l=mi-1;
                    }
                    
                }
            }
        }

    }

    

    }
    
    

    return 0;
}