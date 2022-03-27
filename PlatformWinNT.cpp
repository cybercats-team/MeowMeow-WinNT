#include "PlatformWinNT.h"

PlatformWinNT::PlatformWinNT() : Platform(), resourcePathString() {
  using namespace std;
  using namespace std::filesystem;

  wchar_t buffer[MAX_PATH];
  GetModuleFileNameW(NULL, buffer, MAX_PATH);

  path resourcePath = path(buffer)
    .parent_path()
    .parent_path();

#ifdef _WIN64
  resourcePath = resourcePath.parent_path();
#endif
  
  resourcePath /= "Resource";
  resourcePath += path::preferred_separator;
  resourcePathString = resourcePath.string();
}

const std::string& PlatformWinNT::resourcePath() {
  return resourcePathString;
}
