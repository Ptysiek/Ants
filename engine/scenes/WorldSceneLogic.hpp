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
            std::string antDecision;
            antDecision = ant.behave(world_.matrix_.getScope(ant.x_pos, ant.y_pos));
            AntTranslator(ant, antDecision);
        }
    }

private:
    void AntTranslator(WorldAnt& ant, const std::string& antDecision) {

        if (antDecision == "goUP") {
            --ant.y_pos;
        }
        if (antDecision == "goDOWN") {
            ++ant.y_pos;
        }
        if (antDecision == "goLEFT") {
            --ant.x_pos;
        }
        if (antDecision == "goRIGHT") {
            ++ant.x_pos;
        }
    }


};

