#ifndef RUBIK__S_CUBE_ASSEMBLINGRUBIKSCUBE_H
#define RUBIK__S_CUBE_ASSEMBLINGRUBIKSCUBE_H
#include "CSmallCube.h"
#include "CRubicsCube.h"
class AssemblingRubiksCube {
private:
    CRubicsCube assembling;
public:
    AssemblingRubiksCube(CRubicsCube one);


    bool check_nn_cross(); //Проверка на неправильный кубик
    bool check_cross(); //Проверка на уже собранный белый крест

    void assembling_cross();//Сборка неправильного креста
    void pif_paf_up(char side);//пиф паф для первого слоя, выставляет угловые кубики по углам
    bool check_neighboring_side(char side);//Проверка соседов
    bool check_up_white();//Проверка на белые верхушки
    void assembling_white_side();//Сборка белой стороны
    void side_selection(char side);//Для сборки второго слоя
    void second_layer();//Сборка второго слоя
    bool check_yellow_cross();//Проверка желтого креста
    void assembling_yellow_cross();//Сборка желтого креста
    void assembling_true_angle();//Поставление правильных углов
    void turning_corners();//Переворачиваем углы
    void final();//Постановка центров
    CRubicsCube assemble();

    bool invariance(CRubicsCube one);//Проверка кубика на инвариантность
};


#endif //RUBIK__S_CUBE_ASSEMBLINGRUBIKSCUBE_H
