#include "core.h"

int time_tick_100 = 0;


void init_pic(void)
{
	/*
	IRR�F�C���^���v�g���N�G�X�g���W�X�^ 
		.IRQ�s���̏�Ԃ�\���B�|�[�g��ǂ񂾂Ƃ��ɁAIRR�ɂȂ邩ISR�ɂȂ邩�́AOCW3�őI������B
		.1�ɂȂ��Ă���r�b�g�́A���ݗv�������Ă���i�������͏������́j���荞�݁B
	ISR�F�C���T�[�r�X���W�X�^ 
		.���ݏ������̊��荞�݂��ǂ�ł��邩�������B�|�[�g��ǂ񂾂Ƃ��ɁAIRR�ɂȂ邩ISR�ɂȂ邩�́AOCW3�őI������B
		.1�ɂȂ��Ă���r�b�g�́A���ݏ������̊��荞�݁B�������Ƃ����̂́ACPU�ɑ΂���INT���߂𔭍s�������AEOI�i���荞�ݏI�����߁j���󂯎���Ă��Ȃ����荞�݁B
	IMR�F�C���^���v�g�}�X�N���W�X�^ 
		.���ꂪ1�ɂȂ��Ă��銄�荞�݂́AIRR��1�ɂȂ��Ă��Ă��A�������Ȃ��B 
	*/

	io_out8(PIC0_IMR, 0xff);	/*���荞�ݑS�������i�}�X�^�j*/
	io_out8(PIC1_IMR, 0xff);	/*���荞�ݑS�������i�X���[�u�j*/

	io_out8(PIC0_ICW1, 0x11);	/*�G�b�W�g���K���[�h�ɐݒ�i�}�X�^�j*/
	io_out8(PIC0_ICW2, 0x20);	/*���荞�ݔԍ����A20~27�ɐݒ�B�i�}�X�^�j*/
	io_out8(PIC0_ICW3, 1 << 2);	/*00000100 �܂�A�X���[�u��IRQ2�ɂȂ����Ă܂���Ƃ������ƁB*/
	io_out8(PIC0_ICW4, 0x01);	/*�m���o�b�t�@���[�h�i�}�X�^�j*/

	io_out8(PIC1_ICW1, 0x11);	/*�G�b�W�g���K���[�h�ɐݒ�i�X���[�u�j*/
	io_out8(PIC1_ICW2, 0x28);	/*���荞�ݔԍ����A28~2f�ɐݒ�B�i�X���[�u�j*/
	io_out8(PIC1_ICW3, 2);	/*�����̓}�X�^��IRQ2�ԂɂȂ����Ă܂��Ƃ������ƁB*/
	io_out8(PIC1_ICW4, 0x01);	/*�m���o�b�t�@���[�h�i�X���[�u�j*/

	io_out8(PIC0_IMR, 0xf9);	/*11111001�܂�AIRQ2�ԁi�X���[�u�j��IRQ1�ԁi�L�[�{�[�h�j�������B���Ƃ͖����B�i�}�X�^�j*/	
	io_out8(PIC1_IMR, 0xff);	/*���荞�ݑS�������i�X���[�u�j*/

	return;
}

void inthandler21(int *esp)
{
	char s[30];
	unsigned char data;
	struct BOOTINFO *binfo = (struct BOOTINFO *) ADR_BOOTINFO;
	struct VESAINFO *vinfo = (struct VESAINFO *) ADR_VESAINFO;
	boxfill_i(vinfo->PhysBasePtr, binfo->scrnx, 0x000000, 0,240,264 , 256);	
	data = io_in8(KEYB_DATA);
	sprintf(s,"INT 21(IRQ-1) : PS/2 ���ް��%02X",data);
	putfonts_asc_i(vinfo->PhysBasePtr, binfo->scrnx, 0,240,0xffffff,s);
	io_out8(PIC0_OCW2, 0x61);	/* IRQ-01��t������PIC�ɒʒm �B0x60+�ԍ��B*/
	return;
}

void inthandler20(int *esp)
{
	struct BOOTINFO *binfo = (struct BOOTINFO *) ADR_BOOTINFO;
	struct VESAINFO *vinfo = (struct VESAINFO *) ADR_VESAINFO;
	char s[20];
	time_tick_100 ++;
	boxfill_i(vinfo->PhysBasePtr, binfo->scrnx, 0x000000, 0,256,264 , 272);	
	sprintf(s, "INT 20(IRQ-0) : PIT : %d", time_tick_100);
	putfonts_asc_i(vinfo->PhysBasePtr, binfo->scrnx, 0,256,0xffffff,s);
	io_out8(PIC0_OCW2, 0x60);	/* IRQ-00��t������PIC�ɒʒm �B0x60+�ԍ��B*/
	return;
}

