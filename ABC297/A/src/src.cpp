#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, D;
	cin >> N >> D;
	vector<int> T(N);
	for (int i = 0; i < N; i++) cin >> T[i];

	for (int i = 0; i < N - 1; i++) {
		if (T[i+1] - T[i] <= D) {
			cout << T[i+1];
			return 0;
		}
	}
	cout << -1;
	return 0;
}