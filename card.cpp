#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
int main() {
	FILE *input = fopen("card.inp", "rt");
	FILE *output = fopen("card.out", "wt");

	int t, n, temp, check = 0;
	fscanf(input, "%d", &t);
	while (t--) {
		fscanf(input, "%d", &n);
		vector<int>arr(n + 1);
		vector<vector<int> >dp(n + 1, vector<int>(3));
		for (int i = 1; i < n + 1; i++) {
			fscanf(input, "%d", &arr[i]);
		}
		for (int i = 1; i < n + 1; i++) {
			if (i < 4) {
				dp[i][0] = arr[i];
				dp[i][1] = arr[i];
				dp[i][2] = arr[i];
			}
			else if (i == 4) {
				dp[i][0] = max(dp[i - 2][1], dp[i - 2][2]) + arr[i];
				dp[i][1] = max(dp[i - 3][1], max(dp[i - 3][0], dp[i - 3][2])) + arr[i];
				dp[i][2] = max(dp[i][0], dp[i][1]);
			}
			else if (i == 6) {
				dp[i][0] = arr[6] + arr[4] + arr[1];
				dp[i][1] = max(dp[i - 3][1], max(dp[i - 3][0], dp[i - 3][2])) + arr[i];
				dp[i][2] = max(dp[i - 4][2], max(dp[i - 4][0], dp[i - 4][1])) + arr[i];
			}
			else {
				dp[i][0] = max(dp[i - 2][1], dp[i - 2][2]) + arr[i];
				dp[i][1] = max(dp[i - 3][1], max(dp[i - 3][0], dp[i - 3][2])) + arr[i];
				dp[i][2] = max(dp[i - 4][2], max(dp[i - 4][0], dp[i - 4][1])) + arr[i];
			}
		}
		temp = max(dp[n][0], dp[n][1]);
		fprintf(output, "%d\n", max(dp[n][2], temp));
	}
	fclose(input);
	fclose(output);
}