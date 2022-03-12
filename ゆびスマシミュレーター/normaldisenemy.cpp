#include<random>
#include"normaldisenemy.h"

void normaldisenemy::dec_sayfinger(int sh) {
	double aveh = (double)sh / 2;
	double ndr;
	int indr;
	std::random_device rd;
	std::mt19937 rng(rd());
	std::normal_distribution<> ndrandom(aveh, 1.5);
	while (1) {
		ndr = ndrandom(rng);
		indr = (int)(ndr + 0.5);
		if (indr <= sh && indr >= 0)break;
	}
	sayfinger = indr;
}

void normaldisenemy::dec_efinger(void) {
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<> randthree(0, hand);
	finger = randthree(rng);
}