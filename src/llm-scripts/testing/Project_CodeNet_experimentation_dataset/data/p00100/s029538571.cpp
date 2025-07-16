#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long Int;

int main(){
    map<int,Int> table;
    vector<int> ids;
    int n;
    bool flug;

    while(cin >> n, n != 0){
        flug = false;
        table.clear();
        ids.clear();

        for(int i=1; i<=n; i++){
            int id;
            Int tanka;
            Int number;
            cin >> id >> tanka >> number;
            table[id] += (tanka*number);
            vector<int>::iterator fIter = find(ids.begin(), ids.end(), id);
            if(fIter == ids.end()){
                ids.push_back(id);
            }
        }

        for(vector<int>::iterator Iter = ids.begin(); Iter != ids.end(); Iter++){
            if(table[*Iter] >= 1000000){
                cout << *Iter << endl;
                flug = true;
            }
        }

        if(flug == false){
            cout << "NA" << endl;
        }
    }

    return 0;
}