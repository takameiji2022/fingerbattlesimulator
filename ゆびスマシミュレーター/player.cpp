#include"player.h"

void player::dec_sayfinger(int sh) {
	int exfin = 0;
	while (1) {
		if (hand == 0)break;
		std::cout << "���̐l���グ��w�̍��v��\�z���Ă�������" << std::endl;
		std::cin >> exfin;
		std::cout << std::endl;
		if (exfin >= 0 && exfin <= sh) {
			break;
		}
		else {
			std::cout << "���̐��͏o���܂���I" << std::endl;
		}
	}
	sayfinger = exfin;
}

void player::dec_efinger(void) {
	int upfin = 0;
	while (1) {
		if (hand == 0)break;
		std::cout << "�グ��w�̐��𓚂��Ă�������" << std::endl;
		std::cin >> upfin;
		std::cout << std::endl;
		if (upfin >= 0 && upfin <= hand) {
			break;
		}
		else {
			std::cout << "���̐��͏o���܂���I" << std::endl;
		}
	}
	finger = upfin;
}