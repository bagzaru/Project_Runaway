#include "stdafx.h"
#include "Runaway.h"
#include "TestScene.h"
int main() {
	//������ Ǯ��ũ������ �����մϴ�.
	//�ڵ����� �ػ󵵸� �����մϴ�.
	if (RUNAWM->WindowInit(FALSE, L"Runaway", 800, 600, 32, true, false)) {
		RUNAGLM->PrepareRender();
		RUNASCENEM->NewScene(new TestScene());
		return RUNAWM->MainLoop();
	}
	else
		return 0;
	RUNAGLM->DestroyScene();
}
