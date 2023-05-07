#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, M, C;
	cin >> N >> M >> C;
	vector<int> B(M);
	vector<vector<int>> A(N,vector<int>(M));
	
	for (int j = 0; j < M; j++) {
		cin >> B[j];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> A[i][j];
		}
	}

	int cnt = 0;
	for (int i = 0; i < N; i++) {	
		int sum = 0;
		for (int j = 0; j < M; j++) {
			sum += A[i][j] * B[j];
		}
		sum += C;
		if (sum > 0) cnt++;
	}

	cout << cnt << endl;

	return 0;
}