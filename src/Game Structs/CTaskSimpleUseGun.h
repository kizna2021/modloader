// Generated by IDAStruct_To_CHeader.py
#pragma once
#include <windows.h>
#include "CTask.h"
#include "RwV3D.h"


#pragma pack(push, 1)
struct CTaskSimpleUseGun	// sizeof = 0x3C
{
	CTask __parent;
	BYTE field_8;
	BYTE field_9;
	BYTE field_A;
	BYTE field_B;
	BYTE field_C;
	BYTE field_D;
	BYTE field_E;
	BYTE field_F;
	BYTE field_10;
	BYTE _undefined_0;
	BYTE _undefined_1;
	BYTE _undefined_2;
	DWORD field_14;
	DWORD field_18;
	DWORD m_pEntity;
	RwV3D field_20;
	DWORD field_2C;
	DWORD field_30;
	WORD field_34;
	WORD field_36;
	BYTE field_38;
	BYTE field_39;
	BYTE field_3A;
	BYTE field_3B;
};
#pragma pack(pop)

static_assert(sizeof(CTaskSimpleUseGun) == 0x3C, "Incorrect struct size: CTaskSimpleUseGun");