#pragma once

#include <iostream>
#include<string>
#include<vector>
#include"baseenemy.h"

class randomenemy : public baseenemy {
public:
	randomenemy(std::string ena) :baseenemy(ena) {}
	void dec_sayfinger(int sh);
	void dec_efinger(void);
};
