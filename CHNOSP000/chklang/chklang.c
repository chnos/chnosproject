#include "apilib.h"

void NhMain(void)
{
	int langmode = api_getlang();
	if (langmode == 0) {
		printf("English ASCII mode\n");
	}
	if (langmode == 1) {
		printf("�V�t�g�i�h�r���[�h\n");
	}
	if (langmode == 2) {
		printf("���{��d�t�b���[�h\n");
	}
	api_end();
}
