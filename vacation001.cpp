//数组应用，Josephus问题：一群小孩围成一圈，任意假定一个数M,从第一个小孩起，顺时针方向数，每数到第M个小孩时，该小孩离开，小孩不断离开去圈字不断缩小，最后留下的是第几个小孩？
#include<iostream>
using namespace std;

int main()
{
	//建立小孩数组
	const int num = 10;//小孩数
	int interval;//每次数interval个小孩，便让小孩离开
	int a[num];//小孩数组

	//给小孩编号
	for (int i = 0; i < num; i++)//小孩的编号只与小孩数有关
		a[i] = i + 1;

	//输入数小孩间隔
	cout << "please input the interval:";//输入一个数小孩个数
	cin >> interval;

	//将全体小孩输出
	for (int i = 0; i < num; i++)
		cout << a[i] << ",";
	cout << endl;

	int k = 1;//标识处理第k个离开的小孩
	int i = -1;//数组下标（下一个值0就是第一个小孩的下标）

	//处理获胜前的小孩
	while (1)
	{
		//在圈中数interval个小孩
		for (int j = 0; j < interval;)
		{
			i = (i + 1) % num;
			if (a[i] != 0)
				j++;
		}
		if (k == num) break;
		cout << a[i] << ",";
		a[i] = 0;
		k++;
	}
	//break语句跳转至此
	cout << "\nNo." << a[i] << "boy've won.\n";//输出胜利者

}