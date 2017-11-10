#include "stdafx.h"
#include "Scene.h"
#include "SceneManager.h"


Scene::Scene()
{
}


Scene::~Scene()
{
	for (auto &i : gameObjectList) 
		delete i;	
	for (auto &i : modelList)
		delete i;
	for (auto &i : uiList)
		delete i;
}

void Scene::Update()
{
	for (auto &i : gameObjectList)
		i->Update();
	for (auto &i : uiList)
		i->Update();
}

void Scene::LateUpdate() {
	for (auto &i : gameObjectList)
		i->LateUpdate();
	for (auto &i : uiList)
		i->LateUpdate();
}

void Scene::PushBackGameObject(GameObject* g)
{
	gameObjectList.push_back(g);
}

void Scene::PushBackModel(Model* m)
{
	modelList.push_back(m);
}

void Scene::PushBackUI(UI * u)
{
	uiList.push_back(u);
}

