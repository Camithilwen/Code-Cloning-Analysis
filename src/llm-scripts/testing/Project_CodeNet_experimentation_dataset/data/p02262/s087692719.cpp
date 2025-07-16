#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> &v){
    vector<int>::iterator ite = v.begin();
    while(ite != v.end()){
        cout << *ite << endl;
        ite++;
    }
}

int insSort(vector<int> &v, int g){
    int i, j, x, n = v.size(), cnt = 0;
    for(i = g; i < n; i++){
        x = v[i];
        j = i - g;
        while(j >= 0 && v[j] > x){
            v[j+g] = v[j];
            cnt++;
            j -= g;
        }
        v[j+g] = x;
    }
    return cnt;
}

void makeG(vector<int> &v,int n){
    for(int i = 1; ;){
        if(i > n) break;
        v.push_back(i);
        i = 3*i + 1;
    }
}

void shellSort(vector<int> &v){
    int i, cnt = 0;
    vector<int> g;
    makeG(g, v.size());
    int gs = g.size();
    cout << gs << endl;
    for(i = gs - 1; i >= 0; i--){
        if(i != gs - 1)
            cout << " ";
        cout << g[i];
        cnt += insSort(v, g[i]);
    }
    cout << endl <<  cnt << endl;
}

int main(){
    int n, x, i;
    vector<int> v;
    cin >> n;
    for(i = 0; i < n; i++){
        cin >> x;
        v.push_back(x);
    }
    shellSort(v);
    print(v);
    return 0;
}