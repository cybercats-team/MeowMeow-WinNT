#include "framework.h"
#include "ResourcePath.h"

std::string directory(std::string& path) {
  using namespace std;
  const size_t slashPosition = path.rfind('\\');

  return slashPosition == string::npos ? path : path.substr(0, slashPosition);
}

std::string resourcePath() {
  using namespace std;

  char buffer[MAX_PATH];
  GetModuleFileNameA(NULL, buffer, MAX_PATH);

  string selfPath(buffer);
  string selfDirectory = directory(selfPath);
  string parentDirectory = directory(selfDirectory);

#ifdef _WIN64
  string resourceDirectory = directory(parentDirectory);
#else
  string resourceDirectory = move(parentDirectory);
#endif

  return resourceDirectory + "\\Resource\\";
}
