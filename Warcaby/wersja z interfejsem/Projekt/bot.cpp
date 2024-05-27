//Autor: Wiktor Lewicki
/*
 * bot gra dobrze, g³êbokoœæ sprawdzanego grafu to 4
 * odpowiada zazwyczaj do 3 sekund, przy damach nie widzia³em ¿eby zwalnia³, aczkolwiek
 * napewno graf mo¿liwoœci bêdzie du¿o wiêkszy
 * */
#include "silnik.cpp"
using namespace std;
struct arr{
	int a, b, c, d, val;
};
struct ans{
	int a, b, c, d;
};
arr dfs(place plansza, int depth, int pkt){
	if(depth==5){
                arr rs={0, 0, 0, 0, pkt};
                return rs;
        }
	bool gracz=plansza.czyja_tura();
	arr odp;
	odp.val=500;
	if(gracz) odp.val=-500;
	for(int i=1;i<=8;i++){
		for(int j=1;j<=8;j++){
			for(int k=1;k<=8;k++){
				for(int l=1;l<=8;l++){
					place pom=plansza;
					int pm=pom.ruch_gracza(i, j, k, l);
					arr cp;
					if(!pm) continue;
					else if(pm==-1){
						if(gracz==0){
                                                        arr rs={i, j, k, l, 300};
                                                        cp=rs;
                                                }
						else{
                                                        arr rs={i, j, k, l, 300};
                                                        cp=rs;
                                                }
					}
					else if(pm==1){
						cp=dfs(pom, depth+1, pkt);
					}
					else{
						int mn=1;
						if(pom.kto_zbity) mn=3;//dama czy pion, dama jest wiÄ™cej warta
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
        ans res_pm={res.a, res.b, res.c, res.d};
	return res_pm;
}
