#include <math.h>
#include "binary_logr.h"

extern double w[4];
extern double lr;

void init() {
	int i = 0;
	for (i = 0; i < 4; i++) {
		w[i] = 1.0;
	}
}

void fit(double X[100][5]) {
	int epoch = 0;
	for (epoch = 0; epoch < 100; epoch++) {
		// forward
		double a, y, loss;
		a = f(X[epoch]);
		y = sigmoid(a);
		loss = cross_entropy(y, X[epoch][4]);

		// backward
		int i = 0;
		for (i = 0; i < 4; i++) {
			w[i] -= lr * divE_w(X[epoch][i], y, X[epoch][4]);
		}
	}

}

double f(double X[5]) {
	return w[0] * X[0] + w[1] * X[1] + w[2] * X[2] + w[3] * X[3];
}

double sigmoid(double y) {
	return 1.0 / (1.0 + exp(-y));
}

double cross_entropy(double y, double t) {
	return t * log(y) + (1 - t) * log(1 - y);
}

double divE_w(double X, double y, double t) {
	return X * (y - t);
}

double result(double X[100][5]) {
	int tnum = 0;
	int i = 0;
	for (i = 0; i < 100; i++) {
		if (sigmoid(f(X[i])) < 0.5) {
			// class 0
			if (X[i][4] == 0.0) { tnum++; }
		}
		else {
			// class 1
			if (X[i][4] == 1.0) { tnum++; }
		}
	}
	return (double)tnum ;
}