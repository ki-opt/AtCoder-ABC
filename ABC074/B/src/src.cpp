#include <iostream>
#include <vector>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int N, K;
	cin >> N >> K;
	vector<int> x(N);
	rep(i,N) cin >> x[i];

	int dist = 0;
	for (int i = 0; i < N; i++) {
		if (x[i] - 0 < K - x[i]) {
			dist += (x[i]) * 2;
		} else {
			dist += (K - x[i]) * 2;
		}
	}
	cout << dist << endl;

	return 0;
}