#include <bits/stdc++.h>

using namespace std;



int main(){
    
    int a,b;
    cin>>a>>b;
    string x,y;
    int sum = 0;
    for(;a<=b;a++){
    	y = x = to_string(a);
    	reverse(y.begin(),y.end());
    	if(x==y) sum++;
    }

    cout<<sum;

    return 0;
}
