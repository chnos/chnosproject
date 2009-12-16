#include "apilib.h"
#include <math.h>

void CHNMain(void)
{
    char buf[160 * 100];
    int win, i;
    win = api_openwin(buf, 160, 100, -1, "sincurve");
    for (i = 0; i < 144; i++) {
        api_point(win, i + 8, sin(i * 0.05) * 30 + 60, 0);
    }
    api_getkey(1); /* 何かキーを押せば終了 */
    api_end();
}
