#include<iostream>
#include<vector>
#include<set>
#include<utility>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cctype>
#include<algorithm>
#include<cinttypes>
#include<stack>
#include<ctgmath>
using namespace std;

typedef long long ll;


#define ceil(a,b)  ( !(a%b) ? a/b : a/b+1 )
#define all(a)  (a).begin(),(a).end()
#define allr(a) (a).rbegin(),(a).rend()
#define endl '\n' 
#define debug(a) cin>>#a>>a;
//vector<ll> primes{ }
template<typename T>
T gcd( T a, T b ) { 
    return !a ? b : gcd( b%a, a); 
}

template<typename T>
T lcm( T a, T b ){
    return (a*b)/gcd(a,b); 
} 

int main(){
    string sa,sb,sc;
    cin >> sa >> sb >> sc;
    reverse(sa.begin(),sa.end());
    reverse(sb.begin(),sb.end());
    reverse(sc.begin(),sc.end());
    char check = sa.back();
    sa.pop_back();
    if( sa.empty() ){
        std::cout << 'A' << endl;
    } else {
        bool flag = false;
        while(true){
            switch(check){
                case 'a':
                    if( sa.empty() ){
                        cout << 'A' << endl;
                        flag = true;      
                    } else {
                        check = sa.back();
                        sa.pop_back();
                    }
                    break;
                case 'b':
                    if( sb.empty() ){
                        cout << 'B' << endl;
                        flag = true;      
                    } else {
                        check = sb.back();
                        sb.pop_back();
                    }
                    break;
                case 'c':
                    if( sc.empty() ){
                        cout << 'C' << endl;
                        flag = true;      
                    } else {
                        check = sc.back();
                        sc.pop_back();
                    }
                    break;
            }
            if(flag){
                break;
            }
        }
    }
    return 0;
}
