#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>

using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	int N;
	cin >> N;
	vector<vector<int>> A(N,vector<int>(N));
	rep(i,N) {
		string tmp;
		cin >> tmp; 
		rep(j,N) {
			A[i][j] = tmp[j] - '0';
		}
	}

	rep(i,N) {
		rep(j,N) {
			if (i == 0) {
				if (j == 0) { cout << A[1][0]; }
				else { cout << A[0][j-1]; }
				//cerr << i << endl;
			} else if (i == N - 1) {
				if (j == N - 1) cout << A[i-1][j];
				else cout << A[i][j+1];
				//cerr << i << endl;
			} else {
				if (j == 0) cout << A[i+1][j];
				else if (j == N - 1) cout << A[i-1][j];
				else cout << A[i][j];
				//cerr << i << endl;
			}
		}
		cout << endl;
	}

	return 0;
}