#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> P;
typedef long long ll;

int k;
vector<P> d;
char table[8][8];
vector<int> row;
vector<int> col;

void show_vec(vector<int>);

void solve(){
    
    sort(col.begin(), col.end());
    do{
       
        vector<P> v;
        for (auto &e: d) v.push_back(e);
        
        for (int i = 0 ; i < (int)row.size(); i++)
        {   
            P p;
            p.first = row[i];
            p.second = col[i];
            v.push_back(p);
        }
        bool ok = true;
        for (int i = 0; i < (int)v.size() && ok; i++)
        {
            for (int j = 0; j < (int)v.size(); j++)
            {
                if(i == j) continue;
                int dx = v[i].first - v[j].first;
                int dy = v[i].second - v[j].second;
                if(abs(dx) == abs(dy)){
                    ok = false;
                    break;
                }
            }
            
        }
        if(ok){
            for(auto &e: v){
                //cout << "(" << e.first << ", " << e.second << ")";
                table[e.first][e.second] = 'Q';
            }
        
            break;
        }
    }while(next_permutation(col.begin(), col.end()));
    
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << table[i][j];
        }
        cout << endl;
        
    }
    
}


int main(){
    cin >> k;
    for (int i = 0; i < 8; i++)
    {
        row.push_back(i);
        col.push_back(i);
    }

    
    for (int i = 0; i < k; i++)
    {
        P p;
        cin >> p.first >> p.second;
        row.erase(find(row.begin(), row.end(), p.first));
        col.erase(find(col.begin(), col.end(), p.second));
        d.push_back(p);
    }
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            table[i][j] = '.';
        }
       
        
    }
  
    solve();

    return 0;

}

void show_vec(vector<int> v){
    cout << "[";
    for (int i = 0; i < (int)v.size(); i++)
    {
        cout << v[i] << ", ";
    }
    cout << "\b\b]" << endl;
}
