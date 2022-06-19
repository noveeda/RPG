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

	char* GetPlayerName();

	float GetMaxHP();
	float GetHP();
	float Attack();

	void SetPlayer(const char* name);
	void TakeDamage(float _damage);
	void LevelUp();
	void ShowStatus();
	void GetLoot(float exp, float gold);

	bool IsDeath();

private:
	char		name[50];
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


