#ifndef TEST_ENEMY_H
#define TEST_ENEMY_H

#include "entity.h"
#include "player.h"
#include "../Particles/gravity_particles.h"
#include "../Guns/bullet.h"

#include <memory>

typedef std::unique_ptr<Bullet> BulletPtr;

class Test_Enemy    :   public Entity
{
    public:
        Test_Enemy( const Game& game, const Level& level, const Player& player,
                    Gravity_Particles& blood, std::vector<BulletPtr>& bullets );

        void
        uniqueUpdate( const float dt );

    protected:

    private:
        const Player&               m_player;

        float                       m_accleration = 2;
        float                       m_maxVel      = 200;

        Gravity_Particles&          m_blood;

        std::vector<BulletPtr>&     m_bullets;
};

#endif // TEST_ENEMY_H
