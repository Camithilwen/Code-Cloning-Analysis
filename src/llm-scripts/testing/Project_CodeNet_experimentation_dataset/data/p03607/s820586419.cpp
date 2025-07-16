 #include<bits/stdc++.h>
 using namespace std;
 #define For(start,end) for(int i = (int)start;i<(int)end;i++)
 using Int = long long int;
 int main(){
    set<int>paper;
    int N;
    cin >> N;
    For(0,N)
    {
        int before_size=paper.size();
        int tmp;
        cin>>tmp;
        paper.insert(tmp);
        if(paper.size()==before_size)
        {
            paper.erase(tmp);
        }
    }
    cout<<paper.size()<<endl;
 }