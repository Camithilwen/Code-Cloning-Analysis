#include <iostream>
#include <algorithm>

using namespace std;
int main(){
    int a,b;
    cin >> a >> b;

    if(a == b){
        cout << a+b << endl;
    }else{
        int m = max(a,b);
        cout << m + (m-1) << endl;
    }

}