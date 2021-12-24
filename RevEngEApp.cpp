/***************************************************************
    Name:      RevEngEApp.cpp
    Purpose:   Code for Application Class
    Author:    Hennie Peters (hennie.dot.peters.at.gmail.dot.com)
    Created:   2021-08-30
    Copyright: Hennie Peters ()
    License:
 **************************************************************/

#include "RevEngEApp.h"

//(*AppHeaders
#include "RevEngEMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP( RevEngEApp );

bool RevEngEApp::OnInit() {
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if( wxsOK ) {
        RevEngEFrame* Frame = new RevEngEFrame( 0 );
        Frame->Show();
        SetTopWindow( Frame );
    }
    //*)
    return wxsOK;
}
