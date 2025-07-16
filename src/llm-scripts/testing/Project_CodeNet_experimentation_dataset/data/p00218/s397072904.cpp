#include <iostream>
#include <vector>
//#include <fstream>

using namespace std;

int main()
{
//	cut here before submit 
//	freopen ("testcase.divstudent", "r", stdin );
	const char rank[] = { 'A', 'B', 'C' };
	int n;

	while (cin >> n && n ){
		vector <vector <int> > s(n, vector <int> (3, 0 ) );

		for (int i = 0; i < n; ++i){
			for (int j = 0; j < 3; ++j){
				cin >> s[i][j];	// pm, pe, pj order
			} // end for
		} // end for
/*
100 _ÌÈÚª é	 A
wÆpêÌ½Ï_ª 90 _Èã	 A
3 ÈÚÌ½Ï_ª 80 _Èã	 A
3 ÈÚÌ½Ï_ª 70 _Èã	 B
3 ÈÚÌ½Ï_ª 50 _ÈãÅw©pêª 80 _Èã	 B
ãÌðð½³È¢	 C
¡Ìðð½·êÍAæèxÌ¢NXÉª¯çêÜ·B
*/
		for (int i = 0; i < n; ++i){

			double me  = (s[i][0] + s[i][1])/2.;
			double avg = (s[i][0] + s[i][1] + s[i][2])/3.;
 	
			if ( s[i][0] == 100 || s[i][1] == 100 || s[i][2] == 100
			|| me >= 90.0 || avg >= 80. ) {
				cout << rank[0] << endl;
				continue;
			} // end if
			if ( avg >= 70. || (avg >= 50. && (s[i][0] >= 80 || s[i][1] >= 80 ) ) ) {
				cout << rank[1] << endl;
				continue;
			} // end if

			cout << rank[2] << endl;
		} // end for
	} // end loop
		
	return 0;
}