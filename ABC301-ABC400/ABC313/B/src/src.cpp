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
	vector<int> A(M), B(M);
	vector<vector<int>> tmp(N+1,vector<int>());
	rep(i,M) {
		cin >> A[i] >> B[i];
		tmp[A[i]].push_back(B[i]);
	}

	repp(i,1,N+1) {
		queue<int> que;
		vector<int> check(N+1,0);
		check[i] = 1;
		rep(j,tmp[i].size()) {
			que.push(tmp[i][j]);
			check[tmp[i][j]] = 1;
		}
		while(que.empty() == false) {
			int next = que.front(); que.pop();
			rep(j,tmp[next].size()) {
				if (check[tmp[next][j]] == 1) continue;
				que.push(tmp[next][j]);
				check[tmp[next][j]] = 1;
			}
		}
		int flag = 0;
		repp(j,1,N+1) {
			if (check[j] == 0) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;

	return 0;
}