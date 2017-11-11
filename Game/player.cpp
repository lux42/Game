#include <iostream>
#include "Player.h"

using namespace std;
using namespace sf;

Player::Player(const string &filePath, Vector2f position, int speed)
:  myDX(speed), myDY(speed), mySpeed(speed)
{
    if(!playerI.loadFromFile(filePath)){
        cout << "Error player.png" << endl;
    }else{
    playerS.setPosition(position);
    }
}

void Player::MoveX(char direction, int speed){
    if(direction == 'R')
    playerS.move(speed,0);
    if(direction == 'L')
    playerS.move(-speed,0);

}







Sprite Player::GetSprite()
{
    return playerS;
}
