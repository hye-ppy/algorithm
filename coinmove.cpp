#include<stdio.h>
using namespace std;
#pragma warning(disable:4996)
#include<vector>
int main() {
	FILE *input = fopen("coinmove.inp", "rt");
	FILE *output = fopen("coinmove.out", "wt");
	
	int t, p, k, s;
	fscanf(input, "%d", &t);
	while (t--) {
		fscanf(input, "%d %d %d", &p, &k, &s);
		vector<vector<int> > dp(s + 1, vector<int>(k + 1));
		vector<int>result(s + 1);
		for (int x = 0; x <= s; x++) {
			for (int y = 1; y <= k; y++) {
				int check = 1;
				if (x != s && x%p == 0) {
					dp[x][y] = 0;
					continue;
				}
				for (int z = 1; z <= k; z++) {
					if (y != z) {
						if (x - z < 0) continue;
						if (x - z != 0 && (x - z) % p == 0) continue;
						if (dp[x - z][z] == 0) {
							if (check == 1) {
								result[x] = x - z;
							}
							check = 0;
						}
					}
				}
				if (check == 1) dp[x][y] = 0;
				else dp[x][y] = 1;
			}
		}
		if (result[s] == 0) fprintf(output, "-1\n");
		else fprintf(output, "%d\n", result[s]);
	}
}