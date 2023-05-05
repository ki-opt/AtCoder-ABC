#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<vector<int>> A(3,vector<int>(3));
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> A[i][j];
		}
	}
	int N;
	cin >> N;
	vector<int> b(N);
	for (int i = 0; i < N; i++) cin >> b[i];

	for (int i = 0; i < N; i++) {
		int num = b[i];
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				if (A[j][k] == num) {
					A[j][k] = -1;
					break;
				}
			}
		}
	}

	for (int i = 0; i < 3; i++) {
		int sum = 0;
		for (int j = 0; j < 3; j++) {
			if (A[i][j] == -1) sum++;
			else break;
		}
		if (sum == 3) {
			cout << "Yes" << endl;
			return 0;
		}
		sum = 0;
		for (int j = 0; j < 3; j++) {
			if (A[j][i] == -1) sum++;
			else break;
		}
		if (sum == 3) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	if (A[0][0] == -1 && A[1][1] == -1 && A[2][2] == -1) {
		cout << "Yes" << endl;
		return 0;
	}
	if (A[2][0] == -1 && A[1][1] == -1 && A[0][2] == -1) {
		cout << "Yes" << endl;
		return 0;
	}

	cout << "No" << endl;

	return 0;
}