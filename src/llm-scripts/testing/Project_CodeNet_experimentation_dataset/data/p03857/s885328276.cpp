#include <fstream>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <cmath>
#include <queue>
#include <random>

using namespace std;

#define INT_MAX_VALUE 2147483647
#define LONG_LONG_MAX_VALUE 9223372036854775807
#define ll long long
#define ld long double

struct XX{
    int s;
    int t;
};

class xxGreater {
public:
    bool operator()(const XX& riLeft, const XX& riRight) const {
        //第2条件
        if((riLeft.t) == (riRight.t)){
            return riLeft.s < riRight.s;//<:昇順(小さいものから順番)、>:降順(大きいものから順番)
            //プライオリティキューの場合は > で、top()すると値の小さいものがとれる
        }
        //第1条件
        return (riLeft.t) < (riRight.t);
    }
};


//map<long long,long long> prime_f(long long n){
//    map<long long,long long>res;
//    for(int i=2;i*i<=n;i++){
//        while(n%i==0){
//            ++res[i];
//            n/=i;
//        }
//    }
//    if(n!=1)res[n]=1;
//    return res;
//}




int ppar[200002]; //親
int rrank[200002];//木の深さ
void _init(int n){
    for(int i=1;i<=n;i++){
        ppar[i]=i;
        rrank[i]=0;
    }
}

int find(int x){
    if(ppar[x]==x){
        return x;
    }else{
        return ppar[x]=find(ppar[x]);
    }
}

void unite(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y){
        return;
    }
    if(rrank[x]<rrank[y]){
        ppar[x]=y;
    }else{
        ppar[y]=x;
        if(rrank[x]==rrank[y]){
            rrank[x]++;
        }
    }
}
bool same(int x,int y){
    return find(x)==find(y);
}


int ppar2[200002]; //親
int rrank2[200002];//木の深さ
void _init2(int n){
    for(int i=1;i<=n;i++){
        ppar2[i]=i;
        rrank2[i]=0;
    }
}

int find2(int x){
    if(ppar2[x]==x){
        return x;
    }else{
        return ppar2[x]=find2(ppar2[x]);
    }
}

void unite2(int x,int y){
    x=find2(x);
    y=find2(y);
    if(x==y){
        return;
    }
    if(rrank2[x]<rrank2[y]){
        ppar2[x]=y;
    }else{
        ppar2[y]=x;
        if(rrank2[x]==rrank2[y]){
            rrank2[x]++;
        }
    }
}
bool same2(int x,int y){
    return find2(x)==find2(y);
}

int main(int argc, const char * argv[])
{
    //scanf("%s",S);
    //scanf("%d",&N);
    //scanf("%lld %lld",&target1,&target2);
    //sscanf(tmp.c_str(),"%dd%d%d",&time[i], &dice[i], &z[i]);
    //getline(cin, target);
    //ifstream ifs("a.txt");//テスト用
    //ifs >> a;
    //ここから
    
    //入力高速化
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N,K,L;
    cin >> N >> K >> L;
    
    int tmp[100000],tmp2[100000];
    int ttmp[100000],ttmp2[100000];
    for(int i=0;i<K;i++){
        cin >> tmp[i]>>tmp2[i];
    }
    for(int i=0;i<L;i++){
        cin >> ttmp[i]>>ttmp2[i];
    }
    _init(N);
    _init2(N);
    
    for(int i=0;i<L;i++){
        unite2(ttmp[i],ttmp2[i]);
    }
    for(int i=0;i<K;i++){
        unite(tmp[i],tmp2[i]);
        //ここでつなげる、つなげない判断はしてはいけない
        // a+b c+d (道路)
        // a+b-c (鉄道)
        // 鉄道でb-cを結んでおかないと、b-dが来た時にcとつながれない
    }
    

    int a2[200002];
    map<pair<int,int>,int>a;
    for(int i=1;i<=N;i++){
        a[make_pair(find(i),find2(i))]++;
    }
    for(int i=1;i<=N;i++){
        a2[i]=a[make_pair(find(i),find2(i))];
    }
    for(int i=1;i<=N;i++){
        cout << a2[i];
        if(i!=N){
            cout << " ";
        }else{
            cout << endl;
        }
    }
    
    
    //ここまで
    //cout << "ans" << endl;
    //printf("%.0f\n",ans);//小数点以下表示なし
    //printf("%.7f\n",p);
    
    return 0;
}
