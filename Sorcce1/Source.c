#include <stdio.h>
#include <stdlib.h>
#include "rule.h"

int KEY(int *Kn, int *Y, int *X);
int key_get();
int deliet_key;
int main(void)
{
	//数値の変数
	int  nyr;         //入力キー
	int  sty, stx;    //座標
	int  fy, fx;      //マップ範囲
	int  jm[25][40]; //移動可不判定
	char mapc[3] = { 0 };//複写されたマップ構成情報

	//カウント
	int y, x; //判定生成、座標生成･描写用

	//function replaceEmptyMap(map, mapX, mapY) //{map[mapY][mapX] = NOT_DRAW_MAP;}
	//マップチップ
	char mc[3][3] = {
		/*mc[0] 移動可*/"　",
		/*mc[1] 移動不可*/"■", 
		/*mc[2] アイテム*/"K "};

	//マップ構成 25行x40列
	char map[][81] = {
		/*00*/"■■■■■■■■■■■■■■■■■■■■■",
		/*01*/"■　　　■　　　■　　　■　　　■　　　■",
		/*02*/"■　　　　　K 　　　　　　　　　■　　　■",
		/*03*/"■　　　■　　　■　　　■　　　■　　　■",
		/*04*/"■■■■■■　■■■■■■■　■■■　■■", 
		/*05*/"■　　　■　　　■　　　■　　　■　　　■",
	    /*06*/"■　　　　　　　■　　　　　　　　　　　■",
	    /*07*/"■　　　■　　　■　　　■　　　■　　　■",
	    /*08*/"■■■■■■■■■■■■■■　■■■　■■",  
		/*13*/"■　　　■　　　■　　　■　　　■　　　■", 
		/*14*/"■　　　　　　　■　　　■　　　　　　　■", 
		/*15*/"■　　　■　　　■　　　■　　　■　　　■", 
		/*16*/"■■　■■■■■■■　■■■■■■■　■■", 
		/*17*/"■　　　■　　　■　　　■　　　■　　　■", 
		/*18*/"■　　　　　　　　　　　　　　　　　　　■", 
		/*19*/"■　　　■　　　■　　　■　　　■　　　■", 
		/*20*/"■■■■■■　■■■■■■■　■■■■■■", 
		/*21*/"■　　　■　　　■　　　■　　　■　　　■", 
		/*22*/"■　　　　　　　　　　　　　　　　　　　■", 
		/*23*/"■　　　■　　　■　　　■　　　■　　　■", 
		/*24*/"■■■■■■■■■■■■■■■■■■■■■", };

	char map1[][81] = {
		/*00*/"■■■■■■■■■■■■■■■■■■■■■",
		/*01*/"■　　　■　　　■　　　■　　　■　　　■",
		/*02*/"■　　　　　　　　　　　　　　　■　　　■",
		/*03*/"■　　　■　　　■　　　■　　　■　　　■",
		/*04*/"■■■■■■　■■■■■■■　■■■　■■",
		/*05*/"■　　　■　　　■　　　■　　　■　　　■",
		/*06*/"■　　　　　　　■　　　　　　　　　　　■",
		/*07*/"■　　　■　　　■　　　■　　　■　　　■",
		/*08*/"■■■■■■■■■■■■■■　■■■　■■",
		/*13*/"■　　　■　　　■　　　■　　　■　　　■",
		/*14*/"■　　　　　　　■　　　■　　　　　　　■",
		/*15*/"■　　　■　　　■　　　■　　　■　　　■",
		/*16*/"■■　■■■■■■■　■■■■■■■　■■",
		/*17*/"■　　　■　　　■　　　■　　　■　　　■",
		/*18*/"■　　　　　　　　　　　　　　　　　　　■",
		/*19*/"■　　　■　　　■　　　■　　　■　　　■",
		/*20*/"■■■■■■　■■■■■■■　■■■■■■",
		/*21*/"■　　　■　　　■　　　■　　　■　　　■",
		/*22*/"■　　　　　　　　　　　　　　　　　　　■",
		/*23*/"■　　　■　　　■　　　■　　　■　　　■",
		/*24*/"■■■■■■■■■■■■■■■■■■■■■", };


	//キャラクター
	char st[1][3] = { "P " };
	//鍵
	char sa[1][4] = { "K " };

	//string sa[1][5] = {"移動方向の入力"};

	//キャラクター初期座標指定
	sty = 2, stx = 2;
	
	//say=1.sax=1;


	//マップ範囲算出 
	fy = sizeof(map) / 81;   //行
	fx = strlen(map[0]) / 2; //列
	fy = sizeof(map1) / 81;   //行
	fx = strlen(map1[0]) / 2;

	//当たり判定
	for (y = 0;y < fy;y++) {
		for (x = 0;x < fx;x++) {
			strncpy(mapc, &map[y][(x) * 2], 2,&map1[y][(x) * 2], 2);
			if (strncmp(mc[1], mapc, 2) == 0) { jm[y][x] = 1; } //移動不可のとこ
			else if (strncmp(mc[0], mapc, 2) == 0) { jm[y][x] = 0; } //移動できるとこ
			else if (strncmp(mc[2], mapc, 2) == 0)
			{
				(map1,jm[x][y]);
			}
		}
	}
	
	//出力 
	while (1) {
		system("cls");
		
		//座標
		for (y = 0;y < fy;y++) {
			for (x = 0;x < fx;x++) {
				strncpy(mapc, &map[y][(x) * 2], 2);
				if (jm[y][x] == 0) {
					if (y == sty && x == stx)
					{
						printf("%s", st[0]);
					} //キャラ
					else if (strncmp(mc[0], mapc, 2) == 0)
					{
						printf("%s", mapc);
					}
				}
				else if (strncmp(mc[1], mapc, 2) == 0)
				{
					printf("%s", mapc);
				}
				else if (strncmp(mc[2], mapc, 2) == 0)//あいてむひょうじ
				{
					printf("%s", mapc);
					/*if (strncmp(mc[2], mapc, 2) == 0)
					{
						
					}*/
				}
			}
			if (fx < 40) { printf("\n"); }
		}

		printf("移動方法を入力してください\n");
		printf("h:ルール説明\n");
		//入力キー
		KEY(&nyr, &sty, &stx);

		//壁とマップ外の場所
		for (y = 0;y < sty + 1;y++) {
			for (x = 0;x < fx;x++) {
				if ((y == sty && x == stx && jm[y][x] == 1) || (fy <= sty || fx <= stx)) {
					if (nyr == 0x4b) { stx++; }
					else if (nyr == 0x4d) { stx--; }
					else if (nyr == 0x48) { sty++; }
					else if (nyr == 0x50) { sty--; }
					break;
				}
			}
		}

		//終了
		if (nyr == 0x1b) { printf("▼終了します。\n");break; }
	}

}


int KEY(int *nyr, int *Y, int *X) {
	while (1) {
		*nyr = getch();
		if ((*nyr == 0x00) || (*nyr == 0xe0)) {
			*nyr = getch(); //2:特殊キー
			if (*nyr == 0x4b) { (*X)--; }// ←
			else if (*nyr == 0x4d) { (*X)++; }// →
			else if (*nyr == 0x48) { (*Y)--; }// ↑
			else if (*nyr == 0x50) { (*Y)++; }// ↓
		  //else if (*Kn==0x  ){       }  特殊キーを入れる場合はここに追加
			else { continue; }
			break;
		}
		else if (*nyr == 0x1b) {}// Escキー
		else if (*nyr == 'h') { discription(); }
	  //else if (*Kn==0x  ){}  通常キーをいれるときはここ
		else { continue; }
		break;
	}
	return 0;
}

int key_get()
{
//	if(strncmp(mc[2], mapc, 2) == 0) {jm[y][x] = 0;}
}