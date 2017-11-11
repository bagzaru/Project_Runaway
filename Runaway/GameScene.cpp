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
	character->SetScale(0.5f, 0.5f, 0.5f);
	character->pos.y += 6.0f;
	PushBackGameObject(character);

	boardManager = new BoardManager();
	boardManager->p = character;
	boardManager->pos.z = character->pos.z;
	PushBackGameObject(boardManager);
	int tmp = 16;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 40; j++) {
			boardManager->boards[i][j] = new GameObject(bM);
			boardManager->boards[i][j]->SetPos((float)i*tmp, 0.0f, (float)(j-20)*tmp);
			PushBackGameObject(boardManager->boards[i][j]);
		}
	}
	
	

}


GameScene::~GameScene()
{
}
