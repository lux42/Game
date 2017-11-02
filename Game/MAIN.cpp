#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Player.h"

using namespace sf;
using namespace std;

int size_game_x=1920;
int size_game_y=1080;


// Constantes
const int blockSize = 128;

// Pototype fonctions
void gestion_clavier(void);


int main()
{
    Clock fpsC;
    Clock time;

    RenderWindow window(VideoMode(size_game_x, size_game_y), "Game", Style::Titlebar | Style::Close);
    window.setKeyRepeatEnabled(true);
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);

    Player player1("Graphics/Player/player.png",{100,100},5);


    const int moveSpeed = 10.0;


////////////////////////////////////////////////////////////////////////


    // Main loop
    while (window.isOpen()){

        Event event;

        while (window.pollEvent(event)){
            switch (event.type){
                case Event::Closed:
                    window.close();
                break;
            }


            if(Keyboard::isKeyPressed(Keyboard::Left))
                player1.MoveX('L',moveSpeed);
            else if(Keyboard::isKeyPressed(Keyboard::Right))
                player1.MoveX('R',moveSpeed);

        }




    window.draw(player1.GetSprite());
    window.display();
    window.clear();



    // Compteur FPS
    Time frameTime = fpsC.restart();
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
