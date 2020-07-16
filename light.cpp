#include <stdio.h>
#include <vector>
#include <algorithm>
#pragma warning(disable: 4996)
using namespace std;
int light(int a, int b, vector<vector<int> >l);
int main(void) {
	FILE* input = fopen("light.inp", "rt");
	FILE* output = fopen("light.out", "wt");

	int a, b, t;

	fscanf(input, "%d\n", &t);
	vector<vector<int> >l(t, vector<int>(2));
	for (int i = 0; i < t; i++) {
		fscanf(input, "%d %d\n", &l[i][0], &l[i][1]);
	}
	sort(l.begin(), l.end());
	fscanf(input, "%d\n", &t);
	while (t--) {
		fscanf(input, "%d %d\n", &a, &b);
		fprintf(output, "%d\n", light(a, b, l));

	}
	fclose(input);   
	fclose(output);
}
int light(int a, int b, vector<vector<int> >l) {
	int max = 0, count = 0;
	int i;
	for (i = 0; i < l.size(); i++) {
		if (l[i][0] > b) break;
		if (l[i][0] <= a) {
			if (l[i][1] > max) max = l[i][1];
			if (max >= b) {
				count++;
				break;
			}
			//continue;
		}
		else {
			if (max == 0) break;
			count++;
			if (max >= b) break;
			else {
				if (l[i][0] > max) {
					count--;
					break;
				}
				a = max;
				i--;
			}
		}
		if (count == 0) {
			if (l[i][0] > a) break;
		}
	}
	if (max < b) count = 0;

	if (count == 0) return -1;
	return count;
}