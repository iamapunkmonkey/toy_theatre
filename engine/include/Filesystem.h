#pragma once

#include <stdio.h>  /* defines FILENAME_MAX */

#ifdef WINDOWS
    #include <direct.h>
    #define GetCurrentDir _getcwd
#else

#include <unistd.h>

#define GetCurrentDir getcwd
#endif

namespace lunk {
	class Filesystem {
	public:
		std::string getCurrentWorkingDirectory() {
			char cCurrentPath[FILENAME_MAX];

			if (!GetCurrentDir(cCurrentPath, sizeof(cCurrentPath))) {
				return "";
			}

			cCurrentPath[sizeof(cCurrentPath) - 1] = '\0'; /* not really required */

			return cCurrentPath;
		}
	};
}