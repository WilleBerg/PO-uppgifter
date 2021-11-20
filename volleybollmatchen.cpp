#include <iostream>
#include <string>

using namespace std;

int main() {
	string abString = "";
	int nummer = 0;
	int aPoint = 0; int bPoint = 0;
	int aSet = 0;
	int bSet = 0;
	int totalSet = 0;
	cin >> nummer;
	cin >> abString;
	for (int i = 0; i < abString.size(); i++) {
		if (abString[i] == 'A') {
			if (aPoint + 1 >= 25 && aPoint - 2 + 1 >= bPoint && totalSet < 2) {
				aPoint = 0;
				bPoint = 0;
				aSet++;
				totalSet++;
			} else if (aPoint + 1 >= 15 && aPoint - 2 + 1 >= bPoint && totalSet == 2) {
				aSet++;
			} else {
				aPoint++;
			}
		} else if (abString[i] == 'B'){
			if (bPoint + 1 >= 25 && bPoint - 2 + 1 >= aPoint && totalSet < 2) {
				aPoint = 0;
				bPoint = 0;
				bSet++;
				totalSet++;
			} else if (bPoint + 1 >= 15 && bPoint - 2 + 1 >= aPoint && totalSet == 2) {
				bSet++;
			} else {
				bPoint++;
			}
		}
	}
	cout << aSet << " " << bSet;
	
#ifdef _DEBUG
	system("pause");
#endif // _DEBUG

}