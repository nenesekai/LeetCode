#define PHYSICAL_DAMAGE 1
#define MAGIC_DAMAGE    2
#define TRUE_DAMAGE     3

#include <iostream>
#include <vector>

class Turrent
{

private:

    double health = 5000;

    const double ATK_DMG   = 152;
    const double ATK_RNG   = 750;
    const double ARMOR     = 40;
    const double MAGIC_RES = 40;

public:

    Turrent() {}

    void attack(Hero* target)
    {
        target->take_damage(ATK_DMG, TRUE_DAMAGE);
    }

    void take_damage(int dmg, int dmg_type)
    {
        switch (dmg_type)
        {

        case PHYSICAL_DAMAGE:
            health -= dmg * (100 / (100 + ARMOR));
            break;
        
        case MAGIC_DAMAGE:
            health -= dmg * (100 / (100 + MAGIC_RES));
            break;

        case TRUE_DAMAGE:
            health -= dmg;
            break;

        default:
            exit(1);

        }
    }

};

class Hero
{

protected:

    double health;
    double energy;
    double health_regan;
    double energy_regan;

    double armor;
    double magic_res;
    double crit_dmg;
    double move_spd;

    double atk_rng;
    double raw_phys_dmg;
    double raw_magic_dmg;
    double add_phys_dmg;
    double add_magic_dmg;

    bool   dead;

public:

    virtual void init();

    void respawn()
    {
        init();
    }

    void attack(Turrent* turrent)
    {
        turrent->take_damage(raw_phys_dmg + add_phys_dmg, PHYSICAL_DAMAGE);
        turrent->take_damage(raw_magic_dmg + add_magic_dmg, MAGIC_DAMAGE);
    }

    void take_damage(int dmg, int dmg_type)
    {
        switch (dmg_type)
        {

        case PHYSICAL_DAMAGE:
            health -= dmg * (100 / (100 + armor));
            break;
        
        case MAGIC_DAMAGE:
            health -= dmg * (100 / (100 + magic_res));
            break;

        case TRUE_DAMAGE:
            health -= dmg;
            break;

        default:
            exit(1);

        }

        if (health <= 0)
        {
            dead = true;
            // TODO: Add Thread that Count Down Resurraction Time
            respawn();
        }
    }

};

class Zed : public Hero
{

public:

    Zed()
    {
        init();
    }

    void init()
    {
        health       = 584;
        energy       = 200;
        health_regan = 7;
        energy_regan = 50;
        armor        = 32;
        magic_res    = 32;
        crit_dmg     = 1.75;
        move_spd     = 345;

        raw_phys_dmg = 63;
        atk_rng      = 125;

        dead = false;
    }

};

class Game
{
    
    Turrent* blue_turrent, red_turrent;

    Hero* player1;
    Hero* player2;
    Hero* player3;
    Hero* player4;
    Hero* player5;
    Hero* player6;

    Game()
    {
        blue_turrent = new Turrent();
        red_turrent  = new Turrent();

        *player1 = Zed();
        *player2 = Zed();
        *player3 = Zed();
        *player4 = Zed();
        *player5 = Zed();
        *player6 = Zed();
    }

};