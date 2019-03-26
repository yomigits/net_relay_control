//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit4.h"
#include "Unit5.h"
#include "Unit6.h"
#include <inifiles.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "trayicon"
#pragma resource "*.dfm"
TForm1 *Form1;

AnsiString light_img_1_ON,light_img_2_ON,light_img_3_ON,light_img_4_ON,light_img_5_ON,light_img_6_ON,light_img_7_ON,light_img_8_ON;
AnsiString light_img_1_OFF,light_img_2_OFF,light_img_3_OFF,light_img_4_OFF,light_img_5_OFF,light_img_6_OFF,light_img_7_OFF,light_img_8_OFF;

int time_i=1;  //包序号自增计数器，到255后，自动返回到1

void __fastcall TForm1::WndProc(Winapi::Messages::TMessage &Message)
{
 switch(Message.Msg)
  {
    case WM_SYSCOMMAND:
     {
       switch(Message.WParam)
        {
		  case SC_CLOSE    : break; // 关闭
          case SC_MAXIMIZE : break; // 最大化
		  case SC_MINIMIZE : {Form1->Hide();break;} // 最小化
		  case SC_RESTORE  : break; // 还原
        }
     } break;
  }
 TForm::WndProc(Message);
}

////INDY HTTP CLIENT Get请求 函数
String  GetData(String url,String data)
{
	 TIdHTTP *IdHttp1;
	 try{
			 IdHttp1=new TIdHTTP(Application);
			IdHttp1->Request->ContentType="application/x-www-form-urlencoded";
			if(IdHttp1==NULL)
			 {
				return "";
			 }

			AnsiString Url=url+"?"+data;
			String str =IdHttp1->Get(Url);
			delete   IdHttp1;
			return  str;
	 }
	 catch(Exception &e)
		{
		 if(IdHttp1!=NULL)
			delete IdHttp1;
			return "";
		 }

}



//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
   TIniFile *ini;
   ini = new TIniFile( ChangeFileExt( Application->ExeName, ".INI" ) );
//   ini = new TIniFile( "c:\Net_Relay_Control.INI" );

//------------------------------载入网络参数配置信息---------------------------
   Label1->Caption = ini->ReadString( "Device_Config", "Light1",  "Light1" ) ;
   Label2->Caption = ini->ReadString( "Device_Config", "Light2",  "Light2" ) ;
   Label3->Caption = ini->ReadString( "Device_Config", "Light3",  "Light3" ) ;
   Label4->Caption = ini->ReadString( "Device_Config", "Light4",  "Light4" ) ;
   Label5->Caption = ini->ReadString( "Device_Config", "Light5",  "Light5" ) ;
   Label6->Caption = ini->ReadString( "Device_Config", "Light6",  "Light6" ) ;
   Label7->Caption = ini->ReadString( "Device_Config", "Light7",  "Light7" ) ;
   Label8->Caption = ini->ReadString( "Device_Config", "Light8",  "Light8" ) ;

   Form1->Caption =  ini->ReadString( "Title_Config", "Software_title",  "Smart Home Control System" ) ;
   StatusBar1->Panels->Items[0]->Text = ini->ReadString( "Title_Config", "CopyRight",  "KinCony" ) ;
   /*
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
   */

   ClientSocket1->Host=ini->ReadString( "NetWork_Config", "IP",  "192.168.1.200" ) ;
   ClientSocket1->Port=StrToInt(ini->ReadString( "NetWork_Config", "Port",  "4196" )) ;

   light_img_1_ON= ini->ReadString( "Device_ICO", "Light1_ON",  "Default Caption" ) ;
   light_img_2_ON= ini->ReadString( "Device_ICO", "Light2_ON",  "Default Caption" ) ;
   light_img_3_ON= ini->ReadString( "Device_ICO", "Light3_ON",  "Default Caption" ) ;
   light_img_4_ON= ini->ReadString( "Device_ICO", "Light4_ON",  "Default Caption" ) ;
   light_img_5_ON= ini->ReadString( "Device_ICO", "Light5_ON",  "Default Caption" ) ;
   light_img_6_ON= ini->ReadString( "Device_ICO", "Light6_ON",  "Default Caption" ) ;
   light_img_7_ON= ini->ReadString( "Device_ICO", "Light7_ON",  "Default Caption" ) ;
   light_img_8_ON= ini->ReadString( "Device_ICO", "Light8_ON",  "Default Caption" ) ;

   light_img_1_OFF= ini->ReadString( "Device_ICO", "Light1_OFF",  "Default Caption" ) ;
   light_img_2_OFF= ini->ReadString( "Device_ICO", "Light2_OFF",  "Default Caption" ) ;
   light_img_3_OFF= ini->ReadString( "Device_ICO", "Light3_OFF",  "Default Caption" ) ;
   light_img_4_OFF= ini->ReadString( "Device_ICO", "Light4_OFF",  "Default Caption" ) ;
   light_img_5_OFF= ini->ReadString( "Device_ICO", "Light5_OFF",  "Default Caption" ) ;
   light_img_6_OFF= ini->ReadString( "Device_ICO", "Light6_OFF",  "Default Caption" ) ;
   light_img_7_OFF= ini->ReadString( "Device_ICO", "Light7_OFF",  "Default Caption" ) ;
   light_img_8_OFF= ini->ReadString( "Device_ICO", "Light8_OFF",  "Default Caption" ) ;

   Image1->Picture ->LoadFromFile(light_img_1_OFF);
   Image2->Picture ->LoadFromFile(light_img_2_OFF);
   Image3->Picture ->LoadFromFile(light_img_3_OFF);
   Image4->Picture ->LoadFromFile(light_img_4_OFF);
   Image5->Picture ->LoadFromFile(light_img_5_OFF);
   Image6->Picture ->LoadFromFile(light_img_6_OFF);
   Image7->Picture ->LoadFromFile(light_img_7_OFF);
   Image8->Picture ->LoadFromFile(light_img_8_OFF);


   //------------------------------第一路定时器参数配置信息------------------------
  // ShowMessage(ini->ReadString( "Week_Config", "One_Week1",  "0" ));
  //	if (ini->ReadString( "Week_Config", "One_Week1",  "0" )=="-1") Form3->CheckBox1->Checked=true; else Form3->CheckBox1->Checked=false;   //读取星期选择
 /*  Form3->CheckBox2->Checked  = StrToBool(ini->ReadString( "Week_Config", "One_Week2",  "0" )) ;
   Form3->CheckBox3->Checked  = StrToBool(ini->ReadString( "Week_Config", "One_Week3",  "0" )) ;
   Form3->CheckBox4->Checked  = StrToBool(ini->ReadString( "Week_Config", "One_Week4",  "0" )) ;
   Form3->CheckBox5->Checked  = StrToBool(ini->ReadString( "Week_Config", "One_Week5",  "0" )) ;
   Form3->CheckBox6->Checked  = StrToBool(ini->ReadString( "Week_Config", "One_Week6",  "0" )) ;
   Form3->CheckBox7->Checked  = StrToBool(ini->ReadString( "Week_Config", "One_Week7",  "0" )) ;

   Form3->CheckBox8->Checked  = StrToBool(ini->ReadString( "Enable_Config", "One_EN_1",  "0" )) ;  //读取５个定时时间段使能参数
   Form3->CheckBox9->Checked  = StrToBool(ini->ReadString( "Enable_Config", "One_EN_2",  "0" )) ;
   Form3->CheckBox10->Checked  = StrToBool(ini->ReadString( "Enable_Config", "One_EN_3",  "0" )) ;
   Form3->CheckBox11->Checked  = StrToBool(ini->ReadString( "Enable_Config", "One_EN_4",  "0" )) ;
   Form3->CheckBox12->Checked  = StrToBool(ini->ReadString( "Enable_Config", "One_EN_5",  "0" )) ;
	 */
  // Form3->ComboBox1->Text  = ini->ReadString( "Time_Config", "One_Time1_A",  "Default Caption" ) ;     //第一路的第1个定时器的起止时间段
  /* Form3->ComboBox2->Text  = ini->ReadString( "Time_Config", "One_Time1_B",  "00" ) ;
   Form3->ComboBox3->Text  = ini->ReadString( "Time_Config", "One_Time1_C",  "00" ) ;
   Form3->ComboBox4->Text  = ini->ReadString( "Time_Config", "One_Time1_D",  "00" ) ;

   Form3->ComboBox5->Text  = ini->ReadString( "Time_Config", "One_Time2_A",  "00" ) ;     //第一路的第2个定时器的起止时间段
   Form3->ComboBox6->Text  = ini->ReadString( "Time_Config", "One_Time2_B",  "00" ) ;
   Form3->ComboBox7->Text  = ini->ReadString( "Time_Config", "One_Time2_C",  "00" ) ;
   Form3->ComboBox8->Text  = ini->ReadString( "Time_Config", "One_Time2_D",  "00" ) ;

   Form3->ComboBox9->Text  = ini->ReadString( "Time_Config", "One_Time3_A",  "00" ) ;     //第一路的第3个定时器的起止时间段
   Form3->ComboBox10->Text  = ini->ReadString( "Time_Config", "One_Time3_B",  "00" ) ;
   Form3->ComboBox11->Text  = ini->ReadString( "Time_Config", "One_Time3_C",  "00" ) ;
   Form3->ComboBox12->Text  = ini->ReadString( "Time_Config", "One_Time3_D",  "00" ) ;

   Form3->ComboBox13->Text  = ini->ReadString( "Time_Config", "One_Time4_A",  "00" ) ;     //第一路的第4个定时器的起止时间段
   Form3->ComboBox14->Text  = ini->ReadString( "Time_Config", "One_Time4_B",  "00" ) ;
   Form3->ComboBox15->Text  = ini->ReadString( "Time_Config", "One_Time4_C",  "00" ) ;
   Form3->ComboBox16->Text  = ini->ReadString( "Time_Config", "One_Time4_D",  "00" ) ;

   Form3->ComboBox17->Text  = ini->ReadString( "Time_Config", "One_Time5_A",  "00" ) ;     //第一路的第5个定时器的起止时间段
   Form3->ComboBox18->Text  = ini->ReadString( "Time_Config", "One_Time5_B",  "00" ) ;
   Form3->ComboBox19->Text  = ini->ReadString( "Time_Config", "One_Time5_C",  "00" ) ;
   Form3->ComboBox20->Text  = ini->ReadString( "Time_Config", "One_Time5_D",  "00" ) ;


	   */








   delete ini;





}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{

  StatusBar1->Panels->Items[1]->Text="";


/*StatusBar1->Panels->Items[1]->Text = DateTimeToStr(Now());    */
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button9Click(TObject *Sender)
{
		ClientSocket1->Active = false;
        try
          {
            ClientSocket1->Active=true;
          }
        catch(Exception &E)
          {
            ShowMessage("连接失败！"+E.Message);
        return;
		  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;
  DWORD dwTick = ::GetTickCount();    //延时函数用

  if (N10->Checked==true) {  //如果当前是局域网模式
	send_buf="RELAY-SET-1,1,1";
	ClientSocket1->Socket->SendText(send_buf);
	Image1->Picture ->LoadFromFile(light_img_1_ON);  //变成ON图标

	if (Form6->CheckBox1->Checked)    //如果是点动模式的话，需要延时后自动关闭继电器
	  {
		while (::GetTickCount() - dwTick < StrToInt(Form6->ComboBox1->Text )*1000)  //延时
		Application->ProcessMessages();
		Button2->Click();      //执行关闭按钮
	  }
  }
  else                       //如果当前是因特网模式
  {
   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }

   if (N14->Checked==true) SN=Form5->Edit2->Text ;                //选中的是第1台控制盒
   if (N21->Checked==true) SN=Form5->Edit4->Text ;                //选中的是第2台控制盒
   if (N31->Checked==true) SN=Form5->Edit6->Text ;                //选中的是第3台控制盒
   if (N41->Checked==true) SN=Form5->Edit8->Text ;                //选中的是第4台控制盒

   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //第1路继电器打开
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",1,1";
   String strResponse = GetData(send_buf, data);
   Image1->Picture ->LoadFromFile(light_img_1_ON);  //变成ON图标

	if (Form6->CheckBox1->Checked)    //如果是点动模式的话，需要延时后自动关闭继电器
	  {
		while (::GetTickCount() - dwTick < StrToInt(Form6->ComboBox1->Text )*1000)  //延时
		Application->ProcessMessages();
		Button2->Click();      //执行关闭按钮
	  }

   //Memo1->Text = strResponse;

  }



 // Image1->Picture ->LoadFromFile(light_img_1_ON);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button10Click(TObject *Sender)
{
  ClientSocket1->Active = false;
  ClientSocket1->Close() ;


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button11Click(TObject *Sender)
{
ClientSocket1->Socket->SendText("RELAY-SCAN_DEVICE-NOW");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button12Click(TObject *Sender)
{
ClientSocket1->Socket->SendText("RELAY-TEST-NOW");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  if (N10->Checked==true) {  //如果当前是局域网模式
	send_buf="RELAY-SET-1,1,0";
	ClientSocket1->Socket->SendText(send_buf);
  }
  else                       //如果当前是因特网模式
  {
   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }

   if (N14->Checked==true) SN=Form5->Edit2->Text ;                //选中的是第1台控制盒
   if (N21->Checked==true) SN=Form5->Edit4->Text ;                //选中的是第2台控制盒
   if (N31->Checked==true) SN=Form5->Edit6->Text ;                //选中的是第3台控制盒
   if (N41->Checked==true) SN=Form5->Edit8->Text ;                //选中的是第4台控制盒

   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //第1路继电器关闭
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",1,0";
   String strResponse = GetData(send_buf, data);
  }

  Image1->Picture ->LoadFromFile(light_img_1_OFF);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;
  DWORD dwTick = ::GetTickCount();    //延时函数用

  if (N10->Checked==true) {  //如果当前是局域网模式
	send_buf="RELAY-SET-1,2,1";
	ClientSocket1->Socket->SendText(send_buf);
	Image2->Picture ->LoadFromFile(light_img_2_ON);

		if (Form6->CheckBox2->Checked)    //如果是点动模式的话，需要延时后自动关闭继电器
	  {
		while (::GetTickCount() - dwTick < StrToInt(Form6->ComboBox2->Text )*1000)  //延时
		Application->ProcessMessages();
		Button4->Click();      //执行关闭按钮
	  }
  }
  else                       //如果当前是因特网模式
  {
   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }

   if (N14->Checked==true) SN=Form5->Edit2->Text ;                //选中的是第1台控制盒
   if (N21->Checked==true) SN=Form5->Edit4->Text ;                //选中的是第2台控制盒
   if (N31->Checked==true) SN=Form5->Edit6->Text ;                //选中的是第3台控制盒
   if (N41->Checked==true) SN=Form5->Edit8->Text ;                //选中的是第4台控制盒

   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //第2路继电器打开
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",2,1";
   String strResponse = GetData(send_buf, data);
   Image2->Picture ->LoadFromFile(light_img_2_ON);

	if (Form6->CheckBox2->Checked)    //如果是点动模式的话，需要延时后自动关闭继电器
	  {
		while (::GetTickCount() - dwTick < StrToInt(Form6->ComboBox2->Text )*1000)  //延时
		Application->ProcessMessages();
		Button4->Click();      //执行关闭按钮
	  }
  }

  //Image2->Picture ->LoadFromFile(light_img_2_ON);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  if (N10->Checked==true) {  //如果当前是局域网模式
	send_buf="RELAY-SET-1,2,0";
	ClientSocket1->Socket->SendText(send_buf);
  }
  else                       //如果当前是因特网模式
  {
   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }

   if (N14->Checked==true) SN=Form5->Edit2->Text ;                //选中的是第1台控制盒
   if (N21->Checked==true) SN=Form5->Edit4->Text ;                //选中的是第2台控制盒
   if (N31->Checked==true) SN=Form5->Edit6->Text ;                //选中的是第3台控制盒
   if (N41->Checked==true) SN=Form5->Edit8->Text ;                //选中的是第4台控制盒

   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //第2路继电器关闭
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",2,0";
   String strResponse = GetData(send_buf, data);
  }

  Image2->Picture ->LoadFromFile(light_img_2_OFF);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;
  DWORD dwTick = ::GetTickCount();    //延时函数用

  if (N10->Checked==true) {  //如果当前是局域网模式
	send_buf="RELAY-SET-1,3,1";
	ClientSocket1->Socket->SendText(send_buf);
	Image3->Picture ->LoadFromFile(light_img_3_ON);

	if (Form6->CheckBox3->Checked)    //如果是点动模式的话，需要延时后自动关闭继电器
	  {
		while (::GetTickCount() - dwTick < StrToInt(Form6->ComboBox3->Text )*1000)  //延时
		Application->ProcessMessages();
		Button6->Click();      //执行关闭按钮
	  }
  }
  else                       //如果当前是因特网模式
  {
   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }

   if (N14->Checked==true) SN=Form5->Edit2->Text ;                //选中的是第1台控制盒
   if (N21->Checked==true) SN=Form5->Edit4->Text ;                //选中的是第2台控制盒
   if (N31->Checked==true) SN=Form5->Edit6->Text ;                //选中的是第3台控制盒
   if (N41->Checked==true) SN=Form5->Edit8->Text ;                //选中的是第4台控制盒

   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //第3路继电器打开
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",3,1";
   String strResponse = GetData(send_buf, data);
   Image3->Picture ->LoadFromFile(light_img_3_ON);

	if (Form6->CheckBox3->Checked)    //如果是点动模式的话，需要延时后自动关闭继电器
	  {
		while (::GetTickCount() - dwTick < StrToInt(Form6->ComboBox3->Text )*1000)  //延时
		Application->ProcessMessages();
		Button6->Click();      //执行关闭按钮
	  }
  }


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;
  DWORD dwTick = ::GetTickCount();    //延时函数用

  if (N10->Checked==true) {  //如果当前是局域网模式
	send_buf="RELAY-SET-1,4,1";
	ClientSocket1->Socket->SendText(send_buf);
	Image4->Picture ->LoadFromFile(light_img_4_ON);

	  if (Form6->CheckBox4->Checked)    //如果是点动模式的话，需要延时后自动关闭继电器
	  {
		while (::GetTickCount() - dwTick < StrToInt(Form6->ComboBox4->Text )*1000)  //延时
		Application->ProcessMessages();
		Button8->Click();      //执行关闭按钮
	  }
  }
  else                       //如果当前是因特网模式
  {
   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }

   if (N14->Checked==true) SN=Form5->Edit2->Text ;                //选中的是第1台控制盒
   if (N21->Checked==true) SN=Form5->Edit4->Text ;                //选中的是第2台控制盒
   if (N31->Checked==true) SN=Form5->Edit6->Text ;                //选中的是第3台控制盒
   if (N41->Checked==true) SN=Form5->Edit8->Text ;                //选中的是第4台控制盒

   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //第4路继电器打开
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",4,1";
   String strResponse = GetData(send_buf, data);
   Image4->Picture ->LoadFromFile(light_img_4_ON);

	if (Form6->CheckBox4->Checked)    //如果是点动模式的话，需要延时后自动关闭继电器
	  {
		while (::GetTickCount() - dwTick < StrToInt(Form6->ComboBox4->Text )*1000)  //延时
		Application->ProcessMessages();
		Button8->Click();      //执行关闭按钮
	  }

  }


}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button6Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  if (N10->Checked==true) {  //如果当前是局域网模式
	send_buf="RELAY-SET-1,3,0";
	ClientSocket1->Socket->SendText(send_buf);
  }
  else                       //如果当前是因特网模式
  {
   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }

   if (N14->Checked==true) SN=Form5->Edit2->Text ;                //选中的是第1台控制盒
   if (N21->Checked==true) SN=Form5->Edit4->Text ;                //选中的是第2台控制盒
   if (N31->Checked==true) SN=Form5->Edit6->Text ;                //选中的是第3台控制盒
   if (N41->Checked==true) SN=Form5->Edit8->Text ;                //选中的是第4台控制盒

   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //第3路继电器关闭
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",3,0";
   String strResponse = GetData(send_buf, data);
  }

  Image3->Picture ->LoadFromFile(light_img_3_OFF);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  if (N10->Checked==true) {  //如果当前是局域网模式
	send_buf="RELAY-SET-1,4,0";
	ClientSocket1->Socket->SendText(send_buf);
  }
  else                       //如果当前是因特网模式
  {
   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }

   if (N14->Checked==true) SN=Form5->Edit2->Text ;                //选中的是第1台控制盒
   if (N21->Checked==true) SN=Form5->Edit4->Text ;                //选中的是第2台控制盒
   if (N31->Checked==true) SN=Form5->Edit6->Text ;                //选中的是第3台控制盒
   if (N41->Checked==true) SN=Form5->Edit8->Text ;                //选中的是第4台控制盒

   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //第4路继电器关闭
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",4,0";
   String strResponse = GetData(send_buf, data);
  }

  Image4->Picture ->LoadFromFile(light_img_4_OFF);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button15Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;
  DWORD dwTick = ::GetTickCount();    //延时函数用

  if (N10->Checked==true) {  //如果当前是局域网模式
	send_buf="RELAY-SET-1,5,1";
	ClientSocket1->Socket->SendText(send_buf);
	Image5->Picture ->LoadFromFile(light_img_5_ON);

		if (Form6->CheckBox5->Checked)    //如果是点动模式的话，需要延时后自动关闭继电器
	  {
		while (::GetTickCount() - dwTick < StrToInt(Form6->ComboBox5->Text )*1000)  //延时
		Application->ProcessMessages();
		Button16->Click();      //执行关闭按钮
	  }

  }
  else                       //如果当前是因特网模式
  {
   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }

   if (N14->Checked==true) SN=Form5->Edit2->Text ;                //选中的是第1台控制盒
   if (N21->Checked==true) SN=Form5->Edit4->Text ;                //选中的是第2台控制盒
   if (N31->Checked==true) SN=Form5->Edit6->Text ;                //选中的是第3台控制盒
   if (N41->Checked==true) SN=Form5->Edit8->Text ;                //选中的是第4台控制盒

   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //第5路继电器打开
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",5,1";
   String strResponse = GetData(send_buf, data);
   Image5->Picture ->LoadFromFile(light_img_5_ON);

	if (Form6->CheckBox5->Checked)    //如果是点动模式的话，需要延时后自动关闭继电器
	  {
		while (::GetTickCount() - dwTick < StrToInt(Form6->ComboBox5->Text )*1000)  //延时
		Application->ProcessMessages();
		Button16->Click();      //执行关闭按钮
	  }
  }


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button16Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  if (N10->Checked==true) {  //如果当前是局域网模式
	send_buf="RELAY-SET-1,5,0";
	ClientSocket1->Socket->SendText(send_buf);
  }
  else                       //如果当前是因特网模式
  {
   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }

   if (N14->Checked==true) SN=Form5->Edit2->Text ;                //选中的是第1台控制盒
   if (N21->Checked==true) SN=Form5->Edit4->Text ;                //选中的是第2台控制盒
   if (N31->Checked==true) SN=Form5->Edit6->Text ;                //选中的是第3台控制盒
   if (N41->Checked==true) SN=Form5->Edit8->Text ;                //选中的是第4台控制盒

   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //第5路继电器关闭
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",5,0";
   String strResponse = GetData(send_buf, data);
  }

  Image5->Picture ->LoadFromFile(light_img_5_OFF);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button17Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;
  DWORD dwTick = ::GetTickCount();    //延时函数用

  if (N10->Checked==true) {  //如果当前是局域网模式
	send_buf="RELAY-SET-1,6,1";
	ClientSocket1->Socket->SendText(send_buf);
	Image6->Picture ->LoadFromFile(light_img_6_ON);

		if (Form6->CheckBox6->Checked)    //如果是点动模式的话，需要延时后自动关闭继电器
	  {
		while (::GetTickCount() - dwTick < StrToInt(Form6->ComboBox6->Text )*1000)  //延时
		Application->ProcessMessages();
		Button18->Click();      //执行关闭按钮
	  }
  }
  else                       //如果当前是因特网模式
  {
   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }

   if (N14->Checked==true) SN=Form5->Edit2->Text ;                //选中的是第1台控制盒
   if (N21->Checked==true) SN=Form5->Edit4->Text ;                //选中的是第2台控制盒
   if (N31->Checked==true) SN=Form5->Edit6->Text ;                //选中的是第3台控制盒
   if (N41->Checked==true) SN=Form5->Edit8->Text ;                //选中的是第4台控制盒

   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //第6路继电器打开
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",6,1";
   String strResponse = GetData(send_buf, data);
   Image6->Picture ->LoadFromFile(light_img_6_ON);

	if (Form6->CheckBox6->Checked)    //如果是点动模式的话，需要延时后自动关闭继电器
	  {
		while (::GetTickCount() - dwTick < StrToInt(Form6->ComboBox6->Text )*1000)  //延时
		Application->ProcessMessages();
		Button18->Click();      //执行关闭按钮
	  }
  }


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button19Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;
  DWORD dwTick = ::GetTickCount();    //延时函数用

  if (N10->Checked==true) {  //如果当前是局域网模式
	send_buf="RELAY-SET-1,7,1";
	ClientSocket1->Socket->SendText(send_buf);
	Image7->Picture ->LoadFromFile(light_img_7_ON);

		if (Form6->CheckBox7->Checked)    //如果是点动模式的话，需要延时后自动关闭继电器
	  {
		while (::GetTickCount() - dwTick < StrToInt(Form6->ComboBox7->Text )*1000)  //延时
		Application->ProcessMessages();
		Button20->Click();      //执行关闭按钮
	  }
  }
  else                       //如果当前是因特网模式
  {
   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }

   if (N14->Checked==true) SN=Form5->Edit2->Text ;                //选中的是第1台控制盒
   if (N21->Checked==true) SN=Form5->Edit4->Text ;                //选中的是第2台控制盒
   if (N31->Checked==true) SN=Form5->Edit6->Text ;                //选中的是第3台控制盒
   if (N41->Checked==true) SN=Form5->Edit8->Text ;                //选中的是第4台控制盒

   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //第7路继电器打开
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",7,1";
   String strResponse = GetData(send_buf, data);
   Image7->Picture ->LoadFromFile(light_img_7_ON);

	if (Form6->CheckBox7->Checked)    //如果是点动模式的话，需要延时后自动关闭继电器
	  {
		while (::GetTickCount() - dwTick < StrToInt(Form6->ComboBox7->Text )*1000)  //延时
		Application->ProcessMessages();
		Button20->Click();      //执行关闭按钮
	  }
  }


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button20Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  if (N10->Checked==true) {  //如果当前是局域网模式
	send_buf="RELAY-SET-1,7,0";
	ClientSocket1->Socket->SendText(send_buf);
  }
  else                       //如果当前是因特网模式
  {
   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }

   if (N14->Checked==true) SN=Form5->Edit2->Text ;                //选中的是第1台控制盒
   if (N21->Checked==true) SN=Form5->Edit4->Text ;                //选中的是第2台控制盒
   if (N31->Checked==true) SN=Form5->Edit6->Text ;                //选中的是第3台控制盒
   if (N41->Checked==true) SN=Form5->Edit8->Text ;                //选中的是第4台控制盒

   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //第7路继电器关闭
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",7,0";
   String strResponse = GetData(send_buf, data);
  }

  Image7->Picture ->LoadFromFile(light_img_7_OFF);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button18Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  if (N10->Checked==true) {  //如果当前是局域网模式
	send_buf="RELAY-SET-1,6,0";
	ClientSocket1->Socket->SendText(send_buf);
  }
  else                       //如果当前是因特网模式
  {
   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }

   if (N14->Checked==true) SN=Form5->Edit2->Text ;                //选中的是第1台控制盒
   if (N21->Checked==true) SN=Form5->Edit4->Text ;                //选中的是第2台控制盒
   if (N31->Checked==true) SN=Form5->Edit6->Text ;                //选中的是第3台控制盒
   if (N41->Checked==true) SN=Form5->Edit8->Text ;                //选中的是第4台控制盒

   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //第6路继电器关闭
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",6,0";
   String strResponse = GetData(send_buf, data);
  }

  Image6->Picture ->LoadFromFile(light_img_6_OFF);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button13Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;
  DWORD dwTick = ::GetTickCount();    //延时函数用

  if (N10->Checked==true) {  //如果当前是局域网模式
	send_buf="RELAY-SET-1,8,1";
	ClientSocket1->Socket->SendText(send_buf);
	Image8->Picture ->LoadFromFile(light_img_8_ON);

		if (Form6->CheckBox8->Checked)    //如果是点动模式的话，需要延时后自动关闭继电器
	  {
		while (::GetTickCount() - dwTick < StrToInt(Form6->ComboBox8->Text )*1000)  //延时
		Application->ProcessMessages();
		Button14->Click();      //执行关闭按钮
	  }
  }
  else                       //如果当前是因特网模式
  {
   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }

   if (N14->Checked==true) SN=Form5->Edit2->Text ;                //选中的是第1台控制盒
   if (N21->Checked==true) SN=Form5->Edit4->Text ;                //选中的是第2台控制盒
   if (N31->Checked==true) SN=Form5->Edit6->Text ;                //选中的是第3台控制盒
   if (N41->Checked==true) SN=Form5->Edit8->Text ;                //选中的是第4台控制盒

   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //第8路继电器打开
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",8,1";
   String strResponse = GetData(send_buf, data);
   Image8->Picture ->LoadFromFile(light_img_8_ON);

	if (Form6->CheckBox8->Checked)    //如果是点动模式的话，需要延时后自动关闭继电器
	  {
		while (::GetTickCount() - dwTick < StrToInt(Form6->ComboBox8->Text )*1000)  //延时
		Application->ProcessMessages();
		Button14->Click();      //执行关闭按钮
	  }
  }


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button14Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  if (N10->Checked==true) {  //如果当前是局域网模式
	send_buf="RELAY-SET-1,8,0";
	ClientSocket1->Socket->SendText(send_buf);
  }
  else                       //如果当前是因特网模式
  {
   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }

   if (N14->Checked==true) SN=Form5->Edit2->Text ;                //选中的是第1台控制盒
   if (N21->Checked==true) SN=Form5->Edit4->Text ;                //选中的是第2台控制盒
   if (N31->Checked==true) SN=Form5->Edit6->Text ;                //选中的是第3台控制盒
   if (N41->Checked==true) SN=Form5->Edit8->Text ;                //选中的是第4台控制盒

   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //第8路继电器关闭
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",8,0";
   String strResponse = GetData(send_buf, data);
  }

  Image8->Picture ->LoadFromFile(light_img_8_OFF);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Config1Click(TObject *Sender)
{
Form2->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Exit1Click(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
/*   TIniFile *ini;
   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );

   ini->WriteString ( "Name_Config","Light1", Label1->Caption );
   ini->WriteString ( "Name_Config","Light2", Label2->Caption );
   ini->WriteString ( "Name_Config","Light3", Label3->Caption );
   ini->WriteString ( "Name_Config","Light4", Label4->Caption );
   ini->WriteString ( "Name_Config","Light5", Label5->Caption );
   ini->WriteString ( "Name_Config","Light6", Label6->Caption );
   ini->WriteString ( "Name_Config","Light7", Label7->Caption );
   ini->WriteString ( "Name_Config","Light8", Label8->Caption );

   delete ini;      */
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Connect1Click(TObject *Sender)
{
		ClientSocket1->Active = false;
		try
          {
			ClientSocket1->Active=true;
			DisConnect1->Enabled=true;  //断开连接按钮失效
			Connect1->Enabled =false;   //连接按钮失效
		  }
		catch(Exception &E)
          {
            ShowMessage("连接失败！"+E.Message);
        return;
		  }


//Sleep(1000);
//ClientSocket1->Socket->SendText("RELAY-STATE-1");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DisConnect1Click(TObject *Sender)
{
  ClientSocket1->Active = false;
  ClientSocket1->Close() ;

  DisConnect1->Enabled=false;  //断开连接按钮失效
  Connect1->Enabled =true;   //连接按钮失效

}
//---------------------------------------------------------------------------

void __fastcall TForm1::ClientSocket1Connect(TObject *Sender, TCustomWinSocket *Socket)

{
  StatusBar1->Panels->Items[1]->Text = "Connect OK! ";

  StatusBar1->Panels->Items[2]->Text = "设备已连接";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ClientSocket1Connecting(TObject *Sender, TCustomWinSocket *Socket)

{
  StatusBar1->Panels->Items[1]->Text = "Connecting... ";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ClientSocket1Disconnect(TObject *Sender, TCustomWinSocket *Socket)

{
   StatusBar1->Panels->Items[1]->Text = "DisConnected!" ;
   StatusBar1->Panels->Items[2]->Text = "设备未连接";
   ShowMessage("设备已断开连接");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ClientSocket1Error(TObject *Sender, TCustomWinSocket *Socket,
          TErrorEvent ErrorEvent, int &ErrorCode)
{
  StatusBar1->Panels->Items[1]->Text = "Connect to Server failed!" ;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ClientSocket1Read(TObject *Sender, TCustomWinSocket *Socket)

{
	AnsiString temp,Substr,Substr1,str,str1;
	int input_state;
    int pos; //查找字符串位置
    temp=ClientSocket1->Socket->ReceiveText();
	int real_state=0;
	int Trigger_Run=0; //触发控制输出时，送出的一次性控制8个继电器的字节参数

//------------------------------------------------------------------
	Substr=AnsiString(temp).SubString(1,18);
	if (Substr=="RELAY-SET-1,1,1,OK")
	  {
		StatusBar1->Panels->Items[1]->Text = "Relay-1 ON OK!";
	  }
//------------------------------------------------------------------
	Substr=AnsiString(temp).SubString(1,18);
	if (Substr=="RELAY-SET-1,1,0,OK")
	  {
		StatusBar1->Panels->Items[1]->Text = "Relay-1 OFF OK!";
	  }
//------------------------------------------------------------------

//------------------------------------------------------------------
	Substr=AnsiString(temp).SubString(1,18);
	if (Substr=="RELAY-SET-1,2,1,OK")
	  {
		StatusBar1->Panels->Items[1]->Text = "Relay-2 ON OK!";
	  }
//------------------------------------------------------------------
	Substr=AnsiString(temp).SubString(1,18);
	if (Substr=="RELAY-SET-1,2,0,OK")
	  {
		StatusBar1->Panels->Items[1]->Text = "Relay-2 OFF OK!";
	  }
//------------------------------------------------------------------

//------------------------------------------------------------------
	Substr=AnsiString(temp).SubString(1,18);
	if (Substr=="RELAY-SET-1,3,1,OK")
	  {
		StatusBar1->Panels->Items[1]->Text = "Relay-3 ON OK!";
	  }
//------------------------------------------------------------------
	Substr=AnsiString(temp).SubString(1,18);
	if (Substr=="RELAY-SET-1,3,0,OK")
	  {
		StatusBar1->Panels->Items[1]->Text = "Relay-3 OFF OK!";
	  }
//------------------------------------------------------------------

//------------------------------------------------------------------
	Substr=AnsiString(temp).SubString(1,18);
	if (Substr=="RELAY-SET-1,4,1,OK")
	  {
		StatusBar1->Panels->Items[1]->Text = "Relay-4 ON OK!";
	  }
//------------------------------------------------------------------
	Substr=AnsiString(temp).SubString(1,18);
	if (Substr=="RELAY-SET-1,4,0,OK")
	  {
		StatusBar1->Panels->Items[1]->Text = "Relay-4 OFF OK!";
	  }
//------------------------------------------------------------------

//------------------------------------------------------------------
	Substr=AnsiString(temp).SubString(1,18);
	if (Substr=="RELAY-SET-1,5,1,OK")
	  {
		StatusBar1->Panels->Items[1]->Text = "Relay-5 ON OK!";
	  }
//------------------------------------------------------------------
	Substr=AnsiString(temp).SubString(1,18);
	if (Substr=="RELAY-SET-1,5,0,OK")
	  {
		StatusBar1->Panels->Items[1]->Text = "Relay-5 OFF OK!";
	  }
//------------------------------------------------------------------

//------------------------------------------------------------------
	Substr=AnsiString(temp).SubString(1,18);
	if (Substr=="RELAY-SET-1,6,1,OK")
	  {
		StatusBar1->Panels->Items[1]->Text = "Relay-6 ON OK!";
	  }
//------------------------------------------------------------------
	Substr=AnsiString(temp).SubString(1,18);
	if (Substr=="RELAY-SET-1,6,0,OK")
	  {
		StatusBar1->Panels->Items[1]->Text = "Relay-6 OFF OK!";
	  }
//------------------------------------------------------------------

//------------------------------------------------------------------
	Substr=AnsiString(temp).SubString(1,18);
	if (Substr=="RELAY-SET-1,7,1,OK")
	  {
		StatusBar1->Panels->Items[1]->Text = "Relay-7 ON OK!";
	  }
//------------------------------------------------------------------
	Substr=AnsiString(temp).SubString(1,18);
	if (Substr=="RELAY-SET-1,7,0,OK")
	  {
		StatusBar1->Panels->Items[1]->Text = "Relay-7 OFF OK!";
	  }
//------------------------------------------------------------------

//------------------------------------------------------------------
	Substr=AnsiString(temp).SubString(1,18);
	if (Substr=="RELAY-SET-1,8,1,OK")
	  {
		StatusBar1->Panels->Items[1]->Text = "Relay-8 ON OK!";
	  }
//------------------------------------------------------------------
	Substr=AnsiString(temp).SubString(1,18);
	if (Substr=="RELAY-SET-1,8,0,OK")
	  {
		StatusBar1->Panels->Items[1]->Text = "Relay-8 OFF OK!";
	  }
//------------------------------------------------------------------

	Substr=AnsiString(temp).SubString(1,30);
	if (Substr=="RELAY-SCAN_DEVICE-CHANNEL_8,OK")
	  {
		StatusBar1->Panels->Items[1]->Text = "This is Relay-8 Controller";
		ClientSocket1->Socket->SendText("RELAY-TEST-NOW");
	  }
//------------------------------------------------------------------
	Substr=AnsiString(temp).SubString(1,31);
	if (Substr=="RELAY-SCAN_DEVICE-CHANNEL_32,OK")
	  {
		StatusBar1->Panels->Items[1]->Text = "This is Relay-32 Controller";
	  }
//------------------------------------------------------------------
	Substr=AnsiString(temp).SubString(1,15);
	if (Substr=="HOST-TEST-START")
	  {
		StatusBar1->Panels->Items[1]->Text = "Initialization completion";
	  }
//----------------------如果收到有线输入触发信号------如：RELAY-ALARM-3--------

	Substr=AnsiString(temp).SubString(1,12);

	if (Substr=="RELAY-ALARM-")
	  {
	    Substr1=AnsiString(temp).SubString(13,1);  //取触发路数
		ClientSocket1->Socket->SendText("RELAY-GET_INPUT-1");  //读输入状态
		StatusBar1->Panels->Items[1]->Text = "输入端被触发";

	/*	if (Form4->CheckBox1->Checked)     //如果联动第1路被选择
		 { send_buf="RELAY-SET-1,"+Form4->ComboBox1->Text +","+Form4->ComboBox9->Text;
		   ClientSocket1->Socket->SendText(send_buf);
		 }

		if (Form4->CheckBox2->Checked)     //如果联动第2路被选择
		 { send_buf="RELAY-SET-1,"+Form4->ComboBox2->Text +","+Form4->ComboBox10->Text;
		   ClientSocket1->Socket->SendText(send_buf);
		 }

		if (Form4->CheckBox1->Checked)     //如果联动第1路被选择
		 { send_buf="RELAY-SET-1,"+Form4->ComboBox1->Text +","+Form4->ComboBox9->Text;
		   ClientSocket1->Socket->SendText(send_buf);
		 }

		if (Form4->CheckBox1->Checked)     //如果联动第1路被选择
		 { send_buf="RELAY-SET-1,"+Form4->ComboBox1->Text +","+Form4->ComboBox9->Text;
		   ClientSocket1->Socket->SendText(send_buf);
		 }

		if (Form4->CheckBox1->Checked)     //如果联动第1路被选择
		 { send_buf="RELAY-SET-1,"+Form4->ComboBox1->Text +","+Form4->ComboBox9->Text;
		   ClientSocket1->Socket->SendText(send_buf);
		 }

		if (Form4->CheckBox1->Checked)     //如果联动第1路被选择
		 { send_buf="RELAY-SET-1,"+Form4->ComboBox1->Text +","+Form4->ComboBox9->Text;
		   ClientSocket1->Socket->SendText(send_buf);
		 }

		if (Form4->CheckBox1->Checked)     //如果联动第1路被选择
		 { send_buf="RELAY-SET-1,"+Form4->ComboBox1->Text +","+Form4->ComboBox9->Text;
		   ClientSocket1->Socket->SendText(send_buf);
		 }

		if (Form4->CheckBox1->Checked)     //如果联动第1路被选择
		 { send_buf="RELAY-SET-1,"+Form4->ComboBox1->Text +","+Form4->ComboBox9->Text;
		   ClientSocket1->Socket->SendText(send_buf);
		 }    */

	  }


//------------------------------------------------------------------
	Substr=AnsiString(temp).SubString(1,18);
	//返回温度值    RELAY-GET_INPUT-1,6.5,OK 或 RELAY-GET_INPUT-1,16.5,OK
	if (Substr=="RELAY-GET_INPUT-1,")
	  {
		//ShowMessage(temp);
		str=temp.SubString(19,temp.Length()-18 ); //取出  6.5,OK 或 16.5,OK
		//ShowMessage(str);
		pos=str.Pos(",");  //找出逗号的位置
		str1=AnsiString(str).SubString(1,pos-1); //取出温度值
		//ShowMessage(str1);
		real_state=StrToInt(str1);

	   if ((real_state&0x01)==0x01)
		 {
		   Shape1->Brush->Color=clLime;    //第1路输入端被触发
		   if (Form4->CheckBox1->Checked==true) //如果第1路触发输入端使能有效
			{
			  if (Form4->ComboBox1->Text=="打开") { //根据第1路继电器生成字节参数

			  ClientSocket1->Socket->SendText("RELAY-SET-1,1,1");

			  }
			  else if (Form4->ComboBox1->Text=="关闭") {
			   ;
				   }
			  else if (Form4->ComboBox1->Text=="相反") {
			   ;
				   }
			  else if (Form4->ComboBox1->Text=="不变") {
               ;
				   }





			}









		 }
	   else Shape1->Brush->Color=clRed;



	   if ((real_state&0x02)==0x02) Shape2->Brush->Color=clLime;    //第2路输入端被触发
		 else Shape2->Brush->Color=clRed;
	   if ((real_state&0x04)==0x04) Shape3->Brush->Color=clLime;    //第3路输入端被触发
		 else Shape3->Brush->Color=clRed;
	   if ((real_state&0x08)==0x08) Shape4->Brush->Color=clLime;    //第4路输入端被触发
		 else Shape4->Brush->Color=clRed;
	   if ((real_state&0x10)==0x10) Shape5->Brush->Color=clLime;    //第5路输入端被触发
		 else Shape5->Brush->Color=clRed;
	   if ((real_state&0x20)==0x20) Shape6->Brush->Color=clLime;    //第6路输入端被触发
		 else Shape6->Brush->Color=clRed;
	   if ((real_state&0x40)==0x40) Shape7->Brush->Color=clLime;    //第7路输入端被触发
		 else Shape7->Brush->Color=clRed;
	   if ((real_state&0x80)==0x80) Shape8->Brush->Color=clLime;    //第8路输入端被触发
		 else Shape8->Brush->Color=clRed;


       //如果是温度值，就显示具体数值，看固件版本而定
	   //	Label10->Caption=str1;
	   //	ProgressBar1->Position =StrToFloat(str1);
		//StatusBar1->Panels->Items[1]->Text = "Initialization completion";
	  }
//------------------------------------------------------------------







}
//---------------------------------------------------------------------------

void __fastcall TForm1::DeviceType1Click(TObject *Sender)
{
ClientSocket1->Socket->SendText("RELAY-SCAN_DEVICE-NOW");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Initialization1Click(TObject *Sender)
{
//ClientSocket1->Socket->SendText("RELAY-TEST-NOW");

  ClientSocket1->Socket->SendText("RELAY-SCAN_DEVICE-NOW");
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Sky1Click(TObject *Sender)
{
//  TStyleManager::Initialize();
//  TStyleManager::LoadFromFile("Sky.vsf");
  TStyleManager::SetStyle("Sky");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Glow1Click(TObject *Sender)
{
// TStyleManager::Initialize();
// TStyleManager::LoadFromFile("Glow.vsf");
 TStyleManager::SetStyle("GLow");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Windows101Click(TObject *Sender)
{
//  TStyleManager::Initialize();
//  TStyleManager::LoadFromFile("Silver.vsf");
  TStyleManager::SetStyle("Silver");
}
//---------------------------------------------------------------------------



void __fastcall TForm1::ConFig2Click(TObject *Sender)
{
Form3->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N2Click(TObject *Sender)
{
Form4->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button21Click(TObject *Sender)
{

  AnsiString send_buf,SN,data;

  if (N10->Checked==true) {  //如果当前是局域网模式
	send_buf="RELAY-SET_ALL-1,255";
	ClientSocket1->Socket->SendText(send_buf);
  }
  else                       //如果当前是因特网模式
  {
   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }

   if (N14->Checked==true) SN=Form5->Edit2->Text ;                //选中的是第1台控制盒
   if (N21->Checked==true) SN=Form5->Edit4->Text ;                //选中的是第2台控制盒
   if (N31->Checked==true) SN=Form5->Edit6->Text ;                //选中的是第3台控制盒
   if (N41->Checked==true) SN=Form5->Edit8->Text ;                //选中的是第4台控制盒

   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //全开
   data = "deviceCode=" + SN + "&command=RELAY-SET_ALL-" + IntToStr(time_i)+",255";
   String strResponse = GetData(send_buf, data);
  }


  Image1->Picture ->LoadFromFile(light_img_1_ON);
  Image2->Picture ->LoadFromFile(light_img_2_ON);
  Image3->Picture ->LoadFromFile(light_img_3_ON);
  Image4->Picture ->LoadFromFile(light_img_4_ON);
  Image5->Picture ->LoadFromFile(light_img_5_ON);
  Image6->Picture ->LoadFromFile(light_img_6_ON);
  Image7->Picture ->LoadFromFile(light_img_7_ON);
  Image8->Picture ->LoadFromFile(light_img_8_ON);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button22Click(TObject *Sender)
{

  AnsiString send_buf,SN,data;

  if (N10->Checked==true) {  //如果当前是局域网模式
	send_buf="RELAY-SET_ALL-1,0";
	ClientSocket1->Socket->SendText(send_buf);
  }
  else                       //如果当前是因特网模式
  {
   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }

   if (N14->Checked==true) SN=Form5->Edit2->Text ;                //选中的是第1台控制盒
   if (N21->Checked==true) SN=Form5->Edit4->Text ;                //选中的是第2台控制盒
   if (N31->Checked==true) SN=Form5->Edit6->Text ;                //选中的是第3台控制盒
   if (N41->Checked==true) SN=Form5->Edit8->Text ;                //选中的是第4台控制盒

   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //全关
   data = "deviceCode=" + SN + "&command=RELAY-SET_ALL-" + IntToStr(time_i)+",0";
   String strResponse = GetData(send_buf, data);
  }

  Image1->Picture ->LoadFromFile(light_img_1_OFF);
  Image2->Picture ->LoadFromFile(light_img_2_OFF);
  Image3->Picture ->LoadFromFile(light_img_3_OFF);
  Image4->Picture ->LoadFromFile(light_img_4_OFF);
  Image5->Picture ->LoadFromFile(light_img_5_OFF);
  Image6->Picture ->LoadFromFile(light_img_6_OFF);
  Image7->Picture ->LoadFromFile(light_img_7_OFF);
  Image8->Picture ->LoadFromFile(light_img_8_OFF);


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer2Timer(TObject *Sender)
{
  ClientSocket1->Socket->SendText("RELAY-GET_INPUT-1,1");  //读温度传感器
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N3Click(TObject *Sender)
{
  Timer2->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N4Click(TObject *Sender)
{
  Timer2->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button23Click(TObject *Sender)
{
ClientSocket1->Socket->SendText("RELAY-GET_INPUT-1");  //读输入状态
}
//---------------------------------------------------------------------------


void __fastcall TForm1::N5Click(TObject *Sender)
{

  if (N5->Checked ==true) N5->Checked =false; else { N5->Checked =true;N6->Checked =false;}

  Form3->Timer1->Enabled =true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N6Click(TObject *Sender)
{

  if (N6->Checked ==true) N6->Checked =false; else { N6->Checked =true;N5->Checked =false;}
  Form3->Timer1->Enabled =false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
//TStyleManager::Initialize();
TStyleManager::LoadFromFile("Sky.vsf");
TStyleManager::LoadFromFile("Glow.vsf");
TStyleManager::LoadFromFile("Silver.vsf");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N7Click(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N8Click(TObject *Sender)
{
  Form1->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N12Click(TObject *Sender)
{
  Form5->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N10Click(TObject *Sender)
{
   N10->Checked=true;        //选择为局域网模式
   N11->Checked=false;      //工作模式/因特网　菜单取消选择
   Device1->Enabled=true;   //本地控制　菜单　启用
   N13->Enabled=false;      //远程控制　菜单　禁用
   imer1->Enabled=true;   //定时器　菜单　启用

}
//---------------------------------------------------------------------------

void __fastcall TForm1::N11Click(TObject *Sender)
{
   N11->Checked=true;        //工作模式/因特网　菜单选择
   N10->Checked=false;      //工作模式/局域网　菜单取消选择
   Device1->Enabled=false;   //本地控制　菜单　启用
   N13->Enabled=true;      //远程控制　菜单　禁用
   imer1->Enabled=false;   //定时器　菜单　禁用

}
//---------------------------------------------------------------------------

void __fastcall TForm1::N14Click(TObject *Sender)
{
  AnsiString send_buf,SN,data,Substr,temp,str,str1;
  int i=0;
  int pos,Relay_state;

  N14->Checked=true;   //控制盒1
  N21->Checked=false;  //控制盒2
  N31->Checked=false;  //控制盒3
  N41->Checked=false;  //控制盒4

	 if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }

  if (time_i<10) { i=1;      //计数器为1位数

  }else if (i<100) {i=2;     //计数器为2位数

		}
		else i=3;            //计数器为3位数

  SN=Form5->Edit2->Text;
  send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //查询８路开关的当前状态
  data = "deviceCode=" + SN + "&command=RELAY-STATE-" + IntToStr(time_i);


 // Memo2->Text = send_buf+"?"+data;
  String strResponse = GetData(send_buf, data);
 // Memo1->Text = strResponse;
  //{"message":"Command: RELAY-STATE-5 was sent to device: 56a890e6888793c97ed33f17 successfully.","result":"RELAY-STATE-5,15,OK\u0000","status":"0"}
  //Substr为{"message":"Command: RELAY-STATE-5 was sent to device: 56a890e6888793c97ed33f17 successfully.","result":"RELAY-STATE-5,
  Substr=AnsiString(strResponse).SubString(1,117+i*2);
  temp="{\"message\":\"Command: RELAY-STATE-"+IntToStr(time_i)+" was sent to device: "+SN+" successfully.\",\"result\":\"RELAY-STATE-"+IntToStr(time_i)+",";

  if (Substr==temp) {   //获取到了当前状态的字符串
	 str=strResponse.SubString(117+i*2+1,strResponse.Length()-117+i*2 ); //取出  15,OK\u0000","status":"0"
	 pos=str.Pos(",");  //找出逗号的位置
	 str1=AnsiString(str).SubString(1,pos-1); //取出继电器状态值     15

	 Relay_state=StrToInt(str1);       //15

	 if ((Relay_state&0x01)==0x01) Image1->Picture ->LoadFromFile(light_img_1_ON);    //第1路继电器状态实时显示
		 else Image1->Picture ->LoadFromFile(light_img_1_OFF);
	 if ((Relay_state&0x02)==0x02) Image2->Picture ->LoadFromFile(light_img_2_ON);    //第2路继电器状态实时显示
		 else Image2->Picture ->LoadFromFile(light_img_2_OFF);
	 if ((Relay_state&0x04)==0x04) Image3->Picture ->LoadFromFile(light_img_3_ON);    //第3路继电器状态实时显示
		 else Image3->Picture ->LoadFromFile(light_img_3_OFF);
	 if ((Relay_state&0x08)==0x08) Image4->Picture ->LoadFromFile(light_img_4_ON);    //第4路继电器状态实时显示
		 else Image4->Picture ->LoadFromFile(light_img_4_OFF);
	 if ((Relay_state&0x10)==0x10) Image5->Picture ->LoadFromFile(light_img_5_ON);    //第5路继电器状态实时显示
		 else Image5->Picture ->LoadFromFile(light_img_5_OFF);
	 if ((Relay_state&0x20)==0x20) Image6->Picture ->LoadFromFile(light_img_6_ON);   //第6路继电器状态实时显示
		 else Image6->Picture ->LoadFromFile(light_img_6_OFF);
	 if ((Relay_state&0x40)==0x40) Image7->Picture ->LoadFromFile(light_img_7_ON);    //第7路继电器状态实时显示
		 else Image7->Picture ->LoadFromFile(light_img_7_OFF);
	 if ((Relay_state&0x80)==0x80) Image8->Picture ->LoadFromFile(light_img_8_ON);   //第8路继电器状态实时显示
		 else Image8->Picture ->LoadFromFile(light_img_8_OFF);
  }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::N21Click(TObject *Sender)
{
  AnsiString send_buf,SN,data,Substr,temp,str,str1;
  int i=0;
  int pos,Relay_state;


  N14->Checked=false;   //控制盒1
  N21->Checked=true;  //控制盒2
  N31->Checked=false;  //控制盒3
  N41->Checked=false;  //控制盒4

     if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }

  if (time_i<10) { i=1;      //计数器为1位数

  }else if (i<100) {i=2;     //计数器为2位数

		}
		else i=3;            //计数器为3位数

  SN=Form5->Edit4->Text;
  send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //查询８路开关的当前状态
  data = "deviceCode=" + SN + "&command=RELAY-STATE-" + IntToStr(time_i);


//  Memo2->Text = send_buf+"?"+data;
  String strResponse = GetData(send_buf, data);
 // Memo1->Text = strResponse;
  //{"message":"Command: RELAY-STATE-5 was sent to device: 56a890e6888793c97ed33f17 successfully.","result":"RELAY-STATE-5,15,OK\u0000","status":"0"}
  //Substr为{"message":"Command: RELAY-STATE-5 was sent to device: 56a890e6888793c97ed33f17 successfully.","result":"RELAY-STATE-5,
  Substr=AnsiString(strResponse).SubString(1,117+i*2);
  temp="{\"message\":\"Command: RELAY-STATE-"+IntToStr(time_i)+" was sent to device: "+SN+" successfully.\",\"result\":\"RELAY-STATE-"+IntToStr(time_i)+",";

  if (Substr==temp) {   //获取到了当前状态的字符串
	 str=strResponse.SubString(117+i*2+1,strResponse.Length()-117+i*2 ); //取出  15,OK\u0000","status":"0"
	 pos=str.Pos(",");  //找出逗号的位置
	 str1=AnsiString(str).SubString(1,pos-1); //取出继电器状态值     15

	 Relay_state=StrToInt(str1);       //15

	 if ((Relay_state&0x01)==0x01) Image1->Picture ->LoadFromFile(light_img_1_ON);    //第1路继电器状态实时显示
		 else Image1->Picture ->LoadFromFile(light_img_1_OFF);
	 if ((Relay_state&0x02)==0x02) Image2->Picture ->LoadFromFile(light_img_2_ON);    //第2路继电器状态实时显示
		 else Image2->Picture ->LoadFromFile(light_img_2_OFF);
	 if ((Relay_state&0x04)==0x04) Image3->Picture ->LoadFromFile(light_img_3_ON);    //第3路继电器状态实时显示
		 else Image3->Picture ->LoadFromFile(light_img_3_OFF);
	 if ((Relay_state&0x08)==0x08) Image4->Picture ->LoadFromFile(light_img_4_ON);    //第4路继电器状态实时显示
		 else Image4->Picture ->LoadFromFile(light_img_4_OFF);
	 if ((Relay_state&0x10)==0x10) Image5->Picture ->LoadFromFile(light_img_5_ON);    //第5路继电器状态实时显示
		 else Image5->Picture ->LoadFromFile(light_img_5_OFF);
	 if ((Relay_state&0x20)==0x20) Image6->Picture ->LoadFromFile(light_img_6_ON);   //第6路继电器状态实时显示
		 else Image6->Picture ->LoadFromFile(light_img_6_OFF);
	 if ((Relay_state&0x40)==0x40) Image7->Picture ->LoadFromFile(light_img_7_ON);    //第7路继电器状态实时显示
		 else Image7->Picture ->LoadFromFile(light_img_7_OFF);
	 if ((Relay_state&0x80)==0x80) Image8->Picture ->LoadFromFile(light_img_8_ON);   //第8路继电器状态实时显示
		 else Image8->Picture ->LoadFromFile(light_img_8_OFF);
  }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::N31Click(TObject *Sender)
{
  AnsiString send_buf,SN,data,Substr,temp,str,str1;
  int i=0;
  int pos,Relay_state;

  N14->Checked=false;   //控制盒1
  N21->Checked=false;  //控制盒2
  N31->Checked=true;  //控制盒3
  N41->Checked=false;  //控制盒4

   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }

  if (time_i<10) { i=1;      //计数器为1位数

  }else if (i<100) {i=2;     //计数器为2位数

		}
		else i=3;            //计数器为3位数

  SN=Form5->Edit6->Text;
  send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //查询８路开关的当前状态
  data = "deviceCode=" + SN + "&command=RELAY-STATE-" + IntToStr(time_i);


 // Memo2->Text = send_buf+"?"+data;
  String strResponse = GetData(send_buf, data);
 // Memo1->Text = strResponse;
  //{"message":"Command: RELAY-STATE-5 was sent to device: 56a890e6888793c97ed33f17 successfully.","result":"RELAY-STATE-5,15,OK\u0000","status":"0"}
  //Substr为{"message":"Command: RELAY-STATE-5 was sent to device: 56a890e6888793c97ed33f17 successfully.","result":"RELAY-STATE-5,
  Substr=AnsiString(strResponse).SubString(1,117+i*2);
  temp="{\"message\":\"Command: RELAY-STATE-"+IntToStr(time_i)+" was sent to device: "+SN+" successfully.\",\"result\":\"RELAY-STATE-"+IntToStr(time_i)+",";

  if (Substr==temp) {   //获取到了当前状态的字符串
	 str=strResponse.SubString(117+i*2+1,strResponse.Length()-117+i*2 ); //取出  15,OK\u0000","status":"0"
	 pos=str.Pos(",");  //找出逗号的位置
	 str1=AnsiString(str).SubString(1,pos-1); //取出继电器状态值     15

	 Relay_state=StrToInt(str1);       //15

	 if ((Relay_state&0x01)==0x01) Image1->Picture ->LoadFromFile(light_img_1_ON);    //第1路继电器状态实时显示
		 else Image1->Picture ->LoadFromFile(light_img_1_OFF);
	 if ((Relay_state&0x02)==0x02) Image2->Picture ->LoadFromFile(light_img_2_ON);    //第2路继电器状态实时显示
		 else Image2->Picture ->LoadFromFile(light_img_2_OFF);
	 if ((Relay_state&0x04)==0x04) Image3->Picture ->LoadFromFile(light_img_3_ON);    //第3路继电器状态实时显示
		 else Image3->Picture ->LoadFromFile(light_img_3_OFF);
	 if ((Relay_state&0x08)==0x08) Image4->Picture ->LoadFromFile(light_img_4_ON);    //第4路继电器状态实时显示
		 else Image4->Picture ->LoadFromFile(light_img_4_OFF);
	 if ((Relay_state&0x10)==0x10) Image5->Picture ->LoadFromFile(light_img_5_ON);    //第5路继电器状态实时显示
		 else Image5->Picture ->LoadFromFile(light_img_5_OFF);
	 if ((Relay_state&0x20)==0x20) Image6->Picture ->LoadFromFile(light_img_6_ON);   //第6路继电器状态实时显示
		 else Image6->Picture ->LoadFromFile(light_img_6_OFF);
	 if ((Relay_state&0x40)==0x40) Image7->Picture ->LoadFromFile(light_img_7_ON);    //第7路继电器状态实时显示
		 else Image7->Picture ->LoadFromFile(light_img_7_OFF);
	 if ((Relay_state&0x80)==0x80) Image8->Picture ->LoadFromFile(light_img_8_ON);   //第8路继电器状态实时显示
		 else Image8->Picture ->LoadFromFile(light_img_8_OFF);
  }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::N41Click(TObject *Sender)
{
  AnsiString send_buf,SN,data,Substr,temp,str,str1;
  int i=0;
  int pos,Relay_state;

  N14->Checked=false;   //控制盒1
  N21->Checked=false;  //控制盒2
  N31->Checked=false;  //控制盒3
  N41->Checked=true;  //控制盒4

   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }

  if (time_i<10) { i=1;      //计数器为1位数

  }else if (i<100) {i=2;     //计数器为2位数

		}
		else i=3;            //计数器为3位数

  SN=Form5->Edit8->Text;
  send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //查询８路开关的当前状态
  data = "deviceCode=" + SN + "&command=RELAY-STATE-" + IntToStr(time_i);


 // Memo2->Text = send_buf+"?"+data;
  String strResponse = GetData(send_buf, data);
 // Memo1->Text = strResponse;
  //{"message":"Command: RELAY-STATE-5 was sent to device: 56a890e6888793c97ed33f17 successfully.","result":"RELAY-STATE-5,15,OK\u0000","status":"0"}
  //Substr为{"message":"Command: RELAY-STATE-5 was sent to device: 56a890e6888793c97ed33f17 successfully.","result":"RELAY-STATE-5,
  Substr=AnsiString(strResponse).SubString(1,117+i*2);
  temp="{\"message\":\"Command: RELAY-STATE-"+IntToStr(time_i)+" was sent to device: "+SN+" successfully.\",\"result\":\"RELAY-STATE-"+IntToStr(time_i)+",";

  if (Substr==temp) {   //获取到了当前状态的字符串
	 str=strResponse.SubString(117+i*2+1,strResponse.Length()-117+i*2 ); //取出  15,OK\u0000","status":"0"
	 pos=str.Pos(",");  //找出逗号的位置
	 str1=AnsiString(str).SubString(1,pos-1); //取出继电器状态值     15

	 Relay_state=StrToInt(str1);       //15

	 if ((Relay_state&0x01)==0x01) Image1->Picture ->LoadFromFile(light_img_1_ON);    //第1路继电器状态实时显示
		 else Image1->Picture ->LoadFromFile(light_img_1_OFF);
	 if ((Relay_state&0x02)==0x02) Image2->Picture ->LoadFromFile(light_img_2_ON);    //第2路继电器状态实时显示
		 else Image2->Picture ->LoadFromFile(light_img_2_OFF);
	 if ((Relay_state&0x04)==0x04) Image3->Picture ->LoadFromFile(light_img_3_ON);    //第3路继电器状态实时显示
		 else Image3->Picture ->LoadFromFile(light_img_3_OFF);
	 if ((Relay_state&0x08)==0x08) Image4->Picture ->LoadFromFile(light_img_4_ON);    //第4路继电器状态实时显示
		 else Image4->Picture ->LoadFromFile(light_img_4_OFF);
	 if ((Relay_state&0x10)==0x10) Image5->Picture ->LoadFromFile(light_img_5_ON);    //第5路继电器状态实时显示
		 else Image5->Picture ->LoadFromFile(light_img_5_OFF);
	 if ((Relay_state&0x20)==0x20) Image6->Picture ->LoadFromFile(light_img_6_ON);   //第6路继电器状态实时显示
		 else Image6->Picture ->LoadFromFile(light_img_6_OFF);
	 if ((Relay_state&0x40)==0x40) Image7->Picture ->LoadFromFile(light_img_7_ON);    //第7路继电器状态实时显示
		 else Image7->Picture ->LoadFromFile(light_img_7_OFF);
	 if ((Relay_state&0x80)==0x80) Image8->Picture ->LoadFromFile(light_img_8_ON);   //第8路继电器状态实时显示
		 else Image8->Picture ->LoadFromFile(light_img_8_OFF);
  }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::N16Click(TObject *Sender)
{
Form6->Show();
}
//---------------------------------------------------------------------------

