
#include "core.h"

void Draw_Put_Font_16(void *vram, uint xsize, uint x, uint y, uint c, const uchar *font)
{
	int i;
	uchar d;
	ushort *p;
	for (i = 0; i < 16; i++) {
		p = (ushort *)vram + (y + i) * xsize + x;
		d = font[i];
		if ((d & 0x80) != 0) { p[0] = (ushort)c; }
		if ((d & 0x40) != 0) { p[1] = (ushort)c; }
		if ((d & 0x20) != 0) { p[2] = (ushort)c; }
		if ((d & 0x10) != 0) { p[3] = (ushort)c; }
		if ((d & 0x08) != 0) { p[4] = (ushort)c; }
		if ((d & 0x04) != 0) { p[5] = (ushort)c; }
		if ((d & 0x02) != 0) { p[6] = (ushort)c; }
		if ((d & 0x01) != 0) { p[7] = (ushort)c; }
	}
	return;
}

void Draw_Put_String_16(void *vram, uint xsize, uint x, uint y, uint c, const uchar *s)
{
	c = RGB_32_To_16(c);
	for(; *s != 0x00; s++){
		if(x > xsize - 8){
			break;
		}
		Draw_Put_Font_16(vram, xsize, x, y, c, hankaku + *s * 16);
		x += 8;
	}
	return;
}

void Draw_Fill_Rectangle_16(void *vram, uint xsize, uint c, uint x0, uint y0, uint x1, uint y1)
{
	uint x, y;
	c = RGB_32_To_16(c);
	for(y = y0; y <= y1; y++){
		for(x = x0; x <= x1; x++){
			((ushort *)vram)[y * xsize + x] = (ushort)c;
		}
	}
	return;
}

void Draw_Slide_Line_16(void *vram, uint xsize, uint ysize, uint vxsize, uint px, uint py)
{
	uint x, y;

	for(y = py; y < ysize + py - 16; y++){
		for(x = px; x < xsize + px; x++){
			((ushort *)vram)[y * vxsize + x] = ((ushort *)vram)[(y + 16) * vxsize + x];
		}
	}
	return;
}
