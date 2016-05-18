#pragma once
#include "Instance.h"
#include <iostream>


using namespace std;
class Entity: public Instance {
    public:
        float dx, dy;
        float weight;
        bool on_ground;
        World * world;

        Entity (float x, float y, World * world) : Instance(x, y) {
            this->dx = 0;
            this->dy = 0;
            this->type = "entity";
            this->weight = 6.2f;
            this->on_ground = false;
            this->world = world;
        }

        void updateCollisions(float delta) {
        }

        void updatePhysics (float delta) {
                   }
        
        void addForce (float direction, float force) {
                   }
};
