#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<stack>
#include<climits>
#include<cstring>
#include<queue>
using namespace std;

typedef unsigned long long ull;

const ull INF = ULLONG_MAX/3;

void latentEvaluation(int ss, vector<ull> &xList, vector<ull> &sxList){
    int sn = sxList.size();
    if(sxList[ss] != INF){
        for(int i=0;i<sn;i++){
            xList[sn*ss+i] = sxList[ss];
        }
        sxList[ss] = INF;
    }
}

void update(int s, int t, ull x, vector<ull> &xList, vector<ull> &sxList){
    int nn = xList.size();
    int sn = sxList.size();
    int ss = s/sn;
    int tt = t/sn;
    if(ss == tt){
        latentEvaluation(ss, xList, sxList);
        for (int i=0;i<t-s+1;i++){
            xList[s+i] = x;
        }
    }else{
        latentEvaluation(ss, xList, sxList);
        for(int i=s;i<(ss+1)*sn;i++){
            xList[i] = x;
        }

        latentEvaluation(tt, xList, sxList);
        for(int i=tt*sn;i<t+1;i++){
            xList[i] = x;
        }

        for(int i=ss+1;i<tt;i++){
            sxList[i] = x;
        }
    }
}

void find(int ind, vector<ull> &xList, vector<ull> &sxList){
    int nn = xList.size();
    int sn = sxList.size();
    latentEvaluation(ind/sn, xList, sxList);
    cout << xList[ind] << endl;
}

int main(){
    int n, q, qType, s, t,ind;
    ull x;
    cin >> n >> q;
    int sn = sqrt(n)+1;

    vector<ull> xList(sn*sn, (1ull << 31) -1);

    vector<ull> sxList(sn, INF);

    for (int i=0;i<q;i++){
        cin >> qType;
        if (qType == 0){
            cin >> s >> t >> x;
            update(s,t,x,xList,sxList);
        }else{
            cin >> ind;
            find(ind, xList, sxList);
        }
        /*
        for (int i=0;i<sn*sn;i++){
            cout << xList[i]  << " ";
        }
        cout << endl;
        for (int i=0;i<sn;i++){
            cout << sxList[i] << " ";
        }
        cout << endl;
        */
    }
    return 0;
}