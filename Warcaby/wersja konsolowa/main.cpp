//Autor: Wiktor Lewicki
/*UWAGA!
 * Bot gra bardzo dobrze, ciężko wygrać
 * W przeciągu kilku dni kod zostanie poprawiony na dużo bardziej czytelny
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
