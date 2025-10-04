#include <iostream>
#include <windows.h>
using namespace std;

// task 1
int main()
{
	int a, b;
	char sym;
	cout << "Enter the first side >>> ";
	cin >> a;
	cout << "Enter the second side >>> ";
	cin >> b;
	cout << "Enter the character >>> ";
	cin >> sym;
	cout << "\n\n";
	for (int j = 0; j < a; j++) {
		for (int i = 0; i < b; i++) {
			cout << " " << sym << " ";
		}
		cout << endl;
	}
}

// task 2
int main()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	int a, b;
	int color;
	cout << "Enter the first side >>> ";
	cin >> a;
	cout << "Enter the second side >>> ";
	cin >> b;
	cout << "Enter the color (number) >>> ";
	cin >> color;
	SetConsoleTextAttribute(h, color);
	for (int i = 0; i < a; i++) {
		cout << " # ";
	}
	cout << endl;
	for (int j = 0; j < b - 2; j++) {
		cout << " # ";
		for (int k = 0; k < a - 2; k++) {
			cout << "   ";
		}
		cout << " # " << endl;
	}
	for (int i = 0; i < a; i++) {
		cout << " # ";
	}
	SetConsoleTextAttribute(h, 7);
}
