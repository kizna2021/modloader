// Generated by IDAStruct_To_CHeader.py
#pragma once
#include <windows.h>
#include "CBaseModelInfo.h"
#include "CModelTimeinfo.h"


#pragma pack(push, 1)
struct CModelTobj	// sizeof = 0x24
{
	CBaseModelInfo __parent;
	CModelTimeinfo timeinfo;
};
#pragma pack(pop)

static_assert(sizeof(CModelTobj) == 0x24, "Incorrect struct size: CModelTobj");