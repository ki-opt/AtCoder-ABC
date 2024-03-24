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
#include "atcoder/all"

using ull=unsigned long long;
using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	int N, M; cin >> N >> M;
	vector<int> X(M);
	rep(i,M) {
		cin >> X[i];
	}

	vector<int> l(N+2,0), r(N+2,0);
	rep(i,M-1) {
		int from = X[i], to = X[i+1];
		if (from < to) {
			int tmp_1 = to - from, tmp_2 = from + N - to;
			if (tmp_1 < tmp_2) {
				l[from] += tmp_2;
				l[to] -= tmp_2;
			} else if (tmp_1 > tmp_2) {
				r[from] += tmp_1, r[0] -= tmp_1;
				r[N+1] += tmp_1, r[to] -= tmp_1;
			}
		} else if (from > to) {
			int tmp_1 = N - from + to, tmp_2 = from - to;
			if (tmp_1 < tmp_2) {
				l[from] += tmp_2, l[N+1] -= tmp_2;
				l[0] += tmp_2, l[to] -= tmp_2;
			} else if (tmp_1 > tmp_2) {
				r[from] += tmp_1;
				r[to] -= tmp_1;
			}
		}
	}
	
	vector<int> v(N+2,0);
	v[0] = l[0], v[N+1] = r[N+1];
	rep(i,N+1) {
		v[i+1] += v[i] + l[i+1];
		v[N-i] += v[N+1-i] + r[N-i];
	}

	return 0;
}