#include <iostream>
int date[1001][1001],dp[1001][1001];
int n;
using namespace std;
void tower()
{
	int number;
	for (int i = n - 1;i >= 0;--i)//从倒二行开始寻找 
	{
		for (int j = 0;j <= i;j++)
		{
			number = max(dp[i + 1][j],dp[i + 1][j + 1]);//判断左边的数大还是右边的数大
			dp[i][j] = number + date[i][j]; //通过递推公式算出最大值 
		}
	}
}

void result()
{
	int number;
	int j = 0;
	cout << date[0][0];
	for (int i = 1;i < n;++i)
	{
		number = dp[i - 1][j] - date[i - 1][j];
		if (number == dp[i][j + 1])
		{
			++j;
		}
		cout << "->" << date[i][j];
	}
	cout << endl;
}

int main()
{
	cin >> n;//n为树塔层数
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j <= i;++j)
		{
			cin >> date[i][j];
			if (i == n - 1)
			{
				dp[i][j] = date[i][j];
			}
		}
	}
	 tower();
	 result();
	 cout << dp[0][0]; 
}
