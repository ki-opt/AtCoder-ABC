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

	cout << A[0] << " ";
	repp(i,N,1) {
		if (abs(A[i-1] - A[i]) == 1) {
			cout << A[i] << " ";
		} else if (A[i] > A[i-1]) {
			repp(j,A[i]+1,A[i-1]+1) {
				cout << j << " ";
			}
		} else {
			for(int j = A[i-1] - 1; j >= A[i]; j--) {
				cout << j << " ";
			}
		}
	}

	return 0;
}