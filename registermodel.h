#ifndef REGISTERMODEL_H
#define REGISTERMODEL_H

#include <QAbstractListModel>

#include <register.h>
#include <QList>

class RegisterModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum RigesterRoles {
        NameRole = Qt::UserRole + 1,
        Bit0Role,
        Bit1Role,
        Bit2Role,
        Bit3Role,
        Bit4Role,
        Bit5Role,
        Bit6Role,
        Bit7Role,
        Bit8Role,
        Bit9Role,
        Bit10Role,
        Bit11Role,
        Bit12Role,
        Bit13Role,
        Bit14Role,
        Bit15Role,
    };

    explicit RegisterModel(QObject *parent = 0);

    QHash<int, QByteArray> roleNames() const;
    QModelIndex index(int row, int column, const QModelIndex &parent) const;
    void clear();
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    void addRegister(Register *reg);

private:
    QList<Register *> registers;
};

#endif // REGISTER_H
