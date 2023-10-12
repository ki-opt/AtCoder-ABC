#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>
#include <stack>

using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	int N, T, M;
	cin >> N >> T >> M;
	vector<int> A(M), B(M);
	rep(i,M) {
		cin >> A[i] >> B[i];
		A[i]--; B[i]--;
	}

	stack<vector<int>> st;
	st.push({0});
	repp(i,2,N+1) {
		auto tmp = st.top();

		if (tmp)
	}
	
	return 0;
}