#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
using namespace std;
unsigned char pixel[1080][1920][3];
//记录图片的宽和高
int m, n;
//记录小块图片的宽和高
int p, q;

//将输入的像素计算为具体数值
unsigned char compute(char c1, char c2)
{
	unsigned char ch = 0;
	if (c1 >= 'a')
		ch = (c1 - 'a' + 10) * 16;
	else
		ch = (c1 - '0') * 16;

	if (c2 >= 'a')
		ch += c2 - 'a' + 10;
	else
		ch += c2 - '0';
	return ch;
}

//将小块的平均像素转换为合适的格式
void transfer(int num1, string &num2)
{
	stringstream on;
	on << num1;
	on >> num2;
	on.clear();
	if (num2.size() == 1)
	{
		on << "\\x";
		on << hex << setw(2) << uppercase << (int)num2[0];
	}
	else if (num2.size() == 2)
	{
		on << "\\x";
		on << hex << setw(2) << uppercase << (int)num2[0];
		on << "\\x";
		on << hex << setw(2) << uppercase << (int)num2[1];
	}
	else
	{
		on << "\\x";
		on << hex << setw(2) << uppercase << (int)num2[0];
		on << "\\x";
		on << hex << setw(2) << uppercase << (int)num2[1];
		on << "\\x";
		on << hex << setw(2) << uppercase << (int)num2[2];
	}
	on >> num2;
}

int main()
{
	cin >> m >> n >> p >> q;
	//RGB分别用于记录三原色的数值，N为小块图片的像素数
	int R, G, B, N = p * q;
	//SR SG SB为R G B对应的16进制字符串形式
	string SR, SG, SB;
	//PR PG PB分别用于记录上一小块图片的三原色的数值，初始为0，表默认值
	int PR = 0, PG = 0, PB = 0;
	//color用于输入像素#aaaaaa
	string color;

	//输入像素，并将输入的像素处理好后存入到pixel数组
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> color;
			//判断特殊情况如#a,将其改为#aaaaaa
			if (color.size() == 2)
				color += string(5, color[1]);
			//判断特殊情况如#aaa,将其改为#aaaaaa
			else if (color.size() == 4)
				color = string(1, color[0]) + string(2, color[1]) + string(2, color[2]) + string(2, color[3]);
			//cout << color << endl;
			pixel[i][j][0] = compute(color[1], color[2]);
			pixel[i][j][1] = compute(color[3], color[4]);
			pixel[i][j][2] = compute(color[5], color[6]);
		}
	}
	//进行循环输出小块图片的平均像素，n/q行
	for (int i = 0; i < n / q; i++)
	{
		//每进行新一行的计算时都需要把PR PG PB重置
		PR = 0, PG = 0, PB = 0;
		//共有m/p列
		for (int j = 0; j < m / p; j++)
		{
			//每进行一小块像素计算时，都需要把像素R,G,B重置
			R = 0, G = 0, B = 0;
			//计算每一小块的像素
			for (int k = i * q; k < i * q + q; k++)
			{
				for (int h = j * p; h < j * p + p; h++)
				{
					R += pixel[k][h][0];
					G += pixel[k][h][1];
					B += pixel[k][h][2];
				}
			}
			//对每一小块的像素去平均准，并转换为字符串形式
			R /= N;
			G /= N;
			B /= N;
			transfer(R, SR);
			transfer(G, SG);
			transfer(B, SB);

			//将计算的像素平均值与PR,PG,PB或者默认值0,0,0比较来输出对应数据格式
			if (!(R == PR && G == PG && B == PB))
			{
				if (R == 0 && G == 0 && B == 0)
				{
					cout << "\\x1B\\x5B"
						 << "\\x30\\x6D";
					// cout << "恢复默认";
				}
				else
				{
					cout << "\\x1B\\x5B\\x34\\x38\\x3B\\x32\\x3B" << SR << "\\x3B" << SG << "\\x3B" << SB << "\\x6D";
					// cout << "打印颜色R:" << R << "G:" << G << "B:" << B;
				}
			}
			cout << "\\x20";
			// cout << "打印空格";
			PR = R, PG = G, PB = B;

			//在每行结尾处，如果终端颜色不是默认值，应该重置终端的颜色状态。
			if (j == m / p - 1 && !(R == 0 && G == 0 && B == 0))
			{
				cout << "\\x1B\\x5B\\x30\\x6D";
				// cout << "行尾恢复默认";
			}
		}
		//换行
		cout << "\\x0A";
		// cout << "换行";
	}
	return 0;
}