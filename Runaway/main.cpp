#include "stdafx.h"
#include "Runaway.h"
#include "TestScene.h"
#include "TestScene2.h"
#include "MainScene.h"
int main() {
	//������ Ǯ��ũ������ �����մϴ�.
	//�ڵ����� �ػ󵵸� �����մϴ�.
	if (RUNAWM->WindowInit(FALSE, L"Runaway", 800, 600, 32, true, false)) {
		RUNAGLM->PrepareRender();
		RUNASCENEM->NewScene(new MainScene());
		return RUNAWM->MainLoop();
	}
	else
		return 0;
	RUNAGLM->DestroyScene();
}
