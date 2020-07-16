#include<stdio.h> 
#include<conio.h> 
#include<vector>
#include<utility>
using namespace std;
#pragma warning (disable:4996)
#define P pair<int, int>
vector<vector<int> >puzzle(9, vector<int>(9, 0));
vector<vector<int> >puzzle2(9, vector<int>(9, 0));
vector<P> a;
vector<P> b;
vector<P> c;
vector<P> d;
vector<P> e;
vector<P> f;
vector<P> g;
vector<P> h;
vector<P> ii;
void Display(vector<vector<int> >puzzle, int level)
{
	int t;
	int i, j;
	printf("\n");
	for (t = 0; t<level; t++)printf(" ");
	printf("+-----+-----+-----+\n");
	for (i = 1; i<10; ++i)
	{
		for (t = 0; t<level; t++)printf(" ");
		for (j = 1; j<10; ++j) printf("|%d", puzzle[i - 1][j - 1]);
		printf("|\n");

		if (i % 3 == 0) {
			for (t = 0; t<level; t++)printf(" ");
			printf("+-----+-----+-----+\n");
		}
	}
}

int isAvailable(vector<vector<int> >puzzle, int row, int col, int num)
// row ,col �� �ش� ���ڸ� ���� �� �ִ��� �˻��ϴ� �Լ� 
{
	//int rowStart = (row / 3) * 3;
	//int colStart = (col / 3) * 3;
	int i;
	for (i = 0; i<9; ++i)
	{
		if (puzzle[row][i] == num) return 0;
		// ���� �࿡ ���ڰ� ������ �̿밡��(Available) ���� ���� 
		if (puzzle[i][col] == num) return 0;
		// ���� ���� ���ڰ� ������ �̿밡��(Available) ���� ���� 
		//if (puzzle[rowStart + (i % 3)][colStart + (i / 3)] == num) return 0;
		// 3x3 ĭ�� ���ڰ� ������ �̿밡��(Available) ���� ���� 
	} // for i 
	if (puzzle2[row][col] == 97) {
		for (int i = 0; i < 9; i++) {
			if (puzzle[a[i].first][a[i].second] == num) return 0;
		}
	}
	else if (puzzle2[row][col] == 98) {
		for (int i = 0; i < 9; i++) {
			if (puzzle[b[i].first][b[i].second] == num) return 0;
		}
	}
	else if (puzzle2[row][col] == 99) {
		for (int i = 0; i < 9; i++) {
			if (puzzle[c[i].first][c[i].second] == num) return 0;
		}
	}
	else if (puzzle2[row][col] == 100) {
		for (int i = 0; i < 9; i++) {
			if (puzzle[d[i].first][d[i].second] == num) return 0;
		}
	}
	else if (puzzle2[row][col] == 101) {
		for (int i = 0; i < 9; i++) {
			if (puzzle[e[i].first][e[i].second] == num) return 0;
		}
	}
	else if (puzzle2[row][col] == 102) {
		for (int i = 0; i < 9; i++) {
			if (puzzle[f[i].first][f[i].second] == num) return 0;
		}
	}
	else if (puzzle2[row][col] == 103) {
		for (int i = 0; i < 9; i++) {
			if (puzzle[g[i].first][g[i].second] == num) return 0;
		}
	}
	else if (puzzle2[row][col] == 104) {
		for (int i = 0; i < 9; i++) {
			if (puzzle[h[i].first][h[i].second] == num) return 0;
		}
	}
	else {
		for (int i = 0; i < 9; i++) {
			if (puzzle[ii[i].first][ii[i].second] == num) return 0;
		}
	}

	return 1; // ���� ���ڰ� ���ٸ� ���ڸ� ���� �� ����  
}

int fillSudoku(vector<vector<int> >puzzle, int row, int col, int level)
{
	int i;
	printf("------------------ row %d col %d\n", row, col);
	//Display(puzzle, level);
	//getch();

	if (row<9 && col<9)
	{
		if (puzzle[row][col] != 0)
			// �ش� ��,�� �� ���ڰ� ä����������  
		{
			if ((col + 1)<9) return fillSudoku(puzzle, row, col + 1, level + 1);
			// ���� ���� ���ڸ� ä�쵵�� �Լ� ȣ��  
			else if ((row + 1)<9) return fillSudoku(puzzle, row + 1, 0, level + 1);  
			//���� �� ùĭ�� ���ڸ� ä�쵵�� �Լ� ȣ��
			else return 1;
		} // if

		else
		{
			for (i = 0; i<9; ++i)
			{
				if (isAvailable(puzzle, row, col, i + 1))
					// ����(i+1)�� �ִ� ���� ���� �ϴٸ� 
				{
					puzzle[row][col] = i + 1; // ���ڸ� �ְ�  
					if ((col + 1)<9)  // ���� ������ �Ȱ��ٸ�  
					{
						if (fillSudoku(puzzle, row, col + 1, level + 1)) return 1;
						// ���� ���� ���ڸ� �ִ°� �����ϸ� ������ ����  
						else puzzle[row][col] = 0;
						// �׷��� ������ �׼��ڸ� 0�����Ͽ� ���� 
					} // if 
					else if ((row + 1)<9)  // ���� ������ �ʰ��ٸ�  
					{
						if (fillSudoku(puzzle, row + 1, 0, level + 1)) return 1;
						// ���� �� ùĭ�� ���ڸ� �ִ°� �����ϸ� ������ ���� 
						else puzzle[row][col] = 0;
						// �׷��� ������ �׼��ڸ� 0�����Ͽ� ���� 
					} // else if
					else return 1; // �࿭�� ������ ���ٸ� ������ ����   
				} // if
			} // for i
		} // else 

		return 0;
	} // if 
	else return 1;
}

int main(){
	FILE *input = fopen("sudoku.inp", "rt");
	FILE *output = fopen("sudoku.out", "wt");
	
	for (int k = 0; k < 9; k++) {
		for (int j = 0; j < 9; j++) {
			fscanf(input, "%d", &puzzle[k][j]);
		}
	}
	char kk;
	fscanf(input, "%c", &kk);
	fscanf(input, "%c", &kk);
	for (int k = 0; k < 9; k++) {
		for (int j = 0; j < 9; j++) {
			fscanf(input, "%c ", &kk);
			puzzle2[k][j] = kk;
			if (kk == 97) a.push_back(P(k, j));
			else if (kk == 98) b.push_back(P(k, j));
			else if (kk == 99) c.push_back(P(k, j));
			else if (kk == 100) d.push_back(P(k, j));
			else if (kk == 101) e.push_back(P(k, j));
			else if (kk == 102) f.push_back(P(k, j));
			else if (kk == 103) g.push_back(P(k, j));
			else if (kk == 104) h.push_back(P(k, j));
			else ii.push_back(P(k, j));
		}
	}
	int level = 1;
	if (fillSudoku(puzzle, 0, 0, level))
	{
		Display(puzzle, level);
	} // if

	else printf("\n\nNO SOLUTION\n\n");
	/*
	int level = 1;

	int puzzle[9][9] = { { 0, 0, 0, 0, 0, 0, 0, 9, 0 },
	{ 1, 9, 0, 4, 7, 0, 6, 0, 8 },
	{ 0, 5, 2, 8, 1, 9, 4, 0, 7 },
	{ 2, 0, 0, 0, 4, 8, 0, 0, 0 },
	{ 0, 0, 9, 0, 0, 0, 5, 0, 0 },
	{ 0, 0, 0, 7, 5, 0, 0, 0, 9 },
	{ 9, 0, 7, 3, 6, 4, 1, 8, 0 },
	{ 5, 0, 6, 0, 8, 1, 0, 7, 4 },
	{ 0, 8, 0, 0, 0, 0, 0, 0, 0 } };

	if (fillSudoku(puzzle, 0, 1, level))
	{
		Display(puzzle, level);
	} // if

	else printf("\n\nNO SOLUTION\n\n");
	return 0;
	*/
	fclose(input);
	fclose(output);
}
