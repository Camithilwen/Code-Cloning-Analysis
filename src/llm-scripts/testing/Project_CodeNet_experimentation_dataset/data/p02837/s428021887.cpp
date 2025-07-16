//
//  honestorunkind2.cpp
//  my_programs
//
//  Created by Jiatuo Zou on 7/27/20.
//  Copyright © 2020 Jiatuo Zou. All rights reserved.
//

#include <iostream>
using namespace std;

int f = 0;

int combination(int n, int xy[][2], int A[], int b[], int d, int MAX){
    if(d == n){
        f = 0;
        for(int i = 1; i <= n; i++){
            for(int j = A[i - 1]; j < A[i]; j++){
                if(b[i - 1] == 1 && b[xy[j][0] - 1] != xy[j][1]){
                    f = 1;
                    break;
                }
            }
            if(f == 1){
                break;
            }
        }
        if(f == 0){
            for(int i = 0; i < n; i++){
                if(b[i] == 1){
                    f++;
                }
            }
            MAX = max(MAX, f);
        }
    }
    if(d < n){
        for(int i = 0; i <= 1; i++){
            b[d] = i;
            MAX = combination(n, xy, A, b, d + 1, MAX);
        }
    }
    return MAX;
}

int main()
{
    int n, xy[210][2] = {{0}}, A[16] = {0}, b[15];
    cin >> n;
    for(int i = 1; i <= n; i++){
        int a;
        cin >> a;
        A[i] += (a + A[i - 1]);
        for(int j = A[i - 1]; j < A[i]; j++){
            cin >> xy[j][0] >> xy[j][1];
        }
    }
    cout << combination(n, xy, A, b, 0, 0) << endl;
    return 0;
}
