#include "stdafx.h"
#include "EmptyObject.h"
#include "TestScene2.h"

//빈 오브젝트를 사용할 경우 useModel을 비활성화 해야합니다.

EmptyObject::EmptyObject()
{
	useModel = false;
}


EmptyObject::~EmptyObject()
{
}

void EmptyObject::Update() {
	++k;
	if (k%1000==0)
		printf("%d\n",k);
	if (k > 100000)
	{
		printf("씬 변경!!\n");
		TestScene2* a = new TestScene2();
		RUNASCENEM->ChangeScene(a);
	}

}