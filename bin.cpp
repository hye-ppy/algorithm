#include<stdio.h>
#pragma warning (disable:4996)
using namespace std;
#include<algorithm>
#include<math.h>
int arr[501];
int dp[501][501][501];
int bin(int n, int m, int start);
int main() {
	FILE *input = fopen("bin.inp", "rt");
	FILE *output = fopen("bin.out", "wt");

	int n, m, start, t;
	fscanf(input, "%d", &t);
	while (t--) {
		fscanf(input, "%d %d", &n, &m);
		for (int i = 0; i < n; i++) {
			fscanf(input, "%d", &arr[i]);
		}
		sort(arr, arr + n);
		fprintf(output, "%d\n", bin(n, m, 0));
	}

	fclose(input);
	fclose(output);
}
int bin(int n, int m, int start) {
	if (n == m) {
		dp[n][m][start] = 0;
		return 0;
	}
	else if (m == 1) {
		if (dp[n][m][start] == 0) {
			int mid = (start + start + n - 1) / 2;
			int sum = 0;
			for (int i = start; i < start + n; i++) {
				sum += abs(arr[i] - arr[mid]);
			}
			dp[n][m][start] = sum;
		}
		return dp[n][m][start];
	}
	else if (m > 1) {
		int min;
		for (int i = 2; i < n; i++) {
			if (dp[i][m - 1][start] == 0) bin(i, m - 1, start);
			if (dp[n - i][1][start + i] == 0) bin(n - i, 1, start + i);
			if (i == 2) {
				min = dp[i][m - 1][start] + dp[n - i][1][start + i];
			}
			else {
				if (min > dp[i][m - 1][start] + dp[n - i][1][start + i]) {
					min = dp[i][m - 1][start] + dp[n - i][1][start + i];
				}
			}
		}
		for (int i = 1; i < n - 2; i++) {
			if (dp[i][1][start] == 0) bin(i, 1, start);
			if (dp[n - i][m - 1][start + i] == 0) bin(n - i, m - 1, start + i);
			if (min > dp[i][1][start] + dp[n - i][m - 1][start + i]) {
				min = dp[i][1][start] + dp[n - i][m - 1][start + i];
			}
		}
		dp[n][m][start] = min;
		return dp[n][m][start];
	}
}