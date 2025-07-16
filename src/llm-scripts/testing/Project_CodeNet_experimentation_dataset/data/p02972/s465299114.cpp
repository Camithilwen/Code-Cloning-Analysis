#include<iostream>
#include<vector>

int main(void){
    int n;
    std::cin >> n;
    std::vector<int> a(n+1), b(n+1);
    a[0] = 0;
    for(int i = 1; i <= n; i++){
        std::cin >> a[i];
    }

    for(int i = n; i > 0; i--){
        int cnt = 0;
        for(int j = i; j <= n; j += i){
            if(b[j] == 1) cnt++;
        }
        cnt = cnt % 2;
        if(cnt != a[i]) b[i] = 1;
    }
    int zcnt = 0;
    for(int i = 1; i <= n; i++){
        if(b[i] == 1){
            zcnt++;
        }
    }
    std::cout << zcnt << std::endl;
    for(int i = 1; i <= n; i++){
        if(b[i] == 1){
            std::cout << i << " ";
        }
    }

    return 0;
}