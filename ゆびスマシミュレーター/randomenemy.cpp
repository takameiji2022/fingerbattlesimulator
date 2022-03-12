#include<random>
#include"randomenemy.h"

void randomenemy::dec_sayfinger(int sh) {
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<> randthree(0, sh);
	sayfinger = randthree(rng);
}

void randomenemy::dec_efinger(void) {
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<> randthree(0, hand);
	finger = randthree(rng);
}