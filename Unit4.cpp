//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit4.h"
#include "Unit2.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm4::FormClose(TObject *Sender, TCloseAction &Action)
{
	Form1->Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm4::BitBtn1Click(TObject *Sender)
{
	String action = MessageDlg("Are you sure you want to turn off the PC?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0);

	if (action == mrYes)
	WinExec("shutdown /s /f /t 0", SW_HIDE);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::BitBtn2Click(TObject *Sender)
{
	Form1->Show();
	this->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm4::BitBtn3Click(TObject *Sender)
{
	String action = MessageDlg("Are you sure you want to close the application?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0);
	if (action == mrYes)
		Application->Terminate();
}
//---------------------------------------------------------------------------

