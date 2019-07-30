#include "game.h"

Game::Game()
{
    this->window.create(sf::VideoMode(gbl::WIN_WIDTH, gbl::WIN_HEIGHT), "Name");
    this->window.setFramerateLimit(60);

    std::string groundBG = "res/backgroundBegin.png";
    this->setBg(groundBG);
    this->bg.setPosition(0, gbl::WIN_HEIGHT - 100);
    this->initLoop();
}

/*
======================================
Game::initLoop() has the main loop which shows up at the start
======================================
*/
void Game::initLoop()
{
    std::string path = "res/rocketStand.png";
    sf::Texture t;
    t.setSmooth(true);
    t.loadFromFile(path);
    sf::Sprite s(t);
    s.setPosition(75, gbl::WIN_HEIGHT - 500);

    this->addClouds(50);

    bgColor.g = 100;
    bgColor.b = 255;

    Button start(150,50,500,200,"Start");

    while(window.isOpen())
    {

        this->handleEvents();
        this->window.draw(bg);
        for(auto &bgOb: bgObjs) bgOb->logic(window, false, 0);
        //Logic below here

        this->player.draw(window);
        this->window.draw(s);

        if(start.buttonClicked(window))
            this->startPlay(s);

        //Logic above here
        this->window.display();
    }
}

void Game::startPlay(sf::Sprite &s)
{
    Math m;

    this->camera.setSize(gbl::WIN_WIDTH, gbl::WIN_HEIGHT);

    bool phase = false;

    sf::RectangleShape r;
    sf::Vector2f size(gbl::WIN_WIDTH + 50, gbl::WIN_HEIGHT + 50);
    r.setSize(size);
    r.move(-20, -20);
    sf::Color c;
    int alpha = 0;
    c.a = alpha;
    r.setFillColor(c);
    while(window.isOpen())
    {

        this->handleEvents();
        this->window.setView(camera);
        this->camera.setCenter(gbl::WIN_WIDTH / 2 + m.randRange(-10, 10),
                                gbl::WIN_HEIGHT / 2 + m.randRange(-10, 10));

        this->window.draw(bg);
        for(auto &bgOb: bgObjs) bgOb->logic(window, false, 0);
        this->player.draw(window);
        this->window.draw(s);
        phase = player.moveUp();
        if(phase)
        {
            std::cout << alpha << std::endl;
            if(alpha != 255)
            {
                alpha++;
                c.a = alpha;
                r.setFillColor(c);
                this->window.draw(r);
            }
            else this->loop();

        }

        this->window.display();
    }
}

/*
======================================
Game::loop() has the main loop
======================================
*/
void Game::loop()
{
    this->player.initPlay();
    this->setBg("res/bg2.png");
    bg.setPosition(bg.getPosition().x, 100);
    sf::IntRect bgi(0,0,800,500);
    bg.setTextureRect(bgi);
    while(window.isOpen())
    {
        handleEvents();
        window.draw(bg);
        for(auto &bgOb: bgObjs) bgOb->logic(window, true, this->player.getYVel());

        //Logic below here
        this->player.logic(window);

        //Logic above here

        window.display();
    }
}

/*
======================================
Game::addCloud() adds clouds into a vector
======================================
*/
void Game::addClouds(int amount)
{
    sf::Texture cloudtx;
    sf::Texture cloudtx2;
    std::string cloudtxp = "res/cloud1.png";
    std::string cloudtxp2 = "res/cloud2.png";

    if(!cloudtx.loadFromFile(cloudtxp)){};
    if(!cloudtx2.loadFromFile(cloudtxp2)){};

    cloudtx.setSmooth(true);
    cloudtx2.setSmooth(true);

    for(int i = 0; i < amount; i++)
    {
        Math m;
        int tx = m.randRange(1,2);
        if(tx == 1)
        {
            std::unique_ptr<Cloud> cloud(new Cloud(cloudtx));
            bgObjs.push_back(std::move(cloud));
        }
        else if(tx == 2)
        {
            std::unique_ptr<Cloud> cloud(new Cloud(cloudtx));
            bgObjs.push_back(std::move(cloud));
        }

    }
}



/*
======================================
Game::handleEvents() handles any window events, such as closing the window
======================================
*/
void Game::handleEvents()
{
    this->window.clear(bgColor);
    while(window.pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
        {
            this->window.close();
        }
    }
}

/*
======================================
Game::setBg sets the background texture of the screen
======================================
*/
void Game::setBg(std::string path)
{
    if(!bgT.loadFromFile(path))
    {
        std::cout << "Background could not be loaded" << std::endl;
    }
    else
    {
        this->bg.setTexture(bgT);
    }
}












