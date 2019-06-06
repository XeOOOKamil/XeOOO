#include <iostream>
#define N 100
using namespace std;
char tab[N];
void Switch(char tab[])
{
	int liczba_a = 0;
	int liczba_b = 0;
	int liczba_c = 0;
	int dlugosc = strlen(tab);
	for (int i = 0; i < dlugosc; i++)
	{
		switch (tab[i])
		{
		case 'a':
			liczba_a++;
			break;
		case 'b':
			liczba_b++;
			break;
		case 'c':
			liczba_c++;
			break;
		default:
			break;
		}
	}
	cout << "Liter a w tym wyrazie jest: " << liczba_a << endl;
	cout << "Liter b w tym wyrazie jest: " << liczba_b << endl;
	cout << "Liter c w tym wyrazie jest: " << liczba_c << endl;
}

int main()
{
	cout << "Wprowadz wyraz ktory ma max 100 znakow" << endl;
	cin >> tab;
	Switch(tab);
	system("pause");
	return 0;
}