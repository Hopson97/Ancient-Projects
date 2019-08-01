#ifndef WORLD_H
#define WORLD_H

#include "game.h"
#include "level.h"
#include "Entities/player.h"
#include "Guns/bullet.h"
#include "Particles/gravity_particles.h"
#include "Entities/test_enemy.h"

typedef Gravity_Particles                       GravParts;
typedef std::unique_ptr<Bullet>                 BulletPtr;
typedef std::unique_ptr<Test_Enemy>             EnemyPtr;
typedef std::vector<std::unique_ptr<Entity>>    EntityPtrVect;

class World
{
    public:
        World( Game& game );

        void
        input               ();

        void
        update              ( const float dt );

        void
        draw                ( sf::RenderWindow& window );

        void
        addBullet           ();

        void
        addEye              ();

        const Player&
        getPlayer           () const;

    private:
        void
        updateEntites       ( const float dt );

        template <typename T>
        void
        iterateEntitiess    ( std::vector<std::unique_ptr<T>>& entities, const float dt )
        {
            static_assert ( std::is_base_of < Entity, T > :: value, "T is not derived from Base" );

            for ( size_t i = 0 ; i < entities.size() ; i++ )
            {
                entities.at( i )->update ( dt );
                if ( !entities.at( i )->isAlive() )
                {
                    entities.erase( entities.begin() + i );
                }
            }
        }

    private:
        Game&   m_game;
        Level   m_level;
        Player  m_player;

        GravParts   m_blood;
        GravParts   m_dirt;

        std::vector<EnemyPtr> m_enemies;
        std::vector<BulletPtr>     m_bullets;
};

#endif // WORLD_H
