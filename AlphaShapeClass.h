/*
	RadSites
*/

#pragma once

#include <FileSystem.h>
#include <AbstractClass.h>

class ObjectClass;

class NOVTABLE AlphaShapeClass : public AbstractClass
{
public:
	static const AbstractType AbsID = AbstractType::AlphaShape;

	//Static
	static DynamicVectorClass<AlphaShapeClass*>* Array;

	//IPersist
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT __stdcall Load(IStream* pStm) R0;
	virtual HRESULT __stdcall Save(IStream* pStm,BOOL fClearDirty) R0;

	//Destructor
	virtual ~AlphaShapeClass() RX;

	//AbstractClass
	virtual AbstractType WhatAmI() const RT(AbstractType);
	virtual int	Size() const R0;

	//Constructor
	AlphaShapeClass(ObjectClass* pObj,int nX,int nY) : AbstractClass(false)
		{ JMP_THIS(0x420960); }

protected:
	AlphaShapeClass() : AbstractClass(false) { };

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	ObjectClass* AttachedTo;	//To which object is this AlphaShape attached?
	RectangleStruct Rect;
	SHPStruct* AlphaImage;
	bool IsObjectGone;	//Set if AttachedTo is NULL.
};
