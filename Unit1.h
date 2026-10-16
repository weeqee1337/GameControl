//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Samples.Spin.hpp>
#include <Vcl.Menus.hpp>
#include <System.ImageList.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ImgList.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TSpinEdit *EditHours;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Time;
	TButton *ButtonStart;
	TTimer *Timer1;
	TSpinEdit *EditMinutes;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TTrayIcon *TrayIcon1;
	TButton *ButtonStop;
	TMainMenu *MainMenu1;
	TMenuItem *Settings1;
	TMenuItem *Passwordchange1;
	TMenuItem *N1;
	TMenuItem *N2;
	TBitBtn *BitBtn1;
	TStatusBar *StatusBar1;
	TTimer *TimerStatusbar;
	TMenuItem *Appearance1;
	TMenuItem *Windows11White1;
	TMenuItem *Windows11Dark1;
	void __fastcall ButtonStartClick(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall EditHoursChange(TObject *Sender);
	void __fastcall EditMinutesChange(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall TrayIcon1DblClick(TObject *Sender);
	void __fastcall ButtonStopClick(TObject *Sender);
	void __fastcall Passwordchange1Click(TObject *Sender);
	void __fastcall N2Click(TObject *Sender);
	void __fastcall BitBtn1Click(TObject *Sender);
	void __fastcall FormPaint(TObject *Sender);
	void __fastcall TimerStatusbarTimer(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Windows11White1Click(TObject *Sender);
	void __fastcall Windows11Dark1Click(TObject *Sender);
private:	// User declarations
	int totalSeconds;
	bool FIsFirstShow;
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
