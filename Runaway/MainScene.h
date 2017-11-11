#pragma once
#include "Scene.h"
#include "Button.h"
#include "EmptyObject.h"

class MainScene :
	public Scene
{
	Button* mainLogo;
	Button* gameStartButton;
	Button* myCollectionButton;
	Button* rankButton;
	Button* howToPlayButton;
	Button* exitButton;
public:
	MainScene();
	~MainScene();
};

