#include<stdio.h>
#include<iostream>
using namespace std;
#pragma warning (disable:4996)
#include<vector>
void check(int i, int j, int k, int color);
vector<vector<int> >go(19, vector<int>(19));
vector<vector<int> >ok(19, vector<int>(19));
int main(){
	FILE *input = fopen("go.inp", "rt");
	FILE *output = fopen("go.out", "wt");
	int k;
	char c;
	fscanf(input, "%d", &k);
	for (int i = 0; i < k; i++) {
		fscanf(input, "%c", &c);
		for (int j = 0; j < k; j++) {
			fscanf(input, "%c", &c);
			if (c == '.') continue;
			go[i][j] = c;
		}
	}
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			//바둑알이면 패스
			if (go[i][j] == 66 || go[i][j] == 87) continue;
			//빈곳 집 색 찾기
			if (ok[i][j] == 0) {
				if (i != 0) {
					if (go[i - 1][j] == 66 || go[i - 1][j] == 87) {
						check(i, j, k, go[i - 1][j]);
						continue;
					}
					else if (go[i - 1][j] == 3) {
						go[i][j] = 3;
						continue;
					}
				}
				if (i != k - 1) {
					if (go[i + 1][j] == 66 || go[i + 1][j] == 87) { 
						check(i, j, k, go[i + 1][j]); 
						continue;
					}
					else if (go[i + 1][j] == 3) {
						go[i][j] = 3;
						continue;
					}
				}
				if (j != 0) {
					if (go[i][j - 1] == 66 || go[i][j - 1] == 87) {
						check(i, j, k, go[i][j - 1]);
						continue;
					}
					else if (go[i][j - 1] == 3) {
						go[i][j] = 3;
						continue;
					}
				}
				if (j != k - 1) {
					if (go[i][j + 1] == 66 || go[i][j + 1] == 87) { 
						check(i, j, k, go[i][j + 1]); 
						continue;
					}
					else if (go[i][j + 1] == 3) {
						go[i][j] = 3;
						continue;
					}
				}
			}
		}
	}
	int b = 0, w = 0;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			if (go[i][j] == 1) b++;
			else if (go[i][j] == 2)w++;
		}
	}
	fprintf(output, "%d %d", b, w);


	fclose(input);
	fclose(output);

}
void check(int i, int j, int k, int color) {
	ok[i][j] = 1;
	if (i != 0) {//up
		if (go[i - 1][j] == 66 || go[i - 1][j] == 87) {
			if (go[i - 1][j] != color) {
				go[i][j] = 3;
				return;
			}
		}
		else if (go[i - 1][j] == 3) {
			go[i][j] = 3;
			return;
		}
		else if (ok[i - 1][j] == 0) {
			check(i - 1, j, k, color);
			if (go[i - 1][j] == 3) {
				go[i][j] = 3;
				return;
			}
		}
	}
	if (j != k - 1) {//right
		if (go[i][j + 1] == 66 || go[i][j + 1] == 87) {
			if (go[i][j + 1] != color) {
				go[i][j] = 3;
				return;
			}
		}
		else if (go[i][j + 1] == 3) {
			go[i][j] = 3;
			return;
		}
		else if (ok[i][j + 1] == 0) {
			check(i, j + 1, k, color);
			if (go[i][j + 1] == 3) {
				go[i][j] = 3;
				if (i != 0 && (go[i - 1][j] == 1 || go[i - 1][j] == 2)) go[i - 1][j] = 3;
				return;
			}
		}
	}
	if (i != k - 1) {//down
		if (go[i + 1][j] == 66 || go[i + 1][j] == 87) {
			if (go[i + 1][j] != color) {
				go[i][j] = 3;
				return;
			}
		}
		else if (go[i + 1][j] == 3) {
			go[i][j] = 3;
			return;
		}
		else if (ok[i + 1][j] == 0) {
			check(i + 1, j, k, color);
			if (go[i + 1][j] == 3) {
				go[i][j] = 3;
				if (i != 0 && (go[i - 1][j] == 1 || go[i - 1][j] == 2)) go[i - 1][j] = 3;
				if (j != k - 1 && (go[i][j + 1] == 1 || go[i][j + 1] == 2)) go[i][j + 1] = 3;
				return;
			}
		}
	}
	if (j != 0) {//left
		if (go[i][j - 1] == 66 || go[i][j - 1] == 87) {
			if (go[i][j - 1] != color) {
				go[i][j] = 3;
				return;
			}
		}
		else if (go[i][j - 1] == 3) {
			go[i][j] = 3;
			return;
		}
		else if (ok[i][j - 1] == 0) {
			check(i, j - 1, k, color);
			if (go[i][j - 1] == 3) {
				go[i][j] = 3;
				if (i != 0 && (go[i - 1][j] == 1 || go[i - 1][j] == 2)) go[i - 1][j] = 3;
				if (j != k - 1 && (go[i][j + 1] == 1 || go[i][j + 1] == 2)) go[i][j + 1] = 3;
				if (i != k - 1 && (go[i + 1][j] == 1 || go[i + 1][j] == 2)) go[i + 1][j] = 3;

				return;
			}
		}
	}
	if (color == 66) go[i][j] = 1;
	else go[i][j] = 2;
}