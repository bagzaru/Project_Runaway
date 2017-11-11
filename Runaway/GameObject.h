#pragma once
#include "stdafx.h"
#include "GraphicManager.h"
class GameObject
{
private:
	bool isDestroyed;
	bool isEnabled;
public:
	Vec3 pos;
	Vec3 rot;
	Vec3 scale;
	Model* myModel;
	bool useModel;
	
	GameObject();
	GameObject(Model* MyModel);
	 ~GameObject();
	void SetPos(float x, float y, float z);
	void SetScale(float x, float y, float z);
	void SetRot(float x, float y, float z);
	void MawaruX();
	void MawaruY();
	void MawaruZ();
	void CheckBase();
	virtual void Update();
	virtual void LateUpdate() {};
	virtual void OnCollision(GameObject* ano) {};
};

