//
// Created by Adam Ali on 03/01/2023.
//

#ifndef CRACKINGTHECODINGINTERVIEW_ANIMALQUEUE_H
#define CRACKINGTHECODINGINTERVIEW_ANIMALQUEUE_H
#include <vector>
#include <string>

enum animal_type {
    DOG,
    CAT
};

struct animal {
    std::string name;
    animal_type type;
    int order;
    animal(std::string name, animal_type type) : name(name), type(type), order(0) {}
};

class animalqueue {
private:
    std::vector<animal> dogs;
    std::vector<animal> cats;
    int order;
public:
    // Constructor
    animalqueue() : order(0) {}
    // Destructor
    ~animalqueue() {
        dogs.clear();
        cats.clear();
    }

    void enqueue(animal* a);
    animal dequeueAny();
    animal dequeueDog();
    animal dequeueCat();
};


#endif //CRACKINGTHECODINGINTERVIEW_ANIMALQUEUE_H
