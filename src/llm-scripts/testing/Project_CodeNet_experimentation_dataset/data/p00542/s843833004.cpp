#include<iostream>
using namespace std;

int main(){
    int a,b,c,d,e,f,m,n;
    cin >> a >> b >> c >> d >> e >> f;
    
    if(a<b && a<c && a<d) m=b+c+d;
    if(b<a && b<c && b<d) m=a+c+d;
    if(c<a && c<b && c<d) m=a+b+d;
    if(d<a && d<b && d<c) m=a+b+c;
    if(e<f){
        n=f;
    }else{
        n=e;
    }
    cout << m+n << endl;
}
