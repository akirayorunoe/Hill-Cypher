// Example program
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

string formatString(string a, int &l,int size)
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
	//chuyen string ve digraph(trigraph)
	if ((l % size) != 0) {
		//if (l < size) // TH string co char < size matrix vd 1,2/3 or 1/2
		//{
		//	for (int i = l; i < size; i++)
		//	{
		//		a += "Z";
		//	}
		//}
		//else //TH string co char >size matrix vd 4,5/3 or 3/2
			for (int i = l; (i % size) != 0; i++)
			{
				a += "Z";
			}
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

bool checkMod(int **a,int size)
{
	switch (size)
	{
	case 2:
		if ((a[0][0] * a[1][1] - a[0][1] * a[1][0]) % 26 > 0 && (a[0][0] * a[1][1] - a[0][1] * a[1][0])<=25 && (a[0][0] * a[1][1] - a[0][1] * a[1][0])%2 !=0)
		{
			cout << endl<< (a[0][0] * a[1][1] - a[0][1] * a[1][0])<<endl;
			return true;
		}
		break;
	case 3: 
		if ((a[0][0] * (a[1][1] * a[2][2] - a[1][2] * a[2][1]) - a[0][1] * (a[1][0] * a[2][2] - a[1][2] * a[2][0]) + a[0][2] * (a[1][0] * a[2][1] - a[1][1] * a[2][0])) % 26 > 0 && (a[0][0] * (a[1][1] * a[2][2] - a[1][2] * a[2][1]) - a[0][1] * (a[1][0] * a[2][2] - a[1][2] * a[2][0]) + a[0][2] * (a[1][0] * a[2][1] - a[1][1] * a[2][0])) <= 25 && (a[0][0] * (a[1][1] * a[2][2] - a[1][2] * a[2][1]) - a[0][1] * (a[1][0] * a[2][2] - a[1][2] * a[2][0]) + a[0][2] * (a[1][0] * a[2][1] - a[1][1] * a[2][0])) % 2 !=0)
		{
			cout <<endl<< (a[0][0] * (a[1][1] * a[2][2] - a[1][2] * a[2][1]) - a[0][1] * (a[1][0] * a[2][2] - a[1][2] * a[2][0]) + a[0][2] * (a[1][0] * a[2][1] - a[1][1] * a[2][0]))<<endl;
			return true;
		}
		break;
	default:
		break;
	}
	return false;
}

int** generateKey(int size)
{
	int **m;
	srand(time(NULL));
	m = new int*[size];
	
	do {
		for (int i = 0; i < size; i++)
		{
			m[i] = new int[size];
			for (int j = 0; j < size; j++)
			{
				int a = rand() % 25 + 0;
				m[i][j] = a;
			}
		}
	} while (!checkMod(m, size));
	return m;
}

//int** hillCypher(int **m, int **k, int size,int l)
//{
//	int **temp;
//	int tempR = 0,tempC = 0;
//	int mR = 0, mC = 0;
//	temp[tempR][tempC] = 0;
//	for (int t = 0; t < l; t++)// lap length/2 
//	{
//		for (int i = 0; i < size; i++)//row
//		{
//			for (int j = 0; j < size; j++)//coll
//			{
//				//temp[0++][0] += key[0][0++]*m[0++][0]
//				temp[tempR++][tempC] += k[i][j] * m[mR++][mC];   //a*x+b*y
//			}
//		}
//	}
//}

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
	str = formatString(str, l,size);
	cout << str<<endl<<"Size: "<<size<<endl;
	int **m = createMatrix(str, size);
	printMatrix(m, size, str.length()/size);
	cout << "Key: "<<endl;
	int **key = generateKey(size);
	printMatrix(key, size, size);
	system("pause");
}
