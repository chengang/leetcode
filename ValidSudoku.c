#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isValidSudokuRow(char row[9]) {
	int i,j;
	for(i=0;i<9;i++) {
		char s = row[i];
		if (s == '.')
			continue;
		for(j=0;j<9;j++) {
			if (s == row[j] && j != i) {
				printf("row: %d, col: %d\n", i, j);
				return false;
			}
		}
	}
	return true;
}

bool isValidSudoku(char board[9][9]) {
	int i;
	for(i=0;i<9;i++) {
		char row[9] = {
			board[i][0], \
				board[i][1], \
				board[i][2], \
				board[i][3], \
				board[i][4], \
				board[i][5], \
				board[i][6], \
				board[i][7], \
				board[i][8], \
		};
		if(!isValidSudokuRow(row))
			return false;

		char col[9] = {
			board[0][i], \
				board[1][i], \
				board[2][i], \
				board[3][i], \
				board[4][i], \
				board[5][i], \
				board[6][i], \
				board[7][i], \
				board[8][i], \
		};
		if(!isValidSudokuRow(col))
			return false;
	}

	int j;
	for(i=0;i<3;i++) {
		for(j=0;j<3;j++) {
			char cube[9] = {
				board[i*3+0][j*3+0], \
					board[i*3+0][j*3+1], \
					board[i*3+0][j*3+2], \
					board[i*3+1][j*3+0], \
					board[i*3+1][j*3+1], \
					board[i*3+1][j*3+2], \
					board[i*3+2][j*3+0], \
					board[i*3+2][j*3+1], \
					board[i*3+2][j*3+2], \
			};
			if(!isValidSudokuRow(cube))
				return false;
		}
	}
	return true; 
}

int main() {
	char board[9][9];
	int i,j;
	for(i=0;i<9;i++) {
		for(j=0;j<9;j++) {
			board[i][j] = '.';
		}
	}
	board[0][0] = 5;
	board[0][1] = 3;
	board[0][4] = 7;
	board[1][0] = 6;
	board[1][3] = 1;
	board[1][4] = 9;
	board[1][5] = 5;
	board[2][1] = 9;
	board[2][2] = 8;
	board[2][7] = 6;
	board[3][0] = 8;
	board[3][4] = 6;
	board[3][8] = 3;
	board[4][0] = 4;
	board[4][3] = 8;
	board[4][5] = 3;
	board[4][8] = 1;
	board[5][0] = 7;
	board[5][4] = 2;
	board[5][8] = 6;
	board[6][1] = 6;
	board[6][6] = 2;
	board[6][7] = 8;
	board[7][3] = 4;
	board[7][4] = 1;
	board[7][5] = 9;
	board[7][8] = 5;
	board[8][4] = 8;
	board[8][7] = 7;
	board[8][8] = 9;

	//printf("%c\n", board[0][3]);

	if (isValidSudoku(board)) {
		printf("true\n");
	} else {
		printf("false\n");
	}
	return 0;
}
