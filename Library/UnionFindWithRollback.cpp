/*
https://nyaannyaan.github.io/library/data-structure/rollback-union-find.hpp.html
以下コピペ
概要
Union-FindにUndo機能やrollback機能をつけたライブラリ。
UnionFindの内部実装をQuickFindと呼ばれる経路圧縮を行わない実装にすることで、
マージ1回ごとに値が変更される箇所が高々2か所になる。よってマージするごとにマージ前の配列の値を保存すれば、
Undoはunite前の値を復元することでO(1)で実行することが出来る。同様にしてrollbackも高速に処理できる。

使い方
RollbackUnionFind(int sz)：サイズszのUnionFindを生成する。計算量O(1)
unite(int x, int y)：xとyをマージする。返り値はマージに成功したらtrue、失敗したらfalseを返す。計算量O(logn)(nはUnionFindのサイズ)
find(int k)：kの根を返す。計算量O(logn)
same(int x, int y)：xとyが同じ連結成分に所属しているかを返す。計算量O(logn)
undo()：直前のuniteの操作を取り消す。計算量O(1)
snapshot()：現在のUnionFindの状態を保存する。(保存した状態はrollback()で再現できる。)計算量O(1)
get_state()：現在のuniteが呼ばれた回数を返す。
rollback(int state = -1)：UnionFindをロールバックする。計算量は状況による。(ボトルネックにはならない)
state = -1のとき：snapshot()で保存した状態にロールバックする。
そうでないとき：uniteがstate回呼び出された時の状態にロールバックする。
*/


class RollbackUnionFind {
public:
	vector<int> data;
	stack<pair<int,int>> history;
	int inner_snap;

	RollbackUnionFind(int sz) : inner_snap(0) { data.assign(sz, -1); }

	bool unite(int x, int y) {
		x = root(x), y = root(y);
		history.emplace(x, data[x]);
		history.emplace(y, data[y]);
		if (x == y) return false;
		if (data[x] > data[y]) swap(x, y);
		data[x] += data[y];
		data[y] = x;
		return true;
	}

	int root(int k) {
		if (data[k] < 0) return k;
		return root(data[k]);
	}

	bool issame(int x, int y) { return root(x) == root(y); }

	int size(int k) { return (-data[root(k)]); }

	void undo() {
		data[history.top().first] = history.top().second;
		history.pop();
		data[history.top().first] = history.top().second;
		history.pop();
	}

	void snapshot() { inner_snap = int(history.size() >> 1); }

	int get_state() { return int(history.size() >> 1); }

	void rollback(int state = -1) {
		if (state == -1) state = inner_snap;
		state <<= 1;
		assert(state <= (int)history.size());
		while (state < (int)history.size()) undo();
	}
};