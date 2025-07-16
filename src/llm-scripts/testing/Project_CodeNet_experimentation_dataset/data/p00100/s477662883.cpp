#include <iostream>
#include <vector>
#include <utility>
#include <map>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) break;
        vector< pair<int, long long> > members;
        for (int i = 0; i < n; i++) {
            pair<int, long long> member;
            int id;
            long long cost, count;
            cin >> id >> cost >> count;
            bool exist = false;
            for (int i = 0; i < members.size(); i++) {
                if (members[i].first == id) {
                    members[i].second += cost * count;
                    exist = true;
                }
            }
            if (!exist) {
                member.first = id;
                member.second = cost * count;
                members.push_back(member);
            }
        }
        bool exist = false;
        for (vector< pair<int, long long> >::iterator m_i = members.begin();
                m_i != members.end(); m_i++) {
            if (m_i->second >= 1000000) {
                cout << m_i->first << endl;
                exist = true;
            }
        }
        if (!exist) {
            cout << "NA" << endl;
        }
    }
    return 0;
}
               

            