#include<stdio.h>
#include<iostream>
using namespace std;
#include<vector>
#pragma warning (disable:4996)
int main() {
	FILE *input, *output;
	input = fopen("bowling.inp", "rt");
	output = fopen("bowling.out", "wt");
	
	int n, total;

	fscanf(input, "%d", &n);
	for (int i = 0; i < n; i++) {
		total = 0;
		vector<vector<int> > bowl(10, vector<int>(3));
		for (int x = 0; x < 10; x++) {//입력
			if (x == 9) {
				fscanf(input, "%d", &bowl[x][0]);
				fscanf(input, "%d", &bowl[x][1]);
				if (bowl[x][0] + bowl[x][1] > 9) {
					fscanf(input, "%d", &bowl[x][2]);
				}
			}
			else {
				fscanf(input, "%d", &bowl[x][0]);
				if (bowl[x][0] != 10) {
					fscanf(input, "%d", &bowl[x][1]);
				}
			}
		}
		for (int x = 0; x < 9; x++) {//9프레임까지
			if (bowl[x][0] != 10) {//strike x
				if (bowl[x][0] + bowl[x][1] != 10) {//spare x
					total += bowl[x][0] + bowl[x][1];
				}
				else {//spare
					total += bowl[x][0] + bowl[x][1] + bowl[x + 1][0];
				}
			}
			else {//strike
				if (x == 8) {
					total += bowl[x][0] + bowl[x + 1][0] + bowl[x + 1][1];
				}
				else {
					if (bowl[x + 1][0] == 10) {
						total += bowl[x][0] + bowl[x + 1][0] + bowl[x + 2][0];
					}
					else {
						total += bowl[x][0] + bowl[x + 1][0] + bowl[x + 1][1];
					}
				}
			}
		}
		//10프레임
		if (bowl[9][0] + bowl[9][1] > 9) {
			total += bowl[9][0] + bowl[9][1] + bowl[9][2];
		}
		else {
			total += bowl[9][0] + bowl[9][1];
		}
		fprintf(output, "%d\n", total);
	}



	fclose(input);
	fclose(output);
}