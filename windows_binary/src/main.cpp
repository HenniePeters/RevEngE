//---------------------------------------------------------------------------
#include <vcl.h>
#include <stdint.h>
#include <stdio.h>
#include <jpeg.hpp>
#include <GIFImage.hpp>
#pragma hdrstop
#include "pref.h"
#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmMain *frmMain;
//---------------------------------------------------------------------------
__fastcall TfrmMain::TfrmMain(TComponent* Owner) : TForm(Owner) {

}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::FormCreate(TObject *Sender) {
    frmMain->DoubleBuffered = true;
    IniFile = "";
    IniFile += getenv("APPDATA");
    IniFile += "\\RevEngE\\";
    if( ! DirectoryExists( asIniFile ) ) {
        CreateDirectory( asIniFile.c_str(), NULL );
    }
    IniFile += "RevEngE.ini";
    iDefaultGradient = GetPrivateProfileInt( "RevEngE", "Gradient", 2, IniFile.c_str() );
    if( iDefaultGradient > 5 ) {
        iDefaultGradient = 5;
    }

    iMirror = GetPrivateProfileInt( "RevEngE", "Mirror", 0, IniFile.c_str() );

    char buf[32];
    GetPrivateProfileString( "RevEngE", "Proportional", "true", buf, 32, IniFile.c_str() );
    if( strcmp( buf, "true" ) == 0 ) {
        Image3->Proportional = true;
        Image3->Stretch = false;
    } else {
        Image3->Stretch = true;
        Image3->Proportional = false;
    }
    StatusBar1->Panels[0].Items[0]->Width = StatusBar1->Width / 2;
    StatusBar1->Panels[0].Items[1]->Width = StatusBar1->Width / 2;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::FormClose(TObject *Sender, TCloseAction &Action) {
    char buf[16];
    WritePrivateProfileString( "RevEngE", "Mirror", itoa( iMirror, buf, 10 ), IniFile.c_str() );
    WritePrivateProfileString( "RevEngE", "Gradient", itoa( iDefaultGradient, buf, 10 ), IniFile.c_str() );
    WritePrivateProfileString( "RevEngE", "Proportional", Image3->Proportional ? "true" : "false", IniFile.c_str() );
    if( asFileName1 != "" ) {
        WritePrivateProfileString( "RevEngE", "FileName1", asFileName1.c_str(), IniFile.c_str() );
    }
    if( asFileName2 != "" ) {
        WritePrivateProfileString( "RevEngE", "FileName2", asFileName2.c_str(), IniFile.c_str() );
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::mnuAboutRevEngEClick(TObject *Sender) {
    AnsiString as = "";
    as += "RevEngE v.1.0.0 beta\r\n";
    as += "Reverse Engineering tool for Electronics\r\n";
    as += "\r\n";
    as += "Borland\t\tC++Builder 6.0 (BCB6)\r\n";
    as += "\r\n";
    as += "Project:\t\thttps://github.com/HenniePeters/RevEngE/\r\n";
    as += "\r\n";
    as += "Requested by:\tDave Jones (eevblog.com)\r\n";
    as += "\r\n";
    as += "Developers:\r\n";
    as += "----------\r\n";
    as += "Hennie Peters\tBCB6 Programming\r\n";
    as += "Finn Tolderlund\tAdaptation of the TGIFImage component\r\n";
    as += "Anders Melander\tCreator of TGIFImage component\r\n";

    Application->MessageBoxA( as.c_str() , "    About RevEngE", 0);
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::mnuHowToClick(TObject *Sender) {
    AnsiString as = "";
    as += "Prepare both image files in an image editor:\r\n";
    as += "\t- Component and the solderside images should have the same size and aspect ratio.\r\n";
    as += "\t- Sometimes a perpective correction is needed.\r\n";
    as += "\r\n";
    as += "Load both the component and the solderside images in this application.\r\n";
    as += "Change the gradient between the images with the mousewheel.\r\n";
    as += "One of the images should be mirrored, to do that select the mirror option in preferences.\r\n";
    as += "\r\n";
    as += "\r\n";
    as += "On the ToDo list are:\r\n";
    as += "Add support for portable network graphics (png).\r\n";
    as += "Perspective correction and stretching in X and Y axes.\r\n";
    as += "For the time being, use your favourite image editor.\r\n";
    Application->MessageBoxA( as.c_str() , "    How to use RevEngE", 0);
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::mnuExitClick(TObject *Sender) {
    this->Close();
    Application->Terminate();
}
//---------------------------------------------------------------------------
void TfrmMain::LoadFile1( AnsiString FileName ) {
    AnsiString as;
    if( ! FileExists( FileName ) ) {
        return; // make sure it exists, else get out.
    }
    AnsiString temp2 = ExtractFileName(FileName);
    AnsiString temp = ExtractFileExt(FileName);
    AnsiString Ext = temp.LowerCase();
    if( Ext == ".jpg" || Ext == ".jpeg" ) {  // it's a jpg
        // Decompress the jpeg image into a bitmap.
        TJPEGImage *myjpeg = new TJPEGImage();
        myjpeg->LoadFromFile(FileName);
        myjpeg->DIBNeeded();  // used when jpeg image needs bitmap rep
        Image1->Picture->Bitmap->Assign(myjpeg);
        delete myjpeg;
    } else if( Ext == ".bmp" ) {
        Image1->Picture->Bitmap->LoadFromFile( FileName );
        Image1->Picture->Bitmap->PixelFormat = pf24bit;
    } else if( Ext == ".gif" ) {
        TGIFImage *mygif = new TGIFImage();
        mygif->LoadFromFile(FileName);
        Image1->Picture->Bitmap->Assign(mygif);
        Image1->Picture->Bitmap->PixelFormat = pf24bit;
        delete mygif;
    }
    as = "Load image&1 (";
    as += FileName;
    as += ")";
    mnuLoadImage1->Caption = as;
    asFileName1 = FileName;
    DisplayStatus();
    iGradient = iDefaultGradient;
    MirrorImage( 1 );
    ProcessImages();
}
//---------------------------------------------------------------------------
void TfrmMain::LoadFile2( AnsiString FileName ) {
    AnsiString as;
    if( ! FileExists( FileName ) ) {
        return; // make sure it exists, else get out.
    }
    AnsiString temp2 = ExtractFileName(FileName);
    AnsiString temp = ExtractFileExt(FileName);
    AnsiString Ext = temp.LowerCase();
    if( Ext == ".jpg" || Ext == ".jpeg" ) {  // it's a jpg
        // Decompress the jpeg image into a bitmap.
        TJPEGImage *myjpeg = new TJPEGImage();
        myjpeg->LoadFromFile(FileName);
        myjpeg->DIBNeeded();  // used when jpeg image needs bitmap rep
        Image2->Picture->Bitmap->Assign(myjpeg);
        Image3->Picture->Bitmap->Assign(myjpeg);
        delete myjpeg;
    } else if( Ext == ".bmp" ) {
        Image2->Picture->Bitmap->LoadFromFile( FileName );
        Image2->Picture->Bitmap->PixelFormat = pf24bit;
        Image3->Picture->Bitmap->Assign( Image2->Picture->Bitmap );
        Image3->Picture->Bitmap->PixelFormat = pf24bit;
    } else if( Ext == ".gif" ) {
        TGIFImage *mygif = new TGIFImage();
        mygif->LoadFromFile(FileName);
        Image2->Picture->Bitmap->Assign(mygif);
        Image2->Picture->Bitmap->PixelFormat = pf24bit;
        Image3->Picture->Bitmap->Assign(mygif);
        Image3->Picture->Bitmap->PixelFormat = pf24bit;
        delete mygif;
    }
    as = "Load image&2 (";
    as += FileName;
    as += ")";
    mnuLoadImage2->Caption = as;
    asFileName2 = FileName;
    DisplayStatus();
    iGradient = iDefaultGradient;
    MirrorImage( 2 );
    ProcessImages();
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::mnuLoadImage1Click(TObject *Sender) {
    if( OpenPictureDialog1->Execute() ) {
        int c = OpenPictureDialog1->Files->Count;
        if( c >= 1 && c <=2 ) {
            for( int i=0; i<c; i++ ) {
                //Application->MessageBoxA( OpenPictureDialog1->Files->Strings[i].c_str(), "RevEngE", 0);

                switch(i) {
                    case 0:
                        LoadFile1(OpenPictureDialog1->Files->Strings[i]);
                        break;
                    case 1:
                        LoadFile2(OpenPictureDialog1->Files->Strings[i]);
                        break;
                }
            }
        } else {
            Application->MessageBoxA( "Select 1 or 2 images please!", "2 images will be sufficient", 0 );
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::mnuLoadImage2Click(TObject *Sender) {
    if( OpenPictureDialog1->Execute() ) {
        int c = OpenPictureDialog1->Files->Count;
        if( c == 2 ) {
            for( int i=0; i<c; i++ ) {
                switch(i) {
                    case 0:
                        LoadFile1(OpenPictureDialog1->Files->Strings[i]);
                        break;
                    case 1:
                        LoadFile2(OpenPictureDialog1->Files->Strings[i]);
                        break;
                }
            }
        } else if( c == 1 ) {
            LoadFile2(OpenPictureDialog1->Files->Strings[0]);
        } else {
            Application->MessageBoxA( "Select 1 or 2 images please!", "2 images will be sufficient", 0 );
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::mnuPreferencesClick(TObject *Sender) {
    if( Image3->Proportional ) {
        frmPref->chkStretched->Checked = false;
        frmPref->chkProportional->Checked = true;
    }
    if( Image3->Stretch ) {
        frmPref->chkProportional->Checked = false;
        frmPref->chkStretched->Checked = true;
    }
    frmPref->trbGradient->Position = this->DefaultGradient;
    frmPref->Mirror = iMirror;
    frmPref->Top = frmMain->Top + frmMain->Height / 2 - frmPref->Height / 2;
    frmPref->Left = frmMain->Left + frmMain->Width / 2 - frmPref->Width / 2;
    frmPref->ShowModal();
    LoadFile1( FileName1 );
    LoadFile2( FileName2 );
    ProcessImages();
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::FormMouseWheel(TObject *Sender, TShiftState Shift, int WheelDelta, TPoint &MousePos, bool &Handled) {
    int iTemp = Gradient;
    if( WheelDelta > 0 && Gradient > 0 ) {
        Gradient--;
        if( Gradient < 0) {
            Gradient = 0;
        }
    } else if( WheelDelta < 0 && Gradient < 5 ) {
        Gradient++;
        if( Gradient > 5 ) {
            Gradient = 5;
        }
    }
    if( iTemp != Gradient ) {
        ProcessImages();
        DisplayStatus();
    }
}
//---------------------------------------------------------------------------
void TfrmMain::ProcessImages(void) {
    register uint8_t *p1, *p2, *p3;
    if( asFileName1 != "" && asFileName2 != "" ) {
        for( int y=0; y<Image1->Picture->Bitmap->Height-1 && y<Image2->Picture->Bitmap->Height-1; y++ ) {
            //const char *file = "V:\\CBuilder\\RevEnge\\RevEngE.log";
            //if( FileExists( file ) ) {
            //    FILE *fp = fopen( file, "w" );
            //    fprintf( fp, "%d", y );
            //    fclose(fp);
            //}
            p1 = (uint8_t*) Image1->Picture->Bitmap->ScanLine[y];
            p2 = (uint8_t*) Image2->Picture->Bitmap->ScanLine[y];
            p3 = (uint8_t*) Image3->Picture->Bitmap->ScanLine[y];
            for( int x=0; x<Image1->Picture->Bitmap->Width && x<Image2->Picture->Bitmap->Width; x++ ) {
                p3[x * 3]     = ( (  p1[x * 3] *     ( 255 - (50 * Gradient + Gradient ) ) )
                              + (    p2[x * 3] *              50 * Gradient + Gradient ) ) / 255;
                p3[x * 3 + 1] = ( (  p1[x * 3 + 1] * ( 255 - (50 * Gradient + Gradient ) ) )
                              + (    p2[x * 3 + 1] *          50 * Gradient + Gradient ) ) / 255;
                p3[x * 3 + 2] = ( (  p1[x * 3 + 2] * ( 255 - (50 * Gradient + Gradient ) ) )
                              + (    p2[x * 3 + 2] *          50 * Gradient + Gradient ) ) / 255;
            }
        }
    }
    Refresh();
}
//---------------------------------------------------------------------------
void TfrmMain::DisplayStatus(void) {
    StatusBar1->Panels[0].Items[0]->Text = ExtractFileName(asFileName1);
    StatusBar1->Panels[0].Items[1]->Text = ExtractFileName(asFileName2);
    if( asFileName1 != "" && asFileName2 != "" ) {
        AnsiString as = ExtractFileName(asFileName1);
        int grad = 100 - Gradient * 20;
        as += "   ";
        as += grad;
        as += "%";
        StatusBar1->Panels[0].Items[0]->Text = as;
        as = ExtractFileName(asFileName2);
        as += "   ";
        as += 100 - grad;
        as += "%";
        StatusBar1->Panels[0].Items[1]->Text = as;
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::mnuLatestClick(TObject *Sender) {
    char buf[256];
    GetPrivateProfileString( "RevEngE", "FileName1", "", buf, 256, IniFile.c_str() );
    asFileName1 = buf;
    GetPrivateProfileString( "RevEngE", "FileName2", "", buf, 256, IniFile.c_str() );
    asFileName2 = buf;
    iGradient = iDefaultGradient;
    LoadFile1( asFileName1 );
    LoadFile2( asFileName2 );
    DisplayStatus();
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::FormResize(TObject *Sender) {
    StatusBar1->Panels[0].Items[0]->Width = StatusBar1->Width / 2;
    StatusBar1->Panels[0].Items[1]->Width = StatusBar1->Width / 2;
}
//---------------------------------------------------------------------------
void swap( register uint8_t *x1, register uint8_t *x2 ) {
    register uint8_t tmp;
    tmp = *x1;
    *x1 = *x2;
    *x2 = tmp;
}
//---------------------------------------------------------------------------
void TfrmMain::MirrorImage( int iMirrorParam ) {
    int w;
    register uint8_t *p;
    Graphics::TBitmap *pBitmap;
    if( iMirror == 1 && iMirrorParam == 1 && FileName1 != "" ) {
        pBitmap = Image1->Picture->Bitmap;
        w = Image1->Picture->Bitmap->Width / 2;
    } else if( iMirror == 2 && iMirrorParam == 2 && FileName2 != "") {
        pBitmap = Image2->Picture->Bitmap;
        w = Image2->Picture->Bitmap->Width / 2;
    } else {
        return;
    }
    if( asFileName1 != "" && asFileName2 != "" ) {
        for( int y=0; y<pBitmap->Height-1; y++ ) {
            p = (uint8_t*) pBitmap->ScanLine[y];
            for( register int x=0; x<w; x++ ) {
                swap( &(p[x * 3]    ), &(p[(pBitmap->Width - x) * 3    ]) );
                swap( &(p[x * 3 + 1]), &(p[(pBitmap->Width - x) * 3 + 1]) );
                swap( &(p[x * 3 + 2]), &(p[(pBitmap->Width - x) * 3 + 2]) );
            }
        }
    }
}
//---------------------------------------------------------------------------

