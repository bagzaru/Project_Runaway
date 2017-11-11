#pragma once
#include "Scene.h"
#include "Button.h"
#include "EmptyObject.h"
#include "StarManager.h"

class MainScene :
	public Scene
{
	Button* mainLogo;
	Button* gameStartButton;
	Button* myCollectionButton;
	Button* rankButton;
	Button* howToPlayButton;
	Button* exitButton;


	StarManager* bgStars;
	StarManager* bgStars2;
	Model* whiteStar;
public:
	MainScene();
	~MainScene();
};

