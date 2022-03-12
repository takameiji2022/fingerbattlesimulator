#include"player.h"

void player::dec_sayfinger(int sh) {
	int exfin = 0;
	while (1) {
		if (hand == 0)break;
		std::cout << "他の人が上げる指の合計を予想してください" << std::endl;
		std::cin >> exfin;
		std::cout << std::endl;
		if (exfin >= 0 && exfin <= sh) {
			break;
		}
		else {
			std::cout << "その数は出せません！" << std::endl;
		}
	}
	sayfinger = exfin;
}

void player::dec_efinger(void) {
	int upfin = 0;
	while (1) {
		if (hand == 0)break;
		std::cout << "上げる指の数を答えてください" << std::endl;
		std::cin >> upfin;
		std::cout << std::endl;
		if (upfin >= 0 && upfin <= hand) {
			break;
		}
		else {
			std::cout << "その数は出せません！" << std::endl;
		}
	}
	finger = upfin;
}