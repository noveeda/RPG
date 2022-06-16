#pragma once
enum MonsterClass {
	NO_CLASS = 0,	// Ŭ���� ����
	COMMON,			// �Ϲ� ��
	RARE,			// ���� ��
	UNIQUE,			// ��� ��
	BOSS			// ���� ��
}; // ���� ��͵�

enum MonsterType {
	NO_TYPE = 0,	// Ÿ�� ����
	SLIME,			// ������
	GOBLIN,			// ���
	KOBOLD,			// �ں�Ʈ
	WOLF,			// ����
	GOLEM			// ��
}; // ���� ����

enum StatusType {
	HP,
	ATK,
	DEF,
	EXP,
	GOLD
};

class Monster
{
public:
	Monster();
	~Monster();

	void	SetMonster(MonsterClass m_class, MonsterType m_type);

	const char*	GetMonsterType();
	float	GetMaxHP();
	float	GetHP();
	float	Attack();
	bool	IsDeath();
	void	TakeDamage(int _damage);
	void	DropTreasure(float* target_exp, float* target_gold);

	void	ShowStatus();

private:
	MonsterClass m_class;
	MonsterType  m_type;

	const char* mob_name;
	float max_hp;
	float hp;
	float atk;
	float def;
	float gold;
	float exp;
};

