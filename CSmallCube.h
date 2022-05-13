#ifndef RUBIK__S_CUBE_CSMALLCUBE_H
#define RUBIK__S_CUBE_CSMALLCUBE_H

#include <string>
#include <vector>
#include <iostream>
class CSmallCube {
public:
    std::string lc_up;
    std::string lc_down;
    std::string lc_left;
    std::string lc_right;
    std::string lc_front;
    std::string lc_back;

    int position_lc_up;
    int position_lc_down;
    int position_lc_left;
    int position_lc_right;
    int position_lc_front;
    int position_lc_back;

    CSmallCube();

    void u_degree_rotation();

    void d_degree_rotation();

    void r_degree_rotation();

    void l_degree_rotation();

    void f_degree_rotation();

    void b_degree_rotation();
};


#endif //RUBIK__S_CUBE_CSMALLCUBE_H
