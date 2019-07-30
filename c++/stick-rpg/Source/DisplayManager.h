#ifndef DISPLAYMANAGER_H
#define DISPLAYMANAGER_H

class Display
{
    public:
        static Display& get();

        const sf::RenderWindow& getRaw() const;



    private:

};


#endif // DISPLAYMANAGER_H
