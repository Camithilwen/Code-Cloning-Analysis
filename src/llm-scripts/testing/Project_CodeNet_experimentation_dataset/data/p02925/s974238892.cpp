#include <bits/stdc++.h>
int N;
using namespace std;
int main() {
    cin >> N;

    vector<queue<int>> q(N);
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N-1; ++j) {
            int value;
            cin >> value;
            q.at(i).push(value-1);
        }
    }

    // 優先度が高い順にpushしてある
    // 1から順に試合をしていく。全部満たさないといけないので誰から試合を初めてもかまわない

    chrono::system_clock::time_point start, end;
    start = chrono::system_clock::now();
    int num = 0;
    int days = 0;
    int finish = N * (N-1) / 2;
    while(finish > num) {
        end = chrono::system_clock::now();
        double time = static_cast<double>(chrono::duration_cast<chrono::microseconds>(end-start).count() / 1000.0);
        // cout << setprecision(14) << time << endl;
        if(time > 1800.0) {
            cout << finish << endl;
            return 0;
        }
        days++;
        vector<int> match(N, 0);
        for(int i = 0; i < N; ++i) {
            if(q.at(i).empty()) {
                continue;
            }else {
                if(match.at(i) == 1) {
                    q.at(i).pop();
                }else {
                    int rival = q.at(i).front();
                    if(match.at(rival) == 0) {
                        if(q.at(rival).front() == i) {
                            match.at(i) = match.at(rival) = 1;
                            q.at(i).pop();
                            num++;
                        }
                    }
                }
            }
        }
        int flag = 0;
        for(int i = 0; i < N; ++i) {
            if(match.at(i) == 1) {
                flag = 1;
                break;
            }
        }
        int kazu = 0;
        for(int i = 0; i < N; ++i) {
            if(!q.at(i).empty()) kazu++;
        }
        if(kazu == 1) break;
        if(flag == 0) {
            break;
        }
    }

    if(finish == num) {
        cout << days << endl;
    }else {
        cout << "-1" << endl;
    }
}