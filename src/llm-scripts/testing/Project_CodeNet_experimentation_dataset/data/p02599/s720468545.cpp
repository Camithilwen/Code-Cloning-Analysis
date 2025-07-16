#include <bits/stdc++.h>
#define INF 1023456789
#define sacnf scanf
#define scnf scanf
#define scnaf scanf
#define CRLF <<'\n';
#define ALL(v) v.begin,v.end()
#define SIZE(v) (int)v.size()
#define PRPAIR(x) x.first << x.second
#define DEBUG(x) do { std::cerr <<(x)<<'\n'; } while (0)
#define rep(i,a,b) for(int i=(a);i!=(int)b-((a)>(b));(a)>(b)?--i:++i)
using namespace std;
typedef pair<int,int> ii;
typedef pair<ii,int> pip;
typedef vector<int> vi;
typedef long long ll;
#define BLK 707

int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    int arr[n];
    pip que[q];
    rep(i,0,n)
        scanf("%d",&arr[i]),arr[i]--;
    rep(i,0,q){
        int a,b;
        scanf("%d%d",&a,&b);
        a--,b--;
        que[i] = pip(ii(a,b),i);
    }
    sort(que,que+q,[](pip a,pip b){
                     if (a.first.first/BLK==b.first.first/BLK)
                         return (a.first.first/BLK & 1) ? (a.first.second < b.first.second) : (a.first.second > b.first.second);
                     else
                         return a.first.first/BLK<b.first.first/BLK;
                 });
    int ans[q];
    int L=0,R=-1;
    int cnt[n];
    memset(cnt,0,sizeof cnt);
    int num=0;
    rep(i,0,q){
        int l=que[i].first.first,r=que[i].first.second;
        while(L < l){
            if (--cnt[arr[L]] == 0)
                num--;
            L++;
        }
        while(L > l){
            --L;
            if (cnt[arr[L]]++ == 0)
                num++;
        }
        while(R<r){
            ++R;
            if (cnt[arr[R]]++ == 0)
                num++;
        }
        while(R>r){
            if (--cnt[arr[R]]==0)
                num--;
            R--;
        }
        ans[que[i].second] = num;
    }
    rep(i,0,q)
        printf("%d\n",ans[i]);





}
