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

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	rep(i,N) cin >> A[i];

	int ans = 0;
	unordered_map<int,int> umap;
	rep(i,N) {
		if (umap.count(A[i]) > 0) {
			umap.erase(A[i]);
			ans--;
		} else {
			umap[A[i]] = 1;
			ans++;
		}
	}
	cout << ans << endl;
	/*sort(A.begin(),A.end());
	rep(i,N) {
		
	}*/

	return 0;
}