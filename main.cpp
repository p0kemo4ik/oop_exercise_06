#include <iostream>
#include <algorithm>

#include "list.hpp"
#include "allocator.hpp"
#include "pentagon.hpp"

int main() {
    container::list<Pentagon<double>, allocator::my_allocator<Pentagon<double>, 500>> list;
    int command, pos;

    while(true) {
        std::cout << std::endl;
        std::cout << "1. Добавить фигуру в список"<< std::endl;
        std::cout << "2. Удалить фигуру" << std::endl;
        std::cout << "3. Вывести все фигуры" << std::endl;
        std::cout << "4. Вывести кол-во фигур чья площаль больше чем ..." << std::endl;
        std::cout << "5. Вывести фигуру" << std::endl << std::endl;
        std::cin >> command;

        if (command == 0) {
            break;

        } else if(command == 1) {
            std::cout << "Введите координаты" << std::endl;
            Pentagon<double> pentagon(std::cin);

            std::cout << "1. Добавить фигуру в начало списка" << std::endl;
            std::cout << "2. Добавить фигуру по индексу" << std::endl;
            std::cin >> command;
            if(command == 1) {
                list.push(pentagon);
                continue;
            } else if(command == 2) {
                std::cout << "Введите индекс" << std::endl;
                std::cin >> pos;
                list.insert(pos, pentagon);
                continue;
            } else {
                std::cout << "Неправильная команда" << std::endl;
                std::cin >> command;
                continue;
            }

        } else if(command == 2) {
            std::cout << "1. Удалить фигуру из списка по индексу" << std::endl;
            std::cout << "2. Удалить по итератору" << std::endl;
            std::cout << "3. Удалить фигуру из начала списка" << std::endl;
            std::cin >> command;
            if (command == 1) {
                std::cout << "Введите индекс" << std::endl;
                std::cin >> pos;
                list.erase(pos);
                continue;
            } else if (command == 2) {
                std::cout << "Введите индекс" << std::endl;
                std::cin >> pos;
                auto temp = list.begin();
                for(int i = 0; i < pos; ++i) {
                    ++temp;
                }
                list.erase(temp);
                continue;

            } else if (command == 3) {
                try {
                    list.popFront();
                } catch(std::exception& e) {
                    std::cout << e.what() << std::endl;
                    continue;
                }
            } else {
                std::cout << "Неправильная команда" << std::endl;
                std::cin >> command;
                continue;
            }
        } else if(command == 3) {
            for(const auto& item : list) {
                item.print(std::cout);
                std::cout << "Center: [" << item.center() << "]" << std::endl;
                std::cout << "Area: " << item.square() << std::endl;
                continue;
            }

        } else if(command == 4) {
            std::cout << "Введите площадь" << std::endl;
            std::cin >> pos;
            std::cout << "Количество пятиугольнков площадь, которых меньше заданной " << pos;
            std::cout << std::count_if(list.begin(), list.end(), [pos](Pentagon<double> square) {return square.square() < pos;}) << std::endl;
            continue;

        } else if (command == 5) {
            std::cout << "Введите номер элемента" << std::endl;
            std::cin >> pos;
            try {
                list[pos].print(std::cout);
                std::cout << "Center: [" << list[pos].center() << "]" << std::endl;
                std::cout << "Area: " << list[pos].square() << std::endl;
            } catch(std::exception& e) {
                std::cout << e.what() << std::endl;
                continue;
            }
            continue;

        } else {
            std::cout << "Неправильная команда" << std::endl;
            continue;
        }
    }

    return 0;
}