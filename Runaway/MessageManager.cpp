#include "stdafx.h"
#include "MessageManager.h"
#include "WindowManager.h"
#include "GraphicManager.h"
#include "Camera.h"

MessageManager::MessageMap MessageManager::messageMap[] = {
	//�̰��� �ݹ��Լ��� �߰�
	//{�޽�����, &�Լ���}
	{WM_CREATE, &OnCreate},
	{WM_SIZE, &OnSize },
	{WM_CLOSE, &OnClose },
	{WM_KEYDOWN, &OnKeyDown },
	{WM_KEYUP, &OnKeyUp },
	{WM_MOUSEMOVE, &OnMouseMove },
	{WM_LBUTTONDOWN, &OnLButtonDown },
	{WM_LBUTTONUP, &OnLButtonUp },
	{WM_RBUTTONDOWN, &OnRButtonDown },
	{WM_RBUTTONUP, &OnRButtonUp },
	{WM_CHAR, &OnChar },
	{WM_COMMAND, &OnCommand },
	{WM_SYSCOMMAND, &OnSysCommand },
	{WM_MOUSELEAVE, &OnMouseLeave},
	{WM_SETFOCUS,&OnSetFocus},
	{0,NULL}
};

void MessageManager::UpdateKeyState()
{
	for (int i = 0; i < 256; i++)
	{
		lkey[i] = rkey[i];
		rkey[i] = GetAsyncKeyState(i) & 0x8000;
	}
	
}

int MessageManager::GetMyKeyState(int vk)
{
	if (lkey[vk] && rkey[vk]) return 2; //�Ʊ �������� ���ݵ� ���������� ��
	if (!lkey[vk] && rkey[vk]) return 1; //�Ʊ�� �ƴ����� ������ ����������
	if (lkey[vk] && !rkey[vk]) return -1; //������ ������
	return 0;
}

int MessageManager::GetMyMouseState(int mouseLR)
{
	return 0;
}

void MessageManager::UpdateFPS()
{

	static DWORD frameCount = 0;            //������ ī��Ʈ��
	static float timeElapsed = 0.0f;            //�帥 �ð�
	static DWORD lastTime = timeGetTime();   //������ �ð�(temp����)

	DWORD curTime = timeGetTime();      //���� �ð�
	deltaTime = (curTime - lastTime)*0.001f;       

	timeElapsed += deltaTime;

	frameCount++;

	if (timeElapsed >= 1.0f)         //�帥�ð��� 1���̻��̸� ���� �ϰ������ ó��
	{
		float fps = (float)frameCount / timeElapsed;
		printf("%f\n", fps);     //FPS��� �ϴ� �ҽ�

		frameCount = 0;
		timeElapsed = 0.0f;
	}


	lastTime = curTime;
}

void MessageManager::CloseMyWindow()
{
	RUNAGLM->DestroyScene();
	SendMessage(RUNAWM->mHWnd, WM_CLOSE, 0, 0);
}

LRESULT MessageManager::WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	int i = 0;
	while (messageMap[i].iMsg != 0)
	{
		//�޽����� ���� ���� �� ���ٸ� ����
		if (iMessage == messageMap[i].iMsg)
		{
			(RUNAMM->*(messageMap[i].fp))(wParam, lParam);
		}
		++i;
	}
	return DefWindowProc(hWnd, iMessage, wParam, lParam);
}

void MessageManager::OnSize(WPARAM wParam, LPARAM lParam)
{
	//����� ����Ǿ��� ������ ���
	GLsizei width = LOWORD(lParam);
	GLsizei height = HIWORD(lParam);
	CM->screenHeight = height;
	CM->screenWidth = width;
	CM->widthdividedheight =(float)width/height;
	printf("%d, %d ȭ��ũ�� �����\n", height, width);
	//RUNAGLM->ViewInit(width, height);	//3.0 ����
	RUNAGLM->ReshapeView(width, height);
}

void MessageManager::OnClose(WPARAM wParam, LPARAM lParam)
{
	RUNAWM->DestroyGLWindow();
	PostQuitMessage(0);
}

void MessageManager::OnKeyDown(WPARAM wParam, LPARAM lParam)
{
	//getasynckeystate�� ��ü

	if (wParam == VK_ESCAPE)
	{
		CloseMyWindow();
	}
}

void MessageManager::OnSysCommand(WPARAM wParam, LPARAM lParam)
{
	switch (wParam)				// Check System Calls
	{
	case SC_SCREENSAVE:		// Screensaver Trying To Start?
	case SC_MONITORPOWER:	// Monitor Trying To Enter Powersave?
		return;				// Prevent From Happening
	}
}

void MessageManager::OnMouseMove(WPARAM wParam, LPARAM lParam)
{
	mouseX = GET_X_LPARAM(lParam);
	mouseY = GET_Y_LPARAM(lParam);
	if (RUNASCENEM->currentScene->sceneNumber == Scene::NMainScene) {

	}
	if (RUNASCENEM->currentScene->sceneNumber == Scene::NGameScene) {
		if (mouseX < CM->movePoint) {
			//(800x600)����
			//100���� ������ : 700-(movePoint-mouseX)�� �̵�
			//���� ��ǥ���� 800-movePoint*2 (=600)��ŭ ������
			mouseX = CM->screenWidth - CM->movePoint - (CM->movePoint - mouseX);
			CM->oldMouseX += CM->screenWidth - CM->movePoint * 2;
			SetCursorPos(mouseX, mouseY);
		}
		else if (mouseX > CM->screenWidth - CM->movePoint) {
			//700���� ũ�� : movePoint + (mouseX-width-movePoint) (=100)���� �̵�
			//���� ��ǥ���� 800-movePoint*2 (=600)��ŭ ����
			mouseX -= CM->screenWidth - CM->movePoint * 2;
			CM->oldMouseX -= CM->screenWidth - CM->movePoint * 2;
			//SetCursorPos(mouseX, mouseY);

			//â����� ���� ������, �Ʒ��� �Ѿ �� ���콺 ��ġ -4~10���� �������� ���� �߻�
			//�׵θ� ������ �� ����.. 2017.10.24
			if (RUNAWM->mFullScreen)
				SetCursorPos(mouseX, mouseY);
			else
				SetCursorPos(mouseX + 10, mouseY);
		}

		if (mouseY < CM->movePoint) {
			mouseY = CM->screenHeight - CM->movePoint - (CM->movePoint - mouseY);
			CM->oldMouseY += CM->screenHeight - CM->movePoint * 2;
			SetCursorPos(mouseX, mouseY);
		}
		else if (mouseY > CM->screenHeight - CM->movePoint) {
			mouseY = CM->movePoint + (mouseY - CM->screenHeight + CM->movePoint);
			CM->oldMouseY -= CM->screenHeight - CM->movePoint * 2;

			//â����� ���� ������, �Ʒ��� �Ѿ �� ���콺 ��ġ -4~10���� �������� ���� �߻�
			//�׵θ� ������ �� ����... 2017.10.24
			if (RUNAWM->mFullScreen)
				SetCursorPos(mouseX, mouseY);
			else
				SetCursorPos(mouseX, mouseY + 20);
		}


		CM->FPSCameraRot(mouseX, mouseY);
	}
}

void MessageManager::OnMouseLeave(WPARAM wParam, LPARAM lParam)
{

}

void MessageManager::OnLButtonDown(WPARAM wParam, LPARAM lParam)
{
	mouseLClicked = true;
}

void MessageManager::OnLButtonUp(WPARAM wParam, LPARAM lParam)
{
	mouseLClicked = false;
}

void MessageManager::OnRButtonDown(WPARAM wParam, LPARAM lParam)
{
	mouseRClicked = true;
}

void MessageManager::OnRButtonUp(WPARAM wParam, LPARAM lParam)
{
	mouseRClicked = false;
}

void MessageManager::OnSetFocus(WPARAM wParam, LPARAM lParam)
{
	CM->ClipMouseInWindow();
}
