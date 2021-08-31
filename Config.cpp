#include <sstream>
#include <fstream>
#include <stdexcept>
#include "Config.h"

void AppConfigData::ReadOptions( char *mbstring ) {
    std::string line;
    std::ifstream cfgfile( mbstring );
    for( std::string line; std::getline( cfgfile, line ); ) {
        std::istringstream iss( line );
        std::string id, eq, val;
        bool error = false;
        if( !( iss >> id ) ) {
            error = true;
        } else if( id[0] == '#' ) {
            continue;
        } else if( !( iss >> eq >> val >> std::ws ) || eq != "=" || iss.get() != EOF ) {
            error = true;
        }
        if( error ) {
            // do something appropriate: throw, skip, warn, etc.
        } else {
            Options[id] = val;
        }
    }
}

void AppConfigData::Save( void ) {
    // Save will rewrite the whole file.
    // Comments are all lost
    // This method needs a redesign
    if( ! ReadOnly() ) {
        wxString wxsTemp;
        std::ofstream filestr;
        char mbstring[513];
        wcstombs( mbstring, wxsConfigPath.wc_str(), 512 );
        filestr.open( mbstring );
        if( filestr.is_open() ) {
            wxsTemp = _("Load1 = ") + _(Options["Load1"].c_str()) + _("\n");
            filestr.write( wxsTemp.c_str(), wxsTemp.size() );
            wxsTemp = _("Load2 = ") + _(Options["Load2"].c_str()) + _("\n");
            filestr.write( wxsTemp.c_str(), wxsTemp.size() );
            wxsTemp = _("Latest1 = ") + _(Options["Latest1"].c_str()) + _("\n");
            filestr.write( wxsTemp.c_str(), wxsTemp.size() );
            wxsTemp = _("Latest2 = ") + _(Options["Latest2"].c_str()) + _("\n");
            filestr.write( wxsTemp.c_str(), wxsTemp.size() );
            filestr.close();
        } else {
            if( wxsConfigPath == _("") ) {
                wxsTemp = _("mkdir ");
                wxsTemp += wxsConfigDirCandidate;
                wcstombs( mbstring, wxsTemp.wc_str(), 512 );
                system(mbstring);
                wxsConfigPath = wxsConfigPathCandidate;
                wcstombs( mbstring, wxsConfigPath.wc_str(), 512 );
                std::ofstream output( mbstring, std::ios::out | std::ios::app );
                if( output.is_open() ) {
                    output.close();
                }
                Save();
            }
        }
    }
}

AppConfigData::AppConfigData( wxString wxAppName ) {
    bConfigPath = false;
    std::ifstream filestr;
    wxString wxsTempFile = _( "/etc/" ) + wxAppName + _( ".conf" );
    char mbstring[513];
    wcstombs( mbstring, wxsTempFile.wc_str(), 512 );
    filestr.open( mbstring );
    if( filestr.is_open() ) {
        wxsConfigPath = wxsTempFile;
        bReadOnly = true; // with a .conf file in /etc/ the user cannot change the port, he'll need root assistance
        filestr.close();
        ReadOptions( mbstring );
    } else {
#if defined(__WXMSW__)
        wxString wxsHome = _( getenv( "APPDATA" ) );
        wxString wxsTempFile = _( "~/" ) + wxAppName + _( "/" );
        wxsTempFile.Replace( _( "~" ), wxsHome, false );
        wxsConfigDirCandidate = wxsTempFile;
        wxsTempFile += _( "/" ) + wxAppName + _( ".ini" );
#elif defined(__UNIX__)
        wxString wxsHome = _( getenv( "HOME" ) );
        wxString wxsTempFile = _( "~/.config/" ) + wxAppName;
        wxsTempFile.Replace( _( "~" ), wxsHome, false );
        wxsConfigDirCandidate = wxsTempFile;
        wxsTempFile += _( "/" ) + wxAppName + _( ".conf" );
#endif
        wcstombs( mbstring, wxsTempFile.wc_str(), 512 );
        wxsConfigPathCandidate = wxsTempFile;
        filestr.open( mbstring );
        if( filestr.is_open() ) {
            wxsConfigPath = wxsTempFile;
            filestr.close();
            ReadOptions( mbstring );
        }
    }
}

wxString AppConfigData::ConfigPath( void ) {
    return wxsConfigPath;
}

bool AppConfigData::ReadOnly( void ) {
    return bReadOnly;
}
