#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int N, D, X;
	cin >> N >> D >> X;
	vector<int> A(N);
	rep(i,N) cin >> A[i];

	int sum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < D; j++) {
			int day = j * A[i] + 1;
			if (day <= D) {
				sum++;
			}
		}
	}
	cout << sum + X << endl;

	return 0;
}