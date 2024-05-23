//Autor: Wiktor Lewicki
/*UWAGA!
 * Jest to dopiero szkielet projektu w trakcie budowy
 * Aktualnie jest jedynie zapisany silnik, oraz bot jako przeciwnik
 * Bot gra bardzo dobrze, ciężko wygrać
 * Gra na przestrzeni ok. 2-3 dni zostanie rozwinięta w następujący sposób:
 * Wszystkie błędy (o ile takie są) zostaną usunięte
 * Możliwe że zostanie też wprowadzony interfejs graficzny, co znacznie ułatwi sterowność programu
 * Powyższe zmiany zostaną wykonane najprawdopodobniej do końca tego tygodnia
 * Instrukcja gry będzie w pliku "info.txt"
 * Pozdrawiam!
 * */
#include <bits/stdc++.h>
#include "bot.cpp"
using namespace std;
place gra;
bool ruch(){
	int pm=0;
	do{
		pm=gra.ruch_gracza();
	}while(gra.czyja_tura()==0&&pm!=-1);
	if(pm==-1) return false;
	do{
		ans ruch=bot(gra);
		pm=gra.ruch_gracza(true, ruch.a, ruch.b, ruch.c, ruch.d, true);
	}while(gra.czyja_tura()==1&&pm!=-1);
	if(pm==-1) return false;
	return true;
}
int main(){
	gra.init();
	while(ruch());
	return 0;
}
