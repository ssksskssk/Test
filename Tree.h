#pragma once
#include "UnitBase.h"


class Tree :	public UnitBase
{

	void LineRender(D3DXVECTOR3 start, D3DXVECTOR3 dir, int deep);

public:

	HRESULT Render();

};

