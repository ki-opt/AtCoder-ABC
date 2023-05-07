#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int N, M, X;
	cin >> N >> M >> X;
	vector<int> A(M);
	rep(i,M) cin >> A[i];

	int index;
	rep(i,M) {
		if (A[i] > X) {
			index = i;
			break;
		}
	}

	int cost_N = 0;
	int pos = X;
	while(1) {
		pos++;
		if (pos == N) break;
		for (int i = index; i < M; i++) {
			if (A[i] == pos) { cost_N++; break; }
		}
	}

	int cost_0 = 0;
	pos = X;
	while(1) {
		pos--;
		if (pos == 0) break;
		for (int i = index; i >= 0; i--) {
			if (A[i] == pos) { cost_0++; break; }
		}
	}

	if (cost_N < cost_0) cout << cost_N << endl;
	else cout << cost_0 << endl;

	return 0;
}