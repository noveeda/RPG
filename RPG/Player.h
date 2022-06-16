#pragma once


enum Equipment {
	NO_EQUIPMENT,
	WOODEN_SWORD,
	STONE_SWORD,
	IRON_SWORD,
	STEEL_SWORD,
	MITHRIL_SWORD,
	ORICHALCUM_SWORD
};

class Player{
public:
	Player();
	~Player();

	float GetMaxHP();
	float GetHP();
	float Attack();

	void SetPlayer(char* name);
	void TakeDamage(float _damage);
	void LevelUp();

private:
	char*		name;
	float		max_hp;
	float		hp;
	float		atk;
	float		def;
	float		gold;
	int			lvl;
	int			stat_point;
	float		max_exp;
	float		exp;
	Equipment	equipment;
};


