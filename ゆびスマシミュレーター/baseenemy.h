#pragma once

#include <iostream>
#include<string>
#include<vector>

class baseenemy {
protected:
	std::string name;	//名前
	int finger;			//上げる指	
	int sayfinger;		//予想する指
	int hand;			//手の数
	int order;			//順番
	int rank;			//順位
	int state;			//状態
	int vicnum;			//勝利回数

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
	}//コンストラクタ

	//メンバ変数の取得
	std::string get_name(void);
	int get_finger(void);
	int get_sayfinger(void);
	int get_hand(void);
	int get_order(void);
	int get_rank(void);
	int get_state(void);
	int get_vicnum(void);

	//メンバ変数変更処理
	void dec_name(std::string na);
	void calc_hand(void);
	void dec_order(int dor);
	void dec_rank(int dra);
	void one_state(void);
	void two_state(void);
	void victory(void);
	void plusvic(void);

	//仮想関数
	virtual void dec_sayfinger(int sh);
	virtual void dec_efinger(void);
	virtual void calctable(int sh, int sf);
	virtual void pluscalcetable(void);
	virtual void printrtable(void);
	virtual void printetable(void);

	//一部初期化
	void reconstruct(void);

	//デバッグ用
	void check_state(void);

};
