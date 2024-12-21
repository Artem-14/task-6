#include <iostream>
#include <vector>
#include <locale>

void addColumn(std::vector<std::vector<int>>& matrix, int position, const std::vector<int>& newColumn) {
    if (position < 0 || position > matrix[0].size()) {
        std::cout << "Ошибка: Некорректная позиция столбца!" << std::endl;
        return;
    }
    for (size_t i = 0; i < matrix.size(); ++i) {
        matrix[i].insert(matrix[i].begin() + position, newColumn[i]);
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
    std::vector<int> newColumn = {10, 11, 12};
    int position = 1;

    addColumn(matrix, position, newColumn);

    for (const auto& row : matrix) {
        for (int elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
