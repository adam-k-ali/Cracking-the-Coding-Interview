//
// Created by Adam Ali on 03/01/2023.
//

#include "animalqueue.h"
#include <iostream>

void animalqueue::enqueue(animal* a) {
    a->order = order;
    order++;
    if (a->type == DOG) {
        dogs.push_back(*a);
    } else {
        cats.push_back(*a);
    }
}

animal animalqueue::dequeueAny() {
    if (dogs.empty()) {
        return dequeueCat();
    } else if (cats.empty()) {
        return dequeueDog();
    }
    animal dog = dogs.front();
    animal cat = cats.front();
    if (dog.order < cat.order) {
        dogs.erase(dogs.begin());
        return dog;
    } else {
        cats.erase(cats.begin());
        return cat;
    }
}

animal animalqueue::dequeueDog() {
    if (dogs.empty()) {
        std::cout << "No dogs in queue" << std::endl;
        throw std::runtime_error("No dogs in queue");
    }
    animal dog = dogs.front();
    dogs.erase(dogs.begin());
    return dog;
}

animal animalqueue::dequeueCat() {
    if (cats.empty()) {
        std::cout << "No cats in queue" << std::endl;
        throw std::runtime_error("No cats in queue");
    }
    animal cat = cats.front();
    cats.erase(cats.begin());
    return cat;
}