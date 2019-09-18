//
//  main.cpp
//  Homework 2
//
//  Created by Jason Ghiglieri with assistance from Kyle Thomas, Oswaldo Menchaca, and Evan Derby on 1/17/18.
//  Copyright © 2018 Jason Ghiglieri. All rights reserved.
//

#include <iostream>
#include "VoxelModel.hpp"

int main(int argc, const char * argv[])
{
    // Testing emptyModel method. Pass.
    u_int64_t eModel = emptyModel();
    std::cout << "Hex representation of empty Model: 0x" << std::hex << eModel << std::dec << "\n";
    std::cout << "Binary representation of empty Model: " << std::bitset<64>(eModel) << std::dec << "\n";
    std::cout << "Decimal representation of empty Model: " << eModel << "\n";
    std::cout << "\n";
    
    // Testing fullModel method. Pass.
    u_int64_t fModel = fullModel();
    std::cout << "Hex representation of full Model: 0x" << std::hex << fModel << std::dec << "\n";
    std::cout << "Binary representation of full Model: " << std::bitset<64>(fModel) << std::dec << "\n";
    std::cout << "Decimal representation of full Model: " << fModel << "\n";
    std::cout << "\n";
    
    
    
    // Testing getIndex method. Pass
    u_int8_t index = getIndex(3, 2, 1);
    std::cout << "Index of given XYZ coordinates: " << +index << "\n";
    std::cout << "\n";
    
    
    // Testing getX/Y/Z methods. All pass.
    u_int8_t x = getX(22);
    std::cout << "X value of given index: " << +x << "\n";
    
    u_int8_t y = getY(22);
    std::cout << "Y value of given index: " << +y << "\n";
    
    u_int8_t z = getZ(22);
    std::cout << "Z value of given index: " << +z << "\n";
    std::cout << "\n";
    
    
    
    // Testing getBit method. Pass.
    bool bitValue = getBit(fModel, 1, 1, 2);
    std::cout << "Boolean value for selected bit: " << std::boolalpha << bitValue << "\n";
    std::cout << "\n";
    
    
    
    // Testing setBit method. Pass.
    std::cout << "Binary representation of empty Model before setting bit: " << std::bitset<64>(eModel) << std::dec << "\n";
    u_int64_t setModel = setBit(eModel, 3, 3, 3);
    std::cout << "Binary representation of empty Model after setting bit: " << std::bitset<64>(setModel) << std::dec << "\n";
    
    // Testing clearBit method. Pass.
    std::cout << "Binary representation of full Model before clearing bit: " << std::bitset<64>(fModel) << std::dec << "\n";
    u_int64_t clearModel = clearBit(fModel, 2, 0, 1);
    std::cout << "Binary representation of full Model after clearing bit: " << std::bitset<64>(clearModel) << std::dec << "\n";
    std::cout << "\n";
    
    
    
    // Testing toggle bit method.
    // Pass on Empty model
    std::cout << "Binary representation of empty Model before toggling bit: " << std::bitset<64>(eModel) << std::dec << "\n";
    u_int64_t toggleModelE = toggleBit(eModel, 1, 3, 3);
    std::cout << "Binary representation of empty Model after toggling bit: " << std::bitset<64>(toggleModelE) << std::dec << "\n";
    
    // Pass on Full model
    std::cout << "Binary representation of full Model before toggling bit: " << std::bitset<64>(fModel) << std::dec << "\n";
    u_int64_t toggleModelF = toggleBit(fModel, 2, 0, 0);
    std::cout << "Binary representation of full Model after toggling bit: " << std::bitset<64>(toggleModelF) << std::dec << "\n";
    std::cout << "\n\n";
    
    
    
    // Now lets make a more fun one for the voxel viewer.
    u_int64_t funModel = emptyModel();
    
    for (int i = 0; i < 64; i+=3)
    {
        funModel = toggleBit(funModel, getX(i), getY(i), getZ(i));
    }
    
    std::cout << "Hex representation of fun Model: 0x" << std::hex << funModel << std::dec << "\n";
    std::cout << "Binary representation of fun Model: " << std::bitset<64>(funModel) << std::dec << "\n";
    std::cout << "Decimal representation of fun Model: " << funModel << "\n";
    std::cout << "\n\n";
    
    
    
    // Big, probably unnescessary, extra test to ensure each of the individual bit modifying methods work on every possible bit. Also creates a somewhat satisfying slice through the large binary block printed.
    /*
    u_int64_t rigorousTestModelS = emptyModel();
    u_int64_t rigorousTestModelC = fullModel();
    u_int64_t rigorousTestModelT = emptyModel();
    
    
    for (int x = 0;  x < 4; x++)
    {
        for (int y = 0; y < 4; y++)
        {
            for (int z = 0; z < 4; z++)
            {
                rigorousTestModelS = setBit(rigorousTestModelS, x, y, z);
                std::cout << "Binary representation of Model: " << std::bitset<64>(rigorousTestModelS) << std::dec << "\n";
                rigorousTestModelS = emptyModel();
                
            }
        }
    }
    std::cout << "\n";
    
    
    for (int x = 0;  x < 4; x++)
    {
        for (int y = 0; y < 4; y++)
        {
            for (int z = 0; z < 4; z++)
            {
                rigorousTestModelC = clearBit(rigorousTestModelC, x, y, z);
                std::cout << "Binary representation of Model: " << std::bitset<64>(rigorousTestModelC) << std::dec << "\n";
                rigorousTestModelC = fullModel();
                
            }
        }
    }
    std::cout << "\n";
    
    
    for (int x = 0;  x < 4; x++)
    {
        for (int y = 0; y < 4; y++)
        {
            for (int z = 0; z < 4; z++)
            {
                rigorousTestModelT = toggleBit(rigorousTestModelT, x, y, z);
                std::cout << "Binary representation of Model: " << std::bitset<64>(rigorousTestModelT) << std::dec << "\n";
                rigorousTestModelT = emptyModel();
                
            }
        }
    }
    */
    
}
