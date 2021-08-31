/***************************************************************
    Name:      RevEngEMain.h
    Purpose:   Defines Application Frame
    Author:    Hennie Peters (hennie.dot.peters.at.gmail.dot.com)
    Created:   2021-08-30
    Copyright: Hennie Peters ()
    License:
 **************************************************************/

#ifndef REVENGEMAIN_H
#define REVENGEMAIN_H

#define HOTKEY_ID_1 0x3000		// any value between 0 and 0xBFFF
#define HOTKEY_ID_2 0x3001		// any value between 0 and 0xBFFF

//(*Headers(RevEngEFrame)
#include <wx/bitmap.h>
#include <wx/filedlg.h>
#include <wx/frame.h>
#include <wx/image.h>
#include <wx/menu.h>
#include <wx/statbmp.h>
//*)

class RevEngEFrame: public wxFrame {
public:
    void OnPaint( wxPaintEvent &evt );
    RevEngEFrame( wxWindow* parent, wxWindowID id = -1 );
    virtual ~RevEngEFrame();
private:
    //(*Handlers(RevEngEFrame)
    void OnQuit( wxCommandEvent& event );
    void OnAbout( wxCommandEvent& event );
    void OnClose( wxCloseEvent& event );
    //*)

    //(*Identifiers(RevEngEFrame)
    static const long ID_STATICBITMAP1;
    static const long ID_MENU_LOAD1;
    static const long ID_MENU_LOAD2;
    static const long ID_MENU_LATEST;
    static const long ID_MENUITEM1;
    static const long idMenuAbout;
    //*)

    //(*Declarations(RevEngEFrame)
    wxBitmap              *Image1_BMP;
    wxBitmap              *Image2_BMP;
    wxBitmap              *Image3_BMP;
    wxFileDialog* FileDialog1;
    wxImage               *Image1;
    wxImage               *Image2;
    wxImage               *Image3;
    wxMenuItem* MenuItem3;
    wxMenuItem* MenuItem5;
    wxMenuItem* MenuItem6;
    wxStaticBitmap* StaticBitmap1;
    //*)

    bool bImageReady1 = false, bImageReady2 = false;
    bool bImageValid1 = false, bImageValid2 = false;
    bool bImagesScaled = false;

    wxString wxsImage1, wxsImage2;

    void OnScroll( wxMouseEvent &event );
    void OnSize(wxSizeEvent& event);
    void OnLoad1( wxCommandEvent& evt );
    void OnLoad2( wxCommandEvent& evt );
    void OnLoadLatest( wxCommandEvent& evt );

    DECLARE_EVENT_TABLE()
};

#endif // REVENGEMAIN_H
