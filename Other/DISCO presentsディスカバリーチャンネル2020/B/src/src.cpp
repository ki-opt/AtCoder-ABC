#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>

using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, limit, init) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	int N;
	cin >> N;
	vector<int>A(N);
	rep(i,N) cin >> A[i];

	vector<long int> calc_front(N), calc_back(N);
	calc_front[0] = A[0];
	for (int i = 1; i < N; i++) {
		calc_front[i] = calc_front[i-1] + A[i];
	}
	calc_back[N-1] = A[N-1];
	for (int i = N - 2; i >= 0; i--) {
		calc_back[i] = calc_back[i+1] + A[i];
	}
	long int min_diff = LLONG_MAX;
	for(int i = 0; i < N - 1; i++) {
		long int tmp = abs(calc_front[i] - calc_back[i+1]);
		if (tmp < min_diff) min_diff = tmp;
	}
	cout << min_diff << endl;

	return 0;
}