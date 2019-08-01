#include "soundeffect.h"

SoundEffect :: SoundEffect ( const sf::SoundBuffer& sfxBuffer )
:   m_delay ( sfxBuffer.getDuration().asSeconds() )
{
    m_sound.setBuffer( sfxBuffer );

}

void
SoundEffect :: play()
{
    if ( !m_hasPlayedOnce ) m_replayClock.restart();

    if ( m_replayClock.getElapsedTime().asSeconds() >= m_delay )
    {
        m_hasPlayedOnce = true;
        m_replayClock.restart();
        m_sound.play();
    }


}

void
SoundEffect :: stop()
{
    m_sound.stop();
}
