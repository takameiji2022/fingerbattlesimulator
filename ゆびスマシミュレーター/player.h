#pragma once

#include <iostream>
#include<string>
#include"baseenemy.h"

class player :public baseenemy {
public:
	player(std::string ena) : baseenemy(ena) {}
	void dec_sayfinger(int sh);
	void dec_efinger(void);
};
