#include<stdio.h>
#include<iostream>
using namespace std;
#include<vector>
#pragma warning (disable:4996)
vector<int> pre;
vector<int> in;
vector<int> post;
void postorder(int begin, int end, FILE *output);
void preorder(int begin, int end, FILE *output);
int point = 0;
int main() {
	FILE *input, *output;
	input = fopen("tree.inp", "rt");
	output = fopen("tree.out", "wt");

	int n;
	int a;
	fscanf(input, "%d", &n);
	vector<int> check(3);
	for (int i = 0; i < 2; i++) {
		fscanf(input, "%d", &a);
		if (a == -1) {
			check[0] = 1;
			for (int x = 0; x < n; x++) {
				fscanf(input, "%d", &a);
				pre.push_back(a);
			}
		}
		else if (a == 0) {
			check[1] = 1;
			for (int x = 0; x < n; x++) {
				fscanf(input, "%d", &a);
				in.push_back(a);
			}
		}
		else {
			check[2] = 1;
			for (int x = 0; x < n; x++) {
				fscanf(input, "%d", &a);
				post.push_back(a);
			}
		}
	}
	if (check[2] == 0) {
		postorder(0, n - 1, output);
	}
	else  if (check[0] == 0) {
		point = n - 1;
		preorder(0, n - 1, output);
		for (int i = pre.size() - 1; i > -1; i--) {
			fprintf(output, "%d\n", pre[i]);
		}
	}
	


	fclose(input);
	fclose(output);
}
void postorder(int begin, int end, FILE *output) {
	int i = 0;
	for (i = begin; i < end; i++) {
		if (pre[point] == in[i]) break;
	}
	point++;
	//L
	if (i != begin) {
		postorder(begin, i - 1, output);
	}
	//R
	if (i != end) {
		postorder(i + 1, end, output);
	}
	//D
	fprintf(output, "%d\n", in[i]);

}
void preorder(int begin, int end, FILE *output) {
	int i = 0;
	for (i = begin; i < end; i++) {
		if (post[point] == in[i]) break;
	}
	point--;
	//R
	if (i != end) {
		preorder(i + 1, end, output);
	}
	//L
	if (i != begin) {
		preorder(begin, i - 1, output);
	}
	//D
	pre.push_back(in[i]);

}