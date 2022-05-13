#include "CRubicsCube.h"

#include <utility>

CRubicsCube::CRubicsCube() {
    cube = std::vector<std::vector<std::vector<CSmallCube>>>(3, std::vector<std::vector<CSmallCube >>(3,
                                                                                                      std::vector<CSmallCube>(
                                                                                                              3,
                                                                                                              CSmallCube())));
    default_colors();
}

void CRubicsCube::default_colors() {
//Закрашиваем верхнюю грань в желтый цвет

    for (int x = 0; x < 3; x++) {
        for (int z = 0; z < 3; z++) {
            cube[x][2][z].lc_up = "yellow";
        }
    }

    //Закрашиваем переднюю сторону в синий цвет

    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            cube[x][y][2].lc_front = "blue";
        }
    }

    //Закрашиваем левую сторону в оранжевый цвет

    for (int z = 0; z < 3; z++) {
        for (int y = 0; y < 3; y++) {
            cube[0][y][z].lc_left = "orange";
        }
    }

    //Закрашиваем правую сторону в красный цвет

    for (int z = 0; z < 3; z++) {
        for (int y = 0; y < 3; y++) {
            cube[2][y][z].lc_right = "red";
        }
    }

    //Закрашиваем нижнюю грань в белый цвет

    for (int x = 0; x < 3; x++) {
        for (int z = 0; z < 3; z++) {
            cube[x][0][z].lc_down = "white";
        }
    }

    //Закрашиваем заднюю грань в зеленый цвет

    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            cube[x][y][0].lc_back = "green";
        }
    }

}

void CRubicsCube::printCube() {
    int score = 0;
    //Вывод задней грани
    std::cout << "Back: " << std::endl;
    for (int y = 2; y >= 0; y--) {
        for (int x = 2; x >= 0; x--) {
            if (score == 3) {
                std::cout << std::endl;
                score = 0;
            }
            std::cout << cube[x][y][0].lc_back << " ";
            score++;
        }
    }
    std::cout << std::endl << "====================" << std::endl;
    //Вывод передней грани
    std::cout << "Front: ";
    for (int y = 2; y >= 0; y--) {
        for (int x = 0; x < 3; x++) {
            if (score == 3) {
                std::cout << std::endl;
                score = 0;
            }
            std::cout << cube[x][y][2].lc_front << " ";
            score++;
        }
    }
    std::cout << std::endl << "====================" << std::endl;
    //Вывод левой грани
    std::cout << "Left: ";
    for (int y = 2; y >= 0; y--) {
        for (int z = 0; z < 3; z++) {
            if (score == 3) {
                std::cout << std::endl;
                score = 0;
            }
            std::cout << cube[0][y][z].lc_left << " ";
            score++;
        }
    }
    std::cout << std::endl << "====================" << std::endl;
    //Вывод правой грани
    std::cout << "Right: ";
    for (int y = 2; y >= 0; y--) {
        for (int z = 2; z >= 0; z--) {
            if (score == 3) {
                std::cout << std::endl;
                score = 0;
            }
            std::cout << cube[2][y][z].lc_right << " ";
            score++;
        }
    }
    std::cout << std::endl << "====================" << std::endl;
    //Вывод верхней грани
    std::cout << "Up: ";
    for (int z = 0; z < 3; z++) {
        for (int x = 0; x < 3; x++) {
            if (score == 3) {
                std::cout << std::endl;
                score = 0;
            }
            std::cout << cube[x][2][z].lc_up << " ";
            score++;
        }
    }
    std::cout << std::endl << "====================" << std::endl;
    //Вывод нижней грани
    std::cout << "Down: ";
    for (int z = 2; z >= 0; z--) {
        for (int x = 0; x < 3; x++) {
            if (score == 3) {
                std::cout << std::endl;
                score = 0;
            }
            std::cout << cube[x][0][z].lc_down << " ";
            score++;
        }
    }
    std::cout << std::endl << "====================" << std::endl;
}

void CRubicsCube::turn_up_clockwise() {
    std::vector<std::vector<std::vector<CSmallCube>>> backup_cube = cube;
    positionCubes('U');
    for (int z = 0; z < 3; z++) {
        for (int x = 0; x < 3; x++) {
            if (cube[x][2][z].position_lc_up == 1) {
                backup_cube[2][2][0] = cube[x][2][z];
                backup_cube[2][2][0].position_lc_up = 3;
                backup_cube[2][2][0].u_degree_rotation();
            } else if (cube[x][2][z].position_lc_up == 2) {
                backup_cube[2][2][1] = cube[x][2][z];
                backup_cube[2][2][1].position_lc_up = 4;
                backup_cube[2][2][1].u_degree_rotation();
            } else if (cube[x][2][z].position_lc_up == 3) {
                backup_cube[2][2][2] = cube[x][2][z];
                backup_cube[2][2][2].position_lc_up = 5;
                backup_cube[2][2][2].u_degree_rotation();
            } else if (cube[x][2][z].position_lc_up == 4) {
                backup_cube[1][2][2] = cube[x][2][z];
                backup_cube[1][2][2].position_lc_up = 6;
                backup_cube[1][2][2].u_degree_rotation();
            } else if (cube[x][2][z].position_lc_up == 5) {
                backup_cube[0][2][2] = cube[x][2][z];
                backup_cube[0][2][2].position_lc_up = 7;
                backup_cube[0][2][2].u_degree_rotation();
            } else if (cube[x][2][z].position_lc_up == 6) {
                backup_cube[0][2][1] = cube[x][2][z];
                backup_cube[0][2][1].position_lc_up = 8;
                backup_cube[0][2][1].u_degree_rotation();
            } else if (cube[x][2][z].position_lc_up == 7) {
                backup_cube[0][2][0] = cube[x][2][z];
                backup_cube[0][2][0].position_lc_up = 1;
                backup_cube[0][2][0].u_degree_rotation();
            } else if (cube[x][2][z].position_lc_up == 8) {
                backup_cube[1][2][0] = cube[x][2][z];
                backup_cube[1][2][0].position_lc_up = 2;
                backup_cube[1][2][0].u_degree_rotation();
            }
        }

    }
    cube = backup_cube;
}

void CRubicsCube::turn_down_clockwise() {
    std::vector<std::vector<std::vector<CSmallCube>>> backup_cube = cube;
    positionCubes('D');
    for (int z = 0; z < 3; z++) {
        for (int x = 0; x < 3; x++) {
            if (cube[x][0][z].position_lc_down == 1) {
                backup_cube[2][0][2] = cube[x][0][z];
                backup_cube[2][0][2].position_lc_down = 3;
                backup_cube[2][0][2].d_degree_rotation();
            } else if (cube[x][0][z].position_lc_down == 2) {
                backup_cube[2][0][1] = cube[x][0][z];
                backup_cube[2][0][1].position_lc_down = 4;
                backup_cube[2][0][1].d_degree_rotation();
            } else if (cube[x][0][z].position_lc_down == 3) {
                backup_cube[2][0][0] = cube[x][0][z];
                backup_cube[2][0][0].position_lc_down = 5;
                backup_cube[2][0][0].d_degree_rotation();
            } else if (cube[x][0][z].position_lc_down == 4) {
                backup_cube[1][0][0] = cube[x][0][z];
                backup_cube[1][0][0].position_lc_down = 6;
                backup_cube[1][0][0].d_degree_rotation();
            } else if (cube[x][0][z].position_lc_down == 5) {
                backup_cube[0][0][0] = cube[x][0][z];
                backup_cube[0][0][0].position_lc_down = 7;
                backup_cube[0][0][0].d_degree_rotation();
            } else if (cube[x][0][z].position_lc_down == 6) {
                backup_cube[0][0][1] = cube[x][0][z];
                backup_cube[0][0][1].position_lc_down = 8;
                backup_cube[0][0][1].d_degree_rotation();
            } else if (cube[x][0][z].position_lc_down == 7) {
                backup_cube[0][0][2] = cube[x][0][z];
                backup_cube[0][0][2].position_lc_down = 1;
                backup_cube[0][0][2].d_degree_rotation();
            } else if (cube[x][0][z].position_lc_down == 8) {
                backup_cube[1][0][2] = cube[x][0][z];
                backup_cube[1][0][2].position_lc_down = 2;
                backup_cube[1][0][2].d_degree_rotation();
            }
        }

    }
    cube = backup_cube;
}

void CRubicsCube::turn_right_clockwise() {
    std::vector<std::vector<std::vector<CSmallCube>>> backup_cube = cube;
    positionCubes('R');
    for (int y = 0; y < 3; y++) {
        for (int z = 0; z < 3; z++) {
            if (cube[2][y][z].position_lc_right == 1) {
                backup_cube[2][2][0] = cube[2][y][z];
                backup_cube[2][2][0].position_lc_right = 3;
                backup_cube[2][2][0].r_degree_rotation();
            } else if (cube[2][y][z].position_lc_right == 2) {
                backup_cube[2][1][0] = cube[2][y][z];
                backup_cube[2][1][0].position_lc_right = 4;
                backup_cube[2][1][0].r_degree_rotation();
            } else if (cube[2][y][z].position_lc_right == 3) {
                backup_cube[2][0][0] = cube[2][y][z];
                backup_cube[2][0][0].position_lc_right = 5;
                backup_cube[2][0][0].r_degree_rotation();
            } else if (cube[2][y][z].position_lc_right == 4) {
                backup_cube[2][0][1] = cube[2][y][z];
                backup_cube[2][0][1].position_lc_right = 6;
                backup_cube[2][0][1].r_degree_rotation();
            } else if (cube[2][y][z].position_lc_right == 5) {
                backup_cube[2][0][2] = cube[2][y][z];
                backup_cube[2][0][2].position_lc_right = 7;
                backup_cube[2][0][2].r_degree_rotation();
            } else if (cube[2][y][z].position_lc_right == 6) {
                backup_cube[2][1][2] = cube[2][y][z];
                backup_cube[2][1][2].position_lc_right = 8;
                backup_cube[2][1][2].r_degree_rotation();
            } else if (cube[2][y][z].position_lc_right == 7) {
                backup_cube[2][2][2] = cube[2][y][z];
                backup_cube[2][2][2].position_lc_right = 1;
                backup_cube[2][2][2].r_degree_rotation();
            } else if (cube[2][y][z].position_lc_right == 8) {
                backup_cube[2][2][1] = cube[2][y][z];
                backup_cube[2][2][1].position_lc_right = 2;
                backup_cube[2][2][1].r_degree_rotation();
            }
        }

    }
    cube = backup_cube;
}

void CRubicsCube::turn_left_clockwise() {
    std::vector<std::vector<std::vector<CSmallCube>>> backup_cube = cube;
    positionCubes('L');
    for (int y = 0; y < 3; y++) {
        for (int z = 0; z < 3; z++) {
            if (cube[0][y][z].position_lc_left == 1) {
                backup_cube[0][2][2] = cube[0][y][z];
                backup_cube[0][2][2].position_lc_left = 3;
                backup_cube[0][2][2].l_degree_rotation();
            } else if (cube[0][y][z].position_lc_left == 2) {
                backup_cube[0][1][2] = cube[0][y][z];
                backup_cube[0][1][2].position_lc_left = 4;
                backup_cube[0][1][2].l_degree_rotation();
            } else if (cube[0][y][z].position_lc_left == 3) {
                backup_cube[0][0][2] = cube[0][y][z];
                backup_cube[0][0][2].position_lc_left = 5;
                backup_cube[0][0][2].l_degree_rotation();
            } else if (cube[0][y][z].position_lc_left == 4) {
                backup_cube[0][0][1] = cube[0][y][z];
                backup_cube[0][0][1].position_lc_left = 6;
                backup_cube[0][0][1].l_degree_rotation();
            } else if (cube[0][y][z].position_lc_left == 5) {
                backup_cube[0][0][0] = cube[0][y][z];
                backup_cube[0][0][0].position_lc_left = 7;
                backup_cube[0][0][0].l_degree_rotation();
            } else if (cube[0][y][z].position_lc_left == 6) {
                backup_cube[0][1][0] = cube[0][y][z];
                backup_cube[0][1][0].position_lc_left = 8;
                backup_cube[0][1][0].l_degree_rotation();
            } else if (cube[0][y][z].position_lc_left == 7) {
                backup_cube[0][2][0] = cube[0][y][z];
                backup_cube[0][2][0].position_lc_left = 1;
                backup_cube[0][2][0].l_degree_rotation();
            } else if (cube[0][y][z].position_lc_left == 8) {
                backup_cube[0][2][1] = cube[0][y][z];
                backup_cube[0][2][1].position_lc_left = 2;
                backup_cube[0][2][1].l_degree_rotation();
            }
        }

    }
    cube = backup_cube;
}

void CRubicsCube::turn_front_clockwise() {
    std::vector<std::vector<std::vector<CSmallCube>>> backup_cube = cube;
    positionCubes('F');
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            if (cube[x][y][2].position_lc_front == 1) {
                backup_cube[2][2][2] = cube[x][y][2];
                backup_cube[2][2][2].position_lc_front = 3;
                backup_cube[2][2][2].f_degree_rotation();
            } else if (cube[x][y][2].position_lc_front == 2) {
                backup_cube[2][1][2] = cube[x][y][2];
                backup_cube[2][1][2].position_lc_front = 4;
                backup_cube[2][1][2].f_degree_rotation();
            } else if (cube[x][y][2].position_lc_front == 3) {
                backup_cube[2][0][2] = cube[x][y][2];
                backup_cube[2][0][2].position_lc_front = 5;
                backup_cube[2][0][2].f_degree_rotation();
            } else if (cube[x][y][2].position_lc_front == 4) {
                backup_cube[1][0][2] = cube[x][y][2];
                backup_cube[1][0][2].position_lc_front = 6;
                backup_cube[1][0][2].f_degree_rotation();
            } else if (cube[x][y][2].position_lc_front == 5) {
                backup_cube[0][0][2] = cube[x][y][2];
                backup_cube[0][0][2].position_lc_front = 7;
                backup_cube[0][0][2].f_degree_rotation();
            } else if (cube[x][y][2].position_lc_front == 6) {
                backup_cube[0][1][2] = cube[x][y][2];
                backup_cube[0][1][2].position_lc_front = 8;
                backup_cube[0][1][2].f_degree_rotation();
            } else if (cube[x][y][2].position_lc_front == 7) {
                backup_cube[0][2][2] = cube[x][y][2];
                backup_cube[0][2][2].position_lc_front = 1;
                backup_cube[0][2][2].f_degree_rotation();
            } else if (cube[x][y][2].position_lc_front == 8) {
                backup_cube[1][2][2] = cube[x][y][2];
                backup_cube[1][2][2].position_lc_front = 2;
                backup_cube[1][2][2].f_degree_rotation();
            }
        }

    }
    cube = backup_cube;
}

void CRubicsCube::turn_back_clockwise() {
    std::vector<std::vector<std::vector<CSmallCube>>> backup_cube = cube;
    positionCubes('B');
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            if (cube[x][y][0].position_lc_back == 1) {
                backup_cube[0][2][0] = cube[x][y][0];
                backup_cube[0][2][0].position_lc_back = 3;
                backup_cube[0][2][0].b_degree_rotation();
            } else if (cube[x][y][0].position_lc_back == 2) {
                backup_cube[0][1][0] = cube[x][y][0];
                backup_cube[0][1][0].position_lc_back = 4;
                backup_cube[0][1][0].b_degree_rotation();
            } else if (cube[x][y][0].position_lc_back == 3) {
                backup_cube[0][0][0] = cube[x][y][0];
                backup_cube[0][0][0].position_lc_back = 5;
                backup_cube[0][0][0].b_degree_rotation();
            } else if (cube[x][y][0].position_lc_back == 4) {
                backup_cube[1][0][0] = cube[x][y][0];
                backup_cube[1][0][0].position_lc_back = 6;
                backup_cube[1][0][0].b_degree_rotation();
            } else if (cube[x][y][0].position_lc_back == 5) {
                backup_cube[2][0][0] = cube[x][y][0];
                backup_cube[2][0][0].position_lc_back = 7;
                backup_cube[2][0][0].b_degree_rotation();
            } else if (cube[x][y][0].position_lc_back == 6) {
                backup_cube[2][1][0] = cube[x][y][0];
                backup_cube[2][1][0].position_lc_back = 8;
                backup_cube[2][1][0].b_degree_rotation();
            } else if (cube[x][y][0].position_lc_back == 7) {
                backup_cube[2][2][0] = cube[x][y][0];
                backup_cube[2][2][0].position_lc_back = 1;
                backup_cube[2][2][0].b_degree_rotation();
            } else if (cube[x][y][0].position_lc_back == 8) {
                backup_cube[1][2][0] = cube[x][y][0];
                backup_cube[1][2][0].position_lc_back = 2;
                backup_cube[1][2][0].b_degree_rotation();
            }
        }

    }
    cube = backup_cube;
}

void CRubicsCube::turn_counterclockwise(char side) {
    if (side == 'U') {
        turn_up_clockwise();
        turn_up_clockwise();
        turn_up_clockwise();
    } else if (side == 'D') {
        turn_down_clockwise();
        turn_down_clockwise();
        turn_down_clockwise();
    } else if (side == 'F') {
        turn_front_clockwise();
        turn_front_clockwise();
        turn_front_clockwise();
    } else if (side == 'B') {
        turn_back_clockwise();
        turn_back_clockwise();
        turn_back_clockwise();
    } else if (side == 'L') {
        turn_left_clockwise();
        turn_left_clockwise();
        turn_left_clockwise();
    } else if (side == 'R') {
        turn_right_clockwise();
        turn_right_clockwise();
        turn_right_clockwise();
    }
}

std::vector<std::vector<std::vector<CSmallCube>>> CRubicsCube::getVector() {
    return cube;
}

void CRubicsCube::setVector(std::vector<std::vector<std::vector<CSmallCube>>> process) {
    cube = std::move(process);
}

void CRubicsCube::positionCubes(char side) {
    if (side == 'U') {
        //Проставляем позиции кубиков верхней грани
        for (int z = 0; z < 3; z++) {
            for (int x = 0; x < 3; x++) {
                if (z == 0) {
                    cube[x][2][z].position_lc_up = x + 1;
                } else if (z == 1) {
                    if (x == 0) {
                        cube[x][2][z].position_lc_up = 8;
                    } else if (x == 2) {
                        cube[x][2][z].position_lc_up = 4;
                    }
                } else if (z == 2) {
                    cube[x][2][z].position_lc_up = abs(x - 7);
                }
            }
        }
    } else if (side == 'D') {
        //Проставляем позиции кубиков нижней грани
        for (int z = 2; z >= 0; z--) {
            for (int x = 0; x < 3; x++) {
                if (z == 2) {
                    cube[x][0][z].position_lc_down = x + 1;
                } else if (z == 1) {
                    if (x == 0) {
                        cube[x][0][z].position_lc_down = 8;
                    } else if (x == 2) {
                        cube[x][0][z].position_lc_down = 4;
                    }
                } else if (z == 0) {
                    cube[x][0][z].position_lc_down = abs(x - 7);
                }
            }
        }
    } else if (side == 'R') {
        //Проставляем позиции кубиков правой грани
        for (int y = 2; y >= 0; y--) {
            for (int z = 0; z < 3; z++) {
                if (y == 2) {
                    cube[2][y][z].position_lc_right = abs(z - 3);
                } else if (y == 1) {
                    if (z == 0) {
                        cube[2][y][z].position_lc_right = 4;
                    } else if (z == 2) {
                        cube[2][y][z].position_lc_right = 8;
                    }
                } else if (y == 0) {
                    cube[2][y][z].position_lc_right = z + 5;
                }
            }
        }
    } else if (side == 'L') {
        for (int y = 2; y >= 0; y--) {
            for (int z = 0; z < 3; z++) {
                if (y == 2) {
                    cube[0][y][z].position_lc_left = z + 1;
                } else if (y == 1) {
                    if (z == 0) {
                        cube[0][y][z].position_lc_left = 8;
                    } else if (z == 2) {
                        cube[0][y][z].position_lc_left = 4;
                    }
                } else if (y == 0) {
                    cube[0][y][z].position_lc_left = abs(z - 7);
                }
            }
        }
    } else if (side == 'F') {
        for (int y = 2; y >= 0; y--) {
            for (int x = 0; x < 3; x++) {
                if (y == 2) {
                    cube[x][y][2].position_lc_front = x + 1;
                } else if (y == 1) {
                    if (x == 0) {
                        cube[x][y][2].position_lc_front = 8;
                    } else if (x == 2) {
                        cube[x][y][2].position_lc_front = 4;
                    }
                } else if (y == 0) {
                    cube[x][y][2].position_lc_front = abs(x - 7);
                }
            }
        }
    } else if (side == 'B') {
        for (int y = 2; y >= 0; y--) {
            for (int x = 0; x < 3; x++) {
                if (y == 2) {
                    cube[x][y][0].position_lc_back = abs(x - 3);
                } else if (y == 1) {
                    if (x == 0) {
                        cube[x][y][0].position_lc_back = 4;
                    } else if (x == 2) {
                        cube[x][y][0].position_lc_back = 8;
                    }
                } else if (y == 0) {
                    cube[x][y][0].position_lc_back = x + 5;
                }
            }
        }
    }
}

CRubicsCube &CRubicsCube::operator=(const CRubicsCube &other) {
    cube = other.cube;
    return *this;
}

void CRubicsCube::writing_file() {
    int score = 0;
    std::ofstream fout;
    fout.open("../output.txt");
    //Запись кубика в файл
    //Вывод задней стороны
    for (int y = 2; y >= 0; y--) {
        for (int x = 2; x >= 0; x--) {
            if (score == 3) {
                fout << std::endl;
                score = 0;
            }
            fout << cube[x][y][0].lc_back << " ";
            score++;
        }
    }
    //Вывод передней грани
    for (int y = 2; y >= 0; y--) {
        for (int x = 0; x < 3; x++) {
            if (score == 3) {
                fout << std::endl;
                score = 0;
            }
            fout << cube[x][y][2].lc_front << " ";
            score++;
        }
    }
    //Вывод левой грани
    for (int y = 2; y >= 0; y--) {
        for (int z = 0; z < 3; z++) {
            if (score == 3) {
                fout << std::endl;
                score = 0;
            }
            fout << cube[0][y][z].lc_left << " ";
            score++;
        }
    }
    //Вывод правой грани
    for (int y = 2; y >= 0; y--) {
        for (int z = 2; z >= 0; z--) {
            if (score == 3) {
                fout << std::endl;
                score = 0;
            }
            fout << cube[2][y][z].lc_right << " ";
            score++;
        }
    }
    //Вывод верхней грани
    for (int z = 0; z < 3; z++) {
        for (int x = 0; x < 3; x++) {
            if (score == 3) {
                fout << std::endl;
                score = 0;
            }
            fout << cube[x][2][z].lc_up << " ";
            score++;
        }
    }

    //Вывод нижней грани
    for (int z = 2; z >= 0; z--) {
        for (int x = 0; x < 3; x++) {
            if (score == 3) {
                fout << std::endl;
                score = 0;
            }
            fout << cube[x][0][z].lc_down << " ";
            score++;
        }
    }

    fout.close();
}

void CRubicsCube::read_file() {
    std::vector<std::vector<std::vector<CSmallCube>>> backup_cube = cube;
    std::ifstream fin;
    fin.open("../input.txt");

    for (int y = 2; y >= 0; y--) {
        for (int x = 2; x >= 0; x--) {
            fin >> cube[x][y][0].lc_back;
        }
    }
    for (int y = 2; y >= 0; y--) {
        for (int x = 0; x < 3; x++) {
            fin >> cube[x][y][2].lc_front;
        }
    }
    for (int y = 2; y >= 0; y--) {
        for (int z = 0; z < 3; z++) {
            fin >> cube[0][y][z].lc_left;
        }
    }
    for (int y = 2; y >= 0; y--) {
        for (int z = 2; z >= 0; z--) {
            fin >> cube[2][y][z].lc_right;
        }
    }
    for (int z = 0; z < 3; z++) {
        for (int x = 0; x < 3; x++) {
            fin >> cube[x][2][z].lc_up;
        }
    }
    for (int z = 2; z >= 0; z--) {
        for (int x = 0; x < 3; x++) {
            fin >> cube[x][0][z].lc_down;
        }
    }
    fin.close();
}

void CRubicsCube::random_turn() {
    int k = 0;
    for(int i=0;i<20;i++){
        k = rand() % 10;
        if (k==0) {
            turn_front_clockwise();
        } else if (k==1) {
            turn_back_clockwise();
        } else if (k==2) {
            turn_left_clockwise();
        } else if (k==3) {
            turn_right_clockwise();
        } else if (k==4) {
            turn_down_clockwise();
        } else if (k==5) {
            turn_up_clockwise();
        } else if (k==6) {
            turn_counterclockwise('L');
        } else if (k==7) {
            turn_counterclockwise('D');
        } else if (k==8) {
            turn_counterclockwise('F');
        } else if (k==9) {
            turn_counterclockwise('B');
        }
    }

}

