#include <wx/app.h>
#include <map>

class AppConfigData {
public:
    std::map<std::string, std::string> Options;
    AppConfigData( wxString wxAppName );
    wxString ConfigPath( void);
    bool ReadOnly(void);
    void Save( void );
private:
    wxString wxsConfigPath = _("");
    wxString wxsConfigDirCandidate = _("");
    wxString wxsConfigPathCandidate = _("");
    bool bConfigPath = false;
    bool bReadOnly = false;
    void ReadOptions( char * );
};
