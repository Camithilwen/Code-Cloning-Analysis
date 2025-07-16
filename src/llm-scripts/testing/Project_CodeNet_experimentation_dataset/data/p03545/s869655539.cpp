#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
#define f2(i,j,k) for(int i=j;i>k;i--)
using namespace std;
int main(){
    long long a,b[2],c[2],d[2];
    string bb,cc,dd,s[2];
    s[0]="+";
    s[1]="-";
    cin>>a;
    b[0]=(a/100)%10;
    b[1]=(-1)*b[0];
    c[0]=(a/10)%10;
    c[1]=(-1)*c[0];
    d[0]=a%10;
    d[1]=(-1)*d[0];
    a/=1000;
    f(i,0,2){
        f(j,0,2){
            f(k,0,2){
                if(a+b[i]+c[j]+d[k]==7){
                    bb=s[i];
                    cc=s[j];
                    dd=s[k];
                    break;
                }
            }
        }
    }
    cout<<a<<bb<<b[0]<<cc<<c[0]<<dd<<d[0]<<"="<<7<<endl;
    return 0;
}
