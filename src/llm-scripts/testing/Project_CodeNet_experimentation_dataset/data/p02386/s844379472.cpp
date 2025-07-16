#include<iostream>
#include<string>
#include<vector>

using namespace std;

enum Diceface {
	DICETOP,
	DICEFRONT,
	DICERIGHT,
	DICELEFT,
	DICEBACK,
	DICEBOTTOM,
	DICENUM
};

class Dice {
private:
	int *face;
public:
	Dice( ) { face = new int[DICENUM]; }
	Dice( int top, int front, int right, int left, int back, int bottom ) {
		face = new int[DICENUM];
		
		face[DICETOP] = top;
		face[DICEFRONT] = front;
		face[DICERIGHT] = right;
		face[DICELEFT] = left;
		face[DICEBACK] = back;
		face[DICEBOTTOM] = bottom;
	}
	~Dice( ) {
		delete [ ] face;
	}
	void setFace( int top, int front, int right, int left, int back, int bottom ) {
		face[DICETOP] = top;
		face[DICEFRONT] = front;
		face[DICERIGHT] = right;
		face[DICELEFT] = left;
		face[DICEBACK] = back;
		face[DICEBOTTOM] = bottom;
	
		return;
	}
	void roll( char cmd ) {
		int t;
		if( 'E' == cmd ) {
			t = face[DICETOP];
			face[DICETOP] = face[DICELEFT];
			face[DICELEFT] = face[DICEBOTTOM];
			face[DICEBOTTOM] = face[DICERIGHT];
			face[DICERIGHT] = t;
		} else if( 'N' == cmd ) {
			t = face[DICETOP];
			face[DICETOP] = face[DICEFRONT];
			face[DICEFRONT] = face[DICEBOTTOM];
			face[DICEBOTTOM] = face[DICEBACK];
			face[DICEBACK] = t;
		} else if( 'S' == cmd ) {
			t = face[DICETOP];
			face[DICETOP] = face[DICEBACK];
			face[DICEBACK] = face[DICEBOTTOM];
			face[DICEBOTTOM] = face[DICEFRONT];
			face[DICEFRONT] = t;
		} else if( 'W' == cmd ) {
			t = face[DICETOP];
			face[DICETOP] = face[DICERIGHT];
			face[DICERIGHT] = face[DICEBOTTOM];
			face[DICEBOTTOM] = face[DICELEFT];
			face[DICELEFT] = t;
		} else if( 'M' == cmd ) {
			t = face[DICEBACK];
			face[DICEBACK] = face[DICERIGHT];
			face[DICERIGHT] = face[DICEFRONT];
			face[DICEFRONT] = face[DICELEFT];
			face[DICELEFT] = t;
		}
		return;
	}
	int getFace( int diceface ) {
		return face[ diceface ];
	}

	bool isDiff( Dice &dice ) {
		int cnt;
		string cmd = "MMMMNMMMMWMMMMWMMMMWMMMMNMMMM";

		for( int i=0; i<cmd.length(); i++ ) {		
			if( dice.getFace( DICETOP ) == face[ DICETOP ] ) {
				for( cnt=0; cnt<DICENUM; cnt++ ) {
					if( dice.getFace( cnt ) != face[ cnt ] ) { break; }
				}
				if( DICENUM == cnt ) { break; }
			}
			dice.roll( cmd[i] );
		}
		
		if( DICENUM == cnt ) {
			return false;
		} else {
			return true;
		}
	}

};

int main( )
{
	int t, f, r, l, ba, bo;
	int n;
	
	cin>>n;
	Dice *dice = new Dice[n];
	if( NULL == dice ) { return 0; }
	
	int cnt = 0;
	while( cnt < n ) {
		cin>>t>>f>>r>>l>>ba>>bo;
		dice[ cnt++ ].setFace( t, f, r, l, ba, bo );
	}
	
	bool isDiff = false;
	for( int i=0; i<n-1; i++ ) {
		for( int j=i+1; j<n; j++ ) {
			if( !( isDiff = dice[i].isDiff( dice[j] ) ) ) { break; }
		}
		if( !isDiff ) { break; }
	}
	if( isDiff ) {
		cout<<"Yes"<<endl;		
	} else {
		cout<<"No"<<endl;
	}

	delete [ ] dice; 
	
	return 0;
}