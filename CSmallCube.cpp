#include "CSmallCube.h"

CSmallCube::CSmallCube() {
    lc_up = "black";
    lc_down = "black";
    lc_left = "black";
    lc_right = "black";
    lc_front = "black";
    lc_back = "black";

    position_lc_up = -1;
    position_lc_down = -1;
    position_lc_left = -1;
    position_lc_right = -1;
    position_lc_front = -1;
    position_lc_back = -1;

}

void CSmallCube::u_degree_rotation() {
    std::vector<std::string> arr = {lc_front, lc_left, lc_back, lc_right};
    lc_front = arr[3];
    lc_left = arr[0];
    lc_back = arr[1];
    lc_right = arr[2];

}

void CSmallCube::d_degree_rotation() {
    std::vector<std::string> arr = {lc_front, lc_left, lc_back, lc_right};
    lc_front = arr[1];
    lc_left = arr[2];
    lc_back = arr[3];
    lc_right = arr[0];
}

void CSmallCube::r_degree_rotation() {
    std::vector<std::string> arr = {lc_front, lc_back, lc_up, lc_down};
    lc_front = arr[3];
    lc_down = arr[1];
    lc_back = arr[2];
    lc_up = arr[0];

}

void CSmallCube::l_degree_rotation() {
    std::vector<std::string> arr = {lc_front, lc_back, lc_up, lc_down};
    lc_front = arr[2];
    lc_down = arr[0];
    lc_back = arr[3];
    lc_up = arr[1];
}

void CSmallCube::f_degree_rotation() {
    std::vector<std::string> arr = {lc_left, lc_right, lc_up, lc_down};
    lc_left = arr[3];
    lc_right = arr[2];
    lc_up = arr[0];
    lc_down = arr[1];
}

void CSmallCube::b_degree_rotation() {
    std::vector<std::string> arr = {lc_left, lc_right, lc_up, lc_down};
    lc_left = arr[2];
    lc_right = arr[3];
    lc_up = arr[1];
    lc_down = arr[0];
}



