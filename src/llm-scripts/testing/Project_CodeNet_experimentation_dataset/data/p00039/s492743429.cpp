#define scanf_s scanf
//#define gets_s gets
#include <stdio.h>
#include <string>
#include <iostream>
#include <math.h>
using namespace std;
#define MAX 101
#define MIN -100001
#define _MAX 8


int main(void)
{
	char roman[102];
	char fig[8] = { "IVXLCDM" };
	int value[7] = { 1,5,10,50,100,500,1000 };
	int  sum = 0, b = _MAX;
	while (scanf_s("%s", &roman, MAX) != EOF) {
		for (int i = 0; roman[i] != '\0'; ++i) {
			for (int j = 0; j < 8; ++j) {
				if (roman[i] == fig[j]) {
					if (b >= j) sum += value[j];
					else { sum -= value[b]; sum += value[j] - value[b]; }
					b = j;
				}
			}
		}
		printf("%d\n", sum);
		sum = 0; b = _MAX;
	}
}