#pragma once

#include <vector>

class WorldMatrix {
public:
    // using WMatrix = std::vector<std::vector<TileInformations>>;
    using WMatrix = std::vector<std::vector<char>>;
    
    WMatrix worldMatrix_;
    const size_t size_ = 127;
    
    
    explicit WorldMatrix() {
        initMatrix();
    }
    explicit WorldMatrix(size_t size) : size_(size) {
        WorldMatrix();
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