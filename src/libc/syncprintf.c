#include "common.h"
#include "xstdio.h"

char textBuffer[256];

void* crash_screen_copy_to_buf(void* dest, char* src, u32 size);

void formatText(s32 x, s32 y, char* buffer, char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    _Printf(crash_screen_copy_to_buf, buffer, fmt, args);
    va_end(args);
}

s32 __osSyncVPrintf(const char *fmt, va_list args, s32 arg2) {
    return 1;
}

void osSyncPrintf(const char *fmt, ...) {
    int ans;
    va_list ap;
    va_start(ap, fmt);
    
    _Printf((void*)&__osSyncVPrintf, NULL, fmt, ap);
}
