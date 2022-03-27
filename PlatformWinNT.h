#pragma once

#include "framework.h"

class PlatformWinNT 
  : public Platform 
{
  private:
    std::string resourcePathString;
  public:
    PlatformWinNT();
    const std::string& resourcePath() override;
};
