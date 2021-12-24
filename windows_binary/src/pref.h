//---------------------------------------------------------------------------

#ifndef prefH
#define prefH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TfrmPref : public TForm {
__published:	// IDE-managed Components
    TLabel *Label1;
    TButton *cmdOK;
    TButton *cmdCancel;
    TGroupBox *GroupBox1;
    TRadioButton *chkStretched;
    TRadioButton *chkProportional;
    TGroupBox *GroupBox2;
    TRadioButton *chkMirror1;
    TRadioButton *chkMirror2;
    TRadioButton *chkMirrorNone;
    TGroupBox *GroupBox3;
    TLabel *Label2;
    TLabel *Label3;
    TTrackBar *trbGradient;
    void __fastcall cmdCancelClick(TObject *Sender);
    void __fastcall cmdOKClick(TObject *Sender);
    void __fastcall chkMirror1Click(TObject *Sender);
    void __fastcall chkMirror2Click(TObject *Sender);
    void __fastcall chkMirrorNoneClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
private:	// User declarations
    int iMirror;
public:		// User declarations
    __fastcall TfrmPref(TComponent* Owner);
    __property int Mirror  = { read=iMirror, write=iMirror };
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmPref *frmPref;
//---------------------------------------------------------------------------
#endif
