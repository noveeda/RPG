#pragma once
enum MonsterClass {
	NO_CLASS = 0,	// Å¬·¡½º ¾øÀ½
	COMMON,			// ÀÏ¹Ý ¸÷
	RARE,			// ·¹¾î ¸÷
	UNIQUE,			// Èñ±Í ¸÷
	BOSS			// º¸½º ¸÷
}; // ¸ó½ºÅÍ Èñ±Íµµ

enum MonsterType {
	NO_TYPE = 0,	// Å¸ÀÔ ¾øÀ½
	SLIME,			// ½½¶óÀÓ
	GOBLIN,			// °íºí¸°
	KOBOLD,			// ÄÚº¼Æ®
	WOLF,			// ´Á´ë
	GOLEM			// °ñ·½
}; // ¸ó½ºÅÍ Á¾·ù

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

