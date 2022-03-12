#include<random>
#include"baseenemy.h"

std::string baseenemy::get_name(void) {
	return name;
}

int baseenemy::get_finger(void) {
	return finger;
}

int baseenemy::get_sayfinger(void) {
	return sayfinger;
}

int baseenemy::get_hand(void) {
	return hand;
}

int baseenemy::get_order(void) {
	return order;
}

int baseenemy::get_rank(void) {
	return rank;
}

int baseenemy::get_state(void) {
	return state;
}

int baseenemy::get_vicnum(void) {
	return vicnum;
}

void baseenemy::dec_name(std::string na) {
	name = na;
}


void baseenemy::calc_hand(void) {
	if (hand > 0) {
		hand -= 1;
	}
}

void baseenemy::dec_order(int dor) {
	order = dor;
}

void baseenemy::dec_rank(int dra) {
	rank = dra;
}

void baseenemy::one_state(void) {
	state = 1;
}

void baseenemy::two_state(void) {
	state = 2;
}

void baseenemy::victory(void) {
	state = 0;
}

void baseenemy::plusvic(void) {
	vicnum += 1;
}

void baseenemy::reconstruct(void) {
	hand = 2;
	order = 100;
	rank = 100;
	state = 1;
}

void baseenemy::dec_sayfinger(int sh) {
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<> randthree(0, sh);
	sayfinger = randthree(rng);
}

void baseenemy::dec_efinger(void) {
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<> randthree(0, hand);
	finger = randthree(rng);
}

void baseenemy::calctable(int sh, int sf) {}
void baseenemy::pluscalcetable(void) {}
void baseenemy::printrtable(void) {}
void baseenemy::printetable(void) {}

void baseenemy::check_state(void) {
	std::cout << "–¼‘O" << name << "\nstate" << state << std::endl;
}
