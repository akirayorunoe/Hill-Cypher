// Example program
#include <iostream>
#include <string>
using namespace std;

string formatString(string a, int &l)
{
	//chuyen string ve so chan
	if (l % 2 != 0) {
		a += "z";
	}
	//uppercase
	for (int i = 0; i<l; i++)
	{
		if (97 <= (int)a[i] && (int)a[i] <= 122) {
			a[i] -= 32;
		}
		//remove space
		if ((int)a[i] == 32) {
			//cout <<endl<<"space"<< a[i];
			for (int j = i; j<l - 1; j++)
			{
				a[j] = a[j + 1];
			}
			l--;
		}
	}
	//resize lai chuoi
	a.resize(l);
	return a;
}

int main()
{
	string str;
	cout << "Nhap chuoi:";
	getline(cin,str);
	int l = str.length();
	str = formatString(str, l);
	cout << str<<endl;
	system("pause");
}
