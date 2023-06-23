#include <stdio.h>
#include <math.h>
#include "funciones.h"

float ingreseComponente(char componente, int i){
    float comp;
    printf("Ingrese la componente %c del punto %d: ",componente,i);
    scanf("%f",&comp);
    return comp;
}

float calcularDistancias(float x1, float y1, float z1, float x2, float y2, float z2){
    return sqrt(pow(x1-x2,2)+pow(y1-y2,2)+pow(z1-z2,2));
}

float calcularPerimetro(float puntos[4][3]){
    float l1 = calcularDistancias(puntos[0][0],puntos[0][1],puntos[0][2],puntos[1][0],puntos[1][1],puntos[1][2]);
    float l2 = calcularDistancias(puntos[1][0],puntos[1][1],puntos[1][2],puntos[2][0],puntos[2][1],puntos[2][2]);
    float l3 = calcularDistancias(puntos[0][0],puntos[0][1],puntos[0][2],puntos[2][0],puntos[2][1],puntos[2][2]);

    float l4 = calcularDistancias(puntos[0][0],puntos[0][1],puntos[0][2],puntos[3][0],puntos[3][1],puntos[3][2]);
    float l5 = calcularDistancias(puntos[1][0],puntos[1][1],puntos[1][2],puntos[3][0],puntos[3][1],puntos[3][2]);
    float l6 = calcularDistancias(puntos[3][0],puntos[3][1],puntos[3][2],puntos[2][0],puntos[2][1],puntos[2][2]);

    return l1+l2+l3+l4+l5+l6;
}

float calcularArea(float x1, float y1, float z1, float x2, float y2, float z2,float x3, float y3, float z3){

    float l1 = calcularDistancias(x1,y1,z1,x2,y2,z2);
    float l2 = calcularDistancias(x2,y2,z2,x3,y3,z3);
    float l3 = calcularDistancias(x1,y1,z1,x3,y3,z3);
    float s = (l1+l2+l3)/2;
    return sqrt(s*(s-l1)*(s-l2)*(s-l3));
}

float calcularAreaSuperficial(float puntos[4][3]){
    float areabase = calcularArea(puntos[0][0],puntos[0][1],puntos[0][2],puntos[1][0],puntos[1][1],puntos[1][2],puntos[2][0],puntos[2][1],puntos[2][2]);
    float area1 = calcularArea(puntos[0][0],puntos[0][1],puntos[0][2],puntos[1][0],puntos[1][1],puntos[1][2],puntos[3][0],puntos[3][1],puntos[3][2]);
    float area2 = calcularArea(puntos[0][0],puntos[0][1],puntos[0][2],puntos[2][0],puntos[2][1],puntos[2][2],puntos[3][0],puntos[3][1],puntos[3][2]);
    float area3 = calcularArea(puntos[1][0],puntos[1][1],puntos[1][2],puntos[2][0],puntos[2][1],puntos[2][2],puntos[3][0],puntos[3][1],puntos[3][2]);
    return areabase+area1+area2+area3;
}

float calcularVolumen(float puntos[4][3]){
    float gx=(puntos[0][0]+puntos[1][0]+puntos[2][0])/3;
    float gy=(puntos[0][1]+puntos[1][1]+puntos[2][1])/3;
    float gz=(puntos[0][2]+puntos[1][2]+puntos[2][2])/3;
    float altura = calcularDistancias(gx,gy,gz,puntos[3][0],puntos[3][1],puntos[3][2]); 
    float areaBase = calcularArea(puntos[0][0],puntos[0][1],puntos[0][2],puntos[1][0],puntos[1][1],puntos[1][2],puntos[2][0],puntos[2][1],puntos[2][2]);
    return areaBase*altura/3;
}

int validarPiramide(float puntos[4][3]){
    float gx=(puntos[0][0]+puntos[1][0]+puntos[2][0])/3;
    float gy=(puntos[0][1]+puntos[1][1]+puntos[2][1])/3;
    float gz=(puntos[0][2]+puntos[1][2]+puntos[2][2])/3;
    float a = calcularDistancias(gx,gy,gz,puntos[3][0],puntos[3][1],puntos[3][2]);
    float b = calcularDistancias(gx,gy,gz,puntos[0][0],puntos[0][1],puntos[0][2]);
    float c = calcularDistancias(puntos[0][0],puntos[0][1],puntos[0][2],puntos[3][0],puntos[3][1],puntos[3][2]);
    if((pow(a,2)+pow(b,2))==pow(c,2)){
        return 1;
    }
    else{
        return 2;
    }
}