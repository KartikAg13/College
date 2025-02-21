#include <iostream>
#include <vector>

using namespace std;

bool safe(vector<vector<int>> &maze, int length, int row, int column) {
	if(row < 0 || column < 0 || row >= length || column >= length)
		return false;
	else if(maze[row][column] != 1)
		return false;
	return true;
}

void display(vector<vector<int>> &maze, int length) {
	for(int i = 0; i < length; i++) {
		for(int j = 0; j < length; j++)
			cout << maze[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}

void rat(vector<vector<int>> &maze, int length, int row, int column, int &count) {
	if(row == length - 1 && column == length - 1) {
		maze[row][column] = 2;
		display(maze, length);
		maze[row][column] = 1;
		count++;
		return ;
	}

	maze[row][column] = 2;

	vector<int> direction_1 = {1, -1, 0, 0};
	vector<int> direction_2 = {0, 0, 1, -1};

	for(int index = 0; index < 4; index++) {
		int next_row = row + direction_1[index];
		int next_column = column + direction_2[index];

		if(safe(maze, length, next_row, next_column)) 
			rat(maze, length, next_row, next_column, count);
	}

	maze[row][column] = 1;
}

int main() {
	int length = 10;
	vector<vector<int>> maze = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
		{1, 1, 1, 1, 1, 1, 0, 1, 1, 1},
		{1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
		{1, 1, 1, 1, 0, 1, 1, 1, 1, 1},
		{1, 0, 0, 1, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1}
	};
	
	int count = 0;
	rat(maze, length, 0, 0, count);
	cout << "Total number of solutions: " << count << endl;
	return 0;
}