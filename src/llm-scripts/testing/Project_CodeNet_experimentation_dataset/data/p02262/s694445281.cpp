#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <ctype.h>
#include <algorithm>
#include <cmath>

#define REP(i, n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()
#define square(x) (x) * (x)
#define cube(x) (x) * (x) * (x)

const int INF = 1e9;

using namespace std;
int cnt = 0;

vector<int> insertion_sort(vector<int> a, int n, int g) {

    for(int i=g; i<n; i++){
        int key = a[i];
        int j = i - g;
        while(j >= 0 && a[j] > key){
            a[j+g] = a[j];
            j -= g;
            cnt++;
        }
        a[j+g] = key;
    }
    return a;
}

vector<int> shell_sort(vector<int> a, int n){
    cnt = 0;
    int m = 11;
    int mm = m;
    int g[] = {1, 2, 8, 32, 128, 512, 2048, 2048*4, 2048*16, 2048*64, 2048*256};
    REP(i, m){
        if(g[m-1-i] > n)
            mm--;
    }
    cout << mm << endl;
    REP(i, mm-1){
        cout << g[mm-1-i] << " ";
        a = insertion_sort(a, n, g[mm-1-i]);
    }
    cout << g[0] << endl;
    a = insertion_sort(a, n, g[0]);

    return a;

}
/*
vector<string> selection_sort(vector<string> s){
    int n = s.size();
    vector<int> a;
    REP(i, n)
        a.push_back(atoi(s[i].substr(1, 1).c_str()));

    REP(i, n){
        int mini = i;
        for(int j = i; j < n ; j++){
            if(a[j] < a[mini])
                mini = j;
        }
        if(i != mini){
            swap(a[i], a[mini]);
            swap(s[i], s[mini]);
        }
    }
    return s;
}

vector<string> bubble_sort(vector<string> s) {
    int n = s.size();
    vector<int> a;
    REP(i, n)
        a.push_back(atoi(s[i].substr(1, 1).c_str()));

    REP(i, n)
        for(int j = n - 1; j > i; j--)
            if(a[j] < a[j-1]){
                swap(a[j], a[j-1]);
                swap(s[j], s[j-1]);
            }

    return s;
}

int find(vector<string> target, string query){
    int i = 0;
    vector<string>::iterator iter = target.begin();
    while(iter != target.end()){
        if (*iter == query)
            break;
        i++;
        iter++;
    }

    return i;
}
*/

int main() {
    int n;
    cin >> n;
    int in[n];
    vector<int> a;
    REP(i, n) { cin >> in[i]; a.push_back(in[i]);}
    a = shell_sort(a, n);
    cout << cnt << endl;
    REP(i, n)
        cout << a[i] << endl;

    return 0;
}