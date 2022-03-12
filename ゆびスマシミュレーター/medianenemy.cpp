#include<random>
#include"medianenemy.h"

void medianenemy::dec_sayfinger(int sh) {
	double aveh = (double)sh / 2;
	int medianh;
	medianh = (int)(aveh + 0.5);
	sayfinger = medianh;
}

void medianenemy::dec_efinger(void) {
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<> randthree(0, hand);
	finger = randthree(rng);
}
