#include "stdafx.h"
#include "GameScene.h"
#include "Player.h"


GameScene::GameScene()
{
	sceneNumber = NGameScene;
	bM = new Model("Resource/Model/Floor/Floor.obj", "Resource/Model/Floor/Floor.png");
	cM = new Model("Resource/Model/Character/Character.obj", "Resource/Model/Character/Character.png");
	PushBackModel(bM);
	PushBackModel(cM);

	character = new Player(cM);
	PushBackGameObject(character);
	int tmp = 16;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 100; j++) {
			boards[i][j] = new GameObject(bM);
			boards[i][j]->SetPos((float)i*tmp, 0.0f, (float)j*tmp);
			PushBackGameObject(boards[i][j]);
		}
	}

}


GameScene::~GameScene()
{
}
