#include <bits/stdc++.h>
using namespace std;
int main() {
 int n,m,counter,subcounter;
 string strn,strm;
 cin >> n;
 subcounter = 0;
 vector<string> vecn(0);
 vector<string> vecm(0);
 for (int i = 0; i < n; i++) {
   cin >> strn;
   vecn.push_back(strn);
 }
 cin >> m;
 for (int i = 0; i < m; i++) {
   cin >> strm;
   vecm.push_back(strm);
 }
 for (int i = 0; i < n; i++) {
   counter = 0;
   for (int j = 0; j < n; j++) {
     if  (vecn.at(i) == vecn.at(j)) {
       counter++;
     }
   }
   for (int j = 0; j < m; j++) {
     if (vecn.at(i) == vecm.at(j)) {
       counter = counter -1;
     }
   }
   if (counter > subcounter) {
     subcounter = counter;
   }
 }
 if (subcounter <= 0 ) {
   subcounter = 0;
 }
 
 cout << subcounter;
}
