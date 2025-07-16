#include <iostream>
using namespace std;
int main(void){
    int a,b,c,d;
    int ans=0;
    cin >> a >> b >> c >> d;
    if(a>b) ans +=b;
    else ans += a;
    if(c>d) ans +=d;
    else ans += c;
    cout << ans << endl;
}
