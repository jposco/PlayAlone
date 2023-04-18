//N x N개의 수가 N x N크기의 표에 채워져 있다. 표 안의 수중 (X1, Y1)에서 (X2, Y2)까지의 합을 구하려한다.
//X는 행, Y는 열을 의미한다. 예를 들어 N=4이고, 표가 다음과 같이 채워져 있을 때를 살펴보자.

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N = 0;
	int M = 0;
	cin >> N >> M;

	vector<vector<int>> A(N + 1, vector<int>(N + 1, 0));
	vector<vector<int>> D(N + 1, vector<int>(N + 1, 0));

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> A[i][j];
			D[i][j] = D[i][j - 1] + D[i - 1][j] - D[i - 1][j - 1] + A[i][j];
		}
	}
	
	for (int i = 0; i < M; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		int result = D[x2][y2] - D[x1 - 1][y2] - D[x2][y1 - 1] + D[x1 - 1][y1 - 1];
		cout << result << endl;
	}
}