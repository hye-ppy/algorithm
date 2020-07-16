#include <stdio.h>
#include <algorithm>
#include<vector>
using namespace std;
#pragma warning(disable:4996)
int dp[5001][5001];
int arr1[5001][26];
int arr2[5001][26];
int arr[26];
int color(vector<char>line1, vector<char>line2);
int main() {
	FILE *input = fopen("color.inp", "rt");
	FILE *output = fopen("color.out", "wt");
	int t;;
	char c;
	fscanf(input, "%d", &t);

	fscanf(input, "%c", &c);
	while (t--) {
		vector<char>line1;
		vector<char>line2;
		for (;;) {
			fscanf(input, "%c", &c);
			if (c == '\n') break;
			line1.push_back(c);
		}
		for (;;) {
			fscanf(input, "%c", &c);
			if (c == '\n') break;
			line2.push_back(c);
		}
		fprintf(output, "%d\n", color(line1, line2));
		
	}
	return 0;
}
int color(vector<char>line1, vector<char>line2) {
	int a, b, count, num;
	for (int i = 1; i <= line1.size(); i++) {
		for (int j = 0; j < 26; j++) {
			arr1[i][j] = arr1[i - 1][j];
		}
		arr1[i][line1[i - 1] - 'A']++;
	}
	for (int i = 1; i <= line2.size(); i++) {
		for (int j = 0; j < 26; j++) {
			arr2[i][j] = arr2[i - 1][j];
		}
		arr2[i][line2[i - 1] - 'A']++;
	}
	for (int i = 0; i < 26; i++) {
		arr[i] = arr1[line1.size()][i] + arr2[line2.size()][i];
	}
	for (int i = 0; i <= line1.size(); i++) {
		for (int j = 0; j <= line2.size(); j++) {
			dp[i][j] = 0x7fffffff;
		}
	}
	dp[0][0] = 0;
	for (int i = 0; i < line1.size() + line2.size(); i++) {
		int x = i + 1;
		int y = -1;
		while (x > 0) {
			x--;
			y++;
			if (x > line1.size()) continue;
			if (y > line2.size()) break;
			b = dp[x][y];
			if (x + 1 <= line1.size()) {
				a = b;
				count = line1[x] - 'A';
				num = arr1[x + 1][count] + arr2[y][count];

				if (num == 1) a -= i;
				if (num == arr[count]) a += i;
				if (dp[x + 1][y] > a) dp[x + 1][y] = a;
			}
			if (y + 1 <= line2.size()) {
				a = b;
				count = line2[y] - 'A';
				num = arr1[x][count] + arr2[y + 1][count];

				if (num == 1) a -= i;
				if (num == arr[count]) a += i;
				if (dp[x][y + 1] > a) dp[x][y + 1] = a;
			}
		}
	}
	return dp[line1.size()][line2.size()];
}