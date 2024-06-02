//Autor: Wiktor Lewicki
/*
 * bot gra dobrze, głębokość sprawdzanego grafu to 4
 * odpowiada zazwyczaj do 3 sekund, przy damach nie widziałem żeby zwalniał, aczkolwiek
 * napewno graf będzie dużo większy
 * */
#include <bits/stdc++.h>
#include "silnik.cpp"
using namespace std;
struct arr{
	int a, b, c, d, val;
};
struct ans{
	int a, b, c, d;
};

const int MAX_DEPTH=8;
const int INF=500;
arr dfs(place plansza, int depth, int pkt, int alpha, int beta){
	if(depth==MAX_DEPTH) return{0, 0, 0, 0, pkt};
	bool gracz=plansza.czyja_tura();
	arr odp;
	odp.val=INF;
	if(gracz) odp.val=-INF;
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
					else cp=dfs(pom, depth+1, pom.ocena(), alpha, beta);
					if(gracz&&cp.val>odp.val){
						alpha=cp.val;
						odp.a=i;
						odp.b=j,
						odp.c=k;
						odp.d=l;
						odp.val=cp.val;
					}
					else if(!gracz&&cp.val<odp.val){
						beta=cp.val;
						odp.a=i;
						odp.b=j,
						odp.c=k;
						odp.d=l;
						odp.val=cp.val;
					}
					if(beta<=alpha){
						return odp;
					}
				}
			}
		}
	}
	return odp;
}
ans bot(place plansza){
	arr res=dfs(plansza, 0, plansza.ocena(), -INF, INF);
	return{res.a, res.b, res.c, res.d};
}
