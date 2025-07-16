#include <bits/stdc++.h>
//#define DEBUG
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
template <class T>
void print_vect(std::vector<T> v){
    for(int i = 0 ; i < v .size(); i++) cout << v[i] << " ";
    cout << endl;
}

void solve(){
    string S;
    cin >> S;
    map<char, vi> mp;
    for(int i  = 0 ; i < S.size() ; i++){
        mp[S[i]].push_back(i);        
    }
    for( auto it = mp.begin() ; it != mp.end(); it++){
        char c = (*it).first;
        if((*it).second.size() < 2) continue;

        for(int i = 1 ; i < (*it).second.size(); i++){
            if ( (*it).second[i] <= (*it).second[i-1] + 2){
                //we found 
                cout << (*it).second[i-1] + 1 << " " << (*it).second[i] + 1 << "\n";
                return;
            }
        }
    }
    cout << "-1 -1 \n";
}

int main()
{
    //making data IO Fast
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    /****************************/

    #ifdef DEBUG
    int TEST_CASES = 2;
    while(TEST_CASES--){
    #endif // DEBBUG

    solve();

    #ifdef DEBUG
    }
    #endif // DEBUG
    
    return 0;
}

