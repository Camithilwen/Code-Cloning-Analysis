#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define pii pair<ll,ll>

#define debug(a) { cout << #a << " = " << a << endl;}

void sep() {
    cout << "-------------BLOCK-----------------\n";
}

template<typename T>
void debugv(vector<T> arr) {
    for (auto t: arr)
        cout << t << " ";
    cout << "\n";
}

template<typename T>
void debugarr(T arr, int n) {
    for (int i=0;i<n;i++) cout << arr[i] << " ";
    cout << "\n";
}

const int maxn = 2e5+1;
ll arr1[maxn], n, m, t, k;
ll arr2[maxn];
unordered_map<ll,ll> u;

ll __min(ll a, ll b) {
    return a < b ? a : b;
}

ll __max(ll a, ll b) {
    return a > b ? a : b;
}

void par(int n) {
    cout << "Yes\n";
    for (int i=0;i<n;i++) cout << arr2[i] << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n;
    for (int i=0;i<n;i++) cin>>arr1[i]; 
    for (int i=0;i<n;i++) cin>>arr2[i]; 
    reverse(arr2,arr2+n);

    ll l=n+1,r=n+1;
    for (int i=0;i<n;i++) {
        if (arr1[i]==arr2[i]) {
            if (l == n+1) l = i, r=i;
            else r = i;
        }
    }

    if (l == n+1) {
        par(n);
        return 0;
    }

    ll sl=l,sr=r;
    ll pl=l,pr=r;
    while (sl >=0 && arr1[sl] == arr1[l]) sl--;
    while (sr < n && arr1[sr] == arr1[r]) sr++;
    while (pl >=0 && arr2[pl] == arr2[l]) pl--;
    while (pr < n && arr2[pr] == arr2[r]) pr++;


    sl=__min(sl,pl);
    sr=__max(sr,pr);

    ll i=0;
    ll j=n-1;
    ll sll=l;
    while (i<=sl && l <= r) {
        ll t=arr2[i];
        arr2[i++]=arr2[l];
        arr2[l++]=t;
    }

    while (j >= sr && r >= l) {
        ll t=arr2[j];
        arr2[j--]=arr2[r];
        arr2[r--]=t;
    }

    bool pos=true;

    for (int i=0;i<n;i++)
        if (arr2[i] == arr1[i]) {
            pos=false;
            break;
        }

    if (pos) par(n);
    else cout << "No\n";
}
