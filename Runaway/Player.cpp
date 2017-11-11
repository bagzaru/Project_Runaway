#include "stdafx.h"
#include "Player.h"


Player::Player(Model* MyModel) : GameObject(MyModel)
{
	CM->look.x = 0.0f;
	CM->look.y = -0.5f;
	CM->look.z = 1.0f;
	CM->rot.y = 0.3f;
}


Player::~Player()
{
}

void Player::Update()
{

	if (RUNAMM->GetMyKeyState('W') >0)
		MoveFB(1);
	if (RUNAMM->GetMyKeyState('S') >0)
		MoveFB(-1);
	if (RUNAMM->GetMyKeyState('A') >0)
		MoveLR(1);
	if (RUNAMM->GetMyKeyState('D') >0)
		MoveLR(-1);

	
	CM->pos.z = pos.z - zDistance;
	CM->pos.x = pos.x;
}

void Player::MoveFB(int wtg)
{
	pos.z += speed*wtg*RUNAMM->deltaTime;
	
}

void Player::MoveLR(int wtg)
{
	pos.x += lrspeed*wtg*RUNAMM->deltaTime;
}

