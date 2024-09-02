#include "Entity.h"
#include "Graphic.h"

void Entity::showInfo() {}
int Entity::sufferDmg(int dmg, Entity* e, vector<Entity*>& entity, bool reflect) {
    
    int x = 2;
    int y = 18;
    e->finalDfs = e->dfs * (1 + e->incdfs);
    if (e->getHidden()) {
        
        gotoxy(x, y + 2); cout << e->getName() << "이(가) 공격을 회피하였습니다." << endl;
        _getch();

        return -1;
    }
    else {
        if (reflect && e->reflect) {
            if (e->monster || rdfunc() % 10 < 2) {
                gotoxy(x, y + 2); cout << e->getName() << "이(가) 공격을 반사하였습니다" << "(-" << dmg << ")" << endl;
                y += 2;
                _getch();
                return -dmg;
            }
        }
        if ((e->shield >= (dmg - e->finalDfs)) && (dmg > e->finalDfs)) {
            e->reflectShield -= dmg - e->finalDfs;
            if (e->reflectShield <= 0) e->reflect = false;
            e->shield -= dmg - e->finalDfs;
            gotoxy(x, y + 2); cout << e->getName() << "의 ";
            cout << "쉴드가 " << dmg - e->finalDfs << "만큼 흡수하였습니다. (남은 쉴드: " << e->shield << ")" << endl;
            y += 2;
            _getch();
            return 0;
        }
        else {
            e->finalDmg = dmg - e->shield;
            e->reflect = false;
            gotoxy(x, y + 2); if (e->shield > 0) cout << dmg - e->finalDfs << " 데미지로 인해 " << e->getName() << "의 쉴드가 파괴되었습니다." << endl;
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
        gotoxy(x, y + 2); cout << e->getName() << "의 방어력이 " << e->finalDfs << "이므로 데미지가 들어가지 않았습니다" << endl;
        _getch();
        return 0;
    }
    else {
        donedmg = dmg - e->finalDfs;
        gotoxy(x, y + 2); cout << e->getName() << "(방어력 " << e->finalDfs << ")" << "에게 -" << donedmg << " 데미지를 입혔습니다." << endl;
        e->hitHp(donedmg);
        gotoxy(x, y + 4); cout << e->getName() << "의 체력: " << e->getHp() << endl;
        _getch();
        return donedmg;
    }
}
Entity* Entity::target(vector<Entity*>& entity) {
    auto e = entity[rdfunc() % entity.size()];
    if (aggro) {
        cout << name << "은(는) 어그로에 걸려있습니다." << endl;
        for (auto it = entity.begin(); it != entity.end(); it++) {
            if (charseq == (*it)->charseq) {
                e = *it;
                break;
            }
        }
        aggro = false;
    }
    if (e->instead != NULL) {
        cout << e->name << "은(는) 대신 맞기가 적용되어 있습니다." << endl;
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
    cout << "오버라이딩 안됨" << endl;
    Entity::sufferDmg(temp + dmg, e, entity["아군"]);
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
            gotoxy(x, y + 2); cout << name << "는 신성한 힘이 지속 중입니다. (남은 턴: " << --holy << ")" << endl;
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
            gotoxy(x, y + 2); cout << name << "는 악어의 눈물이 지속 중입니다. (남은 턴: " << --tear << ")" << endl;
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
            gotoxy(x, y + 2); cout << name << "은 탈피가 지속 중입니다. (남은 턴: " << --molt << ")" << endl;
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
            gotoxy(x, y + 2); cout << name << "은(는) 기선 제압이 지속 중입니다. (남은 턴: " << --overpower << ")" << endl;
            y += 2;
            _getch();
        }
            
    }
    if (auracount != NULL) {
        if (auracount <= 0) {
            auracount = NULL;
        }
        else {
            gotoxy(x, y + 2); cout << name << "는 영원의 오라가 지속 중입니다. (남은 턴: " << --auracount << ")" << endl;
            y += 2;
            setHp(aura[auracount]);
            gotoxy(x, y + 2); cout << name << "이 체력 " << aura[auracount] << "을 회복하였습니다." << endl;
            y += 2;
            _getch();
        }
    }
    if (stern) {
        gotoxy(x, y + 2); cout << getName() << "가 행동할 수 없습니다." << endl;
        y += 2;
        _getch();
        stern = false;
    }
    else {
        if (entity["아군"].empty()) {
            gotoxy(x, y + 2); cout << "타켓을 정할 수 없습니다." << endl;
            return;
        }
        else {
            auto* e = target(entity["아군"]);
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
        gotoxy(x, y + 2); cout << e->getName() << "이(가) 사망하였습니다." << endl;
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
    gotoxy(x, y + 3); cout << "행동력: " << getAct() << "     "; 

    
    /*
    gotoxy(x + 4, y + 1); cout << "(상태이상)"; // 괄호 안에 상태이상 변수
    cout << getName() << endl << "방어력: " << getDfs() * (1 + getIncdfs());
    cout << "\t체력: " << getHp() << "(" << getShield() << ")";
    if (act >= 0) cout << "\t행동력: " << getAct();
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