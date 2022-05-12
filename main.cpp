#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class SmallCube {
public:
    string lc_up = "black";
    string lc_down = "black";
    string lc_left = "black";
    string lc_right = "black";
    string lc_front = "black";
    string lc_back = "black";

    int position_lc_up = -1;
    int position_lc_down = -1;
    int position_lc_left = -1;
    int position_lc_right = -1;
    int position_lc_front = -1;
    int position_lc_back = -1;

    void u_degree_rotation() {
        vector<string> arr = {lc_front, lc_left, lc_back, lc_right};
        lc_front = arr[3];
        lc_left = arr[0];
        lc_back = arr[1];
        lc_right = arr[2];

    }

    void d_degree_rotation() {
        vector<string> arr = {lc_front, lc_left, lc_back, lc_right};
        lc_front = arr[1];
        lc_left = arr[2];
        lc_back = arr[3];
        lc_right = arr[0];
    }

    void r_degree_rotation() {
        vector<string> arr = {lc_front, lc_back, lc_up, lc_down};
        lc_front = arr[3];
        lc_down = arr[1];
        lc_back = arr[2];
        lc_up = arr[0];

    }

    void l_degree_rotation() {
        vector<string> arr = {lc_front, lc_back, lc_up, lc_down};
        lc_front = arr[2];
        lc_down = arr[0];
        lc_back = arr[3];
        lc_up = arr[1];
    }

    void f_degree_rotation() {
        vector<string> arr = {lc_left, lc_right, lc_up, lc_down};
        lc_left = arr[3];
        lc_right = arr[2];
        lc_up = arr[0];
        lc_down = arr[1];
    }

    void b_degree_rotation() {
        vector<string> arr = {lc_left, lc_right, lc_up, lc_down};
        lc_left = arr[2];
        lc_right = arr[3];
        lc_up = arr[1];
        lc_down = arr[0];
    }
};

class RubicsCube {
private:
    vector<vector<vector<SmallCube>>> cube;
public:
    RubicsCube() {
        cube = vector<vector<vector<SmallCube>>>(3, vector<vector<SmallCube>>(3, vector<SmallCube>(3, SmallCube())));
        default_colors();
    }

    bool check_nn_cross() {
        vector<int> position;
        int check_non_cross = 0;
        bool check_non_cross1 = false;

        //Проверка на уже собранный крест
        positionCubes('U');
        if (cube[1][2][0].lc_up == "white") {
            check_non_cross++;
            position.push_back(cube[1][2][0].position_lc_up);
        }
        if (cube[2][2][1].lc_up == "white") {
            check_non_cross++;
            position.push_back(cube[2][2][1].position_lc_up);
        }
        if (cube[1][2][2].lc_up == "white") {
            check_non_cross++;
            position.push_back(cube[1][2][2].position_lc_up);
        }
        if (cube[0][2][1].lc_up == "white") {
            check_non_cross++;
            position.push_back(cube[0][2][1].position_lc_up);
        }

        if (check_non_cross == 4) {
            check_non_cross1 = true;
            return true;
        } else {
            return false;
        }
    }

    bool check_cross() {
        vector<int> position;
        int check_non_cross = 0;
        bool check_non_cross1 = false;

        //Проверка на уже собранный крест
        positionCubes('U');
        if (cube[1][0][0].lc_down == "white") {
            check_non_cross++;
            position.push_back(cube[1][2][0].position_lc_up);
        }
        if (cube[2][0][1].lc_down == "white") {
            check_non_cross++;
            position.push_back(cube[2][2][1].position_lc_up);
        }
        if (cube[1][0][2].lc_down == "white") {
            check_non_cross++;
            position.push_back(cube[1][2][2].position_lc_up);
        }
        if (cube[0][0][1].lc_down == "white") {
            check_non_cross++;
            position.push_back(cube[0][2][1].position_lc_up);
        }

        if (check_non_cross == 4) {
            check_non_cross1 = true;
            return true;
        } else {
            return false;
        }
    }

    void default_colors() {
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

    void positionCubes(char side) {

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

    void printCube() {
        int score = 0;
        //Вывод задней грани
        cout << "Back: " << endl;
        for (int y = 2; y >= 0; y--) {
            for (int x = 2; x >= 0; x--) {
                if (score == 3) {
                    cout << endl;
                    score = 0;
                }
                cout << cube[x][y][0].lc_back << " ";
                score++;
            }
        }
        cout << endl << "====================" << endl;
        //Вывод передней грани
        cout << "Front: ";
        for (int y = 2; y >= 0; y--) {
            for (int x = 0; x < 3; x++) {
                if (score == 3) {
                    cout << endl;
                    score = 0;
                }
                cout << cube[x][y][2].lc_front << " ";
                score++;
            }
        }
        cout << endl << "====================" << endl;
        //Вывод левой грани
        cout << "Left: ";
        for (int y = 2; y >= 0; y--) {
            for (int z = 0; z < 3; z++) {
                if (score == 3) {
                    cout << endl;
                    score = 0;
                }
                cout << cube[0][y][z].lc_left << " ";
                score++;
            }
        }
        cout << endl << "====================" << endl;
        //Вывод правой грани
        cout << "Right: ";
        for (int y = 2; y >= 0; y--) {
            for (int z = 2; z >= 0; z--) {
                if (score == 3) {
                    cout << endl;
                    score = 0;
                }
                cout << cube[2][y][z].lc_right << " ";
                score++;
            }
        }
        cout << endl << "====================" << endl;
        //Вывод верхней грани
        cout << "Up: ";
        for (int z = 0; z < 3; z++) {
            for (int x = 0; x < 3; x++) {
                if (score == 3) {
                    cout << endl;
                    score = 0;
                }
                cout << cube[x][2][z].lc_up << " ";
                score++;
            }
        }
        cout << endl << "====================" << endl;
        //Вывод нижней грани
        cout << "Down: ";
        for (int z = 2; z >= 0; z--) {
            for (int x = 0; x < 3; x++) {
                if (score == 3) {
                    cout << endl;
                    score = 0;
                }
                cout << cube[x][0][z].lc_down << " ";
                score++;
            }
        }
        cout << endl << "====================" << endl;
    }

    void turn_up_clockwise() {
        vector<vector<vector<SmallCube>>> backup_cube = cube;
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

    void turn_down_clockwise() {
        vector<vector<vector<SmallCube>>> backup_cube = cube;
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

    void turn_right_clockwise() {
        vector<vector<vector<SmallCube>>> backup_cube = cube;
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

    void turn_left_clockwise() {
        vector<vector<vector<SmallCube>>> backup_cube = cube;
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

    void turn_front_clockwise() {
        vector<vector<vector<SmallCube>>> backup_cube = cube;
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

    void turn_back_clockwise() {
        vector<vector<vector<SmallCube>>> backup_cube = cube;
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

    void turn_counterclockwise(char side) {
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

    void assembling_cross() {

        //Первый этап - сборка неправильного белого креста

        //Начало сборки

        if (!check_nn_cross()) {
            //Если есть нужные нам кубики на передней грани (синий)
            if (cube[0][1][2].lc_front == "white") {
                if (cube[0][2][1].lc_up == "white") {
                    while (cube[0][2][1].lc_up == "white") {
                        turn_up_clockwise();
                    }
                    turn_counterclockwise('L');
                } else {
                    turn_counterclockwise('L');
                }
            }
            if (cube[2][1][2].lc_front == "white") {
                if (cube[2][2][1].lc_up == "white") {
                    while (cube[2][2][1].lc_up == "white") {
                        turn_up_clockwise();
                    }
                    turn_right_clockwise();
                } else {
                    turn_right_clockwise();
                }
            }
            if (cube[1][2][2].lc_front == "white") {
                turn_front_clockwise();
                if (cube[2][2][1].lc_up == "white") {
                    while (cube[2][2][1].lc_up == "white") {
                        turn_up_clockwise();
                    }
                    turn_right_clockwise();
                    if (cube[1][2][2].lc_up == "white") {
                        if (!check_nn_cross()) {
                            while (cube[1][2][2].lc_up == "white") {
                                turn_up_clockwise();
                            }
                            turn_counterclockwise('F');
                        }


                    } else {
                        turn_counterclockwise('F');
                    }
                } else {
                    turn_right_clockwise();
                    if (cube[1][2][2].lc_up == "white") {
                        if (!check_nn_cross()) {
                            while (cube[1][2][2].lc_up == "white") {
                                turn_up_clockwise();
                            }
                            turn_counterclockwise('F');
                        }


                    } else {
                        turn_counterclockwise('F');
                    }
                }
            }
            if (cube[1][0][2].lc_front == "white") {
                if (cube[1][2][2].lc_up == "white") {
                    while (cube[1][2][2].lc_up == "white") {
                        turn_up_clockwise();
                    }
                    turn_counterclockwise('F');
                } else {
                    turn_counterclockwise('F');
                }

                if (cube[2][2][1].lc_up == "white") {
                    while (cube[2][2][1].lc_up == "white") {
                        turn_up_clockwise();
                    }
                    turn_right_clockwise();
                    if (cube[1][2][2].lc_up == "white") {
                        if (!check_nn_cross()) {
                            while (cube[1][2][2].lc_up == "white") {
                                turn_up_clockwise();
                            }
                            turn_front_clockwise();
                        }

                    } else {
                        turn_front_clockwise();
                    }
                } else {
                    turn_right_clockwise();
                    if (cube[1][2][2].lc_up == "white") {
                        if (!check_nn_cross()) {
                            while (cube[1][2][2].lc_up == "white") {
                                turn_up_clockwise();
                            }
                            turn_front_clockwise();
                        }

                    } else {
                        turn_front_clockwise();
                    }
                }
            }

            //Если нужные нам кубики есть на левой грани (оранжевая)
            if (cube[0][1][0].lc_left == "white") {
                if (cube[1][2][0].lc_up == "white") {
                    while (cube[1][2][0].lc_up == "white") {
                        turn_up_clockwise();
                    }
                    turn_counterclockwise('B');
                } else {
                    turn_counterclockwise('B');
                }
            }

            if (cube[0][1][2].lc_left == "white") {
                if (cube[1][2][2].lc_up == "white") {
                    while (cube[1][2][2].lc_up == "white") {
                        turn_up_clockwise();
                    }
                    turn_front_clockwise();
                } else {
                    turn_front_clockwise();
                }
            }
            if (cube[0][2][1].lc_left == "white") {
                turn_left_clockwise();
                if (cube[1][2][2].lc_up == "white") {
                    while (cube[1][2][2].lc_up == "white") {
                        turn_up_clockwise();
                    }
                    turn_front_clockwise();
                    if (cube[0][2][1].lc_up == "white") {
                        if (!check_nn_cross()) {
                            while (cube[0][2][1].lc_up == "white") {
                                turn_up_clockwise();
                            }
                            turn_counterclockwise('L');
                        }


                    } else {
                        turn_counterclockwise('L');
                    }
                } else {
                    turn_front_clockwise();
                    if (cube[0][2][1].lc_up == "white") {
                        if (!check_nn_cross()) {
                            while (cube[0][2][1].lc_up == "white") {
                                turn_up_clockwise();
                            }
                            turn_counterclockwise('L');
                        }


                    } else {
                        turn_counterclockwise('L');
                    }
                }
            }
            if (cube[0][0][1].lc_left == "white") {
                if (cube[0][2][1].lc_up == "white") {
                    while (cube[0][2][1].lc_up == "white") {
                        turn_up_clockwise();
                    }
                    turn_counterclockwise('L');
                } else {
                    turn_counterclockwise('L');
                }

                if (cube[1][2][2].lc_up == "white") {
                    while (cube[1][2][2].lc_up == "white") {
                        turn_up_clockwise();
                    }
                    turn_front_clockwise();
                    if (cube[0][2][1].lc_up == "white") {
                        if (!check_nn_cross()) {
                            while (cube[0][2][1].lc_up == "white") {
                                turn_up_clockwise();
                            }
                            turn_left_clockwise();
                        }

                    } else {
                        turn_left_clockwise();
                    }
                } else {
                    turn_front_clockwise();
                    if (cube[0][2][1].lc_up == "white") {
                        if (!check_nn_cross()) {
                            while (cube[0][2][1].lc_up == "white") {
                                turn_up_clockwise();
                            }
                            turn_left_clockwise();
                        }

                    } else {
                        turn_left_clockwise();
                    }
                }
            }
            //Если нужные нам кубики есть на правой грани (красная)
            if (cube[2][1][2].lc_right == "white") {
                if (cube[1][2][2].lc_up == "white") {
                    while (cube[1][2][2].lc_up == "white") {
                        turn_up_clockwise();
                    }
                    turn_counterclockwise('F');
                } else {
                    turn_counterclockwise('F');
                }
            }

            if (cube[2][1][0].lc_right == "white") {
                if (cube[1][2][0].lc_up == "white") {
                    while (cube[1][2][0].lc_up == "white") {
                        turn_up_clockwise();
                    }
                    turn_back_clockwise();
                } else {
                    turn_back_clockwise();
                }
            }
            if (cube[2][2][1].lc_right == "white") {
                turn_right_clockwise();
                if (cube[1][2][0].lc_up == "white") {
                    while (cube[1][2][0].lc_up == "white") {
                        turn_up_clockwise();
                    }
                    turn_back_clockwise();
                    if (cube[2][2][1].lc_up == "white") {
                        if (!check_nn_cross()) {
                            while (cube[2][2][1].lc_up == "white") {
                                turn_up_clockwise();
                            }
                            turn_counterclockwise('R');
                        }


                    } else {
                        turn_counterclockwise('R');
                    }
                } else {
                    turn_back_clockwise();
                    if (cube[2][2][1].lc_up == "white") {
                        if (!check_nn_cross()) {
                            while (cube[2][2][1].lc_up == "white") {
                                turn_up_clockwise();
                            }
                            turn_counterclockwise('R');
                        }


                    } else {
                        turn_counterclockwise('R');
                    }
                }
            }
            if (cube[2][0][1].lc_right == "white") {
                if (cube[2][2][1].lc_up == "white") {
                    while (cube[2][2][1].lc_up == "white") {
                        turn_up_clockwise();
                    }
                    turn_counterclockwise('R');
                } else {
                    turn_counterclockwise('R');
                }

                if (cube[1][2][0].lc_up == "white") {
                    while (cube[1][2][0].lc_up == "white") {
                        turn_up_clockwise();
                    }
                    turn_back_clockwise();
                    if (cube[2][2][1].lc_up == "white") {
                        if (!check_nn_cross()) {
                            while (cube[2][2][1].lc_up == "white") {
                                turn_up_clockwise();
                            }
                            turn_right_clockwise();
                        }

                    } else {
                        turn_right_clockwise();
                    }
                } else {
                    turn_back_clockwise();
                    if (cube[2][2][1].lc_up == "white") {
                        if (!check_nn_cross()) {
                            while (cube[2][2][1].lc_up == "white") {
                                turn_up_clockwise();
                            }
                            turn_right_clockwise();
                        }

                    } else {
                        turn_right_clockwise();
                    }
                }
            }

            //Если есть нужные нам кубики на задней грани (зеленый)
            if (cube[0][1][0].lc_back == "white") {
                if (cube[0][2][1].lc_up == "white") {
                    while (cube[0][2][1].lc_up == "white") {
                        turn_up_clockwise();
                    }
                    turn_left_clockwise();
                } else {
                    turn_left_clockwise();
                }
            }
            if (cube[2][1][0].lc_back == "white") {
                if (cube[2][2][1].lc_up == "white") {
                    while (cube[2][2][1].lc_up == "white") {
                        turn_up_clockwise();
                    }
                    turn_counterclockwise('R');
                } else {
                    turn_counterclockwise('R');
                }
            }
            if (cube[1][2][0].lc_back == "white") {
                turn_back_clockwise();
                if (cube[0][2][1].lc_up == "white") {
                    while (cube[0][2][1].lc_up == "white") {
                        turn_up_clockwise();
                    }
                    turn_left_clockwise();
                    if (cube[1][2][0].lc_up == "white") {
                        if (!check_nn_cross()) {
                            while (cube[1][2][0].lc_up == "white") {
                                turn_up_clockwise();
                            }
                            turn_counterclockwise('B');
                        }


                    } else {
                        turn_counterclockwise('B');
                    }
                } else {
                    turn_left_clockwise();
                    if (cube[1][2][0].lc_up == "white") {
                        if (!check_nn_cross()) {
                            while (cube[1][2][0].lc_up == "white") {
                                turn_up_clockwise();
                            }
                            turn_counterclockwise('B');
                        }


                    } else {
                        turn_counterclockwise('B');
                    }
                }
            }
            if (cube[1][0][0].lc_back == "white") {
                if (cube[1][2][0].lc_up == "white") {
                    while (cube[1][2][0].lc_up == "white") {
                        turn_up_clockwise();
                    }
                    turn_counterclockwise('B');
                } else {
                    turn_counterclockwise('B');
                }

                if (cube[0][2][1].lc_up == "white") {
                    while (cube[0][2][1].lc_up == "white") {
                        turn_up_clockwise();
                    }
                    turn_left_clockwise();
                    if (cube[1][2][0].lc_up == "white") {
                        if (!check_nn_cross()) {
                            while (cube[1][2][0].lc_up == "white") {
                                turn_up_clockwise();
                            }
                            turn_back_clockwise();
                        }

                    } else {
                        turn_back_clockwise();
                    }
                } else {
                    turn_left_clockwise();
                    if (cube[1][2][0].lc_up == "white") {
                        if (!check_nn_cross()) {
                            while (cube[1][2][0].lc_up == "white") {
                                turn_up_clockwise();
                            }
                            turn_back_clockwise();
                        }

                    } else {
                        turn_back_clockwise();
                    }
                }
            }

            //Если есть нужные нам кубики на нижней грани (белый)
            if (cube[0][0][1].lc_down == "white") {
                if (cube[0][2][1].lc_up == "white") {
                    while (cube[0][2][1].lc_up == "white") {
                        turn_up_clockwise();
                    }
                    turn_counterclockwise('L');
                    turn_counterclockwise('L');
                } else {
                    turn_counterclockwise('L');
                    turn_counterclockwise('L');
                }
            }
            if (cube[2][0][1].lc_down == "white") {
                if (cube[2][2][1].lc_up == "white") {
                    while (cube[2][2][1].lc_up == "white") {
                        turn_up_clockwise();
                    }
                    turn_right_clockwise();
                    turn_right_clockwise();
                } else {
                    turn_right_clockwise();
                    turn_right_clockwise();
                }
            }
            if (cube[1][0][2].lc_down == "white") {
                turn_down_clockwise();
                if (cube[2][2][1].lc_up == "white") {
                    while (cube[2][2][1].lc_up == "white") {
                        turn_up_clockwise();
                    }
                    turn_right_clockwise();
                    turn_right_clockwise();
                    turn_counterclockwise('D');
                } else {
                    turn_right_clockwise();
                    turn_right_clockwise();
                    turn_counterclockwise('D');
                }
            }
            if (cube[1][0][0].lc_down == "white") {
                turn_counterclockwise('D');
                if (cube[2][2][1].lc_up == "white") {
                    while (cube[2][2][1].lc_up == "white") {
                        turn_up_clockwise();
                    }
                    turn_right_clockwise();
                    turn_right_clockwise();
                    turn_down_clockwise();
                } else {
                    turn_right_clockwise();
                    turn_right_clockwise();
                    turn_down_clockwise();
                }
            }
        }

        //Собираем правильный крест
        if (check_nn_cross()) {
            //Сначала берем кубик на позиции 2
            while ((cube[1][1][0].lc_back != cube[1][2][0].lc_back) || cube[1][2][0].lc_up != "white") {
                turn_up_clockwise();
            }
            turn_back_clockwise();
            turn_back_clockwise();

            //Берем кубик на позиции 4
            while ((cube[2][1][1].lc_right != cube[2][2][1].lc_right) || cube[2][2][1].lc_up != "white") {
                turn_up_clockwise();
            }
            turn_right_clockwise();
            turn_right_clockwise();

            //Берём кубик на позиции 6
            while ((cube[1][1][2].lc_front != cube[1][2][2].lc_front) || cube[1][2][2].lc_up != "white") {
                turn_up_clockwise();
            }
            turn_front_clockwise();
            turn_front_clockwise();

            //Берём кубик на позиции 8
            while ((cube[0][1][1].lc_left != cube[0][2][1].lc_left) || cube[0][2][1].lc_up != "white") {
                turn_up_clockwise();
            }
            turn_left_clockwise();
            turn_left_clockwise();

        }

    }

    void pif_paf_up(char side) {
        //Подготовка 0 2 2
        if (side == '7') {
            while (cube[0][2][2].lc_up != "white") {
                turn_front_clockwise();
                turn_up_clockwise();
                turn_counterclockwise('F');
                turn_counterclockwise('U');
            }
        } else if (side == '5') {
            //Подготовка кубика 2 2 2
            while (cube[2][2][2].lc_up != "white") {
                turn_right_clockwise();
                turn_up_clockwise();
                turn_counterclockwise('R');
                turn_counterclockwise('U');
            }
        } else if (side == '3') {
            //Подготовка кубика 2 2 0
            while (cube[2][2][0].lc_up != "white") {
                turn_back_clockwise();
                turn_up_clockwise();
                turn_counterclockwise('B');
                turn_counterclockwise('U');
            }
        } else if (side == '1') {
            //Подготовка кубика 0 2 0
            while (cube[0][2][0].lc_up != "white") {
                turn_left_clockwise();
                turn_up_clockwise();
                turn_counterclockwise('L');
                turn_counterclockwise('U');
            }
        }
    }

    bool check_neighboring_side(char side) {
        if (side == '7') {
            if (((cube[0][2][2].lc_left == cube[0][1][1].lc_left) &&
                 (cube[0][2][2].lc_front == cube[1][1][2].lc_front)) ||
                ((cube[0][2][2].lc_left == cube[1][1][2].lc_front) &&
                 (cube[0][2][2].lc_front == cube[0][1][1].lc_left))) {
                return true;
            }
        } else if (side == '5') {
            if (((cube[2][2][2].lc_front == cube[1][1][2].lc_front) &&
                 (cube[2][2][2].lc_right == cube[2][1][1].lc_right)) ||
                ((cube[2][2][2].lc_front == cube[2][1][1].lc_right) &&
                 (cube[2][2][2].lc_right == cube[1][1][2].lc_front))) {
                return true;
            }
        } else if (side == '3') {
            if (((cube[2][2][0].lc_right == cube[2][1][1].lc_right) &&
                 (cube[2][2][0].lc_back == cube[1][1][0].lc_back)) ||
                ((cube[2][2][0].lc_right == cube[1][1][0].lc_back) &&
                 (cube[2][2][0].lc_back == cube[2][1][1].lc_right))) {
                return true;
            }
        } else if (side == '1') {
            if (((cube[0][2][0].lc_back == cube[1][1][0].lc_back) &&
                 (cube[0][2][0].lc_left == cube[0][1][1].lc_left)) ||
                ((cube[0][2][0].lc_back == cube[0][1][1].lc_left) &&
                 (cube[0][2][0].lc_left == cube[1][1][0].lc_back))) {
                return true;
            }
        }
    }

    bool check_up_white() {
        int score = 0;
        if (cube[0][2][2].lc_up == "white" || cube[0][2][2].lc_left == "white" || cube[0][2][2].lc_front == "white") {
            score++;
        }
        if (cube[2][2][2].lc_up == "white" || cube[2][2][2].lc_right == "white" || cube[2][2][2].lc_front == "white") {
            score++;
        }
        if (cube[2][2][0].lc_up == "white" || cube[2][2][0].lc_back == "white" || cube[2][2][0].lc_right == "white") {
            score++;
        }
        if (cube[0][2][0].lc_up == "white" || cube[0][2][0].lc_back == "white" || cube[0][2][0].lc_left == "white") {
            score++;
        }
        if (score == 4) {
            return true;
        } else {
            return false;
        }

    }

    void assembling_white_side() {
        //Убираем кубик с белой стороной из 0 0 2
        if (!check_up_white()) {
            while (cube[0][2][2].lc_up == "white" || cube[0][2][2].lc_left == "white" ||
                   cube[0][2][2].lc_front == "white") {
                turn_up_clockwise();
            }
            turn_front_clockwise();
            while (cube[0][2][2].lc_up == "white" || cube[0][2][2].lc_left == "white" ||
                   cube[0][2][2].lc_front == "white") {
                turn_up_clockwise();
            }
            turn_counterclockwise('F');

            if (!check_up_white()) {
                //Убираем кубик в 2 0 2
                while (cube[2][2][2].lc_up == "white" || cube[2][2][2].lc_right == "white" ||
                       cube[2][2][2].lc_front == "white") {
                    turn_up_clockwise();
                }
                turn_right_clockwise();
                while (cube[2][2][2].lc_up == "white" || cube[2][2][2].lc_right == "white" ||
                       cube[2][2][2].lc_front == "white") {
                    turn_up_clockwise();
                }
                turn_counterclockwise('R');
                if (!check_up_white()) {
                    //Убираем кубик 2 0 0
                    while (cube[2][2][0].lc_up == "white" || cube[2][2][0].lc_back == "white" ||
                           cube[2][2][0].lc_right == "white") {
                        turn_up_clockwise();
                    }
                    turn_back_clockwise();
                    while (cube[2][2][0].lc_up == "white" || cube[2][2][0].lc_back == "white" ||
                           cube[2][2][0].lc_right == "white") {
                        turn_up_clockwise();
                    }
                    turn_counterclockwise('B');
                    if (!check_up_white()) {
                        //Убираем кубик 0 0 0
                        while (cube[0][2][0].lc_up == "white" || cube[0][2][0].lc_back == "white" ||
                               cube[0][2][0].lc_left == "white") {
                            turn_up_clockwise();
                        }
                        turn_left_clockwise();
                        while (cube[0][2][0].lc_up == "white" || cube[0][2][0].lc_back == "white" ||
                               cube[0][2][0].lc_left == "white") {
                            turn_up_clockwise();
                        }
                        turn_counterclockwise('L');
                    }

                }

            }


        }
        //Подготовка угловых кубиков к поворотам

        //Выставляем кубик 0 0 2
        if (cube[0][2][2].lc_up == "white" || cube[0][2][2].lc_left == "white" || cube[0][2][2].lc_front == "white") {
            pif_paf_up('7');
        } else {
            while (cube[0][2][2].lc_up != "white" && cube[0][2][2].lc_left != "white" &&
                   cube[0][2][2].lc_front != "white") {
                turn_up_clockwise();
            }
            pif_paf_up('7');
        }

        while (!check_neighboring_side('7')) {
            turn_up_clockwise();
            if (cube[0][2][2].lc_up == "white" || cube[0][2][2].lc_left == "white" ||
                cube[0][2][2].lc_front == "white") {
                pif_paf_up('7');
            } else {
                while (cube[0][2][2].lc_up != "white" && cube[0][2][2].lc_left != "white" &&
                       cube[0][2][2].lc_front != "white") {
                    turn_up_clockwise();
                }
                pif_paf_up('7');
            }
        }
        while (cube[0][0][2].lc_down != "white") {
            turn_front_clockwise();
            turn_up_clockwise();
            turn_counterclockwise('F');
            turn_counterclockwise('U');
        }
        //Выставляем кубик 2 0 2
        if (cube[2][2][2].lc_up == "white" || cube[2][2][2].lc_right == "white" || cube[2][2][2].lc_front == "white") {
            pif_paf_up('5');
        } else {
            while (cube[2][2][2].lc_up != "white" && cube[2][2][2].lc_right != "white" &&
                   cube[2][2][2].lc_front != "white") {
                turn_up_clockwise();
            }
            pif_paf_up('5');
        }
        while (!check_neighboring_side('5')) {
            turn_up_clockwise();
            if (cube[2][2][2].lc_up == "white" || cube[2][2][2].lc_right == "white" ||
                cube[2][2][2].lc_front == "white") {
                pif_paf_up('5');
            } else {
                while (cube[2][2][2].lc_up != "white" && cube[2][2][2].lc_right != "white" &&
                       cube[2][2][2].lc_front != "white") {
                    turn_up_clockwise();
                }
                pif_paf_up('5');
            }
        }
        while (cube[2][0][2].lc_down != "white") {
            turn_right_clockwise();
            turn_up_clockwise();
            turn_counterclockwise('R');
            turn_counterclockwise('U');
        }

        //Выставляем кубик 2 0 0
        if (cube[2][2][0].lc_up == "white" || cube[2][2][0].lc_back == "white" || cube[2][2][0].lc_right == "white") {
            pif_paf_up('3');
        } else {
            while (cube[2][2][0].lc_up != "white" && cube[2][2][0].lc_right != "white" &&
                   cube[2][2][0].lc_back != "white") {
                turn_up_clockwise();
            }
            pif_paf_up('3');
        }
        while (!check_neighboring_side('3')) {
            turn_up_clockwise();
            if (cube[2][2][0].lc_up == "white" || cube[2][2][0].lc_back == "white" ||
                cube[2][2][0].lc_right == "white") {
                pif_paf_up('3');
            } else {
                while (cube[2][2][0].lc_up != "white" && cube[2][2][0].lc_right != "white" &&
                       cube[2][2][0].lc_back != "white") {
                    turn_up_clockwise();
                }
                pif_paf_up('3');
            }
        }
        while (cube[2][0][0].lc_down != "white") {
            turn_back_clockwise();
            turn_up_clockwise();
            turn_counterclockwise('B');
            turn_counterclockwise('U');
        }
        //Выставляем кубик 0 0 0
        if (cube[0][2][0].lc_up == "white" || cube[0][2][0].lc_back == "white" || cube[0][2][0].lc_left == "white") {
            pif_paf_up('1');
        } else {
            while (cube[0][2][0].lc_up != "white" && cube[0][2][0].lc_left != "white" &&
                   cube[0][2][0].lc_back != "white") {
                turn_up_clockwise();
            }
            pif_paf_up('1');
        }
        while (!check_neighboring_side('1')) {
            turn_up_clockwise();
            if (cube[0][2][0].lc_up == "white" || cube[0][2][0].lc_back == "white" ||
                cube[0][2][0].lc_left == "white") {
                pif_paf_up('1');
            } else {
                while (cube[0][2][0].lc_up != "white" && cube[0][2][0].lc_left != "white" &&
                       cube[0][2][0].lc_back != "white") {
                    turn_up_clockwise();
                }
                pif_paf_up('1');
            }
        }
        while (cube[0][0][0].lc_down != "white") {
            turn_left_clockwise();
            turn_up_clockwise();
            turn_counterclockwise('L');
            turn_counterclockwise('U');
        }

    }

    void side_selection(char side) {
        if (side == 'B') {
            //Находим для синего центра подходящую грань
            int score_blue = 0;
            for (int i = 0; i < 4; i++) {
                if (cube[1][1][2].lc_front == cube[1][2][2].lc_front) {
                    score_blue++;
                }
                turn_up_clockwise();
            }
            //Мы нашли подходящую грань
            if (score_blue == 1) {
                for (int i = 0; i < 4; i++) {
                    if (cube[1][1][2].lc_front == cube[1][2][2].lc_front) {
                        break;
                    }
                    turn_up_clockwise();
                }
                if (cube[1][2][2].lc_up == "orange") {
                    turn_counterclockwise('U');
                    turn_counterclockwise('L');
                    turn_counterclockwise('U');
                    turn_left_clockwise();
                    turn_up_clockwise();
                    turn_front_clockwise();
                    turn_up_clockwise();
                    turn_counterclockwise('F');
                    turn_counterclockwise('U');

                } else if (cube[1][2][2].lc_up == "red") {
                    turn_up_clockwise();
                    turn_right_clockwise();
                    turn_up_clockwise();
                    turn_counterclockwise('R');
                    turn_counterclockwise('U');
                    turn_counterclockwise('F');
                    turn_counterclockwise('U');
                    turn_front_clockwise();
                    turn_up_clockwise();
                }
            } else if (score_blue == 2) {
                for (int i = 0; i < 4; i++) {
                    if (cube[1][1][2].lc_front == cube[1][2][2].lc_front) {
                        break;
                    }
                    turn_up_clockwise();
                }
                if (cube[1][2][2].lc_up == "orange") {
                    turn_counterclockwise('U');
                    turn_counterclockwise('L');
                    turn_counterclockwise('U');
                    turn_left_clockwise();
                    turn_up_clockwise();
                    turn_front_clockwise();
                    turn_up_clockwise();
                    turn_counterclockwise('F');
                    turn_counterclockwise('U');

                } else if (cube[1][2][2].lc_up == "red") {
                    turn_up_clockwise();
                    turn_right_clockwise();
                    turn_up_clockwise();
                    turn_counterclockwise('R');
                    turn_counterclockwise('U');
                    turn_counterclockwise('F');
                    turn_counterclockwise('U');
                    turn_front_clockwise();
                    turn_up_clockwise();
                }
                for (int i = 0; i < 4; i++) {
                    if (cube[1][1][2].lc_front == cube[1][2][2].lc_front) {
                        break;
                    }
                    turn_up_clockwise();
                }
                if (cube[1][2][2].lc_up == "orange") {
                    turn_counterclockwise('U');
                    turn_counterclockwise('L');
                    turn_counterclockwise('U');
                    turn_left_clockwise();
                    turn_up_clockwise();
                    turn_front_clockwise();
                    turn_up_clockwise();
                    turn_counterclockwise('F');
                    turn_counterclockwise('U');

                } else if (cube[1][2][2].lc_up == "red") {
                    turn_up_clockwise();
                    turn_right_clockwise();
                    turn_up_clockwise();
                    turn_counterclockwise('R');
                    turn_counterclockwise('U');
                    turn_counterclockwise('F');
                    turn_counterclockwise('U');
                    turn_front_clockwise();
                    turn_up_clockwise();
                }

            }
        } else if (side == 'O') {
            //Находим для оранжевого центра подходящую грань
            int score_orange = 0;
            for (int i = 0; i < 4; i++) {
                if (cube[0][1][1].lc_left == cube[0][2][1].lc_left) {
                    score_orange++;
                }
                turn_up_clockwise();
            }
            //Мы нашли подходящую грань
            if (score_orange == 1) {
                for (int i = 0; i < 4; i++) {
                    if (cube[0][1][1].lc_left == cube[0][2][1].lc_left) {
                        break;
                    }
                    turn_up_clockwise();
                }
                if (cube[0][2][1].lc_up == "green") {
                    turn_counterclockwise('U');
                    turn_counterclockwise('B');
                    turn_counterclockwise('U');
                    turn_back_clockwise();
                    turn_up_clockwise();
                    turn_left_clockwise();
                    turn_up_clockwise();
                    turn_counterclockwise('L');
                    turn_counterclockwise('U');


                } else if (cube[0][2][1].lc_up == "blue") {
                    turn_up_clockwise();
                    turn_front_clockwise();
                    turn_up_clockwise();
                    turn_counterclockwise('F');
                    turn_counterclockwise('U');
                    turn_counterclockwise('L');
                    turn_counterclockwise('U');
                    turn_left_clockwise();
                    turn_up_clockwise();
                }
            } else if (score_orange == 2) {
                for (int i = 0; i < 4; i++) {
                    if (cube[0][1][1].lc_left == cube[0][2][1].lc_left) {
                        break;
                    }
                    turn_up_clockwise();
                }
                if (cube[0][2][1].lc_up == "green") {
                    turn_counterclockwise('U');
                    turn_counterclockwise('B');
                    turn_counterclockwise('U');
                    turn_back_clockwise();
                    turn_up_clockwise();
                    turn_left_clockwise();
                    turn_up_clockwise();
                    turn_counterclockwise('L');
                    turn_counterclockwise('U');


                } else if (cube[0][2][1].lc_up == "blue") {
                    turn_up_clockwise();
                    turn_front_clockwise();
                    turn_up_clockwise();
                    turn_counterclockwise('F');
                    turn_counterclockwise('U');
                    turn_counterclockwise('L');
                    turn_counterclockwise('U');
                    turn_left_clockwise();
                    turn_up_clockwise();
                }
                for (int i = 0; i < 4; i++) {
                    if (cube[0][1][1].lc_left == cube[0][2][1].lc_left) {
                        break;
                    }
                    turn_up_clockwise();
                }
                if (cube[0][2][1].lc_up == "green") {
                    turn_counterclockwise('U');
                    turn_counterclockwise('B');
                    turn_counterclockwise('U');
                    turn_back_clockwise();
                    turn_up_clockwise();
                    turn_left_clockwise();
                    turn_up_clockwise();
                    turn_counterclockwise('L');
                    turn_counterclockwise('U');


                } else if (cube[0][2][1].lc_up == "blue") {
                    turn_up_clockwise();
                    turn_front_clockwise();
                    turn_up_clockwise();
                    turn_counterclockwise('F');
                    turn_counterclockwise('U');
                    turn_counterclockwise('L');
                    turn_counterclockwise('U');
                    turn_left_clockwise();
                    turn_up_clockwise();
                }

            }
        } else if (side == 'R') {
            //Находим для красного центра подходящую грань
            int score_red = 0;
            for (int i = 0; i < 4; i++) {
                if (cube[2][1][1].lc_right == cube[2][2][1].lc_right) {
                    score_red++;
                }
                turn_up_clockwise();
            }
            //Мы нашли подходящую грань
            if (score_red == 1) {
                for (int i = 0; i < 4; i++) {
                    if (cube[2][1][1].lc_right == cube[2][2][1].lc_right) {
                        break;
                    }
                    turn_up_clockwise();
                }
                if (cube[2][2][1].lc_up == "green") {
                    turn_up_clockwise();
                    turn_back_clockwise();
                    turn_up_clockwise();
                    turn_counterclockwise('B');
                    turn_counterclockwise('U');
                    turn_counterclockwise('R');
                    turn_counterclockwise('U');
                    turn_right_clockwise();
                    turn_up_clockwise();


                } else if (cube[2][2][1].lc_up == "blue") {
                    turn_counterclockwise('U');
                    turn_counterclockwise('F');
                    turn_counterclockwise('U');
                    turn_front_clockwise();
                    turn_up_clockwise();
                    turn_right_clockwise();
                    turn_up_clockwise();
                    turn_counterclockwise('R');
                    turn_counterclockwise('U');
                }
            } else if (score_red == 2) {
                for (int i = 0; i < 4; i++) {
                    if (cube[2][1][1].lc_right == cube[2][2][1].lc_right) {
                        break;
                    }
                    turn_up_clockwise();
                }
                if (cube[2][2][1].lc_up == "green") {
                    turn_up_clockwise();
                    turn_back_clockwise();
                    turn_up_clockwise();
                    turn_counterclockwise('B');
                    turn_counterclockwise('U');
                    turn_counterclockwise('R');
                    turn_counterclockwise('U');
                    turn_right_clockwise();
                    turn_up_clockwise();


                } else if (cube[2][2][1].lc_up == "blue") {
                    turn_counterclockwise('U');
                    turn_counterclockwise('F');
                    turn_counterclockwise('U');
                    turn_front_clockwise();
                    turn_up_clockwise();
                    turn_right_clockwise();
                    turn_up_clockwise();
                    turn_counterclockwise('R');
                    turn_counterclockwise('U');
                }
                for (int i = 0; i < 4; i++) {
                    if (cube[2][1][1].lc_right == cube[2][2][1].lc_right) {
                        break;
                    }
                    turn_up_clockwise();
                }
                if (cube[2][2][1].lc_up == "green") {
                    turn_up_clockwise();
                    turn_back_clockwise();
                    turn_up_clockwise();
                    turn_counterclockwise('B');
                    turn_counterclockwise('U');
                    turn_counterclockwise('R');
                    turn_counterclockwise('U');
                    turn_right_clockwise();
                    turn_up_clockwise();


                } else if (cube[2][2][1].lc_up == "blue") {
                    turn_counterclockwise('U');
                    turn_counterclockwise('F');
                    turn_counterclockwise('U');
                    turn_front_clockwise();
                    turn_up_clockwise();
                    turn_right_clockwise();
                    turn_up_clockwise();
                    turn_counterclockwise('R');
                    turn_counterclockwise('U');
                }

            }

        } else if (side == 'G') {
            //Находим для зеленого центра подходящую грань
            int score_green = 0;
            for (int i = 0; i < 4; i++) {
                if (cube[1][1][0].lc_back == cube[1][2][0].lc_back) {
                    score_green++;
                }
                turn_up_clockwise();
            }
            //Мы нашли подходящую грань
            if (score_green == 1) {
                for (int i = 0; i < 4; i++) {
                    if (cube[1][1][0].lc_back == cube[1][2][0].lc_back) {
                        break;
                    }
                    turn_up_clockwise();
                }
                if (cube[1][2][0].lc_up == "red") {
                    turn_counterclockwise('U');
                    turn_counterclockwise('R');
                    turn_counterclockwise('U');
                    turn_right_clockwise();
                    turn_up_clockwise();
                    turn_back_clockwise();
                    turn_up_clockwise();
                    turn_counterclockwise('B');
                    turn_counterclockwise('U');

                } else if (cube[1][2][0].lc_up == "orange") {
                    turn_up_clockwise();
                    turn_left_clockwise();
                    turn_up_clockwise();
                    turn_counterclockwise('L');
                    turn_counterclockwise('U');
                    turn_counterclockwise('B');
                    turn_counterclockwise('U');
                    turn_back_clockwise();
                    turn_up_clockwise();
                }
            } else if (score_green == 2) {
                for (int i = 0; i < 4; i++) {
                    if (cube[1][1][0].lc_back == cube[1][2][0].lc_back) {
                        break;
                    }
                    turn_up_clockwise();
                }
                if (cube[1][2][0].lc_up == "red") {
                    turn_counterclockwise('U');
                    turn_counterclockwise('R');
                    turn_counterclockwise('U');
                    turn_right_clockwise();
                    turn_up_clockwise();
                    turn_back_clockwise();
                    turn_up_clockwise();
                    turn_counterclockwise('B');
                    turn_counterclockwise('U');

                } else if (cube[1][2][0].lc_up == "orange") {
                    turn_up_clockwise();
                    turn_left_clockwise();
                    turn_up_clockwise();
                    turn_counterclockwise('L');
                    turn_counterclockwise('U');
                    turn_counterclockwise('B');
                    turn_counterclockwise('U');
                    turn_back_clockwise();
                    turn_up_clockwise();
                }
                for (int i = 0; i < 4; i++) {
                    if (cube[1][1][0].lc_back == cube[1][2][0].lc_back) {
                        break;
                    }
                    turn_up_clockwise();
                }
                if (cube[1][2][0].lc_up == "red") {
                    turn_counterclockwise('U');
                    turn_counterclockwise('R');
                    turn_counterclockwise('U');
                    turn_right_clockwise();
                    turn_up_clockwise();
                    turn_back_clockwise();
                    turn_up_clockwise();
                    turn_counterclockwise('B');
                    turn_counterclockwise('U');

                } else if (cube[1][2][0].lc_up == "orange") {
                    turn_up_clockwise();
                    turn_left_clockwise();
                    turn_up_clockwise();
                    turn_counterclockwise('L');
                    turn_counterclockwise('U');
                    turn_counterclockwise('B');
                    turn_counterclockwise('U');
                    turn_back_clockwise();
                    turn_up_clockwise();
                }

            }
        }
    };

    void second_layer() {
        for (int i = 0; i < 4; i++) {
            side_selection('B');
            side_selection('O');
            side_selection('R');
            side_selection('G');
        }
        //Проверка на неправильные позиции
        if (!((cube[0][1][2].lc_front == cube[1][1][2].lc_front) && (cube[0][1][2].lc_left == cube[0][1][1].lc_left))) {
            turn_counterclockwise('L');
            turn_counterclockwise('U');
            turn_left_clockwise();
            turn_up_clockwise();
            turn_front_clockwise();
            turn_up_clockwise();
            turn_counterclockwise('F');
            turn_counterclockwise('U');
            for (int i = 0; i < 4; i++) {
                side_selection('B');
                side_selection('O');
                side_selection('R');
                side_selection('G');
            }
        }
        if (!((cube[2][1][2].lc_front == cube[1][1][2].lc_front) &&
              (cube[2][1][2].lc_right == cube[2][1][1].lc_right))) {
            turn_counterclockwise('F');
            turn_counterclockwise('U');
            turn_front_clockwise();
            turn_up_clockwise();
            turn_right_clockwise();
            turn_up_clockwise();
            turn_counterclockwise('R');
            turn_counterclockwise('U');
            for (int i = 0; i < 4; i++) {
                side_selection('B');
                side_selection('O');
                side_selection('R');
                side_selection('G');
            }
        }
        if (!((cube[2][1][0].lc_back == cube[1][1][0].lc_back) && (cube[2][1][0].lc_right == cube[2][1][1].lc_right))) {
            turn_counterclockwise('R');
            turn_counterclockwise('U');
            turn_right_clockwise();
            turn_up_clockwise();
            turn_back_clockwise();
            turn_up_clockwise();
            turn_counterclockwise('B');
            turn_counterclockwise('U');
            for (int i = 0; i < 4; i++) {
                side_selection('B');
                side_selection('O');
                side_selection('R');
                side_selection('G');
            }

        }
        if (!((cube[0][1][0].lc_back == cube[1][1][0].lc_back) && (cube[0][1][0].lc_left == cube[0][1][1].lc_left))) {
            turn_counterclockwise('B');
            turn_counterclockwise('U');
            turn_back_clockwise();
            turn_up_clockwise();
            turn_left_clockwise();
            turn_up_clockwise();
            turn_counterclockwise('L');
            turn_counterclockwise('U');
            for (int i = 0; i < 4; i++) {
                side_selection('B');
                side_selection('O');
                side_selection('R');
                side_selection('G');
            }
        }

    }

    bool check_yellow_cross() {
        int check_non_cross = 0;
        bool check_non_cross1 = false;

        if (cube[1][2][0].lc_up == "yellow") {
            check_non_cross++;
        }
        if (cube[2][2][1].lc_up == "yellow") {
            check_non_cross++;

        }
        if (cube[1][2][2].lc_up == "yellow") {
            check_non_cross++;
        }
        if (cube[0][2][1].lc_up == "yellow") {
            check_non_cross++;
        }

        if (check_non_cross == 4) {
            check_non_cross1 = true;
            return true;
        } else {
            return false;
        }

    };

    void assembling_yellow_cross() {
        //Начнем с проверки на крест
        if (!check_yellow_cross()) {
            if (cube[1][2][0].lc_up == "yellow" && cube[1][2][2].lc_up == "yellow") {
                turn_right_clockwise();
                turn_back_clockwise();
                turn_up_clockwise();
                turn_counterclockwise('B');
                turn_counterclockwise('U');
                turn_counterclockwise('R');
            } else if (cube[0][2][1].lc_up == "yellow" && cube[2][2][1].lc_up == "yellow") {
                turn_front_clockwise();
                turn_right_clockwise();
                turn_up_clockwise();
                turn_counterclockwise('R');
                turn_counterclockwise('U');
                turn_counterclockwise('F');
            }
            if (!check_yellow_cross()) {
                if (cube[1][2][0].lc_up == "yellow" && cube[0][2][1].lc_up == "yellow") {
                    turn_front_clockwise();
                    turn_right_clockwise();
                    turn_up_clockwise();
                    turn_counterclockwise('R');
                    turn_counterclockwise('U');
                    turn_right_clockwise();
                    turn_up_clockwise();
                    turn_counterclockwise('R');
                    turn_counterclockwise('U');
                    turn_counterclockwise('F');
                } else if (cube[1][2][0].lc_up == "yellow" && cube[2][2][1].lc_up == "yellow") {
                    turn_counterclockwise('U');
                    turn_front_clockwise();
                    turn_right_clockwise();
                    turn_up_clockwise();
                    turn_counterclockwise('R');
                    turn_counterclockwise('U');
                    turn_right_clockwise();
                    turn_up_clockwise();
                    turn_counterclockwise('R');
                    turn_counterclockwise('U');
                    turn_counterclockwise('F');
                } else if (cube[2][2][1].lc_up == "yellow" && cube[1][2][2].lc_up == "yellow") {
                    turn_up_clockwise();
                    turn_up_clockwise();
                    turn_front_clockwise();
                    turn_right_clockwise();
                    turn_up_clockwise();
                    turn_counterclockwise('R');
                    turn_counterclockwise('U');
                    turn_right_clockwise();
                    turn_up_clockwise();
                    turn_counterclockwise('R');
                    turn_counterclockwise('U');
                    turn_counterclockwise('F');
                } else if (cube[1][2][2].lc_up == "yellow" && cube[0][2][1].lc_up == "yellow") {
                    turn_up_clockwise();
                    turn_front_clockwise();
                    turn_right_clockwise();
                    turn_up_clockwise();
                    turn_counterclockwise('R');
                    turn_counterclockwise('U');
                    turn_right_clockwise();
                    turn_up_clockwise();
                    turn_counterclockwise('R');
                    turn_counterclockwise('U');
                    turn_counterclockwise('F');
                }
                if (!(check_yellow_cross())) {
                    turn_front_clockwise();
                    turn_right_clockwise();
                    turn_up_clockwise();
                    turn_counterclockwise('R');
                    turn_counterclockwise('U');
                    turn_counterclockwise('F');

                    if (cube[1][2][0].lc_up == "yellow" && cube[0][2][1].lc_up == "yellow") {
                        turn_front_clockwise();
                        turn_right_clockwise();
                        turn_up_clockwise();
                        turn_counterclockwise('R');
                        turn_counterclockwise('U');
                        turn_right_clockwise();
                        turn_up_clockwise();
                        turn_counterclockwise('R');
                        turn_counterclockwise('U');
                        turn_counterclockwise('F');
                    } else if (cube[1][2][0].lc_up == "yellow" && cube[2][2][1].lc_up == "yellow") {
                        turn_counterclockwise('U');
                        turn_front_clockwise();
                        turn_right_clockwise();
                        turn_up_clockwise();
                        turn_counterclockwise('R');
                        turn_counterclockwise('U');
                        turn_right_clockwise();
                        turn_up_clockwise();
                        turn_counterclockwise('R');
                        turn_counterclockwise('U');
                        turn_counterclockwise('F');
                    } else if (cube[2][2][1].lc_up == "yellow" && cube[1][2][2].lc_up == "yellow") {
                        turn_up_clockwise();
                        turn_up_clockwise();
                        turn_front_clockwise();
                        turn_right_clockwise();
                        turn_up_clockwise();
                        turn_counterclockwise('R');
                        turn_counterclockwise('U');
                        turn_right_clockwise();
                        turn_up_clockwise();
                        turn_counterclockwise('R');
                        turn_counterclockwise('U');
                        turn_counterclockwise('F');
                    } else if (cube[1][2][2].lc_up == "yellow" && cube[0][2][1].lc_up == "yellow") {
                        turn_up_clockwise();
                        turn_front_clockwise();
                        turn_right_clockwise();
                        turn_up_clockwise();
                        turn_counterclockwise('R');
                        turn_counterclockwise('U');
                        turn_right_clockwise();
                        turn_up_clockwise();
                        turn_counterclockwise('R');
                        turn_counterclockwise('U');
                        turn_counterclockwise('F');
                    }
                }
            }
        }
    }

    void assembling_true_angle() {
        while (!((cube[2][2][2].lc_up == "yellow" || cube[2][2][2].lc_up == "blue" ||
                  cube[2][2][2].lc_up == "red") &&
                 (cube[2][2][2].lc_front == "yellow" ||
                  cube[2][2][2].lc_front == "blue" || cube[2][2][2].lc_front == "red") &&
                 (cube[2][2][2].lc_right == "yellow" ||
                  cube[2][2][2].lc_right == "blue" || cube[2][2][2].lc_right == "red"))) {
            turn_up_clockwise();
        }

        while (!((cube[2][2][0].lc_up == "yellow" || cube[2][2][0].lc_up == "green" || cube[2][2][0].lc_up == "red") &&
                 (cube[2][2][0].lc_back == "yellow" ||
                  cube[2][2][0].lc_back == "green" || cube[2][2][0].lc_back == "red") &&
                 (cube[2][2][0].lc_right == "yellow" ||
                  cube[2][2][0].lc_right == "green" || cube[2][2][0].lc_right == "red"))) {
            turn_right_clockwise();
            turn_up_clockwise();
            turn_counterclockwise('R');
            turn_counterclockwise('U');
            turn_right_clockwise();
            turn_up_clockwise();
            turn_counterclockwise('R');
            turn_counterclockwise('U');
            turn_right_clockwise();
            turn_up_clockwise();
            turn_counterclockwise('R');
            turn_counterclockwise('U');

            turn_counterclockwise('F');
            turn_counterclockwise('U');
            turn_front_clockwise();
            turn_up_clockwise();
            turn_counterclockwise('F');
            turn_counterclockwise('U');
            turn_front_clockwise();
            turn_up_clockwise();
            turn_counterclockwise('F');
            turn_counterclockwise('U');
            turn_front_clockwise();
            turn_up_clockwise();
        }

        while (!((cube[0][2][0].lc_up == "yellow" || cube[0][2][0].lc_up == "green" ||
                  cube[0][2][0].lc_up == "orange") &&
                 (cube[0][2][0].lc_back == "yellow" ||
                  cube[0][2][0].lc_back == "green" || cube[0][2][0].lc_back == "orange") &&
                 (cube[0][2][0].lc_left == "yellow" ||
                  cube[0][2][0].lc_left == "green" || cube[0][2][0].lc_left == "orange"))) {
            turn_left_clockwise();
            turn_up_clockwise();
            turn_counterclockwise('L');
            turn_counterclockwise('U');
            turn_left_clockwise();
            turn_up_clockwise();
            turn_counterclockwise('L');
            turn_counterclockwise('U');
            turn_left_clockwise();
            turn_up_clockwise();
            turn_counterclockwise('L');
            turn_counterclockwise('U');

            turn_counterclockwise('B');
            turn_counterclockwise('U');
            turn_back_clockwise();
            turn_up_clockwise();
            turn_counterclockwise('B');
            turn_counterclockwise('U');
            turn_back_clockwise();
            turn_up_clockwise();
            turn_counterclockwise('B');
            turn_counterclockwise('U');
            turn_back_clockwise();
            turn_up_clockwise();
            while (!((cube[2][2][2].lc_up == "yellow" || cube[2][2][2].lc_up == "blue" ||
                      cube[2][2][2].lc_up == "red") &&
                     (cube[2][2][2].lc_front == "yellow" ||
                      cube[2][2][2].lc_front == "blue" || cube[2][2][2].lc_front == "red") &&
                     (cube[2][2][2].lc_right == "yellow" ||
                      cube[2][2][2].lc_right == "blue" || cube[2][2][2].lc_right == "red"))) {
                turn_up_clockwise();
            }
        }
        while (!((cube[2][2][2].lc_up == "yellow" || cube[2][2][2].lc_up == "blue" ||
                  cube[2][2][2].lc_up == "red") &&
                 (cube[2][2][2].lc_front == "yellow" ||
                  cube[2][2][2].lc_front == "blue" || cube[2][2][2].lc_front == "red") &&
                 (cube[2][2][2].lc_right == "yellow" ||
                  cube[2][2][2].lc_right == "blue" || cube[2][2][2].lc_right == "red"))) {
            turn_up_clockwise();
        }

    }

    void turning_corners() {
        while (cube[0][2][2].lc_up != "yellow") {
            turn_left_clockwise();
            turn_down_clockwise();
            turn_counterclockwise('L');
            turn_counterclockwise('D');
        }
        turn_counterclockwise('U');
        while (cube[0][2][2].lc_up != "yellow") {
            turn_left_clockwise();
            turn_down_clockwise();
            turn_counterclockwise('L');
            turn_counterclockwise('D');
        }
        turn_counterclockwise('U');
        while (cube[0][2][2].lc_up != "yellow") {
            turn_left_clockwise();
            turn_down_clockwise();
            turn_counterclockwise('L');
            turn_counterclockwise('D');
        }
        turn_counterclockwise('U');
        while (cube[0][2][2].lc_up != "yellow") {
            turn_left_clockwise();
            turn_down_clockwise();
            turn_counterclockwise('L');
            turn_counterclockwise('D');
        }

    }

    void final() {
        while (!((cube[2][2][2].lc_up == "yellow" || cube[2][2][2].lc_up == "blue" ||
                  cube[2][2][2].lc_up == "red") &&
                 (cube[2][2][2].lc_front == "yellow" ||
                  cube[2][2][2].lc_front == "blue" || cube[2][2][2].lc_front == "red") &&
                 (cube[2][2][2].lc_right == "yellow" ||
                  cube[2][2][2].lc_right == "blue" || cube[2][2][2].lc_right == "red"))) {
            turn_up_clockwise();
        }
        bool green = false;
        bool red = false;
        bool orange = false;
        while (true) {
            if (cube[0][2][1].lc_left == cube[0][2][0].lc_left) {
                orange = true;
                break;
            } else if (cube[2][2][0].lc_right == cube[2][2][1].lc_right) {
                red = true;
                break;
            } else if (cube[0][2][0].lc_back == cube[1][2][0].lc_back) {
                green = true;
                break;
            }
            turn_right_clockwise();
            turn_up_clockwise();
            turn_counterclockwise('R');
            turn_counterclockwise('U');

            turn_counterclockwise('L');
            turn_counterclockwise('U');
            turn_left_clockwise();
            turn_up_clockwise();

            turn_right_clockwise();
            turn_up_clockwise();
            turn_counterclockwise('R');
            turn_counterclockwise('U');
            turn_right_clockwise();
            turn_up_clockwise();
            turn_counterclockwise('R');
            turn_counterclockwise('U');
            turn_right_clockwise();
            turn_up_clockwise();
            turn_counterclockwise('R');
            turn_counterclockwise('U');
            turn_right_clockwise();
            turn_up_clockwise();
            turn_counterclockwise('R');
            turn_counterclockwise('U');
            turn_right_clockwise();
            turn_up_clockwise();
            turn_counterclockwise('R');
            turn_counterclockwise('U');

            turn_counterclockwise('L');
            turn_counterclockwise('U');
            turn_left_clockwise();
            turn_up_clockwise();
            turn_counterclockwise('L');
            turn_counterclockwise('U');
            turn_left_clockwise();
            turn_up_clockwise();
            turn_counterclockwise('L');
            turn_counterclockwise('U');
            turn_left_clockwise();
            turn_up_clockwise();
            turn_counterclockwise('L');
            turn_counterclockwise('U');
            turn_left_clockwise();
            turn_up_clockwise();
            turn_counterclockwise('L');
            turn_counterclockwise('U');
            turn_left_clockwise();
            turn_up_clockwise();

        }

        if (red) {
            while (!(cube[0][2][2].lc_front == cube[1][2][2].lc_front)) {
                turn_back_clockwise();
                turn_up_clockwise();
                turn_counterclockwise('B');
                turn_counterclockwise('U');

                turn_counterclockwise('F');
                turn_counterclockwise('U');
                turn_front_clockwise();
                turn_up_clockwise();


                turn_back_clockwise();
                turn_up_clockwise();
                turn_counterclockwise('B');
                turn_counterclockwise('U');
                turn_back_clockwise();
                turn_up_clockwise();
                turn_counterclockwise('B');
                turn_counterclockwise('U');
                turn_back_clockwise();
                turn_up_clockwise();
                turn_counterclockwise('B');
                turn_counterclockwise('U');
                turn_back_clockwise();
                turn_up_clockwise();
                turn_counterclockwise('B');
                turn_counterclockwise('U');
                turn_back_clockwise();
                turn_up_clockwise();
                turn_counterclockwise('B');
                turn_counterclockwise('U');


                turn_counterclockwise('F');
                turn_counterclockwise('U');
                turn_front_clockwise();
                turn_up_clockwise();
                turn_counterclockwise('F');
                turn_counterclockwise('U');
                turn_front_clockwise();
                turn_up_clockwise();
                turn_counterclockwise('F');
                turn_counterclockwise('U');
                turn_front_clockwise();
                turn_up_clockwise();
                turn_counterclockwise('F');
                turn_counterclockwise('U');
                turn_front_clockwise();
                turn_up_clockwise();
                turn_counterclockwise('F');
                turn_counterclockwise('U');
                turn_front_clockwise();
                turn_up_clockwise();

            }

        } else if (green) {
            while (!(cube[0][2][2].lc_front == cube[1][2][2].lc_front)) {
                turn_left_clockwise();
                turn_up_clockwise();
                turn_counterclockwise('L');
                turn_counterclockwise('U');

                turn_counterclockwise('R');
                turn_counterclockwise('U');
                turn_right_clockwise();
                turn_up_clockwise();

                turn_left_clockwise();
                turn_up_clockwise();
                turn_counterclockwise('L');
                turn_counterclockwise('U');
                turn_left_clockwise();
                turn_up_clockwise();
                turn_counterclockwise('L');
                turn_counterclockwise('U');
                turn_left_clockwise();
                turn_up_clockwise();
                turn_counterclockwise('L');
                turn_counterclockwise('U');
                turn_left_clockwise();
                turn_up_clockwise();
                turn_counterclockwise('L');
                turn_counterclockwise('U');
                turn_left_clockwise();
                turn_up_clockwise();
                turn_counterclockwise('L');
                turn_counterclockwise('U');


                turn_counterclockwise('R');
                turn_counterclockwise('U');
                turn_right_clockwise();
                turn_up_clockwise();
                turn_counterclockwise('R');
                turn_counterclockwise('U');
                turn_right_clockwise();
                turn_up_clockwise();
                turn_counterclockwise('R');
                turn_counterclockwise('U');
                turn_right_clockwise();
                turn_up_clockwise();
                turn_counterclockwise('R');
                turn_counterclockwise('U');
                turn_right_clockwise();
                turn_up_clockwise();
                turn_counterclockwise('R');
                turn_counterclockwise('U');
                turn_right_clockwise();
                turn_up_clockwise();
            }

        } else if (orange) {
            while (!(cube[0][2][2].lc_front == cube[1][2][2].lc_front)) {
                turn_front_clockwise();
                turn_up_clockwise();
                turn_counterclockwise('F');
                turn_counterclockwise('U');

                turn_counterclockwise('B');
                turn_counterclockwise('U');
                turn_back_clockwise();
                turn_up_clockwise();

                turn_front_clockwise();
                turn_up_clockwise();
                turn_counterclockwise('F');
                turn_counterclockwise('U');
                turn_front_clockwise();
                turn_up_clockwise();
                turn_counterclockwise('F');
                turn_counterclockwise('U');
                turn_front_clockwise();
                turn_up_clockwise();
                turn_counterclockwise('F');
                turn_counterclockwise('U');
                turn_front_clockwise();
                turn_up_clockwise();
                turn_counterclockwise('F');
                turn_counterclockwise('U');
                turn_front_clockwise();
                turn_up_clockwise();
                turn_counterclockwise('F');
                turn_counterclockwise('U');

                turn_counterclockwise('B');
                turn_counterclockwise('U');
                turn_back_clockwise();
                turn_up_clockwise();
                turn_counterclockwise('B');
                turn_counterclockwise('U');
                turn_back_clockwise();
                turn_up_clockwise();
                turn_counterclockwise('B');
                turn_counterclockwise('U');
                turn_back_clockwise();
                turn_up_clockwise();
                turn_counterclockwise('B');
                turn_counterclockwise('U');
                turn_back_clockwise();
                turn_up_clockwise();
                turn_counterclockwise('B');
                turn_counterclockwise('U');
                turn_back_clockwise();
                turn_up_clockwise();
            }

        }

    }

    bool invariance(RubicsCube one) {
        one.assembling_cross();
        one.assembling_white_side();
        one.second_layer();
        one.assembling_yellow_cross();
        one.assembling_true_angle();
        one.turning_corners();
        one.final();

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

    void writing_file() {
        int score = 0;
        ofstream fout;
        fout.open("../output.txt");
        //Запись кубика в файл
        //Вывод задней стороны
        for (int y = 2; y >= 0; y--) {
            for (int x = 2; x >= 0; x--) {
                if (score == 3) {
                    fout << endl;
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
                    fout << endl;
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
                    fout << endl;
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
                    fout << endl;
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
                    fout << endl;
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
                    fout << endl;
                    score = 0;
                }
                fout << cube[x][0][z].lc_down << " ";
                score++;
            }
        }

        fout.close();
    }

    void ride_file() {
        vector<vector<vector<SmallCube>>> backup_cube = cube;
        ifstream fin;
        fin.open("../input.txt");

        for (int y = 2; y >= 0; y--) {
            for (int x = 2; x >= 0; x--) {
                fin >> cube[x][y][0].lc_back;
            }
        }
        fin.close();

    }

};


int main() {
    RubicsCube one;
//    //Для синего
//    one.turn_right_clockwise();
//    one.turn_counterclockwise('L');
//    one.turn_counterclockwise('D');
//    one.turn_front_clockwise();
//    one.turn_right_clockwise();
//    one.turn_counterclockwise('L');
//
//    one.turn_front_clockwise();
//    one.turn_counterclockwise('B');
//    one.turn_down_clockwise();
//    one.turn_left_clockwise();
//    one.turn_front_clockwise();
//    one.turn_counterclockwise('B');

//Оранжевый и синий

//    one.turn_right_clockwise();
//    one.turn_counterclockwise('L');
//    one.turn_front_clockwise();
//    one.turn_counterclockwise('B');
//
//    one.turn_back_clockwise();
//    one.turn_counterclockwise('F');
//    one.turn_down_clockwise();
//    one.turn_right_clockwise();
//    one.turn_back_clockwise();
//    one.turn_counterclockwise('F');

//Оранжевый, синий, красный
//    one.turn_back_clockwise();
//    one.turn_front_clockwise();
//    one.turn_right_clockwise();
//    one.turn_counterclockwise('L');

    //Оранжевый, синий, красный, зеленый
    one.turn_counterclockwise('R');
    one.turn_back_clockwise();
    one.turn_front_clockwise();
    one.turn_counterclockwise('L');

//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);


//    one.assembling_cross();
//    one.assembling_white_side();
//    one.second_layer();
//    one.assembling_yellow_cross();
//    one.assembling_true_angle();
//    one.turning_corners();
//    one.final();
//    one.printCube();
//    cout << endl;
//    cout << one.invariance(one);
//    one.writing_file();
    one.ride_file();
    one.printCube();

};