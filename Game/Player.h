#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <SFML/Graphics.hpp>


class Player{
public :

    Player(){}    // Default

    Player(const std::string &filePath, sf::Vector2f position, int speed);

    void MoveX(char direction,int speed);

    sf::Sprite GetSprite();

private:
    //RectangleShape player;

    sf::Image playerI;
    sf::Sprite playerS;

    int myDX; // Déplacement en X
    int myDY; // Déplacement en Y
    int mySpeed; // Vitesse
};

#endif // PLAYER_H_INCLUDED
