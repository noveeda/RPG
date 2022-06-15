#pragma once

enum Equipment {
	LONG_SWORD,
	SHORT_SWORD,
	BOW,
	CROSS_BOW,
	WAND,
};
class Player
{
public:
	Player();
	~Player();
private:
	float hp;
	float max_hp;
	float atk;
	float def;
	float gold;
	int lvl;
	float exp;
	Equipment equipment;
	
};

