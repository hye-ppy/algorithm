#include<stdio.h>
#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
#pragma warning (disable:4996)
using namespace std;
int main() {
	FILE *input, *output;
	input = fopen("ladder.inp", "rt");
	output = fopen("ladder.out", "wt");

	int k, a, b, c, d;
	fscanf(input, "%d", &k);
	vector<vector<int> >arr(10001, vector<int>(4));
	vector<vector<int> >ladder(k);
	vector<int>result(k);
	for (int i = 0;; i++) {
		fscanf(input, "%d %d %d %d", &a, &b, &c, &d);
		if (a == 0 && b == 0 && c == 0 && d == 0) break;
		arr[i][0] = a; arr[i][1] = b;
		arr[i][2] = c; arr[i][3] = d;
		ladder[a].push_back(b);
		ladder[c].push_back(d);
	}
	for (int i = 0; i < k; i++) {
		sort(ladder[i].begin(), ladder[i].end(), greater<int>());//내림차순정렬
	}
	for (int i = 0; i < k; i++) {
		int index1 = i, index2 = 0;
		for (;;) {
			for (int x = 0;; x++) {
				if (arr[x][0] == index1 && arr[x][1] == ladder[index1][index2]) {
					index1 = arr[x][2];
					for (int y = 0; y < ladder[index1].size(); y++) {
						if (arr[x][3] == ladder[index1][y]) {
							index2 = y;
							break;
						}
					}
					break;
				}
				else if (arr[x][2] == index1 && arr[x][3] == ladder[index1][index2]) {
					index1 = arr[x][0];
					for (int y = 0; y < ladder[index1].size(); y++) {
						if (arr[x][1] == ladder[index1][y]) {
							index2 = y;
							break;
						}
					}
					break;
				}
			}
			if (ladder[index1][index2] == ladder[index1][ladder[index1].size() - 1]) {
				result[index1] = i;
				break;
			}
			index2++;
		}
	}
	for (int i = 0; i < k; i++) {
		fprintf(output, "%d ", result[i]);
	}
	fclose(input);
	fclose(output);
}
