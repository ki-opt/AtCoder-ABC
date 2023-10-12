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
	vector<vector<int>> A(2,vector<int>(N));
	rep(i,2) {
		rep(j,N) cin >> A[i][j];
	}

	vector<vector<int>> sum(2,vector<int>(N,0));
	sum[0][0] = A[0][0];
	repp(i,N,1) {
		sum[0][i] = sum[0][i-1] + A[0][i]; 
	}

	sum[1][0] += A[0][0] + A[1][0];
	repp(i,N,1) {
		if (sum[0][i] > sum[1][i-1]) sum[1][i] = sum[0][i] + A[1][i];
		else sum[1][i] = sum[1][i-1] + A[1][i];
	}
	cout << sum[1][N-1] << endl;

	return 0;
}