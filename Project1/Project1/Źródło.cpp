#include <iostream>
#include <conio.h>
using namespace std;

//dwie funkcje - przezWartosc i przezReferencje,przez Wartosc(dwa parametry formalne a i b i typie int,przezReferencje dwa parametry formalne o nazwie x i y i typie float, dwie funckje wykonujace mnozenie,mamy wyswietlic wartosci zmiennych po wyniku





int przezWartosc(int a, int b) {
	a += 1;
	
	b += 1;

		return a * b;
}

int main() {
	int a, b;
	cout << "Podaj a:";
	cin >> a;
	cout << "Podaj b:";
	cin >> b;

	cout<<przezWartosc(a,b);
	system("pause");
	return 0;
}