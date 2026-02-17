#ifndef VERSION_H
#define VERSION_H

#define MCC_VERSION "1.0.0"
#define MCC_BUILD_DATE __DATE__ " " __TIME__

#if defined(_WIN32)
    #define MCC_PLATFORM "Windows"
#elif defined(__APPLE__)
    #define MCC_PLATFORM "macOS"
#elif defined(__linux__)
    #define MCC_PLATFORM "Linux"
#else
    #define MCC_PLATFORM "Unknown"
#endif

// Project attribution
#define MCC_ATTRIBUTION "(A part of the Discovery open-source project)"

#endif
