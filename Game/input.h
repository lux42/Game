#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

// Gestion des touches du clavier
void gestion_clavier(void){
    updateFPS=false;
    if(Keyboard::isKeyPressed(Keyboard::Right)){
        anim.y = Right;
        sprite_perso.move(speed , 0);
        updateFPS=true;
    }
    else if(Keyboard::isKeyPressed(Keyboard::Left)){
        anim.y = Left;
        sprite_perso.move(-speed , 0);
        updateFPS=true;
    }
    else if(Keyboard::isKeyPressed(Keyboard::Up)){
       // Jump = 1;
        updateFPS=true;
    }
    else {
        updateFPS=false;
    }


    // Limitation du mouvement en fonction de la fenètre
    if(sprite_perso.getPosition().x <= 0)
        sprite_perso.setPosition(Vector2f(0, sprite_perso.getPosition().y));

    if(sprite_perso.getPosition().x >= size_game_x-blockSize)
        sprite_perso.setPosition(Vector2f(size_game_x-blockSize, sprite_perso.getPosition().y));

    if(sprite_perso.getPosition().y <= 0)
        sprite_perso.setPosition(Vector2f(sprite_perso.getPosition().x , 0));

    if(sprite_perso.getPosition().y >= size_game_y-blockSize)
        sprite_perso.setPosition(Vector2f(sprite_perso.getPosition().x , size_game_y-blockSize));
}

#endif // INPUT_H_INCLUDED
