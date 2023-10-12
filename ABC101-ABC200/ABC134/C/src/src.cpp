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

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	rep(i,N) cin >> A[i];
	vector<int> B = A;

	sort(B.begin(),B.end(),greater<int>());
	int max_val = B[0], next_max_val;
	if (B[1] == max_val) {
		rep(i,N) {
			cout << max_val << endl;
		}
	} else {
		next_max_val = B[1];
		rep(i,N) {
			if (A[i] == max_val) {
				cout << next_max_val << endl;
			} else {
				cout << max_val << endl;
			}
		}
	}

	return 0;
}