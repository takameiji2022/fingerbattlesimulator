#pragma once

#include <iostream>
#include<string>
#include"baseenemy.h"

class medianenemy :public baseenemy {
public:
	medianenemy(std::string ena) :baseenemy(ena) {}

	void dec_sayfinger(int sh);
	void dec_efinger(void);

};
