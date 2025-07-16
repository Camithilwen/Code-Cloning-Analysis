#include<iostream>
#include<queue>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

typedef struct{
    int idx[3];
}int3;

typedef struct{
    int status[20][20];
}int20;

typedef vector<pair<int, int > > vecpair;

int20 map;
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int w, h;

pair<int3, vecpair> move(int3 cidx, int d[2], vecpair cstatus){
    pair<int3, vecpair> output;
    int3 nidx;
    vecpair nstatus = cstatus;

    int ch = cidx.idx[0];
    int cw = cidx.idx[1];
    int cs;

    int20 cmap;
    cmap = map;
    REP(i, cstatus.size()){
        cmap.status[cstatus[i].first][cstatus[i].second] = 0;
    }

    if(cmap.status[ch+d[0]][cw+d[1]]==1){
        nidx.idx[0] = -1;
        nidx.idx[1] = -1;
        nidx.idx[2] = -1;
        output = make_pair(nidx, nstatus);
        return output;
    }

    REP(i, 20){
        ch += d[0];
        cw += d[1];
        if(ch<0 || ch>=h || cw<0 || cw>=w || cidx.idx[2]+1 > 10){
            nidx.idx[0] = -1;
            nidx.idx[1] = -1;
            nidx.idx[2] = -1;
            output = make_pair(nidx, nstatus);
            return output;
        } else {
            cs = cmap.status[ch][cw];
        }

        if(cs == 0){
            continue;
        } else if(cs == 1){
            nstatus.push_back(make_pair(ch, cw));
            nidx.idx[0] = ch - d[0];
            nidx.idx[1] = cw - d[1];
            nidx.idx[2] = cidx.idx[2] + 1;
            output = make_pair(nidx, nstatus);
            return output;
        } else if(cs == 3){
            nidx.idx[0] = ch;
            nidx.idx[1] = cw;
            nidx.idx[2] = cidx.idx[2] + 1;
            output = make_pair(nidx, nstatus);
            return output;
        }
    }
}

int main(){
    while(1){
        cin >> w >> h;

        if(w==0){
            break;
        }

        int3 s;
        int g[2];
        REP(i, h){
            REP(j, w){
                cin >> map.status[i][j];
                if(map.status[i][j] == 2){
                    s.idx[0] = i;
                    s.idx[1] = j;
                    s.idx[2] = 0;
                } else if(map.status[i][j] == 3){
                    g[0] = i;
                    g[1] = j;
                }
            }
        }

        queue<int3> qidx;
        queue<vector<pair<int, int> > > qstatus;
        vector<pair<int, int> > init;
        qidx.push(s);
        qstatus.push(init);
        int output = -1;

        while(!qidx.empty()){
            int3 cidx = qidx.front();
            qidx.pop();

            vecpair cstatus = qstatus.front();
            qstatus.pop();

            REP(i, 4){
                int3 nidx;
                vecpair nstatus;
                pair<int3, vecpair> next = move(cidx, dir[i], cstatus);
                nidx = next.first;
                nstatus = next.second;
                if(nidx.idx[0] == g[0] && nidx.idx[1] == g[1]) {
                    output = nidx.idx[2];
                    queue<int3> empty;
                    swap(qidx, empty);
                    break;
                } else if(nidx.idx[0] >= 0){
                    qidx.push(nidx);
                    qstatus.push(nstatus);
                }
            }
        }
        cout << output << endl;
    } 
}