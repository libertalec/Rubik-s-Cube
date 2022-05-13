#include "AssemblingRubiksCube.h"

AssemblingRubiksCube::AssemblingRubiksCube(CRubicsCube one) {
    assembling = one;

}


bool AssemblingRubiksCube::check_nn_cross() {

    std::vector<int> position;
    int check_non_cross = 0;
    bool check_non_cross1 = false;

    //Проверка на уже собранный крест
    assembling.positionCubes('U');
    if (assembling.cube[1][2][0].lc_up == "white") {
        check_non_cross++;
        position.push_back(assembling.cube[1][2][0].position_lc_up);
    }
    if (assembling.cube[2][2][1].lc_up == "white") {
        check_non_cross++;
        position.push_back(assembling.cube[2][2][1].position_lc_up);
    }
    if (assembling.cube[1][2][2].lc_up == "white") {
        check_non_cross++;
        position.push_back(assembling.cube[1][2][2].position_lc_up);
    }
    if (assembling.cube[0][2][1].lc_up == "white") {
        check_non_cross++;
        position.push_back(assembling.cube[0][2][1].position_lc_up);
    }

    if (check_non_cross == 4) {
        check_non_cross1 = true;
        return true;
    } else {
        return false;
    }
}

bool AssemblingRubiksCube::check_cross() {

    std::vector<int> position;
    int check_non_cross = 0;
    bool check_non_cross1 = false;

    //Проверка на уже собранный крест
    assembling.positionCubes('U');
    if (assembling.cube[1][0][0].lc_down == "white") {
        check_non_cross++;
        position.push_back(assembling.cube[1][2][0].position_lc_up);
    }
    if (assembling.cube[2][0][1].lc_down == "white") {
        check_non_cross++;
        position.push_back(assembling.cube[2][2][1].position_lc_up);
    }
    if (assembling.cube[1][0][2].lc_down == "white") {
        check_non_cross++;
        position.push_back(assembling.cube[1][2][2].position_lc_up);
    }
    if (assembling.cube[0][0][1].lc_down == "white") {
        check_non_cross++;
        position.push_back(assembling.cube[0][2][1].position_lc_up);
    }

    if (check_non_cross == 4) {
        check_non_cross1 = true;
        return true;
    } else {
        return false;
    }
}

void AssemblingRubiksCube::assembling_cross() {

    //Первый этап - сборка неправильного белого креста

    //Начало сборки
    for(int k = 0;k<24;k++) {
        if (!check_nn_cross()) {
            //Если есть нужные нам кубики на передней грани (синий)
            if (assembling.cube[0][1][2].lc_front == "white") {
                if (assembling.cube[0][2][1].lc_up == "white") {
                    while (assembling.cube[0][2][1].lc_up == "white") {
                        assembling.turn_up_clockwise();
                    }
                    assembling.turn_counterclockwise('L');
                } else {
                    assembling.turn_counterclockwise('L');
                }
            }
            if (assembling.cube[2][1][2].lc_front == "white") {
                if (assembling.cube[2][2][1].lc_up == "white") {
                    while (assembling.cube[2][2][1].lc_up == "white") {
                        assembling.turn_up_clockwise();
                    }
                    assembling.turn_right_clockwise();
                } else {
                    assembling.turn_right_clockwise();
                }
            }
            if (assembling.cube[1][2][2].lc_front == "white") {
                assembling.turn_front_clockwise();
                if (assembling.cube[2][2][1].lc_up == "white") {
                    while (assembling.cube[2][2][1].lc_up == "white") {
                        assembling.turn_up_clockwise();
                    }
                    assembling.turn_right_clockwise();
                    if (assembling.cube[1][2][2].lc_up == "white") {
                        if (!check_nn_cross()) {
                            while (assembling.cube[1][2][2].lc_up == "white") {
                                assembling.turn_up_clockwise();
                            }
                            assembling.turn_counterclockwise('F');
                        }


                    } else {
                        assembling.turn_counterclockwise('F');
                    }
                } else {
                    assembling.turn_right_clockwise();
                    if (assembling.cube[1][2][2].lc_up == "white") {
                        if (!check_nn_cross()) {
                            while (assembling.cube[1][2][2].lc_up == "white") {
                                assembling.turn_up_clockwise();
                            }
                            assembling.turn_counterclockwise('F');
                        }


                    } else {
                        assembling.turn_counterclockwise('F');
                    }
                }
            }
            if (assembling.cube[1][0][2].lc_front == "white") {
                if (assembling.cube[1][2][2].lc_up == "white") {
                    while (assembling.cube[1][2][2].lc_up == "white") {
                        assembling.turn_up_clockwise();
                    }
                    assembling.turn_counterclockwise('F');
                } else {
                    assembling.turn_counterclockwise('F');
                }

                if (assembling.cube[2][2][1].lc_up == "white") {
                    while (assembling.cube[2][2][1].lc_up == "white") {
                        assembling.turn_up_clockwise();
                    }
                    assembling.turn_right_clockwise();
                    if (assembling.cube[1][2][2].lc_up == "white") {
                        if (!check_nn_cross()) {
                            while (assembling.cube[1][2][2].lc_up == "white") {
                                assembling.turn_up_clockwise();
                            }
                            assembling.turn_front_clockwise();
                        }

                    } else {
                        assembling.turn_front_clockwise();
                    }
                } else {
                    assembling.turn_right_clockwise();
                    if (assembling.cube[1][2][2].lc_up == "white") {
                        if (!check_nn_cross()) {
                            while (assembling.cube[1][2][2].lc_up == "white") {
                                assembling.turn_up_clockwise();
                            }
                            assembling.turn_front_clockwise();
                        }

                    } else {
                        assembling.turn_front_clockwise();
                    }
                }
            }

            //Если нужные нам кубики есть на левой грани (оранжевая)
            if (assembling.cube[0][1][0].lc_left == "white") {
                if (assembling.cube[1][2][0].lc_up == "white") {
                    while (assembling.cube[1][2][0].lc_up == "white") {
                        assembling.turn_up_clockwise();
                    }
                    assembling.turn_counterclockwise('B');
                } else {
                    assembling.turn_counterclockwise('B');
                }
            }

            if (assembling.cube[0][1][2].lc_left == "white") {
                if (assembling.cube[1][2][2].lc_up == "white") {
                    while (assembling.cube[1][2][2].lc_up == "white") {
                        assembling.turn_up_clockwise();
                    }
                    assembling.turn_front_clockwise();
                } else {
                    assembling.turn_front_clockwise();
                }
            }
            if (assembling.cube[0][2][1].lc_left == "white") {
                assembling.turn_left_clockwise();
                if (assembling.cube[1][2][2].lc_up == "white") {
                    while (assembling.cube[1][2][2].lc_up == "white") {
                        assembling.turn_up_clockwise();
                    }
                    assembling.turn_front_clockwise();
                    if (assembling.cube[0][2][1].lc_up == "white") {
                        if (!check_nn_cross()) {
                            while (assembling.cube[0][2][1].lc_up == "white") {
                                assembling.turn_up_clockwise();
                            }
                            assembling.turn_counterclockwise('L');
                        }


                    } else {
                        assembling.turn_counterclockwise('L');
                    }
                } else {
                    assembling.turn_front_clockwise();
                    if (assembling.cube[0][2][1].lc_up == "white") {
                        if (!check_nn_cross()) {
                            while (assembling.cube[0][2][1].lc_up == "white") {
                                assembling.turn_up_clockwise();
                            }
                            assembling.turn_counterclockwise('L');
                        }


                    } else {
                        assembling.turn_counterclockwise('L');
                    }
                }
            }
            if (assembling.cube[0][0][1].lc_left == "white") {
                if (assembling.cube[0][2][1].lc_up == "white") {
                    while (assembling.cube[0][2][1].lc_up == "white") {
                        assembling.turn_up_clockwise();
                    }
                    assembling.turn_counterclockwise('L');
                } else {
                    assembling.turn_counterclockwise('L');
                }

                if (assembling.cube[1][2][2].lc_up == "white") {
                    while (assembling.cube[1][2][2].lc_up == "white") {
                        assembling.turn_up_clockwise();
                    }
                    assembling.turn_front_clockwise();
                    if (assembling.cube[0][2][1].lc_up == "white") {
                        if (!check_nn_cross()) {
                            while (assembling.cube[0][2][1].lc_up == "white") {
                                assembling.turn_up_clockwise();
                            }
                            assembling.turn_left_clockwise();
                        }

                    } else {
                        assembling.turn_left_clockwise();
                    }
                } else {
                    assembling.turn_front_clockwise();
                    if (assembling.cube[0][2][1].lc_up == "white") {
                        if (!check_nn_cross()) {
                            while (assembling.cube[0][2][1].lc_up == "white") {
                                assembling.turn_up_clockwise();
                            }
                            assembling.turn_left_clockwise();
                        }

                    } else {
                        assembling.turn_left_clockwise();
                    }
                }
            }
            //Если нужные нам кубики есть на правой грани (красная)
            if (assembling.cube[2][1][2].lc_right == "white") {
                if (assembling.cube[1][2][2].lc_up == "white") {
                    while (assembling.cube[1][2][2].lc_up == "white") {
                        assembling.turn_up_clockwise();
                    }
                    assembling.turn_counterclockwise('F');
                } else {
                    assembling.turn_counterclockwise('F');
                }
            }

            if (assembling.cube[2][1][0].lc_right == "white") {
                if (assembling.cube[1][2][0].lc_up == "white") {
                    while (assembling.cube[1][2][0].lc_up == "white") {
                        assembling.turn_up_clockwise();
                    }
                    assembling.turn_back_clockwise();
                } else {
                    assembling.turn_back_clockwise();
                }
            }
            if (assembling.cube[2][2][1].lc_right == "white") {
                assembling.turn_right_clockwise();
                if (assembling.cube[1][2][0].lc_up == "white") {
                    while (assembling.cube[1][2][0].lc_up == "white") {
                        assembling.turn_up_clockwise();
                    }
                    assembling.turn_back_clockwise();
                    if (assembling.cube[2][2][1].lc_up == "white") {
                        if (!check_nn_cross()) {
                            while (assembling.cube[2][2][1].lc_up == "white") {
                                assembling.turn_up_clockwise();
                            }
                            assembling.turn_counterclockwise('R');
                        }


                    } else {
                        assembling.turn_counterclockwise('R');
                    }
                } else {
                    assembling.turn_back_clockwise();
                    if (assembling.cube[2][2][1].lc_up == "white") {
                        if (!check_nn_cross()) {
                            while (assembling.cube[2][2][1].lc_up == "white") {
                                assembling.turn_up_clockwise();
                            }
                            assembling.turn_counterclockwise('R');
                        }


                    } else {
                        assembling.turn_counterclockwise('R');
                    }
                }
            }
            if (assembling.cube[2][0][1].lc_right == "white") {
                if (assembling.cube[2][2][1].lc_up == "white") {
                    while (assembling.cube[2][2][1].lc_up == "white") {
                        assembling.turn_up_clockwise();
                    }
                    assembling.turn_counterclockwise('R');
                } else {
                    assembling.turn_counterclockwise('R');
                }

                if (assembling.cube[1][2][0].lc_up == "white") {
                    while (assembling.cube[1][2][0].lc_up == "white") {
                        assembling.turn_up_clockwise();
                    }
                    assembling.turn_back_clockwise();
                    if (assembling.cube[2][2][1].lc_up == "white") {
                        if (!check_nn_cross()) {
                            while (assembling.cube[2][2][1].lc_up == "white") {
                                assembling.turn_up_clockwise();
                            }
                            assembling.turn_right_clockwise();
                        }

                    } else {
                        assembling.turn_right_clockwise();
                    }
                } else {
                    assembling.turn_back_clockwise();
                    if (assembling.cube[2][2][1].lc_up == "white") {
                        if (!check_nn_cross()) {
                            while (assembling.cube[2][2][1].lc_up == "white") {
                                assembling.turn_up_clockwise();
                            }
                            assembling.turn_right_clockwise();
                        }

                    } else {
                        assembling.turn_right_clockwise();
                    }
                }
            }

            //Если есть нужные нам кубики на задней грани (зеленый)
            if (assembling.cube[0][1][0].lc_back == "white") {
                if (assembling.cube[0][2][1].lc_up == "white") {
                    while (assembling.cube[0][2][1].lc_up == "white") {
                        assembling.turn_up_clockwise();
                    }
                    assembling.turn_left_clockwise();
                } else {
                    assembling.turn_left_clockwise();
                }
            }
            if (assembling.cube[2][1][0].lc_back == "white") {
                if (assembling.cube[2][2][1].lc_up == "white") {
                    while (assembling.cube[2][2][1].lc_up == "white") {
                        assembling.turn_up_clockwise();
                    }
                    assembling.turn_counterclockwise('R');
                } else {
                    assembling.turn_counterclockwise('R');
                }
            }
            if (assembling.cube[1][2][0].lc_back == "white") {
                assembling.turn_back_clockwise();
                if (assembling.cube[0][2][1].lc_up == "white") {
                    while (assembling.cube[0][2][1].lc_up == "white") {
                        assembling.turn_up_clockwise();
                    }
                    assembling.turn_left_clockwise();
                    if (assembling.cube[1][2][0].lc_up == "white") {
                        if (!check_nn_cross()) {
                            while (assembling.cube[1][2][0].lc_up == "white") {
                                assembling.turn_up_clockwise();
                            }
                            assembling.turn_counterclockwise('B');
                        }


                    } else {
                        assembling.turn_counterclockwise('B');
                    }
                } else {
                    assembling.turn_left_clockwise();
                    if (assembling.cube[1][2][0].lc_up == "white") {
                        if (!check_nn_cross()) {
                            while (assembling.cube[1][2][0].lc_up == "white") {
                                assembling.turn_up_clockwise();
                            }
                            assembling.turn_counterclockwise('B');
                        }


                    } else {
                        assembling.turn_counterclockwise('B');
                    }
                }
            }
            if (assembling.cube[1][0][0].lc_back == "white") {
                if (assembling.cube[1][2][0].lc_up == "white") {
                    while (assembling.cube[1][2][0].lc_up == "white") {
                        assembling.turn_up_clockwise();
                    }
                    assembling.turn_counterclockwise('B');
                } else {
                    assembling.turn_counterclockwise('B');
                }

                if (assembling.cube[0][2][1].lc_up == "white") {
                    while (assembling.cube[0][2][1].lc_up == "white") {
                        assembling.turn_up_clockwise();
                    }
                    assembling.turn_left_clockwise();
                    if (assembling.cube[1][2][0].lc_up == "white") {
                        if (!check_nn_cross()) {
                            while (assembling.cube[1][2][0].lc_up == "white") {
                                assembling.turn_up_clockwise();
                            }
                            assembling.turn_back_clockwise();
                        }

                    } else {
                        assembling.turn_back_clockwise();
                    }
                } else {
                    assembling.turn_left_clockwise();
                    if (assembling.cube[1][2][0].lc_up == "white") {
                        if (!check_nn_cross()) {
                            while (assembling.cube[1][2][0].lc_up == "white") {
                                assembling.turn_up_clockwise();
                            }
                            assembling.turn_back_clockwise();
                        }

                    } else {
                        assembling.turn_back_clockwise();
                    }
                }
            }

            //Если есть нужные нам кубики на нижней грани (белый)
            if (assembling.cube[0][0][1].lc_down == "white") {
                if (assembling.cube[0][2][1].lc_up == "white") {
                    while (assembling.cube[0][2][1].lc_up == "white") {
                        assembling.turn_up_clockwise();
                    }
                    assembling.turn_counterclockwise('L');
                    assembling.turn_counterclockwise('L');
                } else {
                    assembling.turn_counterclockwise('L');
                    assembling.turn_counterclockwise('L');
                }
            }
            if (assembling.cube[2][0][1].lc_down == "white") {
                if (assembling.cube[2][2][1].lc_up == "white") {
                    while (assembling.cube[2][2][1].lc_up == "white") {
                        assembling.turn_up_clockwise();
                    }
                    assembling.turn_right_clockwise();
                    assembling.turn_right_clockwise();
                } else {
                    assembling.turn_right_clockwise();
                    assembling.turn_right_clockwise();
                }
            }
            if (assembling.cube[1][0][2].lc_down == "white") {
                assembling.turn_down_clockwise();
                if (assembling.cube[2][2][1].lc_up == "white") {
                    while (assembling.cube[2][2][1].lc_up == "white") {
                        assembling.turn_up_clockwise();
                    }
                    assembling.turn_right_clockwise();
                    assembling.turn_right_clockwise();
                    assembling.turn_counterclockwise('D');
                } else {
                    assembling.turn_right_clockwise();
                    assembling.turn_right_clockwise();
                    assembling.turn_counterclockwise('D');
                }
            }
            if (assembling.cube[1][0][0].lc_down == "white") {
                assembling.turn_counterclockwise('D');
                if (assembling.cube[2][2][1].lc_up == "white") {
                    while (assembling.cube[2][2][1].lc_up == "white") {
                        assembling.turn_up_clockwise();
                    }
                    assembling.turn_right_clockwise();
                    assembling.turn_right_clockwise();
                    assembling.turn_down_clockwise();
                } else {
                    assembling.turn_right_clockwise();
                    assembling.turn_right_clockwise();
                    assembling.turn_down_clockwise();
                }
            }
        }

        //Собираем правильный крест
        if (check_nn_cross()) {
            //Сначала берем кубик на позиции 2
            while ((assembling.cube[1][1][0].lc_back != assembling.cube[1][2][0].lc_back) ||
                   assembling.cube[1][2][0].lc_up != "white") {
                assembling.turn_up_clockwise();
            }
            assembling.turn_back_clockwise();
            assembling.turn_back_clockwise();

            //Берем кубик на позиции 4
            while ((assembling.cube[2][1][1].lc_right != assembling.cube[2][2][1].lc_right) ||
                   assembling.cube[2][2][1].lc_up != "white") {
                assembling.turn_up_clockwise();
            }
            assembling.turn_right_clockwise();
            assembling.turn_right_clockwise();

            //Берём кубик на позиции 6
            while ((assembling.cube[1][1][2].lc_front != assembling.cube[1][2][2].lc_front) ||
                   assembling.cube[1][2][2].lc_up != "white") {
                assembling.turn_up_clockwise();
            }
            assembling.turn_front_clockwise();
            assembling.turn_front_clockwise();

            //Берём кубик на позиции 8
            while ((assembling.cube[0][1][1].lc_left != assembling.cube[0][2][1].lc_left) ||
                   assembling.cube[0][2][1].lc_up != "white") {
                assembling.turn_up_clockwise();
            }
            assembling.turn_left_clockwise();
            assembling.turn_left_clockwise();

        }
    }

}

void AssemblingRubiksCube::pif_paf_up(char side) {

    //Подготовка 0 2 2
    if (side == '7') {
        while (assembling.cube[0][2][2].lc_up != "white") {
            assembling.turn_front_clockwise();
            assembling.turn_up_clockwise();
            assembling.turn_counterclockwise('F');
            assembling.turn_counterclockwise('U');
        }
    } else if (side == '5') {
        //Подготовка кубика 2 2 2
        while (assembling.cube[2][2][2].lc_up != "white") {
            assembling.turn_right_clockwise();
            assembling.turn_up_clockwise();
            assembling.turn_counterclockwise('R');
            assembling.turn_counterclockwise('U');
        }
    } else if (side == '3') {
        //Подготовка кубика 2 2 0
        while (assembling.cube[2][2][0].lc_up != "white") {
            assembling.turn_back_clockwise();
            assembling.turn_up_clockwise();
            assembling.turn_counterclockwise('B');
            assembling.turn_counterclockwise('U');
        }
    } else if (side == '1') {
        //Подготовка кубика 0 2 0
        while (assembling.cube[0][2][0].lc_up != "white") {
            assembling.turn_left_clockwise();
            assembling.turn_up_clockwise();
            assembling.turn_counterclockwise('L');
            assembling.turn_counterclockwise('U');
        }
    }

}

bool AssemblingRubiksCube::check_neighboring_side(char side) {

    if (side == '7') {
        if (((assembling.cube[0][2][2].lc_left == assembling.cube[0][1][1].lc_left) &&
             (assembling.cube[0][2][2].lc_front == assembling.cube[1][1][2].lc_front)) ||
            ((assembling.cube[0][2][2].lc_left == assembling.cube[1][1][2].lc_front) &&
             (assembling.cube[0][2][2].lc_front == assembling.cube[0][1][1].lc_left))) {
            return true;
        }
    } else if (side == '5') {
        if (((assembling.cube[2][2][2].lc_front == assembling.cube[1][1][2].lc_front) &&
             (assembling.cube[2][2][2].lc_right == assembling.cube[2][1][1].lc_right)) ||
            ((assembling.cube[2][2][2].lc_front == assembling.cube[2][1][1].lc_right) &&
             (assembling.cube[2][2][2].lc_right == assembling.cube[1][1][2].lc_front))) {
            return true;
        }
    } else if (side == '3') {
        if (((assembling.cube[2][2][0].lc_right == assembling.cube[2][1][1].lc_right) &&
             (assembling.cube[2][2][0].lc_back == assembling.cube[1][1][0].lc_back)) ||
            ((assembling.cube[2][2][0].lc_right == assembling.cube[1][1][0].lc_back) &&
             (assembling.cube[2][2][0].lc_back == assembling.cube[2][1][1].lc_right))) {
            return true;
        }
    } else if (side == '1') {
        if (((assembling.cube[0][2][0].lc_back == assembling.cube[1][1][0].lc_back) &&
             (assembling.cube[0][2][0].lc_left == assembling.cube[0][1][1].lc_left)) ||
            ((assembling.cube[0][2][0].lc_back == assembling.cube[0][1][1].lc_left) &&
             (assembling.cube[0][2][0].lc_left == assembling.cube[1][1][0].lc_back))) {
            return true;
        }
    }
}

bool AssemblingRubiksCube::check_up_white() {

    int score = 0;
    if (assembling.cube[0][2][2].lc_up == "white" || assembling.cube[0][2][2].lc_left == "white" ||
        assembling.cube[0][2][2].lc_front == "white") {
        score++;
    }
    if (assembling.cube[2][2][2].lc_up == "white" || assembling.cube[2][2][2].lc_right == "white" ||
        assembling.cube[2][2][2].lc_front == "white") {
        score++;
    }
    if (assembling.cube[2][2][0].lc_up == "white" || assembling.cube[2][2][0].lc_back == "white" ||
        assembling.cube[2][2][0].lc_right == "white") {
        score++;
    }
    if (assembling.cube[0][2][0].lc_up == "white" || assembling.cube[0][2][0].lc_back == "white" ||
        assembling.cube[0][2][0].lc_left == "white") {
        score++;
    }
    if (score == 4) {
        return true;
    } else {
        return false;
    }
}

void AssemblingRubiksCube::assembling_white_side() {

    //Убираем кубик с белой стороной из 0 0 2
    if (!check_up_white()) {
        while (assembling.cube[0][2][2].lc_up == "white" || assembling.cube[0][2][2].lc_left == "white" ||
               assembling.cube[0][2][2].lc_front == "white") {
            assembling.turn_up_clockwise();
        }
        assembling.turn_front_clockwise();
        while (assembling.cube[0][2][2].lc_up == "white" || assembling.cube[0][2][2].lc_left == "white" ||
               assembling.cube[0][2][2].lc_front == "white") {
            assembling.turn_up_clockwise();
        }
        assembling.turn_counterclockwise('F');

        if (!check_up_white()) {
            //Убираем кубик в 2 0 2
            while (assembling.cube[2][2][2].lc_up == "white" || assembling.cube[2][2][2].lc_right == "white" ||
                   assembling.cube[2][2][2].lc_front == "white") {
                assembling.turn_up_clockwise();
            }
            assembling.turn_right_clockwise();
            while (assembling.cube[2][2][2].lc_up == "white" || assembling.cube[2][2][2].lc_right == "white" ||
                   assembling.cube[2][2][2].lc_front == "white") {
                assembling.turn_up_clockwise();
            }
            assembling.turn_counterclockwise('R');
            if (!check_up_white()) {
                //Убираем кубик 2 0 0
                while (assembling.cube[2][2][0].lc_up == "white" || assembling.cube[2][2][0].lc_back == "white" ||
                       assembling.cube[2][2][0].lc_right == "white") {
                    assembling.turn_up_clockwise();
                }
                assembling.turn_back_clockwise();
                while (assembling.cube[2][2][0].lc_up == "white" || assembling.cube[2][2][0].lc_back == "white" ||
                       assembling.cube[2][2][0].lc_right == "white") {
                    assembling.turn_up_clockwise();
                }
                assembling.turn_counterclockwise('B');
                if (!check_up_white()) {
                    //Убираем кубик 0 0 0
                    while (assembling.cube[0][2][0].lc_up == "white" || assembling.cube[0][2][0].lc_back == "white" ||
                           assembling.cube[0][2][0].lc_left == "white") {
                        assembling.turn_up_clockwise();
                    }
                    assembling.turn_left_clockwise();
                    while (assembling.cube[0][2][0].lc_up == "white" || assembling.cube[0][2][0].lc_back == "white" ||
                           assembling.cube[0][2][0].lc_left == "white") {
                        assembling.turn_up_clockwise();
                    }
                    assembling.turn_counterclockwise('L');
                }

            }

        }


    }
    //Подготовка угловых кубиков к поворотам

    //Выставляем кубик 0 0 2
    if (assembling.cube[0][2][2].lc_up == "white" || assembling.cube[0][2][2].lc_left == "white" ||
        assembling.cube[0][2][2].lc_front == "white") {
        pif_paf_up('7');
    } else {
        while (assembling.cube[0][2][2].lc_up != "white" && assembling.cube[0][2][2].lc_left != "white" &&
               assembling.cube[0][2][2].lc_front != "white") {
            assembling.turn_up_clockwise();
        }
        pif_paf_up('7');
    }

    while (!check_neighboring_side('7')) {
        assembling.turn_up_clockwise();
        if (assembling.cube[0][2][2].lc_up == "white" || assembling.cube[0][2][2].lc_left == "white" ||
            assembling.cube[0][2][2].lc_front == "white") {
            pif_paf_up('7');
        } else {
            while (assembling.cube[0][2][2].lc_up != "white" && assembling.cube[0][2][2].lc_left != "white" &&
                   assembling.cube[0][2][2].lc_front != "white") {
                assembling.turn_up_clockwise();
            }
            pif_paf_up('7');
        }
    }
    while (assembling.cube[0][0][2].lc_down != "white") {
        assembling.turn_front_clockwise();
        assembling.turn_up_clockwise();
        assembling.turn_counterclockwise('F');
        assembling.turn_counterclockwise('U');
    }
    //Выставляем кубик 2 0 2
    if (assembling.cube[2][2][2].lc_up == "white" || assembling.cube[2][2][2].lc_right == "white" ||
        assembling.cube[2][2][2].lc_front == "white") {
        pif_paf_up('5');
    } else {
        while (assembling.cube[2][2][2].lc_up != "white" && assembling.cube[2][2][2].lc_right != "white" &&
               assembling.cube[2][2][2].lc_front != "white") {
            assembling.turn_up_clockwise();
        }
        pif_paf_up('5');
    }
    while (!check_neighboring_side('5')) {
        assembling.turn_up_clockwise();
        if (assembling.cube[2][2][2].lc_up == "white" || assembling.cube[2][2][2].lc_right == "white" ||
            assembling.cube[2][2][2].lc_front == "white") {
            pif_paf_up('5');
        } else {
            while (assembling.cube[2][2][2].lc_up != "white" && assembling.cube[2][2][2].lc_right != "white" &&
                   assembling.cube[2][2][2].lc_front != "white") {
                assembling.turn_up_clockwise();
            }
            pif_paf_up('5');
        }
    }
    while (assembling.cube[2][0][2].lc_down != "white") {
        assembling.turn_right_clockwise();
        assembling.turn_up_clockwise();
        assembling.turn_counterclockwise('R');
        assembling.turn_counterclockwise('U');
    }

    //Выставляем кубик 2 0 0
    if (assembling.cube[2][2][0].lc_up == "white" || assembling.cube[2][2][0].lc_back == "white" ||
        assembling.cube[2][2][0].lc_right == "white") {
        pif_paf_up('3');
    } else {
        while (assembling.cube[2][2][0].lc_up != "white" && assembling.cube[2][2][0].lc_right != "white" &&
               assembling.cube[2][2][0].lc_back != "white") {
            assembling.turn_up_clockwise();
        }
        pif_paf_up('3');
    }
    while (!check_neighboring_side('3')) {
        assembling.turn_up_clockwise();
        if (assembling.cube[2][2][0].lc_up == "white" || assembling.cube[2][2][0].lc_back == "white" ||
            assembling.cube[2][2][0].lc_right == "white") {
            pif_paf_up('3');
        } else {
            while (assembling.cube[2][2][0].lc_up != "white" && assembling.cube[2][2][0].lc_right != "white" &&
                   assembling.cube[2][2][0].lc_back != "white") {
                assembling.turn_up_clockwise();
            }
            pif_paf_up('3');
        }
    }
    while (assembling.cube[2][0][0].lc_down != "white") {
        assembling.turn_back_clockwise();
        assembling.turn_up_clockwise();
        assembling.turn_counterclockwise('B');
        assembling.turn_counterclockwise('U');
    }
    //Выставляем кубик 0 0 0
    if (assembling.cube[0][2][0].lc_up == "white" || assembling.cube[0][2][0].lc_back == "white" ||
        assembling.cube[0][2][0].lc_left == "white") {
        pif_paf_up('1');
    } else {
        while (assembling.cube[0][2][0].lc_up != "white" && assembling.cube[0][2][0].lc_left != "white" &&
               assembling.cube[0][2][0].lc_back != "white") {
            assembling.turn_up_clockwise();
        }
        pif_paf_up('1');
    }
    while (!check_neighboring_side('1')) {
        assembling.turn_up_clockwise();
        if (assembling.cube[0][2][0].lc_up == "white" || assembling.cube[0][2][0].lc_back == "white" ||
            assembling.cube[0][2][0].lc_left == "white") {
            pif_paf_up('1');
        } else {
            while (assembling.cube[0][2][0].lc_up != "white" && assembling.cube[0][2][0].lc_left != "white" &&
                   assembling.cube[0][2][0].lc_back != "white") {
                assembling.turn_up_clockwise();
            }
            pif_paf_up('1');
        }
    }
    while (assembling.cube[0][0][0].lc_down != "white") {
        assembling.turn_left_clockwise();
        assembling.turn_up_clockwise();
        assembling.turn_counterclockwise('L');
        assembling.turn_counterclockwise('U');
    }
}

void AssemblingRubiksCube::side_selection(char side) {

    if (side == 'B') {
        //Находим для синего центра подходящую грань
        int score_blue = 0;
        for (int i = 0; i < 4; i++) {
            if (assembling.cube[1][1][2].lc_front == assembling.cube[1][2][2].lc_front) {
                score_blue++;
            }
            assembling.turn_up_clockwise();
        }
        //Мы нашли подходящую грань
        if (score_blue == 1) {
            for (int i = 0; i < 4; i++) {
                if (assembling.cube[1][1][2].lc_front == assembling.cube[1][2][2].lc_front) {
                    break;
                }
                assembling.turn_up_clockwise();
            }
            if (assembling.cube[1][2][2].lc_up == "orange") {
                assembling.turn_counterclockwise('U');
                assembling.turn_counterclockwise('L');
                assembling.turn_counterclockwise('U');
                assembling.turn_left_clockwise();
                assembling.turn_up_clockwise();
                assembling.turn_front_clockwise();
                assembling.turn_up_clockwise();
                assembling.turn_counterclockwise('F');
                assembling.turn_counterclockwise('U');

            } else if (assembling.cube[1][2][2].lc_up == "red") {
                assembling.turn_up_clockwise();
                assembling.turn_right_clockwise();
                assembling.turn_up_clockwise();
                assembling.turn_counterclockwise('R');
                assembling.turn_counterclockwise('U');
                assembling.turn_counterclockwise('F');
                assembling.turn_counterclockwise('U');
                assembling.turn_front_clockwise();
                assembling.turn_up_clockwise();
            }
        } else if (score_blue == 2) {
            for (int i = 0; i < 4; i++) {
                if (assembling.cube[1][1][2].lc_front == assembling.cube[1][2][2].lc_front) {
                    break;
                }
                assembling.turn_up_clockwise();
            }
            if (assembling.cube[1][2][2].lc_up == "orange") {
                assembling.turn_counterclockwise('U');
                assembling.turn_counterclockwise('L');
                assembling.turn_counterclockwise('U');
                assembling.turn_left_clockwise();
                assembling.turn_up_clockwise();
                assembling.turn_front_clockwise();
                assembling.turn_up_clockwise();
                assembling.turn_counterclockwise('F');
                assembling.turn_counterclockwise('U');

            } else if (assembling.cube[1][2][2].lc_up == "red") {
                assembling.turn_up_clockwise();
                assembling.turn_right_clockwise();
                assembling.turn_up_clockwise();
                assembling.turn_counterclockwise('R');
                assembling.turn_counterclockwise('U');
                assembling.turn_counterclockwise('F');
                assembling.turn_counterclockwise('U');
                assembling.turn_front_clockwise();
                assembling.turn_up_clockwise();
            }
            for (int i = 0; i < 4; i++) {
                if (assembling.cube[1][1][2].lc_front == assembling.cube[1][2][2].lc_front) {
                    break;
                }
                assembling.turn_up_clockwise();
            }
            if (assembling.cube[1][2][2].lc_up == "orange") {
                assembling.turn_counterclockwise('U');
                assembling.turn_counterclockwise('L');
                assembling.turn_counterclockwise('U');
                assembling.turn_left_clockwise();
                assembling.turn_up_clockwise();
                assembling.turn_front_clockwise();
                assembling.turn_up_clockwise();
                assembling.turn_counterclockwise('F');
                assembling.turn_counterclockwise('U');

            } else if (assembling.cube[1][2][2].lc_up == "red") {
                assembling.turn_up_clockwise();
                assembling.turn_right_clockwise();
                assembling.turn_up_clockwise();
                assembling.turn_counterclockwise('R');
                assembling.turn_counterclockwise('U');
                assembling.turn_counterclockwise('F');
                assembling.turn_counterclockwise('U');
                assembling.turn_front_clockwise();
                assembling.turn_up_clockwise();
            }

        }
    } else if (side == 'O') {
        //Находим для оранжевого центра подходящую грань
        int score_orange = 0;
        for (int i = 0; i < 4; i++) {
            if (assembling.cube[0][1][1].lc_left == assembling.cube[0][2][1].lc_left) {
                score_orange++;
            }
            assembling.turn_up_clockwise();
        }
        //Мы нашли подходящую грань
        if (score_orange == 1) {
            for (int i = 0; i < 4; i++) {
                if (assembling.cube[0][1][1].lc_left == assembling.cube[0][2][1].lc_left) {
                    break;
                }
                assembling.turn_up_clockwise();
            }
            if (assembling.cube[0][2][1].lc_up == "green") {
                assembling.turn_counterclockwise('U');
                assembling.turn_counterclockwise('B');
                assembling.turn_counterclockwise('U');
                assembling.turn_back_clockwise();
                assembling.turn_up_clockwise();
                assembling.turn_left_clockwise();
                assembling.turn_up_clockwise();
                assembling.turn_counterclockwise('L');
                assembling.turn_counterclockwise('U');


            } else if (assembling.cube[0][2][1].lc_up == "blue") {
                assembling.turn_up_clockwise();
                assembling.turn_front_clockwise();
                assembling.turn_up_clockwise();
                assembling.turn_counterclockwise('F');
                assembling.turn_counterclockwise('U');
                assembling.turn_counterclockwise('L');
                assembling.turn_counterclockwise('U');
                assembling.turn_left_clockwise();
                assembling.turn_up_clockwise();
            }
        } else if (score_orange == 2) {
            for (int i = 0; i < 4; i++) {
                if (assembling.cube[0][1][1].lc_left == assembling.cube[0][2][1].lc_left) {
                    break;
                }
                assembling.turn_up_clockwise();
            }
            if (assembling.cube[0][2][1].lc_up == "green") {
                assembling.turn_counterclockwise('U');
                assembling.turn_counterclockwise('B');
                assembling.turn_counterclockwise('U');
                assembling.turn_back_clockwise();
                assembling.turn_up_clockwise();
                assembling.turn_left_clockwise();
                assembling.turn_up_clockwise();
                assembling.turn_counterclockwise('L');
                assembling.turn_counterclockwise('U');


            } else if (assembling.cube[0][2][1].lc_up == "blue") {
                assembling.turn_up_clockwise();
                assembling.turn_front_clockwise();
                assembling.turn_up_clockwise();
                assembling.turn_counterclockwise('F');
                assembling.turn_counterclockwise('U');
                assembling.turn_counterclockwise('L');
                assembling.turn_counterclockwise('U');
                assembling.turn_left_clockwise();
                assembling.turn_up_clockwise();
            }
            for (int i = 0; i < 4; i++) {
                if (assembling.cube[0][1][1].lc_left == assembling.cube[0][2][1].lc_left) {
                    break;
                }
                assembling.turn_up_clockwise();
            }
            if (assembling.cube[0][2][1].lc_up == "green") {
                assembling.turn_counterclockwise('U');
                assembling.turn_counterclockwise('B');
                assembling.turn_counterclockwise('U');
                assembling.turn_back_clockwise();
                assembling.turn_up_clockwise();
                assembling.turn_left_clockwise();
                assembling.turn_up_clockwise();
                assembling.turn_counterclockwise('L');
                assembling.turn_counterclockwise('U');


            } else if (assembling.cube[0][2][1].lc_up == "blue") {
                assembling.turn_up_clockwise();
                assembling.turn_front_clockwise();
                assembling.turn_up_clockwise();
                assembling.turn_counterclockwise('F');
                assembling.turn_counterclockwise('U');
                assembling.turn_counterclockwise('L');
                assembling.turn_counterclockwise('U');
                assembling.turn_left_clockwise();
                assembling.turn_up_clockwise();
            }

        }
    } else if (side == 'R') {
        //Находим для красного центра подходящую грань
        int score_red = 0;
        for (int i = 0; i < 4; i++) {
            if (assembling.cube[2][1][1].lc_right == assembling.cube[2][2][1].lc_right) {
                score_red++;
            }
            assembling.turn_up_clockwise();
        }
        //Мы нашли подходящую грань
        if (score_red == 1) {
            for (int i = 0; i < 4; i++) {
                if (assembling.cube[2][1][1].lc_right == assembling.cube[2][2][1].lc_right) {
                    break;
                }
                assembling.turn_up_clockwise();
            }
            if (assembling.cube[2][2][1].lc_up == "green") {
                assembling.turn_up_clockwise();
                assembling.turn_back_clockwise();
                assembling.turn_up_clockwise();
                assembling.turn_counterclockwise('B');
                assembling.turn_counterclockwise('U');
                assembling.turn_counterclockwise('R');
                assembling.turn_counterclockwise('U');
                assembling.turn_right_clockwise();
                assembling.turn_up_clockwise();


            } else if (assembling.cube[2][2][1].lc_up == "blue") {
                assembling.turn_counterclockwise('U');
                assembling.turn_counterclockwise('F');
                assembling.turn_counterclockwise('U');
                assembling.turn_front_clockwise();
                assembling.turn_up_clockwise();
                assembling.turn_right_clockwise();
                assembling.turn_up_clockwise();
                assembling.turn_counterclockwise('R');
                assembling.turn_counterclockwise('U');
            }
        } else if (score_red == 2) {
            for (int i = 0; i < 4; i++) {
                if (assembling.cube[2][1][1].lc_right == assembling.cube[2][2][1].lc_right) {
                    break;
                }
                assembling.turn_up_clockwise();
            }
            if (assembling.cube[2][2][1].lc_up == "green") {
                assembling.turn_up_clockwise();
                assembling.turn_back_clockwise();
                assembling.turn_up_clockwise();
                assembling.turn_counterclockwise('B');
                assembling.turn_counterclockwise('U');
                assembling.turn_counterclockwise('R');
                assembling.turn_counterclockwise('U');
                assembling.turn_right_clockwise();
                assembling.turn_up_clockwise();


            } else if (assembling.cube[2][2][1].lc_up == "blue") {
                assembling.turn_counterclockwise('U');
                assembling.turn_counterclockwise('F');
                assembling.turn_counterclockwise('U');
                assembling.turn_front_clockwise();
                assembling.turn_up_clockwise();
                assembling.turn_right_clockwise();
                assembling.turn_up_clockwise();
                assembling.turn_counterclockwise('R');
                assembling.turn_counterclockwise('U');
            }
            for (int i = 0; i < 4; i++) {
                if (assembling.cube[2][1][1].lc_right == assembling.cube[2][2][1].lc_right) {
                    break;
                }
                assembling.turn_up_clockwise();
            }
            if (assembling.cube[2][2][1].lc_up == "green") {
                assembling.turn_up_clockwise();
                assembling.turn_back_clockwise();
                assembling.turn_up_clockwise();
                assembling.turn_counterclockwise('B');
                assembling.turn_counterclockwise('U');
                assembling.turn_counterclockwise('R');
                assembling.turn_counterclockwise('U');
                assembling.turn_right_clockwise();
                assembling.turn_up_clockwise();


            } else if (assembling.cube[2][2][1].lc_up == "blue") {
                assembling.turn_counterclockwise('U');
                assembling.turn_counterclockwise('F');
                assembling.turn_counterclockwise('U');
                assembling.turn_front_clockwise();
                assembling.turn_up_clockwise();
                assembling.turn_right_clockwise();
                assembling.turn_up_clockwise();
                assembling.turn_counterclockwise('R');
                assembling.turn_counterclockwise('U');
            }

        }

    } else if (side == 'G') {
        //Находим для зеленого центра подходящую грань
        int score_green = 0;
        for (int i = 0; i < 4; i++) {
            if (assembling.cube[1][1][0].lc_back == assembling.cube[1][2][0].lc_back) {
                score_green++;
            }
            assembling.turn_up_clockwise();
        }
        //Мы нашли подходящую грань
        if (score_green == 1) {
            for (int i = 0; i < 4; i++) {
                if (assembling.cube[1][1][0].lc_back == assembling.cube[1][2][0].lc_back) {
                    break;
                }
                assembling.turn_up_clockwise();
            }
            if (assembling.cube[1][2][0].lc_up == "red") {
                assembling.turn_counterclockwise('U');
                assembling.turn_counterclockwise('R');
                assembling.turn_counterclockwise('U');
                assembling.turn_right_clockwise();
                assembling.turn_up_clockwise();
                assembling.turn_back_clockwise();
                assembling.turn_up_clockwise();
                assembling.turn_counterclockwise('B');
                assembling.turn_counterclockwise('U');

            } else if (assembling.cube[1][2][0].lc_up == "orange") {
                assembling.turn_up_clockwise();
                assembling.turn_left_clockwise();
                assembling.turn_up_clockwise();
                assembling.turn_counterclockwise('L');
                assembling.turn_counterclockwise('U');
                assembling.turn_counterclockwise('B');
                assembling.turn_counterclockwise('U');
                assembling.turn_back_clockwise();
                assembling.turn_up_clockwise();
            }
        } else if (score_green == 2) {
            for (int i = 0; i < 4; i++) {
                if (assembling.cube[1][1][0].lc_back == assembling.cube[1][2][0].lc_back) {
                    break;
                }
                assembling.turn_up_clockwise();
            }
            if (assembling.cube[1][2][0].lc_up == "red") {
                assembling.turn_counterclockwise('U');
                assembling.turn_counterclockwise('R');
                assembling.turn_counterclockwise('U');
                assembling.turn_right_clockwise();
                assembling.turn_up_clockwise();
                assembling.turn_back_clockwise();
                assembling.turn_up_clockwise();
                assembling.turn_counterclockwise('B');
                assembling.turn_counterclockwise('U');

            } else if (assembling.cube[1][2][0].lc_up == "orange") {
                assembling.turn_up_clockwise();
                assembling.turn_left_clockwise();
                assembling.turn_up_clockwise();
                assembling.turn_counterclockwise('L');
                assembling.turn_counterclockwise('U');
                assembling.turn_counterclockwise('B');
                assembling.turn_counterclockwise('U');
                assembling.turn_back_clockwise();
                assembling.turn_up_clockwise();
            }
            for (int i = 0; i < 4; i++) {
                if (assembling.cube[1][1][0].lc_back == assembling.cube[1][2][0].lc_back) {
                    break;
                }
                assembling.turn_up_clockwise();
            }
            if (assembling.cube[1][2][0].lc_up == "red") {
                assembling.turn_counterclockwise('U');
                assembling.turn_counterclockwise('R');
                assembling.turn_counterclockwise('U');
                assembling.turn_right_clockwise();
                assembling.turn_up_clockwise();
                assembling.turn_back_clockwise();
                assembling.turn_up_clockwise();
                assembling.turn_counterclockwise('B');
                assembling.turn_counterclockwise('U');

            } else if (assembling.cube[1][2][0].lc_up == "orange") {
                assembling.turn_up_clockwise();
                assembling.turn_left_clockwise();
                assembling.turn_up_clockwise();
                assembling.turn_counterclockwise('L');
                assembling.turn_counterclockwise('U');
                assembling.turn_counterclockwise('B');
                assembling.turn_counterclockwise('U');
                assembling.turn_back_clockwise();
                assembling.turn_up_clockwise();
            }

        }
    }

}

void AssemblingRubiksCube::second_layer() {

    for (int i = 0; i < 4; i++) {
        side_selection('B');
        side_selection('O');
        side_selection('R');
        side_selection('G');
    }
    for (int k = 0; k < 4; k++) {
        //Проверка на неправильные позиции
        if (!((assembling.cube[0][1][2].lc_front == assembling.cube[1][1][2].lc_front) &&
              (assembling.cube[0][1][2].lc_left == assembling.cube[0][1][1].lc_left))) {
            assembling.turn_counterclockwise('L');
            assembling.turn_counterclockwise('U');
            assembling.turn_left_clockwise();
            assembling.turn_up_clockwise();
            assembling.turn_front_clockwise();
            assembling.turn_up_clockwise();
            assembling.turn_counterclockwise('F');
            assembling.turn_counterclockwise('U');
            for (int i = 0; i < 4; i++) {
                side_selection('B');
                side_selection('O');
                side_selection('R');
                side_selection('G');
            }
        }
        if (!((assembling.cube[2][1][2].lc_front == assembling.cube[1][1][2].lc_front) &&
              (assembling.cube[2][1][2].lc_right == assembling.cube[2][1][1].lc_right))) {
            assembling.turn_counterclockwise('F');
            assembling.turn_counterclockwise('U');
            assembling.turn_front_clockwise();
            assembling.turn_up_clockwise();
            assembling.turn_right_clockwise();
            assembling.turn_up_clockwise();
            assembling.turn_counterclockwise('R');
            assembling.turn_counterclockwise('U');
            for (int i = 0; i < 4; i++) {
                side_selection('B');
                side_selection('O');
                side_selection('R');
                side_selection('G');
            }
        }
        if (!((assembling.cube[2][1][0].lc_back == assembling.cube[1][1][0].lc_back) &&
              (assembling.cube[2][1][0].lc_right == assembling.cube[2][1][1].lc_right))) {
            assembling.turn_counterclockwise('R');
            assembling.turn_counterclockwise('U');
            assembling.turn_right_clockwise();
            assembling.turn_up_clockwise();
            assembling.turn_back_clockwise();
            assembling.turn_up_clockwise();
            assembling.turn_counterclockwise('B');
            assembling.turn_counterclockwise('U');
            for (int i = 0; i < 4; i++) {
                side_selection('B');
                side_selection('O');
                side_selection('R');
                side_selection('G');
            }

        }
        if (!((assembling.cube[0][1][0].lc_back == assembling.cube[1][1][0].lc_back) &&
              (assembling.cube[0][1][0].lc_left == assembling.cube[0][1][1].lc_left))) {
            assembling.turn_counterclockwise('B');
            assembling.turn_counterclockwise('U');
            assembling.turn_back_clockwise();
            assembling.turn_up_clockwise();
            assembling.turn_left_clockwise();
            assembling.turn_up_clockwise();
            assembling.turn_counterclockwise('L');
            assembling.turn_counterclockwise('U');
            for (int i = 0; i < 4; i++) {
                side_selection('B');
                side_selection('O');
                side_selection('R');
                side_selection('G');
            }
        }
    }
}

bool AssemblingRubiksCube::check_yellow_cross() {

    int check_non_cross = 0;
    bool check_non_cross1 = false;

    if (assembling.cube[1][2][0].lc_up == "yellow") {
        check_non_cross++;
    }
    if (assembling.cube[2][2][1].lc_up == "yellow") {
        check_non_cross++;

    }
    if (assembling.cube[1][2][2].lc_up == "yellow") {
        check_non_cross++;
    }
    if (assembling.cube[0][2][1].lc_up == "yellow") {
        check_non_cross++;
    }

    if (check_non_cross == 4) {
        check_non_cross1 = true;
        return true;
    } else {
        return false;
    }
}

void AssemblingRubiksCube::assembling_yellow_cross() {

    //Начнем с проверки на крест
    if (!check_yellow_cross()) {
        if (assembling.cube[1][2][0].lc_up == "yellow" && assembling.cube[1][2][2].lc_up == "yellow") {
            assembling.turn_right_clockwise();
            assembling.turn_back_clockwise();
            assembling.turn_up_clockwise();
            assembling.turn_counterclockwise('B');
            assembling.turn_counterclockwise('U');
            assembling.turn_counterclockwise('R');
        } else if (assembling.cube[0][2][1].lc_up == "yellow" && assembling.cube[2][2][1].lc_up == "yellow") {
            assembling.turn_front_clockwise();
            assembling.turn_right_clockwise();
            assembling.turn_up_clockwise();
            assembling.turn_counterclockwise('R');
            assembling.turn_counterclockwise('U');
            assembling.turn_counterclockwise('F');
        }
        if (!check_yellow_cross()) {
            if (assembling.cube[1][2][0].lc_up == "yellow" && assembling.cube[0][2][1].lc_up == "yellow") {
                assembling.turn_front_clockwise();
                assembling.turn_right_clockwise();
                assembling.turn_up_clockwise();
                assembling.turn_counterclockwise('R');
                assembling.turn_counterclockwise('U');
                assembling.turn_right_clockwise();
                assembling.turn_up_clockwise();
                assembling.turn_counterclockwise('R');
                assembling.turn_counterclockwise('U');
                assembling.turn_counterclockwise('F');
            } else if (assembling.cube[1][2][0].lc_up == "yellow" && assembling.cube[2][2][1].lc_up == "yellow") {
                assembling.turn_counterclockwise('U');
                assembling.turn_front_clockwise();
                assembling.turn_right_clockwise();
                assembling.turn_up_clockwise();
                assembling.turn_counterclockwise('R');
                assembling.turn_counterclockwise('U');
                assembling.turn_right_clockwise();
                assembling.turn_up_clockwise();
                assembling.turn_counterclockwise('R');
                assembling.turn_counterclockwise('U');
                assembling.turn_counterclockwise('F');
            } else if (assembling.cube[2][2][1].lc_up == "yellow" && assembling.cube[1][2][2].lc_up == "yellow") {
                assembling.turn_up_clockwise();
                assembling.turn_up_clockwise();
                assembling.turn_front_clockwise();
                assembling.turn_right_clockwise();
                assembling.turn_up_clockwise();
                assembling.turn_counterclockwise('R');
                assembling.turn_counterclockwise('U');
                assembling.turn_right_clockwise();
                assembling.turn_up_clockwise();
                assembling.turn_counterclockwise('R');
                assembling.turn_counterclockwise('U');
                assembling.turn_counterclockwise('F');
            } else if (assembling.cube[1][2][2].lc_up == "yellow" && assembling.cube[0][2][1].lc_up == "yellow") {
                assembling.turn_up_clockwise();
                assembling.turn_front_clockwise();
                assembling.turn_right_clockwise();
                assembling.turn_up_clockwise();
                assembling.turn_counterclockwise('R');
                assembling.turn_counterclockwise('U');
                assembling.turn_right_clockwise();
                assembling.turn_up_clockwise();
                assembling.turn_counterclockwise('R');
                assembling.turn_counterclockwise('U');
                assembling.turn_counterclockwise('F');
            }
            if (!(check_yellow_cross())) {
                assembling.turn_front_clockwise();
                assembling.turn_right_clockwise();
                assembling.turn_up_clockwise();
                assembling.turn_counterclockwise('R');
                assembling.turn_counterclockwise('U');
                assembling.turn_counterclockwise('F');

                if (assembling.cube[1][2][0].lc_up == "yellow" && assembling.cube[0][2][1].lc_up == "yellow") {
                    assembling.turn_front_clockwise();
                    assembling.turn_right_clockwise();
                    assembling.turn_up_clockwise();
                    assembling.turn_counterclockwise('R');
                    assembling.turn_counterclockwise('U');
                    assembling.turn_right_clockwise();
                    assembling.turn_up_clockwise();
                    assembling.turn_counterclockwise('R');
                    assembling.turn_counterclockwise('U');
                    assembling.turn_counterclockwise('F');
                } else if (assembling.cube[1][2][0].lc_up == "yellow" && assembling.cube[2][2][1].lc_up == "yellow") {
                    assembling.turn_counterclockwise('U');
                    assembling.turn_front_clockwise();
                    assembling.turn_right_clockwise();
                    assembling.turn_up_clockwise();
                    assembling.turn_counterclockwise('R');
                    assembling.turn_counterclockwise('U');
                    assembling.turn_right_clockwise();
                    assembling.turn_up_clockwise();
                    assembling.turn_counterclockwise('R');
                    assembling.turn_counterclockwise('U');
                    assembling.turn_counterclockwise('F');
                } else if (assembling.cube[2][2][1].lc_up == "yellow" && assembling.cube[1][2][2].lc_up == "yellow") {
                    assembling.turn_up_clockwise();
                    assembling.turn_up_clockwise();
                    assembling.turn_front_clockwise();
                    assembling.turn_right_clockwise();
                    assembling.turn_up_clockwise();
                    assembling.turn_counterclockwise('R');
                    assembling.turn_counterclockwise('U');
                    assembling.turn_right_clockwise();
                    assembling.turn_up_clockwise();
                    assembling.turn_counterclockwise('R');
                    assembling.turn_counterclockwise('U');
                    assembling.turn_counterclockwise('F');
                } else if (assembling.cube[1][2][2].lc_up == "yellow" && assembling.cube[0][2][1].lc_up == "yellow") {
                    assembling.turn_up_clockwise();
                    assembling.turn_front_clockwise();
                    assembling.turn_right_clockwise();
                    assembling.turn_up_clockwise();
                    assembling.turn_counterclockwise('R');
                    assembling.turn_counterclockwise('U');
                    assembling.turn_right_clockwise();
                    assembling.turn_up_clockwise();
                    assembling.turn_counterclockwise('R');
                    assembling.turn_counterclockwise('U');
                    assembling.turn_counterclockwise('F');
                }
            }
        }
    }

}

void AssemblingRubiksCube::assembling_true_angle() {
    while (!((assembling.cube[2][2][2].lc_up == "yellow" || assembling.cube[2][2][2].lc_up == "blue" ||
              assembling.cube[2][2][2].lc_up == "red") &&
             (assembling.cube[2][2][2].lc_front == "yellow" ||
              assembling.cube[2][2][2].lc_front == "blue" || assembling.cube[2][2][2].lc_front == "red") &&
             (assembling.cube[2][2][2].lc_right == "yellow" ||
              assembling.cube[2][2][2].lc_right == "blue" || assembling.cube[2][2][2].lc_right == "red"))) {
        assembling.turn_up_clockwise();
    }

    while (!((assembling.cube[2][2][0].lc_up == "yellow" || assembling.cube[2][2][0].lc_up == "green" ||
              assembling.cube[2][2][0].lc_up == "red") &&
             (assembling.cube[2][2][0].lc_back == "yellow" ||
              assembling.cube[2][2][0].lc_back == "green" || assembling.cube[2][2][0].lc_back == "red") &&
             (assembling.cube[2][2][0].lc_right == "yellow" ||
              assembling.cube[2][2][0].lc_right == "green" || assembling.cube[2][2][0].lc_right == "red"))) {
        assembling.turn_right_clockwise();
        assembling.turn_up_clockwise();
        assembling.turn_counterclockwise('R');
        assembling.turn_counterclockwise('U');
        assembling.turn_right_clockwise();
        assembling.turn_up_clockwise();
        assembling.turn_counterclockwise('R');
        assembling.turn_counterclockwise('U');
        assembling.turn_right_clockwise();
        assembling.turn_up_clockwise();
        assembling.turn_counterclockwise('R');
        assembling.turn_counterclockwise('U');

        assembling.turn_counterclockwise('F');
        assembling.turn_counterclockwise('U');
        assembling.turn_front_clockwise();
        assembling.turn_up_clockwise();
        assembling.turn_counterclockwise('F');
        assembling.turn_counterclockwise('U');
        assembling.turn_front_clockwise();
        assembling.turn_up_clockwise();
        assembling.turn_counterclockwise('F');
        assembling.turn_counterclockwise('U');
        assembling.turn_front_clockwise();
        assembling.turn_up_clockwise();
    }

    while (!((assembling.cube[0][2][0].lc_up == "yellow" || assembling.cube[0][2][0].lc_up == "green" ||
              assembling.cube[0][2][0].lc_up == "orange") &&
             (assembling.cube[0][2][0].lc_back == "yellow" ||
              assembling.cube[0][2][0].lc_back == "green" || assembling.cube[0][2][0].lc_back == "orange") &&
             (assembling.cube[0][2][0].lc_left == "yellow" ||
              assembling.cube[0][2][0].lc_left == "green" || assembling.cube[0][2][0].lc_left == "orange"))) {
        assembling.turn_left_clockwise();
        assembling.turn_up_clockwise();
        assembling.turn_counterclockwise('L');
        assembling.turn_counterclockwise('U');
        assembling.turn_left_clockwise();
        assembling.turn_up_clockwise();
        assembling.turn_counterclockwise('L');
        assembling.turn_counterclockwise('U');
        assembling.turn_left_clockwise();
        assembling.turn_up_clockwise();
        assembling.turn_counterclockwise('L');
        assembling.turn_counterclockwise('U');

        assembling.turn_counterclockwise('B');
        assembling.turn_counterclockwise('U');
        assembling.turn_back_clockwise();
        assembling.turn_up_clockwise();
        assembling.turn_counterclockwise('B');
        assembling.turn_counterclockwise('U');
        assembling.turn_back_clockwise();
        assembling.turn_up_clockwise();
        assembling.turn_counterclockwise('B');
        assembling.turn_counterclockwise('U');
        assembling.turn_back_clockwise();
        assembling.turn_up_clockwise();
        while (!((assembling.cube[2][2][2].lc_up == "yellow" || assembling.cube[2][2][2].lc_up == "blue" ||
                  assembling.cube[2][2][2].lc_up == "red") &&
                 (assembling.cube[2][2][2].lc_front == "yellow" ||
                  assembling.cube[2][2][2].lc_front == "blue" || assembling.cube[2][2][2].lc_front == "red") &&
                 (assembling.cube[2][2][2].lc_right == "yellow" ||
                  assembling.cube[2][2][2].lc_right == "blue" || assembling.cube[2][2][2].lc_right == "red"))) {
            assembling.turn_up_clockwise();
        }
    }
    while (!((assembling.cube[2][2][2].lc_up == "yellow" || assembling.cube[2][2][2].lc_up == "blue" ||
              assembling.cube[2][2][2].lc_up == "red") &&
             (assembling.cube[2][2][2].lc_front == "yellow" ||
              assembling.cube[2][2][2].lc_front == "blue" || assembling.cube[2][2][2].lc_front == "red") &&
             (assembling.cube[2][2][2].lc_right == "yellow" ||
              assembling.cube[2][2][2].lc_right == "blue" || assembling.cube[2][2][2].lc_right == "red"))) {
        assembling.turn_up_clockwise();
    }


}

void AssemblingRubiksCube::turning_corners() {
    while (assembling.cube[0][2][2].lc_up != "yellow") {
        assembling.turn_left_clockwise();
        assembling.turn_down_clockwise();
        assembling.turn_counterclockwise('L');
        assembling.turn_counterclockwise('D');
    }
    assembling.turn_counterclockwise('U');
    while (assembling.cube[0][2][2].lc_up != "yellow") {
        assembling.turn_left_clockwise();
        assembling.turn_down_clockwise();
        assembling.turn_counterclockwise('L');
        assembling.turn_counterclockwise('D');
    }
    assembling.turn_counterclockwise('U');
    while (assembling.cube[0][2][2].lc_up != "yellow") {
        assembling.turn_left_clockwise();
        assembling.turn_down_clockwise();
        assembling.turn_counterclockwise('L');
        assembling.turn_counterclockwise('D');
    }
    assembling.turn_counterclockwise('U');
    while (assembling.cube[0][2][2].lc_up != "yellow") {
        assembling.turn_left_clockwise();
        assembling.turn_down_clockwise();
        assembling.turn_counterclockwise('L');
        assembling.turn_counterclockwise('D');
    }
}

void AssemblingRubiksCube::final() {
    while (!((assembling.cube[2][2][2].lc_up == "yellow" || assembling.cube[2][2][2].lc_up == "blue" ||
              assembling.cube[2][2][2].lc_up == "red") &&
             (assembling.cube[2][2][2].lc_front == "yellow" ||
              assembling.cube[2][2][2].lc_front == "blue" || assembling.cube[2][2][2].lc_front == "red") &&
             (assembling.cube[2][2][2].lc_right == "yellow" ||
              assembling.cube[2][2][2].lc_right == "blue" || assembling.cube[2][2][2].lc_right == "red"))) {
        assembling.turn_up_clockwise();
    }
    bool green = false;
    bool red = false;
    bool orange = false;
    while (true) {
        if (assembling.cube[0][2][1].lc_left == assembling.cube[0][2][0].lc_left) {
            orange = true;
            break;
        } else if (assembling.cube[2][2][0].lc_right == assembling.cube[2][2][1].lc_right) {
            red = true;
            break;
        } else if (assembling.cube[0][2][0].lc_back == assembling.cube[1][2][0].lc_back) {
            green = true;
            break;
        }
        assembling.turn_right_clockwise();
        assembling.turn_up_clockwise();
        assembling.turn_counterclockwise('R');
        assembling.turn_counterclockwise('U');

        assembling.turn_counterclockwise('L');
        assembling.turn_counterclockwise('U');
        assembling.turn_left_clockwise();
        assembling.turn_up_clockwise();

        assembling.turn_right_clockwise();
        assembling.turn_up_clockwise();
        assembling.turn_counterclockwise('R');
        assembling.turn_counterclockwise('U');
        assembling.turn_right_clockwise();
        assembling.turn_up_clockwise();
        assembling.turn_counterclockwise('R');
        assembling.turn_counterclockwise('U');
        assembling.turn_right_clockwise();
        assembling.turn_up_clockwise();
        assembling.turn_counterclockwise('R');
        assembling.turn_counterclockwise('U');
        assembling.turn_right_clockwise();
        assembling.turn_up_clockwise();
        assembling.turn_counterclockwise('R');
        assembling.turn_counterclockwise('U');
        assembling.turn_right_clockwise();
        assembling.turn_up_clockwise();
        assembling.turn_counterclockwise('R');
        assembling.turn_counterclockwise('U');

        assembling.turn_counterclockwise('L');
        assembling.turn_counterclockwise('U');
        assembling.turn_left_clockwise();
        assembling.turn_up_clockwise();
        assembling.turn_counterclockwise('L');
        assembling.turn_counterclockwise('U');
        assembling.turn_left_clockwise();
        assembling.turn_up_clockwise();
        assembling.turn_counterclockwise('L');
        assembling.turn_counterclockwise('U');
        assembling.turn_left_clockwise();
        assembling.turn_up_clockwise();
        assembling.turn_counterclockwise('L');
        assembling.turn_counterclockwise('U');
        assembling.turn_left_clockwise();
        assembling.turn_up_clockwise();
        assembling.turn_counterclockwise('L');
        assembling.turn_counterclockwise('U');
        assembling.turn_left_clockwise();
        assembling.turn_up_clockwise();

    }

    if (red) {
        while (!(assembling.cube[0][2][2].lc_front == assembling.cube[1][2][2].lc_front)) {
            assembling.turn_back_clockwise();
            assembling.turn_up_clockwise();
            assembling.turn_counterclockwise('B');
            assembling.turn_counterclockwise('U');

            assembling.turn_counterclockwise('F');
            assembling.turn_counterclockwise('U');
            assembling.turn_front_clockwise();
            assembling.turn_up_clockwise();


            assembling.turn_back_clockwise();
            assembling.turn_up_clockwise();
            assembling.turn_counterclockwise('B');
            assembling.turn_counterclockwise('U');
            assembling.turn_back_clockwise();
            assembling.turn_up_clockwise();
            assembling.turn_counterclockwise('B');
            assembling.turn_counterclockwise('U');
            assembling.turn_back_clockwise();
            assembling.turn_up_clockwise();
            assembling.turn_counterclockwise('B');
            assembling.turn_counterclockwise('U');
            assembling.turn_back_clockwise();
            assembling.turn_up_clockwise();
            assembling.turn_counterclockwise('B');
            assembling.turn_counterclockwise('U');
            assembling.turn_back_clockwise();
            assembling.turn_up_clockwise();
            assembling.turn_counterclockwise('B');
            assembling.turn_counterclockwise('U');


            assembling.turn_counterclockwise('F');
            assembling.turn_counterclockwise('U');
            assembling.turn_front_clockwise();
            assembling.turn_up_clockwise();
            assembling.turn_counterclockwise('F');
            assembling.turn_counterclockwise('U');
            assembling.turn_front_clockwise();
            assembling.turn_up_clockwise();
            assembling.turn_counterclockwise('F');
            assembling.turn_counterclockwise('U');
            assembling.turn_front_clockwise();
            assembling.turn_up_clockwise();
            assembling.turn_counterclockwise('F');
            assembling.turn_counterclockwise('U');
            assembling.turn_front_clockwise();
            assembling.turn_up_clockwise();
            assembling.turn_counterclockwise('F');
            assembling.turn_counterclockwise('U');
            assembling.turn_front_clockwise();
            assembling.turn_up_clockwise();

        }

    } else if (green) {
        while (!(assembling.cube[0][2][2].lc_front == assembling.cube[1][2][2].lc_front)) {
            assembling.turn_left_clockwise();
            assembling.turn_up_clockwise();
            assembling.turn_counterclockwise('L');
            assembling.turn_counterclockwise('U');

            assembling.turn_counterclockwise('R');
            assembling.turn_counterclockwise('U');
            assembling.turn_right_clockwise();
            assembling.turn_up_clockwise();

            assembling.turn_left_clockwise();
            assembling.turn_up_clockwise();
            assembling.turn_counterclockwise('L');
            assembling.turn_counterclockwise('U');
            assembling.turn_left_clockwise();
            assembling.turn_up_clockwise();
            assembling.turn_counterclockwise('L');
            assembling.turn_counterclockwise('U');
            assembling.turn_left_clockwise();
            assembling.turn_up_clockwise();
            assembling.turn_counterclockwise('L');
            assembling.turn_counterclockwise('U');
            assembling.turn_left_clockwise();
            assembling.turn_up_clockwise();
            assembling.turn_counterclockwise('L');
            assembling.turn_counterclockwise('U');
            assembling.turn_left_clockwise();
            assembling.turn_up_clockwise();
            assembling.turn_counterclockwise('L');
            assembling.turn_counterclockwise('U');


            assembling.turn_counterclockwise('R');
            assembling.turn_counterclockwise('U');
            assembling.turn_right_clockwise();
            assembling.turn_up_clockwise();
            assembling.turn_counterclockwise('R');
            assembling.turn_counterclockwise('U');
            assembling.turn_right_clockwise();
            assembling.turn_up_clockwise();
            assembling.turn_counterclockwise('R');
            assembling.turn_counterclockwise('U');
            assembling.turn_right_clockwise();
            assembling.turn_up_clockwise();
            assembling.turn_counterclockwise('R');
            assembling.turn_counterclockwise('U');
            assembling.turn_right_clockwise();
            assembling.turn_up_clockwise();
            assembling.turn_counterclockwise('R');
            assembling.turn_counterclockwise('U');
            assembling.turn_right_clockwise();
            assembling.turn_up_clockwise();
        }

    } else if (orange) {
        while (!(assembling.cube[0][2][2].lc_front == assembling.cube[1][2][2].lc_front)) {
            assembling.turn_front_clockwise();
            assembling.turn_up_clockwise();
            assembling.turn_counterclockwise('F');
            assembling.turn_counterclockwise('U');

            assembling.turn_counterclockwise('B');
            assembling.turn_counterclockwise('U');
            assembling.turn_back_clockwise();
            assembling.turn_up_clockwise();

            assembling.turn_front_clockwise();
            assembling.turn_up_clockwise();
            assembling.turn_counterclockwise('F');
            assembling.turn_counterclockwise('U');
            assembling.turn_front_clockwise();
            assembling.turn_up_clockwise();
            assembling.turn_counterclockwise('F');
            assembling.turn_counterclockwise('U');
            assembling.turn_front_clockwise();
            assembling.turn_up_clockwise();
            assembling.turn_counterclockwise('F');
            assembling.turn_counterclockwise('U');
            assembling.turn_front_clockwise();
            assembling.turn_up_clockwise();
            assembling.turn_counterclockwise('F');
            assembling.turn_counterclockwise('U');
            assembling.turn_front_clockwise();
            assembling.turn_up_clockwise();
            assembling.turn_counterclockwise('F');
            assembling.turn_counterclockwise('U');

            assembling.turn_counterclockwise('B');
            assembling.turn_counterclockwise('U');
            assembling.turn_back_clockwise();
            assembling.turn_up_clockwise();
            assembling.turn_counterclockwise('B');
            assembling.turn_counterclockwise('U');
            assembling.turn_back_clockwise();
            assembling.turn_up_clockwise();
            assembling.turn_counterclockwise('B');
            assembling.turn_counterclockwise('U');
            assembling.turn_back_clockwise();
            assembling.turn_up_clockwise();
            assembling.turn_counterclockwise('B');
            assembling.turn_counterclockwise('U');
            assembling.turn_back_clockwise();
            assembling.turn_up_clockwise();
            assembling.turn_counterclockwise('B');
            assembling.turn_counterclockwise('U');
            assembling.turn_back_clockwise();
            assembling.turn_up_clockwise();
        }

    }
}

CRubicsCube AssemblingRubiksCube::assemble() {
    assembling_cross();
    assembling_white_side();
    second_layer();
    assembling_yellow_cross();
    assembling_true_angle();
    turning_corners();
    final();
    return assembling;
}

bool AssemblingRubiksCube::invariance(CRubicsCube one) {
    AssemblingRubiksCube check(one);
    if (one.cube[1][1][2].lc_front != "blue") {
        return false;
    } else if (one.cube[2][1][1].lc_right != "red") {
        return false;
    } else if (one.cube[1][1][0].lc_back != "green") {
        return false;
    } else if (one.cube[0][1][1].lc_left != "orange") {
        return false;
    } else if (one.cube[1][2][1].lc_up != "yellow") {
        return false;
    } else if (one.cube[1][0][1].lc_down != "white") {
        return false;
    }
    one = check.assemble();
    int position = 0;
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            if (one.cube[x][y][2].lc_front == "blue") {
                position++;
            }
        }
    }
    for (int y = 0; y < 3; y++) {
        for (int z = 0; z < 3; z++) {
            if (one.cube[2][y][z].lc_right == "red") {
                position++;
            }
        }
    }
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            if (one.cube[x][y][0].lc_back == "green") {
                position++;
            }
        }
    }
    for (int y = 0; y < 3; y++) {
        for (int z = 0; z < 3; z++) {
            if (one.cube[0][y][z].lc_left == "orange") {
                position++;
            }
        }
    }
    for (int x = 0; x < 3; x++) {
        for (int z = 0; z < 3; z++) {
            if (one.cube[x][2][z].lc_up == "yellow") {
                position++;
            }
        }
    }
    for (int x = 0; x < 3; x++) {
        for (int z = 0; z < 3; z++) {
            if (one.cube[x][0][z].lc_down == "white") {
                position++;
            }
        }
    }
    if (position == 54) {
        return true;
    } else {
        return false;
    }
}






