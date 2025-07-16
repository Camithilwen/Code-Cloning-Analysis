#include <stdio.h>
#include <string.h>

int
main(void)
{
	char line[100];
	char res[100];

	auto chksep = [](char c) -> bool {
			return (c == ' ' || c == '.' || c == '\n');
		};

	while (fgets(line, sizeof line, stdin)) {
		int len = strlen(line);
		int state = 0;
		
		for (int s = 0; s < 26; s++) {

			for (int i = 0; i < len; i++) {
				if (chksep(line[i])) {
					res[i] = line[i];
				} else {
					int c = line[i] + s;
;					if (c > 'z') {
						res[i] = c - 'z' + 'a' - 1;
					} else {
						res[i] = c;
					}
				}

				switch (state) {
				case 0:
					if (res[i] == 't') {
						state = 1;
					}
					break;

				case 1:
					if (res[i] == 'h') {
						state = 2;
					} else {
						state = 0;
					}
					break;

				case 2:
					if (res[i] == 'e') {
						state = 5;
					} else if (res[i] == 'i') {
						state = 3;
					} else if (res[i] == 'a') {
						state = 4;
					} else {
						state = 0;
					}
					break;

				case 3:
					if (res[i] == 's') {
						state = 5;
					} else {
						state = 0;
					}
					break;

				case 4:
					if (res[i] == 't') {
						state = 5;
					} else {
						state = 0;
					}
					break;

				case 5:
					if (chksep(res[i])) {
						state = 99;
					} else {
						state = 0;
					}
					break;
				}
			}

			if (state == 99) {
				res[len] = 0;
				printf("%s", res);
				break;
			}
		}
	}

	return 0;
}