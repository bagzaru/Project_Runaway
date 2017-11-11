#pragma once
#include "stdafx.h"
#include "RUNAMath.h"
#include "GameObject.h"

class GameObject;

class Collider
{
public:
	Vec2 lt;
	Vec2 rb;

	Vec2 dist;
	bool checked=false;
	GameObject* myGameObject;
public:
	Collider(GameObject* myGO, float length);
	Collider(GameObject* myGO, float length, float distX, float distZ);	//�߾����κ��� �ݶ��̴� �Ÿ�
	~Collider();
	bool CheckCollision(Collider* ano);
};

