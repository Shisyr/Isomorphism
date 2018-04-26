#-------------------------------------------------
#
# Project created by QtCreator 2018-04-17T21:01:14
#
#-------------------------------------------------

win32:{

    file_pathes += "\"$$PWD/Users/Mukhamed/Downloads/discrete.exe\""

    CONFIG(release, debug|release):{
        destination_pathes += $$OUT_PWD/release/
        destination_pathes += Path/To/Deploy/Directory
    }
    else:CONFIG(debug, debug|release):{
        destination_pathes += $$OUT_PWD/debug/
    }

    for(file_path,file_pathes){
        file_path ~= s,/,\\,g
        for(dest_path,destination_pathes){
            dest_path ~= s,/,\\,g
            QMAKE_POST_LINK += $$quote(xcopy $${file_path} $${dest_path} /I /Y $$escape_expand(\n\t))
         }
    }
}
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Isomorphism
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    solution.cpp \
    matrix.cpp

HEADERS  += mainwindow.h \
    solution.h \
    matrix.h

FORMS    += mainwindow.ui \
    matrix.ui
