#pragma once
enum MonsterClass {
	NO_CLASS = 0,	// 클래스 없음
	COMMON,			// 일반 몹
	RARE,			// 레어 몹
	UNIQUE,			// 희귀 몹
	BOSS			// 보스 몹
}; // 몬스터 등급

enum MonsterType {
	NO_TYPE = 0,	// 타입 없음
	SLIME,			// 슬라임
	GOBLIN,			// 고블린
	KOBOLD,			// 코볼트
	WOLF,			// 늑대
	GOLEM			// 골렘
}; // 몬스터 종류

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
	float*	DropLoot();

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

