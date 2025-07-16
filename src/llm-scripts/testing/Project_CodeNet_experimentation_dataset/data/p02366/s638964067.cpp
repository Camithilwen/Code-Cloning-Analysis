#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/* Articulation Points (Critical Routers) */
int timer = 0;
void getAP(unordered_map<int,vector<int>*>& adjacencyList, unordered_map<int,int>& d, unordered_map<int,int>& l, unordered_map<int,int>& p, unordered_map<int,bool>& visited, int* ap, int sv){
    visited[sv] = true;
    l[sv] = d[sv] = ++timer;
    int children = 0;
    for(int i=0;i<adjacencyList[sv]->size();i++){
        int n = adjacencyList[sv]->at(i);
        if(visited.count(n)!=0 && p[sv]!=n){
            l[sv] = min(l[sv],d[n]);
        }else if(visited.count(n)==0){
            p[n] = sv;
            children += 1;
            getAP(adjacencyList, d, l, p, visited, ap, n);
            l[sv] = min(l[sv],l[n]);
            if(p[sv]!=-1 && d[sv] <= l[n]){
                ap[sv]=1;
            }
        }
    }
    if(p[sv]==-1 && children>1){
        ap[sv] = 1;
    }
}

void getAP(unordered_map<int,vector<int>*>& adjacencyList){
    int n = adjacencyList.size();
    unordered_map<int,int> discoveryTime;
    unordered_map<int,int> lowestTime;
    unordered_map<int,int> parent;
    int* ap = new int[n];
    unordered_map<int,bool> visited;
    timer = 0;
    for(int i=0;i<n;i++){
        ap[i] = 0;
    }
    parent[0] = -1;
    getAP(adjacencyList,discoveryTime,lowestTime,parent,visited,ap,0);
    for(int i=0;i<n;i++){
        if(ap[i]==1){
            cout << i << endl;
        }
    } 
}

int main() {
    int n, e;
    cin >> n >> e;
    unordered_map<int,vector<int>*> adjacencyList;
    for(int i=0;i<n;i++){
        vector<int>* v = new vector<int>;
        adjacencyList[i] = v;
    }
    for(int i=0;i<e;i++){
        int x,y;
        cin >> x >> y;
        adjacencyList[x]->push_back(y);
        adjacencyList[y]->push_back(x);
    }
    getAP(adjacencyList);
}
