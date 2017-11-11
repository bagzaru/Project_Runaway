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


	//�÷��̾� ����
	character = new Player(cM);
	character->SetScale(0.5f, 0.5f, 0.5f);
	character->pos.y += 6.0f;
	//�ݶ��̴� ���� ���ֱ�
	character->myCollider = new Collider(character, 8.0f);
	PushBackGameObject(character);
	PushBackCollider(character->myCollider);


	//�ٴ� ����
	boardManager = new BoardManager();
	boardManager->p = character;
	boardManager->pos.z = character->pos.z;
	PushBackGameObject(boardManager);
	int tmp = 16;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 40; j++) {
			boardManager->boards[i][j] = new GameObject(bM);
			boardManager->boards[i][j]->SetPos((float)i*tmp, 0.0f, (float)(j - 20)*tmp);
			PushBackGameObject(boardManager->boards[i][j]);
		}
	}


	//���ϴ� ��
	/*whiteStar = new Model("Resource/Model/WhiteCube/Star.obj", "Resource/Model/WhiteCube/Star.png");
	bgStars = new StarManager();
	bgStars->p = character;
	PushBackGameObject(bgStars);
	for (int j = 0; j < bgStars->starcount; j++) {
		bgStars->stars[j] = new GameObject(whiteStar);
		bgStars->SetRandomPos(j);
		PushBackGameObject(bgStars->stars[j]);
	}*/


	//�浹 �׽�Ʈ��
	/*GameObject* a;
	a = new GameObject(bM);
	a->pos.x = 0.0f;
	a->pos.y = 5.0f;
	a->pos.z = 10.0f;
	a->SetScale(0.25f, 0.25f, 0.25f);
	Collider* ac;
	ac = new Collider(a,4.0f);
	PushBackCollider(ac);
	PushBackGameObject(a);*/

	
}


GameScene::~GameScene()
{
}
