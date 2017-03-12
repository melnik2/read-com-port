//---------------------------------------------------------------------------

#ifndef Unit54H
#define Unit54H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Chart.hpp>
#include <ExtCtrls.hpp>
#include <Series.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
#include "sDialogs.hpp"
#include <Dialogs.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TMemo *Memo1;
        TButton *Button1;
        TButton *Button2;
        TComboBox *ComboBox1;
        TComboBox *ComboBox2;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        TMainMenu *MainMenu1;
        TMenuItem *File1;
        TMenuItem *CreateNew1;
        TMenuItem *Open1;
        TMenuItem *Help1;
        TMenuItem *Exit1;
        TsOpenDialog *sOpenDialog1;
        TsSaveDialog *sSaveDialog1;
        TChart *Chart2;
        TLineSeries *Series4;
        TCheckBox *CheckBox1;
        TCheckBox *CheckBox2;
        TCheckBox *CheckBox3;
        TCheckBox *CheckBox4;
        TLineSeries *Series1;
        TLineSeries *Series2;
        TLineSeries *Series3;
        TLabel *Label8;
        TLineSeries *Series5;
        TLineSeries *Series6;
        TEdit *Edit1;
        TEdit *Edit2;
        TLabel *Label9;
        TLabel *Label10;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Open1Click(TObject *Sender);
        void __fastcall CreateNew1Click(TObject *Sender);
        void __fastcall Help1Click(TObject *Sender);
        void __fastcall Exit1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};

//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
