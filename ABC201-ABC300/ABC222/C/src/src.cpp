#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <math.h>
#include <float.h>
#include "atcoder/all"

using namespace std;
using namespace atcoder;

using ull=unsigned long long;
using ll=long long;
//using mint = modint998244353;
//using mint = modint1000000007;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

bool desc_asc(pair<int, int>& left, pair<int, int>& right) {
	if (left.first == right.first) {
		return left.second < right.second;
	} else {
		return right.first < left.first;
	}
}

int check(char left, char right) {
	if (left == 'G') {
		if (right == 'G') return 0;
		else if (right == 'C') return 1;
		else return 2;
	} else if (left == 'C') {
		if (right == 'G') return 2;
		else if (right == 'C') return 0;
		else return 1;
	} else if (left == 'P') {
		if (right == 'G') return 1;
		else if (right == 'C') return 2;
		else return 0;
	}
}

int main() {
	int N, M; cin >> N >> M;
	vector<string> A(2*N);
	rep(i,2*N) cin >> A[i];

	vector<pair<int,int>> ans(2*N);
	rep(i,2*N) ans[i] = {0,i};
	rep(i,M) {
		for(int k = 0; k < 2*N; k+=2)	{
			int left = ans[k].second, right = ans[k+1].second;
			int res = check(A[left][i],A[right][i]);
			if (res == 1) ans[k].first++;
			else if (res == 2) ans[k+1].first++;
		}
		sort(ans.begin(),ans.end(),desc_asc);
	}

	for (auto a : ans) {
		cout << a.second+1 << endl;
	}

	return 0;
}