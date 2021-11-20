#include <iostream>


using namespace std;

int main() {
	int antal = 0;
	cin >> antal;
	int tmp = 1;
	int answer = 0;
	for (int i = 0; i < antal; i++)
	{
		answer += (tmp * tmp * tmp);
		tmp++;
	}
	cout << answer;

#ifdef _DEBUG
	system("pause");
#endif // _DEBUG

}