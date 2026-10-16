//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include <Registry.hpp>
#include <System.SysUtils.hpp>
#include <Vcl.Themes.hpp>
#include <cstdlib>
#include <ctime>
#include "Unit3.h"
#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner), FIsFirstShow(true)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonStartClick(TObject *Sender)
{
	int hours = EditHours->Value;
	int minutes = EditMinutes->Value;

	totalSeconds = (hours * 3600) + (minutes * 60);

	if (totalSeconds > 0) {
		Timer1->Enabled = true;
	} else {
		ShowMessage("Please set a time greater than zero.");
	}

	StatusBar1->SimpleText = "Timer started";
	TimerStatusbar->Enabled = false;
	TimerStatusbar->Enabled = true;
    ShowMessage("Timer started. Minimized to system tray — double-click the icon to restore.");
	Form1->Hide();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
	if (totalSeconds > 0) {
			totalSeconds--;
			int h = totalSeconds / 3600;
			int m = (totalSeconds % 3600) / 60;
			int s = totalSeconds % 60;
			Time->Caption = FormatDateTime("hh:nn:ss", EncodeTime(h, m, s, 0));
	}
	else {
			Timer1->Enabled = false;
			Form2->TimerFocus->Enabled = true;
			Time->Caption = "GameControl";
			Variant shell = Variant::CreateObject("Shell.Application");
			shell.OleProcedure("MinimizeAll");
			Form2->Show();
	}

	if (Timer1->Enabled) {
		ButtonStop->Enabled = true;
		Button1->Enabled = false;
		Button2->Enabled = false;
		Button3->Enabled = false;
		BitBtn1->Enabled = false;
	}
	else {
		ButtonStop->Enabled = false;
		Button1->Enabled = true;
		Button2->Enabled = true;
		Button3->Enabled = true;
		BitBtn1->Enabled = true;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::EditHoursChange(TObject *Sender)
{
	if ((EditHours->Value != 0) || (EditMinutes->Value != 0)) {
		ButtonStart->Enabled = true;
	}
	else {
		ButtonStart->Enabled = false;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::EditMinutesChange(TObject *Sender)
{
	if ((EditHours->Value != 0) || (EditMinutes->Value != 0)) {
		ButtonStart->Enabled = true;
	}
	else {
		ButtonStart->Enabled = false;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	EditMinutes->Value += 30;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	EditHours->Value += 1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	EditHours->Value += 2;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TrayIcon1DblClick(TObject *Sender)
{
	Form1->Show();
	WindowState = wsNormal;
	Application->BringToFront();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonStopClick(TObject *Sender)
{
	Timer1->Enabled = false;
	Time->Caption = "GameControl";
	ButtonStop->Enabled = false;
	Button1->Enabled = true;
	Button2->Enabled = true;
	Button3->Enabled = true;
	BitBtn1->Enabled = true;
	StatusBar1->SimpleText = "Timer stopped";
	TimerStatusbar->Enabled = false;
	TimerStatusbar->Enabled = true;
	EditHours->Value = 0;
	EditMinutes->Value = 0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Passwordchange1Click(TObject *Sender)
{
	Form3->Edit1->Clear();
	Form3->Edit1->PasswordChar = '*';
    Form3->FAllowClose = true;
	Form3->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N2Click(TObject *Sender)
{   String buildDate = __DATE__;
	String buildTime = __TIME__;
	Randomize();
	String message = "GameControl\nBuild: #" + IntToHex((int)&__DATE__, 6) +
			"\nBuild date: " + buildDate + ' ' + buildTime +
			"\nDeveloper: Weeqee1337 (Made in Latvia)\nLicense: The GNU General Public License v3 (GPLv3)";
	ShowMessage(message);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{
	EditHours->Value = 0;
	EditMinutes->Value = 0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormPaint(TObject *Sender)
{
	if (FIsFirstShow) {
	FIsFirstShow = false;
		if (!FileExists(GetCurrentDir() + "\\data.ini")) {
			ButtonStart->Enabled = false;
			EditHours->ReadOnly = true;
			EditMinutes->ReadOnly = true;
			Button1->Enabled = false;
			Button2->Enabled = false;
			Button3->Enabled = false;

			Form3->Caption = "Set Up Password";
			Form3->Label1->Caption = "Set Up Password";
			Form3->FAllowClose = false;
			Form3->ShowModal();
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TimerStatusbarTimer(TObject *Sender)
{
	StatusBar1->SimpleText = "";
	TimerStatusbar->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	TIniFile *ini = new TIniFile(ExtractFilePath(Application->ExeName) + "data.ini");
	UnicodeString savedStyle = ini->ReadString("Settings", "VCLStyle", "Windows11 White Smoke");
	delete ini;

	TStyleManager::SetStyle(savedStyle);
	Windows11White1->Checked = (savedStyle == "Windows11 White Smoke");
	Windows11Dark1->Checked  = (savedStyle == "Windows11 MineShaft");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Windows11White1Click(TObject *Sender)
{
	UnicodeString styleName = "Windows11 White Smoke";

	TStyleManager::SetStyle(styleName);

	Windows11White1->Checked = true;
	Windows11Dark1->Checked = false;

	TIniFile *ini = new TIniFile(ExtractFilePath(Application->ExeName) + "data.ini");
	ini->WriteString("Settings", "VCLStyle", styleName);
	delete ini;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Windows11Dark1Click(TObject *Sender)
{
	UnicodeString styleName = "Windows11 MineShaft";

	TStyleManager::SetStyle(styleName);

	Windows11White1->Checked = false;
	Windows11Dark1->Checked = true;

	TIniFile *ini = new TIniFile(ExtractFilePath(Application->ExeName) + "data.ini");
	ini->WriteString("Settings", "VCLStyle", styleName);
	delete ini;
}
//---------------------------------------------------------------------------
