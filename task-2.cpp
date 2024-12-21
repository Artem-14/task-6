#include <iostream>
#include <vector>
#include <locale>

void deleteColumn(std::vector<std::vector<int>>& matrix, int position) {
    if (position < 0 || position >= matrix[0].size()) {
        std::cout << "Ошибка: Некорректная позиция столбца!" << std::endl;
        return;
    }
    for (auto& row : matrix) {
        row.erase(row.begin() + position);
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    int rows = 3, cols = 3;
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int position = 1;

    deleteColumn(matrix, position);

    for (const auto& row : matrix) {
        for (int elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
