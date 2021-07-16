#pragma once
void init();
void fit(double X[100][5]);
double sigmoid(double y);
double f( double X[4]);
double cross_entropy(double y, double t);
double divE_w(double X, double y, double t);
double result(double X[100][5]);