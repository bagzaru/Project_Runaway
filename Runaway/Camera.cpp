#include "stdafx.h"
#include "Camera.h"
#include "MessageManager.h"

Camera::Camera() : clipCursor(false),isPerspective(false) {
	pos.x = 4.0f;
	pos.y = 3.0f;
	pos.z = -3.0f;
	rot.x = 0.0f;
	rot.y = 0.0f;
	rot.z;
	look.x = -0.4f;
	look.y = -0.3f;
	look.z = 0.3f;
	
}

Camera::~Camera()
{
}

void Camera::Update()
{
	if (RUNAMM->GetMyKeyState('W') >0)
		CalculMoveFB(1);
	if (RUNAMM->GetMyKeyState('S') >0)
		CalculMoveFB(-1);
	if (RUNAMM->GetMyKeyState('A') >0)
		CalculMoveLR(1);
	if (RUNAMM->GetMyKeyState('D') >0)
		CalculMoveLR(-1);
}

void Camera::LateUpdate()
{

}

void Camera::CameraRefresh()
{
	static int count = 0;
	/*if(isPerspective)*/
	Projection = Perspective(45.0f, widthdividedheight, 0.1f, 1000.0f);
	/*else
		Projection = ortho(-10.0f, 10.0f, -10.0f, 10.0f, 0.0f, 100.0f);*/
	View = LookAt(Vec3(pos.x, pos.y, pos.z), Vec3(pos.x+look.x,pos.y+look.y,pos.z+look.z), Vec3(0.0f, 1.0f, 0.0f));
	/*Mat4 Model = Mat4(1.0f);
	RUNAGLM->mvp = (View * Model)*Projection;*/
}

void Camera::FPSCameraRot(int mouseX, int mouseY)
{
	float xp = (float)(mouseX - oldMouseX)*rotSpeed;
	float yp = (float)(mouseY - oldMouseY)*rotSpeed;

	rot.x += xp;
	rot.y += yp;

	look.x = sin(rot.x);
	look.z = -cos(rot.x);

	if (rot.y > piHalf) {
		rot.y -= yp;
	}
	if (rot.y < -piHalf) {
		rot.y -= yp;
	}
	look.y = -tan(rot.y);

	oldMouseX = mouseX;
	oldMouseY = mouseY;
	//printf("pos + look == %f %f %f\n", pos.x + look.x, pos.y + look.y, pos.z + look.z);
}

void Camera::CalculAngleLR(int isRight)
{
	rot.x += rotSpeed*isRight;
	look.x = sin(rot.x);
	look.z = -cos(rot.x);
}

void Camera::CalculAngleUD(int isUp)
{
	rot.y += rotSpeed*isUp;
	//얼마 이상으로 못올라가게
	if (rot.y > piHalf) {
		rot.y -= rotSpeed;
	}
	if (rot.y < -piHalf) {
		rot.y += rotSpeed;
	}
	//printf("%f\n", rot.y);
	look.y = -tan(rot.y);
}

void Camera::CalculMoveFB(int direction)
{
	pos.x = pos.x + direction*(look.x)*movSpeed;
	pos.z = pos.z + direction*(look.z)*movSpeed;
	
	//printf("pos == %f %f %f\n", pos.x, pos.y, pos.z);
}

void Camera::CalculMoveLR(int direction)
{
	pos.x = pos.x + direction*(look.z)*movSpeed;
	pos.z = pos.z + direction*(-look.x)*movSpeed;
	//printf("%f %f %f\n", pos.x, pos.y, pos.z);
}

void Camera::ClipMouseInWindow()
{
	if (!clipCursor)
		return;
	RECT a;
	GetWindowRect(RUNAWM->GetHWND(), &a);
	printf("\n%d %d %d %d\n", a.top, a.bottom, a.left, a.right);
	ClipCursor(&a);
	SetCursor(NULL);
	ShowCursor(showCursor);
}

void Camera::CameraInit()
{
	look.x = sin(rot.x);
	look.z = -cos(rot.x);
	//얼마 이상으로 못올라가게
	if (rot.y > piHalf) {
		rot.y -= rotSpeed;
	}
	if (rot.y < -piHalf) {
		rot.y += rotSpeed;
	}
	CameraRefresh();
}