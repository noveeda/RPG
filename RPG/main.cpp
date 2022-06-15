#include <iostream>
#include "Monster.h"

using namespace std;

int main() {
	Monster mob[3];
	
	for (int i = 0; i < 3; i++) {
		int type;
		cout << "Monster Type(1: SLIME, 2: GOBLIN, 3: KOBOLD, 4: WOLF, 5: GOLEM): "; cin >> type;
		MonsterClass m_c = COMMON;
		MonsterType m_t;
		switch (type) {
		case 1:
			m_t = SLIME;
			break;
		case 2:
			m_t = GOBLIN;
			break;
		case 3:
			m_t = KOBOLD;
			break;
		case 4:
			m_t = WOLF;
			break;
		case 5:
			m_t = GOLEM;
			break;
		}

		mob[i].SetMonster(m_c, m_t);
	}

	for (int i = 0; i < 3; i++) {
		mob[i].ShowStatus();
	}
}