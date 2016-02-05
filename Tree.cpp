#include "Tree.h"
#include "Line.h"


HRESULT Tree::Render()
{

	LineRender(D3DXVECTOR3(0, -2, 0), D3DXVECTOR3(0, 1, 0), 0);

	return S_OK;
}


void Tree::LineRender(D3DXVECTOR3 start, D3DXVECTOR3 dir, int deep)
{
	//aaaaa
	//biiasiduausd
	Line line;
	line.Draw(start, start + dir);

}