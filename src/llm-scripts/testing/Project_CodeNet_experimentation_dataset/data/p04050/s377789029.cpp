#include<iostream>
#include<vector>

using namespace std;
typedef long long ll;
const ll N = 100005;


int main(){
    //入力
    vector<int> v;
    ll n, m, A[N]; cin >> n >> m;
    for (int i = 0; i < m; i++)
        cin >> A[i];
    vector<int> odds;
    vector<int> ans_A;
    for (int i = 0; i < m; i++) //奇数の抽出
    {
        if (A[i]%2==1)
        {
            odds.emplace_back(A[i]);
        }
        if (odds.size() == 3)
        {
            cout << "Impossible";
            return 0;
        }
    }
    if (odds.size() == 0)
    {
        for (int i = 0; i < m; i++)
        {
            ans_A.emplace_back(A[i]);
        }
    }
    else if (odds.size() != 0)
    {
        ans_A.emplace_back(odds[0]);
        for (int i = 0; i < m; i++)
        {
            if(A[i] % 2 == 1) continue;
            ans_A.emplace_back(A[i]);
        }
        if (odds.size() == 2)
        {
            ans_A.emplace_back(odds[1]);
        }
    }
    for (int i = 0; i < ans_A.size(); i++)
    {
        cout << ans_A[i] << " ";   //aの表示
    }
    cout << endl;
    int B_size = ans_A.size();
    if (ans_A.size()==1){
        B_size++;
        ans_A.emplace_back(1);
    }
    else
    {
        ans_A[ans_A.size()-1]++;
    }
    if (ans_A[0] == 1){
        B_size--;
    }
    cout << B_size << endl; //bの大きさの表示
    
    if (ans_A[0] != 1)
    {
        cout << ans_A[0]-1 << " ";
    }
    
    for (int i = 1; i < ans_A.size(); i++)
    {
        cout << ans_A[i] << " " ;
    }
    cout << endl;
}