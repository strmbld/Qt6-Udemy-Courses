#include <QColor>

#include "customtablemodel.h"


CustomTableModel::CustomTableModel(QObject *parent)
    : QAbstractTableModel{parent}
{
    // m_model.append({ "John", "Doe", "32", "Farmer", "Single", "Gounduana", "red" });

    table.append({"John","Doe","32","Farmer","Single","Gounduana","red"});
    table.append({"Mary","Jane","27","Teacher","Married","Verkso","green"});
    table.append({"John","Doe","32","Farmer","Single","Gounduana","blue"});
    table.append({"Mary","Jane","27","Teacher","Married","Verkso","yellow"});
    table.append({"John","Doe","32","Farmer","Single","Gounduana","gray"});
    table.append({"Mary","Jane","27","Teacher","Married","Verkso","black"});
    table.append({"John","Doe","32","Farmer","Single","Gounduana","aliceblue"});
    table.append({"Mary","Jane","27","Teacher","Married","Verkso","yellowgreeen"});
    table.append({"John","Doe","32","Farmer","Single","Gounduana","gray"});
    table.append({"Mary","Jane","27","Teacher","Married","Verkso","white"});
    table.append({"John","Doe","32","Farmer","Single","Gounduana","green"});
    table.append({"Mary","Jane","27","Teacher","Married","Verkso","gray"});
    table.append({"John","Doe","32","Farmer","Single","Gounduana","red"});
    table.append({"Mary","Jane","27","Teacher","Married","Verkso","blue"});
    table.append({"John","Doe","32","Farmer","Single","Gounduana","black"});
    table.append({"Mary","Jane","27","Teacher","Married","Verkso","yellow"});
    table.append({"John","Doe","32","Farmer","Single","Gounduana","gray"});
    table.append({"Mary","Jane","27","Teacher","Married","Verkso","yellow"});
    table.append({"John","Doe","32","Farmer","Single","Gounduana","white"});
    table.append({"Mary","Jane","27","Teacher","Married","Verkso","blue"});
}


int CustomTableModel::rowCount(const QModelIndex &parent) const
{
    if(!parent.isValid()) {
        return table.count();
    }

    return 0;
}

int CustomTableModel::columnCount(const QModelIndex &parent) const
{
    if(!parent.isValid()) {
        return table[0].count();
    }

    return 0;
}

QVariant CustomTableModel::data(const QModelIndex &index, int role) const
{
    if(role == Qt::DisplayRole || role == Qt::EditRole) {
        return table[index.row()][index.column()];
    }

    if(role == Qt::DecorationRole && index.column() == 6) {
        return QColor(table[index.row()][index.column()]);
    }

    return QVariant(); // return {};
}

QVariant CustomTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(orientation == Qt::Horizontal && role == Qt::DisplayRole){
        switch (section) {
        case 0:
            return "First Name";
        case 1:
            return "Last Name";
        case 2:
            return "Age";
        case 3 :
            return "Profession";
        case 4 :
            return "Marital Status";
        case 5 :
            return "Country";
        case 6 :
            return "Favorite color";
        default :
            return "";
        }
    }

    return QVariant();
}


bool CustomTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(role != Qt::EditRole) {
        return false;
    }

    table[index.row()][index.column()] = value.toString();

    emit dataChanged(index, index);

    return true;
}

Qt::ItemFlags CustomTableModel::flags(const QModelIndex &index) const
{
    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}
