#include<bits/stdc++.h>
int main() {
	int arr[26]{};
	std::string name;
	std::cin >> name;
	int n=name.size();
	bool yes = 1;
	for (int x = 0; x < n; x += 2) {
		if (name.substr(x, 2) != "hi") {
			yes = false;
		}
	}
	std::cout << (yes == 1 ? "Yes" : "No");

}