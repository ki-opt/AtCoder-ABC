#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>
#include <queue>
#include <set>

using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, limit, init) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	long int N, K, Q;
	cin >> N >> K >> Q;
	vector<long int> X(Q), Y(Q);
	rep(i,Q) cin >> X[i] >> Y[i];

	long int ans = 0;
	multiset<long int> asc_set, dec_set;
	vector<long int> A(N,-1);
	rep(i,Q) {
		if (A[X[i]-1] == -1) {
			if (asc_set.size() < K) {
				asc_set.insert(Y[i]);
				ans += Y[i];
			} else if (asc_set.size() >= K) {
				if (Y[i] > *asc_set.begin()) {
					long int tmp = *asc_set.begin();
					ans -= tmp;
					ans += Y[i];
					// Yの追加
					asc_set.insert(Y[i]);
					// asc_setからの削除/追加
					auto it = asc_set.find(tmp);
					if (it != asc_set.end()) asc_set.erase(it);
					dec_set.insert(tmp);
				} else if (Y[i] <= *asc_set.begin()) {
					dec_set.insert(Y[i]);
				}
			}
		} else if (A[X[i]-1] != -1) {
			auto it = asc_set.find(A[X[i]-1]);
			if (it != asc_set.end()) {
				ans -= A[X[i]-1];
				asc_set.erase(it);
				if (Y[i] >= *asc_set.begin()) {
					asc_set.insert(Y[i]);
					ans += Y[i];
				} else if (Y[i] < *asc_set.begin()) {
					if (Y[i] >= *dec_set.rbegin()) {
						asc_set.insert(Y[i]);
						ans += Y[i];
					} else {
						asc_set.insert(*dec_set.rbegin());
						ans += *dec_set.rbegin();
						auto it_2 = dec_set.find(*dec_set.rbegin());
						if (it_2 != dec_set.end()) dec_set.erase(it_2);
					}
				}
			} else if (it == asc_set.end()) {
				auto it_3 = dec_set.find(A[X[i]-1]);
				if (it_3 != dec_set.end()) dec_set.erase(it_3);
				if (Y[i] > *asc_set.begin()) {
					long int tmp = *asc_set.begin();
					ans -= tmp;
					ans += Y[i];
					asc_set.insert(Y[i]);
					auto it_2 = asc_set.find(tmp);
					if (it_2 != asc_set.end()) asc_set.erase(it_2);
					dec_set.insert(tmp);
				} else {
					dec_set.insert(Y[i]);
				}
			}
		}
		cout << ans << endl;
		A[X[i]-1] = Y[i];
	}
	return 0;
}