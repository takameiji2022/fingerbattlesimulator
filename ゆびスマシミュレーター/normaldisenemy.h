#pragma once

#include <iostream>
#include<string>
#include"baseenemy.h"

class normaldisenemy :public baseenemy {
public:
	normaldisenemy(std::string ena) :baseenemy(ena) {}
	void dec_sayfinger(int sh);
	void dec_efinger(void);
};
