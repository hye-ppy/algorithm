#include<stdio.h>
#include<iostream>
using namespace std;
#pragma warning (disable:4996)
#include<vector>
#include<algorithm>
int main() {
	FILE *input, *output;
	input = fopen("paper.inp", "rt");
	output = fopen("paper.out", "wt");

	vector<vector<int> >check(4000, vector<int>(4000));
	int n;
	int x, y, w, h;
	fscanf(input, "%d", &n);
	vector<vector<int> >paper(n + 1, vector<int>(4));
	vector<int>xmem;//x축에 숫자들
	vector<int>ymem;
	
	for (int p = 1; p <= n; p++) {
		fscanf(input, "%d %d %d %d", &x, &y, &w, &h);
		paper[p][0] = x; paper[p][1] = y;
		paper[p][2] = x + w; paper[p][3] = y + h;
		xmem.push_back(x); xmem.push_back(x + w);
		ymem.push_back(y); ymem.push_back(y + h);
	}
	//정리
	sort(xmem.begin(), xmem.end());
	sort(ymem.begin(), ymem.end());
	xmem.erase(unique(xmem.begin(), xmem.end()), xmem.end());//중복제거
	ymem.erase(unique(ymem.begin(), ymem.end()), ymem.end());
	
	for (int p = 1; p <= n; p++) {
		for (int q = 0; q < xmem.size(); q++) {
			if (paper[p][0] == xmem[q]) {
				paper[p][0] = q;
			}
			if (paper[p][2] == xmem[q]) {
				paper[p][2] = q;
				break;
			}
		}
		for (int q = 0; q < ymem.size(); q++) {
			if (paper[p][1] == ymem[q]) {
				paper[p][1] = q;
			}
			if (paper[p][3] == ymem[q]) {
				paper[p][3] = q;
				break;
			}
		}
		for (int i = paper[p][0] + 1; i <= paper[p][2]; i++) {
			for (int j = paper[p][1] + 1; j <= paper[p][3]; j++) {
				check[i][j] = p;
			}
		}
	}

	//결과
	int full = 0, xfull = 0, part = 0;
	for (int p = 1; p <= n; p++) {
		int num = 0;
		for (int i = paper[p][0] + 1; i <= paper[p][2]; i++) {
			for (int j = paper[p][1] + 1; j <= paper[p][3]; j++) {
				if (check[i][j] == p) num++;
				else num--;
			}
		}
		if (num == (paper[p][2] - paper[p][0]) * (paper[p][3] - paper[p][1])) {
			full++;
		}
		else if (-num == (paper[p][2] - paper[p][0]) * (paper[p][3] - paper[p][1])) {
			xfull++;
		}
		else{
			part++;
		}
	}
	fprintf(output, "%d %d %d", xfull, part, full);
	

	fclose(input);
	fclose(output);
}