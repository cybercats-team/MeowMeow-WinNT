// MeowMeow.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "PlatformWinNT.h"
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
  
  // TODO: create OS-specific API class wrapper
#ifdef DEBUG
  using namespace std;
  
  DebugLogger::setCustomLogger([&platform](const string& message) -> void {
    string messageWithEndline = message + platform.nl();
    LPCSTR messageCString = messageWithEndline.c_str();

    OutputDebugStringA(messageCString);
  });
#endif

  Application app("Meow Meow :: Turkey Hunter", platform);

  if (!app.initialize()) {
    return EXIT_FAILURE;
  }

  app.run();
  return EXIT_SUCCESS;
}

