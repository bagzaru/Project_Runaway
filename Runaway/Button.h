#pragma once
#include "UI.h"
class Button :
	public UI
{
public:
	enum Buttons {
		noneb,
		startb,
		collectionb,
		rankb,
		howtoplayb,
		exitb
	};
	Buttons myCase;
	bool useButton;
public:
	Button(const char* pngPath, int x, int y, Buttons MyCase);
	~Button();
	void Update();
	bool CollisionCheck();
};

