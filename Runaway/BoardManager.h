#pragma once
#include "GameObject.h"
#include "Player.h"
class BoardManager : public GameObject
{
public:
	BoardManager();
	~BoardManager();
	GameObject* boards[6][40];
	void Update();
	void CreateLine();

	int currentLine;
	Player* p;
};

