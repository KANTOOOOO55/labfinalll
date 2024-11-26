#include "user.h"


User::User() {}

QString User::getEmail() const { //getter returns email of the user when asked
    return email;
}

void User::setEmail(const QString &value) { //setter updates the user's email
    email = value;
}

QString User::getPassword() const { //getter for password attribute, return the password of the user as a q string
    return password;
}

void User::setPassword(const QString &value) { //we use the same idea, get password to read it and set password to change it
    password = value;
}
