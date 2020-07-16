#include<stdio.h>
#pragma warning (disable:4996)
using namespace std;
#include<algorithm>
#include<math.h>
int dp[201][201][201];
int cube(int w, int l, int h);
int main() {
	FILE *input = fopen("cube.inp", "rt");
	FILE *output = fopen("cube.out", "wt");

	int w, l, h, t;
	fscanf(input, "%d", &t);
	while (t--) {
		fscanf(input, "%d %d %d", &w, &l, &h);
		fprintf(output,"%d\n", cube(w, l, h));
	}

	fclose(input);
	fclose(output);
}
int cube(int w, int l, int h) {
	if (dp[w][l][h] != 0) return dp[w][l][h];
	if (w > l) swap(w, l);
	if (l > h) swap(l, h);
	if (w > l) swap(w, l);
	if (dp[w][l][h] != 0) return dp[w][l][h];
	if (w == l && l == h) {
		dp[w][l][h] = 1;
		return 1;
	}
	
	if (w == 1) {
		dp[w][l][h] = l * h;
		return dp[w][l][h];
	}
	int min = 0;
	for (int j = 1; j < w; j++) {
		if (min == 0) {
			min = cube(w - j, l, h) + cube(j, l, h);
		}
		else if (cube(w - j, l, h) + cube(j, l, h) < min) {
			min = cube(w - j, l, h) + cube(j, l, h);
		}
	}
	for (int j = 1; j < l; j++) {
		if (min == 0) {
			min = cube(w, l - j, h) + cube(w, j, h);
		}
		else if (cube(w, l - j, h) + cube(w, j, h) < min) {
			min = cube(w, l - j, h) + cube(w, j, h);
		}
	}
	for (int j = 1; j < h; j++) {
		if (min == 0) {
			min = cube(w, l, h - j) + cube(w, l, j);
		}
		else if (cube(w, l, h - j) + cube(w, l, j) < min) {
			min = cube(w, l, h - j) + cube(w, l, j);
		}
	}
	dp[w][l][h] = min;
	return dp[w][l][h];
	
}