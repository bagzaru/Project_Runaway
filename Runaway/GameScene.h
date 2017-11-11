#pragma once
#include "Scene.h"
#include "Player.h"
#include "EmptyObject.h"
#include "BoardManager.h"
class GameScene :
	public Scene
{
public:
	Model* bM;
	Model* cM;
public:
	
	Player* character;
	BoardManager* boardManager;
	
public:
	GameScene();
	~GameScene();
};

