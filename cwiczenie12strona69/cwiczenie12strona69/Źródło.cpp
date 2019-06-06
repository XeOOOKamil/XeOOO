#include <iostream>

using namespace std;
int p = 0; /*
		   zmienna p to zmienna ktorej wartosc bedzie sie zwiekszac za kazdym razem
		   gdy kolejne litery (na zasadzie pocz¹tek - koniec) beda sie zgadzaly -
		   tzn. przy wyrazie "kajak" bedzie sprawdzana pierwsza i ostatnia litera
		   czyli pierwsza to "k" i ostatnia to tez "k" a wiec p zwiekszy sie o 1/
		   dokona sie inkrementacja. Nastepnie beda sprawdzana druga litera "a" i
		   przedostatnia litera "a"  ktore rowniez sie zgadzaja czyli znowu p zwiekszy
		   sie o 1.
		   Gdybysmy mieli wyraz np. "adam" to pierwsza litera to "a" a ostatnia to "m"
		   wiec p nie zwiekszy sie o 1
		   Tylko pytanie gdzie to porownywanie liter nastepuje? To zobaczymy ponizej.
		   */

char napis[100]; /* zmienna do ktorej uzytkownik bedzie wpisywal okreslony wyraz ktory
				 bedzie sprawdzany czy jest palindromem. Wpisywac wyraz bedziemy w
				 funkcji main
*/

void Palindrom(char napis[100]) /*definiujemy funkcje niezwracajaca (bo void) o nazwie
								Palindrom ktora przyjmuje 1 parametr ktory jest tablicc
								znakow o rozmiarze 100. Nic nie stoi na przeszkodzie
								aby parametr mial taka sama nazwe jak zmienna ktora
								zdefiniowalismy powyzej.
								*/
{
	int dlugosc = strlen(napis);
	/* zmienna "dlugosc" ma wartosc ktora jest policzona przez funkcje strlen
	tzn. w zaleznosci od tego jaki wyraz wprowadzi uzytkownik to tyle znakow policzy
	funkcja strlen
	np. wyraz "adam" ma 4 znaki wiec strlen zwroci wartosc 4 i taka
	wartosc bedzie przypisana do zmiennej dlugosc (max to 100 znakow bo taka wartosc
	podajemy w parametrze ktory jest przekazywany do funcji)
	*/

	int n = dlugosc / 2;/* aby nie porwnywac tych znakow dwa razy to musimy podzielic
						przez 2 wartosc zmiennej dlugosc.
						Jesli tego bysmy nie zrobili to petla ktora stworzylismy
						ponizej dzia³a³aby w ten sposob:
						1. Uzytkownik wprowadza wyraz "adam"
						2. Zmienna dlugosc ma wartosc 4
						3. Petla ma warunek i < dlugosc czyli wykonuje sie 4 razy
						4. Nastepuje sprawdzenie w kolejnych iteracjach liter:
						   - "a" z "m"
						   - "d" z "a"
						   i znowu niepotrzebnie
						   - "a" z "d"
						   - "m" z "a"
						a wiec nie potrzebnie 2 razy sprawdzamy te same litery i dlatego
						tworzymy nowa zmienna "n" ktora ma wartosc 2 razy zmniejsza od
						zmiennej "dlugosc"
						*/
	for (int i = 0; i < n; i++)
	{
		if (napis[i] == napis[dlugosc - i - 1]) p++; /*w tym miejscu nastepuje porownanie liter
		Przyk³adowo: uzytkownik wpisuje wyraz "adam" który jest wpisywany do tablicy o nazwie "napis"
		(zadeklarowalismy taka tablice na poczatku kodu). A wiec tablica ma wpisane litery w komorki
		ktore maja adresy:
		[0] litera "a"
		[1] litera "d"
		[2] litera "a"
		[3] litera "m"
		i teraz dzieki petli i zmiennej sterujacej "i" przechodzimy przez kolejne indeksy/adresy komorek
		bo jak wiemy zmienna "i" inkrementuje/ zwieksza swoja wartosc o 1 po kazdym przejsciu kolejnej
		iteracji petli (czyli w tym przypadku zmienna "i" bedzie mia³a wartosci: 0,1,2,3 KONIEC PETLI)
		i teraz porownujemy litere z poczatku czyli napis[i] i litere  z konca czyli napis[dlugosc-i-1]
		Co oznacza [dlugosc-i-1]?
		W tym miejscu liczony jest indeks/adres komorki?
		Przyk³ad:
		Uzytkownik wprowadzil wyraz "adam" czyli zmienna "dlugosc" ma wartosc 4.
		Nastepnie wchodzimy do pêtli i tam deklarowana jest zmienna steruj¹ca "i" o wartosci 0
		A wiec podczas 1 przejscia pêtli ten adres to:
		[4-0-1] czyli 3 czyli ostatna litera wyrazu "adam" ktora zostala wpisana do tablicy
		Czemu jeszcze na samym koncu w liczeniu tego adresu jest "-1"?
		Poniewaz jak pamietamy adresy komorek w tablicy sa LICZONE OD 0. Gdybysmy nie odjêli tej jedynki
		to wyszlibyœmy poza zakres tablicy i wyst¹pi³by b³¹d programu bo chcielibyœmy siê odwo³aæ do miejsca
		w pamiêci w którym nic nie ma wpisanego.
		I tu wracamy do poczatku czyli obie litery sa porownywane i jesli sa takie same to zmienna "p"
		zwieksza sie o 1.
		*/
	}
	if (p == n)
	{
		cout << "Wprowadzony przez uzytkownika wyraz jest palindromem" << endl;
	}
	else
	{
		cout << "Wprowadzony przez uzytkownika wyraz nie jest palindromem" << endl;
	}
	/*Co dzieje sie w tym miejscu? Dlaczego sprawdzamy czy zmienna p rowna sie zmiennej n?
	  Odp. Jest to logiczne - skoro kazdy wyraz sie ze soba zgadzal po kazdym przejsciu petli
	  (czyli wartosc p zostala zwiekszana o 1) to musi sie p rownac dlugosci wyrazu podzielonej na 2
	  (bo jak pamietamy "n" w³aœnie ma taka d³ugoœæ).
	  Przyklad:
	Uzytkownik wprowadza wyraz "adam"
	Zmienna dlugosc ma wartosc 4
	Zmienna "n" ma wartosc 2 (bo jest dzielona przez 2)
	Zmiennn "p" ma na poczatku wartosc 0
	Odpala sie petla
	[ITERACJA 1]
	"a" jest sprawdzane z "m", nie sa to takie same litery wiec p nie jest zwiekszane o 1
	[ITERACJA 2]
	"d" (druga litera) jest sprawdzane z "a" (przedostatnia litera), nie sa to takie same litery
	wiec p nie jest zwiekszane o 1.
	[KONIEC PETLI BO WARUNEK i < n nie jest juz spelniony bo i =2 czyli  2<2 nie jest spelniony]
	Sprawdzana jest instrukcja warunkowa czy "p" rowna sie "n"
	Warunek nie jest spelniony wiec wyswietla sie komunikat ze wybrany wyraz nie jest palindromem.
	  */
}

int main()
{
	cout << "Prosze wprowadzic wyraz o max 100 znakach" << endl;
	cin >> napis;
	Palindrom(napis);
	return 0;
}