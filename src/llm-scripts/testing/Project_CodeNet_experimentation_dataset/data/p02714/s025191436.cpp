#include <bits/stdc++.h>
using namespace std;

typedef vector< vector<int> > vvi;
typedef vector< vector<bool> > vvb;
typedef vector< vector<char> > vvc;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef long long ll;

int main(){
    int N;
    string S;
    cin >> N >> S;
    ll a=0,b=0,c=0;
    for(int i=0;i<N;i++){
        if(S[i]=='R') a++;
        else if(S[i]=='G') b++;
        else c++;
    }
    ll sum=a*b*c;
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            if(2*j-i>N-1) break;
                if(S[i]!=S[j]&&S[i]!=S[2*j-i]&&S[j]!=S[2*j-i])
                    sum--;
        }
    }
    cout << sum << endl;
    return 0;
}