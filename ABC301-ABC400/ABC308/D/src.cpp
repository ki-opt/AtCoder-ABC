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

struct ab {
	unsigned long int a, b;
};

bool desc_asc(pair<ab,int> &left, pair<ab,int> &right) {
	unsigned long int hidari, migi;
	hidari = left.first.a * (right.first.a + right.first.b);
	migi = right.first.a * (left.first.a + left.first.b);
	if (hidari == migi) {
		return left.second < right.second;
	} else {
		return hidari > migi;
	}
}

int main() {
	int N;
	cin >> N;
	vector<unsigned long int> A(N), B(N);
	rep(i,N) cin >> A[i] >> B[i];

	vector<pair<ab, int>> ans(N);
	rep(i,N) {
		ans[i] = make_pair(ab{A[i],B[i]}, i + 1);
	}
	sort(ans.begin(), ans.end(), desc_asc);
	rep(i,N) cout << ans[i].second << " ";
	cout << endl;

	return 0;
}