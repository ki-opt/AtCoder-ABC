#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	vector<vector<int>> A(N, vector<int>(N));
	vector<vector<int>> B(N, vector<int>(N));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> A[i][j];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> B[i][j];
	}

	vector<vector<int>> wrk_A = A;	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			
		}
	}

	return 0;
}