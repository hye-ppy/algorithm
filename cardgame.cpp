#include<stdio.h>
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#pragma warning (disable:4996)
int n;
vector<int>card(1001);
int game(int n);
int main() {
	FILE *input = fopen("card.inp", "rt");
	FILE *output = fopen("card.out", "wt");

	int t;
	fscanf(input, "%d", &t);
	while (t--) {
		fscanf(input, "%d", &n);
		for (int i = 0; i < n; i++) {
			fscanf(input, "%d", &card[i]);
		}

		fprintf(output, "%d\n", game(n));
	}

	fclose(input);
	fclose(output);
}
int game(int n) {
	vector<vector<int> >dp(n, vector<int>(n));
	for (int x = 0; x < n; x++) {
		for (int i = 0, j = x; j < n; i++, j++) {
			int a, b, c;
			if (i + 2 <= j) {
				a = dp[i + 2][j];
			}
			else {
				a = 0;
			}
			if (i + 1 <= j - 1) {
				b = dp[i + 1][j - 1];
			}
			else {
				b = 0;
			}
			if (i <= j - 2) {
				c = dp[i][j - 2];
			}
			else {
				c = 0;
			}
			dp[i][j] = max(card[i] + min(a, b), card[j] + min(b, c));
		}
	}
	return dp[0][n - 1];
}