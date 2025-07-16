#include<algorithm>
#include<iostream>
#include<cstdio>
int main()
{
    int a[10];
    int m;
    for(int i=0;i<=5;i++){
        std::cin>>a[i];
    }
    std::sort(a,a+4);
    m=std::max(a[4],a[5]);
    std:: cout<<a[3]+a[2]+a[1]+m<<std::endl;
    return 0;
    
    
}
