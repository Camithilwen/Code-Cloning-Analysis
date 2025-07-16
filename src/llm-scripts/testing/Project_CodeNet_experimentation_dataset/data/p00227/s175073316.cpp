#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <boost/tokenizer.hpp>
#include <boost/lexical_cast.hpp>
#include <vector>
#include <list>

using namespace std;
using namespace boost;


int main(int argc, char* argv[])
{
	using sprtr = char_separator<char>;
	using tknzr = tokenizer<sprtr>;
	sprtr sep(" ", "", keep_empty_tokens);

	int f, mf, mo;

	string line;
	while(1) {

		int n, m;
		{
			getline(cin, line);
			tknzr tkns(line, sep);
			auto it = tkns.begin();
			n = lexical_cast<int>(*it++);
			m = lexical_cast<int>(*it);
		}

		if( n == 0 && m == 0 ) {
			break;
		}
		
		list<int> ps;		
		{
			getline(cin, line);
			tknzr tkns(line, sep);
			for( auto p : tkns ) {
				//cout << p << endl;
				ps.push_back(lexical_cast<int>(p));
			}
		}

		ps.sort(greater<int>());

		int div = n / m;
		int mod = n % m;

		int sum = 0;
		auto it = ps.begin();
		for( int i = 0; i < div; i++ ) {
			for( int j = 0; j < m; j++ ) {
				auto p = *it++;
				if( j == m-1 ) continue;
				sum += p;
			}
		}

		if( mod ) {
			for( int i = 0; i < mod; i++ ) {
				auto p = *it++;
				sum += p;			   
			}
		}

		cout << sum << endl;

		ps.clear();
		
	}

    return 0;
}