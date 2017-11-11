#pragma once
#include "GraphicManager.h"
#include "Model.h"
#include "UI.h"
#include "SceneManager.h"

//Scene : ���
//����� ��� ���� �����ϴ� ��ü

class GameObject;

class Scene
{
public:
	enum SceneNumber {
		NMainScene,
		NGameScene
	};
public:
	SceneNumber sceneNumber;
public : 
	list<GameObject*> gameObjectList;
	list<Model*> modelList;
	list<UI*> uiList;

public:
	Scene();
	virtual ~Scene();
	void Update();
	void LateUpdate();
	void PushBackGameObject(GameObject* g);
	void PushBackModel(Model* m);
	void PushBackUI(UI* u);
};

