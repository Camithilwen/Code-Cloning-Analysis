#include <iostream>
#include <vector>
int main() {
    int N;
    std::cin >> N;
    std::vector<int> CuSumWest(N,0),CuSumEast(N,0);
    std::vector<int> CDNum(N,0);//i番目がリーダーだったときに向きを変えなければならない人の数 = CDNum[i]


    for(int i=0;i<N;i++){
        if(i != 0) {
            CuSumEast[i] = CuSumEast[i - 1];
            CuSumWest[i] = CuSumWest[i - 1];
        }
        char input;
        std::cin >> input;
        if(input == 'E'){
            CuSumEast[i]++;
        }else{
            CuSumWest[i]++;
        }
    }
    for(int i=0;i<N;i++) {
        CDNum[i] = CuSumWest[i] + (CuSumEast[N-1] - CuSumEast[i]);
        if((CuSumWest[i] == 1 && i==0) || (CuSumWest[i] - CuSumWest[i-1] == 1) )
            CDNum[i] -- ;
    }

    int min = CDNum[0];

    for(int i=0;i<N;i++){
        if(min > CDNum[i]){
            min = CDNum[i];
        }
    }

    std::cout << min;

    return 0;

}