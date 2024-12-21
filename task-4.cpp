#include <iostream>
#include <vector>
#include <set>
#include <locale>

std::vector<int> getCommon(const std::vector<int>& a, const std::vector<int>& b, const std::vector<int>& c) {
    std::set<int> commonAB(a.begin(), a.end());
    std::vector<int> common;
    for (int x : b) {
        if (commonAB.count(x)) {
            common.push_back(x);
        }
    }
    std::vector<int> result;
    for (int x : common) {
        if (std::find(c.begin(), c.end(), x) != c.end()) {
            result.push_back(x);
        }
    }
    return result;
}

std::vector<int> getUnique(const std::vector<int>& a, const std::vector<int>& b, const std::vector<int>& c) {
    std::set<int> uniqueSet(a.begin(), a.end());
    uniqueSet.insert(b.begin(), b.end());
    uniqueSet.insert(c.begin(), c.end());
    return std::vector<int>(uniqueSet.begin(), uniqueSet.end());
}

std::vector<int> getNegatives(const std::vector<int>& a, const std::vector<int>& b, const std::vector<int>& c) {
    std::set<int> negatives;
    for (int x : a) if (x < 0) negatives.insert(x);
    for (int x : b) if (x < 0) negatives.insert(x);
    for (int x : c) if (x < 0) negatives.insert(x);
    return std::vector<int>(negatives.begin(), negatives.end());
}

int main() {
    setlocale(LC_ALL, "rus");
    std::vector<int> A = {1, 2, 3, -1};
    std::vector<int> B = {3, 4, -1, -2};
    std::vector<int> C = {1, 3, 5, -2};

    auto common = getCommon(A, B, C);
    auto unique = getUnique(A, B, C);
    auto negatives = getNegatives(A, B, C);

    std::cout << "Общие значения для A, B, C: ";
    for (int x : common) std::cout << x << " ";
    std::cout << "\nУникальные значения: ";
    for (int x : unique) std::cout << x << " ";
    std::cout << "\nОтрицательные значения: ";
    for (int x : negatives) std::cout << x << " ";
    std::cout << std::endl;

    return 0;
}
