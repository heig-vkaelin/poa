//
// Created by Alexandre Jaquier on 27.05.2022.
//

#ifndef BUFFY_TRANSFORM_HPP
#define BUFFY_TRANSFORM_HPP

#include "Action.hpp"

class Humanoid;

class Transform : public Action {
public:
    Transform(Humanoid &humanoid);

    void execute(Field &f) override;

private:
    Humanoid *humanoid;
};


#endif //BUFFY_TRANSFORM_HPP
