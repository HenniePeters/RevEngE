//#include <wx/wxprec.h>
//#ifndef WX_PRECOMP
//#   include <map>
//#   include <wx/wx.h>
//#endif

#include <map>
#include <wx/wx.h>

class AppConfigData {
public:
    std::map<std::string, std::string> Options;
    AppConfigData( const char *sAppName );
    wxString ConfigPath( void );
    bool ReadOnly( void );
    void Save( void );
private:
    wxString wxsConfigPath = _( "" );
    wxString wxsConfigDirCandidate = _( "" );
    wxString wxsConfigPathCandidate = _( "" );
    bool bConfigPath = false;
    bool bReadOnly = false;
    void ReadOptions( char * );
};
