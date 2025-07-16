#include <iostream>

using namespace std;

int main(){
    int n,h,w;
    cin>>n>>h>>w;
    int count = (n-h+1)*(n-w+1);
    cout<<count<<endl;
    return 0;
}