#include "stdafx.h"
#include "UI.h"
#include "PNGLoader.h"


UI::UI(const char * pngPath, int x, int y) : pos((float)x, (float)y)
{
	LoadUI(pngPath);
}

UI::~UI()
{
	glDeleteBuffers(1, &vertexBuffer);
	glDeleteBuffers(1, &uvBuffer);

	glDeleteTextures(1, &textureID);
}


bool UI::LoadUI(const char * path)
{

	textureID = LoadPNG(path);
	if (textureID == -1) {
		return false;
	}
	
	glGenVertexArrays(1, &vertexArrayID);					//n개의 정점(vertex) 배열 객체 이름을 배열로 반환
	glBindVertexArray(vertexArrayID);						//정점(vertex) 배열 객체를 name 배열로 바인딩



	glGenBuffers(1, &vertexBuffer);
	glGenBuffers(1, &uvBuffer);


	//UI 포지션이 수정될 일이 없으므로 값을 처음에 지정해버린다
	Vec2 ul = Vec2(pos.x, pos.y + textureHeight);
	Vec2 ur = Vec2(pos.x + textureWidth, pos.y + textureHeight);
	Vec2 dr = Vec2(pos.x + textureWidth, pos.y);
	Vec2 dl = Vec2(pos.x, pos.y);

	Vec2 udl = Vec2(0.0f,1.0f );
	Vec2 udr = Vec2(1.0f,1.0f );
	Vec2 uur = Vec2(1.0f,0.0f);
	Vec2 uul = Vec2(0.0f,0.0f);

	//삼각형1
	v.push_back(ul);
	v.push_back(dl);
	v.push_back(ur);
	//삼각형2
	v.push_back(dr);
	v.push_back(ur);
	v.push_back(dl);

	u.push_back(uul);
	u.push_back(udl);
	u.push_back(uur);

	u.push_back(udr);
	u.push_back(uur);
	u.push_back(udl);

	glGenBuffers(1, &vertexBuffer);									//버퍼 생성
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);					//그 버퍼를 가져옴
	glBufferData(GL_ARRAY_BUFFER, v.size() * sizeof(Vec2), &v[0].x, GL_STATIC_DRAW);	//버퍼에 데이터 저장
	
	glGenBuffers(1, &uvBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, uvBuffer);
	glBufferData(GL_ARRAY_BUFFER, u.size() * sizeof(Vec2), &u[0].x, GL_STATIC_DRAW);


	return true;
}

void UI::Update()
{
}

void UI::LateUpdate()
{
}

GLuint UI::LoadPNG(const char* path)
{
	int w, h;
	unsigned char* image = LoadPNGinPath(path, &w, &h, 0, 3);//RGB : 3, RGBA : 4
	GLuint textureID = -1;
	if (!image) {
		printf("%s PNG 이미지 로드 실패!\n", path);
		return textureID;
	}
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	free((void*)image);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

	glGenerateMipmap(GL_TEXTURE_2D);
	textureWidth = w;
	textureHeight = h;
	return textureID;
}