#include "Rand.h"
#include <random>

using namespace std;

int Range(int range1, int range2) {
	// �õ尪�� ��� ���� random_device ����.
	random_device rd;

	// random_device �� ���� ���� ���� ������ �ʱ�ȭ �Ѵ�.
	mt19937 gen(rd());

	// range1 ���� range2���� �յ� ���� ����
	uniform_int_distribution<int> dis(range1, range2);

	return dis(gen);
}

float Range(float range1, float range2) {
	// �õ尪�� ��� ���� random_device ����.
	random_device rd;

	// random_device �� ���� ���� ���� ������ �ʱ�ȭ �Ѵ�.
	mt19937 gen(rd());

	// range1 ���� range2���� �յ� ���� ����
	uniform_real_distribution<float> dis(range1, range2);

	return dis(gen);
}