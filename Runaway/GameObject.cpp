#include "stdafx.h"
#include "GameObject.h"
#include "SceneManager.h"

GameObject::GameObject() : useModel(false), myModel(NULL), pos(0.0f, 0.0f, 0.0f), rot(0.0f, 0.0f, 0.0f),scale(1.0f,1.0f,1.0f), isDestroyed(false)
{
	//�𵨾��� ������
	printf("�� ������Ʈ ������\n");
}

GameObject::GameObject(Model* MyModel) : useModel(true), myModel(MyModel), pos(0.0f, 0.0f, 0.0f), rot(0.0f, 0.0f, 0.0f), scale(1.0f, 1.0f, 1.0f), isDestroyed(false)
{
	//�� �ִ� ������
	printf("���ӿ�����Ʈ������\n");
}


GameObject::~GameObject()
{
}

void GameObject::SetPos(float x, float y, float z)
{
	pos.x = x;
	pos.y = y;
	pos.z = z;
}

void GameObject::SetScale(float x, float y, float z)
{
	scale.x = x;
	scale.y = y;
	scale.z = z;
}

void GameObject::SetRot(float x, float y, float z)
{
	rot.x = x;
	rot.y = y;
	rot.z = z;
}

