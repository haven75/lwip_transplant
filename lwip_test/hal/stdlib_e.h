#ifndef  STDLIB_E_H
#define STDLIB_E_H

#include "typedefs.h"


#ifndef ARRARY_OF
#define ARRARY_OF(x)  (sizeof(x)/sizeof(x[0]))
#endif
#define MIN_ALIGN_TO16(x)  ((x/16*16)+(!!(x%16))*16)

#define CHAR4_TO_UINT32(ptr) ((uint32_t)ptr[0]<<24)\
	+ ((uint32_t)ptr[1]<<16)\
	+ ((uint32_t)ptr[2]<<8)\
	+ ((uint32_t)ptr[3])

#define UINT32_TO_CHAR4_BIG(ptr, uint) do{ptr[0] = (uint8_t)(uint >> 24);\
	ptr[1] = (uint8_t)(uint >> 16);\
	ptr[2] = (uint8_t)(uint >> 8);\
	ptr[3] = (uint8_t)(uint);}while(0)

#define ARRAY_OF(x) (sizeof(x)/sizeof(x[0]))

int e_memcmp (const void *buffer1, const void *buffer2, int count);
void *e_memcpy (void *dst, void const *src, unsigned int len);
void e_memset (void *paddr, unsigned int size, char value);
unsigned int e_strlen (const char * str);
char *e_strcat(char *str1, char *str2) ;
unsigned char CRC8_Table (unsigned char *p, unsigned int counter);
#endif
