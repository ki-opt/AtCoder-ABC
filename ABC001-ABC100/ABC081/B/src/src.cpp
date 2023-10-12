#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, j, n) for (int i = (int)j; i < (int)(n); i++)

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	rep(i,N) cin >> A[i];

	int min_val = INT_MAX;
	rep(i,N) {
		int cnt = 0;
		while (A[i] % 2 != 1) {
			A[i] /= 2;
			cnt++;
		}
		if (cnt < min_val) min_val = cnt;
	}
	cout << min_val << endl;

	return 0;
}