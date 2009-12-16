#include "apilib.h"

void NhMain(void)
{
	int langmode = api_getlang();
	if (langmode == 0) {
		printf("English ASCII mode\n");
	}
	if (langmode == 1) {
		printf("ƒVƒtƒg‚i‚h‚rƒ‚[ƒh\n");
	}
	if (langmode == 2) {
		printf("“ú–{Œê‚d‚t‚bƒ‚[ƒh\n");
	}
	api_end();
}
