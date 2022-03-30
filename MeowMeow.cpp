// MeowMeow.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "PlatformWinNT.h"
#ifdef DEBUG
#include "PlatformLogger.h"
#endif
#include "MeowMeow.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
  UNREFERENCED_PARAMETER(hInstance);
  UNREFERENCED_PARAMETER(hPrevInstance);
  UNREFERENCED_PARAMETER(lpCmdLine);
  UNREFERENCED_PARAMETER(nCmdShow);
  
  PlatformWinNT platform{};  
#ifdef DEBUG
  PlatformLogger logger(platform);

  Debug::setCustomLogger(logger);
#endif

  Application app("Meow Meow :: Turkey Hunter", platform);

  if (!app.initialize()) {
    return EXIT_FAILURE;
  }

  app.run();
  return EXIT_SUCCESS;
}

