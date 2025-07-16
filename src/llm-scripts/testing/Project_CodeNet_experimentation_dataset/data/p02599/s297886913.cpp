#include <iostream>
#include <vector>

std::vector<int> BIT;//その位置までの良い石の数の区間和
std::vector<int> color;
std::vector<int> right;//色番号ごとの良い石の場所

int RegionSum(int l,int r);
int getSum(int r);
void addBIT(int idx,int value);

int main(){
    int N,Q;
    std::cin >> N >> Q;
    BIT.resize(N+1,0);
    color.resize(N+1,0);
    right.resize(N+1,-1);

    for(int i=1;i<=N;i++){
        std::cin >> color[i];
    }

    std::vector<std::vector<int>> QueryL_(N+1);
    std::vector<std::vector<int>> QueryID(N+1);

    for(int i=0;i<Q;i++){
        int l,r;
        std::cin >> l >> r;
        QueryID[r].push_back(i);
        QueryL_[r].push_back(l);
    }

    std::vector<int> ans(Q);

    //BITの更新と答えの取得。BITは左から順番にi番目を更新していき更新するごとにiを右端とするクエリの答えを取得する
    for(int i=1;i<=N;i++){
        //BITの更新
        if(right[color[i]] != -1)
            addBIT(right[color[i]],-1);//すでにcolor[i]の良い石がある場合は前回までの良い石の位置までのBITを1減らす
        right[color[i]] = i;
        addBIT(i,1);
        //クエリごとの答えの取得
        for(int j=0;j<QueryL_[i].size();j++){
            ans[QueryID[i][j]] = RegionSum(QueryL_[i][j],i);//QueryL_[i][j]:区間右側をiとするクエリ集合のj番目のクエリのl
        }
    }

    for(int i=0;i<Q;i++){
        std::cout << ans[i] << std::endl;
    }

    return 0;
}

int RegionSum(int l,int r){
    return getSum(r) - getSum(l-1);
}

int getSum(int r){
    int Sum=0;
    for(int i=r;i>0;i-=i&(-i)){
        Sum += BIT[i];
    }
    return Sum;
}

void addBIT(int idx,int value){
    for(int i=idx;i<=BIT.size()-1;i+=i&(-i)){
        BIT[i] += value;
    }
    return;
}