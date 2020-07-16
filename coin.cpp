#include<iostream>
#include<stdio.h>
using namespace std;
#include<vector>
#pragma warning (disable:4996)
int dp[101][101][101];
void coin(int a, int b, int c);
int main() {
	FILE *input = fopen("coin.inp", "rt");
	FILE *output = fopen("coin.out", "wt");
	
	int n, a, b, c;
	fscanf(input, "%d", &n);
	while (n--) {
		fscanf(input, "%d %d %d", &a, &b, &c);
		coin(a, b, c);
		fprintf(output, "(%d %d %d) :  %d\n", a, b, c, dp[a][b][c]);
	}


	fclose(input);
	fclose(output);
}
void coin(int a, int b, int c) {
	if (dp[a][b][c] != 0) return;
	if (a + b + c == 1) {
		dp[a][b][c] = -1;
		return;
	}
	for (int i = 1; i < 4; i++) {
		if (a >= i) {
			if (dp[a - i][b][c] == 0) {
				coin(a - i, b, c);
			}
			if (dp[a - i][b][c] == -1) {
				dp[a][b][c] = 1;
				return;
			}
			
		}
		if (b >= i) {
			if (dp[a][b - i][c] == 0) {
				coin(a, b - i, c);
			}
			if (dp[a][b - i][c] == -1) {
				dp[a][b][c] = 1; 
				return;
			}

		}
		if (c >= i) {
			if (dp[a][b][c - i] == 0) {
				coin(a, b, c - i);
			}
			if (dp[a][b][c - i] == -1) {
				dp[a][b][c] = 1;
				return;
			}

		}
	}
	dp[a][b][c] = -1;
	return;
}