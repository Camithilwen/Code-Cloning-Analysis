#include <iostream>
#include <vector>
#include <cstdlib>  
#include <algorithm>
#include <string>

using namespace std;
 
int main() {
    int a,b,sa; 
    cin>>a>>b;
    sa = max(a+b,a-b);
    sa = max(a*b,sa);
    cout<<sa;
    return 0;
}