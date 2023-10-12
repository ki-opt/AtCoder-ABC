#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>
#include <queue>

using ull=unsigned long long;
using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	int N, X;
	cin >> N >> X;
	vector<int> A(N-1);
	rep(i,N-1) {
		cin >> A[i];
	}

	rep(i,101) {
		vector<int> B = A;
		B.push_back(i);
		sort(B.begin(),B.end());
		int total = 0;
		repp(j,1,N-1) { total += B[j]; }
		if (total >= X) {
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	
	/*
	if (total - A[0] - A[N-2] >= X) {
		cout << 0 << endl;
		return 0;
	} else {
		if (X - (total - A[0] - A[N-2]) > A[N-2]) {
			cout << -1 << endl;
			return 0;
		} else {
			cout << X - (total - A[0] - A[N-2]) << endl;
			return 0;
		}
	}*/

	return 0;
}