
#include "core.h"

void decode_fat(unsigned short *fat, bool backup)
{
	int i, j = 0;
	unsigned char *img;

	if(backup)	img = (unsigned char *)ADR_DISKIMG + 0x00001400;
	else		img = (unsigned char *)ADR_DISKIMG + 0x00000200;

	for(i = 0; i < 2880; i += 2){
		fat[i + 0] = (img[j + 0]	| img[j + 1] << 8) & 0xfff;
		fat[i + 1] = (img[j + 1] >> 4	| img[j + 2] << 4) & 0xfff;
		j += 3;
	}
	return;
}

void load_file(unsigned int finfo_no, unsigned char *buf)
{
	int i;
	unsigned char *img;
	unsigned int size;
	unsigned short clustno;

	img = (unsigned char *)ADR_DISKIMG + 0x00003e00;
	size = system.file.list[finfo_no].size;
	clustno = system.file.list[finfo_no].clustno;


	for(;;){
		if(size <= 512){
			for(i = 0; i < size; i++){
				buf[i] = img[clustno * 512 + i];
			}
			break;
		}
		for(i = 0; i < 512; i++){
			buf[i] = img[clustno * 512 + i];
		}
		size -= 512;
		buf += 512;
		clustno = system.file.fat[clustno];
		
	}
}
