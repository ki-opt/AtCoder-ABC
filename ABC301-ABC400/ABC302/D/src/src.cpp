#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>

using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, limit, init) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	int N, M;
	long int D;
	cin >> N >> M >> D;
	vector<long int> A(N),B(M);
	rep(i,N) cin >> A[i];
	rep(i,M) cin >> B[i];

	sort(A.begin(),A.end(),greater<long int>());
	sort(B.begin(),B.end(),greater<long int>());
	long int ans = 0;
	int a = 0, b = 0;
	while(1) {
		ans = abs(A[a] - B[b]);
		if (ans <= D) {
			cout << A[a] + B[b] << endl;
			break;
		} else {
			if (A[a] < B[b]) {
				b++;
			} else {// if (A[a] > B[b]) {
				a++;
			}/* else {
				if (a + 1 != A.size()) a++;
				else (b + 1 != B.size()) b++;
			}*/
		}
		if (a == A.size() || b == B.size()) {
			cout << -1 << endl;
			return 0;
		}
	}
	return 0;
}