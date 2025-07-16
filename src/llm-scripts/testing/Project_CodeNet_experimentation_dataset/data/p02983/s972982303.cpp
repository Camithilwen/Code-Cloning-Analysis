#include<stdio.h>
#include<iostream>
#include<string>
#include<memory>
#include<cmath>
#include<algorithm>
#include<vector>
double min_double(double a,double  b){
    if(a<b) return a;
    else return b;
}
void swap(int *x,int *y){
    int tmp;
    tmp=*x;
    *x=*y;  
    *y=tmp;
}
int gcd(int a,int b){
    if(a<b) swap(&a,&b);
    if(b<1) return -1;

    if(a%b==0) return b;
    return gcd(b,a%b);
}
int lcm(int a,int b){
    return a * b / gcd(a,b);
}

int main(){
    int L,R;
    std::cin>>L>>R;
    if(R - L + 1 >= 2019){
        std::cout<<0<<std::endl;
        return 0;
    }

    int num = R - L + 1;
    int min=2019;
    for(long i=L;i<=R;i++){
        for(long j=i+1;j<=R;j++){
            int cal=(i * j)%2019;
            if(cal < min) min = cal;
        }
    }

    std::cout<<min<<std::endl;

    return 0;
}

