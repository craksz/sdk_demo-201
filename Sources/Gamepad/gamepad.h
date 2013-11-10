#ifndef _GAMEPAD_H_
#define _GAMEPAD_H_

#include <ardrone_tool/UI/ardrone_input.h>
#include "cv.h"


#include <stdio.h>


#define switchTop 5
#define XGAIN1 1.8 
#define XGAIN2 0.5
#define XGAIN3 0.1
#define YGAIN1 1.8
#define YGAIN2 0.5
#define YGAIN3 0.1
#define ZGAIN1 0.8
#define ZGAIN2 3.0
#define ZGAIN3 1.0
#define WGAIN1 1.1
#define WGAIN2 3.3
#define WGAIN3 1.0
#define YAWTOLERANCE 10

typedef enum{
	varX=1,
	varY,
	varYaw,
	varZ
} ControlVars;

typedef struct {

	double x;
	double y;
	double z;
	double w;

	double ref;

	int counter;
	int counter2;

	char *name;

}	fGraph;


typedef struct{
	float phi;
	float theta;
	float gaz;
	float yaw;
}Manual;

//IplImage *getImage();
Manual *getManual();
void clearManual();

extern input_device_t fpad;

C_RESULT open_fpad(void);
C_RESULT update_fpad(void);
C_RESULT close_fpad(void);

/*	Estructura para el control difuso	*/
typedef struct {

	double vin;
	double ref;
	double vout;

	double ke;
	double kr;
	double ku;

	double error;
	double error0;

	char *name;

}	vControl;

vControl* getSomeData(int);

//	Proceso de Control
void fuzzyControl ( vControl *altitud, vControl *X, vControl *Y, vControl *Yaw );

//	Inicializa las structura de control a cero
void inControl ( vControl *control );

//	Establece las escalas de Error, Rate para el control de altitud
void setSkale ( vControl *control, double ke, double kr, double ku );

//	Proceso de fusificación
void fuzzification ( double *element , double *fuzzyMem );

//	Ecuación de la recta con pendiente positiva
void ecRecPos( double *x, double *y , int A, int C );

//	Ecuación de la recta con pendiente negativa
void ecRecNeg( double *x, double *y , int A, int C );

//	Inferencia Difusa para altitud
void fuzzyInferenceAlt( double *fuzzyError, double *fuzzyRate, double *vInference);

//	Método de inferencia difusa: Zadeh fuzzy logic AND
void minimum( double *var1 , double *var2 , double *var3 );

//	Método de inferencia difusa: Zadeh fuzzy logic OR
void maximum( double *var1, double *var2, double *var3);

//	Defusificación: Linear Defuzzyfier
void Defuzz( double *u , double *h , double *ku , double *vout );

void bringItOn(void);



void inGraph( fGraph *gX );
void fuzzyGraph( fGraph *, IplImage * );


void someFunction(void);

#endif //_GAMEPAD_H_