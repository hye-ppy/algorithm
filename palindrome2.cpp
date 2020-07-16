#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
using namespace std;
#pragma warning (disable:4996)
int palindrome();
vector<char> pal;
int main() {
	FILE *input, *output;
	input = fopen("palindrome.inp", "rt");
	output = fopen("palindrome.out", "wt");

	int t, result;
	char c;
	string str;
	fscanf(input, "%d", &t);
	fscanf(input, "%c", &c);
	for (int i = 0; i < t; i++) {
		for (;;) {
			fscanf(input, "%c", &c);
			if (c == '\n') break;
			pal.push_back(c);
		}
		result = palindrome();
		fprintf(output,"%d\n", result);
		pal.clear();
	}



	fclose(input);
	fclose(output);
}
int palindrome() {
	int num = 0;
	int len = pal.size();
	vector<char>::iterator iter = pal.begin();
	vector<char>::iterator iter1 = pal.end() - 1;
	for (int x = 0; x < pal.size() / 2; x++) {
		if (num>2) return -1;
		len = pal.size();
		if (pal[x] != pal[len - 1 - x]) {
			if (num==2) return -1;
			if (len % 2 == 0 && x == (len / 2) - 1) {
				num++;
			}
			else if (pal[x] == pal[len - 1 - x - 1] && pal[x + 1] == pal[len - 1 - x - 2]) {
				num++;
				pal.insert(iter, pal[len - 1 - x]);
			}
			else if (pal[x + 1] == pal[len - 1 - x] && pal[x + 2] == pal[len - 1 - x - 1]) {//안됭
				num++;
				pal.insert(iter1 + 1, pal[x]);
			}
			else if (pal[x + 2] == pal[len - 1 - x]) {
				pal.erase(iter, iter + 2);
				num += 2;
			}
			else if (pal[x] == pal[len - 1 - x - 2]) {
				pal.erase(iter1 - 1, iter1+1);
				num += 2;
			}
			else if (pal[x + 2] == pal[len - 1 - x - 2]) {
				//pal.erase(iter, iter + 2);
				//pal.erase(iter1 - 2, iter1);
				x += 2;
				num += 2;
			}
			else {//추가 안되는 경우
				return -1;
			}
		}
		vector<char>::iterator iter = pal.begin() + x + 1;
		vector<char>::iterator iter1 = pal.end() - 1 - x - 1;
		//iter++;
		//iter1--;
	}
	if (num == 0) return 0;
	else if (num == 1)return 1;
	else if (num == 2)return 2;
	else return -1;
}