//---------------------------------------------------------------------------
//autor: Wiktor Lewicki
//  W przeci¹gu kilku dni kod zostanie poprawiony na du¿o bardziej czytelny
#include <vcl.h>
#include <windows.h>
#pragma hdrstop

#include "warcaby.h"
#include "bot.cpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
using namespace std;
int z1, z2, z3, z4;
place gra;
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::end(){
        char *cstr;
        if(gra.czyja_tura()==0) cstr = "Przegraleœ!";
        else cstr = "Wygra³eœ!";
        Application->MessageBox(cstr, "Koniec", MB_OK);
        Application->Terminate();
}
void __fastcall TForm1::ruch(){
	int pm=0;
	if(gra.czyja_tura()==0){
		pm=gra.ruch_gracza(z1, z2, z3, z4);
                if(!pm){
                        char *cstr = "Z£Y RUCH!";
                        Application->MessageBox(cstr, "B³¹d", MB_OK);
                }
                refresh();
                z1=z2=z3=z4=0;
	}
	if(gra.cont()) end();
	while(gra.czyja_tura()==1&&pm!=-1){
                Label1->Caption="Tura bota   ";
                blok(0);
                Application->ProcessMessages();
                Sleep(1);
		ans zz=bot(gra);
                Sleep(400);
                z1=zz.a, z2=zz.b, z3=zz.c, z4=zz.d;
		pm=gra.ruch_gracza(z1, z2, z3, z4);
                refresh();
                z1=z2=z3=z4=0;
	}
        blok(1);
	if(gra.cont()) end();
        Label1->Caption="Twoja Tura";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
        pole11->Picture->LoadFromFile("img/b.bmp");
        pole12->Picture->LoadFromFile("img/black_p.bmp");
        pole13->Picture->LoadFromFile("img/b.bmp");
        pole14->Picture->LoadFromFile("img/black_p.bmp");
        pole15->Picture->LoadFromFile("img/b.bmp");
        pole16->Picture->LoadFromFile("img/black_p.bmp");
        pole17->Picture->LoadFromFile("img/b.bmp");
        pole18->Picture->LoadFromFile("img/black_p.bmp");
        pole21->Picture->LoadFromFile("img/black_p.bmp");
        pole22->Picture->LoadFromFile("img/b.bmp");
        pole23->Picture->LoadFromFile("img/black_p.bmp");
        pole24->Picture->LoadFromFile("img/b.bmp");
        pole25->Picture->LoadFromFile("img/black_p.bmp");
        pole26->Picture->LoadFromFile("img/b.bmp");
        pole27->Picture->LoadFromFile("img/black_p.bmp");
        pole28->Picture->LoadFromFile("img/b.bmp");
        pole31->Picture->LoadFromFile("img/b.bmp");
        pole32->Picture->LoadFromFile("img/black_p.bmp");
        pole33->Picture->LoadFromFile("img/b.bmp");
        pole34->Picture->LoadFromFile("img/black_p.bmp");
        pole35->Picture->LoadFromFile("img/b.bmp");
        pole36->Picture->LoadFromFile("img/black_p.bmp");
        pole37->Picture->LoadFromFile("img/b.bmp");
        pole38->Picture->LoadFromFile("img/black_p.bmp");
        pole41->Picture->LoadFromFile("img/c.bmp");
        pole42->Picture->LoadFromFile("img/b.bmp");
        pole43->Picture->LoadFromFile("img/c.bmp");
        pole44->Picture->LoadFromFile("img/b.bmp");
        pole45->Picture->LoadFromFile("img/c.bmp");
        pole46->Picture->LoadFromFile("img/b.bmp");
        pole47->Picture->LoadFromFile("img/c.bmp");
        pole48->Picture->LoadFromFile("img/b.bmp");

        pole51->Picture->LoadFromFile("img/b.bmp");
        pole52->Picture->LoadFromFile("img/c.bmp");
        pole53->Picture->LoadFromFile("img/b.bmp");
        pole54->Picture->LoadFromFile("img/c.bmp");
        pole55->Picture->LoadFromFile("img/b.bmp");
        pole56->Picture->LoadFromFile("img/c.bmp");
        pole57->Picture->LoadFromFile("img/b.bmp");
        pole58->Picture->LoadFromFile("img/c.bmp");
        pole61->Picture->LoadFromFile("img/white_p.bmp");
        pole62->Picture->LoadFromFile("img/b.bmp");
        pole63->Picture->LoadFromFile("img/white_p.bmp");
        pole64->Picture->LoadFromFile("img/b.bmp");
        pole65->Picture->LoadFromFile("img/white_p.bmp");
        pole66->Picture->LoadFromFile("img/b.bmp");
        pole67->Picture->LoadFromFile("img/white_p.bmp");
        pole68->Picture->LoadFromFile("img/b.bmp");
        pole71->Picture->LoadFromFile("img/b.bmp");
        pole72->Picture->LoadFromFile("img/white_p.bmp");
        pole73->Picture->LoadFromFile("img/b.bmp");
        pole74->Picture->LoadFromFile("img/white_p.bmp");
        pole75->Picture->LoadFromFile("img/b.bmp");
        pole76->Picture->LoadFromFile("img/white_p.bmp");
        pole77->Picture->LoadFromFile("img/b.bmp");
        pole78->Picture->LoadFromFile("img/white_p.bmp");
        pole81->Picture->LoadFromFile("img/white_p.bmp");
        pole82->Picture->LoadFromFile("img/b.bmp");
        pole83->Picture->LoadFromFile("img/white_p.bmp");
        pole84->Picture->LoadFromFile("img/b.bmp");
        pole85->Picture->LoadFromFile("img/white_p.bmp");
        pole86->Picture->LoadFromFile("img/b.bmp");
        pole87->Picture->LoadFromFile("img/white_p.bmp");
        pole88->Picture->LoadFromFile("img/b.bmp");
        gra.init();
}
void __fastcall TForm1::refresh(){
        if(gra.p[1][2]==0) pole12->Picture->LoadFromFile("img/white_p.bmp");
        else if(gra.p[1][2]==1) pole12->Picture->LoadFromFile("img/black_p.bmp");
        else if(gra.p[1][2]==3) pole12->Picture->LoadFromFile("img/white_d.bmp");
        else if(gra.p[1][2]==4) pole12->Picture->LoadFromFile("img/black_d.bmp");
        else pole12->Picture->LoadFromFile("img/c.bmp");
        if(gra.p[1][4]==0) pole14->Picture->LoadFromFile("img/white_p.bmp");
        else if(gra.p[1][4]==1) pole14->Picture->LoadFromFile("img/black_p.bmp");
        else if(gra.p[1][4]==3) pole14->Picture->LoadFromFile("img/white_d.bmp");
        else if(gra.p[1][4]==4) pole14->Picture->LoadFromFile("img/black_d.bmp");
        else pole14->Picture->LoadFromFile("img/c.bmp");
        if(gra.p[1][6]==0) pole16->Picture->LoadFromFile("img/white_p.bmp");
        else if(gra.p[1][6]==1) pole16->Picture->LoadFromFile("img/black_p.bmp");
        else if(gra.p[1][6]==3) pole16->Picture->LoadFromFile("img/white_d.bmp");
        else if(gra.p[1][6]==4) pole16->Picture->LoadFromFile("img/black_d.bmp");
        else pole16->Picture->LoadFromFile("img/c.bmp");
        if(gra.p[1][8]==0) pole18->Picture->LoadFromFile("img/white_p.bmp");
        else if(gra.p[1][8]==1) pole18->Picture->LoadFromFile("img/black_p.bmp");
        else if(gra.p[1][8]==3) pole18->Picture->LoadFromFile("img/white_d.bmp");
        else if(gra.p[1][8]==4) pole18->Picture->LoadFromFile("img/black_d.bmp");
        else pole18->Picture->LoadFromFile("img/c.bmp");
        if(gra.p[2][1]==0) pole21->Picture->LoadFromFile("img/white_p.bmp");
        else if(gra.p[2][1]==1) pole21->Picture->LoadFromFile("img/black_p.bmp");
        else if(gra.p[2][1]==3) pole21->Picture->LoadFromFile("img/white_d.bmp");
        else if(gra.p[2][1]==4) pole21->Picture->LoadFromFile("img/black_d.bmp");
        else pole21->Picture->LoadFromFile("img/c.bmp");
        if(gra.p[2][3]==0) pole23->Picture->LoadFromFile("img/white_p.bmp");
        else if(gra.p[2][3]==1) pole23->Picture->LoadFromFile("img/black_p.bmp");
        else if(gra.p[2][3]==3) pole23->Picture->LoadFromFile("img/white_d.bmp");
        else if(gra.p[2][3]==4) pole23->Picture->LoadFromFile("img/black_d.bmp");
        else pole23->Picture->LoadFromFile("img/c.bmp");
        if(gra.p[2][5]==0) pole25->Picture->LoadFromFile("img/white_p.bmp");
        else if(gra.p[2][5]==1) pole25->Picture->LoadFromFile("img/black_p.bmp");
        else if(gra.p[2][5]==3) pole25->Picture->LoadFromFile("img/white_d.bmp");
        else if(gra.p[2][5]==4) pole25->Picture->LoadFromFile("img/black_d.bmp");
        else pole25->Picture->LoadFromFile("img/c.bmp");
        if(gra.p[2][7]==0) pole27->Picture->LoadFromFile("img/white_p.bmp");
        else if(gra.p[2][7]==1) pole27->Picture->LoadFromFile("img/black_p.bmp");
        else if(gra.p[2][7]==3) pole27->Picture->LoadFromFile("img/white_d.bmp");
        else if(gra.p[2][7]==4) pole27->Picture->LoadFromFile("img/black_d.bmp");
        else pole27->Picture->LoadFromFile("img/c.bmp");
        if(gra.p[3][2]==0) pole32->Picture->LoadFromFile("img/white_p.bmp");
        else if(gra.p[3][2]==1) pole32->Picture->LoadFromFile("img/black_p.bmp");
        else if(gra.p[3][2]==3) pole32->Picture->LoadFromFile("img/white_d.bmp");
        else if(gra.p[3][2]==4) pole32->Picture->LoadFromFile("img/black_d.bmp");
        else pole32->Picture->LoadFromFile("img/c.bmp");
        if(gra.p[3][4]==0) pole34->Picture->LoadFromFile("img/white_p.bmp");
        else if(gra.p[3][4]==1) pole34->Picture->LoadFromFile("img/black_p.bmp");
        else if(gra.p[3][4]==3) pole34->Picture->LoadFromFile("img/white_d.bmp");
        else if(gra.p[3][4]==4) pole34->Picture->LoadFromFile("img/black_d.bmp");
        else pole34->Picture->LoadFromFile("img/c.bmp");
        if(gra.p[3][6]==0) pole36->Picture->LoadFromFile("img/white_p.bmp");
        else if(gra.p[3][6]==1) pole36->Picture->LoadFromFile("img/black_p.bmp");
        else if(gra.p[3][6]==3) pole36->Picture->LoadFromFile("img/white_d.bmp");
        else if(gra.p[3][6]==4) pole36->Picture->LoadFromFile("img/black_d.bmp");
        else pole36->Picture->LoadFromFile("img/c.bmp");
        if(gra.p[3][8]==0) pole38->Picture->LoadFromFile("img/white_p.bmp");
        else if(gra.p[3][8]==1) pole38->Picture->LoadFromFile("img/black_p.bmp");
        else if(gra.p[3][8]==3) pole38->Picture->LoadFromFile("img/white_d.bmp");
        else if(gra.p[3][8]==4) pole38->Picture->LoadFromFile("img/black_d.bmp");
        else pole38->Picture->LoadFromFile("img/c.bmp");
        if(gra.p[4][1]==0) pole41->Picture->LoadFromFile("img/white_p.bmp");
        else if(gra.p[4][1]==1) pole41->Picture->LoadFromFile("img/black_p.bmp");
        else if(gra.p[4][1]==3) pole41->Picture->LoadFromFile("img/white_d.bmp");
        else if(gra.p[4][1]==4) pole41->Picture->LoadFromFile("img/black_d.bmp");
        else pole41->Picture->LoadFromFile("img/c.bmp");
        if(gra.p[4][3]==0) pole43->Picture->LoadFromFile("img/white_p.bmp");
        else if(gra.p[4][3]==1) pole43->Picture->LoadFromFile("img/black_p.bmp");
        else if(gra.p[4][3]==3) pole43->Picture->LoadFromFile("img/white_d.bmp");
        else if(gra.p[4][3]==4) pole43->Picture->LoadFromFile("img/black_d.bmp");
        else pole43->Picture->LoadFromFile("img/c.bmp");
        if(gra.p[4][5]==0) pole45->Picture->LoadFromFile("img/white_p.bmp");
        else if(gra.p[4][5]==1) pole45->Picture->LoadFromFile("img/black_p.bmp");
        else if(gra.p[4][5]==3) pole45->Picture->LoadFromFile("img/white_d.bmp");
        else if(gra.p[4][5]==4) pole45->Picture->LoadFromFile("img/black_d.bmp");
        else pole45->Picture->LoadFromFile("img/c.bmp");
        if(gra.p[4][7]==0) pole47->Picture->LoadFromFile("img/white_p.bmp");
        else if(gra.p[4][7]==1) pole47->Picture->LoadFromFile("img/black_p.bmp");
        else if(gra.p[4][7]==3) pole47->Picture->LoadFromFile("img/white_d.bmp");
        else if(gra.p[4][7]==4) pole47->Picture->LoadFromFile("img/black_d.bmp");
        else pole47->Picture->LoadFromFile("img/c.bmp");
        if(gra.p[5][2]==0) pole52->Picture->LoadFromFile("img/white_p.bmp");
        else if(gra.p[5][2]==1) pole52->Picture->LoadFromFile("img/black_p.bmp");
        else if(gra.p[5][2]==3) pole52->Picture->LoadFromFile("img/white_d.bmp");
        else if(gra.p[5][2]==4) pole52->Picture->LoadFromFile("img/black_d.bmp");
        else pole52->Picture->LoadFromFile("img/c.bmp");
        if(gra.p[5][4]==0) pole54->Picture->LoadFromFile("img/white_p.bmp");
        else if(gra.p[5][4]==1) pole54->Picture->LoadFromFile("img/black_p.bmp");
        else if(gra.p[5][4]==3) pole54->Picture->LoadFromFile("img/white_d.bmp");
        else if(gra.p[5][4]==4) pole54->Picture->LoadFromFile("img/black_d.bmp");
        else pole54->Picture->LoadFromFile("img/c.bmp");
        if(gra.p[5][6]==0) pole56->Picture->LoadFromFile("img/white_p.bmp");
        else if(gra.p[5][6]==1) pole56->Picture->LoadFromFile("img/black_p.bmp");
        else if(gra.p[5][6]==3) pole56->Picture->LoadFromFile("img/white_d.bmp");
        else if(gra.p[5][6]==4) pole56->Picture->LoadFromFile("img/black_d.bmp");
        else pole56->Picture->LoadFromFile("img/c.bmp");
        if(gra.p[5][8]==0) pole58->Picture->LoadFromFile("img/white_p.bmp");
        else if(gra.p[5][8]==1) pole58->Picture->LoadFromFile("img/black_p.bmp");
        else if(gra.p[5][8]==3) pole58->Picture->LoadFromFile("img/white_d.bmp");
        else if(gra.p[5][8]==4) pole58->Picture->LoadFromFile("img/black_d.bmp");
        else pole58->Picture->LoadFromFile("img/c.bmp");
        if(gra.p[6][1]==0) pole61->Picture->LoadFromFile("img/white_p.bmp");
        else if(gra.p[6][1]==1) pole61->Picture->LoadFromFile("img/black_p.bmp");
        else if(gra.p[6][1]==3) pole61->Picture->LoadFromFile("img/white_d.bmp");
        else if(gra.p[6][1]==4) pole61->Picture->LoadFromFile("img/black_d.bmp");
        else pole61->Picture->LoadFromFile("img/c.bmp");
        if(gra.p[6][3]==0) pole63->Picture->LoadFromFile("img/white_p.bmp");
        else if(gra.p[6][3]==1) pole63->Picture->LoadFromFile("img/black_p.bmp");
        else if(gra.p[6][3]==3) pole63->Picture->LoadFromFile("img/white_d.bmp");
        else if(gra.p[6][3]==4) pole63->Picture->LoadFromFile("img/black_d.bmp");
        else pole63->Picture->LoadFromFile("img/c.bmp");
        if(gra.p[6][5]==0) pole65->Picture->LoadFromFile("img/white_p.bmp");
        else if(gra.p[6][5]==1) pole65->Picture->LoadFromFile("img/black_p.bmp");
        else if(gra.p[6][5]==3) pole65->Picture->LoadFromFile("img/white_d.bmp");
        else if(gra.p[6][5]==4) pole65->Picture->LoadFromFile("img/black_d.bmp");
        else pole65->Picture->LoadFromFile("img/c.bmp");
        if(gra.p[6][7]==0) pole67->Picture->LoadFromFile("img/white_p.bmp");
        else if(gra.p[6][7]==1) pole67->Picture->LoadFromFile("img/black_p.bmp");
        else if(gra.p[6][7]==3) pole67->Picture->LoadFromFile("img/white_d.bmp");
        else if(gra.p[6][7]==4) pole67->Picture->LoadFromFile("img/black_d.bmp");
        else pole67->Picture->LoadFromFile("img/c.bmp");
        if(gra.p[7][2]==0) pole72->Picture->LoadFromFile("img/white_p.bmp");
        else if(gra.p[7][2]==1) pole72->Picture->LoadFromFile("img/black_p.bmp");
        else if(gra.p[7][2]==3) pole72->Picture->LoadFromFile("img/white_d.bmp");
        else if(gra.p[7][2]==4) pole72->Picture->LoadFromFile("img/black_d.bmp");
        else pole72->Picture->LoadFromFile("img/c.bmp");
        if(gra.p[7][4]==0) pole74->Picture->LoadFromFile("img/white_p.bmp");
        else if(gra.p[7][4]==1) pole74->Picture->LoadFromFile("img/black_p.bmp");
        else if(gra.p[7][4]==3) pole74->Picture->LoadFromFile("img/white_d.bmp");
        else if(gra.p[7][4]==4) pole74->Picture->LoadFromFile("img/black_d.bmp");
        else pole74->Picture->LoadFromFile("img/c.bmp");
        if(gra.p[7][6]==0) pole76->Picture->LoadFromFile("img/white_p.bmp");
        else if(gra.p[7][6]==1) pole76->Picture->LoadFromFile("img/black_p.bmp");
        else if(gra.p[7][6]==3) pole76->Picture->LoadFromFile("img/white_d.bmp");
        else if(gra.p[7][6]==4) pole76->Picture->LoadFromFile("img/black_d.bmp");
        else pole76->Picture->LoadFromFile("img/c.bmp");
        if(gra.p[7][8]==0) pole78->Picture->LoadFromFile("img/white_p.bmp");
        else if(gra.p[7][8]==1) pole78->Picture->LoadFromFile("img/black_p.bmp");
        else if(gra.p[7][8]==3) pole78->Picture->LoadFromFile("img/white_d.bmp");
        else if(gra.p[7][8]==4) pole78->Picture->LoadFromFile("img/black_d.bmp");
        else pole78->Picture->LoadFromFile("img/c.bmp");
        if(gra.p[8][1]==0) pole81->Picture->LoadFromFile("img/white_p.bmp");
        else if(gra.p[8][1]==1) pole81->Picture->LoadFromFile("img/black_p.bmp");
        else if(gra.p[8][1]==3) pole81->Picture->LoadFromFile("img/white_d.bmp");
        else if(gra.p[8][1]==4) pole81->Picture->LoadFromFile("img/black_d.bmp");
        else pole81->Picture->LoadFromFile("img/c.bmp");
        if(gra.p[8][3]==0) pole83->Picture->LoadFromFile("img/white_p.bmp");
        else if(gra.p[8][3]==1) pole83->Picture->LoadFromFile("img/black_p.bmp");
        else if(gra.p[8][3]==3) pole83->Picture->LoadFromFile("img/white_d.bmp");
        else if(gra.p[8][3]==4) pole83->Picture->LoadFromFile("img/black_d.bmp");
        else pole83->Picture->LoadFromFile("img/c.bmp");
        if(gra.p[8][5]==0) pole85->Picture->LoadFromFile("img/white_p.bmp");
        else if(gra.p[8][5]==1) pole85->Picture->LoadFromFile("img/black_p.bmp");
        else if(gra.p[8][5]==3) pole85->Picture->LoadFromFile("img/white_d.bmp");
        else if(gra.p[8][5]==4) pole85->Picture->LoadFromFile("img/black_d.bmp");
        else pole85->Picture->LoadFromFile("img/c.bmp");
        if(gra.p[8][7]==0) pole87->Picture->LoadFromFile("img/white_p.bmp");
        else if(gra.p[8][7]==1) pole87->Picture->LoadFromFile("img/black_p.bmp");
        else if(gra.p[8][7]==3) pole87->Picture->LoadFromFile("img/white_d.bmp");
        else if(gra.p[8][7]==4) pole87->Picture->LoadFromFile("img/black_d.bmp");
        else pole87->Picture->LoadFromFile("img/c.bmp");
}
void __fastcall TForm1::blok(bool what){
        pole12->Enabled=what;
        pole14->Enabled=what;
        pole16->Enabled=what;
        pole18->Enabled=what;
        pole21->Enabled=what;
        pole23->Enabled=what;
        pole25->Enabled=what;
        pole27->Enabled=what;
        pole32->Enabled=what;
        pole34->Enabled=what;
        pole36->Enabled=what;
        pole38->Enabled=what;
        pole41->Enabled=what;
        pole43->Enabled=what;
        pole45->Enabled=what;
        pole47->Enabled=what;
        pole52->Enabled=what;
        pole54->Enabled=what;
        pole56->Enabled=what;
        pole58->Enabled=what;
        pole61->Enabled=what;
        pole63->Enabled=what;
        pole65->Enabled=what;
        pole67->Enabled=what;
        pole72->Enabled=what;
        pole74->Enabled=what;
        pole76->Enabled=what;
        pole78->Enabled=what;
        pole81->Enabled=what;
        pole83->Enabled=what;
        pole85->Enabled=what;
        pole87->Enabled=what;
}
void __fastcall TForm1::pole12Click(TObject *Sender)
{
	if(!z1){
		z1=1, z2=2;
		return;
	}
	z3=1, z4=2;
	ruch();        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::pole14Click(TObject *Sender)
{
	if(!z1){
		z1=1, z2=4;
		return;
	}
	z3=1, z4=4;
	ruch();        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::pole16Click(TObject *Sender)
{
	if(!z1){
		z1=1, z2=6;
		return;
	}
	z3=1, z4=6;
	ruch();        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::pole18Click(TObject *Sender)
{
	if(!z1){
		z1=1, z2=8;
		return;
	}
	z3=1, z4=8;
	ruch();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::pole21Click(TObject *Sender)
{
	if(!z1){
		z1=2, z2=1;
		return;
	}
	z3=2, z4=1;
	ruch();        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::pole23Click(TObject *Sender)
{
	if(!z1){
		z1=2, z2=3;
		return;
	}
	z3=2, z4=3;
	ruch();        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::pole25Click(TObject *Sender)
{
	if(!z1){
		z1=2, z2=5;
		return;
	}
	z3=2, z4=5;
	ruch();        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::pole27Click(TObject *Sender)
{
	if(!z1){
		z1=2, z2=7;
		return;
	}
	z3=2, z4=7;
	ruch();        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::pole32Click(TObject *Sender)
{
	if(!z1){
		z1=3, z2=2;
		return;
	}
	z3=3, z4=2;
	ruch();        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::pole34Click(TObject *Sender)
{
	if(!z1){
		z1=3, z2=4;
		return;
	}
	z3=3, z4=4;
	ruch();        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::pole36Click(TObject *Sender)
{
	if(!z1){
		z1=3, z2=6;
		return;
	}
	z3=3, z4=6;
	ruch();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::pole38Click(TObject *Sender)
{
	if(!z1){
		z1=3, z2=8;
		return;
	}
	z3=3, z4=8;
	ruch();        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::pole41Click(TObject *Sender)
{
	if(!z1){
		z1=4, z2=1;
		return;
	}
	z3=4, z4=1;
	ruch();        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::pole43Click(TObject *Sender)
{
	if(!z1){
		z1=4, z2=3;
		return;
	}
	z3=4, z4=3;
	ruch();        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::pole45Click(TObject *Sender)
{
	if(!z1){
		z1=4, z2=5;
		return;
	}
	z3=4, z4=5;
	ruch();        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::pole47Click(TObject *Sender)
{
	if(!z1){
		z1=4, z2=7;
		return;
	}
	z3=4, z4=7;
	ruch();        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::pole52Click(TObject *Sender)
{
	if(!z1){
		z1=5, z2=2;
		return;
	}
	z3=5, z4=2;
	ruch();        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::pole54Click(TObject *Sender)
{
	if(!z1){
		z1=5, z2=4;
		return;
	}
	z3=5, z4=4;
	ruch();        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::pole56Click(TObject *Sender)
{
	if(!z1){
		z1=5, z2=6;
		return;
	}
	z3=5, z4=6;
	ruch();        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::pole58Click(TObject *Sender)
{
	if(!z1){
		z1=5, z2=8;
		return;
	}
	z3=5, z4=8;
	ruch();        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::pole61Click(TObject *Sender)
{
	if(!z1){
		z1=6, z2=1;
		return;
	}
	z3=6, z4=1;
	ruch();        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::pole63Click(TObject *Sender)
{
	if(!z1){
		z1=6, z2=3;
		return;
	}
	z3=6, z4=3;
	ruch();        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::pole65Click(TObject *Sender)
{
	if(!z1){
		z1=6, z2=5;
		return;
	}
	z3=6, z4=5;
	ruch();        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::pole67Click(TObject *Sender)
{
	if(!z1){
		z1=6, z2=7;
		return;
	}
	z3=6, z4=7;
	ruch();        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::pole72Click(TObject *Sender)
{
	if(!z1){
		z1=7, z2=2;
		return;
	}
	z3=7, z4=2;
	ruch();        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::pole74Click(TObject *Sender)
{
	if(!z1){
		z1=7, z2=4;
		return;
	}
	z3=7, z4=4;
	ruch();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::pole76Click(TObject *Sender)
{
	if(!z1){
		z1=7, z2=6;
		return;
	}
	z3=7, z4=6;
	ruch();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::pole78Click(TObject *Sender)
{
	if(!z1){
		z1=7, z2=8;
		return;
	}
	z3=7, z4=8;
	ruch();        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::pole81Click(TObject *Sender)
{
	if(!z1){
		z1=8, z2=1;
		return;
	}
	z3=8, z4=1;
	ruch();        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::pole83Click(TObject *Sender)
{
	if(!z1){
		z1=8, z2=3;
		return;
	}
	z3=8, z4=3;
	ruch();        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::pole85Click(TObject *Sender)
{
	if(!z1){
		z1=8, z2=5;
		return;
	}
	z3=8, z4=5;
	ruch();        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::pole87Click(TObject *Sender)
{
	if(!z1){
		z1=8, z2=7;
		return;
	}
	z3=8, z4=7;
	ruch();
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Autor1Click(TObject *Sender)
{
         Application->MessageBox("Wiktor Lewicki, wiktorek.tfm@gmail.com", "Autor", MB_OK);        
}
//---------------------------------------------------------------------------

