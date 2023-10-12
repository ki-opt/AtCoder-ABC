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
	int N;
	string S;
	cin >> N >> S;

	int ans = 0;
	repp(i,N-1,1){
		unordered_map<char,int> umap;
		int tmp = 0;
		rep(j,i) {
			if(umap.count(S[j]) == 0) umap[S[j]] = 1;
		}
		repp(j,N,i) {
			if(umap.count(S[j]) > 0 && umap[S[j]] == 1) {
				tmp++;
				umap[S[j]]++;
			}
		}
		ans = max(ans,tmp);
	}
	cout << ans << endl;

	return 0;
}