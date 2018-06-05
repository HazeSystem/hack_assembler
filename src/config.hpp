#if defined(linux) || defined(APPLE)
#define SLASH '/'
#define LINE_END '\n'
#endif

#ifdef __CYGWIN__
#define SLASH '\\'
#define LINE_END '\r'
#endif
