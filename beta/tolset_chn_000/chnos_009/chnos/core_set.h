
/* MemoryMap */
//00 00 0d 00	VESA_BIOS_INFO			0x100(256)Bytes

//00 00 0e 00	VESA_MODE_INFO			0x100(256)Bytes

//00 00 0f f0	BootInfo	CYLS		uchar
//00 00 0f f1			LEDS		uchar
//00 00 0f f2			VMODE		uchar
//00 00 0f f3			(Padding)	uchar
//00 00 0f f4			SCRNX		ushort
//00 00 0f f6			SCRNY		ushort
//00 00 0f f8			VRAM		*uchar
//00 00 0f fc			VESAVER		ushort
//00 00 0f fe			APMVER		ushort
//00 00 10 00			ACPI_MEMMAPS	uint
//00 00 10 04			ACPI_MEMMAP	0x18(24)*16=0x180(384)Bytes
//00 00 11 84			APM_FLAGS	ushort

//00 00 7c 00	IPL				0x200(512)Bytes

//00 00 80 00	DSKCAC0				0x168000(1.44M)Bytes

//00 10 00 00	DSKCAC				0x168000(1.44M)Bytes

//00 26 f8 00	IDT				0x800(2K)Bytes

//00 27 00 00	GDT				0x10000(64K)Bytes

//00 28 00 00	bootpack.chn			0x80000(512K)Bytes

//00 40 00 00	メモリ領域開始

#define ADR_BOOTINFO	0x00000ff0
#define ADR_VESAINFO	0x00000e00
#define ADR_DISKIMG	0x00100000

#define EFLAGS_AC_BIT	0x00040000

#define CR0_PROTECTIONENABLE	0x00000001
#define CR0_MONITORCOPROCESSOR	0x00000002
#define CR0_EMULATION		0x00000004
#define CR0_TASKSWITCH		0x00000008
#define CR0_EXTENDEDTYPE	0x00000010
#define CR0_NUMERICERROR	0x00000020
#define CR0_WRITEPROTECT	0x00010000
#define CR0_ALIGNMENTMASK	0x00040000
#define CR0_NOTWRITETHROUGH	0x20000000
#define CR0_CACHE_DISABLE	0x40000000
#define CR0_PAGING		0x80000000

#define CR0_ALL_CACHE_DISABLE	CR0_NOTWRITETHROUGH + CR0_CACHE_DISABLE

#define PG_NOTPRESENT	0x00000000
#define PG_PRESENT	0x00000001
#define PG_READONLY	0x00000000
#define PG_WRITABLE	0x00000002
#define PG_SUPERVISOR	0x00000000
#define PG_USER		0x00000004
#define PG_WRITEBACK	0x00000000
#define PG_WRITETHROUGH	0x00000008
#define PG_CACHE_ENABLE	0x00000000
#define PG_CACHE_DISABLE	0x00000010
#define PG_NOTACCESSED	0x00000000
#define PG_ACCESSED	0x00000020
#define PG_NOTWRITTEN	0x00000000
#define PG_WRITTEN	0x00000040
#define PG_4KBPAGE	0x00000000
#define PG_4MBPAGE	0x00000080
#define PG_NOTGLOBAL	0x00000000
#define	PG_GLOBAL	0x00000100

#define ADR_IDT		0x0026f800
#define LIMIT_IDT	0x000007ff
#define ADR_GDT		0x00270000
#define LIMIT_GDT	0x0000ffff
#define ADR_BOTPAK	0x00280000
#define LIMIT_BOTPAK	0x0007ffff
#define AR_DATA32_RW	0x4092
#define AR_CODE32_ER	0x409a
#define AR_LDT		0x0082
#define AR_TSS32	0x0089
#define AR_INTGATE32	0x008e
#define AR_APP		0x60

#define COL8_000000		0
#define COL8_FF0000		1
#define COL8_00FF00		2
#define COL8_FFFF00		3
#define COL8_0000FF		4
#define COL8_FF00FF		5
#define COL8_00FFFF		6
#define COL8_FFFFFF		7
#define COL8_C6C6C6		8
#define COL8_840000		9
#define COL8_008400		10
#define COL8_848400		11
#define COL8_000084		12
#define COL8_840084		13
#define COL8_008484		14
#define COL8_848484		15

//#define INV_COL32	0xFFFFFFFF
//#define INV_COL16	0x1192
//#define INV_COL8	0xFF

//#define DESKTOP_COL8	COL8_C6C6C6
//#define TASKBAR_COL8	COL8_0000FF

//#define DESKTOP_COL16	RGB16(17,33,17)		/*初期値：10,20,10*/
//#define TASKBAR_COL16	RGB16(20,40,30)		/*初期値：20,40,30*/

//#define DESKTOP_COL32	0x34FF1E
//#define TASKBAR_COL32	0x5EC1E8

//#define TASKBAR_HEIGHT	40

//#define MEMMAN_FREES	4000

#define MEMORY_DESCRIPTION_LENGTH	16

//#define INV_COL32	0xFFFFFFFF
//#define INV_COL16	0x1192
//#define INV_COL8	0xFF

//#define MAX_SHEETS	1024

#define PIC0_ICW1	0x0020
#define PIC0_OCW2	0x0020
#define PIC0_IMR	0x0021
#define PIC0_ICW2	0x0021
#define PIC0_ICW3	0x0021
#define PIC0_ICW4	0x0021
#define PIC1_ICW1	0x00a0
#define PIC1_OCW2	0x00a0
#define PIC1_IMR	0x00a1
#define PIC1_ICW2	0x00a1
#define PIC1_ICW3	0x00a1
#define PIC1_ICW4	0x00a1

//#define MAX_TASKS	1000
//#define TASK_GDT_START	3
//#define MAX_LEVEL_TASKS	100
//#define MAX_LEVELS	10

#define MAX_TIMER	512

#define FIFO32_PUT_OVERFLOW	0x0001

//#define SYS_FIFOSIZE	256
//#define KEYCMD_FIFOSIZE	128
//#define KEYCTRL_FIFOSIZE	128
//#define MOUSECTRL_FIFOSIZE	128

#define PIT_CTRL	0x0043
#define PIT_CNT0	0x0040

#define KEYB_DATA	0x0060
#define PORT_KEYSTA	0x0064
#define KEYSTA_SEND_NOTREADY	0x02
#define KEYCMD_WRITE_MODE	0x60
#define KBC_MODE	0x47
#define PORT_KEYCMD	0x0064
#define KEYCMD_SENDTO_MOUSE	0xd4
#define KEYCMD_LED	0xed

#define MOUSECMD_RESET	0xff
#define MOUSECMD_RESEND	0xfe
#define MOUSECMD_SET_DEFAULTS	0xf6
#define MOUSECMD_DISABLE_DATA_REPORTING	0xf5
#define MOUSECMD_ENABLE_DATA_REPORTING	0xf4
#define MOUSECMD_SET_SAMPLE_RATE	0xf3
#define MOUSECMD_GET_DEVICE_ID	0xf2


//#define MAX_WINDOWS	256
//#define WIN_COL8_ACTIVE		0x000084
//#define WIN_COL8_INACTIVE	0x848484
//#define WIN_COL16_ACTIVE	0x60F8f0
//#define WIN_COL16_INACTIVE	0xBCFCF8
//#define WIN_COL32_ACTIVE	0x93D9FF
//#define WIN_COL32_INACTIVE	0xD0EFFF

//#define CONSOLE_FIFO_BUF_SIZE	128
//#define CONSOLE_FIFO_START_KEYB	128
//#define CONSOLE_FIFO_CURSOR_START	2
//#define CONSOLE_FIFO_CURSOR_STOP	3
//#define CONSOLE_COLOR_BACKGROUND	0x000000
//#define CONSOLE_COLOR_CHAR	0xFFFFFF
//#define CONSOLE_CMDLINE_BUF_SIZE	128
//#define MAX_CONSOLES	16

#define DATA_BYTE	0x100

#define COM1_RX		0x03f8
#define COM1_TX		0x03f8
#define COM1_BAUD_LSB	0x03f8
#define COM1_BAUD_MSB	0x03f9
#define COM1_INTR_ENBL	0x03f9
#define COM1_INTR_ID	0x03fa
#define COM1_CTRL_FIFO	0x03fa
#define COM1_CTRL_LINE	0x03fb
#define COM1_CTRL_MODEM	0x03fc
#define COM1_STA_LINE	0x03fd
#define COM1_STA_MODEM	0x03fe

