#ifndef MUSIC_M_H
#define MUSIC_M_H

#include <SFML/Audio.hpp>
#include <map>

enum class Music_Name
{
    Hell_March
};

namespace Manager
{

class Music_M
{
    public:
        Music_M();

        void
        playSong ( const Music_Name name );

    private:
        void
        loadSongs();

        void
        loadSong ( const Music_Name name, const std::string& filePath );

        std::map<Music_Name, sf::Music> m_music;
};

}

#endif // MUSIC_M_H
