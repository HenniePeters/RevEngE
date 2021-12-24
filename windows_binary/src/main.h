//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <Dialogs.hpp>
#include <ExtDlgs.hpp>
//---------------------------------------------------------------------------
class TfrmMain : public TForm
{
__published:	// IDE-managed Components
    TStatusBar *StatusBar1;
    TMainMenu *MainMenu1;
    TMenuItem *mnuFile;
    TMenuItem *mnuHelp;
    TMenuItem *mnuLoadImage1;
    TMenuItem *mnuLoadImage2;
    TMenuItem *mnuLatest;
    TMenuItem *mnuExit;
    TImage *Image1;
    TMenuItem *mnuAboutRevEngE;
    TOpenPictureDialog *OpenPictureDialog1;
    TImage *Image2;
    TImage *Image3;
    TMenuItem *mnuPreferences;
    TMenuItem *mnuHowTo;
    void __fastcall mnuExitClick(TObject *Sender);
    void __fastcall mnuAboutRevEngEClick(TObject *Sender);
    void __fastcall mnuLoadImage1Click(TObject *Sender);
    void __fastcall mnuLoadImage2Click(TObject *Sender);
    void __fastcall mnuPreferencesClick(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall FormMouseWheel(TObject *Sender, TShiftState Shift,
          int WheelDelta, TPoint &MousePos, bool &Handled);
    void __fastcall mnuLatestClick(TObject *Sender);
    void __fastcall FormResize(TObject *Sender);
    void __fastcall mnuHowToClick(TObject *Sender);
private:
    int iDefaultGradient, iGradient;
    AnsiString asIniFile;
    AnsiString asFileName1;
    AnsiString asFileName2;
    void LoadFile1(AnsiString FileName);
    void LoadFile2(AnsiString FileName);
    void ProcessImages(void);
    void DisplayStatus(void);
    void MirrorImage(int);
    __property AnsiString IniFile  = { read=asIniFile, write=asIniFile };
    __property AnsiString FileName1  = { read=asFileName1, write=asFileName1 };
    __property AnsiString FileName2  = { read=asFileName2, write=asFileName2 };	// User declarations
public:		// User declarations
    int iMirror;
    __fastcall TfrmMain(TComponent* Owner);
    __property int DefaultGradient  = { read=iDefaultGradient, write=iDefaultGradient };
    __property int Gradient  = { read=iGradient, write=iGradient };
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmMain *frmMain;
//---------------------------------------------------------------------------
#endif
