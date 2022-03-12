#pragma once

#include <iostream>
#include<string>
#include<vector>

class baseenemy {
protected:
	std::string name;	//���O
	int finger;			//�グ��w	
	int sayfinger;		//�\�z����w
	int hand;			//��̐�
	int order;			//����
	int rank;			//����
	int state;			//���
	int vicnum;			//������

public:
	baseenemy(std::string ena) {
		name = ena;
		finger = 100;
		sayfinger = 0;
		hand = 2;
		order = 100;
		rank = 100;
		state = 1;
		vicnum = 0;
	}//�R���X�g���N�^

	//�����o�ϐ��̎擾
	std::string get_name(void);
	int get_finger(void);
	int get_sayfinger(void);
	int get_hand(void);
	int get_order(void);
	int get_rank(void);
	int get_state(void);
	int get_vicnum(void);

	//�����o�ϐ��ύX����
	void dec_name(std::string na);
	void calc_hand(void);
	void dec_order(int dor);
	void dec_rank(int dra);
	void one_state(void);
	void two_state(void);
	void victory(void);
	void plusvic(void);

	//���z�֐�
	virtual void dec_sayfinger(int sh);
	virtual void dec_efinger(void);
	virtual void calctable(int sh, int sf);
	virtual void pluscalcetable(void);
	virtual void printrtable(void);
	virtual void printetable(void);

	//�ꕔ������
	void reconstruct(void);

	//�f�o�b�O�p
	void check_state(void);

};
