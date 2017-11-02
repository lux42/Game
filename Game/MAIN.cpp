#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>



using namespace sf;
using namespace std;

void gestion_clavier(void);

// VARIABLES

int speed = 3;

Texture perso;
Sprite sprite_perso;
enum Dir{Down,Left,Right,Up};
Vector2i anim(1, Down);
bool updateFPS = true;

// Constantes

const int blockSize = 64;



int main()
{
    cout << "Bienvenue! :D" << endl;

    Clock clock;
    Clock time;


    float fpsCount = 0;
    float switchFps = 100;
    float fpsSpeed = 500;

    RenderWindow window(VideoMode(800, 480), "Game ");
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(1);




    if(!perso.loadFromFile("player.png")){
    cout << "Impossible de charger l'image" << endl;
    }
    perso.setSmooth(true);

    sprite_perso.setTexture(perso);



    while (window.isOpen())
    {


        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }



            gestion_clavier();



        if(updateFPS)
            fpsCount += fpsSpeed * time.restart().asSeconds();
        else
            fpsCount = 0;



        if(fpsCount >= switchFps){
            fpsCount = 0;
            anim.x++;
            if(anim.x * blockSize >= perso.getSize().x)
                anim.x = 0;
        }
        sprite_perso.setTextureRect(IntRect(anim.x * blockSize, anim.y *blockSize, blockSize, blockSize));









        //window.clear();
        window.draw(sprite_perso);      // affichage du sprite
        window.display();

        window.clear();



    Time frameTime = clock.restart();

    // Compteur FPS
    float framerate = 1 / frameTime.asSeconds();
    cout << "FPS: " << framerate << "\r";
    }

    return 0;
}


void gestion_clavier(void){
    if(Keyboard::isKeyPressed(Keyboard::Right)){
        anim.y = Right;
        sprite_perso.move(speed , 0);
    }
    if(Keyboard::isKeyPressed(Keyboard::Left)){
        anim.y = Left;
        sprite_perso.move(-speed , 0);
    }
    if(Keyboard::isKeyPressed(Keyboard::Up)){
        anim.y = Up;
        sprite_perso.move(0 , -speed);
    }
    if(Keyboard::isKeyPressed(Keyboard::Down)){
        anim.y = Down;
        sprite_perso.move(0 , speed);
    }
}
