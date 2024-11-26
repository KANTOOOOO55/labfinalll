#include "item.h"
#include <QFile>
#include <QTextStream>
#include <QDir>

Item::Item() {} // constructor : creates an empty item object

std::map<QString, Item> Item::getAllItems()
{
    std::map<QString, Item> items; // map to store all items
    QString filePath = QDir::homePath() + "/Documents/items.txt"; //file path to store items
    QFile file(filePath);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) { //open the file for reading and returns an empty map if the file cannot be opened
        return items;
    }

    QTextStream in(&file); // stream for reading the file
    while (!in.atEnd()) { // loop and read the file till the end
        QString line = in.readLine();
        QStringList attributes = line.split("$");
        if (attributes.size() != 7) continue; //ensure the line has exactly 7 attributes before processing
        Item item; // create an item object and set its attributes
        item.setName(attributes[0]);
        item.setDescription(attributes[1]);
        item.setPrice(attributes[2]);
        item.setAvailability(attributes[3]);
        item.setCategory(attributes[4]);
        item.setNumberOfTimesRented(attributes[5]);
        item.setRate(attributes[6]);
        items[item.getName()] = item; //add the item to the map using its name as the key
    }

    file.close(); //close the file after reading
    return items; // return the map of items
}

void Item::saveItems(std::map<QString, Item> items)
{ // writes all items in the map to the file , overwriting existing content
    QString filePath = QDir::homePath() + "/Documents/items.txt"; // file path to store items
    QFile file(filePath);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return;
    }

    QTextStream out(&file); //iterate through the map and write each item's attributes to the file
    for (const auto& [key, item] : items) {
        out << item.getName() << "$"
            << item.getDescription() << "$"
            << item.getPrice() << "$"
            << item.getAvailability() << "$"
            << item.getCategory() << "$"
            << item.getNumberOfTimesRented() << "$"
            << item.getRate() << "\n";
    }

    file.close(); // close the file after writing
}

void Item::saveItem(Item item) { //saves or updates a single item by adding it to map and rewriting the file
    std::map<QString, Item> items = getAllItems();
    items[item.getName()] = item;
    saveItems(items);
}

void Item::setName(const QString& value) {
    name = value;
}

void Item::setDescription(const QString& value) {
    description = value;
}

void Item::setPrice(const QString& value) {
    price = value;
}

void Item::setAvailability(const QString& value) {
    avalability = value;
}

void Item::setCategory(const QString& value) {
    category = value;
}

void Item::setNumberOfTimesRented(const QString& value) {
    numberOfTimesRented = value;
}

void Item::setRate(const QString& value) {
    rate = value;
}

QString Item::getName() const {
    return name;
}
QString Item::getDescription() const {
    return description;
}
QString Item::getPrice() const {
    return price;
}
QString Item::getAvailability() const {
    return avalability;
}
QString Item::getCategory() const {
    return category;
}
QString Item::getNumberOfTimesRented() const {
    return numberOfTimesRented;
}
QString Item::getRate() const {
    return rate;
}

