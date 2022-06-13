#include "Rand.h"
#include <random>

using namespace std;

int Range(int range1, int range2) {
	// 시드값을 얻기 위한 random_device 생성.
	random_device rd;

	// random_device 를 통해 난수 생성 엔진을 초기화 한다.
	mt19937 gen(rd());

	// range1 부터 range2까지 균등 분포 정의
	uniform_int_distribution<int> dis(range1, range2);

	return dis(gen);
}

float Range(float range1, float range2) {
	// 시드값을 얻기 위한 random_device 생성.
	random_device rd;

	// random_device 를 통해 난수 생성 엔진을 초기화 한다.
	mt19937 gen(rd());

	// range1 부터 range2까지 균등 분포 정의
	uniform_real_distribution<float> dis(range1, range2);

	return dis(gen);
}