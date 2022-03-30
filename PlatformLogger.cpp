#include "PlatformLogger.h"

PlatformLogger::PlatformLogger(Platform& platform)
  : CustomLogger(), platform(platform) {}

void PlatformLogger::print(const std::string& message) {
#ifdef DEBUG
  std::string messageWithEndline = message + platform.nl();
  LPCSTR messageCString = messageWithEndline.c_str();

  OutputDebugStringA(messageCString);
#endif
}
