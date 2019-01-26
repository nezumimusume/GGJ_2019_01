#pragma once
#include "tkEngine/physics/tkPhysicsGhostObject.h"
class GameCamera;
class Bird : public IGameObject
{
public:
	Bird();
	~Bird();
	bool Start() override;
	void Update() override;
	void Turn();
	void SetAnimation();
	void AnimationController();
	void Move();
	void Animation();
	//�v���C���[�̍��W��ݒ�
	void SetPosition(const CVector3& pos)
	{
		m_position = pos;
	}
	//�v���C���[�̍��W���擾
	CVector3 GetPosition() const
	{
		return m_position;
	}
	//�v���C���[���~������
	void Stop()
	{
		m_stop = true;
	}
	//�v���C���[�̐^�E�̃x�N�g�����擾
	CVector3 GetRight() const
	{
		return m_birdright;
	}
	//�v���C���[�̌���̃x�N�g�����擾
	CVector3 GetBack() const
	{
		return m_birdback;
	}
private:
	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	CVector3 m_position = { 00.0f,100.0f,0.0f };
	CVector3 m_movespeed = { 0.0f,0.0f,0.0f };
	CQuaternion m_rotation = CQuaternion::Identity;
	CQuaternion m_rotation2 = CQuaternion::Identity;
	CVector3 m_scale = CVector3::One;
	//�v���C���[�̌����ƕ��s�ȃx�N�g��
	CVector3 m_player_heikou;
	CVector3 m_birdright;
	CVector3 m_birdback;
	CCharacterController m_charaCon;
	//�A�j���[�V����
	enum EnAnimationClip {
		enAnimationClip_idle,
		enAnimationClip_walk,
		enAnimationClip_damage,
		enAnimationClip_KneelDown,
		enAnimationClip_num,
	};
	//�A�j���[�V��������
	enum EnState {
		enState_Idle,
		enState_Walk,
		enState_GameOver,
		enState_Damage,
		enState_Eat,
	};
	CAnimationClip m_animClip[enAnimationClip_num];
	EnState m_state = enState_Idle;
	float m_degree = 180.0f;
	float m_radian = 0;
	bool m_stop = false;
	float m_multiply = 40.0f;
	float m_damagetimer = 0.0f;
	float m_blinktimer = 0.0f;
	GameCamera* m_gamecamera = nullptr;

};
