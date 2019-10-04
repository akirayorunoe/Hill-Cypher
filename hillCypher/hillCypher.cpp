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
	// TH string co char < size matrix vd 1,2/3 or 1/2
	 //TH string co char >size matrix vd 4,5/3 or 3/2
			for (int i = l; (i % size) != 0; i++)
			{
				a += "Z";
				l++;
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
			m[i][j] = a[index] - 64;// chuyen ASCIII ve alphabet 26
			index += s;//them chu cach chu hien tai s don vi vao hang tiep theo vd: abcd thi a -> c
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
		//>0 + <=25 + la so le + !=13
		if ((a[0][0] * a[1][1] - a[0][1] * a[1][0]) != 13 &&(a[0][0] * a[1][1] - a[0][1] * a[1][0]) % 26 > 0 && (a[0][0] * a[1][1] - a[0][1] * a[1][0])<=25 && (a[0][0] * a[1][1] - a[0][1] * a[1][0])%2 !=0)
		{
			cout << endl<< (a[0][0] * a[1][1] - a[0][1] * a[1][0])<<endl;
			return true;
		}
		break;
	case 3: 
		if ((a[0][0] * (a[1][1] * a[2][2] - a[1][2] * a[2][1]) - a[0][1] * (a[1][0] * a[2][2] - a[1][2] * a[2][0]) + a[0][2] * (a[1][0] * a[2][1] - a[1][1] * a[2][0])) != 13 && (a[0][0] * (a[1][1] * a[2][2] - a[1][2] * a[2][1]) - a[0][1] * (a[1][0] * a[2][2] - a[1][2] * a[2][0]) + a[0][2] * (a[1][0] * a[2][1] - a[1][1] * a[2][0])) % 26 > 0 && (a[0][0] * (a[1][1] * a[2][2] - a[1][2] * a[2][1]) - a[0][1] * (a[1][0] * a[2][2] - a[1][2] * a[2][0]) + a[0][2] * (a[1][0] * a[2][1] - a[1][1] * a[2][0])) <= 25 && (a[0][0] * (a[1][1] * a[2][2] - a[1][2] * a[2][1]) - a[0][1] * (a[1][0] * a[2][2] - a[1][2] * a[2][0]) + a[0][2] * (a[1][0] * a[2][1] - a[1][1] * a[2][0])) % 2 !=0)
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
	srand((unsigned int)time(NULL));
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

int** hillCypher(int **m, int **k, int size,int l)
{
	int **temp;
	int kR = 0, kC=0;//key row, key coll
	int mR = 0, mC = 0;//matrix row, matrix coll
	temp = new int*[size];
	int columns = l/size;
	for (int i = 0; i<size; i++)
	{
		temp[i] = new int[columns];
		for (int j = 0; j<columns; j++)//giai quyet coll
		{
			if(size == 2)
			{
				temp[i][j] = ((k[kR][kC]*m[mR][mC])+(k[kR][kC+1]*m[mR+1][mC])) % 26;//a*x+b*y
				mC++;//next coll
			}
			else if(size == 3)
			{
				temp[i][j] = ((k[kR][kC] * m[mR][mC]) + (k[kR][kC + 1] * m[mR + 1][mC]) + (k[kR][kC + 2] * m[mR + 2][mC])) % 26;//a*x+b*y
				mC++;//next coll
			}
		}
		mC = 0;
		kR++;
	}
	return temp;
}

void toString(int **a, int hang, int cot)
{
	int i = 0;
	int r = 0, c = 0;
	int condition = hang*cot;
	char *temp = new char[condition];
		while (condition >= 0)
		{
			if (r == hang) { r = 0; c++;}
			temp[i] = a[r++][c]+64;
			if (temp[i] == 64) { temp[i] = 90; }
			i++;
			condition--;
		}
		temp[hang*cot] = '\0';
		cout << endl << temp<<endl;
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
	str = formatString(str, l,size);
	cout << str<<endl<<"Size: "<<size<<endl;
	int **m = createMatrix(str, size);
	printMatrix(m, size, str.length()/size);
	cout << "Key: "<<endl;
	int **key = generateKey(size);
	printMatrix(key, size, size);
	cout << endl << "Encrypt: "<<endl;
	int **value = hillCypher(m, key, size, l);
	printMatrix(value, size, l/size);
	cout << endl;
	toString(value, size, l / size);
	system("pause");
}
