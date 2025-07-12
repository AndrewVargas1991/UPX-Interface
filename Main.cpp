//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormShow(TObject *Sender)
{
        // Esse botão foi criado apenas para tirar o foco inicial dos botões visíveis
        Button1->SetFocus();
        Button1->Visible = False;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
    OpenDialog1->Filter = "Arquivos executáveis (*.exe)|*.exe|Todos os arquivos (*.*)|*.*";
    OpenDialog1->InitialDir = ExtractFilePath(Application->ExeName);

    if (OpenDialog1->Execute())
    {
	Application->MessageBox(L"Aguarde enquanto o UPX comprime o executável.", L"Aviso UPX", MB_OK);
        std::wstring arquivo = OpenDialog1->FileName.c_str();
        std::wstring comando = L"upx -9f \"" + arquivo + L"\"";
        _wsystem(comando.c_str());
        Application->MessageBox(L"Arquivo comprimido.", L"Aviso UPX", MB_OK);
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
    OpenDialog1->Filter = "Arquivos executáveis (*.exe)|*.exe|Todos os arquivos (*.*)|*.*";
    OpenDialog1->InitialDir = ExtractFilePath(Application->ExeName);

    if (OpenDialog1->Execute())
    {
        Application->MessageBox(L"Aguarde enquanto o UPX descomprime o executável.", L"Aviso UPX", MB_OK);
        std::wstring arquivo = OpenDialog1->FileName.c_str();
        std::wstring comando = L"upx -d \"" + arquivo + L"\"";
        _wsystem(comando.c_str());
        Application->MessageBox(L"Arquivo descomprimido.", L"Aviso UPX", MB_OK);
    }
}
//---------------------------------------------------------------------------
