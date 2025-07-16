#include <iostream>

#include <map>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;
//const char a[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
const int maxN=50;
int dp[maxN+1][maxN+1][maxN*maxN+1];

void solver() {

    string a,b,c;
    cin>>a>>b>>c;

    char n = a[0];
    a.erase(0,1);

    while(1){

        if(n == 'a'){
            if(a.size() == 0){
                cout<<"A"<<endl;
                return; }
            n = a[0];
            a.erase(0,1);
        }else if(n == 'b'){
            if(b.size() == 0){
                cout<<"B"<<endl;
                return;
            }
            n = b[0];
            b.erase(0,1);
        }
        else if(n == 'c'){
            if(c.size() == 0){
                cout<<"C"<<endl;
                return;
            }
            n = c[0];
            c.erase(0,1);
        }
    }


    return;
}


int main() {
    int n=1;
    //cin>>n;
    while(n--)
    {
        solver();
    }
}
