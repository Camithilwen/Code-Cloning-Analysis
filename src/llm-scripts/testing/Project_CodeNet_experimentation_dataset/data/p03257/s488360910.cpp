#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int maxN = 500;

long long gcd(long long a, long long b){
    return a%b ? gcd(b, a%b) : b;
}

long long lcm(long long a, long long b){
    return a/gcd(a, b)*b;
}

vector<vector<int>> getPrimes(){
    vector<int> p(100000, 1);
    vector<int> primes;
    for(int i=2;;i++){
        if(!p[i]) continue;
        primes.push_back(i);
        if(primes.size() == 4 * maxN) break;
        for(int j=2*i;j<100000;j+=i) p[j] = 0;
    }
    vector<vector<int>> res(2, vector<int>(2*maxN));
    int seek = 0;
    for(int i=0;i<maxN;i++){
        res[0][2*i] = primes[seek];
        res[0][2*i+1] = primes[3*maxN-1-seek];
        ++seek;
    }
    for(int i=0;i<2*maxN;i++){
        if(i < maxN/4 || maxN/4*7 <= i){
            res[1][i] = res[0][i];
        } else {
            if(i%2 == 0){
                res[1][i] = primes[seek];
            } else {
                res[1][i] = primes[3*maxN-1-seek];
                ++seek;
            }
        }
    }
    return res;
}

vector<vector<long long>> makeBoard(){
    vector<vector<long long>> res(maxN, vector<long long>(maxN, 0));
    auto primes = getPrimes();
    for(int i=0;i<maxN;i++){
        for(int j=i%2;j<maxN;j+=2){
            int idxA = (i+j)/2;
            int idxB = (i-j+maxN-2)/2;
            res[i][j] = (long long)primes[0][idxA] * primes[1][idxB];
        }
    }
    for(int i=0;i<maxN;i++){
        for(int j=1-i%2;j<maxN;j+=2){
            res[i][j] = 1;
            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, -1, 0, 1};
            for(int k=0;k<4;k++){
                int nx = i + dx[k];
                int ny = j + dy[k];
                if(nx < 0 || maxN <= nx || ny < 0 || maxN <= ny) continue;
                res[i][j] = lcm(res[i][j], res[nx][ny]);
            }
            ++res[i][j];
        }
    }
    return res;
}

int main(){
    int N;
    auto board = makeBoard();
    while(cin >> N){
        for(int i=0;i<N;i++){
            cout << board[i][0];
            for(int j=1;j<N;j++) cout << " " << board[i][j];
            cout << endl;
        }
    }
}