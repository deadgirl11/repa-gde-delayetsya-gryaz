#include "libmx.h"

void mx_print_unicode(wchar_t c) {  
    if (c < 128) {
        char res = c;
        write(1, &res, 1);
    }
    else if (c < 2048) {
        char res[2];
        res[0] = (c >> 6 & 0x1f) | 0xc0;
        res[1] = (c >> 0 & 0x3f) | 0x80;
        write(1, res, 2);
    }
    else if (c < 65536) {
        char res[3];
        res[0] = (c >> 12 & 0x0f) | 0xe0;
        res[1] = (c >> 6 & 0x3f) | 0x80;
        res[2] = (c >> 0 & 0x3f) | 0x80;
        write(1, res, 3);
        }
    else if (c < 1114112) {
        char res[4];
        res[0] = (c >> 18 & 0x07) | 0xf0; 
        res[1] = (c >> 12 & 0x0f) | 0x80;
        res[2] = (c >> 6 & 0x3f) | 0x80;
        res[3] = (c >> 0 & 0x3f) | 0x80;
        write(1, res, 4);
    }
}
