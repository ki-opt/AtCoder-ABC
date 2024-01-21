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
	int N;
	cin >> N;
	vector<int> A(N);
	rep(i,N) cin >> A[i];

	int max_val = *max_element(A.begin(),A.end());
	for (int val = max_val - 1; val >= 0; val--) {
		rep(i,N) {
			if (A[i] == val) {
				cout << A[i] << endl;
				return 0;
			}
		}
	}

	return 0;
}