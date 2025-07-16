#include <bits/stdc++.h>
using namespace std;

#define print cout <<
#define printl(s) cout << s << endl;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;

const ll modval = pow(10,9) + 7;

template <typename T>
vector<T> getValues(int num){
    vector<T> values(num);
    for(int i=0;i<num;i++){
        cin >> values.at(i);
    }
    return values;
}

int main(){
    int N;
    cin >> N;
    auto inputs = getValues<ll>(N);
    ll sumOfStep = 0;
    ll front = inputs.at(0);
    for(int i=1;i<N;i++){
      ll target = inputs.at(i);
      int step = 0;
      if(front>target){
        step = front -target;
        sumOfStep += step;
      }
      front = step + inputs.at(i);
    }
    printl(sumOfStep);
}
