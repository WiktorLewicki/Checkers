/*UWAGA!
 * Jest to dopiero szkielet projektu w trakcie budowy
 *	Projekt jest w trakcie tworzenia. 
 * Aktualnie jest jedynie zapisany silnik, można zagrać w dwóch graczy
 * może zawierać błędy, schodź zostało całkiem dobrze przetestowane
 * Gra na przestrzeni ok. 2-3 dni zostanie rozwinięta w następujący sposób:
 * Wszystkie błędy zostaną usunięte
 * Graczem 2 będzie przeciwnik czyli bot który będzie rozważał graf możliwości ruchów z określoną głębokością
 * Możliwe że zostanie też wprowadzony interfejs graficzny, co znacznie ułatwi sterowność programu
 * Powyższe zmiany zostaną wykonane najprawdopodobniej do końca tego tygodnia
 * Instrukcja gry będzie w pliku "info.txt"
 * Pozdrawiam
 * UWAGA!
 * */
#include <bits/stdc++.h>
#include "silnik.cpp"
using namespace std;
int main(){
	place plansza;
	plansza.init();
	plansza.print();
	while(1){
		if(plansza.czy_koniec()){
			if(plansza.tura==0) cout<<"Wygral gracz 2!\n";
			else cout<<"Wygral gracz 1!\n";
			return 0;
		}
		int pm=plansza.ruch_gracza(plansza.tura);
		if(pm){
			if(pm==2) plansza.bierki[!plansza.tura]--;
			if(plansza.bierki[0]==0){
				cout<<"Wygral gracz 2\n";
				return 0;
			}
			if(plansza.bierki[1]==0){
				cout<<"Wygral gracz 1\n";
				return 0;
			}
			if(!(pm==2&&plansza.chk(plansza.last1, plansza.last2, plansza.tura))){
				plansza.tura=!plansza.tura;
				plansza.last1=0, plansza.last2=0;
			}
		}
	}
	return 0;
}
