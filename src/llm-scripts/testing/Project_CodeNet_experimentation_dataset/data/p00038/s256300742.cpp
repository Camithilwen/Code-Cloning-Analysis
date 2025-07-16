#include<iostream>
#include<string>
#include<algorithm>
#define NC 5

using namespace std;

int C[ NC ];

bool isStraight(){
    for ( int i = 2; i < 5; i++ ){
	if ( C[i-1] != C[i] - 1 ) return false;
    }
    if ( C[4] == 13 ) return ( C[0] == 1 ) ? true : false;
    return ( C[0] == C[1] - 1 ) ? true : false;
}

bool isFourC(){
    for ( int i = 2; i < 4; i++ ) if ( C[i-1] != C[i] ) return false;
    return ( C[0] == C[1] || C[3] == C[4] );
}

bool isFullHouse(){
    if ( C[0] == C[1] && C[2] == C[3] && C[3] == C[4] ||
	 C[0] == C[1] && C[1] == C[2] && C[3] == C[4] ) return true;
    else return false;
}

bool isThreeC(){
    if ( C[0] == C[1] && C[1] == C[2] ||
	 C[1] == C[2] && C[2] == C[3] ||
	 C[2] == C[3] && C[3] == C[4] ) return true;
    else return false;
}

bool isPair(int pair){
    int sum = 0;
    for ( int i = 1; i < 5; i++ ) if ( C[i-1] == C[i] ) sum++;
    return sum == pair; // one pair ツつゥ two pair 
}

string judge(){
    sort( C, C + NC );

    if ( isStraight() ) return "straight";
    else if ( isFourC() ) return "four card";
    else if ( isFullHouse() ) return "full house";
    else if ( isThreeC() ) return "three card";
    else if ( isPair(2) ) return "two pair";
    else if ( isPair(1) ) return "one pair";
    else return "null";
}

bool read(){
    char comma;
    if ( !(cin >> C[0]) ) return false;
    for ( int i = 1; i < NC; i++ ){
	cin >> comma >> C[i];
    }
    return true;
}

int main(){
    while ( read() ){
	cout << judge() << endl;
    }
    return 0;
}