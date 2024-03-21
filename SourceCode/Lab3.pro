QT       += core gui
QT += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    departmentview.cpp \
    doctoreditview.cpp \
    doctorview.cpp \
    doctorwelcomeview.cpp \
    idatabase.cpp \
    loginview.cpp \
    main.cpp \
    masterview.cpp \
    medicineditview.cpp \
    patienteditview.cpp \
    patientview.cpp \
    recordeditview.cpp \
    recordview.cpp \
    welcomeview.cpp

HEADERS += \
    departmentview.h \
    doctoreditview.h \
    doctorview.h \
    doctorwelcomeview.h \
    idatabase.h \
    loginview.h \
    masterview.h \
    medicineditview.h \
    patienteditview.h \
    patientview.h \
    recordeditview.h \
    recordview.h \
    welcomeview.h

FORMS += \
    departmentview.ui \
    doctoreditview.ui \
    doctorview.ui \
    doctorwelcomeview.ui \
    loginview.ui \
    masterview.ui \
    medicineditview.ui \
    patienteditview.ui \
    patientview.ui \
    recordeditview.ui \
    recordview.ui \
    welcomeview.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    lab3.qrc
