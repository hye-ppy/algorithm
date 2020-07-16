#include<stdio.h>
#include<iostream>
#include<vector>
#pragma warning (disable:4996)
using namespace std;
int pandora(FILE *input) {
	char c;
	vector<char>pan;
	for (;;) {
		fscanf(input, "%c", &c);
		if (c == '\n') break;
		pan.push_back(c);
	}
	pan.push_back(pan[0]);
	pan.push_back(pan[1]);
	int now = 0, pre = 0, prepre = 0;
	int x = 1, y = 1;
	for (int i = 0; i < pan.size(); i++) {
		if (pan[i] == 'L') {
			prepre = pre;
			pre = now;
			now = (now + 1) % 4;
		}
		else {
			prepre = pre;
			pre = now;
			now = (now + 3) % 4;
		}
		if (i <= 1) continue;
		if (prepre == 1 && pre == 0 && now == 3) y = 0;
		if (prepre == 3 && pre == 2 && now == 1) y = 0;
		if (prepre == 0 && pre == 3 && now == 2) x = 0;
		if (prepre == 2 && pre == 1 && now == 0) x = 0;
	}
	return x + y;
}
int main() {
	FILE *input = fopen("pandora.inp", "rt");
	FILE *output = fopen("pandora.out", "wt");
	int t;
	char c;
	fscanf(input, "%d", &t);
	fscanf(input, "%c", &c);
	while (t--) {
		fprintf(output, "%d\n", pandora(input));
	}
	fclose(input);
	fclose(output);
}