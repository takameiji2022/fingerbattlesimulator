#pragma once
#include <iostream>
#include<string>
#include"baseenemy.h"

class regretenemy :public baseenemy {
protected:
	std::vector<std::vector<int>> rtable{ 10,std::vector<int>(12) };		//�\�z�����e�[�u��
	std::vector < std::vector<int> > etable{ 3,std::vector<int>(3) };	//�ʏ험���e�[�u��

public:
	regretenemy(std::string ena) :baseenemy(ena) {
		firsttableconst();
	}

	void dec_sayfinger(int sh);
	void dec_efinger(void);

	void firsttableconst(void);
	void reconstruct(void);
	void calctable(int sh, int sf);
	void pluscalcetable(void);

	void printrtable(void);
	void printetable(void);
};
