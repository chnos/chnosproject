
#include "core.h"

//�V�[�g����p�����֐��Bsheet.c�ȊO����͌Ăяo���֎~�B
//���̑���A�V�[�g�L�����`�F�b�N�͂�����x�Ȃ��B
//�Ăяo�����̊֐��ŁA�V�[�g���L���ł��邱�Ƃ��m�F���Ă���n�����ƁB

//uint Sheet_Internal_GetLocation[P,Q,R,S](UI_Sheet *sheet, DATA_Location2D *dest);
//�������݉\�Ȃ����Ƃ��[�̊e���W��e�V�[�g�ł̍��W�ŋ��߂�Bdest�ɍ��W���i�[�B
//�e���Ȃ��V�[�g�̏ꍇ�́A�߂�l��1�ɂȂ�Alocation��(0,0)�ł���Ɖ��肳���B
//�e�̂���V�[�g�̏ꍇ�́A�߂�l��0�ɂȂ�A�e���W���i�[�����B

uint Sheet_Internal_GetLocationP(UI_Sheet *sheet, DATA_Location2D *dest)
{
	if(sheet->parent == Null){
		dest->x = 0;
		dest->y = 0;
		return 1;
	}
	dest->x = sheet->location.x;
	dest->y = sheet->location.y;

	return 0;
}

uint Sheet_Internal_GetLocationQ(UI_Sheet *sheet, DATA_Location2D *dest)
{
	if(sheet->parent == Null){
		dest->x = 0;
		dest->y = (int)sheet->size.y - 1;
		return 1;
	}
	dest->x = sheet->location.x;
	dest->y = sheet->location.y + (int)sheet->size.y - 1;

	return 0;
}

uint Sheet_Internal_GetLocationR(UI_Sheet *sheet, DATA_Location2D *dest)
{
	if(sheet->parent == Null){
		dest->x = (int)sheet->size.x - 1;
		dest->y = (int)sheet->size.y - 1;
		return 1;
	}
	dest->x = sheet->location.x + (int)sheet->size.x - 1;
	dest->y = sheet->location.y + (int)sheet->size.y - 1;

	return 0;
}

uint Sheet_Internal_GetLocationS(UI_Sheet *sheet, DATA_Location2D *dest)
{
	if(sheet->parent == Null){
		dest->x = (int)sheet->size.x - 1;
		dest->y = 0;
		return 1;
	}
	dest->x = sheet->location.x + (int)sheet->size.x - 1;
	dest->y = sheet->location.y;

	return 0;
}

//uint Sheet_Internal_MapInitialise(UI_Sheet *parent);
//map������������B
//���łɃ}�b�v���m�ۂ���Ă����ꍇ�́A���������ɍĊm�ۂ���B
//�}�b�v�̍č\���������ōs���B

uint Sheet_Internal_MapInitialise(UI_Sheet *parent)
{
	if(parent->flags.bit.using_map){
		parent->flags.bit.using_map = False;
		System_Memory_Free(parent->map, parent->mapsize);
	}

	parent->mapsize = parent->size.x * parent->size.y * 4;
	parent->map = (uint *)System_Memory_Allocate(parent->mapsize);
	MOVSD_ZeroFill(parent->map, parent->mapsize);
	parent->flags.bit.using_map = True;

	Sheet_Internal_MapRebuild(parent, 0, 0, parent->size.x - 1, parent->size.y - 1);

	return 0;
}

//uint Sheet_Internal_Map[Write, Clear]FromSheet(UI_Sheet *sheet, bool force);
//�e�V�[�g�͈͓̔��̃}�b�v�𐶐�����B
//force��False�̎��́Amap��Null�܂��͎����̃A�h���X�̕�������������Ȃ��B
//force��True�̎��́Amap�͈͓̔��ɋ����I�ɏ������ށB

uint Sheet_Internal_MapWriteFromSheet(UI_Sheet *sheet, bool force, int px0, int py0, int px1, int py1)
{
	int x, y;
	DATA_Location2D p, r;

	if(sheet->parent == Null){
		#ifdef CHNOSPROJECT_DEBUG_SHEET
			debug("Sheet_Internal_MapWriteFromSheet:Null parent.\n");
		#endif
		return 1;
	}

	if(sheet->parent->map == Null){
		#ifdef CHNOSPROJECT_DEBUG_SHEET
			debug("Sheet_Internal_MapWriteFromSheet:Null map.\n");
		#endif
		return 2;
	}

	if(!sheet->flags.bit.visible){
		return 0;
	}

	Sheet_Internal_GetLocationP(sheet, &p);
	Sheet_Internal_GetLocationR(sheet, &r);

	if(p.x < px0){
		p.x = px0;
	}
	if(p.y < py0){
		p.y = py0;
	}
	if(r.x > px1){
		r.x = px1;
	}
	if(r.y > py1){
		r.y = py1;
	}

	if(p.x < 0){
		p.x = 0;
	}
	if(p.y < 0){
		p.y = 0;
	}
	if(r.x >= sheet->parent->size.x){
		r.x = sheet->parent->size.x - 1;
	}
	if(r.y >= sheet->parent->size.y){
		r.y = sheet->parent->size.y - 1;
	}

	if(force){
		for(y = p.y; y <= r.y; y++){
			for(x = p.x; x <= r.x; x++){
				sheet->parent->map[y * sheet->parent->size.x + x] = (uint)sheet;
			}
		}
	} else{
		for(y = p.y; y <= r.y; y++){
			for(x = p.x; x <= r.x; x++){
				if(sheet->parent->map[y * sheet->parent->size.x + x] == Null){
					sheet->parent->map[y * sheet->parent->size.x + x] = (uint)sheet;
				}
			}
		}
	}

	return 0;
}

uint Sheet_Internal_MapClearFromSheet(UI_Sheet *sheet, bool force, int px0, int py0, int px1, int py1)
{
	int x, y;
	DATA_Location2D p, r;

	if(sheet->parent == Null){
		#ifdef CHNOSPROJECT_DEBUG_SHEET
			debug("Sheet_Internal_MapClearFromSheet:Null parent.\n");
		#endif
		return 1;
	}

	if(sheet->parent->map == Null){
		#ifdef CHNOSPROJECT_DEBUG_SHEET
			debug("Sheet_Internal_MapClearFromSheet:Null map.\n");
		#endif
		return 2;
	}

	Sheet_Internal_GetLocationP(sheet, &p);
	Sheet_Internal_GetLocationR(sheet, &r);

	if(p.x < px0){
		p.x = px0;
	}
	if(p.y < py0){
		p.y = py0;
	}
	if(r.x > px1){
		r.x = px1;
	}
	if(r.y > py1){
		r.y = py1;
	}

	if(p.x < 0){
		p.x = 0;
	}
	if(p.y < 0){
		p.y = 0;
	}
	if(r.x >= sheet->parent->size.x){
		r.x = sheet->parent->size.x - 1;
	}
	if(r.y >= sheet->parent->size.y){
		r.y = sheet->parent->size.y - 1;
	}

	if(force){
		for(y = p.y; y <= r.y; y++){
			for(x = p.x; x <= r.x; x++){
				sheet->parent->map[y * sheet->parent->size.x + x] = Null;
			}
		}
	} else{
		for(y = p.y; y <= r.y; y++){
			for(x = p.x; x <= r.x; x++){
				if(sheet->parent->map[y * sheet->parent->size.x + x] == (uint)sheet){
					sheet->parent->map[y * sheet->parent->size.x + x] = Null;
				}
			}
		}
	}

	return 0;
}

//bool Sheet_Internal_IsLocationInRangeOfSheet(UI_Sheet *sheet, int px, int py);
//���̃V�[�g���A���̃V�[�g�̐e�����ł̍��W�ł���(px, py)���܂ނ��ǂ�����Ԃ��B
//�V�[�g�������ł��AFalse��Ԃ������ł���B
//�e�����Ȃ��V�[�g�ł��̊֐������s���Ă����Ӗ����Ǝv����̂ŁAFalse��Ԃ������ł���B

bool Sheet_Internal_IsLocationInRangeOfSheet(UI_Sheet *sheet, int px, int py)
{
	if(sheet == Null){
		return False;
	}
	if(sheet->parent == Null){
		return False;
	}

	if(sheet->location.x > px || sheet->location.y > py){
		return False;
	}
	if(sheet->location.x + (int)sheet->size.x - 1 < px || sheet->location.y + (int)sheet->size.y - 1 < py){
		return False;
	}

	return True;
}

//bool Sheet_Internal_IsRangeOverlappedWithSheet(UI_Sheet *sheet, int px0, int py0, int px1, int py1);
//�w�肳�ꂽ�V�[�g�������̍��W�͈͓��ɏd�Ȃ邩�ǂ�����Ԃ��B

bool Sheet_Internal_IsRangeOverlappedWithSheet(UI_Sheet *sheet, int px0, int py0, int px1, int py1)
{
	if(sheet == Null){
		return False;
	}
	if(sheet->parent == Null){
		return False;
	}

	if(sheet->location.x > px1){
		return False;
	}

	if(sheet->location.y > py1){
		return False;
	}

	if(sheet->location.x + (int)sheet->size.x - 1 < px0){
		return False;
	}

	if(sheet->location.y + (int)sheet->size.y - 1 < py0){
		return False;
	}

	return True;
}

//UI_Sheet *Sheet_Internal_GetSheetFromLocation(UI_Sheet *parent, int px, int py)
//�e�����ł�(px, py)�ɂ�����A����Ԃ̂����Ƃ����������̃V�[�g��Ԃ��B
//���̊֐��͂����ƒx���̂ŁAmap�����p�ł��Ȃ����̂݁A�g�p����ׂ��ł���B
//�G���[�������������́ANull��Ԃ������ł���B

UI_Sheet *Sheet_Internal_GetSheetFromLocation(UI_Sheet *parent, int px, int py)
{
	uint i;
	UI_Sheet *sheet, *search;

	sheet = Null;

	search = parent->child;
	for(i = 0; i < SHEET_MAX_CHILDREN; i++){
		if(search == Null){
			break;
		}
		if(Sheet_Internal_IsLocationInRangeOfSheet(search, px, py) && search->flags.bit.visible){
			sheet = search;
		}
		search = search->next;
	}

	return sheet;
}

//uint Sheet_Internal_MapRebuild(UI_Sheet *parent, int px0, int py0, int px1, int py1);
//���͈͓̔��̃}�b�v�����S�ɍč\������B
uint Sheet_Internal_MapRebuild(UI_Sheet *parent, int px0, int py0, int px1, int py1)
{
	uint i;
	UI_Sheet *search;

	search = parent->child;
	for(i = 0; i < SHEET_MAX_CHILDREN; i++){
		if(search == Null){
			break;
		}
		if(Sheet_Internal_IsRangeOverlappedWithSheet(search, px0, py0, px1, py1)){
			Sheet_Internal_MapWriteFromSheet(search, True, px0, py0, px1, py1);
		}
		search = search->next;
	}

	return 0;
}

//uint Sheet_Internal_MapRefresh(UI_Sheet *sheet, int px0, int py0, int px1, int py1);
//���͈͓̔��̃}�b�v���Asheet�ɕύX���������Ƃ��āA�ŏ����ōč\������B
//���W��map(parent)�Ȃ̂Œ��ӁB
//nolocationchanged==True�ŁAsheet�̈ړ����������̂Ƃ݂Ȃ��A�������ݑΏۂ����X�V�[�g���������ꏊ�݂̂Ɍ��肷��B
//nolocationchanged==False�ŁAsheet�̍����܂ł͂��ׂčč\������B
uint Sheet_Internal_MapRefresh(UI_Sheet *sheet, int px0, int py0, int px1, int py1, bool nolocationchanged)
{
	UI_Sheet *search;
	int x, y;
	uint i; 

	if(px0 < 0){
		px0 = 0;
	}
	if(py0 < 0){
		py0 = 0;
	}
	if(px1 >= sheet->parent->size.x){
		px1 = sheet->parent->size.x - 1;
	}
	if(py1 >= sheet->parent->size.y){
		py1 = sheet->parent->size.y - 1;
	}

	if(!nolocationchanged){
		search = sheet->parent->child;
		for(i = 0; i < SHEET_MAX_CHILDREN; i++){
			if(search == Null){
				break;
			}
			if(Sheet_Internal_IsRangeOverlappedWithSheet(search, px0, py0, px1, py1)){
				Sheet_Internal_MapClearFromSheet(search, False, px0, py0, px1, py1);
			}
			if(search == sheet){
				break;
			}
			search = search->next;
		}
	} else{
		Sheet_Internal_MapClearFromSheet(sheet, False, px0, py0, px1, py1);
	}

	for(y = py0; y <= py1; y++){
		for(x = px0; x <= px1; x++){
			if(sheet->parent->map[y * sheet->parent->size.x + x] == Null){
				search = Sheet_Internal_GetSheetFromLocation(sheet->parent, x, y);
				if(search != Null){
					Sheet_Internal_MapWriteFromSheet(search, False, px0, py0, px1, py1);
				}
			}
		}
	}

	return 0;
}

//uint Sheet_Internal_RefreshSheet(UI_Sheet *sheet, int px0, int py0, int px1, int py1);
//�e�O���[�o�����W�ł̃V�[�gvram���t���b�V���B
uint Sheet_Internal_RefreshSheet(UI_Sheet *sheet, int px0, int py0, int px1, int py1)
{
	DATA_Location2D p, r;
	int x, y;

	if(sheet->parent == Null){
		#ifdef CHNOSPROJECT_DEBUG_SHEET
			debug("Sheet_Internal_RefreshSheet:Null parent.\n");
		#endif
		return 1;
	}

	if(sheet->parent->map == Null){
		#ifdef CHNOSPROJECT_DEBUG_SHEET
			debug("Sheet_Internal_RefreshSheet:Null map.\n");
		#endif
		return 2;
	}

	if(!sheet->flags.bit.visible){
		return 0;
	}

	Sheet_Internal_GetLocationP(sheet, &p);
	Sheet_Internal_GetLocationR(sheet, &r);

	if(p.x < px0){
		p.x = px0;
	}
	if(p.y < py0){
		p.y = py0;
	}
	if(r.x > px1){
		r.x = px1;
	}
	if(r.y > py1){
		r.y = py1;
	}

	if(p.x < 0){
		p.x = 0;
	}
	if(p.y < 0){
		p.y = 0;
	}
	if(r.x >= sheet->parent->size.x){
		r.x = sheet->parent->size.x - 1;
	}
	if(r.y >= sheet->parent->size.y){
		r.y = sheet->parent->size.y - 1;
	}

	for(y = p.y; y <= r.y; y++){
		for(x = p.x; x <= r.x; x++){
			if(sheet->parent->map[y * sheet->parent->size.x + x] == (uint)sheet){
				((uchar *)sheet->parent->vram)[y * sheet->parent->size.x + x] = ((uchar *)sheet->vram)[(y - sheet->location.y) * sheet->size.x + (x - sheet->location.x)];
			}
		}
	}

	return 0;
}
