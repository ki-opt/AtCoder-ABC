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
	vector<int> A(M);
	rep(i,M) cin >> A[i];

	pair<int,int> pairs = {-1,-1};
	vector<int> num(N+1,0);
	rep(i,M) {
		num[A[i]]++;
		if (num[A[i]] > pairs.first) {
			pairs.first = num[A[i]];
			pairs.second = A[i];
		} else if (num[A[i]] == pairs.first) {
			pairs.second = min(A[i],pairs.second);
		}
		cout << pairs.second << endl;
	}


	return 0;
}