#if defined(linux) || defined(APPLE)
#define LINE_END 0
#endif

#ifdef __CYGWIN__
#define LINE_END '\r'
#endif
