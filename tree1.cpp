#include<stdio.h>
#include<iostream>
using namespace std;
#pragma warning (disable:4996)
#include<stack>
#include<string>
#include<vector>
int main() {
	FILE *input, *output;
	input = fopen("tree.inp", "rt");
	output = fopen("tree.out", "wt");

	int n;
	int t;
	char str;
	fscanf(input, "%d", &n);
	fscanf(input, "%c", &str);
	for (int i = 0; i < n; i++) {
		vector<char> tree;
		vector<int>tree1;
		stack<int> stack;
		for (;;) {
			fscanf(input, "%c", &str);
			fprintf(output, "%c", str);
			if (str == ' ') continue;
			if (str == '\n') break;
			if (str >= 65 && str <= 90) {
				tree.push_back(str);
				fscanf(input, "%d", &t);
				fprintf(output, "%d", t);
				tree1.push_back(t);
			}
			else tree.push_back(str);

		}
		int num = 0;
		int y = 0;
		fprintf(output, "Preorder\n");
		for (int x = 0; x < tree.size(); x++) {
			if (tree[x] == '(') {
				fprintf(output, "r%d\n", num);
				num++;
			}
			else if (tree[x] == ')') continue;
			else {
				fprintf(output, "%c%d\n", tree[x], tree1[y]);
				y++;
			}
		}
		y = 0;
		int num1 = 0;
		int check = 0;
		fprintf(output, "Inorder\n");
		for (int x = 0; x < tree.size(); x++) {
			if (tree[x] == '(') {
				stack.push(num1);
				num1++;
			}
			else if (tree[x] == ')') continue;
			else {
				if (check == num1) {
					fprintf(output, "%c%d\n", tree[x], tree1[y]);
					y++;
				}
				else {
					check++;
					fprintf(output, "%c%d\n", tree[x], tree1[y]);
					y++;
					fprintf(output, "r%d\n", stack.top());
					stack.pop();
				}
				
			}
		}
	}

	fclose(input);
	fclose(output);

}