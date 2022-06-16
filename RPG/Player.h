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

const float damage_weight[7] = {
	// �������� ������ ��޿� ���� ������ ����ġ�� ����
	1.0, // NO_EQUIPMENT (�Ǽ��̿��� ������ �����ϱ� ����..)
	1.2, // WOODEN_SWORD
	1.5, // STONE_SWORD
	1.8, // IRON_SWORD
	2.0, // STEEL_SWORD
	2.6, // MITHRIL_SWORD
	3.15 // ORICHARCUM_SWORD
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
	char* name;
	float max_hp;
	float hp;
	float atk;
	float def;
	float gold;
	int lvl;
	int stat_point;
	float max_exp;
	float exp;
	Equipment equipment;

};


