#include "stdafx.h"
#include "MainScene.h"


MainScene::MainScene()
{
	sceneNumber = NMainScene;
	//mainLogo = new UI("gg.png", 100, 100);
	gameStartButton = new Button("Resource/UI/GameStart.png", CM->screenWidth / 2 - 100, 450,Button::startb);
	myCollectionButton = new Button("Resource/UI/Collection.png", CM->screenWidth / 2 - 100, 340, Button::collectionb);
	rankButton = new Button("Resource/UI/Rank.png", CM->screenWidth / 2 - 100, 230, Button::rankb);
	howToPlayButton = new Button("Resource/UI/h2p.png", CM->screenWidth / 2 - 100, 120, Button::howtoplayb);
	exitButton = new Button("Resource/UI/exit.png", CM->screenWidth / 2 - 100, 10, Button::exitb);

	//PushBackUI(mainLogo);
	PushBackUI(gameStartButton);
	PushBackUI(myCollectionButton);
	PushBackUI(rankButton);
	PushBackUI(howToPlayButton);
	PushBackUI(exitButton);

	whiteStar = new Model("Resource/Model/WhiteCube/Star.obj", "Resource/Model/WhiteCube/Star.png");
	bgStars = new StarManager();
	bgStars->p = NULL;
	PushBackGameObject(bgStars);
	for (int j = 0; j < bgStars->starcount; j++) {
		bgStars->stars[j] = new GameObject(whiteStar);
		bgStars->SetRandomPos(j);
		PushBackGameObject(bgStars->stars[j]);
	}
	bgStars2 = new StarManager();
	bgStars2->p = NULL;
	PushBackGameObject(bgStars2);
	for (int j = 0; j < bgStars2->starcount; j++) {
		bgStars2->stars[j] = new GameObject(whiteStar);
		bgStars2->SetRandomPos(j);
		PushBackGameObject(bgStars2->stars[j]);
	}

}


MainScene::~MainScene()
{

}
