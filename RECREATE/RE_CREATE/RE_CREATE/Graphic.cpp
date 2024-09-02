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

    gotoxy(x, y); cout << "忙式式式式式式式忖";
    gotoxy(x, y + 1); cout << "弛"; gotoxy(x + 4, y + 1); cout << "弛";
    gotoxy(x, y + 2); cout << "弛"; gotoxy(x + 4, y + 2); cout << "弛"; gotoxy(x + 5, y + 2); cout << "式式式式";
    gotoxy(x, y + 3); cout << "弛"; gotoxy(x + 4, y + 3); cout << "弛";
    gotoxy(x, y + 4); cout << "戌式式式式式式式戎";

    gotoxy(x + 7, y); cout << " 忙式式式式式式式忖";
    gotoxy(x + 7, y + 1); cout << " 弛"; gotoxy(x + 11, y + 1); cout << " 弛";
    gotoxy(x + 7, y + 2); cout << " 弛"; gotoxy(x + 11, y + 2); cout << " 弛"; gotoxy(x + 12, y + 2); cout << " 式式式式";
    gotoxy(x + 7, y + 3); cout << " 弛"; gotoxy(x + 11, y + 3); cout << " 弛";
    gotoxy(x + 7, y + 4); cout << " 戌式式式式式式式戎";

    // ⑷營 嬪纂
    gotoxy(x + 8, y + 7); cout << "雖ж " << floor << "類";

    gotoxy(x + 15, y); cout << "忙式式式式式式式忖";
    gotoxy(x + 15, y + 1); cout << "弛"; gotoxy(x + 19, y + 1); cout << "弛";
    gotoxy(x + 15, y + 2); cout << "弛"; gotoxy(x + 19, y + 2); cout << "弛";
    gotoxy(x + 15, y + 3); cout << "弛"; gotoxy(x + 19, y + 3); cout << "弛";
    gotoxy(x + 15, y + 4); cout << "戌式式式式式式式戎";

    // ⑷營 嬪纂 �側瘓�

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

// ⑷營 嬪纂. 歜衛煎 stage 頂縑 厥橫場擠.
void now_stage1()
{
    int x = 21;
    int y = 4;
    // 蝶纔檜雖1
    gotoxy(x, y + 2); cout << "\033[36m夭﹥\033[0m";
}
void now_stage2()
{
    int x = 21;
    int y = 4;
    // 蝶纔檜雖2
    gotoxy(x + 7, y + 2); cout << "\033[36m 夭﹥\033[0m";
}
void now_stage3()
{
    int x = 21;
    int y = 4;
    // 蝶纔檜雖3
    gotoxy(x + 15, y + 2); cout << "\033[36m夭﹥\033[0m";
}




// 衛濛 �飛� 嬴蝶酈 嬴お
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


// ぎ
void frame()
{
    int x = 0;
    int y = 13;
    int z = 32;
    int q = 59;
    gotoxy(x, x); cout << "旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬";
    gotoxy(y + 3, x); cout << "有"; gotoxy(q - 16, x); cout << "有";
    gotoxy(x, x + 1); cout << "早"; gotoxy(y + 3, x + 1); cout << "早"; gotoxy(q - 16, x + 1); cout << "早"; gotoxy(q, x + 1); cout << "早";
    gotoxy(x, x + 2); cout << "早"; gotoxy(y + 3, x + 2); cout << "早"; gotoxy(q - 16, x + 2); cout << "早"; gotoxy(q, x + 2); cout << "早";
    gotoxy(x, x + 3); cout << "早"; gotoxy(y + 3, x + 3); cout << "早"; gotoxy(q - 16, x + 3); cout << "早"; gotoxy(q, x + 3); cout << "早";
    gotoxy(x, x + 4); cout << "早"; gotoxy(y + 3, x + 4); cout << "早"; gotoxy(q - 16, x + 4); cout << "早"; gotoxy(q, x + 4); cout << "早";
    gotoxy(x, x + 5); cout << "早"; gotoxy(y + 3, x + 5); cout << "早"; gotoxy(q - 16, x + 5); cout << "早"; gotoxy(q, x + 5); cout << "早";
    gotoxy(x, x + 6); cout << "早"; gotoxy(y + 3, x + 6); cout << "早"; gotoxy(q - 16, x + 6); cout << "早"; gotoxy(q, x + 6); cout << "早";
    gotoxy(x, x + 7); cout << "早"; gotoxy(y + 3, x + 7); cout << "早"; gotoxy(q - 16, x + 7); cout << "早"; gotoxy(q, x + 7); cout << "早";
    gotoxy(x, x + 8); cout << "早"; gotoxy(y + 3, x + 8); cout << "早"; gotoxy(q - 16, x + 8); cout << "早"; gotoxy(q, x + 8); cout << "早";
    gotoxy(x, x + 9); cout << "早"; gotoxy(y + 3, x + 9); cout << "早"; gotoxy(q - 16, x + 9); cout << "早"; gotoxy(q, x + 9); cout << "早";
    gotoxy(x, x + 10); cout << "早"; gotoxy(y + 3, x + 10); cout << "早"; gotoxy(q - 16, x + 10); cout << "早"; gotoxy(q, x + 10); cout << "早";
    gotoxy(x, x + 11); cout << "早"; gotoxy(y + 3, x + 11); cout << "早"; gotoxy(q - 16, x + 11); cout << "早"; gotoxy(q, x + 11); cout << "早";
    gotoxy(x, x + 12); cout << "早"; gotoxy(y + 3, x + 12); cout << "早"; gotoxy(q - 16, x + 12); cout << "早"; gotoxy(q, x + 12); cout << "早";
    gotoxy(x, y); cout << "朵收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收此";
    gotoxy(y + 3, y); cout << "朴"; gotoxy(q - 16, y); cout << "朴";
    gotoxy(x, y + 1); cout << "早"; gotoxy(q, y + 1); cout << "早";
    gotoxy(x, y + 2); cout << "早"; gotoxy(q, y + 2); cout << "早";
    gotoxy(x, y + 3); cout << "早"; gotoxy(q, y + 3); cout << "早";
    gotoxy(x, y + 4); cout << "早"; gotoxy(q, y + 4); cout << "早";
    gotoxy(x, y + 5); cout << "早"; gotoxy(q, y + 5); cout << "早";
    gotoxy(x, y + 6); cout << "早"; gotoxy(q, y + 6); cout << "早";
    gotoxy(x, y + 7); cout << "早"; gotoxy(q, y + 7); cout << "早";
    gotoxy(x, y + 8); cout << "早"; gotoxy(q, y + 8); cout << "早";
    gotoxy(x, y + 9); cout << "早"; gotoxy(q, y + 9); cout << "早";
    gotoxy(x, y + 10); cout << "早"; gotoxy(q, y + 10); cout << "早";
    gotoxy(x, y + 11); cout << "早"; gotoxy(q, y + 11); cout << "早";
    gotoxy(x, y + 12); cout << "早"; gotoxy(q, y + 12); cout << "早";
    gotoxy(x, y + 13); cout << "早"; gotoxy(q, y + 13); cout << "早";
    gotoxy(x, y + 14); cout << "早"; gotoxy(q, y + 14); cout << "早";
    gotoxy(x, y + 15); cout << "早"; gotoxy(q, y + 15); cout << "早";
    gotoxy(x, y + 16); cout << "早"; gotoxy(q, y + 16); cout << "早";
    gotoxy(x, y + 17); cout << "早"; gotoxy(q, y + 17); cout << "早";
    gotoxy(x, y + 18); cout << "早"; gotoxy(q, y + 18); cout << "早";
    gotoxy(x, z); cout << "朵收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收此";
    gotoxy(x, z + 1); cout << "早"; gotoxy(q, z + 1); cout << "早";
    gotoxy(x, z + 2); cout << "早"; gotoxy(q, z + 2); cout << "早";
    gotoxy(x, z + 3); cout << "早"; gotoxy(q, z + 3); cout << "早";
    gotoxy(x, z + 4); cout << "早"; gotoxy(q, z + 4); cout << "早";
    gotoxy(x, z + 5); cout << "早"; gotoxy(q, z + 5); cout << "早";
    gotoxy(x, z + 6); cout << "早"; gotoxy(q, z + 6); cout << "早";
    gotoxy(x, z + 7); cout << "早"; gotoxy(q, z + 7); cout << "早";
    gotoxy(x, z + 8); cout << "早"; gotoxy(q, z + 8); cout << "早";
    gotoxy(x, z + 9); cout << "曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭";

}

// 晦獄 摹鷗雖
void basic_choice()
{
    int x = 1;
    int y = 34;
    gotoxy(x, y); cout << "弛 \033[94m鼻鷓璽 \033[90m(1)\033[0m弛 " << "弛 \033[94m蝶鑒 \033[90m(2)\033[0m弛 ";
    gotoxy(x, y + 2); cout << " Enter Number: " << endl;
}

// 鼻欽縑 釭螃朝 PC 薑爾璽
void PC1_info()
{
    int x = 1;
    int y = 0;
    gotoxy(x, y + 1); cout << "[給問濠]"; // 滲熱撲薑п憮...摹鷗и 贗楚蝶 釭螃啪? ж晦?
    gotoxy(x, y + 2); cout << "HP: 97 / 100"; // 檜匙紫 滲熱煎п憮..
    gotoxy(x, y + 3); cout << "ч翕溘: 10"; // 檜匙舒..

    // 鼻鷓檜鼻 ル衛
    // 鼻鷓 檜鼻 橈擊 隆 寰嗑賊 謠啃橫蹂
    gotoxy(x + 4, y + 1); cout << "(鼻鷓檜鼻)"; // 婪�� 寰縑 鼻鷓檜鼻 滲熱
}
void PC2_info()
{
    int x = 1;
    int y = 4;
    gotoxy(x, y + 1); cout << "[辨煽]";
    gotoxy(x, y + 2); cout << "HP: 97 / 100";
    gotoxy(x, y + 3); cout << "ч翕溘: 10";

    // 鼻鷓檜鼻 ル衛
    gotoxy(x + 4, y + 1); cout << "(醞絮)";
}
void PC3_info()
{
    int x = 1;
    int y = 8;
    gotoxy(x, y + 1); cout << "[纂嶸餌]";
    gotoxy(x, y + 2); cout << "HP: 70 / 80";
    gotoxy(x, y + 3); cout << "ч翕溘: 10";

    // 鼻鷓檜鼻 ル衛
    gotoxy(x + 4, y + 1); cout << "(轎⑸)";
}

// 鼻欽縑 釭螃朝 瞳 薑爾璽
void enemy1_info()
{
    int x = 44;
    int y = 0;
    gotoxy(x, y + 1); cout << "[期渠]";
    gotoxy(x, y + 2); cout << "HP: 200";

    // 鼻鷓檜鼻 ル衛
    gotoxy(x + 4, y + 1); cout << "(鼻鷓檜鼻)";
}
void enemy2_info()
{
    int x = 44;
    int y = 4;
    gotoxy(x, y + 1); cout << "[期渠]";
    gotoxy(x, y + 2); cout << "HP: 200";

    // 鼻鷓檜鼻 ル衛
    gotoxy(x + 4, y + 1); cout << "(鼻鷓檜鼻)";
}
void enemy3_info()
{
    int x = 44;
    int y = 8;
    gotoxy(x, y + 1); cout << "[期渠]";
    gotoxy(x, y + 2); cout << "HP: 200";

    // 鼻鷓檜鼻 ル衛
    gotoxy(x + 4, y + 1); cout << "(鼻鷓檜鼻)";
}

// 渠餌 轎溘
void dialogue()
{
    int x = 1;
    int y = 12;

    // 蝶鑒 餌辨 轎溘擎 蝶鑒 摹鷗и 牖憮渠煎 轎溘 陛棟й梱蹂?
    gotoxy(x, y + 2); cout << "\033[33m陛萄! \033[0m";
    gotoxy(x, y + 3); cout << "給問濠" << "(檜)陛 " << "瞳曖 奢問擊 嘐葬 渠綠ж罹 寞橫 濠撮蒂 鏃м棲棻.";

    gotoxy(x, y + 5); cout << "\033[33m纂嶸! \033[0m";
    gotoxy(x, y + 6); cout << "纂嶸餌" << "(檜)陛 " << "纂嶸曖 縑傘雖蒂 檜辨ж罹 辨煽擊 �蛹嘎桭炴�.";

    gotoxy(x, y + 8); cout << "\033[33m鎬腦晦! \033[0m";
    gotoxy(x, y + 9); cout << "辨煽" << "(檜)陛 " << "陳蘋煎遴 匐晦煎 期渠1曖 擒薄擊 鎬落棲棻.";

    // PC曖 蝶鑒 渠餌 轎溘 檜��, 唸婁 轎溘
    gotoxy(x, y + 11); cout << "\033[34m給問濠陛 寞橫 濠撮蒂 鏃и棻.\033[0m";
    gotoxy(x, y + 12); cout << "> 給問濠曖 HP: 97 / 150"; // [雖薑渠鼻]曖 HP: (⑷營羹溘) / (譆渠羹溘) 

    gotoxy(x, y + 14); cout << "\033[96m纂嶸餌陛 辨煽擊 15 虜躑 纂嶸ц棻.\033[0m";
    gotoxy(x, y + 15); cout << "> 辨煽曖 HP: 97 / 100"; // [給問濠]曖 HP: (⑷營羹溘) / (譆渠羹溘) 

    gotoxy(x, y + 17); cout << "\033[31m辨煽檜 期渠1縑啪 25 虜躑曖 Яп蒂 殮⑼棻!\033[0m"; // [PC]檜 [瞳 檜葷]縑啪 [等嘐雖] 虜躑曖 Яп蒂 殮⑼棻!
    gotoxy(x, y + 18); cout << "> 期渠1曖 HP: 154 / 200"; // [瞳]曖 HP: (⑷營羹溘) / (譆渠羹溘)
}

void class_choice() {
    
    int x = 3;
    int y = 14;
    gotoxy(x - 3, y - 1); cout << "朵收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收此";


    //蘋萄2
    gotoxy(x + 15, y + 1); cout << "< 1 >";
    gotoxy(x + 11, y + 2); cout << "忙式式式式式式式式式式式式式式式式式忖 ";
    gotoxy(x + 11, y + 3); cout << "弛"; gotoxy(x + 20, y + 3); cout << "弛"; gotoxy(x + 13, y + 3); cout << "    辨煽    ";
    gotoxy(x + 11, y + 4); cout << "弛"; gotoxy(x + 20, y + 4); cout << "弛";
    gotoxy(x + 11, y + 5); cout << "弛"; gotoxy(x + 20, y + 5); cout << "弛";
    gotoxy(x + 11, y + 6); cout << "弛"; gotoxy(x + 20, y + 6); cout << "弛";
    gotoxy(x + 11, y + 7); cout << "弛"; gotoxy(x + 20, y + 7); cout << "弛";
    gotoxy(x + 11, y + 8); cout << "弛"; gotoxy(x + 20, y + 8); cout << "弛";
    gotoxy(x + 11, y + 9); cout << "弛"; gotoxy(x + 20, y + 9); cout << "弛";
    gotoxy(x + 11, y + 10); cout << "弛"; gotoxy(x + 20, y + 10); cout << "弛";
    gotoxy(x + 11, y + 11); cout << "弛"; gotoxy(x + 20, y + 11); cout << "弛";
    gotoxy(x + 11, y + 12); cout << "弛"; gotoxy(x + 20, y + 12); cout << "弛";
    gotoxy(x + 11, y + 13); cout << "弛"; gotoxy(x + 20, y + 13); cout << "弛";
    gotoxy(x + 11, y + 14); cout << "弛"; gotoxy(x + 20, y + 14); cout << "弛";
    gotoxy(x + 11, y + 15); cout << "弛"; gotoxy(x + 20, y + 15); cout << "弛";
    gotoxy(x + 11, y + 16); cout << "弛"; gotoxy(x + 20, y + 16); cout << "弛"; 
    gotoxy(x + 11, y + 17); cout << "戌式式式式式式式式式式式式式式式式式戎";

    //蘋萄3
    gotoxy(x + 26, y + 1); cout << "< 2 >";
    gotoxy(x + 22, y + 2); cout << "忙式式式式式式式式式式式式式式式式式忖 ";
    gotoxy(x + 22, y + 3); cout << "弛"; gotoxy(x + 31, y + 3); cout << "弛"; gotoxy(x + 24, y + 3); cout << "   纂嶸餌   ";
    gotoxy(x + 22, y + 4); cout << "弛"; gotoxy(x + 31, y + 4); cout << "弛";
    gotoxy(x + 22, y + 5); cout << "弛"; gotoxy(x + 31, y + 5); cout << "弛";
    gotoxy(x + 22, y + 6); cout << "弛"; gotoxy(x + 31, y + 6); cout << "弛";
    gotoxy(x + 22, y + 7); cout << "弛"; gotoxy(x + 31, y + 7); cout << "弛";
    gotoxy(x + 22, y + 8); cout << "弛"; gotoxy(x + 31, y + 8); cout << "弛";
    gotoxy(x + 22, y + 9); cout << "弛"; gotoxy(x + 31, y + 9); cout << "弛";
    gotoxy(x + 22, y + 10); cout << "弛"; gotoxy(x + 31, y + 10); cout << "弛";
    gotoxy(x + 22, y + 11); cout << "弛"; gotoxy(x + 31, y + 11); cout << "弛";
    gotoxy(x + 22, y + 12); cout << "弛"; gotoxy(x + 31, y + 12); cout << "弛";
    gotoxy(x + 22, y + 13); cout << "弛"; gotoxy(x + 31, y + 13); cout << "弛";
    gotoxy(x + 22, y + 14); cout << "弛"; gotoxy(x + 31, y + 14); cout << "弛";
    gotoxy(x + 22, y + 15); cout << "弛"; gotoxy(x + 31, y + 15); cout << "弛";
    gotoxy(x + 22, y + 16); cout << "弛"; gotoxy(x + 31, y + 16); cout << "弛"; 
    gotoxy(x + 22, y + 17); cout << "戌式式式式式式式式式式式式式式式式式戎";

    //蘋萄4
    gotoxy(x + 37, y + 1); cout << "< 3 >";
    gotoxy(x + 33, y + 2); cout << "忙式式式式式式式式式式式式式式式式式忖 ";
    gotoxy(x + 33, y + 3); cout << "弛"; gotoxy(x + 42, y + 3); cout << "弛"; gotoxy(x + 35, y + 3); cout << "   給問濠   ";
    gotoxy(x + 33, y + 4); cout << "弛"; gotoxy(x + 42, y + 4); cout << "弛";
    gotoxy(x + 33, y + 5); cout << "弛"; gotoxy(x + 42, y + 5); cout << "弛";
    gotoxy(x + 33, y + 6); cout << "弛"; gotoxy(x + 42, y + 6); cout << "弛";
    gotoxy(x + 33, y + 7); cout << "弛"; gotoxy(x + 42, y + 7); cout << "弛";
    gotoxy(x + 33, y + 8); cout << "弛"; gotoxy(x + 42, y + 8); cout << "弛";
    gotoxy(x + 33, y + 9); cout << "弛"; gotoxy(x + 42, y + 9); cout << "弛";
    gotoxy(x + 33, y + 10); cout << "弛"; gotoxy(x + 42, y + 10); cout << "弛";
    gotoxy(x + 33, y + 11); cout << "弛"; gotoxy(x + 42, y + 11); cout << "弛";
    gotoxy(x + 33, y + 12); cout << "弛"; gotoxy(x + 42, y + 12); cout << "弛";
    gotoxy(x + 33, y + 13); cout << "弛"; gotoxy(x + 42, y + 13); cout << "弛";
    gotoxy(x + 33, y + 14); cout << "弛"; gotoxy(x + 42, y + 14); cout << "弛";
    gotoxy(x + 33, y + 15); cout << "弛"; gotoxy(x + 42, y + 15); cout << "弛";
    gotoxy(x + 33, y + 16); cout << "弛"; gotoxy(x + 42, y + 16); cout << "弛"; 
    gotoxy(x + 33, y + 17); cout << "戌式式式式式式式式式式式式式式式式式戎";


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
    gotoxy(x - 3, y - 1); cout << "朵收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收此";



    //蘋萄3
    gotoxy(x + 22, y + 2); cout << "忙式式式式式式式式式式式式式式式式式忖 ";
    gotoxy(x + 22, y + 3); cout << "弛"; gotoxy(x + 31, y + 3); cout << "弛"; 
    gotoxy(x + 22, y + 4); cout << "弛"; gotoxy(x + 31, y + 4); cout << "弛";
    gotoxy(x + 22, y + 5); cout << "弛"; gotoxy(x + 31, y + 5); cout << "弛";
    gotoxy(x + 22, y + 6); cout << "弛"; gotoxy(x + 31, y + 6); cout << "弛";
    gotoxy(x + 22, y + 7); cout << "弛"; gotoxy(x + 31, y + 7); cout << "弛";
    gotoxy(x + 22, y + 8); cout << "弛"; gotoxy(x + 31, y + 8); cout << "弛";
    gotoxy(x + 22, y + 9); cout << "弛"; gotoxy(x + 31, y + 9); cout << "弛";
    gotoxy(x + 22, y + 10); cout << "弛"; gotoxy(x + 31, y + 10); cout << "弛";
    gotoxy(x + 22, y + 11); cout << "弛"; gotoxy(x + 31, y + 11); cout << "弛";
    gotoxy(x + 22, y + 12); cout << "弛"; gotoxy(x + 31, y + 12); cout << "弛";
    gotoxy(x + 22, y + 13); cout << "弛"; gotoxy(x + 31, y + 13); cout << "弛";
    gotoxy(x + 22, y + 14); cout << "弛"; gotoxy(x + 31, y + 14); cout << "弛";
    gotoxy(x + 22, y + 15); cout << "弛"; gotoxy(x + 31, y + 15); cout << "弛";
    gotoxy(x + 22, y + 16); cout << "弛"; gotoxy(x + 31, y + 16); cout << "弛"; 
    gotoxy(x + 22, y + 17); cout << "戌式式式式式式式式式式式式式式式式式戎";


    //skil_input();
    switch (i) {
    case '1':
        gotoxy(x + 25, y + 3); cout << " 辨煽";
        skil_dealer(2);
        break;
    case '2':
        gotoxy(x + 25, y + 3); cout << " 纂嶸餌";
        skil_healer(2);
        break;
    case '3':
        gotoxy(x + 25, y + 3); cout << " 給問濠";
        skil_tanker(2);
        break;
    default:
        break;
    }
    
}

// 蝶鑒 摹鷗 衛 蛔濰ж朝 蘋萄
void skil_choice(int i, string skillname, int act)
{
    string blank = "                ";
    size_t middle = blank.size() / 2; // 醞懈 嬪纂 啗骯
    std::string blankname = blank; // 錳獄 僥濠翮 犒餌

    // 醞懈 嬪纂縑 僥濠翮 鳶殮
    blankname.insert(middle, skillname);

    int originalLength = blankname.length();

    int length = 12;

    std::string name;
    if (length >= originalLength) {
        name = blankname;
    }
    else {
        // 醞懈 嬪纂 啗骯
        int start = (originalLength - length) / 2;

        // 醞懈 睡碟 濠腦晦
        name = blankname.substr(start, length);
    }
    int x = 3;
    int y = 14;
    gotoxy(x - 3, y - 1); cout << "朵收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收此";

    // 蘋萄1
    if (i == 0) {
        gotoxy(x + 4, y + 1); cout << "< 1 >";
        gotoxy(x, y + 2); cout << "忙式式式式式式式式式式式式式式式式式忖 ";
        gotoxy(x, y + 3); cout << "弛"; gotoxy(x + 9, y + 3); cout << "弛"; gotoxy(x + 2, y + 3); cout << name << "  ";
        gotoxy(x, y + 4); cout << "弛"; gotoxy(x + 9, y + 4); cout << "弛";
        gotoxy(x, y + 5); cout << "弛"; gotoxy(x + 9, y + 5); cout << "弛";
        gotoxy(x, y + 6); cout << "弛"; gotoxy(x + 9, y + 6); cout << "弛";
        gotoxy(x, y + 7); cout << "弛"; gotoxy(x + 9, y + 7); cout << "弛";
        gotoxy(x, y + 8); cout << "弛"; gotoxy(x + 9, y + 8); cout << "弛";
        gotoxy(x, y + 9); cout << "弛"; gotoxy(x + 9, y + 9); cout << "弛";
        gotoxy(x, y + 10); cout << "弛"; gotoxy(x + 9, y + 10); cout << "弛";
        gotoxy(x, y + 11); cout << "弛"; gotoxy(x + 9, y + 11); cout << "弛";
        gotoxy(x, y + 12); cout << "弛"; gotoxy(x + 9, y + 12); cout << "弛";
        gotoxy(x, y + 13); cout << "弛"; gotoxy(x + 9, y + 13); cout << "弛";
        gotoxy(x, y + 14); cout << "弛"; gotoxy(x + 9, y + 14); cout << "弛";
        gotoxy(x, y + 15); cout << "弛"; gotoxy(x + 9, y + 15); cout << "弛";
        gotoxy(x, y + 16); cout << "弛"; gotoxy(x + 9, y + 16); cout << "弛"; gotoxy(x + 5, y + 16); cout << "\033[33m" << act <<"\033[0m"; // ч翕溘
        gotoxy(x, y + 17); cout << "戌式式式式式式式式式式式式式式式式式戎";
    }

    
    //蘋萄2
    else if (i == 1) {
        gotoxy(x + 15, y + 1); cout << "< 2 >";
        gotoxy(x + 11, y + 2); cout << "忙式式式式式式式式式式式式式式式式式忖 ";
        gotoxy(x + 11, y + 3); cout << "弛"; gotoxy(x + 20, y + 3); cout << "弛"; gotoxy(x + 13, y + 3); cout << name << "  ";
        gotoxy(x + 11, y + 4); cout << "弛"; gotoxy(x + 20, y + 4); cout << "弛";
        gotoxy(x + 11, y + 5); cout << "弛"; gotoxy(x + 20, y + 5); cout << "弛";
        gotoxy(x + 11, y + 6); cout << "弛"; gotoxy(x + 20, y + 6); cout << "弛";
        gotoxy(x + 11, y + 7); cout << "弛"; gotoxy(x + 20, y + 7); cout << "弛";
        gotoxy(x + 11, y + 8); cout << "弛"; gotoxy(x + 20, y + 8); cout << "弛";
        gotoxy(x + 11, y + 9); cout << "弛"; gotoxy(x + 20, y + 9); cout << "弛";
        gotoxy(x + 11, y + 10); cout << "弛"; gotoxy(x + 20, y + 10); cout << "弛";
        gotoxy(x + 11, y + 11); cout << "弛"; gotoxy(x + 20, y + 11); cout << "弛";
        gotoxy(x + 11, y + 12); cout << "弛"; gotoxy(x + 20, y + 12); cout << "弛";
        gotoxy(x + 11, y + 13); cout << "弛"; gotoxy(x + 20, y + 13); cout << "弛";
        gotoxy(x + 11, y + 14); cout << "弛"; gotoxy(x + 20, y + 14); cout << "弛";
        gotoxy(x + 11, y + 15); cout << "弛"; gotoxy(x + 20, y + 15); cout << "弛";
        gotoxy(x + 11, y + 16); cout << "弛"; gotoxy(x + 20, y + 16); cout << "弛"; gotoxy(x + 16, y + 16); cout << "\033[33m" << act << "\033[0m";
        gotoxy(x + 11, y + 17); cout << "戌式式式式式式式式式式式式式式式式式戎";
    }

    
    
    //蘋萄3
    else if (i == 2) {
        gotoxy(x + 26, y + 1); cout << "< 3 >";
        gotoxy(x + 22, y + 2); cout << "忙式式式式式式式式式式式式式式式式式忖 ";
        gotoxy(x + 22, y + 3); cout << "弛"; gotoxy(x + 31, y + 3); cout << "弛"; gotoxy(x + 24, y + 3); cout << name << "  ";
        gotoxy(x + 22, y + 4); cout << "弛"; gotoxy(x + 31, y + 4); cout << "弛";
        gotoxy(x + 22, y + 5); cout << "弛"; gotoxy(x + 31, y + 5); cout << "弛";
        gotoxy(x + 22, y + 6); cout << "弛"; gotoxy(x + 31, y + 6); cout << "弛";
        gotoxy(x + 22, y + 7); cout << "弛"; gotoxy(x + 31, y + 7); cout << "弛";
        gotoxy(x + 22, y + 8); cout << "弛"; gotoxy(x + 31, y + 8); cout << "弛";
        gotoxy(x + 22, y + 9); cout << "弛"; gotoxy(x + 31, y + 9); cout << "弛";
        gotoxy(x + 22, y + 10); cout << "弛"; gotoxy(x + 31, y + 10); cout << "弛";
        gotoxy(x + 22, y + 11); cout << "弛"; gotoxy(x + 31, y + 11); cout << "弛";
        gotoxy(x + 22, y + 12); cout << "弛"; gotoxy(x + 31, y + 12); cout << "弛";
        gotoxy(x + 22, y + 13); cout << "弛"; gotoxy(x + 31, y + 13); cout << "弛";
        gotoxy(x + 22, y + 14); cout << "弛"; gotoxy(x + 31, y + 14); cout << "弛";
        gotoxy(x + 22, y + 15); cout << "弛"; gotoxy(x + 31, y + 15); cout << "弛";
        gotoxy(x + 22, y + 16); cout << "弛"; gotoxy(x + 31, y + 16); cout << "弛"; gotoxy(x + 27, y + 16); cout << "\033[33m" << act << "\033[0m";
        gotoxy(x + 22, y + 17); cout << "戌式式式式式式式式式式式式式式式式式戎";
    }
    

    //蘋萄4
    else if (i == 3) {
        gotoxy(x + 37, y + 1); cout << "< 4 >";
        gotoxy(x + 33, y + 2); cout << "忙式式式式式式式式式式式式式式式式式忖 ";
        gotoxy(x + 33, y + 3); cout << "弛"; gotoxy(x + 42, y + 3); cout << "弛"; gotoxy(x + 35, y + 3); cout << name << "  ";
        gotoxy(x + 33, y + 4); cout << "弛"; gotoxy(x + 42, y + 4); cout << "弛";
        gotoxy(x + 33, y + 5); cout << "弛"; gotoxy(x + 42, y + 5); cout << "弛";
        gotoxy(x + 33, y + 6); cout << "弛"; gotoxy(x + 42, y + 6); cout << "弛";
        gotoxy(x + 33, y + 7); cout << "弛"; gotoxy(x + 42, y + 7); cout << "弛";
        gotoxy(x + 33, y + 8); cout << "弛"; gotoxy(x + 42, y + 8); cout << "弛";
        gotoxy(x + 33, y + 9); cout << "弛"; gotoxy(x + 42, y + 9); cout << "弛";
        gotoxy(x + 33, y + 10); cout << "弛"; gotoxy(x + 42, y + 10); cout << "弛";
        gotoxy(x + 33, y + 11); cout << "弛"; gotoxy(x + 42, y + 11); cout << "弛";
        gotoxy(x + 33, y + 12); cout << "弛"; gotoxy(x + 42, y + 12); cout << "弛";
        gotoxy(x + 33, y + 13); cout << "弛"; gotoxy(x + 42, y + 13); cout << "弛";
        gotoxy(x + 33, y + 14); cout << "弛"; gotoxy(x + 42, y + 14); cout << "弛";
        gotoxy(x + 33, y + 15); cout << "弛"; gotoxy(x + 42, y + 15); cout << "弛";
        gotoxy(x + 33, y + 16); cout << "弛"; gotoxy(x + 42, y + 16); cout << "弛"; gotoxy(x + 38, y + 16); cout << "\033[33m" << act << "\033[0m";
        gotoxy(x + 33, y + 17); cout << "戌式式式式式式式式式式式式式式式式式戎";
    }
    

    //蘋萄5
    else if (i == 4) {
        gotoxy(x + 48, y + 1); cout << "< 5 >";
        gotoxy(x + 44, y + 2); cout << "忙式式式式式式式式式式式式式式式式式忖 ";
        gotoxy(x + 44, y + 3); cout << "弛"; gotoxy(x + 53, y + 3); cout << "弛"; gotoxy(x + 46, y + 3); cout << name << "  ";
        gotoxy(x + 44, y + 4); cout << "弛"; gotoxy(x + 53, y + 4); cout << "弛";
        gotoxy(x + 44, y + 5); cout << "弛"; gotoxy(x + 53, y + 5); cout << "弛";
        gotoxy(x + 44, y + 6); cout << "弛"; gotoxy(x + 53, y + 6); cout << "弛";
        gotoxy(x + 44, y + 7); cout << "弛"; gotoxy(x + 53, y + 7); cout << "弛";
        gotoxy(x + 44, y + 8); cout << "弛"; gotoxy(x + 53, y + 8); cout << "弛";
        gotoxy(x + 44, y + 9); cout << "弛"; gotoxy(x + 53, y + 9); cout << "弛";
        gotoxy(x + 44, y + 10); cout << "弛"; gotoxy(x + 53, y + 10); cout << "弛";
        gotoxy(x + 44, y + 11); cout << "弛"; gotoxy(x + 53, y + 11); cout << "弛";
        gotoxy(x + 44, y + 12); cout << "弛"; gotoxy(x + 53, y + 12); cout << "弛";
        gotoxy(x + 44, y + 13); cout << "弛"; gotoxy(x + 53, y + 13); cout << "弛";
        gotoxy(x + 44, y + 14); cout << "弛"; gotoxy(x + 53, y + 14); cout << "弛";
        gotoxy(x + 44, y + 15); cout << "弛"; gotoxy(x + 53, y + 15); cout << "弛";
        gotoxy(x + 44, y + 16); cout << "弛"; gotoxy(x + 53, y + 16); cout << "弛"; gotoxy(x + 49, y + 16); cout << "\033[33m" << act << "\033[0m";
        gotoxy(x + 44, y + 17); cout << "戌式式式式式式式式式式式式式式式式式戎";
    }
    
    //skil_input();

    //skil_tanker();
    //skil_dealer();
    //skil_healer();
}

// 蝶鑒 摹鷗 衛 蘋萄縑 轎溘腎朝 斜楚а. 歜衛煎 skil_choice 寰縑 厥橫場擠.
void skil_tanker(int i)
{
    int x = 2;
    int y = 15;

    //蘋萄1
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
    

    //蘋萄2
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

    //蘋萄3
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

    //蘋萄4
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

    //蘋萄5
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

    //蘋萄1
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

    //蘋萄2
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

    //蘋萄3
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


    //蘋萄4
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

    //蘋萄5
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


    //蘋萄1
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

    //蘋萄2
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

    //蘋萄3
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

    //蘋萄4
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


    //蘋萄5
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

// 蝶鑒 摹鷗, 棻衛 鉻晦蒂 僭橫瑤. 歜衛煎 skil_choice л熱 寰縑 厥橫場擠.
void skil_input()
{
    int x = 1;
    int y = 34;
    gotoxy(x, y); cout << "弛 \033[94m蝶鑒 摹鷗 \033[90m(1)\033[0m弛 " << "弛 \033[94m棻衛 鉻晦 \033[90m(2)\033[0m弛 ";
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

    //蘋萄1
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


    //蘋萄2
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

    //蘋萄3
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

    //蘋萄4
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

    //蘋萄5
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

    //蘋萄1
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

    //蘋萄2
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

    //蘋萄3
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


    //蘋萄4
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

    //蘋萄5
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


    //蘋萄1
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

    //蘋萄2
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

    //蘋萄3
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

    //蘋萄4
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


    //蘋萄5
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
