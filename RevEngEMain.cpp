/***************************************************************
    Name:      RevEngEMain.cpp
    Purpose:   Code for Application Frame
    Author:    Hennie Peters (hennie.dot.peters.at.gmail.dot.com)
    Created:   2021-08-30
    Copyright: Hennie Peters ()
    License:
 **************************************************************/

#include <wx/msgdlg.h>
#include <wx/wx.h>
#include "RevEngEMain.h"
#include "Config.h"

//(*InternalHeaders(RevEngEFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f
};

wxString wxbuildinfo( wxbuildinfoformat format ) {
    wxString wxbuild( _T( "\r\nRevEngE v. 1.0\r\n\r\n" ) );
    wxbuild << _( CB_VERSION );
    wxbuild << _( "\r\n" );
    wxbuild << wxVERSION_STRING;
    if( format == long_f ) {
#if defined(__WXMSW__)
        wxbuild << _T( "-Windows" );
#elif defined(__UNIX__)
        wxbuild << _T( "-Linux" );
#endif
#if wxUSE_UNICODE
        wxbuild << _T( "-Unicode build" );
#else
        wxbuild << _T( "-ANSI build" );
#endif // wxUSE_UNICODE
    }
    return wxbuild;
}

class AppConfigData *config = new class AppConfigData("RevEngE");

//(*IdInit(RevEngEFrame)
const long RevEngEFrame::ID_STATICBITMAP1 = wxNewId();
const long RevEngEFrame::ID_MENU_LOAD1 = wxNewId();
const long RevEngEFrame::ID_MENU_LOAD2 = wxNewId();
const long RevEngEFrame::ID_MENU_LATEST = wxNewId();
const long RevEngEFrame::ID_MENUITEM1 = wxNewId();
const long RevEngEFrame::idMenuAbout = wxNewId();
//*)

BEGIN_EVENT_TABLE( RevEngEFrame, wxFrame )
    //(*EventTable(RevEngEFrame)
    //*)
    EVT_PAINT( RevEngEFrame::OnPaint )
    EVT_MOUSEWHEEL( RevEngEFrame::OnScroll )
    EVT_SIZE( RevEngEFrame::OnSize )
END_EVENT_TABLE()

RevEngEFrame::RevEngEFrame( wxWindow* parent, wxWindowID id ) {
    //(*Initialize(RevEngEFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, wxID_ANY, _("RevEngE"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(1331,766));
    SetForegroundColour(wxColour(0,0,0));
    StaticBitmap1 = new wxStaticBitmap(this, ID_STATICBITMAP1, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxFULL_REPAINT_ON_RESIZE, _T("ID_STATICBITMAP1"));
    StaticBitmap1->SetMinSize(wxSize(0,0));
    StaticBitmap1->SetMaxSize(wxSize(0,0));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem5 = new wxMenuItem(Menu1, ID_MENU_LOAD1, _("Load image&1"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem5);
    MenuItem6 = new wxMenuItem(Menu1, ID_MENU_LOAD2, _("Load image&2"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem6);
    MenuItem3 = new wxMenuItem(Menu1, ID_MENU_LATEST, _("&Load latest files"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem3);
    MenuItem3->Enable(false);
    MenuItem1 = new wxMenuItem(Menu1, ID_MENUITEM1, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    Image1 = new wxImage();
    Image1_BMP = new wxBitmap();
    Image2 = new wxImage();
    Image2_BMP = new wxBitmap();
    Image3 = new wxImage();
    Image3_BMP = new wxBitmap();
    FileDialog1 = new wxFileDialog(this, _("Select file"), wxEmptyString, wxEmptyString, wxFileSelectorDefaultWildcardStr, wxFD_DEFAULT_STYLE, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));

    Connect(ID_MENUITEM1,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&RevEngEFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&RevEngEFrame::OnAbout);
    Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&RevEngEFrame::OnClose);
    //*)
    Connect( ID_MENU_LOAD1, wxEVT_COMMAND_MENU_SELECTED, ( wxObjectEventFunction )&RevEngEFrame::OnLoad1 );
    Connect( ID_MENU_LOAD2, wxEVT_COMMAND_MENU_SELECTED, ( wxObjectEventFunction )&RevEngEFrame::OnLoad2 );
    Connect( ID_MENU_LATEST, wxEVT_COMMAND_MENU_SELECTED, ( wxObjectEventFunction )&RevEngEFrame::OnLoadLatest );

    if( config->Options["Latest1"] != _("") && config->Options["Latest2"] != _("") ) {
        MenuItem3->Enable(true);
    }
    this->Maximize( true );
}

RevEngEFrame::~RevEngEFrame() {
    //(*Destroy(RevEngEFrame)
    //*)
}

void RevEngEFrame::OnLoad1( wxCommandEvent& evt ) {
    FileDialog1->SetPath( config->Options["Latest1"] );
    if(FileDialog1->ShowModal() == wxID_OK) {
        wxsImage1.Clear();
        wxsImage1 = FileDialog1->GetPath();
        bImageReady1 = true;
        bImagesScaled = false;
        bImageValid1 = false;
        bImageValid2 = false;
    }
}

void RevEngEFrame::OnLoad2( wxCommandEvent& evt ) {
    FileDialog1->SetPath( config->Options["Latest2"] );
    if(FileDialog1->ShowModal() == wxID_OK) {
        wxsImage2.Clear();
        wxsImage2 = FileDialog1->GetPath();
        bImageReady2 = true;
        bImagesScaled = false;
        bImageValid1 = false;
        bImageValid2 = false;
    }
}

void RevEngEFrame::OnLoadLatest( wxCommandEvent& evt ) {
    wxsImage1 = config->Options["Latest1"];
    wxsImage2 = config->Options["Latest2"];
    bImageReady1 = true;
    bImageReady2 = true;
    bImagesScaled = false;
}

#define MAX_OPACITY 255

int white_weight = 128;

void RevEngEFrame::OnPaint( wxPaintEvent& evt ) {
    if( Image1->IsOk() &&  Image2->IsOk() && bImageReady1 &&  bImageReady2 && bImagesScaled ) {
        register unsigned char *Image1Pixels;
        register unsigned char *Image2Pixels;
        register unsigned char *Image3Pixels;
        register int i, j, k;
        Image1Pixels = Image1->GetData(); // RGBRGBRGB...
        Image2Pixels = Image2->GetData(); // RGBRGBRGB...
        Image3Pixels = Image3->GetData(); // RGBRGBRGB...
        for( i = 0; i < Image1->GetWidth(); ++i ) {
            for( j = 0; j < Image1->GetHeight(); ++j ) {
                if( *Image1Pixels || *( Image1Pixels + 1 ) || *( Image1Pixels + 2 ) ) {
                    k = ( ( ( unsigned int ) * Image2Pixels++ * ( MAX_OPACITY - white_weight ) ) + ( ( unsigned char ) * Image1Pixels++ * white_weight ) ) / MAX_OPACITY;
                    *Image3Pixels++ = k;
                    k = ( ( ( unsigned int ) * Image2Pixels++ * ( MAX_OPACITY - white_weight ) ) + ( ( unsigned char ) * Image1Pixels++ * white_weight ) ) / MAX_OPACITY;
                    *Image3Pixels++ = k;
                    k = ( ( ( unsigned int ) * Image2Pixels++ * ( MAX_OPACITY - white_weight ) ) + ( ( unsigned char ) * Image1Pixels++ * white_weight ) ) / MAX_OPACITY;
                    *Image3Pixels++ = k;
                } else {
                    Image3Pixels += 3;
                    Image2Pixels += 3;
                    Image1Pixels += 3;
                }
            }
        }
        wxPaintDC *dc = new wxPaintDC( this );
        dc->Clear();
        dc->DrawBitmap( *Image3, 0, 0, false );
    } else {
        if( bImageReady1 &&  Image1->LoadFile( wxsImage1, wxBITMAP_TYPE_ANY ) ) {
            config->Options["Load1"] = wxsImage1;
            config->Save();
            bImageValid1 = true;
        }
        if( bImageReady2 &&  Image2->LoadFile( wxsImage2, wxBITMAP_TYPE_ANY ) ) {
            config->Options["Load2"] = wxsImage2;
            config->Save();
            bImageValid2 = true;
        }
        if( bImageReady1 && bImageReady2 ) {
            double fScale = 1.0;
            int w = GetClientRect().width, h = GetClientRect().height;
            int w1 = Image1->GetWidth(), h1 = Image1->GetHeight();
            int w2 = Image2->GetWidth(), h2 = Image2->GetHeight();
            double fScaleW = ( double ) w / w1;
            double fScaleH = ( double ) h / h1;
            if( fScaleW < fScaleH ) {
                fScale = fScaleW;
            } else {
                fScale = fScaleH;
            }
            fScaleW = ( double ) w / w2;
            fScaleH = ( double ) h / w2;
            if( fScaleW < fScaleH ) {
                if( fScale < fScaleW ) {
                    fScale = fScaleW;
                }
            } else {
                if( fScale < fScaleH ) {
                    fScale = fScaleH;
                }
            }
            wxImage img1, img2;

            img1.Create( w, h );
            img1.Paste( Image1->Scale( fScale * w1, fScale * h1 ), 0, 0 );

            img2.Create( w, h );
            img2.Paste( Image2->Scale( fScale * w2, fScale * h2 ), 0, 0 );

            //Image1->Clear();
            Image1->Create( w, h );
            Image1->Paste( img1, 0, 0 );

            //Image2->Clear();
            Image2->Create( w, h );
            Image2->Paste( img2, 0, 0 );

            Image3->Create( w, h );
            bImagesScaled = true;
            white_weight = 128;

            SetTitle( "RevEngE (use the mouse wheel to change the gradient)" );
            Refresh();
        }
    }
}

void RevEngEFrame::OnSize( wxSizeEvent& event ) {
    bImagesScaled = false;
    Refresh();
}

void RevEngEFrame::OnQuit( wxCommandEvent& event ) {
    //std::terminate(); // terminate closes all windows
    Close();
}

#ifdef __GLIBC__
#include <gnu/libc-version.h>
#endif
void RevEngEFrame::OnAbout( wxCommandEvent& event ) {
    wxString msg = wxbuildinfo( long_f );
    msg << _( "\r\nGNU GCC version: " ) << __GNUC__ << "." << __GNUC_MINOR__ << "." << __GNUC_PATCHLEVEL__;
#ifdef __GLIBC__
    msg << _( "\r\nGNU libc compile-time version: " ) << __GLIBC__ << "." << __GLIBC_MINOR__;
    msg << _( "\r\nGNU libc runtime version: " ) << gnu_get_libc_version();
#endif
    msg << _( "\r\n\r\nProject:\t\t\thttps://github.com/HenniePeters/RevEngE/\r\n\r\n" );
    msg << _( "Requested by:\t\tDave Jones (eevblog.com)\r\n\r\n" );
    msg << _( "Developer:\r\n--------------------\r\n" );
    msg << _( "Hennie Peters:\t\tC++ programming\r\n" );

    wxMessageBox( msg, _( "About RevEngE" ) );
}

void RevEngEFrame::OnClose( wxCloseEvent& event ) {
    if( bImageValid1 && bImageValid2 ) {
        if( Image1 != Image2 && Image1 != _("") && Image2 != _("") ) {
            config->Options["Latest1"] = wxsImage1;
            config->Options["Latest2"] = wxsImage2;
            config->Save();
        }
    }
    config->Save();
    std::terminate(); // terminate closes all windows
}

void RevEngEFrame::OnScroll(	wxMouseEvent& event ) {
    //white_weight = Slider1->GetValue();
    white_weight += event.GetWheelRotation() / 5;
    if( white_weight > 255 ) {
        white_weight = 255;
    }
    if( white_weight < 000 ) {
        white_weight = 0;
    }
    Refresh();
}


