// 次のコンビネーションを生成する関数
bool next_combination(vector<int>& combination, int n, int k) {
	for (int i = k - 1; i >= 0; --i) {
		if (combination[i] < n - k + i) {
			++combination[i];
			for (int j = i + 1; j < k; ++j) {
					combination[j] = combination[j - 1] + 1;
			}
			return true;
		}
	}
	return false;
}
/*
	// コンビネーションを列挙
	vector<int> combination(N);
	for (int i = 0; i < N; ++i) combination[i] = i;
	do {
		for (int num : combination) {
		}
	} while (next_combination(combination, N, k));
*/