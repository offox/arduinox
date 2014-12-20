#include "registermodel.h"

RegisterModel::RegisterModel(QObject *parent) :
    QAbstractListModel(parent)
{
}

QHash<int, QByteArray> RegisterModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    roles[Bit0Role] = "bit0";
    roles[Bit1Role] = "bit1";
    roles[Bit2Role] = "bit2";
    roles[Bit3Role] = "bit3";
    roles[Bit4Role] = "bit4";
    roles[Bit5Role] = "bit5";
    roles[Bit6Role] = "bit6";
    roles[Bit7Role] = "bit7";
    return roles;
}

QModelIndex RegisterModel::index(int row, int column,
                                 const QModelIndex &parent) const{
    Q_UNUSED(parent);
    if (row >= registers.size()) {
        return QModelIndex();
    }

    Register *reg = registers.at(row);
    return createIndex(row, column, reg);
}

void RegisterModel::clear() {
    beginResetModel();
    registers.clear();
    endResetModel();
}

int RegisterModel::rowCount(const QModelIndex &parent) const {
    if(parent.isValid()) {
        return 0;
    }

    return registers.size();
}

QVariant RegisterModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid()) {
        return QVariant();
    }

    if (index.row() >= registers.size() || index.row() < 0) {
        return QVariant();
    }

    if (index.isValid()) {
        Register *reg = registers.at(index.row());

        if (role == Bit0Role)
            return reg->value() & 0x01 ? true : false;
        else if (role == Bit1Role)
            return reg->value() & 0x02 ? true : false;
        else if (role == Bit2Role)
            return reg->value() & 0x04 ? true : false;
        else if (role == Bit3Role)
            return reg->value() & 0x08 ? true : false;
        else if (role == Bit4Role)
            return reg->value() & 0x10 ? true : false;
        else if (role == Bit5Role)
            return reg->value() & 0x20 ? true : false;
        else if (role == Bit6Role)
            return reg->value() & 0x40 ? true : false;
        else if (role == Bit7Role)
            return reg->value() & 0x80 ? true : false;
        else if (role == NameRole)
            return reg->name();
    }

    return QVariant();


}

void RegisterModel::addRegister(Register *reg) {
    registers.append(reg);
}

