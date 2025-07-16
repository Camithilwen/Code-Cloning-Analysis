#include <array>
#include <cstdlib>
#include <iostream>
#include <string>
#include <queue>
#include <vector>
class SSF {
private:
	void ScanLine(std::vector<std::string> *map, const char lx, const char rx, const char y, const char oy, std::array<std::queue<char>, 4> *buffer) {
		unsigned char i = lx;
		while (i <= rx) {
			while (i < rx) {
				if (map->at(y).at(i) != '0') {
					break;
				}
				++i;
			}
			if (map->at(y).at(i) == '0') {
				break;
			}
			buffer->at(0).push(i);
			while (i <= rx) {
				if (map->at(y).at(i) == '0') {
					break;
				}
				++i;
			}
			buffer->at(1).push(i - 1);
			buffer->at(2).push(y);
			buffer->at(3).push(oy);
		}
		return;
	}
public:
	unsigned char SeedFill(std::vector<std::string> *map, const unsigned char x, const unsigned char y) {
		std::array<std::queue<char>, 4> buffer;
		unsigned char lx, rx, ly, oy;
		if (map->at(y).at(x) == '0' || map->empty() == true) {
			return 0;
		}
		buffer.at(0).push(x);
		buffer.at(1).push(x);
		buffer.at(2).push(y);
		buffer.at(3).push(y);
		while (buffer.front().empty() == false) {
			char lxsav = buffer.at(0).front() - 1, rxsav = buffer.at(1).front() + 1;
			lx = buffer.at(0).front();
			buffer.at(0).pop();
			rx = buffer.at(1).front();
			buffer.at(1).pop();
			ly = buffer.at(2).front();
			buffer.at(2).pop();
			oy = buffer.at(3).front();
			buffer.at(3).pop();
			if (map->at(ly).at(lx) == '0') {
				continue;
			}
			while (rx < map->at(ly).size() - 1) {
				if (map->at(ly).at(rx + 1) == '0') {
					break;
				}
				++rx;
			}
			while (lx > 0) {
				if (map->at(ly).at(lx - 1) == '0') {
					break;
				}
				--lx;
			}
			for (unsigned char i = lx; i <= rx; ++i) {
				map->at(ly).at(i) = '0';
			}
			if (ly - 1 >= 0) {
				if (ly - 1 == oy) {
					ScanLine(map, lx, lxsav, ly - 1, ly, &buffer);
					ScanLine(map, rxsav, rx, ly - 1, ly, &buffer);
				}
				else {
					ScanLine(map, lx, rx, ly - 1, ly, &buffer);
				}
			}
			if (ly + 1 <= map->size() - 1) {
				if (ly + 1 == oy) {
					ScanLine(map, lx, lxsav, ly + 1, ly, &buffer);
					ScanLine(map, rxsav, rx, ly + 1, ly, &buffer);
				}
				else {
					ScanLine(map, lx, rx, ly + 1, ly, &buffer);
				}
			}
		}
		return 1;
	}
};
int main() {
	while (1) {
		SSF ssf;
		std::vector<std::string> map;
		unsigned short count = 0;
		do {
			map.resize(count + 1);
			std::getline(std::cin, map.at(count));
			if (map.at(count).empty() == true) {
				std::getline(std::cin, map.at(count));
				if (map.at(count).empty() == true) {
					return EXIT_SUCCESS;
				}
			}
			map.at(count).resize(map.front().size(), '0');
			map.at(count).shrink_to_fit();
		} while (++count < map.front().size());
		map.shrink_to_fit();
		count = 0;
		for (unsigned char j = 0; j < map.size(); ++j) {
			for (unsigned char i = 0; i < map.at(j).size(); ++i) {
				count += ssf.SeedFill(&map, i, j);
			}
		}
		std::cout << count << std::endl;
	}
	return EXIT_SUCCESS;
}