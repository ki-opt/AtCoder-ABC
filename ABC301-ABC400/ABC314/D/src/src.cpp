#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>
#include <queue>
#include <cctype>
#include <cstdlib>

using ll=long long;
using std::vector; using std::cin; using std::cout;
using std::pair; using std::string;
//using std::transform; using std::toupper; using std::tolower;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	int N, Q;
	string S;
	cin >> N >> S >> Q;
	vector<int> t(Q),x(Q);
	vector<char> c(Q);
	pair<int,int> pairs = {-999,-999};
	rep(i,Q) {
		cin >> t[i] >> x[i] >> c[i];
		if (t[i] == 2) pairs = {i,-1};
		else if (t[i] == 3) pairs = {i,1};
	}

	if (pairs.first == -999) {
		rep(i,Q) {		
			if (t[i] == 1) S[x[i]-1] = c[i];
		}
		cout << S;
	} else {
		rep(i,pairs.first) {
			if (t[i] == 1) S[x[i]-1] = c[i];
		}
		if (pairs.second == -1) {
			std::transform(S.cbegin(),S.cend(),S.begin(),::tolower);
		} else if (pairs.second == 1) {
			std::transform(S.cbegin(),S.cend(),S.begin(),::toupper);
		}
		repp(i,pairs.first,Q) {
			if (t[i] == 1) S[x[i]-1] = c[i];
		}
		cout << S;
	}

	return 0;
}