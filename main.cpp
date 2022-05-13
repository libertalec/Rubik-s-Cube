#include <iostream>
#include "CSmallCube.h"
#include "AssemblingRubiksCube.h"
#include "AssemblingRubiksCube.h"


int main() {
    std::string command;
    CRubicsCube one;

    std::cout << "What command do you want to execute? ";
    std::cout << std::endl;
    std::cout << "list - list of commands";
    std::cout << std::endl;
    while (std::cin >> command) {
        if (command == "list") {
            std::cout << "Reading from a file (read), writing to a file(write)";
            std::cout << std::endl;
            std::cout << "clockwise rotation of each face(turn_up/down/left/right/up/down)";
            std::cout << std::endl;
            std::cout << "counterclockwise rotation of each face(turnc_up/down/left/right/up/down)";
            std::cout << std::endl;
            std::cout << "output of the current state(print)";
            std::cout << std::endl;
            std::cout << "assembly of the cube(assemble)";
            std::cout << std::endl;
            std::cout << "random combination of the cube(random)";
            std::cout << std::endl;
        } else if (command == "print") {
            one.printCube();
        } else if (command == "turn_up") {
            one.turn_up_clockwise();
        } else if (command == "turn_down") {
            one.turn_down_clockwise();
        } else if (command == "turn_left") {
            one.turn_left_clockwise();
        } else if (command == "turn_right") {
            one.turn_right_clockwise();
        } else if (command == "turn_back") {
            one.turn_back_clockwise();
        } else if (command == "turn_front") {
            one.turn_front_clockwise();
        } else if (command == "turnc_up") {
            one.turn_counterclockwise('U');
        } else if (command == "turnc_down") {
            one.turn_counterclockwise('D');
        } else if (command == "turnc_left") {
            one.turn_counterclockwise('L');
        } else if (command == "turnc_right") {
            one.turn_counterclockwise('R');
        } else if (command == "turnc_back") {
            one.turn_counterclockwise('B');
        } else if (command == "turnc_front") {
            one.turn_counterclockwise('F');
        } else if (command == "read") {
            one.read_file();
        } else if (command == "write") {
            one.writing_file();
        } else if (command == "assemble") {
            AssemblingRubiksCube check(one);
            one = check.assemble();
        }else if(command == "random"){
            one.random_turn();
        }
    }


};