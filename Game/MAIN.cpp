#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace sf;
using namespace std;

int size_game_x=1920;
int size_game_y=1080;

// VARIABLES
int speed = 5;


Texture background;
Sprite  sprite_background;

Texture perso;
Sprite sprite_perso;


bool updateFPS = true;
enum Dir{Left,Right};
Vector2i anim(1, Left);


// Constantes
const int blockSize = 128;

// Pototype fonctions
void gestion_clavier(void);     // analyse le clavier et fait bouger le personnage

#include "input.h"
#include "Affichage.h"

int main()
{
    Clock clock;
    Clock time;

    RenderWindow window(VideoMode(size_game_x, size_game_y), "Game");
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(1);

    RectangleShape block1(Vector2f(400,20));


////////////////////////////////////////////////////////////////////////
    // image Background
    cout << "Ouverture de l'image <background.jpg>...";

    if(!background.loadFromFile("Graphics/Background/background.png"))
        cout << "Impossible de charger l'image <background.png>";
    else
        cout << "OK";

    cout << endl;

    // Image Personnage
    cout << "Ouverture de l'image <stickman.png>..." ;

    if(!perso.loadFromFile("Graphics/Player/stickman.png"))
        cout << "Impossible de charger l'image <stickman.png>" << endl;
    else
        cout << "OK";

    cout << endl;

    perso.setSmooth(true);

    sprite_background.setTexture(background);
    sprite_perso.setTexture(perso);
    sprite_perso.setPosition(0,1016);
////////////////////////////////////////////////////////////////////////
    block1.setFillColor(sf::Color(0, 250, 0));
    block1.setPosition(1000,1000);

    while (window.isOpen()){
        Event event;
        while (window.pollEvent(event)){
            if (event.type == Event::Closed)
                window.close();
            if(Keyboard::isKeyPressed(Keyboard::Escape))
                window.close();
        }

        gestion_clavier();


        // fonction d'affichage (retourne 1 pour restart le timer)
    if(aff_perso(time.getElapsedTime().asMilliseconds()))
        time.restart();



    // image perso "repos"
    cout << sprite_perso.getPosition().x << "," << sprite_perso.getPosition().y << "  ";


    window.draw(sprite_background);
    window.draw(block1);
    window.draw(sprite_perso);      // affichage du sprite
    window.display();
    window.clear();

    // Compteur FPS
    Time frameTime = clock.restart();
    float framerate = 1 / frameTime.asSeconds();
    cout << "FPS: " << framerate << "\r";
    }
    return 0;
}

/*




        // Affichage animation
        if(updateFPS){
            if(time.getElapsedTime().asMilliseconds() >= 50){
                anim.x++;
                if(anim.x * blockSize >= perso.getSize().x)
                    anim.x = 0;
            time.restart();
            }
        sprite_perso.setTextureRect(IntRect(anim.x * blockSize, anim.y *blockSize, blockSize, blockSize));
        }else
        sprite_perso.setTextureRect(IntRect(0 , 256, blockSize, blockSize));






        */
