#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>
#include <float.h>

using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, limit, init) for (int iter = (int)init; iter < (int)(limit); iter++)

struct node {
	int i,j,k;
	int tokuten;
};

int mex(int i, int j, int k) {
	vector<int> check(3,0);
	check[i] = 1; check[j] = 1; check[k] = 1;
	rep(l,3) {
		if (check[l] == 0) {
			//cerr << l << endl;
			return l;
		}
	}
	return 3;
}

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	rep(i,N) cin >> A[i];
	string S;
	cin >> S;

	vector<vector<int>> e(3), m(3,vector<int>(N+1,0)), x(3,vector<int>(N+1,0));
	rep(i,N) {
		if (S[i] == 'M') { 
			m[A[i]][i+1] = m[A[i]][i] + 1;
			rep(j,3) {
				if (A[i] != j) m[j][i+1] = m[j][i];
			}
		} else { 
			rep(j,3) {
				m[j][i+1] = m[j][i];
			}
		}
		
		if (S[i] == 'E') { e[A[i]].push_back(i); } 
		
		if (S[N-i-1] == 'X') { 
			x[A[N-i-1]][N-i-1] = x[A[N-i-1]][N-i] + 1;
			rep(j,3) {
				if (A[N-i-1] != j) x[j][N-i-1] = x[j][N-i];
			}
		} else { 
			rep(j,3) {
				x[j][N-i-1] = x[j][N-i]; 
			}
		}
	}

	vector<node> comb;
	rep(i,3) { rep(j,3) { rep(k,3) {
		comb.push_back({i,j,k,mex(i,j,k)});
	}}}
	
	int ans = 0;
	rep(index, comb.size()) {
		int i = comb[index].i, j = comb[index].j, k = comb[index].k;
		int tokuten = comb[index].tokuten;
		rep(index_2,e[j].size()) {
			int tmp = e[j][index_2];
			ans += m[i][tmp+1] * x[k][tmp+1] * tokuten;
		}		
	}
	cout << ans << endl;
	return 0;
}