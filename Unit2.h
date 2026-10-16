#ifndef Unit2H
#define Unit2H

#include <System.Classes.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Buttons.hpp>

class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TButton *Button1;
	TPanel *Panel1;
	TEdit *Edit1;
	TButton *Button2;
	TTimer *TimerFocus;
	TButton *Button3;
	void __fastcall FormResize(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Edit1Change(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall FormDeactivate(TObject *Sender);
	void __fastcall TimerFocusTimer(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);

private:	// User declarations
	bool FAllowClose;

public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
};

extern PACKAGE TForm2 *Form2;

#endif
