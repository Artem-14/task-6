#include <iostream>
#include <vector>
#include <locale>

void shiftMatrix(std::vector<std::vector<int>>& matrix, int shifts, bool shiftRows) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    shifts %= (shiftRows ? rows : cols);

    if (shiftRows) {
        for (int s = 0; s < shifts; ++s) {
            std::vector<int> lastRow = matrix.back();
            for (int i = rows - 1; i > 0; --i) {
                matrix[i] = matrix[i - 1];
            }
            matrix[0] = lastRow;
        }
    } else {
        for (int s = 0; s < shifts; ++s) {
            std::vector<int> lastCol(rows);
            for (int i = 0; i < rows; ++i) {
                lastCol[i] = matrix[i][cols - 1];
            }
            for (int i = cols - 1; i > 0; --i) {
                for (int j = 0; j < rows; ++j) {
                    matrix[j][i] = matrix[j][i - 1];
                }
            }
            for (int i = 0; i < rows; ++i) {
                matrix[i][0] = lastCol[i];
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int shifts = 1;
    bool shiftRows = true;

    shiftMatrix(matrix, shifts, shiftRows);

    for (const auto& row : matrix) {
        for (int elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
