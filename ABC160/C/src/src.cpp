#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int K, N;
	cin >> K >> N;
	vector<int> A(N);
	rep(i,N) cin >> A[i];
	
	int max_dist = 0;
	rep(i,N-1) {
		if (A[i+1]-A[i] > max_dist) {
			max_dist = A[i+1] - A[i];
		}
	}
	if (K - A[N-1] + A[0] > max_dist) max_dist = K - A[N-1] + A[0];

	long int dist = 0;
	rep(i,N) {
		if (i == N - 1) dist += A[0] + K - A[i];
		else dist += A[i+1] - A[i];
	}

	cout << dist - max_dist << endl;

	return 0;
}