
#include <vcl.h>
#pragma hdrstop

#include<iostream>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include <time.h>
#include <utilcls.h>


#include "Unit54.h"
//----------------------------------------------------------------
#pragma package(smart_init)
#pragma link "sDialogs"
#pragma resource "*.dfm"
TForm1 *Form1;

using namespace std;

FILE *fp;

char answer[8];
DWORD n,btr,temp,mask,signal;
int im,isw1,j2,j3,j4,speedrl,start1;
int isw2=0;
int isw3=0;
speed1[7]={9600,19200,38400,57600,74880,115200};
String sc;
OVERLAPPED overlapped;
COMSTAT comstat;
Variant mExcel;
bool col1,have1;
String status1;
int beg1, end1;

int m;
int icom;
int cnt1, cnt2;
int em1;
int row1=2;
int max1;
int min1;

char str4[2];

char ccom1[2];
char ccom2[4]="COM";

char cx1[12];  //str1str2str3

char *s3 = new char[14];

AnsiString FileName1;
AnsiString FileName2;

void func1();


//----------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//----------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
Memo1->Clear();
for (int j=0; j<=100; j++){
Series4->Add(0,j2,clDkGray);
}
for (int i=1; i<10; i++)ComboBox1->Items->Add(i);
for (int i=0; i<6; i++)ComboBox2->Items->Add(speed1[i]);
}

//---------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
ifstream file2 (FileName2.c_str());
if(file2==NULL) {
isw2=1;
Label6->Caption="Bad";
}
else {
isw2=2;
Label6->Caption="OK";
}
file2.close();

if (isw3!=0)isw2=3;
else isw3=1;

switch (isw2) {
case 1:

SelectDirectory("","",FileName1);
sSaveDialog1->Execute();
sSaveDialog1->InitialDir = FileName1;
FileName2=sSaveDialog1->FileName+".xlsx";

mExcel = CreateOleObject("Excel.Application");
mExcel.OlePropertyGet("Workbooks").OleProcedure("Add");
mExcel.OlePropertyGet("Workbooks").OlePropertyGet("Item", 1).OleProcedure("SaveAs", FileName2.c_str());
mExcel.OlePropertyGet("Workbooks").OleProcedure("Open",FileName2.c_str());

Label5->Caption=FileName2;
isw2=2;
Label6->Caption="Create";
break;
case 2:
mExcel = CreateOleObject("Excel.Application");
mExcel.OlePropertyGet("Workbooks").OleProcedure("Open",FileName2.c_str());
Label6->Caption="Open";
break;
default:
mExcel.OlePropertyGet("Workbooks").OlePropertyGet("Item", 1).OleProcedure("Save");
mExcel.OleProcedure("Quit");
isw3=0;
func1();
Label6->Caption="Closed str "+IntToStr(beg1)+" end "+IntToStr(end1);
break;
}
func1();
Label4->Caption=status1;
}

//----------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
sc="COM"+ComboBox1->Text;
speedrl=strtoul(ComboBox2->Text.c_str(),NULL,10);
isw1=!isw1;
//j4=0;
if (isw1!=0){
//Memo1->Clear();

  Series5->Clear();
  Series6->Clear();
  max1=StrToInt(Edit1->Text);
  min1=StrToInt(Edit2->Text);
  Series5->AddXY(0,max1,0,clSilver);
  Series6->AddXY(0,-min1,0,clSilver);
}

HANDLE port = CreateFile(sc.c_str(), GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

DCB dcb;
GetCommState(port, &dcb);
dcb.BaudRate = speedrl;
dcb.ByteSize = 8;
dcb.Parity = NOPARITY ;  //NOPARITY  (BYTE)
dcb.StopBits = ONESTOPBIT; //ONESTOPBIT
dcb.fRtsControl = RTS_CONTROL_DISABLE;

SetCommState(port, &dcb);

while (isw1==1){

ReadFile(port, answer, 1, &n, NULL);
if(n>0){

if (answer[0] !='\t' && answer[0] !='\n') cx1[cnt1]= answer[0], cnt1++;
else {
 em1 = atoi (cx1);
 cnt1=0;
        
cnt2++;

if(CheckBox1->Checked == true){
itoa(j4, str4, 10);
if (cnt2==1)strcpy(s3, str4), strcat(s3, "\t"), strcat(s3, cx1);
else strcat(s3, "\t"), strcat(s3, cx1);
if (cnt2==3){
 Memo1->Lines->Add(s3);
for (int i=0; i<14; i++){
s3[i]=0;
  }
 } //cnt2=3
} //CheckBox1

for (int i=0; i<12; i++){
cx1[i]=NULL;
}

Application->ProcessMessages();

if (isw2!=2){
switch (cnt2){
case 1:
if(CheckBox2->Checked == true)Series1->Add(em1,j4,clBlue);
break;
case 2:
if(CheckBox3->Checked == true)Series2->Add(em1,j4,clRed);
break;
case 3:
if(CheckBox4->Checked == true)Series3->Add(em1,j4,clGreen);
j4++;
cnt2=0;
break;
default:
break;
}  //switch cnt2  1
} // if isw2!=2
else {
switch (cnt2){
case 1:
if(CheckBox2->Checked == true)Series1->Add(em1,j4,clBlue);
mExcel.OlePropertyGet("Cells").OlePropertyGet("Item", row1, 1).OlePropertySet("Value",em1);
break;
case 2:
if(CheckBox3->Checked == true)Series2->Add(em1,j4,clRed);
mExcel.OlePropertyGet("Cells").OlePropertyGet("Item", row1, 2).OlePropertySet("Value",em1);
break;
case 3:
if(CheckBox4->Checked == true)Series3->Add(em1,j4,clGreen);
mExcel.OlePropertyGet("Cells").OlePropertyGet("Item", row1, 3).OlePropertySet("Value",em1);
j4++;
cnt2=0;
row1++;
break;
default:
break;
}  //switch cnt2  2
}  //else isw2=2
}  //else  answer

if (j4>=100) Series1->Clear(), Series2->Clear(), Series3->Clear(), Memo1->Clear(), j4=0;

} //n Word
} //while

CloseHandle (port);
}

//----------------------------------------------------------------

void __fastcall TForm1::CreateNew1Click(TObject *Sender)
{

SelectDirectory("","",FileName1);
sSaveDialog1->Execute();
sSaveDialog1->InitialDir = FileName1;
FileName2=sSaveDialog1->FileName+".xlsx";

mExcel = CreateOleObject("Excel.Application");
mExcel.OlePropertyGet("Workbooks").OleProcedure("Add");
mExcel.OlePropertyGet("Workbooks").OlePropertyGet("Item", 1).OleProcedure("SaveAs", FileName2.c_str());
mExcel.OlePropertyGet("Workbooks").OleProcedure("Open",FileName2.c_str());

Label4->Caption="File create";
Label5->Caption=FileName2;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Open1Click(TObject *Sender)
{

SelectDirectory("","",FileName1);
sOpenDialog1->Execute();
sOpenDialog1->InitialDir = FileName1;
FileName2=sOpenDialog1->FileName;

Label4->Caption="File open";
Label5->Caption=FileName2;
}

//-----------------------------------------------------------------

void func1(){
switch (isw2) {
case 2:
status1="File save";
beg1=row1;
break;
case 3:
status1="File stop";
end1=row1;
break;
default:
break;
}
}
//-----------------------------------------------------------------

void __fastcall TForm1::Help1Click(TObject *Sender)
{
 ShowMessage("");
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Exit1Click(TObject *Sender)
{
SendMessage(Handle,WM_CLOSE,NULL,NULL);        
}
//---------------------------------------------------------------------------

