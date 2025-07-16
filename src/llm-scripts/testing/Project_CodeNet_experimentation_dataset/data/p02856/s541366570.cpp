#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll M;
deque<ll> d;
deque<ll> c;
deque<ll> e;

int main(){
    cin >> M;
    for(int i=0;i<M;i++){
        ll a,b;
        cin >> a >> b;
        d.push_back(a);
        c.push_back(b);
    }
    ll count = 0;
    while(d.size() > 0){
        if(c[0] == 1){
            e.push_back(d[0]);
            c.pop_front();
            d.pop_front();
            continue;
        }
        ll dd = d[0];
        ll cc = c[0];
        c.pop_front();
        d.pop_front();
        if(dd < 5){
            if(cc % 2 == 1){
                c.push_front(1);
                d.push_front(dd);
            }
            c.push_front(cc/2);
            d.push_front(dd*2);
            count += cc/2;
            continue;            
        }
        if(cc % 2 == 1){
            c.push_front(1);
            d.push_front(dd);
        }
        dd = (dd*2)/10 + (dd*2)%10;
        c.push_front(cc/2);
        d.push_front(dd);
        count += cc/2 * 2;
    }
    while(e.size() > 1){
        ll a = e[0];
        ll b = e[1];
        e.pop_front();
        e.pop_front();
        if(a+b < 10){
            count++;
            e.push_front(a+b);
        }else{
            count += 2;
            e.push_front((a+b)/10 + (a+b)%10);
        }
    }
    cout << count << endl;
    return 0;
}