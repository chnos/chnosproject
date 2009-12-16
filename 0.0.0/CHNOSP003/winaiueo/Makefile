APP      = winaiueo
STACK    = 16k
MALLOC   = 0k
SJISCONV = $(TOOLPATH)sjisconv.exe -s

include ../app_make.txt
%.ca : %.c Makefile
	$(SJISCONV) $*.c $*.ca

%.gas : %.ca Makefile
	$(CC1) -o $*.gas $*.ca