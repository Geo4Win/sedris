/// Dummy entry call for DLL

#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers

#include <windows.h>


// The includes below force the C++ classes to be exported
#include "taccess/interface/include/seWorkspace.h"
#include "taccess/interface/include/seTransmittal.h"
#include "taccess/interface/include/seIterator.h"
#include "taccess/interface/include/seDRMAll.h"
#include "taccess/interface/include/seHelperDRM.h"
#include "taccess/interface/include/seHelperDataTable.h"
#include "taccess/interface/include/seHelperImage.h"
#include "taccess/interface/include/seHelperSRM.h"
#include "srm/src/include/BaseSRF.h"
#include "srm/src/include/srf_all.h"
#include "srm/src/include/Exception.h"
#include "srm/src/include/Direction.h"
#include "srm/src/include/Orientation.h"


__declspec(dllexport) void __SEDRIS_Dummy_Export()
{
    sedris::seHelperDRM t1;
    sedris::seHelperDataTable t2;
    sedris::seHelperImage t3;
    sedris::seHelperSRM t4;
}


BOOL APIENTRY DllMain
(
    HANDLE hModule, 
    DWORD  ul_reason_for_call, 
    LPVOID lpReserved
)
{
    return TRUE;
}
