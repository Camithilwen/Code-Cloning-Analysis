#include <bits/stdc++.h>
using namespace std;
int main(){
  int m;
  cin >> m;
  vector<int> nodes;
  vector<pair<int, int>> child;
  int n = 0;
  for (int i = 0; i < m; i++){
    string q;
    cin >> q;
    if (q == "insert"){
      int k;
      cin >> k;
      if (n != 0){
        int v = 0;
        while (1){
          if (k < nodes[v]){
            if (child[v].first != -1){
              v = child[v].first;
            } else {
              child[v].first = nodes.size();
              break;
            }
          } else {
            if (child[v].second != -1){
              v = child[v].second;
            } else {
              child[v].second = nodes.size();
              break;
            }
          }
        }
      }
      nodes.push_back(k);
      child.push_back(make_pair(-1, -1));
      n++;
    }
    if (q == "find"){
      int k;
      cin >> k;
      if (n == 0){
        cout << "no" << endl;
      } else {
        int v = 0;
        while (1){
          if (k < nodes[v]){
            if (child[v].first == -1){
              cout << "no" << endl;
              break;
            } else {
              v = child[v].first;
            }
          } else if (k > nodes[v]){
            if (child[v].second == -1){
              cout << "no" << endl;
              break;
            } else {
              v = child[v].second;
            }
          } else {
            cout << "yes" << endl;
            break;
          }
        }
      }
    }
    if (q == "delete"){
      int k;
      cin >> k;
      int v = 0;
      int u;
      while (1){
        if (k < nodes[v]){
          u = v;
          v = child[v].first;
        } else if (k > nodes[v]){
          u = v;
          v = child[v].second;
        } else {
          break;
        }
      }
      if (child[v].first != -1 && child[v].second != -1){
        u = v;
        int w = child[v].second;
        while (child[w].first != -1 || child[w].second != -1){
          u = w;
          if (child[w].first != -1){
            w = child[w].first;
          } else {
            w = child[w].second;
          }
        }
        swap(nodes[v], nodes[w]);
        v = w;
      }
      if (child[v].first != -1 && child[v].second == -1){
        int w = child[v].first;
        nodes[v] = nodes[w];
        child[v].first = child[w].first;
        child[v].second = child[w].second;
      } else if (child[v].second != -1 && child[v].first == -1){
        int w = child[v].second;
        nodes[v] = nodes[w];
        child[v].first = child[w].first;
        child[v].second = child[w].second;
      } else {
        if (child[u].first == v){
          child[u].first = -1;
        } else {
          child[u].second = -1;
        }
      }
      n--;
    }
    if (q == "print"){
      //Inorder
      if (n != 0){
        stack<int> S;
        vector<int> t(nodes.size(), 0);
        S.push(0);
        while (!S.empty()){
          int v = S.top();
          S.pop();
          if (t[v] == 1){
            cout << ' ' << nodes[v];
          }
          if (t[v] == 0){
            S.push(v);
            if (child[v].second != -1){
              S.push(child[v].second);
            }
            S.push(v);
            if (child[v].first != -1){
              S.push(child[v].first);
            }
          }
          t[v]++;
        }
      }
      cout << endl;
      //Preorder
      if (n != 0){
        stack<int> S;
        vector<int> t(nodes.size(), 0);
        S.push(0);
        while (!S.empty()){
          int v = S.top();
          S.pop();
          if (t[v] == 0){
            cout << ' ' << nodes[v];
          }
          if (t[v] == 0){
            S.push(v);
            if (child[v].second != -1){
              S.push(child[v].second);
            }
            S.push(v);
            if (child[v].first != -1){
              S.push(child[v].first);
            }
          }
          t[v]++;
        }
      }
      cout << endl;
    }
  }
}
