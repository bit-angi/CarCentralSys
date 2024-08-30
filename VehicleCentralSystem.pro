QT       += core gui network multimedia sql multimediawidgets xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    MapWidget.cpp \
    audio.cpp \
    chatserver.cpp \
    chatwindow.cpp \
    findmima.cpp \
    gpswindow.cpp \
    homewindow.cpp \
    http.cpp \
    littlepicwidget.cpp \
    login.cpp \
    lrcwidget.cpp \
    main.cpp \
    mainwindow.cpp \
    mainwindow2.cpp \
    musicwindow.cpp \
    picplayerwidget.cpp \
    register.cpp \
    searchwidget.cpp \
    speech.cpp \
    videowindow.cpp \
    widget.cpp


HEADERS += \
    ClickableLabel.h \
    MapWidget.h \
    chatserver.h \
    chatwindow.h \
    findmima.h \
    gpswindow.h \
    homewindow.h \
    littlepicwidget.h \
    login.h \
    lrcwidget.h \
    mainwindow.h \
    musicwindow.h \
    picplayerwidget.h \
    register.h \
    searchwidget.h \
    videowindow.h \
    weathertool.h \
    audio.h \
    http.h \
    speech.h \
    weatherdata.h \
    widget.h \
    mainwindow2.h \

FORMS += \
    chatwindow.ui \
    findmima.ui \
    gpswindow.ui \
    homewindow.ui \
    littlepicwidget.ui \
    login.ui \
    lrcwidget.ui \
    mainwindow.ui \
    musicwindow.ui \
    picplayerwidget.ui \
    register.ui \
    videowindow.ui \
    widget.ui \
    mainwindow2.ui \


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc \
    background.qrc \
    img.qrc \
    main.qrc \
    new.qrc \
    pic.qrc \
    res.qrc \
    res1.qrc

