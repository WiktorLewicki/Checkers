//Autor: Wiktor Lewicki
/*
 * Co prawda bot nie jest jakoś super inteligentny ze względu 
 * na ograniczoną głębokość grafu, za to czasami potrafi zagrać całkiem niezłe ruchy.
 * Czasami może się zdarzyć, że bot dłużej popracuje, głównie wtedy, kiedy jest dużo dam,
 * ale zazwyczaj odpowiada do 3 sekund*/
#include <bits/stdc++.h>
#include "silnik.cpp"
using namespace std;
struct arr{
	int a, b, c, d, val;
};
struct ans{
	int a, b, c, d;
};
arr dfs(place plansza, int depth, int pkt){
	if(depth==5) return{0, 0, pkt};
	bool gracz=plansza.czyja_tura();
	arr odp;
	odp.val=-500*(int)gracz+100;
	for(int i=1;i<=8;i++){
		for(int j=1;j<=8;j++){
			for(int k=1;k<=8;k++){
				for(int l=1;l<=8;l++){
					place pom=plansza;
					int pm=pom.ruch_gracza(true, i, j, k, l, false);
					arr cp;
					if(!pm) continue;
					else if(pm==-1){
						if(gracz==0) cp={i, j, k, l, 300};
						else cp={i, j, k, l, -300};
					}
					else if(pm==1){
						cp=dfs(pom, depth+1, pkt);
					}
					else{
						int mn=1;
						if(pom.kto_zbity) mn=3;//dama czy pion, dama jest więcej warta
						if(gracz==0) cp=dfs(pom, depth+1, pkt-mn);
						else cp=dfs(pom, depth+1, pkt+mn);
					}
					if(gracz&&cp.val>odp.val){
						odp.a=i;
						odp.b=j,
						odp.c=k;
						odp.d=l;
						odp.val=cp.val;
					}
					else if(!gracz&&cp.val<odp.val){
						odp.a=i;
						odp.b=j,
						odp.c=k;
						odp.d=l;
						odp.val=cp.val;
					}
				}
			}
		}
	}
	return odp;
}
ans bot(place plansza){
	arr res=dfs(plansza, 0, 0);
	return{res.a, res.b, res.c, res.d};
}
