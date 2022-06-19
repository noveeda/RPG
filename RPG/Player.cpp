#include <iostream>
#include <cstring>
#include "Player.h"

const float damage_weight[7] = {
	// 착용중인 무기의 등급에 따라 데미지 가중치를 적용
	1.0, // NO_EQUIPMENT (맨손이여도 맞으면 아프니까 ㅎㅎ..)
	1.2, // WOODEN_SWORD
	1.5, // STONE_SWORD
	1.8, // IRON_SWORD
	2.0, // STEEL_SWORD
	2.6, // MITHRIL_SWORD
	3.15 // ORICHARCUM_SWORD
};

Player::Player()
{
	strcpy_s(this->name, "");
	this->atk		= 0;
	this->def		= 0;
	this->max_hp	= 0;
	this->hp		= this->max_hp;
	this->max_exp	= 0;
	this->exp		= this->max_exp;
	this->lvl		= 0;
	this->gold		= 0;
	this->equipment = NO_EQUIPMENT;
	this->stat_point= 0;
}

Player::~Player() {

}

char* Player::GetPlayerName() {
	return this->name;
}

void Player::SetPlayer(const char* name) {
	strcpy_s(this->name, 50, name);
	this->atk = 10;
	this->def = 10;
	this->max_hp = 100;
	this->hp = this->max_hp;
	this->exp = 0;
	this->max_exp = 100;
	this->lvl = 1;
}

float Player::GetMaxHP() {
	return this->max_hp;
}

float Player::GetHP(){
	return this->hp;
}

float Player::Attack() {
	return this->atk * damage_weight[this->equipment];
}

// 피해
void Player::TakeDamage(float damage) {

	//체력 = 데미지 - (데미지 * (방어력 / 100 + 방어력))

	float damageLossPercent = (this->def / (100 + this->def));
	this->hp -= damage - (damage * damageLossPercent);

	if (this->hp <= 0) this->hp = 0;
}

// 레벨 업
void Player::LevelUp() {
	if (this->exp >= this->max_exp) {
		// 레벨 업
		this->lvl++;
		// 경험치 초기화
		this->exp = 0;
		
		// 레벨 마다 경험치 요구량이 점점 높아짐
		if (lvl <= 10) this->max_exp += 100;
		else if (lvl <= 30) this->max_exp += 150;
		else if (lvl <= 60) this->max_exp += 300;
		else if (lvl <= 100) this->max_exp += 500;
		else this->max_exp += 900;
		
		// 스테이터스 가산
		this->atk += 10;
		this->def += 10;
		this->max_hp += 100;
		this->hp += 100;

		// 내가 맘대로 추가가 가능한 스탯포인트 +5
		this->stat_point += 5;
	}
}

void Player::ShowStatus() {
	printf("{\t\n");
	printf("\t\"Name\"	  : \"%s\",\n", this->name);
	printf("\t\"ATK\"	  : \"%g\",\n", this->atk);
	printf("\t\"DEF\"	  : \"%g\",\n", this->def);
	printf("\t\"Max_HP\"  : \"%g\",\n", this->max_hp);
	printf("\t\"HP\"	  : \"%g\",\n", this->hp);
	printf("\t\"Exp\"	  : \"%g\",\n", this->exp);
	printf("\t\"Max_Exp\" : \"%g\",\n", this->max_exp);
	printf("\t\"LVL\"	  : \"%d\",\n", this->lvl);
	printf("},\n");
}

// 죽을 시 보유 골드, 경험치의 10%를 잃음.
bool Player::IsDeath() {
	if (this->hp <= 0) {
		this->gold -= this->gold * .1;
		this->exp -= this->exp * .1;
		return true;
	}
}