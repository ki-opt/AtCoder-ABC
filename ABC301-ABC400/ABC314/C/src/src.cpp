#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>
#include <queue>

using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	int N, M;
	cin >> N >> M;
	string S;
	cin >> S;
	vector<int> C(N);
	vector<vector<int>> iro(M+1,vector<int>());
	rep(i,N) {
		cin >> C[i];
		iro[C[i]].push_back(i);
	}

	repp(i,1,M+1) {
		string tmp;
		for (int j = iro[i].size() - 1; j > 0; j--) {
			if (tmp.empty()) tmp = S[iro[i][j]];
			S[iro[i][j]] = S[iro[i][j-1]];
			/*
			if (tmp.empty()) {
				tmp = S[iro[i][j+1]];
				S[iro[i][j+1]] = S[iro[i][j]];
			} else {
				tmp = S[iro[i][j+1]];
				S[iro[i][j+1]] = tmp[0];
			}*/
		}
		if (tmp.empty() == false) S[iro[i][0]] = tmp[0];
	}
	cout << S << endl;
	return 0;
}