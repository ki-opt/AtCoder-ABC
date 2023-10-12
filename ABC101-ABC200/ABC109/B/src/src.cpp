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
	vector<string> W(N);
	rep(i,N) cin >> W[i];

	vector<string> check;
	check.push_back(W[0]);
	repp(i,N,1) {
		if(W[i-1][W[i-1].size()-1] != W[i][0]) {
			cout << "No" << endl;
			return 0;
		}
		rep(j,check.size()) {
			if (check[j] == W[i]) {
				cout << "No" << endl;
				return 0;
			}
		}
		check.push_back(W[i]);
	}
	cout << "Yes" << endl;

	return 0;
}