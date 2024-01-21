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
	vector<vector<int>> A(N+1,vector<int>(N+1)), B(N+1,vector<int>(N+1));
	repp(i,1,N+1) repp(j,1,N+1) cin >> A[i][j];
	repp(i,1,N+1) repp(j,1,N+1) cin >> B[i][j];

	bool a = true;
	repp(i,1,N+1) repp(j,1,N+1) {
		if (A[i][j] == 1) a = false;
	}
	if (a) {cout << "Yes" << endl; return 0;}

	vector<vector<int>> origA = A;
	int cnt = 0;
	while(cnt < 4) {
		vector<vector<int>> tmp = A;
		repp(i,1,N+1) repp(j,1,N+1) A[i][j] = tmp[N+1-j][i];
		bool isFound = true;
		repp(i,1,N+1) repp(j,1,N+1) if (A[i][j] == 1 && B[i][j] == 0) isFound = false;
		if (isFound) {
			cout << "Yes" << endl;
			return 0;
		} 
		cnt++;
	}
	cout<< "No" << endl;
	return 0;
}