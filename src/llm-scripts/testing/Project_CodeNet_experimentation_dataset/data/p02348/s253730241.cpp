#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

#define SEG_NUM (1<<20)

pair<long, long> seg[SEG_NUM*2];

long find(int i){
    i += SEG_NUM;
    long ans = 2147483647;
    int time = 0;
    while(i > 0){
        if(time < seg[i].first) {
            ans = seg[i].second;
            time = seg[i].first;
        }
        i /= 2;
    }
    return ans;
}

void update(int s, int t, long x, long time){
    s += SEG_NUM;
    t += SEG_NUM;
    while(s < t){
        if(s % 2 == 1){
            seg[s].first = time;
            seg[s].second = x;
            s++;
        }
        s /= 2;
        if(t % 2 == 1){
            seg[t-1].first = time;
            seg[t-1].second = x;
            t--;
        }
        t /= 2;
    }
}

int main() {
    for(long i=0;i<2*SEG_NUM;++i){
        seg[i] = make_pair(0, 2147483647);
    }
    int n, q;
    cin>>n>>q;
    long query, s, t, x, i;
    for(int time=0;time<q;++time){
        cin>>query;
        if(query){
            cin>>i;
            cout<<find(i)<<endl;
        }
        else {
            cin>>s>>t>>x;
            update(s, t+1, x, time+1);
        }
    }
}


