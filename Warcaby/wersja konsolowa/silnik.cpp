//Autor: Wiktor Lewicki
#include <bits/stdc++.h>
using namespace std;
class place{
	public:
	int p[9][9];
	int last1, last2;
	int stan;
	bool tura;
	bool who, read;
	bool kto_zbity;
	void print(){//czytanie planszy
		if(!read) return;
		system("cls");
		cout<<"  ";
		for(int i=1;i<=8;i++){
			cout<<"  "<<i<<" ";
		}
		cout<<"\n";
		string pm="  +---+---+---+---+---+---+---+---+\n";
		for(int i=1;i<=8;i++){
			cout<<pm;
			cout<<i<<" ";
			for(int j=1;j<=8;j++){
				if(p[i][j]==5) cout<<"| "<<" "<<" ";
				else if(p[i][j]==1) cout<<"| "<<"@"<<" ";
				else if(p[i][j]==0) cout<<"| "<<"#"<<" ";
				else if(p[i][j]==3) cout<<"| "<<"M"<<" ";
				else cout<<"| "<<"W"<<" ";
			}
			cout<<"|\n";
		}
		cout<<pm;
	}
	void init(){//inicjalizacja planszy
		for(int i=1;i<=8;i++){
			for(int j=1;j<=8;j++){
				p[i][j]=5;
			}
		}
		p[1][2]=p[1][4]=p[1][6]=p[1][8]=1;
		p[2][1]=p[2][3]=p[2][5]=p[2][7]=1;
		p[3][2]=p[3][4]=p[3][6]=p[3][8]=1;
	
		p[6][1]=p[6][3]=p[6][5]=p[6][7]=0;
		p[7][2]=p[7][4]=p[7][6]=p[7][8]=0;
		p[8][1]=p[8][3]=p[8][5]=p[8][7]=0;
		
		last1=0;
		last2=0; 
		tura=false;
		stan=0;
		who=false;
		read=true;
		kto_zbity=false;
		print();
	}
	bool gd(int az, int bz){//sprawdzanie czy pole poza planszą
		if(az<0||bz<0||az>8||bz>8) return false;
		return true;
	}
	bool comp(int a, int b, bool gracz){//sprawdzanie czy bierka nalezy do gracza
		if(gracz==0){
			if(p[a][b]==0||p[a][b]==3) return true;
			return false;
		}
		else{
			if(p[a][b]==1||p[a][b]==4) return true;
			return false;
		}
	}
	void bicie(int mv1, int mv2){//zbita dama czy pion
		if(p[mv1][mv2]<2) kto_zbity=false;
		else kto_zbity=true;
		p[mv1][mv2]=5;
	}
	bool chk_dama(int i, int j, int r1, int r2, bool gracz){//sprawdzanie czy dana dama może coś zbić
		int pl1=i+r1, pl2=j+r2, fs=0;
		while(gd(pl1, pl2)){
			if(fs&&p[pl1][pl2]==5) return true;
			else if(fs) return false;
			if(comp(pl1, pl2, gracz)) return false;
			if(comp(pl1, pl2, !gracz)) fs=1;
			pl1+=r1, pl2+=r2;
		}
		return false;
	}
	bool chk(int i, int j, bool gracz){//sprawdzanie czy dany bierek może coś zbić
		if(p[i][j]==gracz+3){
			if(chk_dama(i, j, -1, -1, gracz)) return true;
			if(chk_dama(i, j, -1, 1, gracz)) return true;
			if(chk_dama(i, j, 1, -1, gracz)) return true;
			if(chk_dama(i, j, 1, 1, gracz)) return true;
			return false;
		}
		if(gd(i-2, j-2)&&comp(i-1, j-1, !gracz)&&p[i-2][j-2]==5) return true;
		if(gd(i+2, j-2)&&comp(i+1, j-1, !gracz)&&p[i+2][j-2]==5) return true;
		if(gd(i-2, j+2)&&comp(i-1, j+1, !gracz)&&p[i-2][j+2]==5) return true;
		if(gd(i+2, j+2)&&comp(i+1, j+1, !gracz)&&p[i+2][j+2]==5) return true;
		return false;
	}
	bool czy_ruch_pionkiem_bez_bicia(int a, int b, int c, int d, bool gracz){//czy coś sie ruszy bez bicia
		if(!gd(c, d)) return false;
		if(p[c][d]!=5) return false;
		int dr=1;
		if(gracz==1) dr=-1;
		if((c==a-1*dr&&d==b-1)||(c==a-1*dr&&d==b+1)){
			return true;
		}
		return false;
	}
	bool czy_koniec(){//sprawdzanie czy gracz może zrobić ruch
		for(int i=1;i<=8;i++){
			for(int j=1;j<=8;j++){
				if(!comp(i, j, tura)) continue;
				if(p[i][j]==3||p[i][j]==4){
					if(gd(i-1, j-1)&&p[i-1][j-1]==5) return false;
					if(gd(i-1, j+1)&&p[i-1][j+1]==5) return false;
					if(gd(i+1, j-1)&&p[i+1][j-1]==5) return false;
					if(gd(i+1, j+1)&&p[i+1][j+1]==5) return false;
				}
				if(chk(i, j, tura)) return false;
				if(czy_ruch_pionkiem_bez_bicia(i, j, i-1, j-1, tura)) return false;
				if(czy_ruch_pionkiem_bez_bicia(i, j, i-1, j+1, tura)) return false;
				if(czy_ruch_pionkiem_bez_bicia(i, j, i+1, j-1, tura)) return false;
				if(czy_ruch_pionkiem_bez_bicia(i, j, i+1, j+1, tura)) return false;
			}
		}
		return true;
	}
	bool scanner(bool gracz){//sprawdzanie czy jest wymuszane bicie
		for(int i=1;i<=8;i++){
			for(int j=1;j<=8;j++){
				if(comp(i, j, gracz)&&chk(i, j, gracz)) return true;
			}
		}
		return false;
	}
	
	void dama(int a, int b, bool gracz){//sprawdzanie zamiany na dame
		if(gracz==0&&p[a][b]==0&&a==1){
			p[a][b]=3;
		}
		if(gracz==1&&p[a][b]==1&&a==8){
			p[a][b]=4;
		}
	}
	
	void move(int a, int b, int c, int d, bool gracz){//ruch bierkiem
		p[c][d]=p[a][b];
		p[a][b]=5;
		if(p[c][d]<2) dama(c, d, gracz);
		last1=c, last2=d;
	}
	int dama_ruch(int a, int b, int c, int d, int r1, int r2, bool gracz, bool oblig){//ruch damą
		int pn1=0, pn2=0;
		int msc1=a+r1, msc2=b+r2;
		while(gd(msc1, msc2)&&msc1!=c&&msc2!=d){
			if(comp(msc1, msc2, gracz)){
				pn1=-1, pn2=-1;
				break;
			}
			if(comp(msc1, msc2, !gracz)){
				if(pn1){
					pn1=-1, pn2=-1;
					break;
				}
				pn1=msc1;
				pn2=msc2;
			}
			msc1+=r1, msc2+=r2;
		}
		if(pn1==-1){
			print();
			if(read) cout<<"Nie mozesz zrobic takiego ruchu za pomoca damy\n";
			stan=0;
			return 0;
		}
		else{
			if(pn1) bicie(pn1, pn2);
			else if(oblig){
				print();
				if(read) cout<<"Musisz wykonac bicie\n";
				stan=0;
				return 0;
			}
			move(a, b, c, d, gracz);
			print();
			if(pn1){
				stan=2;
				return 2;
			}
			else{
				stan=1;
				return 1;
			}
		}
	}
	bool czyja_tura(){//kogo ruch
		if(stan==0) return tura;
		if(!(stan==2&&chk(last1, last2, tura))){
			return !tura;
		}
		return tura;
	}
	bool cont(){//zmiana tury i rozgryzwka
		if(stan==0) return false;
		if(!(stan==2&&chk(last1, last2, tura))){
			tura=!tura;
			last1=0, last2=0;
		}
		if(czy_koniec()){
			if(tura==0&&read) cout<<"Wygral gracz 2!\n"; 
			else if(read) cout<<"Wygral gracz 1!\n";
			return true;
		}
		return false;
	}
	int ruch_gracza(bool bt=false, int m1=0, int m2=0, int m3=0, int m4=0, bool show=true){//ruch
		who=bt;
		read=show;
		if(cont()) return -1;
		bool gracz=tura;
		if(gracz==0&&read) cout<<"rusza sie gracz 1\n";
		else if(read) cout<<"rusza sie gracz 2\n";
		int a, b, c, d;
		if(read) cout<<"Zaznacz pionka ktorym chcesz ruszyc\n";
		if(!who) cin>>a>>b;
		else a=m1, b=m2;
		if(last1&&last2){//kontynuowanie bicia
			if(a!=last1||b!=last2){
				print();
				if(read) cout<<"Musisz kontynuowac bicie tym pionkiem ktorym sie ruszyles, pole: "<<last1<<" "<<last2<<"\n";
				stan=0;
				return 0;
			}
		}
		if(!gd(a, b)){//sprawdzanie czy poza planszą
			print();
			if(read) cout<<"Nieprawidlowe dane\n";
			stan=0;
			return 0;
		}
		if(!comp(a, b, gracz)){//sprawdzanie czy na polu jest bierek gracza
			print();
			if(read) cout<<"Tu nie ma twojego pionka\n";
			stan=0;
			return 0;
		}
		if(read) cout<<"Podaj pole na ktorym chcesz postawic tego pionka\n";
		if(!who) cin>>c>>d;
		else c=m3, d=m4;
		if(!gd(c, d)){//sprawdzanie czy poza planszą
			print();
			if(read) cout<<"Nieprawidlowe dane\n";
			stan=0;
			return 0;
		}
		if(p[c][d]!=5){//sprawdzanie czy pole puste
			print();
			if(read) cout<<"Na tym polu stoi inny pionek\n";
			stan=0;
			return 0;
		}
		bool oblig = scanner(gracz);//czy wymuszone bicie
		if(p[a][b]==3||p[a][b]==4){// ruch damą
			int znak1=c-a, znak2=d-b;
			if(abs(znak1)!=abs(znak2)){
				print();
				if(read) cout<<"Nie mozesz zrobic takiego ruchu za pomoca damy\n";
				stan=0;
				return 0;
			}
			if(znak1<0&&znak2<0){
				int rrr=dama_ruch(a, b, c, d, -1, -1, gracz, oblig);
				stan=rrr;
				return rrr;
			}
			else if(znak1<0&&znak2>0){
				int rrr=dama_ruch(a, b, c, d, -1, 1, gracz, oblig);
				stan=rrr;
				return rrr;
			}
			else if(znak1>0&&znak2<0){
				int rrr=dama_ruch(a, b, c, d, 1, -1, gracz, oblig);
				stan=rrr;
				return rrr;
			}
			else{
				int rrr=dama_ruch(a, b, c, d, 1, 1, gracz, oblig);
				stan=rrr;
				return rrr;
			}
		}
		
		int dr=1;
		if(gracz==1) dr=-1;
		if((c==a-2*dr&&d==b-2)||(c==a-2*dr&&d==b+2)){//bicie pionkiem
			if(c==a-2*dr&&d==b-2){
				if(comp(a-1*dr, b-1, !gracz)){
					move(a, b, a-2*dr, b-2, gracz);
					bicie(a-1*dr, b-1);
					print();
					stan=2;
					return 2;
				}
				else{
					print();
					if(read) cout<<"Nie mozesz zrobic takiego ruchu\n";
					stan=0;
					return 0;
				}
			}
			else{
				if(comp(a-1*dr, b+1, !gracz)){
					move(a, b, a-2*dr, b+2, gracz);
					bicie(a-1*dr, b+1);
					print();
					stan=2;
					return 2;
				}
				else{
					print();
					if(read) cout<<"Nie mozesz zrobic takiego ruchu\n";
					stan=0;
					return 0;
				}
			}
		}
		if(oblig){//wymuszenie bicia pionkiem
			dr=-dr;
			if((c==a-2*dr&&d==b-2)||(c==a-2*dr&&d==b+2)){
				if(c==a-2*dr&&d==b-2){
					if(comp(a-1*dr, b-1, !gracz)){
						move(a, b, a-2*dr, b-2, gracz);
						bicie(a-1*dr, b-1);
						print();
						stan=2;
						return 2;
					}
					else{
						print();
						if(read) cout<<"Nie mozesz zrobic takiego ruchu\n";
						stan=0;
						return 0;
					}
				}
				else{
					if(comp(a-1*dr, b+1, !gracz)){
						move(a, b, a-2*dr, b+2, gracz);
						bicie(a-1*dr, b+1);
						print();
						stan=2;
						return 2;
					}
					else{
						print();
						if(read) cout<<"Nie mozesz zrobic takiego ruchu\n";
						stan=0;
						return 0;
					}
				}
			}
			print();
			if(read) cout<<"Musisz wykonac bicie\n";
			stan=0;
			return 0;
		}
		dr=1;
		if(gracz==1) dr=-1;
		if(!czy_ruch_pionkiem_bez_bicia(a, b, c, d, gracz)){ //ruch pionkiem
			print();
			if(read) cout<<"Nie mozesz zrobic takiego ruchu\n";
			stan=0;
			return 0;
		}
		else{
			move(a, b, c, d, gracz);
			print();
			stan=1;
			return 1;
		}
	}
};
