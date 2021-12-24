//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "pref.h"
#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmPref *frmPref;
//---------------------------------------------------------------------------
__fastcall TfrmPref::TfrmPref(TComponent* Owner) : TForm(Owner) {
    iMirror = 0;
}
//---------------------------------------------------------------------------
void __fastcall TfrmPref::FormShow(TObject *Sender) {
    if( iMirror == 1 ) {
        chkMirror1->Checked = true;
    } else if( iMirror == 2 ) {
        chkMirror2->Checked = true;
    } else {
        chkMirrorNone->Checked = true;
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmPref::cmdCancelClick(TObject *Sender) {
    this->Close();
}
//---------------------------------------------------------------------------
void __fastcall TfrmPref::cmdOKClick(TObject *Sender) {
    frmMain->DefaultGradient = trbGradient->Position;
    frmMain->iMirror = iMirror;
    if( chkProportional->Checked ) {
        frmMain->Image3->Stretch = false;
        frmMain->Image3->Proportional = true;
    }
    if( chkStretched->Checked ) {
        frmMain->Image3->Proportional = false;
        frmMain->Image3->Stretch = true;
    }
    this->Close();
}
//---------------------------------------------------------------------------
void __fastcall TfrmPref::chkMirror1Click(TObject *Sender) {
    iMirror = 1;
}
//---------------------------------------------------------------------------
void __fastcall TfrmPref::chkMirror2Click(TObject *Sender) {
    iMirror = 2;
}
//---------------------------------------------------------------------------
void __fastcall TfrmPref::chkMirrorNoneClick(TObject *Sender) {
    iMirror = 0;
}
//---------------------------------------------------------------------------

