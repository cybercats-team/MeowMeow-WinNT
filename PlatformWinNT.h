#pragma once

#include "framework.h"

class PlatformWinNT 
  : public Platform 
{
  protected:
    const std::string getResourcePath() override;
};
