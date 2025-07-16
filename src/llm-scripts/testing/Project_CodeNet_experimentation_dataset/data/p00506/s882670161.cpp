#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cctype>
using namespace std;
void _2();
void _3();
int main(){

    int n;
    scanf("%d",&n);

    (n == 2) ? _2() : _3();

    return 0;
}
void _2(){

    int a,b;
    scanf("%d%d",&a,&b);
    int mi = min(a,b);
    for(int i = 1; i <= mi; i++){
        if(a % i == 0 && b % i == 0){
            printf("%d\n",i);
        }
    }
    return;
}
void _3(){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    int mi = min(a,min(b,c));
    for(int i = 1; i <= mi; i++){
        if(a % i == 0 && b % i == 0 && c % i == 0){
            printf("%d\n",i);
        }
    }
    return;
}