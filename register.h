#ifndef REGISTER_H
#define REGISTER_H

#include <QString>

class Register
{
public:
    explicit Register(const QString &name, char value);

    void setValue(char value) {
        d_value = value;
    }

    char value() {
        return d_value;
    }

    void setName(QString name) {
        d_name = name;
    }

    QString name() {
        return d_name;
    }

private:
    char d_value;
    QString d_name;
};

#endif // REGISTER_H
