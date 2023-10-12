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
	vector<string> S(N);
	vector<int> A(N);
	rep(i,N) cin >> S[i] >> A[i];

	int index;
	int min_val = INT_MAX;
	rep(i,N) {
		if (A[i] < min_val) {
			min_val = A[i];
			index = i;
		}
	}

	int cnt = 0;
	while(1) {
		cout << S[index] << endl;
		index++;
		if (index == N) index = 0;
		cnt++;
		if (cnt >= N) break;
	}

	return 0;
}