#include "core.h"

void scrool_win_8(UI_Window *winfo, uchar *vram);
void scrool_win_16(UI_Window *winfo, ushort *vram);
void scrool_win_32(UI_Window *winfo, uint *vram);

char closebtn[16][40] = {
	"OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO",
	"OQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ$@",
	"OQQQQQQQQQQQQQJJQQQQQQQQJJQQQQQQQQQQQQ$@",
	"OQQQQQQQQQQQQQJJJQQQQQQJJJQQQQQQQQQQQQ$@",
	"OQQQQQQQQQQQQQQJJJQQQQJJJQQQQQQQQQQQQQ$@",
	"OQQQQQQQQQQQQQQQJJJQQJJJQQQQQQQQQQQQQQ$@",
	"OQQQQQQQQQQQQQQQQJJJJJJQQQQQQQQQQQQQQQ$@",
	"OQQQQQQQQQQQQQQQQQJJJJQQQQQQQQQQQQQQQQ$@",
	"OQQQQQQQQQQQQQQQQQJJJJQQQQQQQQQQQQQQQQ$@",
	"OQQQQQQQQQQQQQQQQJJJJJJQQQQQQQQQQQQQQQ$@",
	"OQQQQQQQQQQQQQQQJJJQQJJJQQQQQQQQQQQQQQ$@",
	"OQQQQQQQQQQQQQQJJJQQQQJJJQQQQQQQQQQQQQ$@",
	"OQQQQQQQQQQQQQJJJQQQQQQJJJQQQQQQQQQQQQ$@",
	"OQQQQQQQQQQQQQJJQQQQQQQQJJQQQQQQQQQQQQ$@",
	"OQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ$@",
	"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
};

void init_windows(void)
{
	int i;

	for(i = 0;i < MAX_WINDOWS;i++){
		system.ui.window.ctrl.winfos[i].flags = initialized;
		system.ui.window.ctrl.winfos[i].buf = (void *)0x00000000;
		system.ui.window.ctrl.winfos[i].app_buf = (void *)0x00000000;
		system.ui.window.ctrl.winfos[i].app_buf_bits = 0;
		system.ui.window.ctrl.winfos[i].task = (UI_Task *)0;
	}
	return;
}

UI_Window *window_alloc(void)
{
	UI_Window *win;
	int i;

	for(i = 0;i < MAX_WINDOWS;i++){
		if(system.ui.window.ctrl.winfos[i].flags == initialized){
			win = &system.ui.window.ctrl.winfos[i];
			win->flags = allocated;
			win->buf = (void *)0x00000000;
			win->app_buf = (void *)0x00000000;
			win->app_buf_bits = 0;
			win->task = (UI_Task *)0;
			return win;
		}
	}
	return 0;
}

void window_free(UI_Window *winfo)
{
	winfo->flags = initialized;
	winfo->task = (UI_Task *)0;
	return;
}

UI_Window *make_window(uchar *title, int xsize, int ysize, int px, int py, int height, bool active)
{
	UI_Window *winfo = window_alloc();

	if(winfo == 0) goto err;
	winfo->winxsize = xsize + 8;
	winfo->winysize = ysize + 28;
	winfo->xsize = xsize;
	winfo->ysize = ysize;
	winfo->position.x = px;
	winfo->position.y = py;
	winfo->origin.x = 4;
	winfo->origin.y = 24;
	winfo->win = sheet_alloc();
	winfo->buf = (uint *)sys_memman_alloc((winfo->winxsize * winfo->winysize) * (system.data.info.vesa.BitsPerPixel >> 2));

	sheet_setbuf(winfo->win, winfo->buf, winfo->winxsize, winfo->winysize,INV_COL32);	

	change_window(winfo, title, active);
	boxfill_win(winfo, 0xFFFFFF, 0, 0, winfo->xsize, winfo->ysize);

	sheet_slide(winfo->win, px, py);
	sheet_updown(winfo->win, height);	
err:
	return winfo;
}

UI_Window *make_window_app(uchar *title, int xsize, int ysize, int px, int py, int height, bool active, uint *buf, UI_Task *task)
{
	UI_Window *winfo = window_alloc();

	if(winfo == 0) goto err;
	winfo->winxsize = xsize + 8;
	winfo->winysize = ysize + 28;
	winfo->xsize = xsize;
	winfo->ysize = ysize;
	winfo->position.x = px;
	winfo->position.y = py;
	winfo->origin.x = 4;
	winfo->origin.y = 24;
	winfo->win = sheet_alloc();
	winfo->buf = buf;
	winfo->task = task;

	sheet_setbuf(winfo->win, winfo->buf, winfo->winxsize, winfo->winysize,INV_COL32);	

	change_window(winfo, title, active);
	boxfill_win(winfo, 0xFFFFFF, 0, 0, winfo->xsize, winfo->ysize);

	sheet_slide(winfo->win, px, py);
	sheet_updown(winfo->win, height);	
err:
	return winfo;
}

UI_Window *make_window_app_compatible_hrb(uchar *title, int xsize, int ysize, int px, int py, int height, bool active, uint *buf, UI_Task *task)
{
	xsize = xsize - 8;
	ysize = ysize - 28;
	return make_window_app(title, xsize, ysize, px, py, height, active, buf, task);
}

void free_window_app(UI_Window *winfo)
{
	sheet_free(winfo->win);
	window_free(winfo);
	return;
}

void change_window(UI_Window *winfo, uchar *title, bool active)
{
	uint color = 0;
	int x = 0, y = 0;
	char c;

	for (; *title != 0x00; title++) {
		winfo->title[x] = *title;		
		x++;
	}
	winfo->title[x] = 0x00;
	winfo->active = active;	

	if(system.data.info.vesa.BitsPerPixel == 8){
		if(active) color = WIN_COL8_ACTIVE;
		else color = WIN_COL8_INACTIVE;
	} else if(system.data.info.vesa.BitsPerPixel == 16){
		if(active) color = WIN_COL16_ACTIVE;
		else color = WIN_COL16_INACTIVE;
	} else if(system.data.info.vesa.BitsPerPixel == 32){
		if(active) color = WIN_COL32_ACTIVE;
		else color = WIN_COL32_INACTIVE;
	}

	boxfill_i(winfo->buf, winfo->winxsize, color, 0, 0, winfo->winxsize, 24);	
	boxfill_i(winfo->buf, winfo->winxsize, color, 0, 0, 4, winfo->winysize);
	boxfill_i(winfo->buf, winfo->winxsize, color, winfo->winxsize - 4, 0, winfo->winxsize, winfo->winysize);
	boxfill_i(winfo->buf, winfo->winxsize, color, 0, winfo->winysize - 4, winfo->winxsize, winfo->winysize);


	line_i(winfo->buf, winfo->winxsize, 0, 0, winfo->winxsize - 1, 0, 0xFFFFFF);
	line_i(winfo->buf, winfo->winxsize, 0, 0, 0, winfo->winysize - 1, 0xFFFFFF);
	line_i(winfo->buf, winfo->winxsize, winfo->winxsize - 1, 0, winfo->winxsize - 1, winfo->winysize - 1, 0x000000);
	line_i(winfo->buf, winfo->winxsize, 0, winfo->winysize - 1, winfo->winxsize - 1, winfo->winysize - 1, 0x000000);

	putfonts_asc_sht_i(winfo->win, 4, 4, 0xFFFFFF, color, winfo->title);

	for(y = 0; y < 16; y++){
		for(x = 0; x < 40; x++){
			c = closebtn[y][x];
			if(c == '@')		color = 0xFF0000;
			else if(c == '$')	color = 0xFF0000;
			else if(c == 'Q')	color = 0xFF0000;
			else if(c == 'J')	color = 0xFFFFFF;
			else if(c == 'O')	color = 0xFFFFFF;
			point_i(winfo->buf, winfo->winxsize - 44 + x, y, color, winfo->winxsize);
		}
	}
	refresh_window(winfo);
	return;
}

void change_window_title(UI_Window *winfo, uchar *title)
{
	change_window(winfo, title, winfo->active);
}

void change_window_active(UI_Window *winfo, bool active)
{
	change_window(winfo, winfo->title, active);
}

void slide_window(UI_Window *winfo, int px, int py)
{
	winfo->position.x = px;
	winfo->position.y = py;

	sheet_slide(winfo->win, winfo->position.x, winfo->position.y);
	return;
}

void refresh_window(UI_Window *winfo)
{
	sheet_refresh_full(winfo->win);
	return;
}

void refresh_window_alpha(UI_Window *winfo)
{
	sheet_refresh_full_alpha(winfo->win);
	return;
}

void boxfill_win(UI_Window *winfo, uint c, int x0, int y0, int x1, int y1)
{
	if(x0 < 0 || y0 < 0 || x1 > winfo->xsize || y1 > winfo->ysize) goto err;

	boxfill_i(winfo->buf, winfo->winxsize, c, winfo->origin.x + x0, winfo->origin.y + y0, winfo->origin.x + x1, winfo->origin.y + y1);
	sheet_refresh(winfo->win, x0 + winfo->origin.x, y0 + winfo->origin.y, x1 + winfo->origin.x, y1 + winfo->origin.y);
err:
	return;
}

void point_win(UI_Window *winfo, uint c, int x, int y)
{
	point_i(winfo->buf, x + winfo->origin.x, y + winfo->origin.y, c, winfo->winxsize);
	return;
}

void putfonts_win(UI_Window *winfo, int x, int y, uint c, uint bc, const uchar *s)
{
	if(x < 0 || y < 0 || x > winfo->xsize || y > winfo->ysize) goto err;
	putfonts_asc_sht_i(winfo->win, x + winfo->origin.x, y + winfo->origin.y, c, bc, s);
err:
	return;
}

void putfonts_win_no_bc(UI_Window *winfo, int x, int y, uint c, const uchar *s)
{
	if(x < 0 || y < 0 || x > winfo->xsize || y > winfo->ysize) goto err;
	putfonts_asc_sht_i_no_bc(winfo->win, x + winfo->origin.x, y + winfo->origin.y, c, s);
err:
	return;
}

void scrool_win(UI_Window *winfo)
{
	if(system.data.info.vesa.BitsPerPixel == 8) scrool_win_8(winfo, winfo->buf);
	else if(system.data.info.vesa.BitsPerPixel == 16) scrool_win_16(winfo, winfo->buf);
	else if(system.data.info.vesa.BitsPerPixel == 32) scrool_win_32(winfo, winfo->buf);
	boxfill_win(winfo, 0x000000, 0, winfo->ysize - 16, winfo->xsize, winfo->ysize);
	return;
}

void scrool_win_32(UI_Window *winfo, uint *vram)
{
	int x, y;
	for (y = winfo->origin.y; y < winfo->ysize + winfo->origin.y - 16; y++) {
		for (x = winfo->origin.x; x < winfo->xsize + winfo->origin.x; x++) {
			vram[x + y * winfo->winxsize] = vram[x + (y + 16) * winfo->winxsize];
		}
	}
	return;
}

void scrool_win_16(UI_Window *winfo, ushort *vram)
{
	int x, y;

	for (y = winfo->origin.y; y < winfo->ysize + winfo->origin.y - 16; y++) {
		for (x = winfo->origin.x; x < winfo->xsize + winfo->origin.x; x++) {
			vram[x + y * winfo->winxsize] = vram[x + (y + 16) * winfo->winxsize];
		}
	}
	return;
}

void scrool_win_8(UI_Window *winfo, uchar *vram)
{
	int x, y;

	for (y = winfo->origin.y; y < winfo->ysize + winfo->origin.y - 16; y++) {
		for (x = winfo->origin.x; x < winfo->xsize + winfo->origin.x; x++) {
			vram[x + y * winfo->winxsize] = vram[x + (y + 16) * winfo->winxsize];
		}
	}
	return;
}

void line_win(UI_Window *winfo, int x0, int y0, int x1, int y1, uint c)
{
	line_i(winfo->buf, winfo->winxsize, x0 + winfo->origin.x, y0 + winfo->origin.y, x1 + winfo->origin.x, y1 + winfo->origin.y, c);
	return;
}

void draw_hexagon_win(UI_Window *winfo, int a, int x, int y, uint c)
{
	draw_hexagon_i(winfo->buf, winfo->winxsize, a, x + winfo->origin.x, y + winfo->origin.y, c);
	return;
}



