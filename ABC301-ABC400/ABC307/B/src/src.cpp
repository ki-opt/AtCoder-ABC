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
	vector<string> S(N);
	rep(i,N) cin >> S[i];

	rep(i,N) {
		rep(j,N) {
			string tmp;
			if (i != j) {
				tmp = S[i] + S[j];
				//if (tmp.size() % 2 == 0) {
				int failed_flag = 0;
				rep(k,tmp.size()/2) {
					if (tmp[k] != tmp[tmp.size()-k-1]) {
						failed_flag = 1;
						break;
					}
				}
				if (failed_flag == 0) {
					cout << "Yes" << endl;
					return 0;
				}
				//}
			}
		}
	}
	cout << "No" << endl;

	return 0;
}