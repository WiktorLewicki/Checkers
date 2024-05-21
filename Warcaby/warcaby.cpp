/*UWAGA!
 * Jest to dopiero szkielet projektu w trakcie budowy
 *	Projekt jest w trakcie tworzenia. 
 * Aktualnie jest to końcowy etap kodu potrzebnego do obsługi zdarzeń na planszy,
 * może zawierać błędy
 * Jedyną możliwością na ten moment jest zagranie na "dwie osoby" poprzez podawanie współrzędnych kwadratów aby zaznaczyc pionek
 * a następnie podanie pola docelowego
 * Gra na przestrzeni ok. 2-3 dni zostanie rozwinięta w następujący sposób:
 * Wszystkie błędy zostaną usunięte oraz program zostanie przepisany w dużo bardziej czytelny, miły dla oka sposób
 * Graczem 2 będzie przeciwnik czyli bot który będzie rozważał graf możliwości ruchów z określoną głębokością
 * Możliwe że zostanie też wprowadzony interfejs graficzny, co znacznie ułatwi sterowność programu
 * Powyższe zmiany zostaną wykonane najprawdopodobniej do końca tego tygodnia
 * Pozdrawiam
 * UWAGA!
 * */
#include <bits/stdc++.h>
using namespace std;
int tura, bierki[2];
int last1, last2;
bool gd(int az, int bz){
	if(az<0||bz<0||az>8||bz>8) return false;
	return true;
}
class place;
vector<place> history;
class place{
	public:
	int p[9][9];
	void print(bool ppp=true){
		if(ppp)system("cls");
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
	void init(){
		for(int i=1;i<=8;i++){
			for(int j=1;j<=8;j++) p[i][j]=5;
		}
		p[1][2]=p[1][4]=p[1][6]=p[1][8]=1;
		p[2][1]=p[2][3]=p[2][5]=p[2][7]=1;
		p[3][2]=p[3][4]=p[3][6]=p[3][8]=1;
		
		p[6][1]=p[6][3]=p[6][5]=p[6][7]=0;
		p[7][2]=p[7][4]=p[7][6]=p[7][8]=0;
		p[8][1]=p[8][3]=p[8][5]=p[8][7]=0;
		
		tura=0;
		bierki[0]=bierki[1]=12;
		
		
	}
	void czy_ruch(bool gracz){
		for(int i=1;i<=8;i++){
			for(int j=1;j<=8;j++){
				//
			}
		}
	}
	bool chk(int i, int j, bool gracz){
		if(p[i][j]==gracz+3){
			int pl1=i+1, pl2=j+1, fs=0;
			while(gd(pl1, pl2)){
				if(fs){
					if(p[pl1][pl2]==5) return true;
					break;
				}
				if(comp(pl1, pl2, gracz)) break;
				if(comp(pl1, pl2, !gracz)) fs=1;
				pl1++, pl2++;
			}
			pl1=i+1, pl2=j-1, fs=0;
			while(gd(pl1, pl2)){
				if(fs){
					if(p[pl1][pl2]==5) return true;
					break;
				}
				if(comp(pl1, pl2, gracz)) break;
				if(comp(pl1, pl2, !gracz)) fs=1;
				pl1++, pl2--;
			}
			pl1=i-1, pl2=j+1, fs=0;
			while(gd(pl1, pl2)){
				if(fs){
					if(p[pl1][pl2]==5) return true;
					break;
				}
				if(comp(pl1, pl2, gracz)) break;
				if(comp(pl1, pl2, !gracz)) fs=1;
				pl1--, pl2++;
			}
			pl1=i-1, pl2=j-1, fs=0;
			while(gd(pl1, pl2)){
				if(fs){
					if(p[pl1][pl2]==5) return true;
					break;
				}
				if(comp(pl1, pl2, gracz)) break;
				if(comp(pl1, pl2, !gracz)) fs=1;
				pl1--, pl2--;
			}
			return false;
		}
		if(gd(i-2, j-2)&&p[i-1][j-1]==!gracz&&p[i-2][j-2]==5) return true;
		if(gd(i+2, j-2)&&p[i+1][j-1]==!gracz&&p[i+2][j-2]==5) return true;
		if(gd(i-2, j+2)&&p[i-1][j+1]==!gracz&&p[i-2][j+2]==5) return true;
		if(gd(i+2, j+2)&&p[i+1][j+1]==!gracz&&p[i+2][j+2]==5) return true;
		return false;
	}
	bool comp(int a, int b, bool gracz){
		if(gracz==0){
			if(p[a][b]==0||p[a][b]==3) return true;
			return false;
		}
		else{
			if(p[a][b]==1||p[a][b]==4) return true;
			return false;
		}
	}
	bool scanner(bool gracz){
		for(int i=1;i<=8;i++){
			for(int j=1;j<=8;j++){
				if(comp(i, j, gracz)&&chk(i, j, gracz)) return true;
			}
		}
		return false;
	}
	////////////////////////////////////////////////
	void dama(int a, int b, bool gracz){
		if(gracz==0&&p[a][b]==0&&a==1){
			p[a][b]=3;
		}
		if(gracz==1&&p[a][b]==1&&a==8){
			p[a][b]=4;
		}
	}
	void move(int a, int b, int c, int d, bool gracz){
		p[c][d]=p[a][b];
		p[a][b]=5;
		if(p[c][d]<2) dama(c, d, gracz);
		last1=c, last2=d;
	}
	int ruch_gracza(bool gracz){
		if(gracz==0) cout<<"rusza sie gracz 1\n";
		else cout<<"rusza sie gracz 2\n";
		int a, b, c, d;
		cout<<"Zaznacz pionka ktorym chcesz ruszyc\n";
		cin>>a>>b;
		if(last1){
			if(a!=last1||b!=last2){
				print();
				cout<<"Musisz kontynuowac bicie tym pionkiem ktorym sie ruszyles, pole: "<<last1<<" "<<last2<<"\n";
				return 0;
			}
		}
		if(a==0&&b==0){
			for(auto v : history){
				v.print(0);
				cout<<"\n";
			}
			exit(0);
		}
		if(a<1||b<1||a>8||b>8){
			print();
			cout<<"Nieprawidlowe dane\n";
			return 0;
		}
		if(!comp(a, b, gracz)){
			print();
			cout<<"Tu nie ma twojego pionka\n";
			return 0;
		}
		cout<<"Podaj pole na ktorym chcesz postawic tego pionka\n";
		cin>>c>>d;
		if(c<1||d<1||c>8||d>8){
			print();
			cout<<"Nieprawidlowe dane\n";
			return 0;
		}
		if(p[c][d]!=5){
			print();
			cout<<"Na tym polu stoi inny pionek\n";
			return 0;
		}
		bool oblig = scanner(gracz);
		if(p[a][b]==3||p[a][b]==4){//////////////////////////////////////////////
			int znak1=c-a, znak2=d-b;
			if(abs(znak1)!=abs(znak2)){
				print();
				cout<<"Nie mozesz zrobic takiego ruchu za pomoca damy1\n";
				return 0;
			}
			if(znak1<0&&znak2<0){
				int pn1=0, pn2=0;
				int msc1=a-1, msc2=b-1;
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
					msc1--, msc2--;
				}
				if(pn1==-1){
					print();
					cout<<"Nie mozesz zrobic takiego ruchu za pomoca damy2\n";
					return 0;
				}
				else{
					if(pn1){
						p[pn1][pn2]=5;
						bierki[!gracz]--;
					}
					else if(oblig){
						print();
						cout<<"Musisz wykonac bicie\n";
						return 0;
					}
					move(a, b, c, d, gracz);
					print();
					if(pn1) return 2;
					else return 1;
				}
			}
			else if(znak1<0&&znak2>0){
				int pn1=0, pn2=0;
				int msc1=a-1, msc2=b+1;
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
					msc1--, msc2++;
				}
				if(pn1==-1){
					print();
					cout<<"Nie mozesz zrobic takiego ruchu za pomoca damy3\n";
					return 0;
				}
				else{
					if(pn1){
						p[pn1][pn2]=5;
						bierki[!gracz]--;
					}
					else if(oblig){
						print();
						cout<<"Musisz wykonac bicie\n";
						return 0;
					}
					move(a, b, c, d, gracz);
					print();
					if(pn1) return 2;
					else return 1;
				}
			}
			else if(znak1>0&&znak2<0){
				int pn1=0, pn2=0;
				int msc1=a+1, msc2=b-1;
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
					msc1++, msc2--;
				}
				if(pn1==-1){
					print();
					cout<<"Nie mozesz zrobic takiego ruchu za pomoca damy4\n";
					return 0;
				}
				else{
					if(pn1){
						p[pn1][pn2]=5;
						bierki[!gracz]--;
					}
					else if(oblig){
						print();
						cout<<"Musisz wykonac bicie\n";
						return 0;
					}
					move(a, b, c, d, gracz);
					print();
					if(pn1) return 2;
					else return 1;
				}
			}
			else{
				int pn1=0, pn2=0;
				int msc1=a+1, msc2=b+1;
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
					msc1++, msc2++;
				}
				if(pn1==-1){
					print();
					cout<<"Nie mozesz zrobic takiego ruchu za pomoca damy5\n";
					return 0;
				}
				else{
					if(pn1){
						p[pn1][pn2]=5;
						bierki[!gracz]--;
					}
					else if(oblig){
						print();
						cout<<"Musisz wykonac bicie\n";
						return 0;
					}
					move(a, b, c, d, gracz);
					print();
					if(pn1) return 2;
					else return 1;
				}
			}
		}//////////////////////////////////////////////////////////
		int dr=1;
		if(gracz==1) dr=-1;
		if((c==a-2*dr&&d==b-2)||(c==a-2*dr&&d==b+2)){
			if(c==a-2*dr&&d==b-2){
				if(comp(a-1*dr, b-1, !gracz)){
					move(a, b, a-2*dr, b-2, gracz);
					p[a-1*dr][b-1]=5;
					print();
					return 2;
				}
				else{
					print();
					cout<<"Nie mozesz zrobic takiego ruchu1\n";
					return 0;
				}
			}
			else{
				if(comp(a-1*dr, b+1, !gracz)){
					move(a, b, a-2*dr, b+2, gracz);
					p[a-1*dr][b+1]=5;
					print();
					return 2;
				}
				else{
					print();
					cout<<"Nie mozesz zrobic takiego ruchu2\n";
					return 0;
				}
			}
		}
		if(oblig){
			dr=-dr;
			if((c==a-2*dr&&d==b-2)||(c==a-2*dr&&d==b+2)){
				if(c==a-2*dr&&d==b-2){
					if(comp(a-1*dr, b-1, !gracz)){
						move(a, b, a-2*dr, b-2, gracz);
						p[a-1*dr][b-1]=5;
						print();
						return 2;
					}
					else{
						print();
						cout<<"Nie mozesz zrobic takiego ruchu1\n";
						return 0;
					}
				}
				else{
					if(comp(a-1*dr, b+1, !gracz)){
						move(a, b, a-2*dr, b+2, gracz);
						p[a-1*dr][b+1]=5;
						print();
						return 2;
					}
					else{
						print();
						cout<<"Nie mozesz zrobic takiego ruchu2\n";
						return 0;
					}
				}
			}
			print();
			cout<<"Musisz wykonac bicie\n";
			return 0;
		}
		dr=1;
		if(gracz==1) dr=-1;
		if(!((c==a-1*dr&&d==b-1)||(c==a-1*dr&&d==b+1))){ 
			print();
			cout<<"Nie mozesz zrobic takiego ruchu3\n";
			return 0;
		}
		else{
			move(a, b, c, d, gracz);
			print();
			return 1;
		}
	}///////////////////////////////////////////////////
};
int main(){
	place plansza;
	plansza.init();
	plansza.print();
	while(1){
		int pm=plansza.ruch_gracza(tura);
		history.push_back(plansza);
		if(pm){
			if(bierki[0]==0){
				cout<<"Wygral gracz 2\n";
				return 0;
			}
			if(bierki[1]==0){
				cout<<"Wygral gracz 1\n";
				return 0;
			}
			if(!(pm==2&&plansza.chk(last1, last2, tura))){
				tura=!tura;
				last1=0, last2=0;
			}
		}
	}
	return 0;
}
