//Autor: Wiktor Lewicki
/*UWAGA!
 * Jest to dopiero szkielet projektu w trakcie budowy
 *	Projekt jest w trakcie tworzenia. 
 * Aktualnie jest jedynie zapisany silnik, można zagrać w dwóch graczy
 * może zawierać błędy
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
	while(plansza.ruch_gracza()!=-1);
	return 0;
}
