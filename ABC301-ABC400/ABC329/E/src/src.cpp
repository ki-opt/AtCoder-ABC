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
	int N, M;
	cin >> N >> M;
	string S, T;
	cin >> S >> T;

	queue<int> que;
	vector<bool> used(N,false);

	auto check = [&](int i) {
		if (used[i]) return;
		bool isFound = true;
		rep(j,M) {
			if (S[i+j] != T[j] && S[i+j] != '#') { isFound = false; break; }
		}
		if (isFound) { que.push(i); used[i] = true; }
	};

	rep(i,N-M+1) check(i);
	while(!que.empty()) {
		int tmp_i = que.front(); que.pop();
		rep(i,M) S[tmp_i+i] = '#';
		repp(i,max(0,tmp_i-M+1),min(tmp_i+M,N-M+1)) {
			check(i);
		}
	}
	
	rep(i,S.size()) {
		if (S[i] != '#') { cout << "No" << endl; return 0;}
	}
	cout << "Yes" << endl;

	/*
	rep(i,N) {
		bool isFound = false;
		rep(j,M) {
			if (S[i] == T[j]) { isFound = true; break;}
		}
		if (!isFound) { cout << "No" << endl; return 0; }
	}
	if (S[0] != T[0] || S[N-1] != T[M-1]) { cout << "No" << endl; return 0; }

	vector<int> tmp;
	rep(i,N) {
		rep(j,M) {
			if (S[i+j] != T[j]) {
				
			}
		}
	}
	*/
	return 0;
}