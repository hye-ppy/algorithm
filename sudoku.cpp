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
// row ,col 에 해당 숫자를 넣을 수 있는지 검사하는 함수 
{
	//int rowStart = (row / 3) * 3;
	//int colStart = (col / 3) * 3;
	int i;
	for (i = 0; i<9; ++i)
	{
		if (puzzle[row][i] == num) return 0;
		// 같은 행에 숫자가 있으면 이용가능(Available) 하지 않음 
		if (puzzle[i][col] == num) return 0;
		// 같은 열에 숫자가 있으면 이용가능(Available) 하지 않음 
		//if (puzzle[rowStart + (i % 3)][colStart + (i / 3)] == num) return 0;
		// 3x3 칸에 숫자가 있으면 이용가능(Available) 하지 않음 
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

	return 1; // 같은 숫자가 없다면 숫자를 넣을 수 있음  
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
			// 해당 행,열 에 숫자가 채워져있으면  
		{
			if ((col + 1)<9) return fillSudoku(puzzle, row, col + 1, level + 1);
			// 다음 열에 숫자를 채우도록 함수 호출  
			else if ((row + 1)<9) return fillSudoku(puzzle, row + 1, 0, level + 1);  
			//다음 행 첫칸에 숫자를 채우도록 함수 호출
			else return 1;
		} // if

		else
		{
			for (i = 0; i<9; ++i)
			{
				if (isAvailable(puzzle, row, col, i + 1))
					// 숫자(i+1)를 넣는 것이 가능 하다면 
				{
					puzzle[row][col] = i + 1; // 숫자를 넣고  
					if ((col + 1)<9)  // 열이 끝까지 안갔다면  
					{
						if (fillSudoku(puzzle, row, col + 1, level + 1)) return 1;
						// 다음 열에 숫자를 넣는게 가능하면 성공을 리턴  
						else puzzle[row][col] = 0;
						// 그렇지 않으면 그숫자를 0으로하여 물림 
					} // if 
					else if ((row + 1)<9)  // 행이 끝까지 않갔다면  
					{
						if (fillSudoku(puzzle, row + 1, 0, level + 1)) return 1;
						// 다음 행 첫칸에 숫자를 넣는게 가능하면 성공을 리턴 
						else puzzle[row][col] = 0;
						// 그렇지 않으면 그숫자를 0으로하여 물림 
					} // else if
					else return 1; // 행열이 끝까지 같다면 성공을 리턴   
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
