#include "effects.hpp"

//#####################  Skinny shadow  #######################
QGraphicsDropShadowEffect*   skinnyShadow(){

    return skinnyShadow(Qt::black);

}

QGraphicsDropShadowEffect*   skinnyShadow(const QColor& Color){

    return customShadow(Color, 3, 1, 1);

}

//##########################   mild shadow ################################

QGraphicsDropShadowEffect*   mildShadow(){

    return mildShadow(Qt::black);

}

QGraphicsDropShadowEffect*   mildShadow(const QColor& Color){

    return customShadow(Color, 3, 3, 3);

}

//########################  moderate shadow ###########################

QGraphicsDropShadowEffect*   moderateShadow(){

    return moderateShadow(Qt::black);

}

QGraphicsDropShadowEffect*   moderateShadow(const QColor& Color){

    return customShadow(Color, 3, 5, 5);

}

//#############################  heavy shadow ###############

QGraphicsDropShadowEffect*   heavyShadow(){

    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect();

    effect->setBlurRadius(30);
    effect->setXOffset(7);
    effect->setYOffset(7);
    effect->setColor(Qt::black);
    return effect;

}

QGraphicsDropShadowEffect*   heavyShadow(const QColor& Color){

    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect();

    effect->setBlurRadius(3);
    effect->setXOffset(7);
    effect->setYOffset(7);
    effect->setColor(Color);
    return effect;

}

//############################ custom shadow #################

QGraphicsDropShadowEffect* customShadow(const QColor& Color, int radius, int xOffset, int yOffset){

    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect();

    effect->setBlurRadius(radius);
    effect->setXOffset(xOffset);
    effect->setYOffset(yOffset);
    effect->setColor(Color);

    return effect;
}
