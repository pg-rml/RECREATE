#include "Graphic.h"

void gotoxy(int x, int y)
{
    COORD pos = { 2 * x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


void stage(int floor, int stage)
{
    int x = 20;
    int y = 4;

    gotoxy(x, y); cout << "������������������";
    gotoxy(x, y + 1); cout << "��"; gotoxy(x + 4, y + 1); cout << "��";
    gotoxy(x, y + 2); cout << "��"; gotoxy(x + 4, y + 2); cout << "��"; gotoxy(x + 5, y + 2); cout << "��������";
    gotoxy(x, y + 3); cout << "��"; gotoxy(x + 4, y + 3); cout << "��";
    gotoxy(x, y + 4); cout << "������������������";

    gotoxy(x + 7, y); cout << " ������������������";
    gotoxy(x + 7, y + 1); cout << " ��"; gotoxy(x + 11, y + 1); cout << " ��";
    gotoxy(x + 7, y + 2); cout << " ��"; gotoxy(x + 11, y + 2); cout << " ��"; gotoxy(x + 12, y + 2); cout << " ��������";
    gotoxy(x + 7, y + 3); cout << " ��"; gotoxy(x + 11, y + 3); cout << " ��";
    gotoxy(x + 7, y + 4); cout << " ������������������";

    // ���� ��ġ
    gotoxy(x + 8, y + 7); cout << "���� " << floor << "��";

    gotoxy(x + 15, y); cout << "������������������";
    gotoxy(x + 15, y + 1); cout << "��"; gotoxy(x + 19, y + 1); cout << "��";
    gotoxy(x + 15, y + 2); cout << "��"; gotoxy(x + 19, y + 2); cout << "��";
    gotoxy(x + 15, y + 3); cout << "��"; gotoxy(x + 19, y + 3); cout << "��";
    gotoxy(x + 15, y + 4); cout << "������������������";

    // ���� ��ġ Ȱ��ȭ

    switch (stage)
    {

    case 1:
        now_stage1();
        break;
    
    case 2:
        now_stage2();
        break;

    case 3:
        
        now_stage3();
        break;

    default:
        break;
    }

}

// ���� ��ġ. �ӽ÷� stage ���� �־����.
void now_stage1()
{
    int x = 21;
    int y = 4;
    // ��������1
    gotoxy(x, y + 2); cout << "\033[36m�ԡ�\033[0m";
}
void now_stage2()
{
    int x = 21;
    int y = 4;
    // ��������2
    gotoxy(x + 7, y + 2); cout << "\033[36m �ԡ�\033[0m";
}
void now_stage3()
{
    int x = 21;
    int y = 4;
    // ��������3
    gotoxy(x + 15, y + 2); cout << "\033[36m�ԡ�\033[0m";
}




// ���� ȭ�� �ƽ�Ű ��Ʈ
void start_ascii()
{
    int x = 17;
    int y = 4;

    gotoxy(x, y - 2); cout << "                  .       |         .    .";
    gotoxy(x, y - 1); cout << "            .  *         -*-          *";
    gotoxy(x, y); cout << "                 \\        |         /   .";
    gotoxy(x, y + 1); cout << ".    .            .      /^\\     .              .   ";
    gotoxy(x, y + 2); cout << "   *    |\\   /\\    /\\  / / \\ \\  /\\    /\\   /|    *";
    gotoxy(x, y + 3); cout << " .   .  |  \\ \\/ /\\ \\ / /     \\ \\ / /\\ \\/ /  | .     ";
    gotoxy(x, y + 4); cout << "         \\ | _ _\\/_ _ \\_\\_ _ /_/_ _\\/_ _ \\_/";
    gotoxy(x, y + 5); cout << "           \\  *  *  *   \\ \\/ /  *  *  *  /";
    gotoxy(x, y + 6); cout << "            ` ~ ~ ~ ~ ~  ~\\/~ ~ ~ ~ ~ ~ '";
}


// Ʋ
void frame()
{
    int x = 0;
    int y = 13;
    int z = 32;
    int q = 59;
    gotoxy(x, x); cout << "����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������";
    gotoxy(y + 3, x); cout << "��"; gotoxy(q - 16, x); cout << "��";
    gotoxy(x, x + 1); cout << "��"; gotoxy(y + 3, x + 1); cout << "��"; gotoxy(q - 16, x + 1); cout << "��"; gotoxy(q, x + 1); cout << "��";
    gotoxy(x, x + 2); cout << "��"; gotoxy(y + 3, x + 2); cout << "��"; gotoxy(q - 16, x + 2); cout << "��"; gotoxy(q, x + 2); cout << "��";
    gotoxy(x, x + 3); cout << "��"; gotoxy(y + 3, x + 3); cout << "��"; gotoxy(q - 16, x + 3); cout << "��"; gotoxy(q, x + 3); cout << "��";
    gotoxy(x, x + 4); cout << "��"; gotoxy(y + 3, x + 4); cout << "��"; gotoxy(q - 16, x + 4); cout << "��"; gotoxy(q, x + 4); cout << "��";
    gotoxy(x, x + 5); cout << "��"; gotoxy(y + 3, x + 5); cout << "��"; gotoxy(q - 16, x + 5); cout << "��"; gotoxy(q, x + 5); cout << "��";
    gotoxy(x, x + 6); cout << "��"; gotoxy(y + 3, x + 6); cout << "��"; gotoxy(q - 16, x + 6); cout << "��"; gotoxy(q, x + 6); cout << "��";
    gotoxy(x, x + 7); cout << "��"; gotoxy(y + 3, x + 7); cout << "��"; gotoxy(q - 16, x + 7); cout << "��"; gotoxy(q, x + 7); cout << "��";
    gotoxy(x, x + 8); cout << "��"; gotoxy(y + 3, x + 8); cout << "��"; gotoxy(q - 16, x + 8); cout << "��"; gotoxy(q, x + 8); cout << "��";
    gotoxy(x, x + 9); cout << "��"; gotoxy(y + 3, x + 9); cout << "��"; gotoxy(q - 16, x + 9); cout << "��"; gotoxy(q, x + 9); cout << "��";
    gotoxy(x, x + 10); cout << "��"; gotoxy(y + 3, x + 10); cout << "��"; gotoxy(q - 16, x + 10); cout << "��"; gotoxy(q, x + 10); cout << "��";
    gotoxy(x, x + 11); cout << "��"; gotoxy(y + 3, x + 11); cout << "��"; gotoxy(q - 16, x + 11); cout << "��"; gotoxy(q, x + 11); cout << "��";
    gotoxy(x, x + 12); cout << "��"; gotoxy(y + 3, x + 12); cout << "��"; gotoxy(q - 16, x + 12); cout << "��"; gotoxy(q, x + 12); cout << "��";
    gotoxy(x, y); cout << "����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������";
    gotoxy(y + 3, y); cout << "��"; gotoxy(q - 16, y); cout << "��";
    gotoxy(x, y + 1); cout << "��"; gotoxy(q, y + 1); cout << "��";
    gotoxy(x, y + 2); cout << "��"; gotoxy(q, y + 2); cout << "��";
    gotoxy(x, y + 3); cout << "��"; gotoxy(q, y + 3); cout << "��";
    gotoxy(x, y + 4); cout << "��"; gotoxy(q, y + 4); cout << "��";
    gotoxy(x, y + 5); cout << "��"; gotoxy(q, y + 5); cout << "��";
    gotoxy(x, y + 6); cout << "��"; gotoxy(q, y + 6); cout << "��";
    gotoxy(x, y + 7); cout << "��"; gotoxy(q, y + 7); cout << "��";
    gotoxy(x, y + 8); cout << "��"; gotoxy(q, y + 8); cout << "��";
    gotoxy(x, y + 9); cout << "��"; gotoxy(q, y + 9); cout << "��";
    gotoxy(x, y + 10); cout << "��"; gotoxy(q, y + 10); cout << "��";
    gotoxy(x, y + 11); cout << "��"; gotoxy(q, y + 11); cout << "��";
    gotoxy(x, y + 12); cout << "��"; gotoxy(q, y + 12); cout << "��";
    gotoxy(x, y + 13); cout << "��"; gotoxy(q, y + 13); cout << "��";
    gotoxy(x, y + 14); cout << "��"; gotoxy(q, y + 14); cout << "��";
    gotoxy(x, y + 15); cout << "��"; gotoxy(q, y + 15); cout << "��";
    gotoxy(x, y + 16); cout << "��"; gotoxy(q, y + 16); cout << "��";
    gotoxy(x, y + 17); cout << "��"; gotoxy(q, y + 17); cout << "��";
    gotoxy(x, y + 18); cout << "��"; gotoxy(q, y + 18); cout << "��";
    gotoxy(x, z); cout << "����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������";
    gotoxy(x, z + 1); cout << "��"; gotoxy(q, z + 1); cout << "��";
    gotoxy(x, z + 2); cout << "��"; gotoxy(q, z + 2); cout << "��";
    gotoxy(x, z + 3); cout << "��"; gotoxy(q, z + 3); cout << "��";
    gotoxy(x, z + 4); cout << "��"; gotoxy(q, z + 4); cout << "��";
    gotoxy(x, z + 5); cout << "��"; gotoxy(q, z + 5); cout << "��";
    gotoxy(x, z + 6); cout << "��"; gotoxy(q, z + 6); cout << "��";
    gotoxy(x, z + 7); cout << "��"; gotoxy(q, z + 7); cout << "��";
    gotoxy(x, z + 8); cout << "��"; gotoxy(q, z + 8); cout << "��";
    gotoxy(x, z + 9); cout << "����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������";

}

// �⺻ ������
void basic_choice()
{
    int x = 1;
    int y = 34;
    gotoxy(x, y); cout << "�� \033[94m����â \033[90m(1)\033[0m�� " << "�� \033[94m��ų \033[90m(2)\033[0m�� ";
    gotoxy(x, y + 2); cout << " Enter Number: " << endl;
}

// ��ܿ� ������ PC ����â
void PC1_info()
{
    int x = 1;
    int y = 0;
    gotoxy(x, y + 1); cout << "[������]"; // ���������ؼ�...������ Ŭ���� ������? �ϱ�?
    gotoxy(x, y + 2); cout << "HP: 97 / 100"; // �̰͵� �������ؼ�..
    gotoxy(x, y + 3); cout << "�ൿ��: 10"; // �̰͵�..

    // �����̻� ǥ��
    // ���� �̻� ���� �� �ȶ߸� ���پ��
    gotoxy(x + 4, y + 1); cout << "(�����̻�)"; // ��ȣ �ȿ� �����̻� ����
}
void PC2_info()
{
    int x = 1;
    int y = 4;
    gotoxy(x, y + 1); cout << "[�뺴]";
    gotoxy(x, y + 2); cout << "HP: 97 / 100";
    gotoxy(x, y + 3); cout << "�ൿ��: 10";

    // �����̻� ǥ��
    gotoxy(x + 4, y + 1); cout << "(�ߵ�)";
}
void PC3_info()
{
    int x = 1;
    int y = 8;
    gotoxy(x, y + 1); cout << "[ġ����]";
    gotoxy(x, y + 2); cout << "HP: 70 / 80";
    gotoxy(x, y + 3); cout << "�ൿ��: 10";

    // �����̻� ǥ��
    gotoxy(x + 4, y + 1); cout << "(����)";
}

// ��ܿ� ������ �� ����â
void enemy1_info()
{
    int x = 44;
    int y = 0;
    gotoxy(x, y + 1); cout << "[����]";
    gotoxy(x, y + 2); cout << "HP: 200";

    // �����̻� ǥ��
    gotoxy(x + 4, y + 1); cout << "(�����̻�)";
}
void enemy2_info()
{
    int x = 44;
    int y = 4;
    gotoxy(x, y + 1); cout << "[����]";
    gotoxy(x, y + 2); cout << "HP: 200";

    // �����̻� ǥ��
    gotoxy(x + 4, y + 1); cout << "(�����̻�)";
}
void enemy3_info()
{
    int x = 44;
    int y = 8;
    gotoxy(x, y + 1); cout << "[����]";
    gotoxy(x, y + 2); cout << "HP: 200";

    // �����̻� ǥ��
    gotoxy(x + 4, y + 1); cout << "(�����̻�)";
}

// ��� ���
void dialogue()
{
    int x = 1;
    int y = 12;

    // ��ų ��� ����� ��ų ������ ������� ��� �����ұ��?
    gotoxy(x, y + 2); cout << "\033[33m����! \033[0m";
    gotoxy(x, y + 3); cout << "������" << "(��)�� " << "���� ������ �̸� ����Ͽ� ��� �ڼ��� ���մϴ�.";

    gotoxy(x, y + 5); cout << "\033[33mġ��! \033[0m";
    gotoxy(x, y + 6); cout << "ġ����" << "(��)�� " << "ġ���� �������� �̿��Ͽ� �뺴�� ȸ���մϴ�.";

    gotoxy(x, y + 8); cout << "\033[33m���! \033[0m";
    gotoxy(x, y + 9); cout << "�뺴" << "(��)�� " << "��ī�ο� �˱�� ����1�� ������ ��ϴ�.";

    // PC�� ��ų ��� ��� ����, ��� ���
    gotoxy(x, y + 11); cout << "\033[34m�����ڰ� ��� �ڼ��� ���Ѵ�.\033[0m";
    gotoxy(x, y + 12); cout << "> �������� HP: 97 / 150"; // [�������]�� HP: (����ü��) / (�ִ�ü��) 

    gotoxy(x, y + 14); cout << "\033[96mġ���簡 �뺴�� 15 ��ŭ ġ���ߴ�.\033[0m";
    gotoxy(x, y + 15); cout << "> �뺴�� HP: 97 / 100"; // [������]�� HP: (����ü��) / (�ִ�ü��) 

    gotoxy(x, y + 17); cout << "\033[31m�뺴�� ����1���� 25 ��ŭ�� ���ظ� ������!\033[0m"; // [PC]�� [�� �̸�]���� [������] ��ŭ�� ���ظ� ������!
    gotoxy(x, y + 18); cout << "> ����1�� HP: 154 / 200"; // [��]�� HP: (����ü��) / (�ִ�ü��)
}

void class_choice() {
    
    int x = 3;
    int y = 14;
    gotoxy(x - 3, y - 1); cout << "����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������";


    //ī��2
    gotoxy(x + 15, y + 1); cout << "< 1 >";
    gotoxy(x + 11, y + 2); cout << "�������������������������������������� ";
    gotoxy(x + 11, y + 3); cout << "��"; gotoxy(x + 20, y + 3); cout << "��"; gotoxy(x + 13, y + 3); cout << "    �뺴    ";
    gotoxy(x + 11, y + 4); cout << "��"; gotoxy(x + 20, y + 4); cout << "��";
    gotoxy(x + 11, y + 5); cout << "��"; gotoxy(x + 20, y + 5); cout << "��";
    gotoxy(x + 11, y + 6); cout << "��"; gotoxy(x + 20, y + 6); cout << "��";
    gotoxy(x + 11, y + 7); cout << "��"; gotoxy(x + 20, y + 7); cout << "��";
    gotoxy(x + 11, y + 8); cout << "��"; gotoxy(x + 20, y + 8); cout << "��";
    gotoxy(x + 11, y + 9); cout << "��"; gotoxy(x + 20, y + 9); cout << "��";
    gotoxy(x + 11, y + 10); cout << "��"; gotoxy(x + 20, y + 10); cout << "��";
    gotoxy(x + 11, y + 11); cout << "��"; gotoxy(x + 20, y + 11); cout << "��";
    gotoxy(x + 11, y + 12); cout << "��"; gotoxy(x + 20, y + 12); cout << "��";
    gotoxy(x + 11, y + 13); cout << "��"; gotoxy(x + 20, y + 13); cout << "��";
    gotoxy(x + 11, y + 14); cout << "��"; gotoxy(x + 20, y + 14); cout << "��";
    gotoxy(x + 11, y + 15); cout << "��"; gotoxy(x + 20, y + 15); cout << "��";
    gotoxy(x + 11, y + 16); cout << "��"; gotoxy(x + 20, y + 16); cout << "��"; 
    gotoxy(x + 11, y + 17); cout << "��������������������������������������";

    //ī��3
    gotoxy(x + 26, y + 1); cout << "< 2 >";
    gotoxy(x + 22, y + 2); cout << "�������������������������������������� ";
    gotoxy(x + 22, y + 3); cout << "��"; gotoxy(x + 31, y + 3); cout << "��"; gotoxy(x + 24, y + 3); cout << "   ġ����   ";
    gotoxy(x + 22, y + 4); cout << "��"; gotoxy(x + 31, y + 4); cout << "��";
    gotoxy(x + 22, y + 5); cout << "��"; gotoxy(x + 31, y + 5); cout << "��";
    gotoxy(x + 22, y + 6); cout << "��"; gotoxy(x + 31, y + 6); cout << "��";
    gotoxy(x + 22, y + 7); cout << "��"; gotoxy(x + 31, y + 7); cout << "��";
    gotoxy(x + 22, y + 8); cout << "��"; gotoxy(x + 31, y + 8); cout << "��";
    gotoxy(x + 22, y + 9); cout << "��"; gotoxy(x + 31, y + 9); cout << "��";
    gotoxy(x + 22, y + 10); cout << "��"; gotoxy(x + 31, y + 10); cout << "��";
    gotoxy(x + 22, y + 11); cout << "��"; gotoxy(x + 31, y + 11); cout << "��";
    gotoxy(x + 22, y + 12); cout << "��"; gotoxy(x + 31, y + 12); cout << "��";
    gotoxy(x + 22, y + 13); cout << "��"; gotoxy(x + 31, y + 13); cout << "��";
    gotoxy(x + 22, y + 14); cout << "��"; gotoxy(x + 31, y + 14); cout << "��";
    gotoxy(x + 22, y + 15); cout << "��"; gotoxy(x + 31, y + 15); cout << "��";
    gotoxy(x + 22, y + 16); cout << "��"; gotoxy(x + 31, y + 16); cout << "��"; 
    gotoxy(x + 22, y + 17); cout << "��������������������������������������";

    //ī��4
    gotoxy(x + 37, y + 1); cout << "< 3 >";
    gotoxy(x + 33, y + 2); cout << "�������������������������������������� ";
    gotoxy(x + 33, y + 3); cout << "��"; gotoxy(x + 42, y + 3); cout << "��"; gotoxy(x + 35, y + 3); cout << "   ������   ";
    gotoxy(x + 33, y + 4); cout << "��"; gotoxy(x + 42, y + 4); cout << "��";
    gotoxy(x + 33, y + 5); cout << "��"; gotoxy(x + 42, y + 5); cout << "��";
    gotoxy(x + 33, y + 6); cout << "��"; gotoxy(x + 42, y + 6); cout << "��";
    gotoxy(x + 33, y + 7); cout << "��"; gotoxy(x + 42, y + 7); cout << "��";
    gotoxy(x + 33, y + 8); cout << "��"; gotoxy(x + 42, y + 8); cout << "��";
    gotoxy(x + 33, y + 9); cout << "��"; gotoxy(x + 42, y + 9); cout << "��";
    gotoxy(x + 33, y + 10); cout << "��"; gotoxy(x + 42, y + 10); cout << "��";
    gotoxy(x + 33, y + 11); cout << "��"; gotoxy(x + 42, y + 11); cout << "��";
    gotoxy(x + 33, y + 12); cout << "��"; gotoxy(x + 42, y + 12); cout << "��";
    gotoxy(x + 33, y + 13); cout << "��"; gotoxy(x + 42, y + 13); cout << "��";
    gotoxy(x + 33, y + 14); cout << "��"; gotoxy(x + 42, y + 14); cout << "��";
    gotoxy(x + 33, y + 15); cout << "��"; gotoxy(x + 42, y + 15); cout << "��";
    gotoxy(x + 33, y + 16); cout << "��"; gotoxy(x + 42, y + 16); cout << "��"; 
    gotoxy(x + 33, y + 17); cout << "��������������������������������������";


    //skil_input();

    skil_dealer(1);
    skil_healer(2);
    skil_tanker(3);
}

void class_chosen(int i) {

    system("cls");
    frame();
    start_ascii();

    int x = 3;
    int y = 14;
    gotoxy(x - 3, y - 1); cout << "����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������";



    //ī��3
    gotoxy(x + 22, y + 2); cout << "�������������������������������������� ";
    gotoxy(x + 22, y + 3); cout << "��"; gotoxy(x + 31, y + 3); cout << "��"; 
    gotoxy(x + 22, y + 4); cout << "��"; gotoxy(x + 31, y + 4); cout << "��";
    gotoxy(x + 22, y + 5); cout << "��"; gotoxy(x + 31, y + 5); cout << "��";
    gotoxy(x + 22, y + 6); cout << "��"; gotoxy(x + 31, y + 6); cout << "��";
    gotoxy(x + 22, y + 7); cout << "��"; gotoxy(x + 31, y + 7); cout << "��";
    gotoxy(x + 22, y + 8); cout << "��"; gotoxy(x + 31, y + 8); cout << "��";
    gotoxy(x + 22, y + 9); cout << "��"; gotoxy(x + 31, y + 9); cout << "��";
    gotoxy(x + 22, y + 10); cout << "��"; gotoxy(x + 31, y + 10); cout << "��";
    gotoxy(x + 22, y + 11); cout << "��"; gotoxy(x + 31, y + 11); cout << "��";
    gotoxy(x + 22, y + 12); cout << "��"; gotoxy(x + 31, y + 12); cout << "��";
    gotoxy(x + 22, y + 13); cout << "��"; gotoxy(x + 31, y + 13); cout << "��";
    gotoxy(x + 22, y + 14); cout << "��"; gotoxy(x + 31, y + 14); cout << "��";
    gotoxy(x + 22, y + 15); cout << "��"; gotoxy(x + 31, y + 15); cout << "��";
    gotoxy(x + 22, y + 16); cout << "��"; gotoxy(x + 31, y + 16); cout << "��"; 
    gotoxy(x + 22, y + 17); cout << "��������������������������������������";


    //skil_input();
    switch (i) {
    case '1':
        gotoxy(x + 25, y + 3); cout << " �뺴";
        skil_dealer(2);
        break;
    case '2':
        gotoxy(x + 25, y + 3); cout << " ġ����";
        skil_healer(2);
        break;
    case '3':
        gotoxy(x + 25, y + 3); cout << " ������";
        skil_tanker(2);
        break;
    default:
        break;
    }
    
}

// ��ų ���� �� �����ϴ� ī��
void skil_choice(int i, string skillname, int act)
{
    string blank = "                ";
    size_t middle = blank.size() / 2; // �߾� ��ġ ���
    std::string blankname = blank; // ���� ���ڿ� ����

    // �߾� ��ġ�� ���ڿ� ����
    blankname.insert(middle, skillname);

    int originalLength = blankname.length();

    int length = 12;

    std::string name;
    if (length >= originalLength) {
        name = blankname;
    }
    else {
        // �߾� ��ġ ���
        int start = (originalLength - length) / 2;

        // �߾� �κ� �ڸ���
        name = blankname.substr(start, length);
    }
    int x = 3;
    int y = 14;
    gotoxy(x - 3, y - 1); cout << "����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������";

    // ī��1
    if (i == 0) {
        gotoxy(x + 4, y + 1); cout << "< 1 >";
        gotoxy(x, y + 2); cout << "�������������������������������������� ";
        gotoxy(x, y + 3); cout << "��"; gotoxy(x + 9, y + 3); cout << "��"; gotoxy(x + 2, y + 3); cout << name << "  ";
        gotoxy(x, y + 4); cout << "��"; gotoxy(x + 9, y + 4); cout << "��";
        gotoxy(x, y + 5); cout << "��"; gotoxy(x + 9, y + 5); cout << "��";
        gotoxy(x, y + 6); cout << "��"; gotoxy(x + 9, y + 6); cout << "��";
        gotoxy(x, y + 7); cout << "��"; gotoxy(x + 9, y + 7); cout << "��";
        gotoxy(x, y + 8); cout << "��"; gotoxy(x + 9, y + 8); cout << "��";
        gotoxy(x, y + 9); cout << "��"; gotoxy(x + 9, y + 9); cout << "��";
        gotoxy(x, y + 10); cout << "��"; gotoxy(x + 9, y + 10); cout << "��";
        gotoxy(x, y + 11); cout << "��"; gotoxy(x + 9, y + 11); cout << "��";
        gotoxy(x, y + 12); cout << "��"; gotoxy(x + 9, y + 12); cout << "��";
        gotoxy(x, y + 13); cout << "��"; gotoxy(x + 9, y + 13); cout << "��";
        gotoxy(x, y + 14); cout << "��"; gotoxy(x + 9, y + 14); cout << "��";
        gotoxy(x, y + 15); cout << "��"; gotoxy(x + 9, y + 15); cout << "��";
        gotoxy(x, y + 16); cout << "��"; gotoxy(x + 9, y + 16); cout << "��"; gotoxy(x + 5, y + 16); cout << "\033[33m" << act <<"\033[0m"; // �ൿ��
        gotoxy(x, y + 17); cout << "��������������������������������������";
    }

    
    //ī��2
    else if (i == 1) {
        gotoxy(x + 15, y + 1); cout << "< 2 >";
        gotoxy(x + 11, y + 2); cout << "�������������������������������������� ";
        gotoxy(x + 11, y + 3); cout << "��"; gotoxy(x + 20, y + 3); cout << "��"; gotoxy(x + 13, y + 3); cout << name << "  ";
        gotoxy(x + 11, y + 4); cout << "��"; gotoxy(x + 20, y + 4); cout << "��";
        gotoxy(x + 11, y + 5); cout << "��"; gotoxy(x + 20, y + 5); cout << "��";
        gotoxy(x + 11, y + 6); cout << "��"; gotoxy(x + 20, y + 6); cout << "��";
        gotoxy(x + 11, y + 7); cout << "��"; gotoxy(x + 20, y + 7); cout << "��";
        gotoxy(x + 11, y + 8); cout << "��"; gotoxy(x + 20, y + 8); cout << "��";
        gotoxy(x + 11, y + 9); cout << "��"; gotoxy(x + 20, y + 9); cout << "��";
        gotoxy(x + 11, y + 10); cout << "��"; gotoxy(x + 20, y + 10); cout << "��";
        gotoxy(x + 11, y + 11); cout << "��"; gotoxy(x + 20, y + 11); cout << "��";
        gotoxy(x + 11, y + 12); cout << "��"; gotoxy(x + 20, y + 12); cout << "��";
        gotoxy(x + 11, y + 13); cout << "��"; gotoxy(x + 20, y + 13); cout << "��";
        gotoxy(x + 11, y + 14); cout << "��"; gotoxy(x + 20, y + 14); cout << "��";
        gotoxy(x + 11, y + 15); cout << "��"; gotoxy(x + 20, y + 15); cout << "��";
        gotoxy(x + 11, y + 16); cout << "��"; gotoxy(x + 20, y + 16); cout << "��"; gotoxy(x + 16, y + 16); cout << "\033[33m" << act << "\033[0m";
        gotoxy(x + 11, y + 17); cout << "��������������������������������������";
    }

    
    
    //ī��3
    else if (i == 2) {
        gotoxy(x + 26, y + 1); cout << "< 3 >";
        gotoxy(x + 22, y + 2); cout << "�������������������������������������� ";
        gotoxy(x + 22, y + 3); cout << "��"; gotoxy(x + 31, y + 3); cout << "��"; gotoxy(x + 24, y + 3); cout << name << "  ";
        gotoxy(x + 22, y + 4); cout << "��"; gotoxy(x + 31, y + 4); cout << "��";
        gotoxy(x + 22, y + 5); cout << "��"; gotoxy(x + 31, y + 5); cout << "��";
        gotoxy(x + 22, y + 6); cout << "��"; gotoxy(x + 31, y + 6); cout << "��";
        gotoxy(x + 22, y + 7); cout << "��"; gotoxy(x + 31, y + 7); cout << "��";
        gotoxy(x + 22, y + 8); cout << "��"; gotoxy(x + 31, y + 8); cout << "��";
        gotoxy(x + 22, y + 9); cout << "��"; gotoxy(x + 31, y + 9); cout << "��";
        gotoxy(x + 22, y + 10); cout << "��"; gotoxy(x + 31, y + 10); cout << "��";
        gotoxy(x + 22, y + 11); cout << "��"; gotoxy(x + 31, y + 11); cout << "��";
        gotoxy(x + 22, y + 12); cout << "��"; gotoxy(x + 31, y + 12); cout << "��";
        gotoxy(x + 22, y + 13); cout << "��"; gotoxy(x + 31, y + 13); cout << "��";
        gotoxy(x + 22, y + 14); cout << "��"; gotoxy(x + 31, y + 14); cout << "��";
        gotoxy(x + 22, y + 15); cout << "��"; gotoxy(x + 31, y + 15); cout << "��";
        gotoxy(x + 22, y + 16); cout << "��"; gotoxy(x + 31, y + 16); cout << "��"; gotoxy(x + 27, y + 16); cout << "\033[33m" << act << "\033[0m";
        gotoxy(x + 22, y + 17); cout << "��������������������������������������";
    }
    

    //ī��4
    else if (i == 3) {
        gotoxy(x + 37, y + 1); cout << "< 4 >";
        gotoxy(x + 33, y + 2); cout << "�������������������������������������� ";
        gotoxy(x + 33, y + 3); cout << "��"; gotoxy(x + 42, y + 3); cout << "��"; gotoxy(x + 35, y + 3); cout << name << "  ";
        gotoxy(x + 33, y + 4); cout << "��"; gotoxy(x + 42, y + 4); cout << "��";
        gotoxy(x + 33, y + 5); cout << "��"; gotoxy(x + 42, y + 5); cout << "��";
        gotoxy(x + 33, y + 6); cout << "��"; gotoxy(x + 42, y + 6); cout << "��";
        gotoxy(x + 33, y + 7); cout << "��"; gotoxy(x + 42, y + 7); cout << "��";
        gotoxy(x + 33, y + 8); cout << "��"; gotoxy(x + 42, y + 8); cout << "��";
        gotoxy(x + 33, y + 9); cout << "��"; gotoxy(x + 42, y + 9); cout << "��";
        gotoxy(x + 33, y + 10); cout << "��"; gotoxy(x + 42, y + 10); cout << "��";
        gotoxy(x + 33, y + 11); cout << "��"; gotoxy(x + 42, y + 11); cout << "��";
        gotoxy(x + 33, y + 12); cout << "��"; gotoxy(x + 42, y + 12); cout << "��";
        gotoxy(x + 33, y + 13); cout << "��"; gotoxy(x + 42, y + 13); cout << "��";
        gotoxy(x + 33, y + 14); cout << "��"; gotoxy(x + 42, y + 14); cout << "��";
        gotoxy(x + 33, y + 15); cout << "��"; gotoxy(x + 42, y + 15); cout << "��";
        gotoxy(x + 33, y + 16); cout << "��"; gotoxy(x + 42, y + 16); cout << "��"; gotoxy(x + 38, y + 16); cout << "\033[33m" << act << "\033[0m";
        gotoxy(x + 33, y + 17); cout << "��������������������������������������";
    }
    

    //ī��5
    else if (i == 4) {
        gotoxy(x + 48, y + 1); cout << "< 5 >";
        gotoxy(x + 44, y + 2); cout << "�������������������������������������� ";
        gotoxy(x + 44, y + 3); cout << "��"; gotoxy(x + 53, y + 3); cout << "��"; gotoxy(x + 46, y + 3); cout << name << "  ";
        gotoxy(x + 44, y + 4); cout << "��"; gotoxy(x + 53, y + 4); cout << "��";
        gotoxy(x + 44, y + 5); cout << "��"; gotoxy(x + 53, y + 5); cout << "��";
        gotoxy(x + 44, y + 6); cout << "��"; gotoxy(x + 53, y + 6); cout << "��";
        gotoxy(x + 44, y + 7); cout << "��"; gotoxy(x + 53, y + 7); cout << "��";
        gotoxy(x + 44, y + 8); cout << "��"; gotoxy(x + 53, y + 8); cout << "��";
        gotoxy(x + 44, y + 9); cout << "��"; gotoxy(x + 53, y + 9); cout << "��";
        gotoxy(x + 44, y + 10); cout << "��"; gotoxy(x + 53, y + 10); cout << "��";
        gotoxy(x + 44, y + 11); cout << "��"; gotoxy(x + 53, y + 11); cout << "��";
        gotoxy(x + 44, y + 12); cout << "��"; gotoxy(x + 53, y + 12); cout << "��";
        gotoxy(x + 44, y + 13); cout << "��"; gotoxy(x + 53, y + 13); cout << "��";
        gotoxy(x + 44, y + 14); cout << "��"; gotoxy(x + 53, y + 14); cout << "��";
        gotoxy(x + 44, y + 15); cout << "��"; gotoxy(x + 53, y + 15); cout << "��";
        gotoxy(x + 44, y + 16); cout << "��"; gotoxy(x + 53, y + 16); cout << "��"; gotoxy(x + 49, y + 16); cout << "\033[33m" << act << "\033[0m";
        gotoxy(x + 44, y + 17); cout << "��������������������������������������";
    }
    
    //skil_input();

    //skil_tanker();
    //skil_dealer();
    //skil_healer();
}

// ��ų ���� �� ī�忡 ��µǴ� �׷���. �ӽ÷� skil_choice �ȿ� �־����.
void skil_tanker(int i)
{
    int x = 2;
    int y = 15;

    //ī��1
    if (i == 0) {
        gotoxy(x + 2, y + 5); cout << "\033[34m  |`-._/\\_.-`|";
        gotoxy(x + 2, y + 6); cout << "  |    ||    |";
        gotoxy(x + 2, y + 7); cout << "  |___o()o___|";
        gotoxy(x + 2, y + 8); cout << "  |__((<>))__|";
        gotoxy(x + 2, y + 9); cout << "  \\   o\\/o   /";
        gotoxy(x + 2, y + 10); cout << "   \\   ||   /";
        gotoxy(x + 2, y + 11); cout << "    \\  ||  /";
        gotoxy(x + 2, y + 12); cout << "     '.||.'";
        gotoxy(x + 2, y + 13); cout << "       ``\033[0m";
    }
    

    //ī��2
    else if (i == 1) {
        
        gotoxy(x + 13, y + 5); cout << "\033[34m  |`-._/\\_.-`|";
        gotoxy(x + 13, y + 6); cout << "  |    ||    |";
        gotoxy(x + 13, y + 7); cout << "  |___o()o___|";
        gotoxy(x + 13, y + 8); cout << "  |__((<>))__|";
        gotoxy(x + 13, y + 9); cout << "  \\   o\\/o   /";
        gotoxy(x + 13, y + 10); cout << "   \\   ||   /";
        gotoxy(x + 13, y + 11); cout << "    \\  ||  /";
        gotoxy(x + 13, y + 12); cout << "     '.||.'";
        gotoxy(x + 13, y + 13); cout << "       ``\033[0m";
    }

    //ī��3
    else if (i == 2) {
        
        gotoxy(x + 24, y + 5); cout << "\033[34m  |`-._/\\_.-`|";
        gotoxy(x + 24, y + 6); cout << "  |    ||    |";
        gotoxy(x + 24, y + 7); cout << "  |___o()o___|";
        gotoxy(x + 24, y + 8); cout << "  |__((<>))__|";
        gotoxy(x + 24, y + 9); cout << "  \\   o\\/o   /";
        gotoxy(x + 24, y + 10); cout << "   \\   ||   /";
        gotoxy(x + 24, y + 11); cout << "    \\  ||  /";
        gotoxy(x + 24, y + 12); cout << "     '.||.'";
        gotoxy(x + 24, y + 13); cout << "       ``\033[0m";
    }

    //ī��4
    else if (i == 3) {
        
        gotoxy(x + 35, y + 5); cout << "\033[34m  |`-._/\\_.-`|";
        gotoxy(x + 35, y + 6); cout << "  |    ||    |";
        gotoxy(x + 35, y + 7); cout << "  |___o()o___|";
        gotoxy(x + 35, y + 8); cout << "  |__((<>))__|";
        gotoxy(x + 35, y + 9); cout << "  \\   o\\/o   /";
        gotoxy(x + 35, y + 10); cout << "   \\   ||   /";
        gotoxy(x + 35, y + 11); cout << "    \\  ||  /";
        gotoxy(x + 35, y + 12); cout << "     '.||.'";
        gotoxy(x + 35, y + 13); cout << "       ``\033[0m";
    }

    //ī��5
    else if (i == 4) {
        
        gotoxy(x + 46, y + 5); cout << "\033[34m  |`-._/\\_.-`|";
        gotoxy(x + 46, y + 6); cout << "  |    ||    |";
        gotoxy(x + 46, y + 7); cout << "  |___o()o___|";
        gotoxy(x + 46, y + 8); cout << "  |__((<>))__|";
        gotoxy(x + 46, y + 9); cout << "  \\   o\\/o   /";
        gotoxy(x + 46, y + 10); cout << "   \\   ||   /";
        gotoxy(x + 46, y + 11); cout << "    \\  ||  /";
        gotoxy(x + 46, y + 12); cout << "     '.||.'";
        gotoxy(x + 46, y + 13); cout << "       ``\033[0m";
    }
    


}
void skil_dealer(int i)
{
    int x = 3;
    int y = 14;

    //ī��1
    if (i == 0) {
        
        gotoxy(x + 2, y + 5); cout << "\033[31m     /\\";
        gotoxy(x + 2, y + 6); cout << "    // \\";
        gotoxy(x + 2, y + 7); cout << "    || |";
        gotoxy(x + 2, y + 8); cout << "    || |";
        gotoxy(x + 2, y + 9); cout << "    || |";
        gotoxy(x + 2, y + 10); cout << " __ || | __";
        gotoxy(x + 2, y + 11); cout << "/___||_|___\\";
        gotoxy(x + 2, y + 12); cout << "    _MM_";
        gotoxy(x + 2, y + 13); cout << "   (&<>&)";
        gotoxy(x + 2, y + 14); cout << "    ~~~~\033[0m";
    }

    //ī��2
    else if (i == 1) {
        
        gotoxy(x + 13, y + 5); cout << "\033[31m     /\\";
        gotoxy(x + 13, y + 6); cout << "    // \\";
        gotoxy(x + 13, y + 7); cout << "    || |";
        gotoxy(x + 13, y + 8); cout << "    || |";
        gotoxy(x + 13, y + 9); cout << "    || |";
        gotoxy(x + 13, y + 10); cout << " __ || | __";
        gotoxy(x + 13, y + 11); cout << "/___||_|___\\";
        gotoxy(x + 13, y + 12); cout << "    _MM_";
        gotoxy(x + 13, y + 13); cout << "   (&<>&)";
        gotoxy(x + 13, y + 14); cout << "    ~~~~\033[0m";
    }

    //ī��3
    else if (i == 2) {
        
        gotoxy(x + 24, y + 5); cout << "\033[31m     /\\";
        gotoxy(x + 24, y + 6); cout << "    // \\";
        gotoxy(x + 24, y + 7); cout << "    || |";
        gotoxy(x + 24, y + 8); cout << "    || |";
        gotoxy(x + 24, y + 9); cout << "    || |";
        gotoxy(x + 24, y + 10); cout << " __ || | __";
        gotoxy(x + 24, y + 11); cout << "/___||_|___\\";
        gotoxy(x + 24, y + 12); cout << "    _MM_";
        gotoxy(x + 24, y + 13); cout << "   (&<>&)";
        gotoxy(x + 24, y + 14); cout << "    ~~~~\033[0m";
    }


    //ī��4
    else if (i == 3) {
        
        gotoxy(x + 35, y + 5); cout << "\033[31m     /\\";
        gotoxy(x + 35, y + 6); cout << "    // \\";
        gotoxy(x + 35, y + 7); cout << "    || |";
        gotoxy(x + 35, y + 8); cout << "    || |";
        gotoxy(x + 35, y + 9); cout << "    || |";
        gotoxy(x + 35, y + 10); cout << " __ || | __";
        gotoxy(x + 35, y + 11); cout << "/___||_|___\\";
        gotoxy(x + 35, y + 12); cout << "    _MM_";
        gotoxy(x + 35, y + 13); cout << "   (&<>&)";
        gotoxy(x + 35, y + 14); cout << "    ~~~~\033[0m";

    }

    //ī��5
    else if (i == 4) {
        
        gotoxy(x + 46, y + 5); cout << "\033[31m     /\\";
        gotoxy(x + 46, y + 6); cout << "    // \\";
        gotoxy(x + 46, y + 7); cout << "    || |";
        gotoxy(x + 46, y + 8); cout << "    || |";
        gotoxy(x + 46, y + 9); cout << "    || |";
        gotoxy(x + 46, y + 10); cout << " __ || | __";
        gotoxy(x + 46, y + 11); cout << "/___||_|___\\";
        gotoxy(x + 46, y + 12); cout << "    _MM_";
        gotoxy(x + 46, y + 13); cout << "   (&<>&)";
        gotoxy(x + 46, y + 14); cout << "    ~~~~\033[0m";
    }


    
    
}

void skil_healer(int i)
{
    int x = 3;
    int y = 14;


    //ī��1
    if (i == 0) {
        
        gotoxy(x + 2, y + 5); cout << "\033[96m (`-._o_.-')";
        gotoxy(x + 2, y + 6); cout << "  (`- | -')";
        gotoxy(x + 2, y + 7); cout << "   `-.|.-'";
        gotoxy(x + 2, y + 8); cout << "     o|o ";
        gotoxy(x + 2, y + 9); cout << "    ( | )";
        gotoxy(x + 2, y + 10); cout << "     `!'";
        gotoxy(x + 2, y + 11); cout << "     (|)";
        gotoxy(x + 2, y + 12); cout << "      X";
        gotoxy(x + 2, y + 13); cout << "     (|)";
        gotoxy(x + 2, y + 14); cout << "     '|`\033[0m";
    }

    //ī��2
    else if (i == 1) {
        
        gotoxy(x + 13, y + 5); cout << "\033[96m (`-._o_.-')";
        gotoxy(x + 13, y + 6); cout << "  (`- | -')";
        gotoxy(x + 13, y + 7); cout << "   `-.|.-'";
        gotoxy(x + 13, y + 8); cout << "     o|o";
        gotoxy(x + 13, y + 9); cout << "    ( | )";
        gotoxy(x + 13, y + 10); cout << "     `!'";
        gotoxy(x + 13, y + 11); cout << "     (|)";
        gotoxy(x + 13, y + 12); cout << "      X";
        gotoxy(x + 13, y + 13); cout << "     (|)";
        gotoxy(x + 13, y + 14); cout << "     '|`\033[0m";
    }

    //ī��3
    else if (i == 2) {
        
        gotoxy(x + 24, y + 5); cout << "\033[96m (`-._o_.-')";
        gotoxy(x + 24, y + 6); cout << "  (`- | -')";
        gotoxy(x + 24, y + 7); cout << "   `-.|.-'";
        gotoxy(x + 24, y + 8); cout << "     o|o";
        gotoxy(x + 24, y + 9); cout << "    ( | )";
        gotoxy(x + 24, y + 10); cout << "     `!'";
        gotoxy(x + 24, y + 11); cout << "     (|)";
        gotoxy(x + 24, y + 12); cout << "      X";
        gotoxy(x + 24, y + 13); cout << "     (|)";
        gotoxy(x + 24, y + 14); cout << "     '|`\033[0m";
    }

    //ī��4
    else if (i == 3) {
        
        gotoxy(x + 35, y + 5); cout << "\033[96m (`-._o_.-')";
        gotoxy(x + 35, y + 6); cout << "  (`- | -')";
        gotoxy(x + 35, y + 7); cout << "   `-.|.-'";
        gotoxy(x + 35, y + 8); cout << "     o|o";
        gotoxy(x + 35, y + 9); cout << "    ( | )";
        gotoxy(x + 35, y + 10); cout << "     `!'";
        gotoxy(x + 35, y + 11); cout << "     (|)";
        gotoxy(x + 35, y + 12); cout << "      X";
        gotoxy(x + 35, y + 13); cout << "     (|)";
        gotoxy(x + 35, y + 14); cout << "     '|`\033[0m";
    }


    //ī��5
    else if (i == 4) {
        
        gotoxy(x + 46, y + 5); cout << "\033[96m (`-._o_.-')";
        gotoxy(x + 46, y + 6); cout << "  (`- | -')";
        gotoxy(x + 46, y + 7); cout << "   `-.|.-'";
        gotoxy(x + 46, y + 8); cout << "     o|o";
        gotoxy(x + 46, y + 9); cout << "    ( | )";
        gotoxy(x + 46, y + 10); cout << "     `!'";
        gotoxy(x + 46, y + 11); cout << "     (|)";
        gotoxy(x + 46, y + 12); cout << "      X";
        gotoxy(x + 46, y + 13); cout << "     (|)";
        gotoxy(x + 46, y + 14); cout << "     '|`\033[0m";
    }
    

    
}

// ��ų ����, �ٽ� �̱⸦ ���. �ӽ÷� skil_choice �Լ� �ȿ� �־����.
void skil_input()
{
    int x = 1;
    int y = 34;
    gotoxy(x, y); cout << "�� \033[94m��ų ���� \033[90m(1)\033[0m�� " << "�� \033[94m�ٽ� �̱� \033[90m(2)\033[0m�� ";
    gotoxy(x, y + 2); cout << " Enter Number: " << endl;
}

void screen_reset() {
    
    int x = 1;
    int y = 14;

    gotoxy(x, y + 1); cout << "                                                                                                                  ";
    gotoxy(x, y + 2); cout << "                                                                                                                  ";
    gotoxy(x, y + 3); cout << "                                                                                                                  ";
    gotoxy(x, y + 4); cout << "                                                                                                                  ";
    gotoxy(x, y + 5); cout << "                                                                                                                  ";
    gotoxy(x, y + 6); cout << "                                                                                                                  ";
    gotoxy(x, y + 7); cout << "                                                                                                                  ";
    gotoxy(x, y + 8); cout << "                                                                                                                  ";
    gotoxy(x, y + 9); cout << "                                                                                                                  ";
    gotoxy(x, y + 10); cout << "                                                                                                                  ";
    gotoxy(x, y + 11); cout << "                                                                                                                  ";
    gotoxy(x, y + 12); cout << "                                                                                                                  ";
    gotoxy(x, y + 13); cout << "                                                                                                                  ";
    gotoxy(x, y + 14); cout << "                                                                                                                  ";
    gotoxy(x, y + 15); cout << "                                                                                                                  ";
    gotoxy(x, y + 16); cout << "                                                                                                                  ";
    gotoxy(x, y + 17); cout << "                                                                                                                  ";
}

void console_reset() {

    int x = 1;
    int y = 34;
    gotoxy(x, y); cout << "                                                            ";
    gotoxy(x, y + 2); cout << "                                                          " << endl;
    gotoxy(x, y + 4); cout << "                                                          " << endl;
    gotoxy(x, y + 6); cout << "                                                          " << endl;

}

void status_reset() {
    int x = 1;
    int y = 0;

    for (int i = 0; i < 12; i++) {
        gotoxy(x, y + 1 + i); cout << "                           ";
    }
    
    x = 44;
    y = 0;
    for (int i = 0; i < 12; i++) {
        gotoxy(x, y + 1 + i); cout << "                           ";
    }
}


void skil_tanker_used(int i)
{
    int x = 2;
    int y = 15;

    //ī��1
    if (i == 0) {
        gotoxy(x + 2, y + 5); cout << "\033[90m  |`-._/\\_.-`|";
        gotoxy(x + 2, y + 6); cout << "  |    ||    |";
        gotoxy(x + 2, y + 7); cout << "  |___o()o___|";
        gotoxy(x + 2, y + 8); cout << "  |__((<>))__|";
        gotoxy(x + 2, y + 9); cout << "  \\   o\\/o   /";
        gotoxy(x + 2, y + 10); cout << "   \\   ||   /";
        gotoxy(x + 2, y + 11); cout << "    \\  ||  /";
        gotoxy(x + 2, y + 12); cout << "     '.||.'";
        gotoxy(x + 2, y + 13); cout << "       ``\033[0m";
    }


    //ī��2
    else if (i == 1) {

        gotoxy(x + 13, y + 5); cout << "\033[90m  |`-._/\\_.-`|";
        gotoxy(x + 13, y + 6); cout << "  |    ||    |";
        gotoxy(x + 13, y + 7); cout << "  |___o()o___|";
        gotoxy(x + 13, y + 8); cout << "  |__((<>))__|";
        gotoxy(x + 13, y + 9); cout << "  \\   o\\/o   /";
        gotoxy(x + 13, y + 10); cout << "   \\   ||   /";
        gotoxy(x + 13, y + 11); cout << "    \\  ||  /";
        gotoxy(x + 13, y + 12); cout << "     '.||.'";
        gotoxy(x + 13, y + 13); cout << "       ``\033[0m";
    }

    //ī��3
    else if (i == 2) {

        gotoxy(x + 24, y + 5); cout << "\033[90m  |`-._/\\_.-`|";
        gotoxy(x + 24, y + 6); cout << "  |    ||    |";
        gotoxy(x + 24, y + 7); cout << "  |___o()o___|";
        gotoxy(x + 24, y + 8); cout << "  |__((<>))__|";
        gotoxy(x + 24, y + 9); cout << "  \\   o\\/o   /";
        gotoxy(x + 24, y + 10); cout << "   \\   ||   /";
        gotoxy(x + 24, y + 11); cout << "    \\  ||  /";
        gotoxy(x + 24, y + 12); cout << "     '.||.'";
        gotoxy(x + 24, y + 13); cout << "       ``\033[0m";
    }

    //ī��4
    else if (i == 3) {

        gotoxy(x + 35, y + 5); cout << "\033[90m  |`-._/\\_.-`|";
        gotoxy(x + 35, y + 6); cout << "  |    ||    |";
        gotoxy(x + 35, y + 7); cout << "  |___o()o___|";
        gotoxy(x + 35, y + 8); cout << "  |__((<>))__|";
        gotoxy(x + 35, y + 9); cout << "  \\   o\\/o   /";
        gotoxy(x + 35, y + 10); cout << "   \\   ||   /";
        gotoxy(x + 35, y + 11); cout << "    \\  ||  /";
        gotoxy(x + 35, y + 12); cout << "     '.||.'";
        gotoxy(x + 35, y + 13); cout << "       ``\033[0m";
    }

    //ī��5
    else if (i == 4) {

        gotoxy(x + 46, y + 5); cout << "\033[90m  |`-._/\\_.-`|";
        gotoxy(x + 46, y + 6); cout << "  |    ||    |";
        gotoxy(x + 46, y + 7); cout << "  |___o()o___|";
        gotoxy(x + 46, y + 8); cout << "  |__((<>))__|";
        gotoxy(x + 46, y + 9); cout << "  \\   o\\/o   /";
        gotoxy(x + 46, y + 10); cout << "   \\   ||   /";
        gotoxy(x + 46, y + 11); cout << "    \\  ||  /";
        gotoxy(x + 46, y + 12); cout << "     '.||.'";
        gotoxy(x + 46, y + 13); cout << "       ``\033[0m";
    }



}
void skil_dealer_used(int i)
{
    int x = 3;
    int y = 14;

    //ī��1
    if (i == 0) {

        gotoxy(x + 2, y + 5); cout << "\033[90m     /\\";
        gotoxy(x + 2, y + 6); cout << "    // \\";
        gotoxy(x + 2, y + 7); cout << "    || |";
        gotoxy(x + 2, y + 8); cout << "    || |";
        gotoxy(x + 2, y + 9); cout << "    || |";
        gotoxy(x + 2, y + 10); cout << " __ || | __";
        gotoxy(x + 2, y + 11); cout << "/___||_|___\\";
        gotoxy(x + 2, y + 12); cout << "    _MM_";
        gotoxy(x + 2, y + 13); cout << "   (&<>&)";
        gotoxy(x + 2, y + 14); cout << "    ~~~~\033[0m";
    }

    //ī��2
    else if (i == 1) {

        gotoxy(x + 13, y + 5); cout << "\033[90m     /\\";
        gotoxy(x + 13, y + 6); cout << "    // \\";
        gotoxy(x + 13, y + 7); cout << "    || |";
        gotoxy(x + 13, y + 8); cout << "    || |";
        gotoxy(x + 13, y + 9); cout << "    || |";
        gotoxy(x + 13, y + 10); cout << " __ || | __";
        gotoxy(x + 13, y + 11); cout << "/___||_|___\\";
        gotoxy(x + 13, y + 12); cout << "    _MM_";
        gotoxy(x + 13, y + 13); cout << "   (&<>&)";
        gotoxy(x + 13, y + 14); cout << "    ~~~~\033[0m";
    }

    //ī��3
    else if (i == 2) {

        gotoxy(x + 24, y + 5); cout << "\033[90m     /\\";
        gotoxy(x + 24, y + 6); cout << "    // \\";
        gotoxy(x + 24, y + 7); cout << "    || |";
        gotoxy(x + 24, y + 8); cout << "    || |";
        gotoxy(x + 24, y + 9); cout << "    || |";
        gotoxy(x + 24, y + 10); cout << " __ || | __";
        gotoxy(x + 24, y + 11); cout << "/___||_|___\\";
        gotoxy(x + 24, y + 12); cout << "    _MM_";
        gotoxy(x + 24, y + 13); cout << "   (&<>&)";
        gotoxy(x + 24, y + 14); cout << "    ~~~~\033[0m";
    }


    //ī��4
    else if (i == 3) {

        gotoxy(x + 35, y + 5); cout << "\033[90m     /\\";
        gotoxy(x + 35, y + 6); cout << "    // \\";
        gotoxy(x + 35, y + 7); cout << "    || |";
        gotoxy(x + 35, y + 8); cout << "    || |";
        gotoxy(x + 35, y + 9); cout << "    || |";
        gotoxy(x + 35, y + 10); cout << " __ || | __";
        gotoxy(x + 35, y + 11); cout << "/___||_|___\\";
        gotoxy(x + 35, y + 12); cout << "    _MM_";
        gotoxy(x + 35, y + 13); cout << "   (&<>&)";
        gotoxy(x + 35, y + 14); cout << "    ~~~~\033[0m";

    }

    //ī��5
    else if (i == 4) {

        gotoxy(x + 46, y + 5); cout << "\033[90m     /\\";
        gotoxy(x + 46, y + 6); cout << "    // \\";
        gotoxy(x + 46, y + 7); cout << "    || |";
        gotoxy(x + 46, y + 8); cout << "    || |";
        gotoxy(x + 46, y + 9); cout << "    || |";
        gotoxy(x + 46, y + 10); cout << " __ || | __";
        gotoxy(x + 46, y + 11); cout << "/___||_|___\\";
        gotoxy(x + 46, y + 12); cout << "    _MM_";
        gotoxy(x + 46, y + 13); cout << "   (&<>&)";
        gotoxy(x + 46, y + 14); cout << "    ~~~~\033[0m";
    }




}

void skil_healer_used(int i)
{
    int x = 3;
    int y = 14;


    //ī��1
    if (i == 0) {

        gotoxy(x + 2, y + 5); cout << "\033[90m (`-._o_.-')";
        gotoxy(x + 2, y + 6); cout << "  (`- | -')";
        gotoxy(x + 2, y + 7); cout << "   `-.|.-'";
        gotoxy(x + 2, y + 8); cout << "     o|o ";
        gotoxy(x + 2, y + 9); cout << "    ( | )";
        gotoxy(x + 2, y + 10); cout << "     `!'";
        gotoxy(x + 2, y + 11); cout << "     (|)";
        gotoxy(x + 2, y + 12); cout << "      X";
        gotoxy(x + 2, y + 13); cout << "     (|)";
        gotoxy(x + 2, y + 14); cout << "     '|`\033[0m";
    }

    //ī��2
    else if (i == 1) {

        gotoxy(x + 13, y + 5); cout << "\033[90m (`-._o_.-')";
        gotoxy(x + 13, y + 6); cout << "  (`- | -')";
        gotoxy(x + 13, y + 7); cout << "   `-.|.-'";
        gotoxy(x + 13, y + 8); cout << "     o|o";
        gotoxy(x + 13, y + 9); cout << "    ( | )";
        gotoxy(x + 13, y + 10); cout << "     `!'";
        gotoxy(x + 13, y + 11); cout << "     (|)";
        gotoxy(x + 13, y + 12); cout << "      X";
        gotoxy(x + 13, y + 13); cout << "     (|)";
        gotoxy(x + 13, y + 14); cout << "     '|`\033[0m";
    }

    //ī��3
    else if (i == 2) {

        gotoxy(x + 24, y + 5); cout << "\033[90m (`-._o_.-')";
        gotoxy(x + 24, y + 6); cout << "  (`- | -')";
        gotoxy(x + 24, y + 7); cout << "   `-.|.-'";
        gotoxy(x + 24, y + 8); cout << "     o|o";
        gotoxy(x + 24, y + 9); cout << "    ( | )";
        gotoxy(x + 24, y + 10); cout << "     `!'";
        gotoxy(x + 24, y + 11); cout << "     (|)";
        gotoxy(x + 24, y + 12); cout << "      X";
        gotoxy(x + 24, y + 13); cout << "     (|)";
        gotoxy(x + 24, y + 14); cout << "     '|`\033[0m";
    }

    //ī��4
    else if (i == 3) {

        gotoxy(x + 35, y + 5); cout << "\033[90m (`-._o_.-')";
        gotoxy(x + 35, y + 6); cout << "  (`- | -')";
        gotoxy(x + 35, y + 7); cout << "   `-.|.-'";
        gotoxy(x + 35, y + 8); cout << "     o|o";
        gotoxy(x + 35, y + 9); cout << "    ( | )";
        gotoxy(x + 35, y + 10); cout << "     `!'";
        gotoxy(x + 35, y + 11); cout << "     (|)";
        gotoxy(x + 35, y + 12); cout << "      X";
        gotoxy(x + 35, y + 13); cout << "     (|)";
        gotoxy(x + 35, y + 14); cout << "     '|`\033[0m";
    }


    //ī��5
    else if (i == 4) {

        gotoxy(x + 46, y + 5); cout << "\033[90m (`-._o_.-')";
        gotoxy(x + 46, y + 6); cout << "  (`- | -')";
        gotoxy(x + 46, y + 7); cout << "   `-.|.-'";
        gotoxy(x + 46, y + 8); cout << "     o|o";
        gotoxy(x + 46, y + 9); cout << "    ( | )";
        gotoxy(x + 46, y + 10); cout << "     `!'";
        gotoxy(x + 46, y + 11); cout << "     (|)";
        gotoxy(x + 46, y + 12); cout << "      X";
        gotoxy(x + 46, y + 13); cout << "     (|)";
        gotoxy(x + 46, y + 14); cout << "     '|`\033[0m";
    }



}
