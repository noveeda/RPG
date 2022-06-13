#include <cmath>
#include <iostream>
#include "Monster.h"
#include "rand.h"

#pragma warning( disable : 26812 )
#define NOT_DEFINED 0

using namespace std;


const char* MonsterName[] = {
	"NO NAME",
	"SLIME",
	"GOBLIN",
	"KOBOLD",
	"WOLF",
	"GOLEM"
};

const float MonsterBaseStatus[][6] = {
//     HP    ATK    DEF    Exp    Gold
	{	0,	   0,	  0,     0,      0}, // NOT SPECIFIED
	{  20,     3,     4,     5,      5}, // SLIME
	{  30,    10,     8,    10,     13}, // GOBLIN
	{  60,    15,    16,    20,     20}, // COBALT
	{  30,    20,    20,    20,	    30}, // WOLF
	{  80,    10,    50,    15,     40}  // GOLEM
};

Monster::Monster() {
	this->mob_name	= MonsterName[NOT_DEFINED];
	this->m_class	= NO_CLASS;
	this->m_type	= NO_TYPE;
	// 각 몹 타입에 해당하는 스탯
	this->max_hp	= MonsterBaseStatus[NOT_DEFINED][HP];
	this->hp		= max_hp;
	this->atk		= MonsterBaseStatus[NOT_DEFINED][ATK];
	this->def		= MonsterBaseStatus[NOT_DEFINED][DEF];

	// 범위 : 경험치 ± √(경험치)
	float exp		= MonsterBaseStatus[NOT_DEFINED][EXP];
	this->exp		= Range(exp - sqrt(exp), exp + sqrt(exp));
	
	// 범위 : 골드 ± √(골드)
	float gold		= MonsterBaseStatus[m_type][GOLD];
	this->gold		= Range(gold - sqrt(gold), gold + sqrt(gold));
}

Monster::~Monster() {

}

void	Monster::SetMonster(MonsterClass m_class, MonsterType m_type) {
	
	this->mob_name = MonsterName[m_type];
	this->m_class = m_class;
	this->m_type = m_type;

	// 각 몹 타입에 해당하는 스탯
	this->max_hp = MonsterBaseStatus[m_type][HP];
	this->hp	 = max_hp;
	this->atk	 = MonsterBaseStatus[m_type][ATK];
	this->def	 = MonsterBaseStatus[m_type][DEF];

	// 범위 : 경험치 ± √(경험치)
	float exp = MonsterBaseStatus[m_type][EXP];
	this->exp = round(Range(exp - sqrt(exp), exp + sqrt(exp)) * 100) / 100;	// 소수 2자리까지 반올림

	// 범위 : 골드 ± √(골드)
	float gold = MonsterBaseStatus[m_type][GOLD];
	this->gold = round(Range(gold - sqrt(gold), gold + sqrt(gold)) * 100) / 100;
	
}

const char*	Monster::GetMonsterType() {
	return this->mob_name;
}

float	Monster::GetMaxHP() {
	return this->max_hp;
}

float	Monster::GetHP() {
	return this->hp;
}

void	Monster::TakeDamage(int _damage){
	float damageLossPercent = (this->def / (100 + this->def));
	this->hp -= _damage - (_damage * damageLossPercent);
	if (this->hp <= 0) this->hp = 0;
}

bool	Monster::IsDeath() {
	if (this->hp <= 0) return true;
	return false;
}

void	Monster::DropTreasure(float* target_exp, float* target_gold)
{
	if (IsDeath() == true) {
		*target_exp	 = this->exp;
		*target_gold = this->gold;
	}
}

void	Monster::ShowStatus() {
	printf("{\n");
	printf("    \"MAX_HP\" : \"%g\",\n", max_hp);
	printf("    \"HP\" : \"%g\",\n", hp);
	printf("    \"ATK\" : \"%g\",\n", atk);
	printf("    \"DEF\" : \"%g\",\n", def);
	printf("    \"EXP\" : \"%g\",\n", exp);
	printf("    \"GOLD\" : \"%g\",\n", gold);
	printf("},\n");
}