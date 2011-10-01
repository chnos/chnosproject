
/*debug option*/
#define CHNOSPROJECT_DEBUG		/*��`����ƃf�o�b�O���[�h�Ŏ��s�B���ꂼ��̃f�o�b�O�I�v�V�������L���ɂ���K�v������*/

#ifdef CHNOSPROJECT_DEBUG
	//#define CHNOSPROJECT_DEBUG_MEMORY	/*��`����ƃ������֘A�̃f�o�b�O���I���ɂ���*/
	#define CHNOSPROJECT_DEBUG_EMULATOR_X86
#endif

/*new object types*/
typedef enum _bool { false, true} bool;
typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef enum _col_text { black, blue, green, skyblue, red, purple, brown, white} col_text;

/*defines*/
#define True	1
#define False	0

typedef union DATA_BIT32 {
	uint data;
	struct DATA_BIT32_BIT {
		unsigned bit0 : 1;
		unsigned bit1 : 1;
		unsigned bit2 : 1;
		unsigned bit3 : 1;
		unsigned bit4 : 1;
		unsigned bit5 : 1;
		unsigned bit6 : 1;
		unsigned bit7 : 1;
		unsigned bit8 : 1;
		unsigned bit9 : 1;
		unsigned bit10 : 1;
		unsigned bit11 : 1;
		unsigned bit12 : 1;
		unsigned bit13 : 1;
		unsigned bit14 : 1;
		unsigned bit15 : 1;
		unsigned bit16 : 1;
		unsigned bit17 : 1;
		unsigned bit18 : 1;
		unsigned bit19 : 1;
		unsigned bit20 : 1;
		unsigned bit21 : 1;
		unsigned bit22 : 1;
		unsigned bit23 : 1;
		unsigned bit24 : 1;
		unsigned bit25 : 1;
		unsigned bit26 : 1;
		unsigned bit27 : 1;
		unsigned bit28 : 1;
		unsigned bit29 : 1;
		unsigned bit30 : 1;
		unsigned bit31 : 1;
	} bit;
} Data_Bit32;

typedef union CPU_CONTROL_REGISTER0 {
	uint cr0;
	struct CPU_CONTROL_REGISTER0_BIT {
		unsigned PE : 1;
		unsigned MP : 1;
		unsigned EM : 1;
		unsigned TS : 1;
		unsigned ET : 1;
		unsigned NE : 1;
		unsigned bit6 : 1;
		unsigned bit7 : 1;
		unsigned bit8 : 1;
		unsigned bit9 : 1;
		unsigned bit10 : 1;
		unsigned bit11 : 1;
		unsigned bit12 : 1;
		unsigned bit13 : 1;
		unsigned bit14 : 1;
		unsigned bit15 : 1;
		unsigned WP : 1;
		unsigned bit17 : 1;
		unsigned AM : 1;
		unsigned bit19 : 1;
		unsigned bit20 : 1;
		unsigned bit21 : 1;
		unsigned bit22 : 1;
		unsigned bit23 : 1;
		unsigned bit24 : 1;
		unsigned bit25 : 1;
		unsigned bit26 : 1;
		unsigned bit27 : 1;
		unsigned bit28 : 1;
		unsigned NW : 1;
		unsigned CD : 1;
		unsigned PG : 1;
	} bit;
} CPU_ControlRegister0;

typedef union CPU_CONTROL_REGISTER3 {
	uint cr3;
	struct CPU_CONTROL_REGISTER3_BIT {
		unsigned bit0 : 1;
		unsigned bit1 : 1;
		unsigned bit2 : 1;
		unsigned PWT : 1;
		unsigned PCD : 1;
		unsigned bit5 : 1;
		unsigned bit6 : 1;
		unsigned bit7 : 1;
		unsigned bit8 : 1;
		unsigned bit9 : 1;
		unsigned bit10 : 1;
		unsigned bit11 : 1;
		unsigned PDB : 20;
	} bit;
} CPU_ControlRegister3;

typedef union CPU_CONTROL_REGISTER4 {
	uint cr4;
	struct CPU_CONTROL_REGISTER4_BIT {
		unsigned VME : 1;
		unsigned PVI : 1;
		unsigned TSD : 1;
		unsigned DE : 1;
		unsigned PSE : 1;
		unsigned PAE : 1;
		unsigned MCE : 1;
		unsigned PGE : 1;
		unsigned PCE : 1;
		unsigned OSFXSR : 1;
		unsigned OSXMMEXCPT : 1;
		unsigned bit11 : 1;
		unsigned bit12 : 1;
		unsigned VMXE : 1;
		unsigned SMXE : 1;
		unsigned bit15 : 1;
		unsigned bit16 : 1;
		unsigned PCIDE : 1;
		unsigned OSXSAVE : 1;
		unsigned bit19 : 1;
		unsigned SMEP : 1;
		unsigned bit21 : 1;
		unsigned bit22 : 1;
		unsigned bit23 : 1;
		unsigned bit24 : 1;
		unsigned bit25 : 1;
		unsigned bit26 : 1;
		unsigned bit27 : 1;
		unsigned bit28 : 1;
		unsigned bit29 : 1;
		unsigned bit30 : 1;
		unsigned bit31 : 1;
	} bit;
} CPU_ControlRegister4;

typedef union CPU_EFLAGS {
	uint eflags;
	struct CPU_EFLAGS_BIT {
		unsigned CF : 1;
		unsigned bit1 : 1;
		unsigned PF : 1;
		unsigned bit3 : 1;
		unsigned AF : 1;
		unsigned bit5 : 1;
		unsigned ZF : 1;
		unsigned SF : 1;
		unsigned TF : 1;
		unsigned IF : 1;
		unsigned DF : 1;
		unsigned OF : 1;
		unsigned IOPL : 2;
		unsigned NT : 1;
		unsigned bit15 : 1;
		unsigned RF : 1;
		unsigned VM : 1;
		unsigned AC : 1;
		unsigned VIF : 1;
		unsigned VIP : 1;
		unsigned ID : 1;
		unsigned bit22 : 1;
		unsigned bit23 : 1;
		unsigned bit24 : 1;
		unsigned bit25 : 1;
		unsigned bit26 : 1;
		unsigned bit27 : 1;
		unsigned bit28 : 1;
		unsigned bit29 : 1;
		unsigned bit30 : 1;
		unsigned bit31 : 1;
	} bit;
} CPU_EFlags;

/*functions*/
/*bootpack.c �����*/
#define PHYSICAL_MEMORY_ALLOCATION_START_ADDRESS	0x00400000
#define SYSTEM_MEMORY_CONTROL_TAGS	1024
//
typedef struct IO_MEMORYCONTROLTAG {
	void *addr;
	uint size;
} IO_MemoryControlTag;

typedef IO_MemoryControlTag* IO_MemoryControl;

typedef struct SYSTEM_COMMONDATA {
	uint RunningPhase;
	uint PhysicalMemorySize;
	IO_MemoryControl MemoryController;
} System_CommonData;
//
void System_Set_RunningPhase(uint phase);
uint System_Get_RunningPhase(void);
void System_Check_Memory(void);
uint System_Get_PhisycalMemorySize(void);

/*cfunc.c vsnprintf�̓Ǝ�������*/
typedef struct CFUNCTION_VSNPRINTF_WORKAREA {
	uchar *destination_buf;		/*�������ݐ敶����̊J�n�A�h���X*/
	uint length_destination_buf;	/*�������ݐ敶����̍ő�T�C�Y*/
	uint index_destination_buf;	/*�������ݐ敶����̃C���f�b�N�X*/

	const uchar *format_buf;	/*�����w�蕶����̊J�n�A�h���X*/
	uint index_format_buf;		/*�����w�蕶����̃C���f�b�N�X*/

	uchar temporary_data[16];	/*�ꎞ�f�[�^�̔z��*/
	uchar temporary_data_double[8];	/*64�r�b�g���������_�p�o�b�t�@*/

	uint *vargs;			/*�ϒ������̊J�n�A�h���X*/
	uint index_vargs;		/*�ϒ������̌��݂̏ꏊ*/

	uint format_phase;		/*�t�H�[�}�b�g�̒i�K�������B*/
						/*���l	:�Ӗ�*/
						/*0	:�t�H�[�}�b�g�w�蒆�ł͂Ȃ�*/
						/*1	:�t���O�ȍ~�̏�����v��*/
						/*2	:�t�B�[���h���ȍ~�̏�����v���B*/
						/*3	:���x�ȍ~�̏�����v���B*/
						/*4	:�ϊ��C���q�ȍ~�̏�����v���B*/
						/*5	:�t�H�[�}�b�g�w��q��v��*/
} CFunction_vsnprintf_WorkArea;
//
int snprintf(uchar s[], const uchar format[], uint n, ...);
int vsnprintf(uchar s[], const uchar format[], uint n, uint vargs[]);
//
int CFunction_vsnprintf(uchar s[], const uchar format[], uint n, uint vargs[]);
void CFunction_vsnprintf_Initialise_WorkArea(CFunction_vsnprintf_WorkArea *work, uchar s[], const uchar format[], uint n, uint vargs[]);
int CFunction_vsnprintf_Check_FormatBuffer(CFunction_vsnprintf_WorkArea *work);
int CFunction_vsnprintf_Check_DestinationBuffer(CFunction_vsnprintf_WorkArea *work);
uchar CFunction_vsnprintf_Read_FormatBuffer(CFunction_vsnprintf_WorkArea *work);
void CFunction_vsnprintf_Write_DestinationBuffer(CFunction_vsnprintf_WorkArea *work, uchar c);
void CFunction_vsnprintf_End(CFunction_vsnprintf_WorkArea *work);
uint CFunction_vsnprintf_Get_NextArgument(CFunction_vsnprintf_WorkArea *work);
void CFunction_vsnprintf_To_String_From_Hex_Upper(CFunction_vsnprintf_WorkArea *work, uint hex);
void CFunction_vsnprintf_To_String_From_Hex_Lower(CFunction_vsnprintf_WorkArea *work, uint hex);
void CFunction_vsnprintf_To_String_From_Decimal_Unsigned(CFunction_vsnprintf_WorkArea *work, uint d);


/*dsctbl.c �Z�O�����g�E�Q�[�g�f�B�X�N���v�^�֘A*/
#define ADR_IDT		0x0026f800
#define LIMIT_IDT	0x000007ff
#define ADR_GDT		0x00270000
#define LIMIT_GDT	0x0000ffff
#define ADR_BOOTPACK	0x00280000
#define LIMIT_BOOTPACK	0x0007ffff
//
#define AR_DATA32_RW	0x4092	//AR_32+AR_PRESENT+AR_CODE_OR_DATA+AR_TYPE_DATA_RW
#define AR_CODE32_ER	0x409a	//AR_32+AR_PRESENT+AR_CODE_OR_DATA+AR_TYPE_CODE_ER
#define AR_LDT		0x0082	//AR_PRESENT+AR_SYSTEM_DESCRIPTOR+AR_TYPE_LDT
#define AR_TSS32	0x0089	//AR_PRESENT+AR_SYSTEM_DESCRIPTOR+AR_TYPE_TSS32_READY
#define AR_INTGATE32	0x008e	//AR_PRESENT+AR_SYSTEM_DESCRIPTOR+AR_TYPE_INTGATE32
//
#define AR_GRANULARITY_BYTE	0x0000	//G=0	�֐��Ŏ����ݒ肷��̂ł��̃r�b�g�͏��0
#define AR_GRANULARITY_4KB	0x8000	//G=1
#define AR_16			0x0000	//D/B=0
#define AR_32			0x4000	//D/B=1
#define AR_NOTPRESENT		0x0000	//P=0
#define AR_PRESENT		0x0080	//P=1
#define AR_SYSTEM		0x0000	//DPL=0
#define AR_USER			0x0060	//DPL=3
#define	AR_SYSTEM_DESCRIPTOR	0x0000	//S=0
#define AR_CODE_OR_DATA		0x0010	//S=1
//S=0
#define AR_TYPE_TSS16_READY	0x0001
#define AR_TYPE_LDT		0x0002
#define AR_TYPE_TSS16_BUSY	0x0003
#define AR_TYPE_CALLGATE16	0x0004
#define AR_TYPE_TASKGATE	0x0005
#define AR_TYPE_INTGATE16	0x0006
#define AR_TYPE_TRAPGATE16	0x0007
#define AR_TYPE_TSS32_READY	0x0009
#define AR_TYPE_TSS32_BUSY	0x000b
#define AR_TYPE_CALLGATE32	0x000c
#define AR_TYPE_INTGATE32	0x000e
#define AR_TYPE_TRAPGATE32	0x000f
//S=1
#define AR_TYPE_ACCESSED	0x0001	//�֐��ݒ莞�ɂ̓N���A�A�ǂݏo�����̓A�N�Z�X�ς݂Ȃ�Z�b�g
//DATA
#define AR_TYPE_DATA_R			0x0000
#define AR_TYPE_DATA_RW			0x0002
#define AR_TYPE_DATA_R_EXPAND_DOWN	0x0004
#define AR_TYPE_DATA_RW_EXPAND_DOWN	0x0006
//CODE
#define AR_TYPE_CODE_E			0x0008
#define AR_TYPE_CODE_ER			0x000a
#define AR_TYPE_CODE_E_CONFORMING	0x000c
#define AR_TYPE_CODE_ER_CONFORMING	0x000e
//
typedef struct SEGMENT_DESCRIPTOR { 
	ushort limit_low, base_low;
	uchar base_mid, access_right;
	uchar limit_high, base_high;
} IO_SegmentDescriptor;

typedef struct GATE_DESCRIPTOR { 
	ushort offset_low, selector;
	uchar dw_count, access_right;
	ushort offset_high;
} IO_GateDescriptor;
//
void Initialise_GlobalDescriptorTable(void);
void Initialise_InterruptDescriptorTable(void);
void SegmentDescriptor_Set(IO_SegmentDescriptor *seg_desc, uint limit, uint base, uint ar);
uint SegmentDescriptor_Get_Base(IO_SegmentDescriptor *seg_desc);
uint SegmentDescriptor_Get_Limit(IO_SegmentDescriptor *seg_desc);
uint SegmentDescriptor_Get_AccessRight(IO_SegmentDescriptor *seg_desc);
void GateDescriptor_Set(IO_GateDescriptor *gate_desc, uint offset, uint selector, uint ar);
void System_SegmentDescriptor_Set_Absolute(uint selector, uint limit, uint base, uint ar);
uint System_SegmentDescriptor_Get_Base(uint selector);
uint System_SegmentDescriptor_Get_Limit(uint selector);
uint System_SegmentDescriptor_Get_AccessRight(uint selector);
uint System_SegmentDescriptor_Set(uint limit, int base, int ar);
void System_GateDescriptor_Set(uint irq, uint offset, uint selector, uint ar);

/*emu86.c x86�G�~�����[�^�[�֘A*/
typedef struct EMULATOR_X86_ENVIRONMENT_SEGMENT_REGISTER {
	ushort selector;
	ushort type;
	uint base;
	uint limit;
} Emulator_x86_Environment_SegmentRegister;

typedef struct EMULATOR_X86_ENVIRONMENT_SYSTEM_TABLE_REGISTER {
	uint base;
	ushort limit;
} Emulator_x86_Environment_SystemTableRegister;

typedef struct EMULATOR_X86_ENVIRONMENT {
	CPU_EFlags EFLAGS;
	uint EIP;
//
	uint GReg[8];
//
	Emulator_x86_Environment_SystemTableRegister GDTR;
	Emulator_x86_Environment_SystemTableRegister IDTR;
//
	Emulator_x86_Environment_SegmentRegister SReg[8];
//
	CPU_ControlRegister0 CR0;
	uint CR2;
	CPU_ControlRegister3 CR3;
	CPU_ControlRegister4 CR4;
//
	uchar now_opcode;
	uchar operation_end;
	uchar operation_32bit;
	uchar operation_prefix_lock_repeat;
	uchar operation_prefix_segment;
	uchar operation_prefix_opsize;
	uchar operation_prefix_addrsize;
} Emulator_x86_Environment;

typedef union EMULATOR_X86_OPCODE_MODRM {
	uchar modrm;
	struct EMULATOR_X86_OPCODE_MODRM_BIT {
		unsigned RM : 3;
		unsigned Reg : 3;
		unsigned Mod : 2;
	} bit;
} Emulator_x86_OperationCode_ModRM;
//
#define OPCODE_REG_EAX			0
#define OPCODE_REG_ECX			1
#define OPCODE_REG_EDX			2
#define OPCODE_REG_EBX			3
#define OPCODE_REG_ESP			4
#define OPCODE_REG_EBP			5
#define OPCODE_REG_ESI			6
#define OPCODE_REG_EDI			7
//
#define OPCODE_W_BYTE			0
#define OPCODE_W_16BIT_OR_32BIT		1
//
#define OPCODE_REG_BYTE_AL		0
#define OPCODE_REG_BYTE_CL		1
#define OPCODE_REG_BYTE_DL		2
#define OPCODE_REG_BYTE_BL		3
#define OPCODE_REG_BYTE_AH		4
#define OPCODE_REG_BYTE_CH		5
#define OPCODE_REG_BYTE_DH		6
#define OPCODE_REG_BYTE_BH		7
//
#define OPCODE_SREG2_ES			0
#define OPCODE_SREG2_CS			1
#define OPCODE_SREG2_SS			2
#define OPCODE_SREG2_DS			3
//
#define OPCODE_SREG3_ES			0
#define OPCODE_SREG3_CS			1
#define OPCODE_SREG3_SS			2
#define OPCODE_SREG3_DS			3
#define OPCODE_SREG3_FS			4
#define OPCODE_SREG3_GS			5
//
#define OPCODE_EEE_CR0			0
#define OPCODE_EEE_CR2			2
#define OPCODE_EEE_CR3			3
#define OPCODE_EEE_CR4			4
//
#define OPCODE_EEE_DR0			0
#define OPCODE_EEE_DR1			1
#define OPCODE_EEE_DR2			2
#define OPCODE_EEE_DR3			3
#define OPCODE_EEE_DR6			6
#define OPCODE_EEE_DR7			7
//
#define OPCODE_TTTN_OVERFLOW		0
#define OPCODE_TTTN_NO_OVERFLOW		1
#define OPCODE_TTTN_BELOW		2
#define OPCODE_TTTN_NOT_BELOW		3
#define OPCODE_TTTN_EQUAL_OR_ZERO	4
#define OPCODE_TTTN_NOT_EQUAL_OR_ZERO	5
#define OPCODE_TTTN_NOT_ABOVE		6
#define OPCODE_TTTN_ABOVE		7
#define OPCODE_TTTN_SIGN		8
#define OPCODE_TTTN_NOT_SIGN		9
#define OPCODE_TTTN_PARITY		10
#define OPCODE_TTTN_NOT_PARITY		10
#define OPCODE_TTTN_LESS_THAN		10
#define OPCODE_TTTN_NOT_LESS_THAN	10
#define OPCODE_TTTN_NOT_GREATER_THAN	10
#define OPCODE_TTTN_GREATER_THAN	10
//
#define OPCODE_D_REG_SOURCE		0
#define OPCODE_D_REG_DESTINATION	1
//
#define OPCODE_MOD_INDEXONLY		0
#define OPCODE_MOD_INDEX_AND_DISP_BYTE	1
#define OPCODE_MOD_INDEX_AND_DISP_FULL	2
#define OPCODE_MOD_REGISTER		3
//
#define OPCODE_RM32_ADDR_EAX		0
#define OPCODE_RM32_ADDR_ECX		1
#define OPCODE_RM32_ADDR_EDX		2
#define OPCODE_RM32_ADDR_EBX		3
#define OPCODE_RM32_ADDR_SIB		4
#define OPCODE_RM32_ADDR_EBP		5
#define OPCODE_RM32_MOD00_ADDR_DISP32	5
#define OPCODE_RM32_ADDR_ESI		6
#define OPCODE_RM32_ADDR_EDI		7
//
#define OPCODE_RM16_ADDR_BX_SI		0
#define OPCODE_RM16_ADDR_BX_DI		1
#define OPCODE_RM16_ADDR_BP_SI		2
#define OPCODE_RM16_ADDR_BP_DI		3
#define OPCODE_RM16_ADDR_SI		4
#define OPCODE_RM16_ADDR_DI		5
#define OPCODE_RM16_ADDR_BP		6
#define OPCODE_RM16_MOD00_ADDR_DISP16	6
#define OPCODE_RM16_ADDR_BX		7
//
#define OPCODE_PREFIX_NONE		0
//
#define OPCODE_PREFIX_LOCK		0xf0
#define OPCODE_PREFIX_REPNE_REPNZ	0xf2
#define OPCODE_PREFIX_REP_REPE_REPZ	0xf3
//
//#define OPCODE_PREFIX_CS		0x2e
//#define OPCODE_PREFIX_SS		0x36
//#define OPCODE_PREFIX_DS		0x3e
//#define OPCODE_PREFIX_ES		0x26
//#define OPCODE_PREFIX_FS		0x64
//#define OPCODE_PREFIX_GS		0x65
#define OPCODE_PREFIX_BRANCH_NOT_TAKEN	0x2e
#define OPCODE_PREFIX_BRANCH_TAKEN	0x3e
//
#define OPCODE_PREFIX_OPERAND_SIZE	0x66
//
#define OPCODE_PREFIX_ADDRESS_SIZE	0x67
//
void Emulator_x86_Initialise(Emulator_x86_Environment *env);
uint Emulator_x86_Execute(Emulator_x86_Environment *env);
uint Emulator_x86_Execute_Auto(Emulator_x86_Environment *env);
uint Emulator_x86_FetchCode(Emulator_x86_Environment *env, uint bytes);
void Emulator_x86_InstructionPointer_Increment(Emulator_x86_Environment *env);
uint Emulator_x86_Get_EffectivePhysicalAddress(Emulator_x86_Environment *env, uint sreg, uint offset);
void Emulator_x86_MoveToGReg(Emulator_x86_Environment *env, uint reg, uint data, uint fullsize);
uint Emulator_x86_MoveFromGReg(Emulator_x86_Environment *env, uint reg, uint fullsize);
void Emulator_x86_MoveToSReg(Emulator_x86_Environment *env, uint sreg, ushort selector);
void Emulator_x86_Push_Data_To_Stack(Emulator_x86_Environment *env, uint data, uint size_dword);
uint Emulator_x86_Pop_Data_From_Stack(Emulator_x86_Environment *env, uint size_dword);
//
void Emulator_x86_Operation_MOV_To_Reg_FullSize(Emulator_x86_Environment *env);
void Emulator_x86_Operation_MOV_To_SegReg(Emulator_x86_Environment *env);
void Emulator_x86_Operation_MOV_To_ByteReg(Emulator_x86_Environment *env);
void Emulator_x86_Operation_INTn(Emulator_x86_Environment *env);
void Emulator_x86_Operation_LEA(Emulator_x86_Environment *env);
void Emulator_x86_Operation_CALL_Near_Relative(Emulator_x86_Environment *env);
void Emulator_x86_Operation_PUSHA(Emulator_x86_Environment *env);
void Emulator_x86_Operation_POPA(Emulator_x86_Environment *env);
void Emulator_x86_Operation_MOV_To_ByteReg_Gb_Eb(Emulator_x86_Environment *env);
void Emulator_x86_Operation_CMP_AL(Emulator_x86_Environment *env);
void Emulator_x86_Operation_Jcc_JE_rel8(Emulator_x86_Environment *env);
void Emulator_x86_Operation_INC_RegOnly(Emulator_x86_Environment *env);
void Emulator_x86_Operation_JMP_rel8(Emulator_x86_Environment *env);
void Emulator_x86_Operation_RET_Near(Emulator_x86_Environment *env);
void Emulator_x86_Operation_PUSH_RegOnly(Emulator_x86_Environment *env);

/*emu86asm.nas x86�G�~�����[�^�[�֘A�A�Z���u���֐�*/
uint asm_Emulator_x86_Get_EFlags_Compare(uint first_op, uint second_op);	//eflags��Ԃ�
uint asm_Emulator_x86_Get_EFlags_Increment(uint first_op);

/*error.c �G���[�֘A*/
#define ERROR_CPU_EXCEPTION_00			0x00000000	//int *esp
#define ERROR_CPU_EXCEPTION_01			0x00000001	//int *esp
#define ERROR_CPU_EXCEPTION_02			0x00000002	//int *esp
#define ERROR_CPU_EXCEPTION_03			0x00000003	//int *esp
#define ERROR_CPU_EXCEPTION_04			0x00000004	//int *esp
#define ERROR_CPU_EXCEPTION_05			0x00000005	//int *esp
#define ERROR_CPU_EXCEPTION_06			0x00000006	//int *esp
#define ERROR_CPU_EXCEPTION_07			0x00000007	//int *esp
#define ERROR_CPU_EXCEPTION_08			0x00000008	//int *esp
#define ERROR_CPU_EXCEPTION_09			0x00000009	//int *esp
#define ERROR_CPU_EXCEPTION_0A			0x0000000a	//int *esp
#define ERROR_CPU_EXCEPTION_0B			0x0000000b	//int *esp
#define ERROR_CPU_EXCEPTION_0C			0x0000000c	//int *esp
#define ERROR_CPU_EXCEPTION_0D			0x0000000d	//int *esp
#define ERROR_CPU_EXCEPTION_0E			0x0000000e	//int *esp
#define ERROR_CPU_EXCEPTION_0F			0x0000000f	//int *esp
#define ERROR_CPU_EXCEPTION_10			0x00000010	//int *esp
#define ERROR_CPU_EXCEPTION_11			0x00000011	//int *esp
#define ERROR_CPU_EXCEPTION_12			0x00000012	//int *esp
#define ERROR_CPU_EXCEPTION_13			0x00000013	//int *esp
#define ERROR_CPU_EXCEPTION_14			0x00000014	//int *esp
#define ERROR_CPU_EXCEPTION_15			0x00000015	//int *esp
#define ERROR_CPU_EXCEPTION_16			0x00000016	//int *esp
#define ERROR_CPU_EXCEPTION_17			0x00000017	//int *esp
#define ERROR_CPU_EXCEPTION_18			0x00000018	//int *esp
#define ERROR_CPU_EXCEPTION_19			0x00000019	//int *esp
#define ERROR_CPU_EXCEPTION_1A			0x0000001a	//int *esp
#define ERROR_CPU_EXCEPTION_1B			0x0000001b	//int *esp
#define ERROR_CPU_EXCEPTION_1C			0x0000001c	//int *esp
#define ERROR_CPU_EXCEPTION_1D			0x0000001d	//int *esp
#define ERROR_CPU_EXCEPTION_1E			0x0000001e	//int *esp
#define ERROR_CPU_EXCEPTION_1F			0x0000001f	//int *esp
#define ERROR_CPU_EXCEPTIONS			0x0000001f
//
#define ERROR_NO_MORE_SEGMENT			0x00000020	//uint *retaddr
#define ERROR_NOT_ENOUGH_FREE_MEMORY		0x00000021	//IO_MemoryControl ctrl, uint size
#define ERROR_MEMORY_FREE_RANGE_OVERLAPPED	0x00000022	//IO_MemoryControl ctrl, uint tagno
#define ERROR_NO_MORE_FREE_TAG			0x00000023	//IO_MemoryControl ctrl
#define ERROR_INVALID_FREE_MEMORY_INDEX		0x00000024	//IO_MemoryControl ctrl, uint tagno
//
uint Error_Report(uint error_no, ...);
void Error_Abort(void);
void Error_Set_Enable_SerialPort(bool serial);
void Error_Set_Enable_Display_TextMode(bool tdisp);
int Error_Put_String(const uchar format[], ...);
void Error_CPU_Exception_Put_Registers_With_ErrorCode(uint *esp);
void Error_CPU_Exception_Put_Registers_Without_ErrorCode(uint *esp);

/*intrpt.c ���荞�݊֘A*/
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
//
void Initialise_ProgrammableInterruptController(void);
void ProgrammableInterruptController_InterruptMask_Clear(uint irq);
void ProgrammableInterruptController_InterruptRequest_Complete(uint irq);
void InterruptHandler27(uint *esp);

/*keyboard.c �L�[�{�[�h�֘A*/
#define KEYB_DATA		0x0060
#define PORT_KEYSTA		0x0064
#define KEYSTA_SEND_NOTREADY	0x02
#define KEYCMD_WRITE_MODE	0x60
#define KBC_MODE		0x47
#define PORT_KEYCMD		0x0064
#define KEYCMD_SENDTO_MOUSE	0xd4
#define KEYCMD_LED		0xed
//
void Initialise_Keyboard(void);
void InterruptHandler21(uint *esp);

/*memory.c �������֘A*/
uint Memory_Test(uint start, uint end);
IO_MemoryControl Memory_Initialise_Control(void *start, uint size, uint tags);
void Memory_Free(IO_MemoryControl ctrl, void *addr, uint size);
void Memory_Free_Sub(IO_MemoryControl ctrl, uint tagno);
void *Memory_Allocate(IO_MemoryControl ctrl, uint size);
void *Memory_Allocate_Aligned(IO_MemoryControl ctrl, uint size, uint align);
uint Memory_Get_FreeSize(IO_MemoryControl ctrl);

/*serial.c �V���A���ʐM�֘A*/
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
//
void Initialise_SerialPort(void);
void SerialPort_Send(const uchar s[]);
//
#ifdef CHNOSPROJECT_DEBUG
void debug(const uchar format[], ...);
#endif

/*timer.c �^�C�}�[�֘A*/
#define PIT_CTRL	0x0043
#define PIT_CNT0	0x0040
//
void Initialise_ProgrammableIntervalTimer(void);
void InterruptHandler20(uint *esp);

/*vgatmode.c VGA�e�L�X�g���[�h�֘A*/
#define VGA_CRTC_R_NUMBER		0x03d4
#define VGA_CRTC_R_DATA			0x03d5
#define VGA_CRTC_R_CURSOR_LOCATION_HIGH	0x0e
#define VGA_CRTC_R_CURSOR_LOCATION_LOW	0x0f
#define VGA_TEXTMODE_ADR		0xb8000
//
uchar VGA_CRTController_ReadRegister(uchar regno);
void VGA_CRTController_WriteRegister(uchar regno, uchar data);
void TextMode_Write_TextRAM(ushort index, uchar data);
void TextMode_Put_Character_Absolute(uchar c, col_text col, ushort location);
void TextMode_Put_String_Absolute(const uchar s[], col_text col, uint x, uint y);
void TextMode_Clear_Screen(void);
ushort TextMode_Get_CursorLocation(void);
void TextMode_Set_CursorLocation(ushort location);
void TextMode_Put_Character(uchar c, col_text col);
void TextMode_Newline(void);
void TextMode_Put_String(const uchar s[], col_text col);

/*xception.c ��O�֘A*/
void CPU_ExceptionHandler00(int *esp);
void CPU_ExceptionHandler01(int *esp);
void CPU_ExceptionHandler02(int *esp);
void CPU_ExceptionHandler03(int *esp);
void CPU_ExceptionHandler04(int *esp);
void CPU_ExceptionHandler05(int *esp);
void CPU_ExceptionHandler06(int *esp);
void CPU_ExceptionHandler07(int *esp);
void CPU_ExceptionHandler08(int *esp);
void CPU_ExceptionHandler09(int *esp);
void CPU_ExceptionHandler0a(int *esp);
void CPU_ExceptionHandler0b(int *esp);
void CPU_ExceptionHandler0c(int *esp);
void CPU_ExceptionHandler0d(int *esp);
void CPU_ExceptionHandler0e(int *esp);
void CPU_ExceptionHandler0f(int *esp);
void CPU_ExceptionHandler10(int *esp);
void CPU_ExceptionHandler11(int *esp);
void CPU_ExceptionHandler12(int *esp);
void CPU_ExceptionHandler13(int *esp);
void CPU_ExceptionHandler14(int *esp);
void CPU_ExceptionHandler15(int *esp);
void CPU_ExceptionHandler16(int *esp);
void CPU_ExceptionHandler17(int *esp);
void CPU_ExceptionHandler18(int *esp);
void CPU_ExceptionHandler19(int *esp);
void CPU_ExceptionHandler1a(int *esp);
void CPU_ExceptionHandler1b(int *esp);
void CPU_ExceptionHandler1c(int *esp);
void CPU_ExceptionHandler1d(int *esp);
void CPU_ExceptionHandler1e(int *esp);
void CPU_ExceptionHandler1f(int *esp);

/*nasfunc0.nas ���̊֐��ɑS���ˑ����Ȃ��A�Z���u���֐��Q*/
void IO_HLT(void);			//CPU���~������B���荞�݂�����ƍĊJ����B�������߁B
void IO_CLI(void);			//CPU�ւ̊O�����荞�݂��~������B�������߁BNMI�Ɨ�O�ɂ͌����Ȃ��B
void IO_STI(void);			//CPU�ւ̊O�����荞�݂��ĊJ������B�������߁B
void IO_STIHLT(void);			//CPU�ւ̊O�����荞�݂��ĊJ��������ACPU���~������Bsti��hlt�̊Ԃɔ������銄�荞�݂ւ̑΍�B�B
uint IO_In8(uint port);			//port�Ԃ�I/O�|�[�g����f�[�^���o�C�g�P�ʂŎ󂯎��B�߂�l�͎󂯎�����f�[�^�BI/O�������߁B
void IO_Out8(uint port, uint data);	//port�Ԃ�I/O�|�[�g��data���o�C�g�P�ʂŏo�͂���BI/O�������߁B
uint IO_In16(uint port);		//port�Ԃ�I/O�|�[�g����f�[�^�����[�h�P�ʂŎ󂯎��B�߂�l�͎󂯎�����f�[�^�BI/O�������߁B
void IO_Out16(uint port, uint data);	//port�Ԃ�I/O�|�[�g��data�����[�h�P�ʂŏo�͂���BI/O�������߁B
uint IO_In32(uint port);		//port�Ԃ�I/O�|�[�g����f�[�^���_�u�����[�h�P�ʂŎ󂯎��B�߂�l�͎󂯎�����f�[�^�BI/O�������߁B
void IO_Out32(uint port, uint data);	//port�Ԃ�I/O�|�[�g��data���_�u�����[�h�P�ʂŏo�͂���BI/O�������߁B
uint IO_Load_EFlags(void);		//EFLAGS���W�X�^��ǂݍ��ށB
void IO_Store_EFlags(uint eflags);	//EFLAGS���W�X�^��eflags�ɕύX����B
uint Load_CR0(void);			//�R���g���[�����W�X�^0��ǂݍ��ށB�������߁B
void Store_CR0(uint cr0);		//�R���g���[�����W�X�^0��cr0�ɕύX����B�������߁B
uint Load_CR2(void);			//�R���g���[�����W�X�^2��ǂݍ��ށB�������߁B
void Store_CR2(uint cr2);		//�R���g���[�����W�X�^2��cr2�ɕύX����B�������߁B
uint Load_CR3(void);			//�R���g���[�����W�X�^3��ǂݍ��ށB�������߁B
void Store_CR3(uint cr3);		//�R���g���[�����W�X�^3��cr3�ɕύX����B�������߁B
uint Load_CR4(void);			//�R���g���[�����W�X�^4��ǂݍ��ށB�������߁B
void Store_CR4(uint cr4);		//�R���g���[�����W�X�^4��cr4�ɕύX����B�������߁B
void Load_GDTR(uint limit, uint addr);	//�O���[�o���E�f�B�X�N���v�^�E�e�[�u���E���W�X�^(GDTR)�ɁAaddr����limit�͈̔͂�GDT�Ƃ��ă��[�h������B�������߁B
void Load_IDTR(uint limit, uint addr);	//�C���^���v�g�E�f�B�X�N���v�^�E�e�[�u���E���W�X�^(IDTR)�ɁAaddr����limit�͈̔͂�IDT�Ƃ��ă��[�h������B�������߁B
void Load_TR(uint tr);			//�Z�O�����g�E�Z���N�^tr���A�^�X�N���W�X�^�Ɍ��݂̃^�X�N�Ƃ��ă��[�h������B�������߁B
void FarJMP(uint eip, uint cs);		//���݂̃Z�O�����g�Ƃ͈قȂ�Z�O�����gcs�̃I�t�Z�b�geip�Ƀv���O�����̐�����ڂ��B
void FarCall(uint eip, uint cs);	//���݂̃Z�O�����g�Ƃ͈قȂ�Z�O�����gcs�̃I�t�Z�b�geip�Ƀv���O�����̐���𕪊򂳂���B
void CLTS(void);			//�R���g���[���E���W�X�^0���ɂ���ATask-Switched�t���O���N���A����BFPU�̐���ɗ��p�B�������߁B
void FNSave(uint *addr);		//FPU�������addr����n�܂�108�o�C�g�Ɋi�[���AFPU������������B�ڍׂȃ`�F�b�N�͍s��Ȃ��B
void FRStore(uint *addr);		//FPU�������addr����n�܂�108�o�C�g���畜������B
void PIT_Beep_On(void);			//�r�[�v�����J�n����B
void PIT_Beep_Off(void);		//�r�[�v�����~����B
void PIT_Beep_Set(uint fq);		//�r�[�v���̎��g�����AfqHz�ɕύX����B
					//fq�̒l
					//C:262 C#:277 D:294 D#:311 E:330 F:349 F#:370 G:392 G#:415 A:440 A#:466 B:494 C:523
void CPUID(void *addr, uint id);	//addr�Ԓn��uint[4]�ɁACPU�̎��ʏ��id�Ԃ�EAX�EEBX�EEDX�EECX�̏��ԂŊi�[����B
void CPUID2(void *addr, uint id);	//addr�Ԓn��uint[4]�ɁACPU�̎��ʏ��id�Ԃ�EAX�EEBX�EECX�EEDX�̏��ԂŊi�[����B
					//��L��̊֐��́AEFLAGS����ID�t���O(�r�b�g21)���ύX�\�ȏꍇ�̂ݎ��s�ł���B
void TSC_Read(uint *addr);		//addr�Ԓn��uint[2]�ɁA�}�V���ŗL���W�X�^(MSR)���ɂ���A�^�C���E�X�^���v�E�J�E���^�̏�ʁE���ʂ��ꂼ��32�r�b�g��ǂݍ��ށB
					//���̊֐��́Acpuid��TSC�r�b�g���L���łȂ���Ύg�p�ł��Ȃ��B
uint Memory_Test_Sub(uint start, uint end);
void INT_3(void);			//�u���[�N�|�C���g��O�𔭐�������B
uint DIV_64_32(uint dividend_low, uint dividend_high, uint divisor);
					//=((dividend_high << 32) | dividend_low) / divisor
uint MOD_64_32(uint dividend_low, uint dividend_high, uint divisor);
					//=((dividend_high << 32) | dividend_low) % divisor
/*nasfunc0.nas ���̊֐��Ɉˑ�����A�Z���u���֐��Q*/
void asm_CPU_ExceptionHandler00(void);
void asm_CPU_ExceptionHandler01(void);
void asm_CPU_ExceptionHandler02(void);
void asm_CPU_ExceptionHandler03(void);
void asm_CPU_ExceptionHandler04(void);
void asm_CPU_ExceptionHandler05(void);
void asm_CPU_ExceptionHandler06(void);
void asm_CPU_ExceptionHandler07(void);
void asm_CPU_ExceptionHandler08(void);
void asm_CPU_ExceptionHandler09(void);
void asm_CPU_ExceptionHandler0a(void);
void asm_CPU_ExceptionHandler0b(void);
void asm_CPU_ExceptionHandler0c(void);
void asm_CPU_ExceptionHandler0d(void);
void asm_CPU_ExceptionHandler0e(void);
void asm_CPU_ExceptionHandler0f(void);
void asm_CPU_ExceptionHandler10(void);
void asm_CPU_ExceptionHandler11(void);
void asm_CPU_ExceptionHandler12(void);
void asm_CPU_ExceptionHandler13(void);
void asm_CPU_ExceptionHandler14(void);
void asm_CPU_ExceptionHandler15(void);
void asm_CPU_ExceptionHandler16(void);
void asm_CPU_ExceptionHandler17(void);
void asm_CPU_ExceptionHandler18(void);
void asm_CPU_ExceptionHandler19(void);
void asm_CPU_ExceptionHandler1a(void);
void asm_CPU_ExceptionHandler1b(void);
void asm_CPU_ExceptionHandler1c(void);
void asm_CPU_ExceptionHandler1d(void);
void asm_CPU_ExceptionHandler1e(void);
void asm_CPU_ExceptionHandler1f(void);
//
void asm_InterruptHandler20(void);
void asm_InterruptHandler21(void);
void asm_InterruptHandler27(void);