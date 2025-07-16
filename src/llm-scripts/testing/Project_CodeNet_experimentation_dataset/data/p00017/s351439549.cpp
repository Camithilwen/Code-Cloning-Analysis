#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

const int msg_size = 80;
const char int2alp[26] = {
	'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
	'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
	'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
	'y', 'z'
};

typedef map<char, int> myMap;
myMap alp2int;

int get_length(char *data) {
	for (int i = 0;; i++) {
		if (data[i] == '\0') {
			return i;
		}
	}
}

bool is_match(char *data) {
	for (int i = 0; i < 81; i++) {
		if (data[i] == 't' && data[i+1] == 'h') {
			if (data[i+2] == 'e') {
				return true;
			}
			else if (data[i+2] == 'i' && data[i+3] == 's'){
				return true;
			}
			else if (data[i+2] == 'a' && data[i+3] == 't') {
				return true;
			}
		}
	}
	return false;
}

bool gen_caesar(char *data, int size, int length) {
	char prev[100], back[100];
	prev[length] = back[length] ='\0';
	for (int i = 0; i < length; i++) {
		if (data[i] == ' ' || data[i] == '.' || data[i] == '\n') {
			prev[i] = data[i];
			back[i] = data[i];
		}
		else {
			prev[i] = int2alp[(alp2int[data[i]]+size) % 26];
			back[i] = int2alp[(alp2int[data[i]] >= size) ? alp2int[data[i]]-size : 26-(size-alp2int[data[i]])];
		}
	}
	if (is_match(prev)) {
		printf("%s", prev);
		return true;
	}
	if (is_match(back)) {
		printf("%s", back);
		return true;
	}
	return false;
}

void init_alp2int() {
	alp2int.insert(myMap::value_type('a', 0));
	alp2int.insert(myMap::value_type('b', 1));
	alp2int.insert(myMap::value_type('c', 2));
	alp2int.insert(myMap::value_type('d', 3));
	alp2int.insert(myMap::value_type('e', 4));
	alp2int.insert(myMap::value_type('f', 5));
	alp2int.insert(myMap::value_type('g', 6));
	alp2int.insert(myMap::value_type('h', 7));
	alp2int.insert(myMap::value_type('i', 8));
	alp2int.insert(myMap::value_type('j', 9));
	alp2int.insert(myMap::value_type('k', 10));
	alp2int.insert(myMap::value_type('l', 11));
	alp2int.insert(myMap::value_type('m', 12));
	alp2int.insert(myMap::value_type('n', 13));
	alp2int.insert(myMap::value_type('o', 14));
	alp2int.insert(myMap::value_type('p', 15));
	alp2int.insert(myMap::value_type('q', 16));
	alp2int.insert(myMap::value_type('r', 17));
	alp2int.insert(myMap::value_type('s', 18));
	alp2int.insert(myMap::value_type('t', 19));
	alp2int.insert(myMap::value_type('u', 20));
	alp2int.insert(myMap::value_type('v', 21));
	alp2int.insert(myMap::value_type('w', 22));
	alp2int.insert(myMap::value_type('x', 23));
	alp2int.insert(myMap::value_type('y', 24));
	alp2int.insert(myMap::value_type('z', 25));
}

int main(int argc, char *argv[]) {
	init_alp2int();
	char rcv[100];
	
	while(NULL != fgets(rcv, 80, stdin)) {
		int length = get_length(rcv);
	
		for (int i = 0; i < 26; i++) {
			if (gen_caesar(rcv, i, length)) {
				break;
			}
		}
	}
	return 0;
}