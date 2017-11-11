#pragma once
#include "stdafx.h"
#include "RUNAMath.h"
class UI
{
public: 
	Vec2 pos;
	
public:
	GLuint vertexArrayID;
	GLuint textureID;
	GLuint vertexBuffer;
	GLuint uvBuffer;

	vector<Vec2> v;	//���ؽ� �迭
	vector<Vec2> u;	//UV �迭

public:
	int textureWidth;
	int textureHeight;
public:
	UI(const char * pngPath, int x, int y);
	virtual ~UI();
	bool LoadUI(const char* path);
	virtual void Update();
	virtual void LateUpdate();
	
	GLuint LoadPNG(const char* path);
};

