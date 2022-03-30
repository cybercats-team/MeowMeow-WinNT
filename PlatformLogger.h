#pragma once

#include "framework.h"

class PlatformLogger 
  : public CustomLogger 
{
  private:
    Platform& platform;
  public:
    PlatformLogger(Platform& platform);
    void print(const std::string& message) override;
};
