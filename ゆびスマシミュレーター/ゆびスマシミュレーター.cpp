#include <iostream>
#include<random>
#include"randomenemy.h"
#include"normaldisenemy.h"
#include"medianenemy.h"
#include"regretenemy.h"
#include"player.h"

#define Pnum 5	//プレイヤー数
#define GamePlayNum 1 //ゲーム回数


//状況説明関数
void placestate(baseenemy* enemy[Pnum]) { 
	int sumhand = 0, playernum = 0;
	for (int i = 0;i < Pnum;i++) {
		if (enemy[i]->get_state() != 0) {
			sumhand += enemy[i]->get_hand();
			playernum += 1;
		}
	}

	std::cout << "現在の状況\n場にある手の数の合計  " << sumhand << "\n残りの人数  " << playernum << std::endl;
	for (int i = 0;i < Pnum;i++) {
		std::cout << enemy[i]->get_name() << "  ";
		if (enemy[i]->get_state() == 0) {
			std::cout << enemy[i]->get_rank() << "位" << std::endl;
		}
		else {
			std::cout << "残りの手の数  " << enemy[i]->get_hand() << std::endl;
		}
	}
	std::cout << std::endl;
}


//結果説明関数
void resultstate(int order, baseenemy* enemy[Pnum]) {
	int sumfinger = 0;
	for (int i = 0;i < Pnum;i++) {
		if (enemy[i]->get_state() == 1) {
			sumfinger += enemy[i]->get_finger();
		}
	}
	std::cout << enemy[order]->get_name() << "が" << enemy[order]->get_sayfinger() << "本指が上がると予想しました" << std::endl;
	std::cout << "上がった指の数は" << sumfinger << "本でした" << std::endl;
	if (enemy[order]->get_sayfinger() == sumfinger) {
		std::cout << "正解です！" << std::endl;
	}
	else {
		std::cout << "残念はずれです！" << std::endl;
	}
	std::cout << std::endl;
}


//ゲーム進行関数
void gameprogress(baseenemy* enemy[Pnum]) {
	int rank = 1;
	int sumfinger = 0;
	int sumhand = 0;
	int playernum = Pnum;

	for (int i = 0;i < Pnum;i++) {
		enemy[i]->reconstruct();
	}//必要な値の初期化
	
	while (1) {
		if (playernum == 1)break;
		for (int j = 0;j < Pnum;j++) {
			sumhand = 0;
			sumfinger = 0;

			if (enemy[j]->get_state() != 0) {
				enemy[j]->two_state();
			}//予想状態へ

			placestate(enemy);//状態表示

			for (int i = 0;i < Pnum;i++) {
				if (enemy[i]->get_state() == 0) {}
				else if (enemy[i]->get_state() == 1) {
					sumhand += enemy[i]->get_hand();
					enemy[i]->dec_efinger();
					sumfinger += enemy[i]->get_finger();
				}
			}//生存プレイヤの上げる指を決定

			enemy[j]->dec_sayfinger(sumhand); //予想決定

			resultstate(j, enemy); //結果表示

			enemy[j]->one_state(); //状態戻す

			if (enemy[j]->get_sayfinger() == sumfinger) {
				enemy[j]->calc_hand();
			}
			else {
				for (int k = 0;k < Pnum;k++)
					if (enemy[k]->get_hand() != 0) {
						enemy[k]->pluscalcetable();
					}
			}//状態の更新

			enemy[j]->calctable(sumhand, sumfinger);//状態の更新

			if (enemy[j]->get_hand() == 0 && enemy[j]->get_rank() == 100) {
				enemy[j]->victory();
				enemy[j]->dec_rank(rank);
				rank++;
				playernum -= 1;
			}//状態の更新

			if (playernum == 1) {
				for (int i = 0;i < Pnum;i++) {
					if (enemy[i]->get_rank() == 100)
						enemy[i]->dec_rank(rank);
				}
				break;
			}//終了条件と最下位の決定
		}//一周終了
	}//ゲーム終了
}




int main()
{
	//名前決定
	std::string name1 = "太郎";
	std::string name2 = "次郎";
	std::string name3 = "三郎";
	std::string name4 = "四郎";
	std::string name5 = "五郎";

	//プレイヤの種類決定
	player p1(name1);
	randomenemy p2(name2);
	medianenemy p3(name3);
	normaldisenemy p4(name4);
	regretenemy p5(name5);


	baseenemy* enemy[] = {&p1, &p2, &p3, &p4, &p5}; 

	std::cout << "gaemstart\n";

	for (int i = 0;i < GamePlayNum;i++) {
		gameprogress(enemy);
		for (int j = 0;j < Pnum;j++) {
			std::cout << enemy[j]->get_name() << enemy[j]->get_rank() << "位" << std::endl;
			if (enemy[j]->get_rank() == 1) {
				enemy[j]->plusvic();
			}
		}
	}//全ゲーム終了

	std::cout << std::endl;

	for (int i = 0;i < Pnum;i++) {
		std::cout << enemy[i]->get_name() << "1位回数 " << enemy[i]->get_vicnum() << std::endl;
	}//１位回数表示

	std::cout << std::endl;

	for (int i = 0;i < Pnum;i++) {
		enemy[i]->printrtable();
		enemy[i]->printetable();
	}//regretplayerの利得テーブル表示

	return 0;
}