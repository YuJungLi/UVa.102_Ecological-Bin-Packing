#include <iostream>
#include <iomanip>
#include <string>
#pragma warning( disable : 4996 )
using namespace std;

int main()
{
	freopen("Input.txt", "rt", stdin);
	freopen("Output.txt", "w+t", stdout);
	int B[3], G[3], C[3];
	while (cin >> B[0] >> G[0] >> C[0])
	{
		int sumB = B[0], sumG = G[0], sumC = C[0], move[6], min, ptr = 0;
		char sort[6][3] = { 'B', 'C', 'G',
							'B', 'G', 'C',
							'C', 'B', 'G',
							'C', 'G', 'B',
							'G', 'B', 'C',
							'G', 'C', 'B'};
		for (int i = 1; i < 3; i++)
		{
			cin >> B[i] >> G[i] >> C[i];
			sumB += B[i];
			sumG += G[i];
			sumC += C[i];
		}
		move[0] = sumB - B[0] + sumG - G[2] + sumC - C[1];
		move[1] = sumB - B[0] + sumG - G[1] + sumC - C[2];
		move[2] = sumB - B[1] + sumG - G[2] + sumC - C[0];
		move[3] = sumB - B[2] + sumG - G[1] + sumC - C[0];
		move[4] = sumB - B[1] + sumG - G[0] + sumC - C[2];
		move[5] = sumB - B[2] + sumG - G[0] + sumC - C[1];
		min = move[0];
		for (int i = 1; i < 6; i++)
			if (move[i] < min)
			{
				min = move[i];
				ptr = i;
			}
		cout << sort[ptr][0] << sort[ptr][1] << sort[ptr][2] << " " << min << endl;
	}
	return 0;
}