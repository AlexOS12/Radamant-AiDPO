#ifndef PERSON_H
#define PERSON_H

#include <QString>

struct Person {
    QString lastname;
    QString passport;

    Person(QString lastname, QString passport) {
        this->lastname = lastname;
        this->passport = passport;
    }
};

#endif // PERSON_H
