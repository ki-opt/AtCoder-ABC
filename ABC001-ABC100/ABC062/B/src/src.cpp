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
	int H, W;
	cin >> H >> W;
	vector<string> a(H);
	rep(i,H){
		cin >> a[i];
	}

	rep(i,W+2){
		cout << "#";
	}
	cout << endl;
	rep(i,H){
		cout << "#";
		cout << a[i];
		cout << "#" << endl;
	}	
	rep(i,W+2){
		cout << "#";
	}

	return 0;
}