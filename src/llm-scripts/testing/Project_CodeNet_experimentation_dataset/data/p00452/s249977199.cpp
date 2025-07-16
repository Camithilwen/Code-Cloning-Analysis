#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M;
int score[1002001];
int point[1001];
int bin_search(int n){
    int h=0, t=(N+1)*(N+1);
    int temp;
    int status;
    while(h<=t){
        temp = (t+h)/2;
        if(n == score[temp]) return -1;
        else if(n > score[temp]){
            h = temp + 1;
            status = 1;
        }else{
            t = temp - 1;
            status = 0;
        }
    }
    if(status){
        return score[temp];
    }else{
        return score[temp-1];
    }
}
int main(){
    int a;
    int size;
    int b;
    int m;
    cin >> N >> M;
    while(N || M){
        m = 0;
        point[0] = 0;
        for(int i=1;i<=N;i++){
            cin >> point[i];
        }
        size = -1;
        for(int i=0;i<=N;i++){
            for(int j=0;j<=N;j++){
                score[size++] = point[i]+point[j];
            }
        }
        sort(score,score+size);
        for(int i=0;i<size && score[i] < M;i++){
            b = bin_search(M-score[i]);
            if(b == -1){
                break;
            }else{
                m = max(m, b+score[i]);
            }
        }
        cout << m << endl;
        cin >> N >> M;
    }
}