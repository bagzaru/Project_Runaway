#include "stdafx.h"
#include "EmptyObject.h"
#include "TestScene2.h"

//�� ������Ʈ�� ����� ��� useModel�� ��Ȱ��ȭ �ؾ��մϴ�.

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
		printf("�� ����!!\n");
		TestScene2* a = new TestScene2();
		RUNASCENEM->ChangeScene(a);
	}

}