#pragma once
#include "GameObject.h"
class Player :
	public GameObject
{
public:
	Player(Model* MyModel);
	~Player();

	void Update();

	float speed = 30.0f;
	float lrspeed = 20.0f;
	int hp = 10;
	int maxhp = 10;
	int mp = 10;
	float zDistance = 50.0f;

	void MoveFB(int wtg);
	void MoveLR(int wtg);

	//콜라이더 사용시 선언
	Collider* myCollider;
	void OnCollision(GameObject* ano);
};

