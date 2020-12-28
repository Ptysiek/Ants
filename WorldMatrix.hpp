#pragma once


#include <vector>


using WMatrix = std::vector<std::vector<char>>;

struct WorldScope {
    WMatrix scopeMatrix_;
    size_t x;
    size_t y;
};


class WorldMatrix {
public:
    // using WMatrix = std::vector<std::vector<TileInformations>>;
    
    WMatrix worldMatrix_;
    const size_t size_ = 127;
    
    
    explicit WorldMatrix() {
        initMatrix();
    }
    explicit WorldMatrix(size_t size) : size_(size) {
        WorldMatrix();
    }
    
    WorldScope getScope(size_t x, size_t y) {
        return WorldScope {
            WMatrix {
                { getPos(x-1,y-1),  getPos(x,y-1),  getPos(x+1,y-1) },
                { getPos(x-1,y),    getPos(x,y),    getPos(x+1,y) },
                { getPos(x-1,y+1),  getPos(x,y+1),  getPos(x+1,y+1) }
            }, 
            x, 
            y
        };
    }
    
    char getPos(size_t x, size_t y) const { 
        if (!checkPos(x) || !checkPos(y)) {
            return '0';
        }
        return worldMatrix_[y][x];
    }

    bool checkPos(size_t pos) const { 
        if (pos >= size_) {
            return false;
        }
        return true;
    }


private:
    void initMatrix() {
        worldMatrix_.resize(size_);
        
        // for (std::vector<char>& matrixrow : worldMatrix_) {
        for (auto& matrixrow : worldMatrix_) {
            matrixrow.resize(size_);
        } 
    }
};
