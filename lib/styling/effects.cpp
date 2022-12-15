#include "effects.hpp"

QGraphicsDropShadowEffect*   mildShadow(){

    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect();

    effect->setBlurRadius(3);
    effect->setXOffset(3);
    effect->setYOffset(3);
    effect->setColor(Qt::black);
    return effect;
}
