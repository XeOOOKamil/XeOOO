#include <iostream>
#include <string>
#define N=100
#using namespace std; 

using namespace std;

int main()
{
	string tekst;
	int liczba_sp = 0;
	cout << "Podaj swoj tekst: ";
	getline(cin, tekst);
	for (int i = 0; i < tekst.length(); i++)
	{
		if (tekst[i] == ' ')
			liczba_sp++;
	}
	cout << "Ilosc spacji: " << liczba_sp << endl;

	system("pause");
}