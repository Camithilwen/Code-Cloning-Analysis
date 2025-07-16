#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define pll pair <ll, ll>
#define pci pair <char, int>
#define pld pair <ld, ld>
#define ppld pair <pld, pld>
#define ppll pair <pll, pll>
#define pldl pair <ld, ll>
#define vll vector <ll>
#define vvll vector <vll>
#define vpll vector <pll>
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define mll map <ll, ll>
#define fastmap gp_hash_table
#define cd complex <double>
#define vcd vector <cd>
#define PI 3.14159265358979
#define ordered_set tree <ll, null_type, less <ll>, rb_tree_tag, tree_order_statistics_node_update>
#pragma 03
using namespace std;
using namespace __gnu_pbds;
ll a[200005], b[200005], c[400005], d[200005], lps[200005];
ll n;
void clps(){ 
    ll l = 0; lps[0] = 0; ll i = 1; 
    while (i < n){ 
        if (d[i] == d[l]) l++, lps[i] = l, i++; 
        else if (l != 0) l = lps[l - 1]; 
        else lps[i] = 0, i++;  
    } 
} 
vll fp;
void kmp(){
  	clps();
    ll i = 0, j = 0;
    while (i < 2 * n - 1){ 
        if (d[j] == c[i]){ 
            j++; i++; 
        } 
        if (j == n){
			fp.pb(i - j); 
            j = lps[j - 1]; 
        } 
        else if ((i < 2 * n - 1) && (d[j] != c[i])){ 
            if (j != 0) j = lps[j - 1]; 
            else i++; 
        } 
    } 
} 
int main(){
	cin >> n;
	for (ll i = 0; i < n; i++) cin >> a[i];
	for (ll i = 0; i < n; i++) cin >> b[i];
	for (ll i = 0; i < n; i++) c[i] = a[i] ^ a[(i + 1) % n];
	for (ll i = 0; i < n; i++) d[i] = b[i] ^ b[(i + 1) % n];
	for (ll i = n; i < 2 * n - 1; i++) c[i] = c[i - n];
	kmp();
	for (ll i = 0; i < fp.size(); i++) cout << fp[i] << " " << (b[0] ^ a[fp[i]]) << endl;
}