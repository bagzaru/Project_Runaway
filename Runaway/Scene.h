#pragma once
#include "GraphicManager.h"
#include "Model.h"
#include "UI.h"

//Scene : ���
//����� ��� ���� �����ϴ� ��ü

class GameObject;

class Scene
{
public : 
	list<GameObject*> gameObjectList;
	list<Model*> modelList;
	list<UI*> uiList;
public : 
	int sceneNumber;

public:
	Scene();
	virtual ~Scene();
	void Update();
	void LateUpdate();
	void PushBackGameObject(GameObject* g);
	void PushBackModel(Model* m);
	void PushBackUI(UI* u);
};

