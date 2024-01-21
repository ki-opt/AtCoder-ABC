#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>
#include <queue>

using ull=unsigned long long;
using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	string S,T;
	cin >> S >> T;
	map<string,int> mp;
	mp["AB"] = 0; mp["BA"] = 0; mp["BC"] = 0; mp["CB"] = 0;
	mp["CD"] = 0; mp["DC"] = 0; mp["DE"] = 0; mp["ED"] = 0;
	mp["EA"] = 0; mp["AE"] = 0;
	mp["AC"] = 2; mp["CA"] = 2;
	mp["AD"] = 2; mp["DA"] = 2;
	mp["EB"] = 2; mp["BE"] = 2; mp["EC"] = 2; mp["CE"] = 2;
	mp["DB"] = 2; mp["BD"] = 2; mp["DA"] = 2; mp["AD"] = 2;

	if (mp[S] == mp[T]) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}