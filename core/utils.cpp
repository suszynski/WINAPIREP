#include "utils.h"
#include <intrin.h>

namespace own::utils {

    bool wstrcmp(WPCSTR first, WPCSTR second) {
        while (*first == *second) {
            if (*first == '\0') return true;
            ++first;
            ++second;
        }
        return false;
    }

    _PEB* GetPeb() {

        return (_PEB*)__readgsqword(0x60);
    }


}
