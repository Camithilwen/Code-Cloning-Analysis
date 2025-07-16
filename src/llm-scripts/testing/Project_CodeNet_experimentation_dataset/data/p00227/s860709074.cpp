#include <bits/stdc++.h>
using namespace std;
int main(void) {
    int n,m,p;
    std::deque<int> deq;
    while (cin>>n>>m) {
        if (n==0&&m==0) {
            break;
        } else {
            for (int i=0;i<n;i++) {
                cin>>p;
                deq.emplace_back(p);
            }
            sort(deq.begin(),deq.end(),greater<int>());
            int sum=0;
            while (n>=m) {
                for (int j=0;j<m;j++) {
                    if (j!=m-1) {
                        sum+=deq.front();
                        deq.pop_front();
                        n--;
                    } else {
                        deq.pop_front();
                        n--;
                    }
                }
            }
            if (n!=0) {
                for (int k=0;k<n;k++) {
                    sum+=deq.front();
                    deq.pop_front();
                }
            }
            cout<<sum<<endl;
        }
    }
}
