#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <ctime>
#include <algorithm>
#include "watermelon.h" 
#include "file.h"
using namespace std;
pair<int, int> r;
tuple<int, int, string> d;
const int H=8;
int board[H][H];
int dir,x,y;
const string v="v1.8.8";
const string name="watermelon.txt";
void print(){
	cout<<"  ";
	for(int i=0;i<8;i++)
	cout<<i;
	cout<<endl;
	for(int i=0;i<8;i++){
		cout<<i<<" "; 
		for(int j=0;j<8;j++){
			if(board[i][j]==0){
				cout<<" ";
				continue;
			}
			if(i==x&&j==y){
				cout<<"W";
				continue;
			}
			switch(board[i][j]){
				case 0:
					cout<<" ";
					break;
				case 1:
					cout<<"■";
					break;
				case 2:
					cout<<"▲";
					break;
				case 3:
					cout<<"★";
					break;
				case 4:
					cout<<"#";
					break;
				case 5:
					cout<<"●";
					break;				
			}
		}
		cout<<endl;
	}
} 
void Drop() {
    for (int i = H - 1; i >= 0; i--) {
        for (int j = 0; j < H; j++) {
            if (board[i][j] == 0) {
                int k = i - 1;
                while (k >= 0 && board[k][j] == 0) {
                    k--;
                }
                if (k >= 0) {
                    board[i][j] = board[k][j];
                    board[k][j] = 0;
                }
            }
        }
    }
}
void Same(int board[8][8]) {
    bool changed = false;
    while (!changed) {
        changed = false;

        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                int num = board[i][j];
                int count = 1;

                // 检查水平方向
                for (int k = j + 1; k < 8; k++) {
                    if (board[i][k] == num) {
                        count++;
                    } else {
                        break;
                    }
                }

                if (count >= 3) {
                    for (int k = j; k < j + count; k++) {
                        board[i][k] = 0;
                    }
                    changed = true;
                }

                count = 1;

                // 检查垂直方向
                for (int k = i + 1; k < 8; k++) {
                    if (board[k][j] == num) {
                        count++;
                    } else {
                        break;
                    }
                }

                if (count >= 3) {
                    for (int k = i; k < i + count; k++) {
                        board[k][j] = 0;
                    }
                    changed = true;
                }
            }
        }
    }
}

// 判断是否存在 3 个及以上相同的数字
bool has(int board[8][8]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            int num = board[i][j];
            int count = 1;

            // 检查水平方向
            for (int k = j + 1; k < 8; k++) {
                if (board[i][k] == num) {
                    count++;
                } else {
                    break;
                }
            }

            if (count >= 3) {
                return true;
            }

            count = 1;

            // 检查垂直方向
            for (int k = i + 1; k < 8; k++) {
                if (board[k][j] == num) {
                    count++;
                } else {
                    break;
                }
            }

            if (count >= 3) {
                return true;
            }
        }
    }

    return false;
}
bool all(int arr[8][8], int row, int col) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i!= row || j!= col) && arr[i][j]!= 0) {
                return false;
            }
        }
    }
    return true;
}
int run(int p){
	system("cls");
	cout<<"欢迎来玩西瓜消消乐！W是西瓜，消除除西瓜以外所有图形即可获得300西瓜币\n注意：\n1.坐标范围：0~7\n";
	//Sleep(5000);
	int cnt=0;
	bool over=false;
	while(!over){
		if(all(board,x,y))
		over=true;
		print();
		int x1,y1;
		cout<<"请输入您指定的坐标(x y)：";
		cin>>x1>>y1;
		cout<<"请输入交换方向（1：上、2：下、3：左、4、右）：";
		cin>>dir; 
		switch(dir){
    	case 1:
    		swap(board[x1][y1],board[x1-1][y1]);
			break;
		case 2:
			swap(board[x1][y1],board[x1+1][y1]);
			break;
		case 3:
			swap(board[x1][y1],board[x1][y1-1]);
			break;
		case 4:
			swap(board[x1][y1],board[x1][y1+1]);
			break;
	} 
		cnt++;
		if(has(board))
		Same(board);
		Drop(); 
		system("cls");
	}
	cout<<"恭喜！您消除了西瓜，一共用了"<<cnt<<"步，获得了100枚西瓜币！\n\n"; 
	p+=300;
	return p; 
}
pair<int, int> turnData(int p,int gm){
	system("cls");
	int pgm;
	while(1){
	cout<<"您现在拥有"<<p<<"枚西瓜币\n";
	cout<<"您现在拥有"<<gm<<"个金西瓜\n";
	cout<<"备注：\n1. 金西瓜8000一个\n2. 按下0退出\n";
	cout<<"请输入您要兑换的金西瓜个数：";
	cin>>pgm;
	if(pgm==0){
		r=make_pair(p,gm);
		system("cls");
		return r;
	}
	pgm=pgm*8000;
	if(pgm>p){
		cout<<"对不起，您西瓜币数量太少，请重新输入兑换个数！";
		Sleep(3000); 
	}
	else{
		p-=pgm;
		gm+=pgm/8000;
		cout<<"兑换成功！\n您现在有"<<gm<<"个金西瓜和"<<p<<"枚西瓜币！\n";
		Sleep(5000); 
	} 
	system("cls");
}
}

void displayMenu(string u) {
	cout<<"您好！"<<u<<endl;
	cout<<"-------------------------------------------------\n";
    cout<<"请选择您想要访问的内容：\n";
    cout<<"1. 西瓜展览区\n"; 
    cout<<"2. 西瓜游戏区\n";
    cout<<"3. 西瓜答题区\n";
    cout<<"4. 兑换金西瓜\n";
    cout<<"5. 西瓜币和金西瓜统计\n";
    cout<<"6. 更改名字\n";
    cout<<"7. 版权声明\n";
    cout<<"8. 退出\n";
    cout<<"请输入您的选择：";
}
void firstmenu() {
	cout<<"-------------------------------------------------\n";
    cout<<"请选择您想要查看的内容：\n";
    cout<<"1. 介绍\n";
    cout<<"2. 营养价值\n";
    cout<<"3. 种类\n";
    cout<<"4. 种植技巧\n";
    cout<<"5. 中国部分西瓜产地\n";
    cout<<"6. 西瓜画\n";
    cout<<"7. 西瓜古诗\n"; 
    cout<<"0. 返回上一级\n";
    cout<<"请输入您的选择：";
}

void secondmenu() {
	cout<<"-------------------------------------------------\n";
    cout<<"请选择您想要玩的游戏：\n";
    cout<<"1. 西瓜迷宫\n";
    cout<<"2. 打西瓜\n";
    cout<<"3. 猜西瓜重量\n";
    cout<<"4. 赌西瓜\n"; 
    cout<<"5. 西瓜贪吃蛇\n";
    cout<<"6. 西瓜消消乐\n";
    cout<<"7. 吃西瓜\n";
    cout<<"0. 返回上一级\n";
    cout<<"请输入您的选择：";
}
void thirdmenu() {
	cout<<"-------------------------------------------------\n";
    cout<<"请选择您想要参与的答题活动：\n";
    cout<<"1. 西瓜知识竞赛\n";
    cout<<"2. 西瓜古诗竞赛\n";
    cout<<"3. 猪八戒吃西瓜题目\n";
    cout<<"0. 返回上一级\n";
    cout<<"请输入您的选择：";
}
void first(){
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			int b=rand()%(5-1+1)+1;
			board[i][j]=b;
		}
	}
}
int point=0,gm=0;
bool ifcr,nochange;
int main() {
	first();
    Watermelon watermelon;
    File file;
    board[x][y]==6;
	srand(time(0));
	x=y=rand()%(8-1+1)+1;
    string user="",oldName;
    if(file.isFileEmpty(name)==true){
	ifcr=false;
	}
    else if(file.checkFileOnDesktop(name)){
	d=file.readDataFromDesktop(name);
	point=get<0>(d);
	gm=get<1>(d);
	user=get<2>(d);
	ifcr=true;
	}else{
		file.createFileOnDesktop(name); 
		ifcr=false; 
	} 
    int choice,c1,c2,c3,cp;
	cout<<"欢迎来到西瓜的百科全书！\n当前版本是"<<v<<endl;
	cout<<"-------------------------------------------------\n";
	if(ifcr)
	{
		cout<<"发现您之前使用过西瓜百科全书，是否将存档迁移过来？(Y/N)";
		char qwjkv;
		cin>>qwjkv;
		if(toupper(qwjkv)!='Y'){
		point=0;
		gm=0;
		user=""; 
		nochange=true;
		}
	}
	else{
		cout<<"请输入你的名字：";
		cin>>user;
	}if(nochange){
		cout<<"请输入你的名字：";
		cin>>user;
	}
	system("cls");
    do {
        displayMenu(user);
		cin >> choice;
		cout<<endl;
        switch (choice) {
            case 1:
                do{
                	firstmenu();
                	cin>>c1;
                	switch(c1){
                		case 1:
                			watermelon.printTypes(); break; 
                		case 2:
                			watermelon.printNutrition(); break; 
						case 3:
                			watermelon.printCultivation(); break; 
						case 4:
                			watermelon.funFact(); break; 
                		case 5:
							watermelon.where(); break;
						case 6:
							watermelon.round(); break;
						case 7:
							do{
			                	watermelon.poemmenu();
			                	cin>>cp;
			                	switch(cp){
                			case 1:
	                			system("cls"); 
	                			cout<< "1.《西瓜吟》\n\n宋·文天祥\n拔出金佩刀，斫破苍玉瓶。\n千点红樱桃，一团黄水晶。\n下咽顿除烟火气，入齿便作冰雪声。\n\n这首诗描绘了切开西瓜的瞬间美景与品尝时的美妙感受。诗人用“金佩刀”来切开如“苍玉瓶”般的西瓜，露出里面如“红樱桃”般的瓜籽和“黄水晶”般的瓜瓤。吃下后，仿佛能立刻消除烟火气，而牙齿间则发出冰雪般的声音，形容西瓜的清凉与甜美。\n\n"; 
								break; 
	                		case 2:
	                			system("cls"); 
	                		    cout<<"2.《西瓜》\n\n宋·顾逢\n多处淮乡得，天然碧玉团。\n破来肌体莹，嚼处齿牙寒。\n清敌炎威退，凉生酒量宽。\n东门无此种，雪片簇冰盘。\n\n这首诗赞美了西瓜的清凉与美丽。诗人在淮乡得到了这种天然的“碧玉团”，切开后瓜体晶莹，吃在嘴里牙齿都感到寒冷。西瓜的清凉能够抵御夏日的炎热，让人的酒量都变得更宽了。最后两句则表达了诗人对这种西瓜的喜爱，认为东门都没有这种美味的西瓜，只有像雪片一样的冰盘才能与之相比。\n\n"; 
								break; 
							case 3:
								system("cls"); 
	                		    cout<<"3.《值侯修学趣儒人稍急因遗莲花莲实西瓜于吾宗》\n\n宋·曾丰\n珠房颗颗绿英英，兴味超然芹藻馨。\n不必铁槌挝碎却，苦心应念子衿青。\n\n绀色毬儿护水晶，味甘如蜜冷如冰。香风飘满葵丘戍，散与鸮林解郁蒸。\n这首诗不仅描绘了西瓜的形态与味道，还寄托了诗人的情感。前两句描述了西瓜的藤蔓和果实，形象地比喻为“珠房颗颗绿英英”，并赞美其兴味超然。接着，诗人用“不必铁槌挝碎却”来形容西瓜的易碎与珍贵，并表达了对“子衿青”（可能指学生或儒人）的关心与思念。后两句则描绘了西瓜的甜美与清凉，以及它在夏日里给人们带来的舒适与愉悦。\n\n";
								break; 
							case 4:
								system("cls"); 
	                		    cout<<"4.《西瓜园》\n\n宋·范成大\n绿蔓盈园夏日长，西瓜滚圆卧中央。\n清凉一片消烦暑，碧玉刀开见红瓤。\n\n这首诗描绘了一幅夏日西瓜园的景象。第一句'绿蔓盈园夏日长'描述了夏天西瓜园里藤蔓茂盛的景象。第二句'西瓜滚圆卧中央'形象地描绘了西瓜在园中的位置，它们圆润地躺在那里。第三句'清凉一片消烦暑'表达了西瓜给人们带来的清凉感，帮助消除夏日的炎热。最后一句'碧玉刀开见红瓤'用比喻的手法描述了切开西瓜时看到的情景，绿色的外皮像碧玉，而红色的瓜瓤则令人垂涎。\n\n"; 
								break; 
							case 5:
								system("cls");
								cout << "5.《行圆诗》\n\n南北朝·沈约\n";
								cout << "寒瓜方卧垅，秋菰亦满陂。" << endl;
							    cout << "紫茄纷烂熳，绿芋郁参差。" << endl;
							    cout << "初菘向堪把，时韮日离离。" << endl;
							    cout << "高梨有繁实，何减万年枝。" << endl;
							    cout << "荒渠集野雁，安用昆明池。" << endl << endl;	
							    cout << "这首诗描绘了一幅田园果蔬丰茂的景象，营造出一种宁静、富足的田园氛围。诗人通过细致地描写园中的各种农作物，展现出田园生活的质朴和美好，表达了对田园风光的赞美和对自然的热爱。\n\n";
							    break;
							case 0:
	                			cout<< "\n正在退出中...\n\n"; break; 
							default:
	                			cout<< "\n无效的选择，请重新运行程序并输入有效的选项。\n\n"; 					
						}
					}while(cp!=0);
                	break;				
						case 0:
                			cout<< "正在退出中...\n"; break; 
						default:
                			cout<< "\n无效的选择，请重新运行程序并输入有效的选项。\n\n"; 					
					}
				}while(c1!=0);
				system("cls"); 
                break;
            case 2:
                do{
                	secondmenu();
                	cin>>c2;
                	switch(c2){
                		case 1:
                			point=watermelon.migong(point);
							break; 
                		case 2:
                			point=watermelon.hit(point);
							break;
						case 3:
							point=watermelon.weigh(point);
							break;	
						case 4:
							point=watermelon.board(point);
							break;	 
						case 5:
							point=watermelon.snake(point);
							break;	
						case 6:
							point=run(point);
							break;	
						case 7:
							point=watermelon.eat(point);
							break;	
						case 0:
                			cout<< "正在退出中...\n"; break; 
						default:
                			cout<< "\n无效的选择，请重新运行程序并输入有效的选项。\n\n"; 					
					}
				}while(c2!=0);
				system("cls"); 
                break;
            case 3:
                do{
                	thirdmenu();
                	cin>>c3;
                	switch(c3){
                		case 1:
                			point=watermelon.zhishi(user,point);
							break; 
                		case 2:
                			point=watermelon.zhishi2(user,point);
							break;
						case 3:
							point=watermelon.pwt(gm); 
							break; 	 
						case 0:
                			cout<< "正在退出中...\n"; break; 
						default:
                			cout<< "\n无效的选择，请重新运行程序并输入有效的选项。\n\n"; 					
					}
				}while(c3!=0);
				system("cls"); 
                break;
            case 4:
				r=turnData(point,gm);
				point=r.first;
				gm=r.second;
				break;
			case 5:
				system("cls");
				watermelon.Data(point,gm);
				break;	
			case 6:
				system("cls");
				oldName=user; 
				cout<<"请输入您想要更改的名字：";
				cin>>user;
				if(oldName==user){
					cout<<"名字和之前相同！\n\n";
				}
				else
				cout<<"更改成功！您现在的名字是"<<user<<"\n\n";
				break;	    
			case 7:
				watermelon.shengming(v);
				break;
            case 8:
            	cout<<"您现在拥有"<<point<<"枚西瓜币\n";
				cout<<"您现在拥有"<<gm<<"个金西瓜\n\n";
				cout<<"是否为您存档？(Y/N)";
				char cheakyn;
				cin>>cheakyn;
				if(toupper(cheakyn)=='Y')
				{
					file.writeDataToDesktop(point,gm,user,name);	
				}
            	cout<<"欢迎下次使用！\n";
                break;    
            default:
                cout<< "无效的选择，请重新运行程序并输入有效的选项。\n\n";
                cout<<"-------------------------------------------------\n";
        }
    } while (choice !=8);
	cout<<"按任意键退出...\n";
	getch();
    return 0;
}
