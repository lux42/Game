#ifndef AFFICHAGE_H_INCLUDED
#define AFFICHAGE_H_INCLUDED



// fonction d'affichage
int aff_perso(int time_f){
        // Affichage animation
        if(updateFPS){
            if(time_f >= 50){
                anim.x++;
                if(anim.x * blockSize >= perso.getSize().x)
                    anim.x = 0;
                    return 1;
            }
        sprite_perso.setTextureRect(IntRect(anim.x * blockSize, anim.y *blockSize, blockSize, blockSize));
        }else
        sprite_perso.setTextureRect(IntRect(0 , 256, blockSize, blockSize));

return 0;
}

#endif // AFFICHAGE_H_INCLUDED
