
#include "core.h"

void init_keyboard(void)
{
	/* �������ݐ��FIFO�o�b�t�@���L�� */
//	keyfifo = fifo;
//	keydata0 = data0;
	/* �L�[�{�[�h�R���g���[���̏����� */
	wait_KBC_sendready();
	io_out8(PORT_KEYCMD, KEYCMD_WRITE_MODE);
	wait_KBC_sendready();
	io_out8(KEYB_DATA, KBC_MODE);
	io_out8(PIC0_IMR, io_in8(PIC0_IMR) & 0xfd);
	return;
}

void inthandler21(int *esp)
{
	int data;
	data = io_in8(KEYB_DATA);
	io_out8(PIC0_OCW2, 0x61);	/* IRQ-01��t������PIC�ɒʒm �B0x60+�ԍ��B*/
//	fifo32_put(keyfifo,data + keydata0);
	putfonts_asc_sht_i(system.sys.sht.desktop, 8, 184, 0xFFFFFF, 0x000000, "INT:21 IRQ:1 PS/2���ް��");
	return;
}

void wait_KBC_sendready(void)
{
	/* �L�[�{�[�h�R���g���[�����f�[�^���M�\�ɂȂ�̂�҂� */
	for (;;) {
		if ((io_in8(PORT_KEYSTA) & KEYSTA_SEND_NOTREADY) == 0) {
			break;
		}
	}
	return;
}
