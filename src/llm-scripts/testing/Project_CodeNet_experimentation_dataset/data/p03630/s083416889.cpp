#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int H, W;
string S[2020];
int pt[2020][2020];
deque<pair<int, int> > st;

int main(int argc, const char * argv[]) {
    cin >> H >> W;
    for (int i = 0; i < H; ++i)
        cin >> S[i];

    for (int i = 0; i < H - 1; ++i) {
        string r0 = S[i];
        string r1 = S[i + 1];
        bool p = (r0[0] == r1[0]);
        pt[i][0] = 1;
        int c = 1;
        for (int j = 1; j < W; ++j) {
            if (p == (r0[j] == r1[j])) {
                c += 1;
            } else {
                p = !p;
                c = 1;
            }
            pt[i][j] = c;
        }
    }

    int max_area = (H < W) ? W : H;

    for (int j = 0; j < W; ++j) {
        st.push_back(make_pair(0, pt[0][j]));
        for (int i = 1; i < H - 1; ++i) {
            int w = pt[i][j];
            int li = i;
            while (!st.empty() && w < st.back().second) {
                pair<int, int> p = st.back();
                st.pop_back();
                li = p.first;
                int area = p.second * (i - (st.empty() ? 0 : li) + 1);
                max_area = (max_area < area) ? area : max_area;
            }
            if (st.empty() || st.back().second < w) {
                st.push_back(make_pair(li, w));
            }
        }
        while (!st.empty()) {
            pair<int, int> p = st.back();
            st.pop_back();
            int area = p.second * (H - (st.empty() ? 0 : p.first));
            max_area = (max_area < area) ? area : max_area;
        }
    }

    cout << max_area << endl;
    return 0;
}
