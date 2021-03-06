#ifndef PHPSETTERGETTERENTRY_H
#define PHPSETTERGETTERENTRY_H

#include <wx/string.h>
#include <vector>
#include "PHPEntityBase.h"

enum eSettersGettersFlags {
    kSG_None                = 0x00000000,
    kSG_StartWithUpperCase  = 0x00000001,
    kSG_NameOnly            = 0x00000002,
};

class PHPSetterGetterEntry
{
public:
    typedef std::vector<PHPSetterGetterEntry> Vec_t;
    
protected:
    PHPEntityBase::Ptr_t m_entry;
    
protected:
    void FormatName(wxString &name) const;
    
public:
    PHPSetterGetterEntry();
    PHPSetterGetterEntry(PHPEntityBase::Ptr_t entry);
    virtual ~PHPSetterGetterEntry();
    
    /**
     * @brief generate getter for the this PHPEntry
     * @param flags generation flags
     */
    wxString GetGetter(eSettersGettersFlags flags = kSG_None) const;
    
    /**
     * @brief generate setter for the this PHPEntry
     * @param flags generation flags
     */
    wxString GetSetter(eSettersGettersFlags flags = kSG_None) const;
};

#endif // PHPSETTERGETTERENTRY_H
