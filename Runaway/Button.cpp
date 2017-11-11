#include "stdafx.h"
#include "Button.h"
#include "Camera.h"
#include "MessageManager.h"
#include "TestScene.h"
#include "SceneManager.h"
#include "GameScene.h"


Button::Button(const char* pngPath, int x, int y, Buttons MyCase) : UI(pngPath,x,y), useButton(true), myCase(MyCase)
{

}


Button::~Button()
{
}

void Button::Update()
{
	if (RUNAMM->mouseLClicked&&CollisionCheck()) {
		switch (myCase) {
		case startb:
			RUNASCENEM->ChangeScene(new GameScene());
			break;
		case collectionb:
			//컬렉션창

			break;
		case rankb:
			//랭킹창

			break;
		case howtoplayb:
			//하우투플레이창

			break;
		case exitb:
			RUNAMM->CloseMyWindow();
			break;
		}
	}
}

bool Button::CollisionCheck()
{
	int my = CM->screenHeight - RUNAMM->mouseY;
	int mx = RUNAMM->mouseX;
	int pl = pos.x;
	int pr = pos.x + textureWidth;
	int pt = pos.y + textureHeight;
	int pb = pos.y;
	if (my >= pb&&my <= pt&&mx >= pl&&mx <= pr) {
		return true;
	}
	return false;
}


