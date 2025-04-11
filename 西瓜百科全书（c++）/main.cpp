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
					cout<<"��";
					break;
				case 2:
					cout<<"��";
					break;
				case 3:
					cout<<"��";
					break;
				case 4:
					cout<<"#";
					break;
				case 5:
					cout<<"��";
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

                // ���ˮƽ����
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

                // ��鴹ֱ����
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

// �ж��Ƿ���� 3 ����������ͬ������
bool has(int board[8][8]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            int num = board[i][j];
            int count = 1;

            // ���ˮƽ����
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

            // ��鴹ֱ����
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
	cout<<"��ӭ�������������֣�W�����ϣ�������������������ͼ�μ��ɻ��300���ϱ�\nע�⣺\n1.���귶Χ��0~7\n";
	//Sleep(5000);
	int cnt=0;
	bool over=false;
	while(!over){
		if(all(board,x,y))
		over=true;
		print();
		int x1,y1;
		cout<<"��������ָ��������(x y)��";
		cin>>x1>>y1;
		cout<<"�����뽻������1���ϡ�2���¡�3����4���ң���";
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
	cout<<"��ϲ�������������ϣ�һ������"<<cnt<<"���������100ö���ϱң�\n\n"; 
	p+=300;
	return p; 
}
pair<int, int> turnData(int p,int gm){
	system("cls");
	int pgm;
	while(1){
	cout<<"������ӵ��"<<p<<"ö���ϱ�\n";
	cout<<"������ӵ��"<<gm<<"��������\n";
	cout<<"��ע��\n1. ������8000һ��\n2. ����0�˳�\n";
	cout<<"��������Ҫ�һ��Ľ����ϸ�����";
	cin>>pgm;
	if(pgm==0){
		r=make_pair(p,gm);
		system("cls");
		return r;
	}
	pgm=pgm*8000;
	if(pgm>p){
		cout<<"�Բ��������ϱ�����̫�٣�����������һ�������";
		Sleep(3000); 
	}
	else{
		p-=pgm;
		gm+=pgm/8000;
		cout<<"�һ��ɹ���\n��������"<<gm<<"�������Ϻ�"<<p<<"ö���ϱң�\n";
		Sleep(5000); 
	} 
	system("cls");
}
}

void displayMenu(string u) {
	cout<<"���ã�"<<u<<endl;
	cout<<"-------------------------------------------------\n";
    cout<<"��ѡ������Ҫ���ʵ����ݣ�\n";
    cout<<"1. ����չ����\n"; 
    cout<<"2. ������Ϸ��\n";
    cout<<"3. ���ϴ�����\n";
    cout<<"4. �һ�������\n";
    cout<<"5. ���ϱҺͽ�����ͳ��\n";
    cout<<"6. ��������\n";
    cout<<"7. ��Ȩ����\n";
    cout<<"8. �˳�\n";
    cout<<"����������ѡ��";
}
void firstmenu() {
	cout<<"-------------------------------------------------\n";
    cout<<"��ѡ������Ҫ�鿴�����ݣ�\n";
    cout<<"1. ����\n";
    cout<<"2. Ӫ����ֵ\n";
    cout<<"3. ����\n";
    cout<<"4. ��ֲ����\n";
    cout<<"5. �й��������ϲ���\n";
    cout<<"6. ���ϻ�\n";
    cout<<"7. ���Ϲ�ʫ\n"; 
    cout<<"0. ������һ��\n";
    cout<<"����������ѡ��";
}

void secondmenu() {
	cout<<"-------------------------------------------------\n";
    cout<<"��ѡ������Ҫ�����Ϸ��\n";
    cout<<"1. �����Թ�\n";
    cout<<"2. ������\n";
    cout<<"3. ����������\n";
    cout<<"4. ������\n"; 
    cout<<"5. ����̰����\n";
    cout<<"6. ����������\n";
    cout<<"7. ������\n";
    cout<<"0. ������һ��\n";
    cout<<"����������ѡ��";
}
void thirdmenu() {
	cout<<"-------------------------------------------------\n";
    cout<<"��ѡ������Ҫ����Ĵ�����\n";
    cout<<"1. ����֪ʶ����\n";
    cout<<"2. ���Ϲ�ʫ����\n";
    cout<<"3. ��˽��������Ŀ\n";
    cout<<"0. ������һ��\n";
    cout<<"����������ѡ��";
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
	cout<<"��ӭ�������ϵİٿ�ȫ�飡\n��ǰ�汾��"<<v<<endl;
	cout<<"-------------------------------------------------\n";
	if(ifcr)
	{
		cout<<"������֮ǰʹ�ù����ϰٿ�ȫ�飬�Ƿ񽫴浵Ǩ�ƹ�����(Y/N)";
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
		cout<<"������������֣�";
		cin>>user;
	}if(nochange){
		cout<<"������������֣�";
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
	                			cout<< "1.����������\n\n�Ρ�������\n�γ����嵶����Ʋ���ƿ��\nǧ���ӣ�ң�һ�Ż�ˮ����\n���ʶٳ��̻�������ݱ�����ѩ����\n\n����ʫ������п����ϵ�˲��������Ʒ��ʱ��������ܡ�ʫ���á����嵶�����п��硰����ƿ��������ϣ�¶�������硰��ӣ�ҡ���Ĺ��Ѻ͡���ˮ������Ĺ�ȿ�����º󣬷·������������̻����������ݼ��򷢳���ѩ����������������ϵ�������������\n\n"; 
								break; 
	                		case 2:
	                			system("cls"); 
	                		    cout<<"2.�����ϡ�\n\n�Ρ��˷�\n�ദ����ã���Ȼ�����š�\n��������Ө��������������\n��������ˣ�����������\n�����޴��֣�ѩƬ�ر��̡�\n\n����ʫ���������ϵ�������������ʫ���ڻ���õ���������Ȼ�ġ������š����п�����徧Ө�������������ݶ��е����䡣���ϵ������ܹ��������յ����ȣ����˵ľ�������ø����ˡ��������������ʫ�˶��������ϵ�ϲ������Ϊ���Ŷ�û��������ζ�����ϣ�ֻ����ѩƬһ���ı��̲�����֮��ȡ�\n\n"; 
								break; 
							case 3:
								system("cls"); 
	                		    cout<<"3.��ֵ����ѧȤ�����Լ�����������ʵ���������ڡ�\n\n�Ρ�����\n�鷿�ſ���ӢӢ����ζ��Ȼ����ܰ��\n�����������ȴ������Ӧ�������ࡣ\n\n�ɫ�¶���ˮ����ζ����������������Ʈ����������ɢ���^�ֽ�������\n����ʫ������������ϵ���̬��ζ������������ʫ�˵���С�ǰ�������������ϵ������͹�ʵ������ر���Ϊ���鷿�ſ���ӢӢ��������������ζ��Ȼ�����ţ�ʫ���á������������ȴ�����������ϵ���������󣬲�����˶ԡ������ࡱ������ָѧ�������ˣ��Ĺ�����˼�����������������ϵ��������������Լ���������������Ǵ��������������á�\n\n";
								break; 
							case 4:
								system("cls"); 
	                		    cout<<"4.������԰��\n\n�Ρ����ɴ�\n����ӯ԰���ճ������Ϲ�Բ�����롣\n����һƬ��������񵶿�����ȿ��\n\n����ʫ�����һ����������԰�ľ��󡣵�һ��'����ӯ԰���ճ�'��������������԰������ïʢ�ľ��󡣵ڶ���'���Ϲ�Բ������'����������������԰�е�λ�ã�����Բ����������������'����һƬ������'��������ϸ����Ǵ����������У������������յ����ȡ����һ��'���񵶿�����ȿ'�ñ������ַ��������п�����ʱ�������龰����ɫ����Ƥ����񣬶���ɫ�Ĺ�ȿ�����˴��ѡ�\n\n"; 
								break; 
							case 5:
								system("cls");
								cout << "5.����Բʫ��\n\n�ϱ�������Լ\n";
								cout << "���Ϸ����⣬���������顣" << endl;
							    cout << "���ѷ����ף��������β" << endl;
							    cout << "��ݿ�򿰰ѣ�ʱ������롣" << endl;
							    cout << "�����з�ʵ���μ�����֦��" << endl;
							    cout << "������Ұ�㣬���������ء�" << endl << endl;	
							    cout << "����ʫ�����һ����԰���߷�ï�ľ���Ӫ���һ���������������԰��Χ��ʫ��ͨ��ϸ�µ���д԰�еĸ���ũ���չ�ֳ���԰��������Ӻ����ã�����˶���԰���������Ͷ���Ȼ���Ȱ���\n\n";
							    break;
							case 0:
	                			cout<< "\n�����˳���...\n\n"; break; 
							default:
	                			cout<< "\n��Ч��ѡ�����������г���������Ч��ѡ�\n\n"; 					
						}
					}while(cp!=0);
                	break;				
						case 0:
                			cout<< "�����˳���...\n"; break; 
						default:
                			cout<< "\n��Ч��ѡ�����������г���������Ч��ѡ�\n\n"; 					
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
                			cout<< "�����˳���...\n"; break; 
						default:
                			cout<< "\n��Ч��ѡ�����������г���������Ч��ѡ�\n\n"; 					
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
                			cout<< "�����˳���...\n"; break; 
						default:
                			cout<< "\n��Ч��ѡ�����������г���������Ч��ѡ�\n\n"; 					
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
				cout<<"����������Ҫ���ĵ����֣�";
				cin>>user;
				if(oldName==user){
					cout<<"���ֺ�֮ǰ��ͬ��\n\n";
				}
				else
				cout<<"���ĳɹ��������ڵ�������"<<user<<"\n\n";
				break;	    
			case 7:
				watermelon.shengming(v);
				break;
            case 8:
            	cout<<"������ӵ��"<<point<<"ö���ϱ�\n";
				cout<<"������ӵ��"<<gm<<"��������\n\n";
				cout<<"�Ƿ�Ϊ���浵��(Y/N)";
				char cheakyn;
				cin>>cheakyn;
				if(toupper(cheakyn)=='Y')
				{
					file.writeDataToDesktop(point,gm,user,name);	
				}
            	cout<<"��ӭ�´�ʹ�ã�\n";
                break;    
            default:
                cout<< "��Ч��ѡ�����������г���������Ч��ѡ�\n\n";
                cout<<"-------------------------------------------------\n";
        }
    } while (choice !=8);
	cout<<"��������˳�...\n";
	getch();
    return 0;
}
