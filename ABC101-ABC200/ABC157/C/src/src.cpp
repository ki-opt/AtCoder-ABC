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
	int N, M;
	cin >> N >> M;
	vector<int> s(M), c(M);
	rep(i,M) cin >> s[i] >> c[i];

	int lower;
	if (N == 1) lower = 0;
	else lower = (int)pow(10,N-1);
	repp(i,(int)pow(10,N),lower){

		unsigned digit = 0;
		int tmp_2 = i;
		while(tmp_2 != 0) {
			tmp_2 /= 10;
			digit++;
		}

		int flag = 1;
		rep(j,M) {
			/*if ((digit == 2 || digit == 1) && s[j] == 1 && c[j] == 0) {
				flag = 0;
				break;	
			}*/
			int tmp = i;
			rep(k,N-s[j]) {
				tmp /= 10;
			}
			if (tmp % 10 != c[j]) {
				flag = 0;
				break;
			}
		}
		if (flag == 1) {
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;

	return 0;
}