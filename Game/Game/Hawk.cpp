#include "stdafx.h"
#include "Hawk.h"


Hawk::Hawk()
{
}


Hawk::~Hawk()
{
	DeleteGO(m_skinModelRender);
}

bool Hawk::Start()
{
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(CmoFilePaths::HAWK);
	//シャドウキャスターとシャドウレシーバーのフラグを立てる。
	m_skinModelRender->SetShadowCasterFlag(true);
	m_skinModelRender->SetShadowReceiverFlag(true);
	
	m_startpos = { -400.0f,350.0f,0.0f };

	m_skinModelRender->SetPosition(m_startpos);
	return true;
}
void Hawk::Update()
{
}