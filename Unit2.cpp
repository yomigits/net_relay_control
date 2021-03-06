//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include <inifiles.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
   TIniFile *ini;
   ini = new TIniFile( ChangeFileExt( Application->ExeName, ".INI" ) );

   Form2->Edit1->Text= ini->ReadString( "NetWork_Config", "IP",  "Default Caption" ) ;
   Form2->Edit2->Text= ini->ReadString( "NetWork_Config", "Port",  "Default Caption" ) ;

   Form2->Edit3->Text= ini->ReadString( "Device_Config", "Light1",  "Default Caption" ) ;
   Form2->Edit4->Text= ini->ReadString( "Device_Config", "Light2",  "Default Caption" ) ;
   Form2->Edit5->Text= ini->ReadString( "Device_Config", "Light3",  "Default Caption" ) ;
   Form2->Edit6->Text= ini->ReadString( "Device_Config", "Light4",  "Default Caption" ) ;
   Form2->Edit7->Text= ini->ReadString( "Device_Config", "Light5",  "Default Caption" ) ;
   Form2->Edit8->Text= ini->ReadString( "Device_Config", "Light6",  "Default Caption" ) ;
   Form2->Edit9->Text= ini->ReadString( "Device_Config", "Light7",  "Default Caption" ) ;
   Form2->Edit10->Text= ini->ReadString( "Device_Config", "Light8",  "Default Caption" ) ;

   Form2->Edit11->Text= ini->ReadString( "Title_Config", "Software_title",  "Default Caption" ) ;
   Form2->Edit12->Text= ini->ReadString( "Title_Config", "CopyRight",  "Default Caption" ) ;
	//ShowMessage(ini->ReadString( "Device_ICO", "Light1_ON",  "Default Caption" ) );
   Image1->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light1_ON",  "Default Caption" ) );
   Image2->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light2_ON",  "Default Caption" ) );
   Image3->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light3_ON",  "Default Caption" ) );
   Image4->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light4_ON",  "Default Caption" ) );
   Image5->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light5_ON",  "Default Caption" ) );
   Image6->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light6_ON",  "Default Caption" ) );
   Image7->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light7_ON",  "Default Caption" ) );
   Image8->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light8_ON",  "Default Caption" ) );

   Image9->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light1_OFF",  "Default Caption" ) );
   Image10->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light2_OFF",  "Default Caption" ) );
   Image11->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light3_OFF",  "Default Caption" ) );
   Image12->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light4_OFF",  "Default Caption" ) );
   Image13->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light5_OFF",  "Default Caption" ) );
   Image14->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light6_OFF",  "Default Caption" ) );
   Image15->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light7_OFF",  "Default Caption" ) );
   Image16->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light8_OFF",  "Default Caption" ) );


   delete ini;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button2Click(TObject *Sender)
{
Close();

}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
   TIniFile *ini;
   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
//   ini = new TIniFile( "C:\Net_Relay_Control.INI" );

   ini->WriteString ( "NetWork_Config", "IP", Edit1->Text );
   ini->WriteString ( "NetWork_Config", "Port", Edit2->Text );

   ini->WriteString ( "Title_Config", "Software_title", Edit11->Text );
   ini->WriteString ( "Title_Config", "CopyRight", Edit12->Text );

   ini->WriteString ( "Device_Config", "Light1", Edit3->Text );
   ini->WriteString ( "Device_Config", "Light2", Edit4->Text );
   ini->WriteString ( "Device_Config", "Light3", Edit5->Text );
   ini->WriteString ( "Device_Config", "Light4", Edit6->Text );
   ini->WriteString ( "Device_Config", "Light5", Edit7->Text );
   ini->WriteString ( "Device_Config", "Light6", Edit8->Text );
   ini->WriteString ( "Device_Config", "Light7", Edit9->Text );
   ini->WriteString ( "Device_Config", "Light8", Edit10->Text );
  /*
   ini->WriteString ( "Device_ICO", "Light1", Image1->Picture->GetNamePath() );
   ini->WriteString ( "Device_ICO", "Light2", Image2->Picture->GetNamePath() );
   ini->WriteString ( "Device_ICO", "Light3", Image3->Picture->GetNamePath() );
   ini->WriteString ( "Device_ICO", "Light4", Image4->Picture->GetNamePath() );
   ini->WriteString ( "Device_ICO", "Light5", Image5->Picture->GetNamePath() );
   ini->WriteString ( "Device_ICO", "Light6", Image6->Picture->GetNamePath() );
   ini->WriteString ( "Device_ICO", "Light7", Image7->Picture->GetNamePath() );
   ini->WriteString ( "Device_ICO", "Light8", Image8->Picture->GetNamePath() );
   */

   delete ini;
   Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button3Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image1->Picture->LoadFromFile(OpenDialog1->FileName);

   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light1_ON", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button4Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image2->Picture->LoadFromFile(OpenDialog1->FileName);

   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light2_ON", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button5Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image3->Picture->LoadFromFile(OpenDialog1->FileName);
   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light3_ON", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button6Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image4->Picture->LoadFromFile(OpenDialog1->FileName);
   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light4_ON", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button7Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image5->Picture->LoadFromFile(OpenDialog1->FileName);
   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light5_ON", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button8Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image6->Picture->LoadFromFile(OpenDialog1->FileName);
   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light6_ON", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button9Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image7->Picture->LoadFromFile(OpenDialog1->FileName);
   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light7_ON", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button10Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image8->Picture->LoadFromFile(OpenDialog1->FileName);
   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light8_ON", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button11Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image9->Picture->LoadFromFile(OpenDialog1->FileName);

   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light1_OFF", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button12Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image10->Picture->LoadFromFile(OpenDialog1->FileName);

   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light2_OFF", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button13Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image11->Picture->LoadFromFile(OpenDialog1->FileName);

   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light3_OFF", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button14Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image12->Picture->LoadFromFile(OpenDialog1->FileName);

   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light4_OFF", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button15Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image13->Picture->LoadFromFile(OpenDialog1->FileName);

   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light5_OFF", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button16Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image14->Picture->LoadFromFile(OpenDialog1->FileName);

   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light6_OFF", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button17Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image15->Picture->LoadFromFile(OpenDialog1->FileName);

   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light7_OFF", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button18Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image16->Picture->LoadFromFile(OpenDialog1->FileName);

   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light8_OFF", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------

