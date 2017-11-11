#include "stdafx.h"
#include "BoardManager.h"


BoardManager::BoardManager()
{
	currentLine = 0;
}


BoardManager::~BoardManager()
{
}

void BoardManager::Update()
{
	if ((int)p->pos.z > (int)(pos.z+16.0f)) {
		pos.z += 16.0f;
		for (int i = 0; i < 6; ++i) {
			boards[i][currentLine]->pos.z += 40.0f*16.0f;
		}
		++currentLine;
		if (currentLine >= 40)
			currentLine = 0;
	}
}
