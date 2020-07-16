#include<stdio.h>
#include<algorithm>
#include<utility>
#include<functional>
#include<vector>
#include<queue>
#include<math.h>
#pragma warning (disable:4996)
using namespace std;

#define p pair<int,int> 
const int inf = 1e9;
int n, m, h;
int num[1050][1050];
vector<p>e[1000500];
int water[1000500];
priority_queue < p, vector<p>, greater<p>> pq;
int a[100][100], b[100][100], c[100][100];
int sum = 0;

void edge(int a, int b, int w);
int watertank(int x, int y);

int main() {
	FILE *input = fopen("watertank.inp", "rt");
	FILE *output = fopen("watertank.out", "wt");
	
	int t, aa;
	fscanf(input, "%d", &t);
	while (t--) {
		fscanf(input, "%d %d %d", &n, &m, &h);
		
		for (int i = 0; i <100; i++) {
			for (int j = 1; j <100; j++) {
				a[i][j] = -1;
			}
		}
		for (int i = 0; i < n + 2; i++) {
			for (int j = 1; j < m + 2; j++) {
				c[i][j] = 0;
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m + 1; j++) {
				c[i][j] = h;
			}
		}
		for (int i = 0; i < n + 1; i++) {
			for (int j = 1; j < m; j++) {
				fscanf(input, "%d", &a[i][j]);
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 1; j < m + 1; j++) {
				fscanf(input, "%d", &b[i][j]);
			}
		}
		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < m + 1; j++) {
				int ff=watertank(i, j);
			}
		}
		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < m + 1; j++) {
				sum += c[i][j];
			}
		}
		fprintf(output, "%d", sum);
		/*
		int count = 0;
		for (int i = 0; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				num[i][j] = ++count;
			}
		}
		for (int i = 0; i <= n + 1; i++) {
			for (int j = 1; j <= m; j++) {
				fscanf(input, "%d", &a);
				if (a != -1) {
					edge(num[i][j], num[i - 1][j], a);
				}
			}
		}
		for (int i = 0; i <= n; i++) {
			for (int j = 1; j <= m + 1; j++) {
				fscanf(input, "%d", &a);
				if (a != -1) {
					edge(num[i][j], num[i][j - 1], a);
				}
			}
		}
		for (int i = 0; i <= n * m; i++) {
			water[i] = h;
		}*/
		//watertank(output);

	}
	


	fclose(input);
	fclose(output);

}
int watertank(int x, int y) {
	/*water[0] = 0;
	pq.push(p(0, 0));

	while (!pq.empty()) {
		int h = pq.top().first;
		int tank = pq.top().second;
		pq.pop();
		

	}*/
	int waterHigh;
	//printf("tank(%d, %d, %d)\n", x, y);

	if (c[x][y] != h)
		return c[x][y];

	if (a[x - 1][y - 1] != -1 && a[x - 1][y - 1] < c[x][y])
	{
		waterHigh = watertank(x - 1, y);
		if (a[x - 1][y - 1] >= waterHigh)
			waterHigh = a[x - 1][y - 1];
		c[x][y] = waterHigh;
	}

	if (b[x - 1][y] != -1 && b[x - 1][y] < c[x][y])
	{
		waterHigh = watertank(x, y + 1);
		if (b[x - 1][y] >= waterHigh)
			waterHigh = b[x - 1][y];
		c[x][y] = waterHigh;
	}

	if (a[x][y - 1] != -1 && a[x][y - 1] < c[x][y])
	{
		waterHigh = watertank(x + 1, y);
		if (a[x][y - 1] >= waterHigh)
			waterHigh = a[x][y - 1];
		c[x][y] = waterHigh;
	}

	if (b[x - 1][y - 1] != -1 && b[x - 1][y - 1] < c[x][y])
	{
		waterHigh = watertank(x, y - 1);
		if (b[x - 1][y - 1] >= waterHigh)
			waterHigh = b[x - 1][y - 1];
		c[x][y] = waterHigh;
	}

	return c[x][y];
}
void edge(int a, int b, int w) {
	e[a].push_back(p( b,w ));
	e[b].push_back(p( a,w ));
}