#include <iostream> 
#include <cstdio> 
#include <cstdlib> 
#include <cstring> 
#include <cmath> 
#include <algorithm> 
using namespace std; 
const int Mod = 1e9 + 7; 
int N, M, X, Y, Z, f[41][1 << 18]; 
int OK, ALL; 
void pls(int &x, int y) { x += y; if (x >= Mod) x -= Mod; } 
int main () { 
	cin >> N >> X >> Y >> Z; 
	M = X + Y + Z; 
	OK = (1 << (X + Y + Z - 1)) | (1 << (Y + Z - 1)) | (1 << (Z - 1)); 
	ALL = (1 << M) - 1; 
	f[0][0] = 1; 
	for (int i = 1; i <= N; i++) { 
		for (int s = 0; s < 1 << M; s++) { 
			for (int j = 1; j < 11; j++) { 
				int t = ((s << j) | (1 << (j - 1))) & ALL; 
				if ((t & OK) == OK) continue; 
				pls(f[i][t], f[i - 1][s]); 
			} 
		} 
	} 
	int ans = 1; 
	for (int i = 1; i <= N; i++) ans = 10ll * ans % Mod; 
	for (int i = 0; i < 1 << M; i++) ans = (ans - f[N][i] + Mod) % Mod; 
	printf("%d\n", ans); 
    return 0; 
} 