using namespace std;
#include <bits/stdc++.h>

int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a<=b){
        if(d<=c){
            std::cout << a+d << std::endl;
        }
        else {
            std::cout << a+c << std::endl;
        }
    }
    else{
        if(c<=d){
            std::cout << b+c << std::endl;
        }
        else{
            std::cout << b+d << std::endl;
        }
    }
    return 0;
}
