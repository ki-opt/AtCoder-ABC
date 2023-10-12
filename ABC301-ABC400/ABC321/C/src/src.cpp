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
	//cout << (10<<10) << endl;
	
	int K;
	cin >> K;
	
	/*
	if (K <= 10) {
		cout << K << endl;
		return 0;
	}
	vector<vector<vector<int>>> hyo(10,vector<vector<int>>(10));
	for (int i = 0; i < 10; i++) hyo[i][1].push_back(1);
	for (int num = 1; num < 10; num++) {
		for (int keta = 2; keta < 10; keta++) {
			if (num == 1) hyo[num][keta].push_back()		
			hyo[num][keta].push_back(10*keta);
		}
	}

	int keta = 2;
	while(1) {
		for(int i = 1; i < 10; i++) {
			
		}
	}

	/*
	int tmp = 10;
	int keta = 2;
	while(1) {

	}
	*/

	return 0;
}