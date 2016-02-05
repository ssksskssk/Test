#include "Camera.h"


Camera::Camera()
{
	pos =	D3DXVECTOR3(0, 0, -5);
	target =D3DXVECTOR3(0, 0, 0);
	upVec =	D3DXVECTOR3(0, 1, 0);

	angle = 60;
	aspect = (float)WINDOW_WIDTH / WINDOW_HEIGHT;
	nearClip = 0.1f;
	farClip = 1000.0f;
}


Camera::~Camera()
{
}

HRESULT Camera::SetView()
{
	D3DXMatrixLookAtLH(&view, &pos, &target, &upVec);

	if (FAILED(g_pDevice->SetTransform(D3DTS_VIEW, &view)))
	{
		MessageBox(0, "�r���[�s��̐ݒ�Ɏ��s���܂���", "Camera", MB_OK);
		return E_FAIL;
	}

	return S_OK;
}

HRESULT Camera::SetProjection()
{
	D3DXMatrixPerspectiveFovLH(&proj, 
		D3DXToRadian(angle), aspect, 
		nearClip, farClip);

	if (FAILED(g_pDevice->SetTransform(D3DTS_PROJECTION, &proj)))
	{
		MessageBox(0, "�ˉe�s��̐ݒ�Ɏ��s���܂���", "Camera", MB_OK);
		return E_FAIL;
	}

	return S_OK;
}

HRESULT Camera::Update()
{
	if (FAILED(SetView()))
	{
		return E_FAIL;
	}

	if (FAILED(SetProjection()))
	{
		return E_FAIL;
	}

	return S_OK;
}

D3DXMATRIX Camera::Billboard()
{
	D3DXMATRIX matrix;

	//�œ_����J�����ւ̃x�N�g�������߂�
	D3DXMatrixLookAtLH(&matrix, &D3DXVECTOR3(0, 0, 0), &(target - pos), &D3DXVECTOR3(0, 1, 0));

	//�t�s������߂�֐�
	D3DXMatrixInverse(&matrix, NULL, &matrix);
	return matrix;
}