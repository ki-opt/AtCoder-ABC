#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>

using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, limit, init) for (int iter = (int)init; iter < (int)(limit); iter++)

bool desc_asc(pair<double,int> &left, pair<double,int> &right) {
	if (left.first == right.first) {
		return left.second < right.second;
	} else {
		return right.first < left.first;
	}
}

int main() {
	int N;
	cin >> N;
	vector<unsigned long int> A(N), B(N);
	rep(i,N) cin >> A[i] >> B[i];

	vector<pair<double,int>> ans(N);
	rep(i,N) {
		ans[i] = make_pair((double)A[i] / (double)(A[i] + B[i]), i + 1);
		cerr << ans[i].first << endl;
	}
	sort(ans.begin(),ans.end(), desc_asc);
	rep(i,N) cout << ans[i].second << " ";

	return 0;
}