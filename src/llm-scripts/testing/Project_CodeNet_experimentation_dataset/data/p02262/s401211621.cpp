#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int cnt;

void insertionSort(vector<int> &mat,int g){
    for(int i=g;i<mat.size();i++){
        int v = mat[i];
        int j = i - g;
        while(j>=0 && mat[j]>v){
            mat[j+g] = mat[j];
            j = j - g;
            cnt++;
            mat[j+g] = v;
        }
    }
}

void shellSort(vector<int> &mat){
    vector<int>g;
    cnt = 0;
    for(int h=1;h<=mat.size();h=3*h+1)g.push_back(h);
    reverse(g.begin(),g.end());
    int m = g.size();
    cout << m << endl;
    for(int i=0;i<g.size();i++){
        if(i<g.size()-1) cout << g[i] << " ";
        else cout << g[i] << endl;
    }
    for(int i=0;i<m;i++)insertionSort(mat,g[i]);
}

int main(){
    vector<int> mat;
    int n,x;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x;
        mat.push_back(x);
    }
    shellSort(mat);
    cout << cnt << endl;
    for(int i=0;i<n;i++) cout << mat[i] << endl;
    return 0;
}