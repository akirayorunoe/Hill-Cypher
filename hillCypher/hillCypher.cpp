// Example program
#include <iostream>
#include <string>
using namespace std;

string formatString(string a, int &l)
{
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
			//uppercase khi dich phan tu len 
			if (97 <= (int)a[i] && (int)a[i] <= 122) {
				a[i] -= 32;
			}
			l--;
		}
	}
	//resize lai chuoi
	a.resize(l);
	//chuyen string ve so chan
	if (l % 2 != 0) {
		a += "Z";
	}
	return a;
}

int** createMatrix(string a,int s)
{
	int **m,index=0,temp=0;
	m = new int*[s];
	int columns = a.length() / s;
	for (int i = 0; i<s; i++)
	{
		m[i] = new int[columns];		
		for (int j = 0; j<columns; j++)		
		{
			m[i][j] = a[index];
			index += s;
		}
		index = ++temp;
	}
	return m;
}

void printMatrix(int **a, int hang, int cot) {
	for (int i = 0; i<hang; i++)
	{
		for (int j = 0; j<cot; j++)
			cout << a[i][j] << "\t";	
		cout << "\n";						
	}
}

int main()
{
	int size;
	//input
	string str;
	cout << "Nhap chuoi: ";
	getline(cin,str);
	cout <<endl<< "Nhap size la 2 hoac 3";
	do {
		cout << endl << "Nhap size: ";
		cin >> size;
	} while (size != 2 && size != 3);
	//serve problem 
	int l = str.length();
	str = formatString(str, l);
	cout << str<<endl<<"Size: "<<size<<endl;
	int **m = createMatrix(str, size);
	printMatrix(m, size, str.length()/size);
	system("pause");
}
