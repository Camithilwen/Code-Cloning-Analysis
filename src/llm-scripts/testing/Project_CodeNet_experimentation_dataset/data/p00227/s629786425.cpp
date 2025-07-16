#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int m,n;
    priority_queue<int> que;

    while(cin>>n>>m,m|n){
        int sum=0;

        for(int i=0;i<n;i++){
            int p;
            cin>>p;
            que.push(p);
        }

        vector<int> bag;

        while(que.size()){
            int p=que.top();que.pop();
            bag.push_back(p);
            if(que.empty() || bag.size()==m){
                for_each(bag.begin(),bag.end(),[&sum](int v){sum += v;});
                if(bag.size()==m) sum-=p;
                bag.clear();
            }
        }

        cout<<sum<<endl;
    }

    return 0;
}