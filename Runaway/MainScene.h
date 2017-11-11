#pragma once
#include "Scene.h"
#include "UI.h"
#include "EmptyObject.h"
class MainScene :
	public Scene
{

	Model* testModel1;
	EmptyObject* et;
	UI* mainLogo;
	UI* gameStartButton;
	UI* myCollectionButton;
	UI* rankButton;
	UI* howToPlayButton;
	UI* exitButton;
public:
	MainScene();
	~MainScene();
};

