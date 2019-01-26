#pragma once
/// <summary>
/// ��
/// </summary>
class Hawk : public IGameObject
{
public:
	Hawk();
	~Hawk();
	bool Start() override;
	void Update() override;
	prefab::CSkinModelRender* m_skinModelRender = nullptr;
private:
	CVector3 m_startpos = CVector3::Zero;
};

