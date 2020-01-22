#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include<conio.h>
#include<ctime>
#include<windows.h>
using namespace std;

void ekranPoczatkowy();
void info();
void gra();
int wylosuj();
bool czyBylaWylosowana(int iLiczba, int tab[], int ile);
void wygrana();
int wczytajLiczbe()
{
	char wczytLicz;
	do {
		cin.clear();
		cin.sync();
		cin >> wczytLicz;

		if ((int)wczytLicz < 49 || (int)wczytLicz > 51)
		{

		}
		

	} while ((int)wczytLicz < 49 || int(wczytLicz) >51);

	return wczytLicz;
}
int wczytaj()
{
	char wczytLicz;
	do {
		cin.clear();
		cin.sync();
		cin >> wczytLicz;

		if ((int)wczytLicz < 65 || (int)wczytLicz > 68)
			cout << "Podales zle dane: sproboj ponownie." << endl;


	} while ((int)wczytLicz < 65 || int(wczytLicz) >68);

	return wczytLicz;
}
int main()
{
	
	
	setlocale(LC_ALL, "polish");
	int a = 3;
	while (a>2)
	{
		system("cls");
		ekranPoczatkowy();
		
		char wybor;
		wybor = wczytajLiczbe();
		
		switch (wybor) 
		{
		 case '1':
			 gra();
			 break;
		 case '2':
			 info();
			 break;
		 case '3':
			 a = 1;
			 break;
		 case '4':
			 
			 break;
		 default:
			 cout << "Podaj poprawnie!!!";
			 Sleep(2000);
			 break;

		}

	}

	
}

void ekranPoczatkowy()
{
	
	 

		cout << "	ooo        ooooo  o8o  oooo   o8o                                                                  " << endl;
		cout << "	`88.       .888'  `'  ` 888   `'                                                                    " << endl;
		cout << "	`88.       .888'  `''  `888   `''                                                                  " << endl;
		cout << "	 888b     d'888  oooo   888  oooo   .ooooo.  ooo. .oo.    .ooooo.  oooo d8b   oooooooo oooo    ooo " << endl;
		cout << "	 8 Y88. .P  888  `888   888  `888  d88' `88b `888P'Y88b  d88' `88b `888""8P  d'''7d8P   `88.  .8'  "<<endl;
		cout << "	 8  `888'   888   888   888   888  888   888  888   888  888ooo888  888        .d8P'     `88..8'   " << endl;
		cout << "	 8    Y     888   888   888   888  888   888  888   888  888    .o  888      .d8P'  .P    `888'    " << endl;
		cout << "	o8o        o888o o888o o888o o888o `Y8bod8P' o888o o888o `Y8bod8P' d888b    d8888888P      .8'     " << endl;
		cout << "	-------------------------------------------------------------------------------------- .o..P'      " << endl;
		cout << "        --------------------------------------------------------------------------------------`Y8P'   "<<  endl;
		cout << "**************************" << endl;
		cout << "*   1.ZAGRAJ             *" << endl;
		cout << "*   2.INFO               *" << endl;
		cout << "*   3.WYJSCIE            *" << endl;
		cout << "**************************" << endl;
		cout << "Wpisz tutaj: ";

}
void info()
{
	cout << "*********************************************" << endl;
	cout << "Zbiór 12 pytań na które musisz odpowiedzieć poprawnnie." << endl;
	cout << "Jeśli się pomylisz będziesz musiał zagrać jeszcze raz!" << endl;
	cout << "              !!!POWODZENIA!!" << endl;
	cout << "*********************************************" << endl;
	Sleep(3000);
}
void gra()
{
	srand(time(NULL));
	fstream plik;
	string pytania[28];
	string odpA[28];
	string odpB[28];
	string odpC[28];
	string odpD[28];
	string poprawna[28];
	plik.open("pytania.txt", ios::in);

	if (plik.is_open())
	{
		for (int i = 0;i < 28;i++)
		{
			getline(plik, pytania[i]);
			getline(plik, odpA[i]);
			getline(plik, odpB[i]);
			getline(plik, odpC[i]);
			getline(plik, odpD[i]);
			getline(plik, poprawna[i]);
		}

	}
	else
		cout << "Nie udalo sie otworzyc pliku";	
	int drabinka[] = { 500, 1000, 2000, 5000, 10000, 20000, 40000, 75000, 125000, 250000, 500000, 1000000 };
	
	int i = 0;
	int j;
	char w;
	int punkty=0;

	int wylosowane[12]; // losowanie bez powtorzen
	int wylosowanych = 0;
	do
	{
		int liczba = wylosuj();
		if (czyBylaWylosowana(liczba, wylosowane, wylosowanych) == false)
		{
			wylosowane[wylosowanych] = liczba;
			wylosowanych++;
		} 
	} while (wylosowanych < 12);

	


	while (i < 12)
	{
		system("cls");
		j = wylosowane[i];
		cout << "********************************************" << endl;
		cout << "#"<<i+1<<"        !!!" << drabinka[i] << " zł!!!" << endl;
		cout << "********************************************" << endl;
		cout << pytania[j] << endl;

		cout << "A " << odpA[j] << endl;
		cout << "B " << odpB[j] << endl;
		cout << "C " << odpC[j] << endl;
		cout << "D " << odpD[j] << endl;
		cout << "Odpowiedz:";
		cin >> w;

		

		if (int(w) > 95) //zamiana na duza litere
			w = (int)w - 32;
		if (int(w) == int(poprawna[j][0]))
		{
			cout << endl;
			cout << "!!!Gratulacje.Poprawna odpowiedz!!!";
			punkty = 100 * (i + 1);
			Sleep(2000);
			i++;
		}
		else
		{
			
			cout << endl;
			cout << "Zła odpowiedz.Poprawna to " << poprawna[j][0] << "!!!" << endl;
			cout << "Zagraj jeszcze raz." << endl;
			
			Sleep(3000);
			break;
		}
		if (i == 12)
		{
			wygrana();
			Sleep(4000);
		}
		
			 
	}

}
bool czyBylaWylosowana(int iLiczba, int tab[], int ile) 
{
	if (ile <= 0)
		return false;

	int i = 0;
	do
	{
		if (tab[i] == iLiczba)
			return true;

		i++;
	} while (i < ile);

	return false;
}
int wylosuj()
{
	return(rand() % 28);
}
void wygrana()
{
	system("cls");
	cout << "WWWWWWWW                           WWWWWWWW                                                                                                            " << endl;
	cout << "W::::::W                           W::::::W                                                                                                                 " << endl;
	cout << "W::::::W                           W::::::W                                                                                                                 " << endl;
	cout << "W::::::W                           W::::::W                                                                                                                 " << endl;
	cout << " W:::::W           WWWWW           W:::::Wyyyyyyy           yyyyyyyggggggggg   gggggrrrrr   rrrrrrrrr   aaaaaaaaaaaaa  nnnn  nnnnnnnn      aaaaaaaaaaaaa    " << endl;
	cout << "  W:::::W         W:::::W         W:::::W  y:::::y         y:::::yg:::::::::ggg::::gr::::rrr:::::::::r  a::::::::::::a n:::nn::::::::nn    a::::::::::::a   " << endl;
	cout << "   W:::::W       W:::::::W       W:::::W    y:::::y       y:::::yg:::::::::::::::::gr:::::::::::::::::r aaaaaaaaa:::::an::::::::::::::nn   aaaaaaaaa:::::a  " << endl;
	cout << "    W:::::W     W:::::::::W     W:::::W      y:::::y     y:::::yg::::::ggggg::::::ggrr::::::rrrrr::::::r         a::::ann:::::::::::::::n           a::::a  " << endl;
	cout << "     W:::::W   W:::::W:::::W   W:::::W        y:::::y   y:::::y g:::::g     g:::::g  r:::::r     r:::::r  aaaaaaa:::::a  n:::::nnnn:::::n    aaaaaaa:::::a  " << endl;
	cout << "      W:::::W W:::::W W:::::W W:::::W          y:::::y y:::::y  g:::::g     g:::::g  r:::::r     rrrrrrraa::::::::::::a  n::::n    n::::n  aa::::::::::::a  " << endl;
	cout << "       W:::::W:::::W   W:::::W:::::W            y:::::y:::::y   g:::::g     g:::::g  r:::::r           a::::aaaa::::::a  n::::n    n::::n a::::aaaa::::::a  " << endl;
	cout << "        W:::::::::W     W:::::::::W              y:::::::::y    g::::::g    g:::::g  r:::::r          a::::a    a:::::a  n::::n    n::::na::::a    a:::::a  " << endl;
	cout << "         W:::::::W       W:::::::W                y:::::::y     g:::::::ggggg:::::g  r:::::r          a::::a    a:::::a  n::::n    n::::na::::a    a:::::a  " << endl;
	cout << "          W:::::W         W:::::W                  y:::::y       g::::::::::::::::g  r:::::r          a:::::aaaa::::::a  n::::n    n::::na:::::aaaa::::::a  " << endl;
	cout << "           W:::W           W:::W                  y:::::y         gg::::::::::::::g  r:::::r           a::::::::::aa:::a n::::n    n::::n a::::::::::aa:::a " << endl;
	cout << "            WWW             WWW                  y:::::y            gggggggg::::::g  rrrrrrr            aaaaaaaaaa  aaaa nnnnnn    nnnnnn  aaaaaaaaaa  aaaa " << endl;
	cout << "                                                y:::::y                     g:::::g                                                                         " << endl;
	cout << "                                               y:::::y          gggggg      g:::::g                                                                         " << endl;
	cout << "                                              y:::::y           g:::::gg   gg:::::g                                                                         " << endl;
	cout << "                                             y:::::y             g::::::ggg:::::::g                                                                         " << endl;
	cout << "                                            yyyyyyy               gg:::::::::::::g                                                                          " << endl;
	cout << "                                                                    ggg::::::ggg                                                                            " << endl;
	cout << "                                                                       gggggg     " << endl;
}



                                                                                                           

