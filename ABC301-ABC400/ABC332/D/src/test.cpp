#include <iostream>
#include <unordered_map>
#include <vector>

// ハッシュ関数の定義
struct VectorHash {
    std::size_t operator()(const std::vector<int>& vec) const {
        std::size_t seed = vec.size();
        for (const auto& i : vec) {
            seed ^= i + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
};

// 等値比較関数の定義
struct VectorEqual {
    bool operator()(const std::vector<int>& lhs, const std::vector<int>& rhs) const {
        return lhs == rhs;
    }
};

int main() {
    std::unordered_map<std::vector<int>, int, VectorHash, VectorEqual> myMap;

    // 二次元ベクトルをキーとして使用
    std::vector<int> key1 = {1, 2, 3};
    std::vector<int> key2 = {4, 5, 6};

    myMap[key1] = 42;
    myMap[key2] = 99;

    // アクセスして値を取得
    std::cout << "Value for key1: " << myMap[key1] << std::endl;
    std::cout << "Value for key2: " << myMap[key2] << std::endl;

    return 0;
}