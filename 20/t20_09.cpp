#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

bool containsAllElements(const std::vector<int>& V0, const std::vector<int>& Vi) {
    std::vector<int> sortedV0 = V0;
    std::vector<int> sortedVi = Vi;
    std::sort(sortedV0.begin(), sortedV0.end());
    std::sort(sortedVi.begin(), sortedVi.end());

    return std::includes(sortedVi.begin(), sortedVi.end(), sortedV0.begin(), sortedV0.end());
}

int main() {
    std::ifstream inputFile("data.bin", std::ios::binary);
    if (!inputFile) {
        std::cerr << "Failed to open file." << std::endl;
        return 1;
    }

    int sizeV0;
    inputFile.read(reinterpret_cast<char*>(&sizeV0), sizeof(sizeV0));
    std::vector<int> V0(sizeV0);
    inputFile.read(reinterpret_cast<char*>(V0.data()), sizeV0 * sizeof(int));

    int N;
    inputFile.read(reinterpret_cast<char*>(&N), sizeof(N));

    std::vector<std::vector<int>> vectors(N);
    for (int i = 0; i < N; ++i) {
        int sizeVi;
        inputFile.read(reinterpret_cast<char*>(&sizeVi), sizeof(sizeVi));
        vectors[i].resize(sizeVi);
        inputFile.read(reinterpret_cast<char*>(vectors[i].data()), sizeVi * sizeof(int));
    }

    inputFile.close();

    int count = 0;
    for (const auto& Vi : vectors) {
        if (containsAllElements(V0, Vi)) {
            ++count;
        }
    }

    std::cout << "The number of vectors Vi that contain all elements of V0: " << count << std::endl;

    return 0;
}
