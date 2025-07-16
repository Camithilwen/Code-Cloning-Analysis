#include <bits/stdc++.h>
using namespace std;

int main(void){
    
    list<char> A;
    list<char> B;
    list<char> C;
    
    string S_A,S_B,S_C;
    cin >> S_A >> S_B >> S_C;
    for(int i=0;i<S_A.size();i++) A.push_back(S_A[i]);
    for(int i=0;i<S_B.size();i++) B.push_back(S_B[i]);
    for(int i=0;i<S_C.size();i++) C.push_back(S_C[i]);
    
    char t = A.front();
    A.pop_front();
    
    while(1){
        
        if(t == 'a'){
            if(A.size() == 0){
                cout << 'A' << endl;
                return 0;
            }   
            t = A.front();
            A.pop_front();
            
        }
        else if(t == 'b'){
            if(B.size() == 0){
                cout << 'B' << endl;
                return 0;
            }
            t = B.front();
            B.pop_front();
            
        }
        else{
            if(C.size() == 0){
                cout << 'C' << endl;
                return 0;
            }
            t = C.front();
            C.pop_front();
        }
    }
}