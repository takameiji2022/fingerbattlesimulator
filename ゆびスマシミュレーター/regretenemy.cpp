#include<random>
#include"regretenemy.h"

void regretenemy::dec_sayfinger(int sh) {
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_real_distribution<> kakuritu(0.0, 1.0);
	std::vector<double> ptable(12);
	double calckakuritu = kakuritu(rng);
	double pplus = 0;
	int deccol = 0;
	int tablesum = 0;
	for (int i = 0;i < 12;i++) {
		tablesum += rtable[sh - 1][i];
	}

	for (int i = 0;i < 12;i++) {
		ptable[i] = rtable[sh - 1][i] / (double)tablesum;
		pplus += ptable[i];
		if (calckakuritu <= pplus) {
			deccol = i;
			break;
		}
	}
	sayfinger = deccol;
}

void regretenemy::dec_efinger(void) {
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_real_distribution<> kakuritu(0.0, 1.0);
	std::vector<double> pertable(3);
	double calckakuritu = kakuritu(rng);
	double pplus = 0;
	int deccol = 0;
	int tablesum = 0;
	for (int i = 0;i < 3;i++) {
		tablesum += etable[hand][i];
	}
	for (int i = 0;i < 3;i++) {
		pertable[i] = etable[hand][i] / (double)tablesum;
		pplus += pertable[i];
		if (calckakuritu <= pplus) {
			deccol = i;
			break;
		}
	}
	finger = deccol;
}

void regretenemy::reconstruct(void) {
	hand = 2;
	order = 100;
	rank = 100;
	state = 1;
}

void regretenemy::firsttableconst(void) {
	for (int i = 0;i < 10;i++) {
		for (int j = 0;j < 12;j++) {
			if (j < i + 2) {
				rtable[i][j] = 1;
			}
			else {
				rtable[i][j] = 0;
			}
		}
	}

	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			if (j < i + 1) {
				etable[i][j] = 1;
			}
			else {
				etable[i][j] = 0;
			}
		}
	}
}

void regretenemy::calctable(int sh, int sf) {
	rtable[sh - 1][sf] += 1;
}

void regretenemy::pluscalcetable(void) {
	etable[hand][finger] += 1;
}

void regretenemy::printrtable(void) {
	std::cout << name << "‚Ìsaytable" << std::endl;
	for (int i = 0;i < 10;i++) {
		for (int j = 0;j < 12;j++) {
			std::cout << rtable[i][j] << "  ";
		}
		std::cout << "\n";
	}
}

void regretenemy::printetable(void) {
	std::cout << name << "‚Ìetable" << std::endl;
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			std::cout << etable[i][j] << "  ";
		}
		std::cout << "\n";
	}
}