#include<stdio.h>
#include<iostream>
#pragma warning (disable:4996)
using namespace std;
long long pole(int n, int l, int r);
long long p[21][21][21];
int main() {
	FILE *input = fopen("pole.inp", "rt");
	FILE *output = fopen("pole.out", "wt");

	int t, n, l, r;
	fscanf(input, "%d", &t);
	while (t--) {
		fscanf(input, "%d %d %d", &n, &l, &r);
		fprintf(output, "%lld\n", pole(n, l, r));
	}

	fclose(input);
	fclose(output);
}
long long pole(int n, int l, int r) {
	p[1][1][1] = 1;
	for (int nn = 2; nn <= n; nn++) {
		for (int ll = 1; ll <= l; ll++) {
			for (int rr = 1; rr <= r; rr++) {
				p[nn][ll][rr] = p[nn - 1][ll - 1][rr] + p[nn - 1][ll][rr - 1] + p[nn - 1][ll][rr] * (nn - 2);
			}
		}
	}
	return p[n][l][r];
}
