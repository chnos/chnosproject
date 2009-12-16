#include "apilib.h"
#include <string.h>
void NhMain(void)
{		
	char txtinfo[40];
	struct MOUSE_INFO info = {0,0,0,0};
	int win;
	char buf[300 * 50];
	win = api_openwin(buf, 300, 50, -1, "mouse");
	for (;;) {
		tomo_getmouse(0,&info);
		sprintf(txtinfo,"X=%d,Y=%d\n",info.x,info.y);
		printf(txtinfo);
	}	
}
