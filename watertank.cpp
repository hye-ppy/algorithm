#include<stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <functional>
#pragma warning (disable:4996)
using namespace std;
#define P pair<int, int>
vector < vector < vector<int> > > a;
vector < vector < vector<int> > > b;
int watertank(int n, int m, int h);
int main() {
	FILE *input = fopen("watertank.inp", "rt");
	FILE *output = fopen("watertank.out", "wt");
	int t, x;
	fscanf(input, "%d", &t);
	while (t--) {
		int n, m, h;
		fscanf(input, "%d %d %d", &n, &m, &h);
		a.assign(n + 1, vector < vector <int> >(m + 1, vector <int>(2, -1)));
		b.assign(n + 1, vector < vector <int> >(m + 1, vector <int>(2, -1)));

		for (int i = 0; i < n + 1; i++) {
			for (int j = 0; j < m; j++) {
				fscanf(input, "%d", &x);
				if (i > 0) a[i - 1][j][1] = x;
				if (i < n) a[i][j][0] = x;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j<m + 1; j++) {
				fscanf(input, "%d", &x);
				if (j > 0) b[i][j - 1][1] = x;
				if (j < m) b[i][j][0] = x;
			}
		}		
		fprintf(output, "%d\n", watertank(n, m, h));
	}

	
	fclose(input);
	fclose(output);
}
int watertank(int n, int m, int h) {
	vector<vector<int> >dist(n + 1, vector<int>(m + 1));
	vector<vector<bool> >visited(n + 1, vector<bool>(m + 1, false));
	priority_queue<P, vector<P>, greater<P> > PQ;
	int arr[4] = { -1, 1, 0, 0 };
	int nr, nc;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dist[i][j] = h;
			for (int k = 0; k < 2; k++) {
				nr = i + arr[k];
				nc = j + arr[k + 2];
				if (a[i][j][k] >= 0 && (nr < 0 || nr >= n || nc < 0 || nc >= m)) {
					dist[i][j] = min(a[i][j][k], dist[i][j]);
					PQ.push(P(dist[i][j], i * 1000 + j));
				}
			}
			for (int k = 0; k < 2; k++) {
				nr = i + arr[k + 2];
				nc = j + arr[k];
				if (b[i][j][k] >= 0 && (nr < 0 || nr >= n || nc < 0 || nc >= m)) {
					dist[i][j] = min(b[i][j][k], dist[i][j]);
					PQ.push(P(dist[i][j], i * 1000 + j));
				}
			}
		}
	}
	while (!PQ.empty()) {
		int r, c;
		r = PQ.top().second / 1000, c = PQ.top().second % 1000;
		PQ.pop();
		while (!PQ.empty() && visited[r][c]) {
			r = PQ.top().second / 1000, c = PQ.top().second % 1000;
			PQ.pop();
		}
		if (!visited[r][c]) visited[r][c] = true;
		else break;
		for (int k = 0; k < 2; k++) {
			nr = r + arr[k];
			nc = c + arr[k + 2];
			if (a[r][c][k] < 0 || nr < 0 || nr >= n || nc < 0 || nc >= m || visited[nr][nc]) continue;
			int nd = max(dist[r][c], a[r][c][k]);
			if (nd < dist[nr][nc]) {
				dist[nr][nc] = nd;
				PQ.push(P(dist[nr][nc], nr * 1000 + nc));
			}
		}
		for (int k = 0; k < 2; k++) {
			nr = r + arr[k + 2];
			nc = c + arr[k];
			if (b[r][c][k] < 0 || nr < 0 || nr >= n || nc < 0 || nc >= m || visited[nr][nc]) continue;
			int nd = max(dist[r][c], b[r][c][k]);
			if (nd < dist[nr][nc]) {
				dist[nr][nc] = nd;
				PQ.push(P(dist[nr][nc], nr * 1000 + nc));
			}
		}
	}
	int result = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			result += dist[i][j];
		}
	}
	return result;
}