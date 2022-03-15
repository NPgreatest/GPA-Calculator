QT       += core gui


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    aboutwindow.cpp \
    addalgorithmwindow.cpp \
    algorithm.cpp \
    course.cpp \
    main.cpp \
    calculatorwindow.cpp \
    transcript.cpp

HEADERS += \
    aboutwindow.h \
    addalgorithmwindow.h \
    algorithm.h \
    calculatorwindow.h \
    course.h \
    transcript.h

FORMS += \
    aboutwindow.ui \
    addalgorithmwindow.ui \
    calculatorwindow.ui


CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Images.qrc \
    translator.qrc \

TRANSLATIONS  =  tr_zh.ts tr_en.ts
