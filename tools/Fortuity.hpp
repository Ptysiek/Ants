#pragma once

#include <random>
#include <iostream>

#include <exception>


class Fortuity {
public: 
    static int getRandom(int first, int last) {
        if (first > last) {
            std::swap(first, last);
        }

        const int result = makeRandomNumber(first, last);

        if (result < first || result > last) {
            throw std::logic_error("Fortuity::getRandom(int,int): Result value out of scope");
        }

        return result;
    }

private:
    static int makeRandomNumber(const int first, const int last) {
        std::random_device random_device;
        std::mt19937 random_engine(random_device());
        std::uniform_int_distribution<int> distribution(first, last);

        return distribution(random_engine);
    }
};
