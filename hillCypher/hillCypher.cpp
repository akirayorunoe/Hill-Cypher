// Example program
#include <iostream>
#include <string>
using namespace std;

string formatString(string a)
{
	int n = a.length();
	//chuyen string ve so chan
	if (n % 2 != 0) {
		a += "z";
	}
	//uppercase
	for (int i = 0; i<n; i++)
	{
		if (97 <= (int)a[i] && (int)a[i] <= 122) {
			a[i] -= 32;
		}
		//remove space
		if ((int)a[i] == 32) {
			//cout <<endl<<"space"<< a[i];
			for (int j = i; j<n - 1; j++)
			{
				a[j] = a[j + 1];
			}
			n--;
		}
	}
	return a;
}

int main()
{
	string str;
	cout << "Nhap chuoi:";
	getline(cin,str);
	str = formatString(str);
	cout << str;
	system("pause");
}
