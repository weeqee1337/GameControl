//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
#include <Registry.hpp>
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
UnicodeString XorCipher(UnicodeString text, int key)
{
	UnicodeString result = "";
	for (int i = 1; i <= text.Length(); i++) {
		int cryptedCode = text[i] ^ key;
		result += IntToStr(cryptedCode) + " ";
	}
	return result.Trim();
}
//---------------------------------------------------------------------------
UnicodeString XorDecrypt(UnicodeString cryptedText, int key)
{
	if (cryptedText.IsEmpty() || cryptedText.Trim().IsEmpty()) return "";

	UnicodeString result = "";
	int pos = 1;
	int len = cryptedText.Length();

	while (pos <= len) {
		UnicodeString numStr = "";

		while (pos <= len && cryptedText[pos] != ' ') {
			numStr += cryptedText[pos];
			pos++;
		}

		if (pos <= len && cryptedText[pos] == ' ') {
			pos++;
		}

		if (!numStr.IsEmpty()) {
			try {
				int code = StrToInt(numStr);
				wchar_t originalChar = code ^ key;
				result += originalChar;
			}
			catch (...) {
			}
		}
	}
	return result;
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button1Click(TObject *Sender)
{
	if (Edit1->Text.Length() >= 8) {
	UnicodeString exePath = ExtractFilePath(Application->ExeName);
	TIniFile *ini = new TIniFile(exePath + "data.ini");

	UnicodeString encryptedPassword = XorCipher(Edit1->Text, 42);

	try {
		ini->WriteString("Main", "Password", encryptedPassword);
		ShowMessage("Password has been saved.");
		Form1->StatusBar1->SimpleText = "Password has been saved";
		Form1->TimerStatusbar->Enabled = false;
		Form1->TimerStatusbar->Enabled = true;
	}

	__finally {
		delete ini;
	}
	if (Label1->Caption == "Set Up Password") {
		Application->Terminate();
	}
	else
		Close();
	}
	else {
	ShowMessage("Password must be at least 8 characters long.");
    Edit1->SetFocus();
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Edit1Change(TObject *Sender)
{
	if (Edit1->Text != "") {
		Button1->Enabled = true;
	}
	else {
		Button1->Enabled = false;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button2Click(TObject *Sender)
{
	Edit1->PasswordChar ^= '*';
	if (Button2->Caption == "Show") Button2->Caption = "Hide";
	else Button2->Caption = "Show";
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button3Click(TObject *Sender)
{
    this->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::FormCloseQuery(TObject *Sender, bool &CanClose)
{
	CanClose = FAllowClose;
}
//---------------------------------------------------------------------------

