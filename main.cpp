#include <iostream>

int grid[9][9] = {{8, 0, 0, 0, 0, 0, 0, 0, 0}, 
				  {0, 0, 3, 6, 0, 0, 0, 0, 0}, 
				  {0, 7, 0, 0, 9, 0, 2, 0, 0}, 
				  {0, 5, 0, 0, 0, 7, 0, 0, 0}, 
				  {0, 0, 0, 0, 4, 5, 7, 0, 0},
				  {0, 0, 0, 1, 0, 0, 0, 3, 0}, 
				  {0, 0, 1, 0, 0, 0, 0, 6, 8}, 
				  {0, 0, 8, 5, 0, 0, 0, 1, 0}, 
				  {0, 9, 0, 0, 0, 0, 4, 0, 0}};

int count = 0;

bool possible(int row, int col, int num) {
	for (int i = 0; i < 9; i++) {
		if (grid[row][i] == num || grid[i][col] == num) {
			return false;
		}
	}

	row = (row / 3) * 3;
	col = (col / 3) * 3;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (grid[row + i][col + j] == num) {
				return false;
			}
		}
	}

	return true;
}

bool solve() {
	count++;
    
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (grid[i][j] == 0) {
				for (int n = 1; n < 10; n++) {
					if (possible(i, j, n)) {
						grid[i][j] = n;
						if (solve()) {
							return true;
						}
						grid[i][j] = 0;
					}
				}
				return false;
			}
		}
	}
	return true;
}

int main() {
	if (!solve()) {
		std::cerr << "puzzle cannot be solved" << std::endl;
	}

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			std::cout << grid[i][j] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl << count << std::endl;
}
