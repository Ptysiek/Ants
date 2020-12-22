#pragma once


#include "../../WorldEngine.hpp"
#include "../../AntBuilder.hpp"



struct WorldSceneLogic {

    WorldEngine world_;
    AntBuilder antBuild_;

    WorldSceneLogic() : antBuild_(world_) {
        for (size_t i = 0; i < 20; i++)
        {
            antBuild_.summon();
        } 
    }

    void Update() {
        for (auto& ant : world_.allAntsInThisWorld_) {
            ant.behave();
        }
    }


};

