#include<iostream>
using namespace std;
int main(void)
{
    int n,pm[10001],pe[10001],pj[10001];
    while(1){
        cin>>n;
        if(n==0)break;
        for(int i=0;i<n;i++){
            cin>>pm[i]>>pe[i]>>pj[i];
        }
        for(int i=0;i<n;i++){
            if(pm[i]==100||pe[i]==100||pj[i]==100||(pm[i]+pe[i])/2>=90||(pm[i]+pe[i]+pj[i])/3>=80)
                cout<<"A\n";
            else if((pm[i]+pe[i]+pj[i])/3>=70)cout<<"B\n";
            else if((pm[i]>=80||pe[i]>=80)&&(pm[i]+pe[i]+pj[i])/3>=50)cout<<"B\n";
            else cout<<"C\n";
        }
    }
}