#pragma once
#include "Scene.h"
#include "Player.h"
#include "EmptyObject.h"
#include "BoardManager.h"
#include "StarManager.h"
class GameScene :
	public Scene
{
public:
	Model* bM;
	Model* cM;
	Model* whiteStar;
public:
	StarManager* bgStars;
	Player* character;
	BoardManager* boardManager;
	
public:
	GameScene();
	~GameScene();
};

