#include "Entity.h"
#include "Graphic.h"

void Entity::showInfo() {}
int Entity::sufferDmg(int dmg, Entity* e, vector<Entity*>& entity, bool reflect) {
    
    int x = 2;
    int y = 18;
    e->finalDfs = e->dfs * (1 + e->incdfs);
    if (e->getHidden()) {
        
        gotoxy(x, y + 2); cout << e->getName() << "��(��) ������ ȸ���Ͽ����ϴ�." << endl;
        _getch();

        return -1;
    }
    else {
        if (reflect && e->reflect) {
            if (e->monster || rdfunc() % 10 < 2) {
                gotoxy(x, y + 2); cout << e->getName() << "��(��) ������ �ݻ��Ͽ����ϴ�" << "(-" << dmg << ")" << endl;
                y += 2;
                _getch();
                return -dmg;
            }
        }
        if ((e->shield >= (dmg - e->finalDfs)) && (dmg > e->finalDfs)) {
            e->reflectShield -= dmg - e->finalDfs;
            if (e->reflectShield <= 0) e->reflect = false;
            e->shield -= dmg - e->finalDfs;
            gotoxy(x, y + 2); cout << e->getName() << "�� ";
            cout << "���尡 " << dmg - e->finalDfs << "��ŭ ����Ͽ����ϴ�. (���� ����: " << e->shield << ")" << endl;
            y += 2;
            _getch();
            return 0;
        }
        else {
            e->finalDmg = dmg - e->shield;
            e->reflect = false;
            gotoxy(x, y + 2); if (e->shield > 0) cout << dmg - e->finalDfs << " �������� ���� " << e->getName() << "�� ���尡 �ı��Ǿ����ϴ�." << endl;
            y += 2;
            _getch();
            return Entity::decreaseHp(e->finalDmg, e, entity);
        }
    }
}
int Entity::decreaseHp(int dmg, Entity* e, vector<Entity*>& entity) {

    screen_reset();

    int x = 2;
    int y = 14;

    int donedmg = 0;
    if ((dmg - e->finalDfs) <= 0) {
        gotoxy(x, y + 2); cout << e->getName() << "�� ������ " << e->finalDfs << "�̹Ƿ� �������� ���� �ʾҽ��ϴ�" << endl;
        _getch();
        return 0;
    }
    else {
        donedmg = dmg - e->finalDfs;
        gotoxy(x, y + 2); cout << e->getName() << "(���� " << e->finalDfs << ")" << "���� -" << donedmg << " �������� �������ϴ�." << endl;
        e->hitHp(donedmg);
        gotoxy(x, y + 4); cout << e->getName() << "�� ü��: " << e->getHp() << endl;
        _getch();
        return donedmg;
    }
}
Entity* Entity::target(vector<Entity*>& entity) {
    auto e = entity[rdfunc() % entity.size()];
    if (aggro) {
        cout << name << "��(��) ��׷ο� �ɷ��ֽ��ϴ�." << endl;
        for (auto it = entity.begin(); it != entity.end(); it++) {
            if (charseq == (*it)->charseq) {
                e = *it;
                break;
            }
        }
        aggro = false;
    }
    if (e->instead != NULL) {
        cout << e->name << "��(��) ��� �±Ⱑ ����Ǿ� �ֽ��ϴ�." << endl;
        for (auto it = entity.begin(); it != entity.end(); it++) {
            if (e->instead == (*it)->charseq) {
                e = *it;
                break;
            }
        }
        e->instead = NULL;
    }
    if (hidden) hidden = false;
    return e;
}
void Entity::useSkill(const int n, Entity* e, map<string, vector<Entity*>>& entity, map<string, vector<Skill>>& buff) {
    cout << "�������̵� �ȵ�" << endl;
    Entity::sufferDmg(temp + dmg, e, entity["�Ʊ�"]);
}
void Entity::attack(map<string, vector<Entity*>>& entity, map<string, vector<Skill>>& buff) {
    int x = 2;
    int y = 14;
    screen_reset();
    
    reflect = false;
    reflectDmg = 0;
    if (holy != NULL) {
        if (holy <= 0) {
            incdmg -= 0.2f;
            holy = NULL;
        }
        else {
            gotoxy(x, y + 2); cout << name << "�� �ż��� ���� ���� ���Դϴ�. (���� ��: " << --holy << ")" << endl;
            y += 2;
            _getch();
        }
            
    }
    if (tear != NULL) {
        if (tear <= 0) {
            incdmg -= 0.05f;
            tear = NULL;
        }
        else {
            gotoxy(x, y + 2); cout << name << "�� �Ǿ��� ������ ���� ���Դϴ�. (���� ��: " << --tear << ")" << endl;
            y += 2;
            _getch();
        }
            
    }
    if (molt != NULL) {
        if (molt <= 0) {
            incdmg -= 0.07f;
            incdfs -= 0.07f;
            molt = NULL;
        }
        else {
            gotoxy(x, y + 2); cout << name << "�� Ż�ǰ� ���� ���Դϴ�. (���� ��: " << --molt << ")" << endl;
            y += 2;
            _getch();
        }
           
    }
    if (overpower != NULL) {
        if (overpower <= 0) {
            for (; overpowercount != 0; overpowercount--) incdmg += 0.1f;
            overpower = NULL;
        }
        else {
            gotoxy(x, y + 2); cout << name << "��(��) �⼱ ������ ���� ���Դϴ�. (���� ��: " << --overpower << ")" << endl;
            y += 2;
            _getch();
        }
            
    }
    if (auracount != NULL) {
        if (auracount <= 0) {
            auracount = NULL;
        }
        else {
            gotoxy(x, y + 2); cout << name << "�� ������ ���� ���� ���Դϴ�. (���� ��: " << --auracount << ")" << endl;
            y += 2;
            setHp(aura[auracount]);
            gotoxy(x, y + 2); cout << name << "�� ü�� " << aura[auracount] << "�� ȸ���Ͽ����ϴ�." << endl;
            y += 2;
            _getch();
        }
    }
    if (stern) {
        gotoxy(x, y + 2); cout << getName() << "�� �ൿ�� �� �����ϴ�." << endl;
        y += 2;
        _getch();
        stern = false;
    }
    else {
        if (entity["�Ʊ�"].empty()) {
            gotoxy(x, y + 2); cout << "Ÿ���� ���� �� �����ϴ�." << endl;
            return;
        }
        else {
            auto* e = target(entity["�Ʊ�"]);
            int n = rdfunc() % getSkillNum();
            useSkill(n, e, entity, buff);
            if (cursedDoll) {
                cursedDoll = false;
                incdmg += 0.15f;
            }
        }
    }
}
bool Entity::entityErase(Entity* e, vector<Entity*>& entity) {
    
    screen_reset();

    int x = 2;
    int y = 14;

    if (e->getHp() <= 0) {
        auto it = std::find(entity.begin(), entity.end(), e);
        gotoxy(x, y + 2); cout << e->getName() << "��(��) ����Ͽ����ϴ�." << endl;
        _getch();
        return true;
    }
    return false;
}
void Entity::insertUpperBound(vector<Skill>& buff, Skill& skill) {
    auto it = std::upper_bound(buff.begin(), buff.end(), skill);
    buff.insert(it, skill);
}
void Entity::print(int x, int y) {

    gotoxy(x, y + 1); cout << getName(); 
    gotoxy(x, y + 2); cout << "HP: " << getHp() << " / " << getMaxHp() << " (+ " << getShield() << ")     "; 
    gotoxy(x, y + 3); cout << "�ൿ��: " << getAct() << "     "; 

    
    /*
    gotoxy(x + 4, y + 1); cout << "(�����̻�)"; // ��ȣ �ȿ� �����̻� ����
    cout << getName() << endl << "����: " << getDfs() * (1 + getIncdfs());
    cout << "\tü��: " << getHp() << "(" << getShield() << ")";
    if (act >= 0) cout << "\t�ൿ��: " << getAct();
    cout << endl;
    */
}
void Entity::stage_init() {
    act = MaxAct;
    incdmg = 0;
    incdfs = 0;
    shield = 0;
    hidden = false;
    stern = false;
    aggro = false;
    instead = NULL;
    overpower = 0;
    cursedDoll = false;
    reflect = false;
    reflectShield = 0;
    reflectDmg = 0;
    overpower = 0;
    guard = 0;
}