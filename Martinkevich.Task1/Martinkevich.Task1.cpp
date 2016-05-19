#include<iostream>
#include<fstream>

using namespace std;

const int N = 30;

void ShowContentsFile(char*);
int* InitArray(char*, int);
int ContentsFile(char*);
int* Confluence(int*, int*, int, int);
void BubbleSort(int*, int);
void AddFile(char*, int*, int);

int main()
{
	int n, m;
	char fileName1[N] = "", fileName2[N] = "", fileName3[N] = "";
	cout << "Enter the name of 1 file: ";
	cin.getline(fileName1, N, '\n');
	cout << "Contents of 1 file: " << endl;
	ShowContentsFile(fileName1);
	cout << "Enter the name of 2 file: ";
	cin.getline(fileName2, N, '\n');
	cout << "Contents of 1 file: " << endl;
	ShowContentsFile(fileName2);
	cout << "Enter the name of new file: ";
	cin.getline(fileName3, N, '\n');
	n = ContentsFile(fileName1);
	m = ContentsFile(fileName2);
	int l = n + m;
	int* a1 = InitArray(fileName1, n);
	int* a2 = InitArray(fileName2, m);
	int* c = Confluence(a1, a2, n, m);
	BubbleSort(c, l);
	cout << endl;
	AddFile(fileName3, c, l);
	cout << "Information has been successfully added in " << fileName3 << "!" << endl;
	system("pause");
	return 0;
}


int ContentsFile(char* fileName)
{
	ifstream streamIn(fileName);
	if (!streamIn.is_open())
	{
		cout << "Cannot open file to read!" << endl;
		system("pause");
		exit(1);
	}
	int count = 0, term;
	while (!streamIn.eof())
	{
		streamIn >> term;
		count++;
	}
	streamIn.close();
	return count;
}

int* InitArray(char* fileName, int n)
{
	ifstream streamIn(fileName);
	if (!streamIn.is_open())
	{
		cout << "Cannot open file to read!" << endl;
		system("pause");
		exit(1);
	}
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
		streamIn >> arr[i];
	streamIn.close();
	return arr;
}

int* Confluence(int* a, int* b, int n, int m)
{
	int* c = new int[n + m];
	for (int i = 0; i < n; i++)
	{
		c[i] = a[i];
	}
	for (int i = 0; i < m;)
	{
		for (int j = n; j < (n + m); j++)
		{
			c[j] = b[i];
			i++;
		}
	}
	return c;
}

void BubbleSort(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (arr[j] < arr[j - 1])
			{
				int x = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = x;
			}
		}
	}
}

void AddFile(char* fileName, int* arr, int n)
{
	ofstream streamOut(fileName, ios::app);
	if (!streamOut.is_open())
	{
		cout << "\nCannot open file to addition!\n";
		system("pause");
		exit(1);
	}
	streamOut << "\n\n";
	for (int i = 0; i < n; i++)
	{
		streamOut.width(5);
		streamOut << arr[i];
	}
	streamOut.close();
}

void ShowContentsFile(char* fileName)
{
	ifstream streamIn;
	streamIn.open(fileName);
	if (!streamIn.is_open())
	{
		cout << " Cannot open file " << fileName << " to read!" << endl;
		system("pause");
		exit(1);
	}
	char String[N] = "";
	while (!streamIn.eof())
	{
		streamIn.getline(String, N, '\n');
		cout << String << endl;
	}
}