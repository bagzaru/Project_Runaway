#include "stdafx.h"
#include "MainScene.h"


MainScene::MainScene()
{
	mainLogo = new UI("gg.png", 100, 100);
	gameStartButton = new UI("Resource/UI/GameStart.png", 512, 200);
	myCollectionButton = new UI("Resource/UI/Collection.png", 512, 300);
	rankButton = new UI("Resource/UI/Rank.png", 512, 400);
	howToPlayButton = new UI("Resource/UI/h2p.png", 512, 500);
	exitButton = new UI("Resource/UI/gg.png", 512, 600);

	PushBackUI(mainLogo);
	PushBackUI(gameStartButton);
	PushBackUI(myCollectionButton);
	PushBackUI(rankButton);
	PushBackUI(howToPlayButton);
	PushBackUI(exitButton);

}


MainScene::~MainScene()
{
}
