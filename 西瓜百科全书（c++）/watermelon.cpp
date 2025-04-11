#include "watermelon.h"
#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>
#define RESET "\x1B[0m"
#define GREEN "\x1B[32m"
#define RED "\x1B[31m"
using namespace std;
void Watermelon::hide(){
	HANDLE            hOut;
	CONSOLE_CURSOR_INFO curInfo;
	hOut=GetStdHandle(STD_OUTPUT_HANDLE);
	curInfo.dwSize=1;
	curInfo.bVisible=0;
	SetConsoleCursorInfo(hOut,&curInfo);
}
void Watermelon::set(){
	HANDLE hOut;
	COORD pos={0,0};
	hOut=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut,pos);
}
struct Question {
    string question;
    string options[4];
    char correctAnswer; // ��ȷ�𰸵���ĸ��A, B, C, D��
};
struct Question2{
    string question2;
    string options2[4];
    char correctAnswer2; // ��ȷ�𰸵���ĸ��A, B, C, D��
};

void Watermelon::printTypes() {
	system("cls"); 
    cout << "���ϣ�ѧ����Citrullus lanatus���Ǻ�«�ƣ��ֽк��ϡ��Ĺϣ���һ���������ٱ�ֲ�\n";
    cout << "������һ�ֹ㷺�����ʳ��ֲ�ԭ���ڷ����ȴ��ĸɺ�ɳĮ�ش��������й���\n\n";	
}

void Watermelon::printNutrition() {
	system("cls"); 
    cout << "Ӫ����ֵ��\n";
    cout << "���Ϻ��д���ˮ�֡��Ƿ֡����ְ����ᡢά���ء������ʵ�Ӫ���ɷ֡�\n";
    cout << "�������ܹ����Ƚ������ֹ�ʣ��������򡢽�Ѫѹ�ȹ�Ч��\n\n";
	
}

void Watermelon::printCultivation() {
	system("cls"); 
    cout << "���ࣺ\n";
    cout << "���ϵ����෱�࣬�������к�Ƥ�ϡ���Ƥ�ϡ����ѹϡ�����ϵȡ�\n";
    cout << "��ͬ����������ڿڸС���ȡ�ˮ�ֺ����ȷ���������ͬ��\n\n";
    
}

void Watermelon::funFact() {
	system("cls"); 
    cout << "��ֲ���ɣ�\n";
    cout << "1. ����ѡ��ѡ���Ź෽�㡢��������������ɡ������еȻ����ϵȵĵؿ���ֲ,����Χ�¶Ⱦ�����25~30�ȡ�\n";
    cout << "   ������ǰ��ÿĶʩ��ָ�����л���3000��5000����Ϸ�200��300���ʩ���������أ���ƽ��ϸ��\n";
    cout << "2. ���Ӵ���ѡ�ñ������޳溦���������ӡ�Ϊ����߷�ѿ�ʣ����Խ����ӷ�����ˮ�н���4-6Сʱ���̳�����ˮ�֣�¶�׺󼴿ɲ��֡�\n";
    cout << "3. ����ʱ�䣺���������ȶ���15������ʱ���֡����õ㲥����ÿѨ��1-2�����ӣ�����2-3���׺��ϸ������������ʪ��\n";
    cout << "4. ���������Ϸ�֦����ǿ����Ҫ��ʱ��֦ѹ����һ�����˫����֦��������֦�ķ���������������������������׳�Ĳ�����\n";
    cout << "   �����������ڼ䣬Ҫ����ʩ�ʺͽ�ˮ����������������Ҫ��ʱ׷�ʣ���������ʪ�󣬱����ˮ��\n";
    cout << "5. ���溦���Σ����ϲ��溦�϶࣬Ҫ��ǰԤ�������Բ���������κͻ�ѧ�������ϵķ������з��Ρ�\n";
    cout << "   �ڷ������ڣ�����ʹ��ɱ������ɱ������з��Σ������顢�پ��塢�������ȡ�\n";
    cout << "6. ����ʱ�������ϵĳ���ʱ����Ʒ�ֺ���ֲʱ����졣����ͨ���۲����ϵ���ۡ��ô������������ȷ������ж������Ƿ���졣\n";
    cout << "   ��������ϱ�Ƥ�⻬����������������������ë���䣬�����ô�����ʱ�����������顯��������\n\n";
    
}
void Watermelon::show()
{
	HANDLE h_GAME =GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor_info;
	GetConsoleCursorInfo(h_GAME,&cursor_info);
	cursor_info.bVisible=true;
	SetConsoleCursorInfo(h_GAME,&cursor_info);
}

int Watermelon::zhishi2(string a,int p){
	system("cls"); 
	srand(time(0));
	if(a=="")
	cout<<"��ӭ���μ����Ϲ�ʫ������������Ŀ��8����ÿ��10�֣���80�֡�\n"; 
	else
	cout<<a<<"����ӭ���μ����Ϲ�ʫ������������Ŀ��8����ÿ��10�֣���80�֡�\n"; 
    vector<Question2> questions2= {
    	{"�����ľ��ʫ����ȷ�ᵽ��������һˮ����", {"A. ��С�ɲ�¶���ǣ�������������ͷ����", "B. ��������˪����ɳ����������ʳ���ϡ���", "C. ��������Ҷ����̣�ӳ�պɻ������졣��", "D. ���ɾն����£���Ȼ����ɽ����"}, 'B'},//ľ׮ 
        {"�����ʶٳ��̻�������ݱ�����ѩ���� �����������ʳ������ʱ��������ܡ��������ʫ����λʫ��������", {"A. ���ɴ�", "B. ����", "C. ����", "D. ������"}, 'B'},
        {"��λ�δ�ʫ��������Ϊ�⣬д���ˡ����Ի���ã���Ȼ�����š�������ʫ�䣿", {"A. ����", "B. ������", "C. ���ɴ�", "D. ½��"}, 'C'},
        {"���й�ʫ�У���һ�����������ϵ���������֮����", {"A. �����Ϸ����⣬�����������", "B. ��������ü�������ֵ��ʱ����", "C. �����������ˮ�����ˡ���", "D. ����ɴ����͸���㣬��������׺���ҡ���"}, 'A'},
        {"�����Ѻ�ȿ����ɴ����Ƥ���������ġ������ʫ���������ˮ����", {"A. ����", "B. ��", "C. ����", "D. ����", },'C'}, // ע�⣺�����90%�Ǽ�˵����ʵ�ʿ���������ͬ
        {"�����ľ�ʫ�е����������ϵ�Բ���������ƣ�", {"A. ����Բ���������̣���������δ���ۡ���", "B. �����¼�ʱ�У��Ѿ������졣��", "C. ��ǧĥ������ᾢ���ζ������ϱ��硣��", "D. ����������Ϊ��ͣ�ÿ��ѽڱ�˼�ס���"}, 'B'},
        {"��λʫ��ͨ����������˪����ɳ��������ʫ�䣬չ������������Ұ�е�����״̬��", {"A. ���", "B. �Ÿ�", "C. ������", "D. ���ɴ�"}, 'D'}, // ע�⣺�����ж���Ӫ���������ѡһ����Ϊʾ��
        {"�����ľ�ʫ�����������������п����ȿ���ѵ����˾���", {"A. ����������׺���ң��ɺ�ɴ��͸���㡣��", "B. ����ɴ����͸���㣬��������׺���ҡ���", "C. ������ױ��һ���ߣ�����������˿�С���", "D. ����ȿ���������У�����ɿ�����Ƣ����"}, 'D'}, // ע�⣺����ʱ������򻷾�����
        {"�����ľ�ʫ�����ϵ������ڸ���Ϊ���У�", {"A. ����֮���£����ɳ��䡣��", "B. ����ɬ�����̵��ʣ�ζ֮��Ʒ����⡣��", "C. ����ڸ�����񺮣���ζ�Ƽճ����䡣�� ","D. ��������ζ����ǰ�������˹������ࡣ��"}, 'C'}// ע�⣺�䶳���ܻ�Ӱ��ڸУ��������Ͽ���
    };
	int s=0;
	char ans;
	vector<int> temp;
	for (int i = 0; i < 8; ++i)
	{
		temp.push_back(i + 1);
		    	
	}
	random_shuffle(temp.begin(), temp.end());//turn num order
    for(int i=0;i<8;i++){
    	int a=temp[i];
    	cout<<i+1<<". "<<questions2[a].question2<<endl;
    	for(int i=0;i<4;i++){
    	cout<<questions2[a].options2[i]<<endl;
    	}
    	cin>>ans;
    	if(toupper(ans)==questions2[a].correctAnswer2){
    		cout<<"��ϲ��������ˣ�\n"; 
			s+=10; 
		}else{
			cout<<"���ź�������ˡ���ȷ����"<<questions2[a].correctAnswer2<<endl; 
		}
		cout<<endl; 
	}
	cout << "��Ϸ�������������շ�����: " <<s<< endl;
	cout<<"��ϲ���õ�"<<s<<"ö���ϱң�\n"; 
	p+=s;
	cout<<endl;
	return p;
	}
	
int Watermelon::zhishi(string a,int p){
	system("cls"); 
	srand(time(0));
	if(a=="")
	cout<<"��ӭ���μ�����֪ʶ������������Ŀ��10����ÿ��10�֣���100�֡�\n"; 
	else
	cout<<a<<"����ӭ���μ�����֪ʶ������������Ŀ��10����ÿ��10�֣���100�֡�\n"; 
    vector<Question> questions = {
    	{"�������ĸ����ڵ�ˮ����", {"A. ����", "B. �ļ�", "C. �＾", "D. ����"}, 'B'},//ľ׮ 
        {"�������ĸ����ڵ�ˮ����", {"A. ����", "B. �ļ�", "C. �＾", "D. ����"}, 'B'},
        {"���ϵ��ĸ���������", {"A. ��Ƥ", "B. ����", "C. ��������", "D. ������Ƥ"}, 'C'},
        {"����Ƥ����ʳ����", {"A. ����", "B. ������", "C. ֻ����ɫ��Ƥ����", "D. ֻ�л�ɫ��Ƥ����"}, 'A'},
        {"���Ϻ��ж���ˮ�֣�", {"A. 50%", "B. 70%", "C. 90%", "D. 100%"}, 'C'}, // ע�⣺�����90%�Ǽ�˵����ʵ�ʿ���������ͬ
        {"���ϵ����ӿ�����ֲ��", {"A. ����", "B. ������", "C. ֻ�к�ɫ�����ӿ���", "D. ֻ�а�ɫ�����ӿ���"}, 'A'},
        {"��������ЩӪ����ֵ��", {"A. ����ά����C", "B. ����֬��", "C. �����Ƿ���Ӫ��", "D. ���϶�����"}, 'A'}, // ע�⣺�����ж���Ӫ���������ѡһ����Ϊʾ��
        {"�����п�����ö�ò���ʳ�ã�", {"A. 1Сʱ", "B. 2Сʱ", "C. ����", "D. һ��"}, 'C'}, // ע�⣺����ʱ������򻷾�����
        {"���Ͽ����䶳������", {"A. ����", "B. ������", "C. ֻ�����", "D. ����䶳������"}, 'A'}, // ע�⣺�䶳���ܻ�Ӱ��ڸУ��������Ͽ���
        {"���ϵ�Ӣ����ʲô��", {"A. Watermelon", "B. Melon", "C. Pineapple", "D. Orange"}, 'A'},
        {"���������Ǹ��ƣ�",{"A. �ѿ�","B. ��«��","C. ����","D. �տ�"},'B'}, 
        {"���������������͵�ˮ����",{"A. ������","B. ����","C. �˹���","D. ������"},'B'},
        {"����Ƥ����������ʲô��",{"A. ֻ���ӵ�","B. �������Ƴ��̲�","C. �������ɹ�Ƥ��","D. B��C������"},'D'},
		{"�����ѿ���ʳ����",{"A. ���ԣ���Ӫ���ḻ","B. �����ԣ����ڶ����ﳤ������","C. �����ԣ���Ϊ�ж�","D. ���ԣ���Ӫ����ֵ����"},'D'}
    };
	int s=0;
	char ans;
	vector<int> temp;
	for (int i = 0; i < 12; ++i)
	{
		temp.push_back(i + 1);
		    	
	}
	random_shuffle(temp.begin(), temp.end());//turn num order
    for(int i=0;i<10;i++){
    	int a=temp[i];
    	cout<<i+1<<". "<<questions[a].question<<endl;
    	for(int i=0;i<4;i++){
    	cout<<questions[a].options[i]<<endl;
    	}
    	cin>>ans;
    	if(toupper(ans)==questions[a].correctAnswer){
    		cout<<"��ϲ��������ˣ�\n"; 
			s+=10; 
		}else{
			cout<<"���ź�������ˡ���ȷ����"<<questions[a].correctAnswer<<endl; 
		}
		cout<<endl; 
	}
	cout << "��Ϸ�������������շ�����: " <<s<< endl;
	cout<<"��ϲ���õ�"<<s<<"ö���ϱң�\n"; 
	p+=s;
	cout<<endl;
	return p;
	}
int Watermelon::migong(int p){
system("cls"); 
hide();
int SIZE = 10;
srand (time(0));
int a=rand()%(7-1+1)+1;
int watermelonX = a, watermelonY =a;
// �Թ���ͼ��0��ʾͨ·��1��ʾǽ��
char maze[SIZE][SIZE] = {
    "##########",
    "#    #  ##",
    "# ## ### #",
    "##       #",
    "## #  ## #",
    "##  #  # #",
    "#     ## #",
    "#   #   ##",
    "# #    # #",
    "##########"
};

// ���λ��
int playerX = 1, playerY = 1,x=0;
if(watermelonX==playerX&&watermelonY==playerY) {
	watermelonY++;
	watermelonX+=3;
}
    bool gameOver = false;
	maze[watermelonX][watermelonY]=' ';
    while (!gameOver){
    	set();
    	cout<<"��ӭ���������Թ�������WASD�����������ң�P������λ�ã�W�����ϣ�#��ǽ�ڡ��뽫���뷨�л�ΪӢ�ġ���ȥ�����ϰɣ�\n"; 
    	for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i == playerX && j == playerY) {
                cout << 'P'; // 'P'��ʾ���
            } else if (i == watermelonX && j == watermelonY) {
                cout << 'W'; // 'W'��ʾ����
            } else {
                cout << maze[i][j];
            }
        }
        cout<<endl; 
    	}
        // ����������
        if (kbhit()) {
            char input = getch();
            int newX = playerX, newY = playerY;
    		switch (input) {
        		case 'w': newX--;  break; // ��
        		case 's': newX++;  break; // ��
       	 		case 'a': newY--;  break; // ��
        		case 'd': newY++;  break; // ��
       		}
       	

    // �����λ���Ƿ����Թ����Ҳ���ǽ��
    if (maze[newX][newY]==' '&& newX < SIZE && newY < SIZE ) {
        playerX = newX;
        playerY = newY;
        x++;
    }
	}

        // ����Ƿ�ʤ��
        if (playerX == watermelonX && playerY == watermelonY) {
            
        	cout << endl;
    
            cout << "��ϲ�����ҵ������ϣ���һ������"<<x<<"��\n";
		    cout<<"��ϲ���õ�100ö���ϱң�\n\n"; 
		    p+=100;
            gameOver = true;
        }
    
}
	show();
	return p;
}
int Watermelon::snake(int p){
	system("cls");
	set(); 
	hide();
	const int SIZE = 20;
	srand(time(0));
	int a=rand()%(7-1+1)+1,sc=0,tt=0,cnt=0;
	int g[21][21]={0};
	int playerX = 1, playerY = 1,x=0;
    bool gameOver = false;
    cout<<"��ӭ��������̰���ߣ�����WASD�����������ң�P������λ�ã�W�����϶���#��ǽ��\n����30���ʱ�����\n�뽫���뷨�л�ΪӢ�ġ���ȥ�����ϰɣ�\n"; 
	Sleep(3000);
	cout<<"��Ϸ��ʼ��";
	Sleep(900);
	system("cls");
    clock_t start,end;
    	start = clock();
    	//��ʼ�� 
    	for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) { 
			if (rand()%(4-1+1)+1==3&&cnt<=120) {
                g[i][j]=1;
                cnt++;
            }
        }
    	}	
    while (!gameOver){
		set();
    	for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
        	if(i==0||i==SIZE-1||j==0||j==SIZE-1)
        	cout<<"#";
            else if (i == playerX && j == playerY) {
                cout << 'P'; // 'P'��ʾ���
            } else if (g[i][j]==1) {
                cout << 'W'; // 'W'��ʾ���϶��� 
                g[i][j]=1;
            } else {
                cout << " ";
            }
        }
        cout<<endl; 
    	}	
    	end = clock();
		if((end - start) >= 30 *CLOCKS_PER_SEC)
		gameOver=true;
        // ����������
        if (kbhit()) {
            char input = getch();
            int newX = playerX, newY = playerY;
    		switch (input) {
        		case 'w': newX--;  break; // ��
        		case 's': newX++;  break; // ��
       	 		case 'a': newY--;  break; // ��
        		case 'd': newY++;  break; // ��
       		}
       	

    // �����λ���Ƿ����Թ����Ҳ���ǽ��
    if (newX!=0&&newX!=SIZE-1&&newY!=SIZE-1&&newY!=0) {
        playerX = newX;
        playerY = newY;
    }
}
        if (g[playerX][playerY]==1) {
            g[playerX][playerY]=0;
            sc++;
        }
}
	show();
	int sco=sc*5;
	cout<<"��Ϸ���������ܹ�����"<<sc<<"�����϶���\n�������" <<sco<<"ö���ϱң�\n\n";
	p+=sco;
	return p;
}
int Watermelon::hit(int p){
srand(static_cast<unsigned int>(time(0)));
	hide();
	system("cls"); 
	cout<<"��ӭ�����������Ϸ��'-'Ϊ���ϡ�����10�У�0~9����10�У�0~9����\nע�⣺X�����Y�����0��ʼ������Ҫ���ź����ţ��м���Ҫ�ӿո�\n��Ϸ������ʼ��" ; 
	Sleep(5000);
    // ��ʼ�����ϵ�λ��
    int playerX, playerY,cnt=0;
    bool gameOver = false;
    while (!gameOver) {
		hide();    	
    	time_t t1,t2;
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
		for(int i=3;i>0;i--){
			cout<<i;
			Sleep(1000); 
			system("cls");
		}
		cout<<"��ʼ��"; 
		cnt++;
		int watermelonX = rand() % 10;
    	int watermelonY = rand() % 10; 
		Sleep(500); 
		system("cls");
        // ��ӡ��Ϸ��ͼ
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                if (i == watermelonX && j == watermelonY) {
                    cout << "-"; // ���ϵ�λ��
                } else {
                    cout << "_"; // �յ�
                }
            }
            cout << endl;
        }
		show();
        // �����������
        cout << "����7�����������ϵ�λ�ã�x y��: ";
        time(&t1);
        cin >> playerX >> playerY;
		time(&t2);
		int c=t2-t1;
		hide(); 
        if(c>7){
        	cout<<"�Բ�����û���ڹ涨ʱ�������롣��������!" ;
        	Sleep(3000);
			continue; 
		}
        if (playerX < 0 || playerX >= 10 || playerY < 0 || playerY >= 10) {
            cout << "�������" << endl;
            Sleep(2000);
            continue; // ��������ѭ����ʣ�ಿ�֣����´�ӡ��ͼ�ͽ�������
        }
        if (watermelonX == playerX && watermelonY == playerY) {
            cout << "\n��ϲ�������������ϣ�����" <<cnt<<"�λ���������\n";
            float t=1-(cnt/10);
		    int qq=100*t; 
		    p+=qq;
		    cout<<"��ϲ���õ�"<<qq<<"ö���ϱң�\n\n"; 
            gameOver = true; // ������Ϸ������־
        } else {
            cout << "δ���У������ԡ�" << endl;
            Sleep(500);
        }
    }
    return p;
}
void Watermelon::poemmenu(){
	cout<<"\n-------------------------------------------------\n";
    cout<<"��ѡ������Ҫ�˽�Ĺ�ʫ��\n";
    cout<<"1. �����顶��������"<<endl;
	cout<<"2. �˷꡶���ϡ�"<<endl;
	cout<<"3. ���ᡶֵ����ѧȤ�����Լ�����������ʵ���������ڡ�"<<endl;
	cout<<"4. ���ɴ�����԰��"<<endl;
	cout<<"5. ��Լ����԰ʫ��\n";
	cout<<"0. ������һ��\n";
    cout<<"����������ѡ��";
}
void Watermelon::shengming(string v1){
	system("cls");
	cout<<"������������С��������\n";
	cout<<"�汾�ţ�"<<v1<<endl; 
	cout<<"\n����������ѵģ������֧������ط��ã���ô���ͱ�ƭ�ˣ�\n";
	cout<<"�����Ծ����ʹ�á��ıࡢת�صȣ����Ͻ�������Υ�߱ؾ���\n";	
	cout<<endl;
	cout<<"��л����֧�֣�\n\n";
	cout<<"-------------------------------------------------\n";
}
void Watermelon::where() {
	system("cls"); 
    cout << "�й����ϲ��ֲ���\n";
    cout << "�������ϣ�ɽ��ʡ�����ж�������ȫ��������һ��������ֳ�������أ�����Ͳ����߾�ȫ����һ��\n";
    cout << "��̨���ϣ�����ʡ�γ��ж�̨��Ҳ�Ǳ������й�����֮��ĳ��У���ֲ��ģΪ����ʡ��һ��\n";
	cout << "�������ϣ����Ͽ�����������ϱ���Ϊ�������ϣ�Ƥ��֭�ࡢưɳ����\n";
	cout << "�����������ϣ�����������ʿ���������أ��������������к��н���Ԫ�������ʱ���֮Ϊ��ɰ�ϡ�\n\n";
}
int Watermelon::pwt(int gm){	
	srand(time(0));
	int b=rand()%(5-2+1)+2,n;
	int x=rand()%(8-1+1)+1;	
	if(x%b==0){
		x++;
	} 
	bool a1=false;
	while(!a1){
	int b=rand()%(5-2+1)+2,n;
	int x=rand()%(8-1+1)+1;	
	if(x%b==0){
		x++;
	} 	
	system("cls");	
	cout<<"��ӭ������˽��������Ϸ��\n��Ϸ����������һ����������������������ϵĸ�������˽����"<<b<<"��ȥ�����ϡ����ϵı�Ŵӡ�1����ʼ���򣬳ʻ��ΰڷţ���β��ӡ�\n������ܱ�����"<<x<<"�Ž����ϣ���ô���Ӯ�ˣ�\n";
	cout<<"˵������˽�ӸոճԵ������Ͽ�ʼ�ߣ���"<<b<<"�������Ҫ�Ե����ϡ�\nע�⣺\n1. ��һ���Ǵ����ϻ���絽��1�������ϣ�����1����\n2. �������Ҫ��"<<x<<"�󣬷��������ϡ�\n"; 
	cout<<"���������ϵĸ�����";
	cin>>n;
	if(n<x){
	cout<<"\n�������!����ԭ�����������"<<x<<"С��\n�������ϣ�\n";
	Sleep(4000);
	continue;
	}else
	a1=true;
}
	list<int> a;
	for(int i=1;i<=n;i++)
	a.push_back(i);
	list<int>::iterator i=a.begin();
	for(int j=1;j<=n-1;j++){
	i++; 
	if(i==a.end())
	i=a.begin();
	if(*i==b){
		i=a.erase(i);
		if(i==a.end())
		i=a.begin();
	}
	}
	int cans=*(a.begin());
	if(cans==x){
	cout<<"��ϲ������ס�˽����ϲ��õ�����������ϣ�\n\n";
	gm++; 
	}else{
	cout<<"���ź��������ϱ���˽����\n\n";	
	}
	return gm;
}
int Watermelon::weigh(int p){
	system("cls");
	int num,n=-1,cnt=0;
	bool flag=false;
	cout<<"��ӭ���������������Ϸ��"<<endl; 
	cout<<"���������Ϸ�У�����ÿ������һ�����������������ϵ�������\nҪ�����������Ҫ���ڵ���1��С�ڵ���10��\nף���������!\n";
	srand(time(0));
	num=rand()%(10-1+1)+1;
	do{
		cout<<"���������ϵ�������"; 
		cnt++;
		cin>>n;
		cout<<endl;
		if(n>10||n<1){
			cout<<"��Ч�����룬���������룡"<<endl;
			cout<<"-------------------------------------------------\n"; 
			cnt--;
		}
		else if(n>num){
		    cout<<"�����´���!"<<endl; cout<<"-------------------------------------------------\n";
		}else if(n<num){
			cout<<"������С��!"<<endl; cout<<"-------------------------------------------------\n";
		}else{
			cout<<"��ϲ�����¶��ˣ�"; 
			cout<<"��һ������"<<cnt<<"��\n";
			float t=10-(cnt/10);
		    int qq=10*t; 
		    p+=qq;
		    cout<<"��ϲ���õ�"<<qq<<"ö���ϱң�\n";  
			flag=true; 
		}		
	}while(flag==false);
    return p;
}
int Watermelon::board(int p){
	system("cls"); 
	srand(time(0));
	int cnt=0;
	char ans;
	int a[3]={rand()%(5-1+1)+1,rand()%(5-1+1)+1,rand()%(5-1+1)+1}; 
	cout<<"��ӭ�������������Ϸ��\n";
	cout<<"����Ϸ�μ���۳�200ö���ϱң����ͬ��μ�������Y����ͬ��������N����ͬ���ֱ���˳�\n";
	cout<<"�����룺"; 
	cin>>ans;
	toupper(ans);
	if(ans!='Y')
	return p;
	else if(p<200) 
	{
		cout<<"�Բ��������ϱҲ��㣬���´�������!\n";
		Sleep(3000);
		return p;
	}
	system("cls"); 
	p-=200;
	cout<<"��ӭ�������������Ϸ��\n";
	cout<<"\n��Ϸ�����밴����ʾ����3������ע�⣬��3��������һ����\n��3�����������ϵı�š�ϵͳ�����п����������ϣ�������ݳ���ĳ̶�������������:";
	cout<<"\n1. ���3�����϶��ǳ��죬��ô����õ�8000ö���ϱ�\n";
	cout<<"2. ���������2�������ǳ��죬��ô����õ�500ö���ϱ�\n";
	cout<<"3. �������1�������ǳ��죬��ô����õ�200ö���ϱ�\n";
	cout<<"4. ���û�����ϳ��죬��ô������õ����ϱ�"<<endl;
	for(int i=0;i<=2;i++){
		int ans;
		cin>>ans;
		a[i]=a[i]%2; 
		if(a[i]==1)//δ����
		cout<<"��"<<i+1<<"��������δ�����\n";
		else{
		cout<<"��"<<i+1<<"�������ǳ����\n";
		cnt++;
		}
	}
	if(cnt==3){
		cout<<"��ϲ����3�����ϳ����ˣ��õ����ϱ�8000����\n";
		p+=8000;
	}else if(cnt==2){
		cout<<"��ϲ����2�����ϳ����ˣ��õ����ϱ�1000����\n";
		p+=500;
	}else if(cnt==1){
		cout<<"��ϲ����1�����ϳ����ˣ��õ����ϱ�200����\n";
		p+=200;
	}else if(cnt==0){
		cout<<"���ź���һ�����϶�û����\n";
	}
	return p;
}
void Watermelon::Data(int p,int gm){
	cout<<"������ӵ��"<<p<<"ö���ϱ�\n";
	cout<<"������ӵ��"<<gm<<"��������\n��������˳�...";
	getch();
	system("cls");
}
void Watermelon::round(){
	srand(time(0));
	system("cls");
    cout << RED;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 60 - i; j++) {
            cout << " ";
        }
        for (int k = 0; k < 2 * i + 1; k++) { 
            cout << "��";
        }
        cout << endl;
    }
    cout <<GREEN;
    for(int i=0;i<=49;i++){
    	cout<<" ";
	}
    for (int m = 0; m < 21; m++) {
        cout << "��";
    }
    cout << "\033[0m";  // �ָ�Ĭ����ɫ
    cout << endl;
}
int Watermelon::eat(int p){
	system("cls");
	srand(time(0));
	int fr=rand()%(12-4+1)+4,many,cnt,last;
	if(fr<=2)
	fr=8;
	bool over=false,isuser=true,isuserwin=false;
	stack<int> f;
	for(int i=0;i<fr;i++)
	f.push(i);
	cout<<"��ӭ�����������Ϸ��\n��һ��ˮ�����ϣ����Ÿ��ָ������ɸ�ˮ��������µ�ˮ��������\n";
	cout<<"��Ҫ����������С�����������µ����ϣ�һ��ֻ�ܳ�һ�������������Ե����Ͼ���Ӯ������80ö���ϱ�\n";
	cout<<"����һ����"<<fr<<"��ˮ��";
	cout<<"\n-------------------------------------------------\n";
	while(!over){
		if(isuser){
			cout<<"�����ֵ�������ˮ��������������Ҫ�Եĸ���������1��2����";
			cin>>many;
			if(many==1){
				f.pop(); 
				if(f.empty())
				{
					over=true;
					isuserwin=true;
				}
			}else if(many==2){
				f.pop();
				if(f.empty())
				{
					over=true;
					isuserwin=true;
				}
				f.pop();
				if(f.empty())
				{
					over=true;
					isuserwin=true;
				}
			}else{
				cout<<"������Ч�����������룡\n";
				continue;
			}
		}else{
			cout<<"�����ֵ�����С������ˮ����";
			last=f.size(); 
			many=last%2==0?2:1;
			if(many==1){
				f.pop();
				if(f.empty())
				{
					over=true;
					isuserwin=false;
				}
				cout<<"����С������1��\n";
			}else{
				f.pop();
				if(f.empty())
				{
					over=true;
					isuserwin=false;
				}
				f.pop();
				if(f.empty())
				{
					over=true;
					isuserwin=false;
				}
				cout<<"����С������2��\n";
			}
		}
		isuser=!isuser;
	}
	if(isuserwin){
		cout<<"��ϲ�������Ե������ϣ������80ö���ϱң�\n";
		p+=80;
	}else
		cout<<"���ź�������С��Ե������һ������\n";
	cout<<endl;	
	return p;	
}
