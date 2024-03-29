#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	this->Kp = Kp;
	this->Ki = Ki;
	this->Kd = Kd;

	p_error = 0;
	i_error = 0;
	d_error = 0;
}

void PID::UpdateError(double cte) {
	double previous_cte = p_error;

	p_error = cte;
	i_error += cte;
	d_error = cte - previous_cte;
}

double PID::TotalError() {
	return -Kp*p_error - Ki*i_error - Kd*d_error;
}