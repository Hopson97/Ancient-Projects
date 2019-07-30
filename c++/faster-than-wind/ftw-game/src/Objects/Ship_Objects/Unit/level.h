#ifndef LEVEL_H
#define LEVEL_H


class Level
{
    public:
                        Level(const int initialLevel);

                void    addExp              (  const int exp );
        const   int     getLevel            () const;
        const   int     getCurrentExp       () const;
        const   int     getExpForNextLvl    () const;
        const   int     getTotalExp         () const;

    private:
                void    checkForLvlUp       ();
        const   int     getExpOverflow      ();
                void    levelUp             ();
        const   bool    levelUpPossible     ();



    private:
   static const int MAXIMUM_LEVEL   { 100 };

                int mCurrentLevel   { 1  };
                int mCurrentExp     { 0  };
                int mExpAtNextLvl   { 10 };
                int mTotalExp       { 0  };
};

#endif // LEVEL_H
