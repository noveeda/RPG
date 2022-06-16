#include <iostream>
#include "Player.h"

Player::Player()
{
	this->name		= NULL;
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

void Player::SetPlayer(char* name) {
	this->name = name;
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

void Player::TakeDamage(float damage) {

	//체력 = 데미지 - (데미지 * (방어력 / 100 + 방어력))

	float damageLossPercent = (this->def / (100 + this->def));
	this->hp -= damage - (damage * damageLossPercent);

	if (this->hp <= 0) this->hp = 0;
}

void Player::LevelUp() {
	if (this->exp == this->max_exp) {
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