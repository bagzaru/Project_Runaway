#pragma once
#include "GameObject.h"
class BoardManger : public GameObject
{
	Model* board;
	struct BoardSet {
		GameObject b[6];
	};
public:
	BoardManger();
	~BoardManger();
	void CreateLine();

};

