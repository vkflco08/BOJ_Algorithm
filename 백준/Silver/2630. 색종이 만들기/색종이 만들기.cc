#include <iostream>
#include <algorithm>
using namespace std;
int arr[129][129];
int whiteNum = 0, blueNum = 0;
int dx[] = { 0, 1, 0, 1 };
int dy[] = { 0, 0, 1, 1 };

int N;

bool travel(int x, int y, int width) {
	int tmp = arr[x][y];
	for (int i = x; i < x + width; i++) {
		for (int j = y; j < y + width; j++) {
			if (tmp != arr[i][j])	return false;
		}
	}
	return true;
}

void algorithm(int x, int y, int width) {
	if (travel(x, y, width)) {
		arr[x][y] == 0 ? whiteNum++ : blueNum++;
	}
	else {
		int tmp = width/2;
		for (int i = 0; i < 4; i++) {
			if(tmp > 0)
				algorithm(x + (tmp * dx[i]), y + (tmp * dy[i]), width / 2);
		}
	}
}
int main() {

	cin >> N;

	//white = 0, blue = 1
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	algorithm(0, 0, N);

	cout << whiteNum << endl << blueNum << endl;
}