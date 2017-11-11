#pragma once
#include "Scene.h"
#include "Player.h"
class GameScene :
	public Scene
{
public:
	Model* bM;
	Model* cM;
public:
	GameObject* boards[6][100];
	Player* character;
	
public:
	GameScene();
	~GameScene();
};

