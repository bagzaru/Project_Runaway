#include "stdafx.h"
#include "Collider.h"

Collider::Collider(GameObject* myGO, float length) : myGameObject(myGO), dist(0.0f, 0.0f)
{
	lt.x = -length*0.5f;
	lt.y = -length*0.5f;
	rb.x = length*0.5f;
	rb.y = length*0.5f;
}

Collider::Collider(GameObject * myGO, float length, float distX, float distZ) : myGameObject(myGO), dist(distX, distZ)
{
	lt.x = -length*0.5f;
	lt.y = -length*0.5f;
	rb.x = length*0.5f;
	rb.y = length*0.5f;
}

Collider::~Collider()
{
}

bool Collider::CheckCollision(Collider* ano)
{
	if (
		myGameObject->pos.x + dist.x + lt.x<ano->myGameObject->pos.x + ano->dist.x + ano->rb.x&&
		myGameObject->pos.z + dist.y + lt.y<ano->myGameObject->pos.z + ano->dist.y + ano->rb.y&&
		myGameObject->pos.x + dist.x + rb.x>ano->myGameObject->pos.x + ano->dist.x + ano->lt.x&&
		myGameObject->pos.z + dist.y + rb.y>ano->myGameObject->pos.z + ano->dist.y+ ano->lt.y)
	{
		return true;
	}

	return false;
}
