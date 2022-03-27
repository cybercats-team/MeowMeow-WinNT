// header.h : include file for standard system include files,
// or project specific include files
//

#pragma once

#include "targetver.h"

// C/C++ Standard Library
#include <stdlib.h>
#include <sstream>
#include <filesystem>

// Framework
#include "Framework/Application.h"

// Exclude rarely-used stuff from Windows headers
#define WIN32_LEAN_AND_MEAN             
// Windows Header Files
#include <windows.h>
