#include <iostream>
using namespace std;

int arr[100][100];
int arr2[100][100];
bool visited[100][100];
bool visited2[100][100];


int dx[] = { 0, 0, -1, 1 };		// 상하좌우
int dy[] = { 1, -1, 0, 0 };
int N;

void DFS(int x, int y);
void DFS2(int x, int y);

enum color{R=1,G,B};

int main() {
	int count = 0, count2 = 0;
	cin >> N;
	//cin.ignore();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char tmp;  cin >> tmp;
			arr[i][j] = color(tmp);
			if (tmp == 'R' || tmp == 'G')
				arr2[i][j] = 5;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				DFS(i, j);
				count++;
			}
			if (!visited2[i][j]) {
				DFS2(i, j);
				count2++;
			}
		}
	}

	cout << count << " " << count2;
	//cout << count;

	return 0;
}


void DFS(int x, int y) {
	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];

		if (xx < 0 || xx >= N || yy < 0 || yy >= N)
			continue;
		if(arr[x][y] == arr[xx][yy] && visited[xx][yy] == 0)
			DFS(xx, yy);
	}
}



void DFS2(int x, int y) {
	visited2[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];

		if (xx < 0 || xx >= N || yy < 0 || yy >= N)
			continue;
		if (arr2[x][y] == arr2[xx][yy] && visited2[xx][yy] == 0)
			DFS2(xx, yy);
	}
}
