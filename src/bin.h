#ifndef __BIN_H__
#define __BIN_H__
// printf("foo: "FMT, BIN(10));
#define FMT "%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c\n"
#define BIN(val)  \
    (val & 0x80000000 ? '1' : '0'), \
    (val & 0x40000000 ? '1' : '0'), \
    (val & 0x20000000 ? '1' : '0'), \
    (val & 0x10000000 ? '1' : '0'), \
    (val & 0x08000000 ? '1' : '0'), \
    (val & 0x04000000 ? '1' : '0'), \
    (val & 0x02000000 ? '1' : '0'), \
    (val & 0x01000000 ? '1' : '0'), \
    (val & 0x00800000 ? '1' : '0'), \
    (val & 0x00400000 ? '1' : '0'), \
    (val & 0x00200000 ? '1' : '0'), \
    (val & 0x00100000 ? '1' : '0'), \
    (val & 0x00080000 ? '1' : '0'), \
    (val & 0x00040000 ? '1' : '0'), \
    (val & 0x00020000 ? '1' : '0'), \
    (val & 0x00010000 ? '1' : '0'), \
    (val & 0x00008000 ? '1' : '0'), \
    (val & 0x00004000 ? '1' : '0'), \
    (val & 0x00002000 ? '1' : '0'), \
    (val & 0x00001000 ? '1' : '0'), \
    (val & 0x00000800 ? '1' : '0'), \
    (val & 0x00000400 ? '1' : '0'), \
    (val & 0x00000200 ? '1' : '0'), \
    (val & 0x00000100 ? '1' : '0'), \
    (val & 0x00000080 ? '1' : '0'), \
    (val & 0x00000040 ? '1' : '0'), \
    (val & 0x00000020 ? '1' : '0'), \
    (val & 0x00000010 ? '1' : '0'), \
    (val & 0x00000008 ? '1' : '0'), \
    (val & 0x00000004 ? '1' : '0'), \
    (val & 0x00000002 ? '1' : '0'), \
    (val & 0x00000001 ? '1' : '0') 
#endif /*__BIN_H__*/
