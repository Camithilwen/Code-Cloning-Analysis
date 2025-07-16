#include<bits/stdc++.h>

using namespace std;

int main()
{
    int N,M;
    cin >> N >> M;
    vector<int> s(M);
    vector<int> c(M);
    int ans=0;

    if(M == 0 && N==1){
        cout << "0" << endl;
        return 0;
    }

    for(int i=0; i<M; i++){
        cin >> s.at(i) >> c.at(i);
        if(N>1 && s.at(i) == 1 && c.at(i) == 0){
            cout << "-1" << endl;
            return 0;
        }
    }

    vector<int> d(N);

    for(int i=0; i<M; i++){
        if(d.at(s.at(i)-1) == 1 && c.at(i) != ans/(int)(pow(10,N-s.at(i))) ) {
            cout << "-1" << endl;
            return 0;
        }
        if(d.at(s.at(i)-1) == 0){
            ans += c.at(i)*(int)pow(10,N-s.at(i)) ;
            d.at(s.at(i)-1)++;
        }
    }

    if(d.at(0) == 0){
        ans += (int)pow(10,N-1);
    }

    cout << ans << endl;

}