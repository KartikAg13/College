#include <iostream>
#include <vector>

using namespace std;

bool safe(vector<vector<int>> &board, int length, int row, int column) {
	// check for same column
	for(int i = 0; i < row; i++) {
		if(board[i][column] == 1)
			return false;
	}

	// check for left diagonal
	int r = row, c = column;
	while(r >= 0 && c >= 0) {
		if(board[r][c] == 1)
			return false;
		r--;
		c--;
	}

	// check for right diagonal
	r = row, c = column;
	while(r >= 0 && c <= length) {
		if(board[r][c] == 1)
			return false;
		r--;
		c++;
	}
	return true;
}

void display(vector<vector<int>> &board, int length) {
	for(int i = 0; i < length; i++) {
		for(int j = 0; j < length; j++)
			cout << board[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}

void queen(vector<vector<int>> &board, int length, int row, int &count) {
	if(row == length) {
		display(board, length);
		count++;
		return ;
	}
	for(int column = 0; column < length; column++) {
		if(safe(board, length, row, column)) {
			board[row][column] = 1;
			queen(board, length, row + 1, count);
			board[row][column] = 0;
		}
	}
}

int main() {
	int length = 8;
	vector<vector<int>> board(length, vector<int>(length, 0));
	int count = 0;
	queen(board, length, 0, count);
	cout << "Total number of solutions: " << count << endl;
	return 0;
}