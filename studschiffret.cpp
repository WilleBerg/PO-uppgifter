#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
	int x = 0;
	int y = 0;
	
	map<int, char> sortMap;
	map<int, char> sortMap2;
	string cryptMsg = "";
	string testMsg = "ABCDEFGHIJKLMNOPQRSTUVWXYZ&¤%?";
	cin >> y >> x >> cryptMsg;
	char rutNet[100][100];

	int currX = 0;
	int currY = 0;

	bool posY = true;
	bool posX = true;

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			rutNet[i][j] = '2';
		}
	}

	for (int i = 0; i < cryptMsg.length(); i++) {
		if (currX  == x - 1) {
			posX = false;
		}
		if (currY == y - 1) {
			posY = false;
		}
		if (currX == 0) {
			posX = true;
		}
		if (currY == 0) {
			posY = true;
		}

		if (posY == true) {
			if (posX == true) {
				if (rutNet[currY][currX] != '2') {
					rutNet[currY + 1][currX + 1] = testMsg[i];
					currY = currY + 2;
					currX = currX + 2;
				} else {
					rutNet[currY][currX] = testMsg[i];
					currY++;
					currX++;
				}
			} else {
				if (rutNet[currY][currX] != '2') {
					rutNet[currY + 1][currX - 1] = testMsg[i];
					currY = currY + 2;
					currX = currX - 2;
				} else {
					rutNet[currY][currX] = testMsg[i];
					currY++;
					currX--;
				}
			}
		} else {
			if (posX == true) {
				if (rutNet[currY][currX] != '2') {
					rutNet[currY - 1][currX + 1] = testMsg[i];
					currY = currY - 2;
					currX = currX + 2;
				} else {
					rutNet[currY][currX] = testMsg[i];
					currY--;
					currX++;
				}
			} else {
				if (rutNet[currY][currX] != '2') {
					rutNet[currY - 1][currX - 1] = testMsg[i];
					currY = currY - 2;
					currX = currX - 2;
				} else {
					rutNet[currY][currX] = testMsg[i];
					currY--;
					currX--;
				}
			}
		}
	}
	char finString[30];
	int cock = 0;
	int sfrList[30];
	cout << endl;
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			if (rutNet[i][j] != '2') {
				finString[cock] = rutNet[i][j];
				cock++;
			}
		}
	}
	for (int i = 0; i < cryptMsg.length(); i++) {
		sortMap[i] = testMsg[i];
		sortMap2[i] = cryptMsg[i];
	}
	for (int i = 0; i < cryptMsg.length(); i++) {
		for (int j = 0; j < cryptMsg.length(); j++) {
			if (finString[i] == sortMap[j]) {
				sfrList[i] = j;
			}
		}
	}
	for (int i = 0; i < cryptMsg.length(); i++) {
		for (int j = 0; j < cryptMsg.length(); j++) {
			if (sfrList[j] == i) {
				cout << cryptMsg[j];
			}
		}
	}
}