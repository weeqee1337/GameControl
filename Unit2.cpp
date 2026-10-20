//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include <comobj.hpp>
#include <IniFiles.hpp>
#include "Unit3.h"
#include "Unit1.h"
#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
TForm2 *Form2;
HHOOK g_hKeyboardHook = NULL;

LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	if (nCode == HC_ACTION)
	{
		KBDLLHOOKSTRUCT *pKeyInfo = (KBDLLHOOKSTRUCT *)lParam;
		bool bBlock = false;

		if (pKeyInfo->vkCode == VK_LWIN || pKeyInfo->vkCode == VK_RWIN)
		{
			bBlock = true;
		}

		if ((pKeyInfo->flags & LLKHF_ALTDOWN) != 0)
		{
			if (pKeyInfo->vkCode == VK_TAB || pKeyInfo->vkCode == VK_ESCAPE)
			{
				bBlock = true;
			}
		}

		if (pKeyInfo->vkCode == VK_ESCAPE && (GetKeyState(VK_CONTROL) & 0x8000) != 0)
		{
			bBlock = true;
		}

		if (bBlock)
		{
			return 1;
		}
	}

	return CallNextHookEx(g_hKeyboardHook, nCode, wParam, lParam);
}
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormCreate(TObject *Sender)
{
	FAllowClose = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormDestroy(TObject *Sender)
{
	TimerFocus->Enabled = false;

	if (g_hKeyboardHook != NULL)
	{
		UnhookWindowsHookEx(g_hKeyboardHook);
		g_hKeyboardHook = NULL;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormResize(TObject *Sender)
{
	int w = Screen->DesktopWidth;
	int h = Screen->DesktopHeight;

	Label1->Left = (w - Label1->Width) / 2;
	Label1->Top = (h - Label1->Height) / 2;

	Button1->Left = (w - Button1->Width) / 2;
	Button1->Top = Label1->Top + Label1->Height + 20;

	Panel1->Left = (w - Panel1->Width) / 2;
	Panel1->Top = Button1->Top + Button1->Height + 20;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormShow(TObject *Sender)
{
	FAllowClose = false;

	Edit1->Text = "";

	if (g_hKeyboardHook == NULL)
	{
		g_hKeyboardHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, GetModuleHandle(NULL), 0);
	}

	this->BorderStyle = bsNone;
	this->FormStyle = fsStayOnTop;

	int screenWidth = Screen->DesktopWidth;
	int screenHeight = Screen->DesktopHeight;

	SetWindowLong(this->Handle, GWL_STYLE, WS_POPUP | WS_VISIBLE);

	SetWindowPos(this->Handle,
		HWND_TOPMOST,
		0, 0,
		screenWidth, screenHeight,
		SWP_SHOWWINDOW | SWP_FRAMECHANGED | SWP_NOCOPYBITS);

	this->Invalidate();
	this->Repaint();

	FormResize(Sender);

	TimerFocus->Interval = 50;
	TimerFocus->Enabled = true;

	if (Edit1->CanFocus()) {
		Edit1->SetFocus();
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormDeactivate(TObject *Sender)
{
	Application->BringToFront();
	this->SetFocus();
	if (Edit1->CanFocus()) {
		Edit1->SetFocus();
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::TimerFocusTimer(TObject *Sender)
{
	HWND activeWindow = GetForegroundWindow();

	if (activeWindow != this->Handle)
	{
		BringToFront();
		SetForegroundWindow(this->Handle);

		SetWindowPos(this->Handle,
			HWND_TOPMOST,
			0, 0,
			Screen->DesktopWidth, Screen->DesktopHeight,
			SWP_SHOWWINDOW | SWP_FRAMECHANGED
		);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Edit1Change(TObject *Sender)
{
	Button2->Enabled = (Edit1->Text != "");
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
	Panel1->Visible = true;
	FormResize(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button2Click(TObject *Sender)
{
	UnicodeString exePath = ExtractFilePath(Application->ExeName);
	TIniFile *ini = new TIniFile(exePath + "data.ini");
	UnicodeString rawPassword;

	try {
		rawPassword = ini->ReadString("Main", "Password", "");
	}
	__finally {
		delete ini;
	}

	UnicodeString decryptedPassword = XorDecrypt(rawPassword, 42);

	if (Edit1->Text == decryptedPassword) {
		TimerFocus->Enabled = false;

		if (g_hKeyboardHook != NULL)
		{
			UnhookWindowsHookEx(g_hKeyboardHook);
			g_hKeyboardHook = NULL;
		}

		FAllowClose = true;

		Panel1->Visible = false;

		Form4->Show();
		Form1->WindowState = wsNormal;

		Close();
	} else {
		ShowMessage("Wrong password.");
		Edit1->Text = "";
		Edit1->SetFocus();
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormCloseQuery(TObject *Sender, bool &CanClose)
{
	CanClose = FAllowClose;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button3Click(TObject *Sender)
{
	Edit1->PasswordChar ^= '*';
	if (Button3->Caption == "Show") Button3->Caption = "Hide";
	else Button3->Caption = "Show";
}
//---------------------------------------------------------------------------
