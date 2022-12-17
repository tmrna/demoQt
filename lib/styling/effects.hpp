#ifndef EFFECTS_HPP
#define EFFECTS_HPP

#include <QGraphicsDropShadowEffect>
#include <QColor>

// Shadows

// Qt::black, radius = 3, x = 1, y = 1
QGraphicsDropShadowEffect* skinnyShadow();

// Color, same settings as skinny
QGraphicsDropShadowEffect* skinnyShadow(const QColor&);

//--------------------------------------------------------------------------------------------------------

// Qt::black, radius = 3, x = 3, y = 3
QGraphicsDropShadowEffect* mildShadow();

// Color, same settings as mild
QGraphicsDropShadowEffect* mildShadow(const QColor&);

//---------------------------------------------------------------------------------------------------------

// Qt::black, radius = 3, x = 5, y = 5
QGraphicsDropShadowEffect* moderateShadow();

// Color, same settings as moderate
QGraphicsDropShadowEffect* moderateShadow(const QColor&);

//--------------------------------------------------------------------------------------------------------

// Qt::black, radius = 3, x = 7, y = 7
QGraphicsDropShadowEffect* heavyShadow();

// Color, same settings as heavy
QGraphicsDropShadowEffect* heavyShadow(const QColor&);

//--------------------------------------------------------------------------------------------------------

// returns shadow effect using color, radius, x-offset, y-offset
QGraphicsDropShadowEffect* customShadow(const QColor&, int, int, int);

//--------------------------------------------------------------------------------------------------------

// sets the shadow to the new settings
void setShadow(QGraphicsDropShadowEffect*, const QColor& color, int radius, int xOffset, int yOffset);

//--------------------------------------------------------------------------------------------------------

#endif
