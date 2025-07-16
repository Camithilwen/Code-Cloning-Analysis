#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

int main() {
    int N, K; cin >> N >> K;
    vector<long long int> D(N);

    vector<long long int> Juwel(N);
    for (int i = 0; i < N; i++) {
        cin >> D.at(i);
    }
    int answer = 0, sum = 0 ;
    for (int action = 0; action <= K; action++) {
        for (int back = 0; back <= action; back++) {
            for (int left = 0; left <= action - back; left++) {
                Juwel.clear();
                sum = 0;
                if (left < (int)D.size()) {
                    for (int i = 0; i < left; i++)Juwel.push_back(D.at(i));

                    for (int i = 0; i < min(action - back - left, N - back - left); i++)Juwel.push_back(D.at(N - i - 1));
                }
                else {
                    for (int i = 0; i < (int)D.size(); i++)Juwel.push_back(D.at(i));
                }

                sort(Juwel.begin(), Juwel.end());

                for (int i = 0; i < min( back , (int)Juwel.size()); i++) {
                    if (Juwel.at(i) < 0)Juwel.at(i) = 0;
                }
                for (int i = 0; i <(int) Juwel.size(); i++)sum += Juwel.at(i);

                if (sum >= answer)answer = sum;
            }
        }
    }
    cout << answer << endl;
    return 0;
}