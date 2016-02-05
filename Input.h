#pragma once
#define DIRECTINPUT_VERSION 0x800 //DirectInput �̃o�[�W�����ݒ�

#include <dinput.h>
#include <XInput.h>

#pragma comment(lib,"dxguid.lib")
#pragma comment(lib,"dinput8.lib")
#pragma comment(lib,"Xinput.lib")

#define SAFE_RELEASE(p) { if(p != NULL) { (p)->Release(); (p) = NULL; } }

class Input
{
	LPDIRECTINPUT8        pDinput; //DirectInput�I�u�W�F�N�g
	LPDIRECTINPUTDEVICE8  pKeyDevice;  //�f�o�C�X�I�u�W�F�N�g�i�L�[�{�[�h�j

	BYTE  keyState[256];    //�e�L�[�̏��
	BYTE  prevKeyState[256];//�O��̃L�[�̏��

	XINPUT_STATE    controllerState[4];   //�R���g���[���[�̏��
	XINPUT_STATE    prevControllerState[4];   //�O��̃R���g���[���[�̏��

public:
	Input();
	~Input();
	HRESULT Init(HWND hWnd);//DirectInput�̏���
	HRESULT Update();       //�e���̓f�o�C�X�̏�Ԃ��擾

	BOOL  IsKeyPush(DWORD keyCode); //�C�ӂ̃L�[��������Ă��邩�`�F�b�N
	BOOL  IsKeyTap(DWORD keyCode); //�C�ӂ̃L�[�������ꂽ�u�Ԃ��`�F�b�N
	BOOL  IsKeyRelease(DWORD keyCode);


	BOOL  IsPadButtonPush(DWORD buttonCode, int ID = 0);    //�R���g���[���[�̃{�^����������Ă��邩
	BOOL  IsPadButtonTap(DWORD buttonCode, int ID = 0);
	BOOL  IsPadButtonRelease(DWORD buttonCode, int ID = 0);

	float GetPadLStickX(int ID = 0);			//���X�e�B�b�N�̍��E�̌X��
	float GetPadLStickY(int ID = 0);			//���X�e�B�b�N�̏㉺�̌X��
	float GetPadRStickX(int ID = 0);			//�E�X�e�B�b�N�̍��E�̌X��
	float GetPadRStickY(int ID = 0);			//�E�X�e�B�b�N�̏㉺�̌X��
	float GetPadLTrigger(int ID = 0);			//���g���K�[�̉�������
	float GetPadRTrigger(int ID = 0);			//�E�g���K�[�̉�������

	void  Vibration(float leftSpeed, float rightSpeed, int ID = 0);                   //�U���G�t�F�N�g
};

