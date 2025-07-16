#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    vector<int> via(n),vib(n);
    for(int i = 0; i < n; i++){
        scanf("%d", &via[i]);
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &vib[n-i-1]);
    }
    
    int k = -1;
    int kCount = 0;
    for(int i = 0; i < n; i++){
        if(via[i] == vib[i]){
            k = via[i];
            kCount++;
        }
    }
    if(kCount > 0){
        int iaNotEqual_k, ibNotEqual_k, iabEqual_k;
        for(int i = 0; i < n; i++){
            if(via[i] == k){
                iaNotEqual_k = i;
                break;
            }        
        }
        for(int i = 0; i < n; i++){
            if(vib[i] == k){
                ibNotEqual_k = i;
                break;
            }        
        }
        for(int i = n - 1; i >= 0; i--){
            if(via[i] == vib[i]){
                iabEqual_k = i;
                iabEqual_k++;
                break;
            }        
        }
        int iRev = min(iaNotEqual_k + ibNotEqual_k, iabEqual_k);
        reverse(vib.begin(), vib.begin()+iRev);
        reverse(vib.begin()+iRev, vib.end());
    }
        
    for(int i = 0; i < n; i++){
        if(via[i] == vib[i]){
            printf("No");
            return 0;
        }
    }
    
    printf("Yes\n");
    for(int i = 0; i < n; i++){
        printf("%d ", vib[i]);
    }
    return 0;
}
