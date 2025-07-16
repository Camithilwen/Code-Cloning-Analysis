#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <deque>
using namespace std;

int main() {
    //input
    long n; cin >> n;
    vector<int> v(n + 1);
    for(int i = 1; i < n + 1; i++) cin >> v[i];

    vector<int> e(100001,0);
	vector<int> em(100001,0);
    vector<int> o(100001,0);
	vector<int> om(100001,0);
    for(int i = 1; i < n + 1; i++) {
        if(i % 2 == 1){
            o[v[i]] += 1;
            om[v[i]] += 1;
        }else{
            e[v[i]] += 1;           
			em[v[i]] += 1;
        }
    }
 
    //compute
    int ans;
    sort(e.rbegin(),e.rend());
    sort(o.rbegin(),o.rend());

    bool p,q,r;
    p = (count(o.begin(),o.end(),o[0]) == 1);
    q = (count(e.begin(),e.end(),e[0]) == 1);
    r = (find(om.begin(),om.end(),o[0]) - om.begin() == find(em.begin(),em.end(),e[0]) - em.begin()); 
     
    if( p && q && r ){
      ans = n - max( o[0] + e[1],o[1] + e[0] );
    }else{
      ans = n - ( o[0] + e[0] );
    }
    
    //output
    cout << ans << endl;
}