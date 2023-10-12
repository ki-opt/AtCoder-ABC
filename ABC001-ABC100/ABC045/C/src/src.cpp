#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>
#include <functional>

using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

template <typename T> bool next_combination(const T first, const T last, int k) {
    const T subset = first + k;
    // empty container | k = 0 | k == n 
    if (first == last || first == subset || last == subset) {
        return false;
    }
    T src = subset;
    while (first != src) {
        src--;
        if (*src < *(last - 1)) {
            T dest = subset;
            while (*src >= *dest) {
                dest++;
            }
            iter_swap(src, dest);
            rotate(src + 1, dest + 1, last);
            rotate(subset, subset + (last - dest) - 1, last);
            return true;
        }
    }
    // restore
    rotate(first, subset, last);
    return false;
}

int main() {
	string S;
	cin >> S;
	ll ans = stoll(S);
	repp(i,1,S.size()) {
		vector<int> v(S.size()-1);
		rep(j,S.size()-1) v[j] = j+1;
		do {
			vector<int> tmp(i);
			rep(j,i) tmp[j] = v[j];
			sort(tmp.begin(),tmp.end());
			rep(j,i) {
				if (j == 0) ans += stoll(S.substr(0,tmp[j]));
				else {
					ll val = stoll(S.substr(tmp[j-1],tmp[j]-tmp[j-1]));
					ans += val;
				}

				if (j + 1 == i) ans += stoll(S.substr(tmp[j],S.size()-tmp[j]));
			}
		} while(next_combination(v.begin(), v.end(), i));
	}
	cout << ans << endl;
	return 0;
}