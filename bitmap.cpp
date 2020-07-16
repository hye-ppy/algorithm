#include<stdio.h>
#include<iostream>
#pragma warning (disable:4996)
using namespace std;
#include<vector>
void bm(int b_row, int b_column, int e_row, int e_column);
vector<vector<int> >arr(100);
int main() {
	FILE *input = fopen("bitmap.inp", "rt");
	FILE *output = fopen("bitmap.out", "wt");
	char c, t;
	int m, n;
	for (;;) {
		fscanf(input, "%c %d %d", &c, &m, &n);
		if (c == '#') break;
		fscanf(input, "%c", &t);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				fscanf(input, "%c", &t);
				arr[i].push_back(t - 48);
			}
		}
		fscanf(input, "%c", &t);//\n
		if (c == 'B') {
			bm(0, 0, m - 1, n - 1);
		}
	}



	fclose(input);
	fclose(output);
}
void bm(int b_row,int b_column,int e_row,int e_column) {
	bool check = true;
	for (int i = b_row; i <= e_row; i++) {
		for (int j = b_column; j <= e_column; j++) {
			if (arr[b_row][b_column] != arr[i][j]) {
				check = false;
				break;
			}
		}
		if (!check) break;
	}
	if (check) {
		printf("%d", arr[b_row][b_column]);
		return;
	}
	printf("D");
	
	int mid_row = (e_row - b_row + 1) / 2;
	//if (e_row - b_row + 1 != 1 && (e_row - b_row + 1) % 2 != 0) mid_row++;
	if ( (e_row - b_row + 1) % 2 != 0) mid_row++;
	int mid_column = (e_column - b_column + 1) / 2;
	if ((e_column - b_column + 1) % 2 != 0) mid_column++;
	//if (e_column - b_column + 1 != 1 && (e_column - b_column + 1) % 2 != 0) mid_column++;
	bm(b_row, b_column, b_row + mid_row - 1, b_column + mid_column - 1);
	bm(b_row, b_column + mid_column, b_row + mid_row - 1, e_column);
	bm(b_row + mid_row, b_column, e_row, b_column + mid_column - 1);
	bm(b_row + mid_row, b_column + mid_column, e_row, e_column);
	/*
	bm(b_row, b_column, (e_row - b_row) / 2, (e_column - b_column) / 2);
	bm(b_row, ((e_column - b_column) / 2) + 1, (e_row - b_row) / 2, e_column);
	bm(((e_row - b_row) / 2) + 1, b_column, e_row, (e_column - b_column) / 2);
	bm(((e_row - b_row) / 2) + 1, ((e_column - b_column) / 2) + 1, b_row, e_column);*/

}