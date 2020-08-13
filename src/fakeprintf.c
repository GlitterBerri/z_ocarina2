#if 0
void rmonPrintf( const char *fmt, ... ) {char *c = fmt;}
void osSyncPrintf( const char *fmt, ... ) {char *c = fmt;}
void fakePrintf( const char *fmt, ... ) {char *c = fmt;}
#else
void rmonPrintf(void) {}
void osSyncPrintf( void) {}
void fakePrintf( void) {}
#endif

