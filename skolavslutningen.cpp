#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
	int n, m, amnt;
	int k = 0;
	vector<string> karta;
	map<char, int> mp;
	map<int, char> slutgiltig;
	string alfa = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		string tmp = "";
		cin >> tmp;
		karta.push_back(tmp);
	}
	for (int i = 0; i < k; i++) {
		mp[alfa[i]] = i + 1;
	}
	bool same = true;
	
	for (int i = 0; i < m; i++) {
		char prev = karta[0][i];
		int om = 0;
		for (int j = 0; j < n; j++) {
			//karta[j][i]
			if (karta[j][i] != prev) {
				mp[karta[j][i]] = mp[prev];
			}
			prev = karta[j][i];
		}
	}

	for (int i = 0; i < mp.size(); i++) {
		slutgiltig[mp[alfa[i]]] = alfa[i];
	}
	cout << slutgiltig.size();
}