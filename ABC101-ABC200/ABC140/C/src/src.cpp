#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>

using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, limit, init) for (int iter = (int)init; iter < (int)(limit); iter++)

int func_max(int a, int b) {
	if (a > b) return a;
	else return b;
}

int main() {
	int N;
	cin >> N;
	vector<int> B(N-1);
	rep(i,N-1) cin >> B[i];

	vector<int> A(N,0);
	A[0] = B[0];
	A[1] = B[0];
	repp(i,N-1,1) {
		A[i+1] = B[i];
		if (B[i] < A[i]) {
			A[i] = B[i];
		}
	}

	int sum = 0;
	rep(i,N) {
		sum += A[i];
	}
	cout << sum << endl;
	return 0;
}