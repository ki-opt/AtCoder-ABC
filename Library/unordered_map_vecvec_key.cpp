#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// ハッシュ関数の定義
struct VectorHash {
	size_t operator()(const vector<vector<int>>& vec) const {
		size_t seed = vec.size();
		for (const auto& innerVec : vec) {
			seed ^= innerVec.size() + 0x9e3779b9 + (seed << 6) + (seed >> 2);
			for (const auto& i : innerVec) {
				seed ^= i + 0x9e3779b9 + (seed << 6) + (seed >> 2);
			}
		}
		return seed;
	}
};

// 等値比較関数の定義
struct VectorEqual {
	bool operator()(const vector<vector<int>>& lhs, const vector<vector<int>>& rhs) const {
		return lhs == rhs;
	}
};

int main() {
	unordered_map<vector<vector<int>>, int, VectorHash, VectorEqual> myMap;

	// 二次元ベクトルをキーとして使用
	vector<vector<int>> key1 = {{1, 2, 3}, {4, 5, 6}};
	vector<vector<int>> key2 = {{7, 8, 9}, {10, 11, 12}};

	myMap[key1] = 42;
	myMap[key2] = 99;

	// アクセスして値を取得
	cout << "Value for key1: " << myMap[key1] << endl;
	cout << "Value for key2: " << myMap[key2] << endl;

	return 0;
}