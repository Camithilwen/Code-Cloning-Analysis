#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;
 
int main(){
    string str ;
    while ( cin >> str ){
        int len = str.size() ;
        stack<char> container ;
        for ( int i = 0 ; i < str.size() ; i ++ ){
            if ( str[i] == 'T' ){
                if ( !container.empty() ){
                    if ( container.top() == 'S' ){
                        len -= 2 ;
                        container.pop() ;
                    }
                }else{
                    container.push(str[i]) ;
                }
            }else{
                container.push(str[i]) ;
            }
        }
        cout << len << endl ;
    }
    return 0 ;
}