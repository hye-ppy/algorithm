#include<stdio.h>
#pragma warning (disable:4996)
using namespace std;
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>
#include<functional>
#define p pair<int,int>

pair<int, int> p1[10000];
pair<int, int> select[10000];
int sum = 0;
void prim(int n, int vertex, vector<vector<int> > &weight, vector<vector<int> > &num, FILE *output);
void prim1(int n, int vertex, vector<vector<int> > &weight, vector<vector<int> > &num, FILE *output);
int main() {
	FILE *input = fopen("mst.inp", "rt");
	FILE *output = fopen("mst.out", "wt");

	int n, m, count = 0;
	fscanf(input, "%d %d", &n, &m);
	vector<vector<int> >weight(n, vector<int>(n));
	vector<vector<int> >num(n, vector<int>(n));

	int u, v, w;
	while (m--) {
		fscanf(input, "%d %d %d", &u, &v, &w);
		weight[u][v] = w;
		weight[v][u] = w;
		num[v][u] = count;
		num[u][v] = count++;
	}
	prim(n, 0, weight, num, output);
	prim1(n, n / 2, weight, num, output);
	prim1(n, n - 1, weight, num, output);


	fclose(input);
	fclose(output);
}
void prim(int n, int vertex, vector<vector<int> > &weight, vector<vector<int> > &num, FILE *output) {
	vector<int>nearest(n);
	vector<int>distance(n);
	queue<int>seq;
	//초기화
	for (int i = 0; i < n; i++) {
		if (i == vertex) continue;
		nearest[i] = vertex;
		distance[i] = weight[vertex][i];
	}
	if (vertex != 0) {
		fprintf(output, "Tree edges by Prim algorithm with starting vertex %d: %d\n", vertex, sum);
	}
	//남은 정점 수만큼 만
	int min, vnear, edge;
	int x = 0;
	for (int i = 0; i < n - 1; i++) {
		int check = 0;
		//가장작은거 찾기
		for (int i = 0; i < n; i++) {
			if (i == vertex || distance[i] < 1) continue;
			if (check == 0) {
				min = distance[i];
				vnear = i;
				check = 1;
				continue;
			}
			if (distance[i] <= min) {
				if (distance[i] == min && num[nearest[vnear]][vnear] < num[nearest[i]][i]) continue;
				min = distance[i];
				vnear = i;
			}
		}
		//super node
		if (vertex != 0) {
			fprintf(output, "%d\n", num[nearest[vnear]][vnear]);
		}
		if (vertex == 0) {
			edge = num[nearest[vnear]][vnear];
			select[x].first = nearest[vnear];
			select[x].second = vnear;
			seq.push(edge);
			p1[x].first = distance[vnear];
			p1[x++].second = edge;
			sum += min;
		}
		distance[vnear] = -1;
		//갱신
		for (int i = 0; i < n; i++) {
			if (i == vertex || distance[i] == -1) continue;
			if (weight[vnear][i] != 0 && (weight[vnear][i] <= distance[i] || distance[i] == 0)) {
				if (weight[vnear][i] == distance[i] && num[vnear][i] > num[nearest[i]][i]) continue;
				distance[i] = weight[vnear][i];
				nearest[i] = vnear;
			}
			/*else if (weight[vnear][i] != 0 && weight[vnear][i] == distance[i]) {
			if (num[vnear][i] < num[nearest[i]][i]) {
			distance[i] = weight[vnear][i];
			nearest[i] = vnear;
			}
			}*/
		}
	}
	//
	if (vertex == 0) {
		sort(p1, p1 + n - 1);
		fprintf(output, "Tree edges by Kruskal algorithm: %d\n", sum);
		for (int i = 0; i < n - 1; i++) {
			fprintf(output, "%d\n", p1[i].second);
		}

		//
		fprintf(output, "Tree edges by Prim algorithm with starting vertex %d: %d\n", vertex, sum);
		for (int i = 0; i < n - 1; i++) {
			fprintf(output, "%d\n", seq.front());
			seq.pop();
		}
	}
	//sort(select, select + n - 1);
}
void prim1(int n, int vertex, vector<vector<int> > &weight, vector<vector<int> > &num, FILE *output) {
	fprintf(output, "Tree edges by Prim algorithm with starting vertex %d: %d\n", vertex, sum);

	priority_queue<p, vector<p>, greater<p> > dist;
	//queue<p> dist[10000];
	//pair<int, int> dist[10000];
	int x = n - 1;
	vector<int>dp(n - 1);
	int c = 0;
	while (x--) {
		for (int i = 0; i < n - 1; i++) {
			if (dp[i] == 0 && (select[i].first == vertex || select[i].second == vertex)) {
				dist.push(p(weight[select[i].first][select[i].second], num[select[i].first][select[i].second]));
				dp[i] = 1;
			}
		}
		fprintf(output, "%d\n", dist.top().second);
		for (int i = 0; i < n - 1; i++) {
			if (dp[i] == 1) {
				if (dist.top().first == weight[select[i].first][select[i].second] && dist.top().second == num[select[i].first][select[i].second]) {
					if (vertex == select[i].first) vertex = select[i].second;
					else vertex = select[i].first;
					dp[i] = -1;
					break;
				}
			}
		}
		dist.pop();
	}	
}