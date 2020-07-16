#include<stdio.h>
#include<iostream>
using namespace std;
#pragma warning (disable:4996)
#include<vector>
vector<char>cube1(6);
vector<char>cube2(6);
vector<char>part1(4);
vector<char>part2(4);
bool xcube();
int main() {
	FILE *input, *output;
	input = fopen("cube.inp", "rt");
	output = fopen("cube.out", "wt");

	int c;
	for (;;) {
		for (int i = 0; i < 12; i++) {
			if (i < 6) fscanf(input, "%c", &cube1[i]);
			else fscanf(input, "%c", &cube2[i - 6]);
		}
		fscanf(input, "%c", &c);
		int check = 0;
		for (int x = 1; x < 12; x++) {
			if (x < 6) {
				if (cube1[0] == cube1[x]) check++;
			}
			else {
				if (cube1[0] == cube2[x - 6]) check++;
			}
		}
		if (check == 11) {//같은 문자열 종료
			fprintf(output, "TRUE\n");
			break;
		}
		if (cube1[0] == cube2[0] && cube1[5] == cube2[5]) {//경우1
			part1[0] = cube1[1]; part1[1] = cube1[2];
			part1[2] = cube1[4]; part1[3] = cube1[3];
			part2[0] = cube2[1]; part2[1] = cube2[2];
			part2[2] = cube2[4]; part2[3] = cube2[3];
			if (xcube()) {
				fprintf(output, "TRUE\n");
				continue;
			}
		}
		if (cube1[0] == cube2[5] && cube1[5] == cube2[0]) {//경우2
			part1[0] = cube1[1]; part1[1] = cube1[2];
			part1[2] = cube1[4]; part1[3] = cube1[3];
			part2[0] = cube2[1]; part2[1] = cube2[3];
			part2[2] = cube2[4]; part2[3] = cube2[2];
			if (xcube()) {
				fprintf(output, "TRUE\n");
				continue;
			}
		}
		if (cube1[0] == cube2[1] && cube1[5] == cube2[4]) {//경우3
			part1[0] = cube1[1]; part1[1] = cube1[2];
			part1[2] = cube1[4]; part1[3] = cube1[3];
			part2[0] = cube2[3]; part2[1] = cube2[5];
			part2[2] = cube2[2]; part2[3] = cube2[0];
			if (xcube()) {
				fprintf(output, "TRUE\n");
				continue;
			}
		}
		if (cube1[0] == cube2[4] && cube1[5] == cube2[1]) {//경우4
			part1[0] = cube1[1]; part1[1] = cube1[2];
			part1[2] = cube1[4]; part1[3] = cube1[3];
			part2[0] = cube2[3]; part2[1] = cube2[0];
			part2[2] = cube2[2]; part2[3] = cube2[5];
			if (xcube()) {
				fprintf(output, "TRUE\n");
				continue;
			}
		}
		if (cube1[0] == cube2[2] && cube1[5] == cube2[3]) {//경우5
			part1[0] = cube1[1]; part1[1] = cube1[2];
			part1[2] = cube1[4]; part1[3] = cube1[3];
			part2[0] = cube2[1]; part2[1] = cube2[5];
			part2[2] = cube2[4]; part2[3] = cube2[0];
			if (xcube()) {
				fprintf(output, "TRUE\n");
				continue;
			}
		}
		if (cube1[0] == cube2[3] && cube1[5] == cube2[2]) {//경우6 고침
			part1[0] = cube1[1]; part1[1] = cube1[2];
			part1[2] = cube1[4]; part1[3] = cube1[3];
			part2[0] = cube2[1]; part2[1] = cube2[0];
			part2[2] = cube2[4]; part2[3] = cube2[5];
			if (xcube()) {
				fprintf(output, "TRUE\n");
				continue;
			}
		}
		fprintf(output, "FALSE\n");
		
	}
	fclose(input);
	fclose(output);
}
bool xcube() {
	for (int i = 0; i < 4; i++) {
		int num = 0;
		int sub;
		for (int j = 0; j < 4; j++) {
			if (j + i == 4) {
				sub = j;
				if (part1[j] == part2[j - sub]) num++;
			}
			else if (i + j > 4) {
				if (part1[j] == part2[j - sub]) num++;
			}
			else {
				if (part1[j] == part2[j + i]) num++;
			}

		}
		if (num == 4) return true;
	}
	return false;
}