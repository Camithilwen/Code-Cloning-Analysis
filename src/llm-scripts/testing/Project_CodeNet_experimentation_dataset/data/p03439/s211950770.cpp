#include <bits/stdc++.h>
typedef long long ll;
#define MOD 1000000007
using namespace std;

int main() {
    int N; cin >> N;
    cout << 0 << endl;
    string pres,s;
    int l,r,prei;
    l = N-1; r=0;
    cin >> pres;
    if(pres == "Vacant") return 0;
    else cout << N-1 << endl;
    cin >> s;
    if(s == "Vacant") return 0;
    else{
        cout << (l+r)/2 << endl;
    }
    prei = 0;
    for (int i = 0; i < 30; i++)
    {
        cin >> s;
        if(s == "Vacant") return 0;
        else if(s == pres){
            if(abs((l+r)/2-prei)%2 == 0){
                if(prei == r){
                    prei = (l+r)/2;
                    r = (l+r)/2;
                }else{
                    prei = (l+r)/2;
                    l = (l+r)/2;
                }
            }
            else{
                if(prei == r){
                    prei = (l+r)/2;
                    l = (l+r)/2;
                }else{
                    prei = (l+r)/2;
                    r = (l+r)/2;
                }
            }
        }
        else{
            if(abs((l+r)/2-prei)%2 == 0){
                if(prei == r){
                    prei = (l+r)/2;
                    l = (l+r)/2;
                }else{
                    prei = (l+r)/2;
                    r = (l+r)/2;
                }
            }
            else{
                if(prei == r){
                    prei = (l+r)/2;
                    r = (l+r)/2;
                }else{
                    prei = (l+r)/2;
                    l = (l+r)/2;
                }
            }      
        }
        pres = s;
        cout << (l+r)/2 << endl;
    }
    return -1;
}