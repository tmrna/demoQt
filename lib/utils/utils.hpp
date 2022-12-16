#ifndef UTILS_HPP
#define UTILS_HPP

#include <QString>
#include <QFile>
#include <QJsonDocument>
#include <QPair>
#include <algorithm>
#include <QGlobalStatic>

namespace utils{

    // read the .qss file and return the style.
    QString getStyling(const char* path);
    QString getGeneralStyling();
}

#endif
