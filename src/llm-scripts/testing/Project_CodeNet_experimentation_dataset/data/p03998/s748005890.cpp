#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<queue<char>> s(3);
    for(int ix=0;ix<3;ix++){
        string tmp;
        cin >> tmp;
        for(int ixx=0;ixx<tmp.size();ixx++) s.at(ix).push(tmp.at(ixx));
    }
    char card;
    int turnplayer = 0;
    while(!s.at(turnplayer).empty()){
        card = s.at(turnplayer).front();
        s.at(turnplayer).pop();
        turnplayer = card - 'a';
    }
    if(turnplayer == 0) cout << "A" << endl;
    if(turnplayer == 1) cout << "B" << endl;
    if(turnplayer == 2) cout << "C" << endl;
}