/* Copyright (C) 2018-2019 Thomas Jespersen, TKJ Electronics. All rights reserved.
 *
 * This program is free software: you can redistribute it and/or modify  
 * it under the terms of the GNU General Public License as published by  
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * General Public License for more details. 
 *
 * Contact information
 * ------------------------------------------
 * Thomas Jespersen, TKJ Electronics
 * Web      :  http://www.tkjelectronics.dk
 * e-mail   :  thomasj@tkjelectronics.dk
 * ------------------------------------------
 */

#ifndef MODULES_PARAMETERS_H
#define MODULES_PARAMETERS_H

#include "stm32h7xx_hal.h"
#include "ThreadSafeParameter.hpp"
#include "ESCON.h"
#include "EEPROM.h"
#include "LSPC.hpp"

#define PARAMETERS_LENGTH 	((uint32_t)&paramsGlobal->eeprom_ - (uint32_t)&paramsGlobal->ForceDefaultParameters)

class Parameters
{
	public:	
		bool ForceDefaultParameters = true; // always load the default parameters listed below, no matter what is stored in EEPROM
		uint16_t ParametersSize = 0;

		struct debug_t {
			/* Debugging parameters */
			bool EnableDumpMessages = true;
			bool EnableRawSensorOutput = true;
			bool UseFilteredIMUinRawSensorOutput = true;
			bool DisableMotorOutput = false; // can be enabled to test full controller functionality without torque being applied
			/* Debugging parameters end */
		} debug;

		struct behavioural_t {
			/* Behavioural parameters */
			bool IndependentHeading = false; // do not correct/track the heading (will not track the heading reference given as part of the quaternion reference)
			bool YawVelocityBraking = false; // if independent heading is enabled and q_dot is used, then yaw velocity will be counteracted by enabling this
			bool StepTestEnabled = false;
			bool SineTestEnabled = false;
			lspc::ParameterTypes::powerButtonMode_t PowerButtonMode = lspc::ParameterTypes::START_STOP_VELOCITY_CONTROL;
			/* Behavioural parameters end */
		} behavioural;
		
		struct controller_t {
			/* Balance Controller Tuning parameters */
			float SampleRate = 200;
			
			/* Controller selection */
			lspc::ParameterTypes::controllerType_t type = lspc::ParameterTypes::SLIDING_MODE_CONTROLLER;  // LQR_CONTROLLER or SLIDING_MODE_CONTROLLER
			lspc::ParameterTypes::controllerMode_t mode = lspc::ParameterTypes::OFF;  // OFF, QUATERNION_CONTROL, ANGULAR_VELOCITY_CONTROL, VELOCITY_CONTROL or PATH_FOLLOWING

			/* Torque output filtering parameters */
			bool EnableTorqueLPF = false;
			float TorqueLPFtau = 0.005; // 0.005 (sliding mode)
			bool TorqueRampUp = true;
			float TorqueRampUpTime = 1.0; // seconds to ramp up Torque after initialization

			/* Motor failure detection parameters (detects ESCON motor driver) */
			bool MotorFailureDetection = true; // detect ESCON motor driver failures (due to current overload, above nominal, for prolonged time)
			float MotorFailureDetectionTime = 0.05; // 50 ms response time for detecting motor failure until the motor driver is reset
			//float MotorFailureThreshold = 0.1; // 10% difference between torque setpoint and delivered torque for longer than MotorFailureDetectionTime will trigger the motor failure event
			float MotorFailureThreshold = 0.5; // more than 0.5 Nm difference between setpoint/requested torque and delivered torque is detected as a failure
			bool StopAtMotorFailure = true; // determines what action to take at failure: the controller should stop (require manual start) or the motor driver should automatically be reset

			/* Controller behaviour parameters */
			bool DisableQdot = false;
			float ReferenceTimeout = 0.5; // if reference is older than 500 ms, do not use it and fall back to 0 reference

			/* Sliding Mode parameters */
			lspc::ParameterTypes::slidingManifoldType_t ManifoldType = lspc::ParameterTypes::Q_DOT_BODY_MANIFOLD;
			bool ContinousSwitching = true;
			bool EquivalentControl = true; // include equivalent control / computed torque (inverse dynamics)
			bool DisableQdotInEquivalentControl = false;
			// u = tau_eq + tau_switching
			// tau_switching = -eta * sat(S/epsilon)
			// In linear region (|S| < epsilon) this turns into
			// tau_switching_linear = -eta/epsilon * S
			// With a maximum torque of 0.8
			float K[3] = {20, 20, 4}; // sliding manifold gain  (S = omega + K*devec*q_err)  or  (S = q_dot + K*devec*q_err)  depending on manifold type
			float eta[3] = {7, 7, 9}; // {5, 5, 10}  switching gain
			float epsilon[3] = {0.5, 0.5, 0.2}; // continous switching law : "radius" of epsilon-tube around the sliding surface, wherein the control law is linear in S

			/* Balance LQR parameters */
			float LQR_K[3*8] = {
					129.602115577122,	8.78174512168197e-14,	-2.58198889746921,	7.87035441101331,	3.35474179461199e-15,	-0.280870541084474,
					-64.8010577885609,	112.238724474001,		-2.58198889746921,	-3.93517720550666,	6.82429800184739,	-0.280870541084474,
					-64.8010577885609,	-112.238724474,			-2.5819888974692,	-3.93517720550666,	-6.82429800184739,	-0.280870541084473
			};
			float LQR_MaxYawError = 10.0; // yaw error clamp [degrees]
			bool LQR_EnableSteadyStateTorque = true; // use steady state torque based on reference

			/* Velocity controller parameters */
			float VelocityController_AccelerationLimit = 1.0;
			float VelocityController_MaxTilt	= 4.0; // max tilt that velocity controller can set [degrees]
			float VelocityController_MaxIntegralCorrection = 4.0; // max tilt integral effect can compensate with [degrees]
			float VelocityController_VelocityClamp = 0.3; // velocity clamp for the velocity error [meters pr. second]
			float VelocityController_IntegralGain = 0.8; // integral gain, which corresponds to the incremental compensation rate (1/gain is the number of seconds it takes the integral to reach a constant offset value)
			float VelocityController_AngleLPFtau = 0.1; // time-constant for low pass filter on angle reference output
			float VelocityController_OmegaLPFtau = 0.02; // time-constant for low pass filter on angle reference output
			bool VelocityController_UseOmegaRef = false;
			/* Controller Tuning parameters end */
		} controller;

		struct estimator_t {
			/* Estimator Tuning parameters */
			float SampleRate = 200;
			
			/* Xsens IMU usage */
			bool UseXsensIMU = true;
			bool ConfigureXsensIMUatBoot = true;
			bool UseXsensQuaternionEstimate = false; // should the orientation estimate be replaced by the Xsens IMU estimate (q_dot will still be the output of the estimator due to necessary filtering/smoothing)
			bool UseHeadingEstimateFromXsensIMU = false; // if the Xsens Quaternion estimate is not used, setting this flag to true will input the Xsens heading into the QEKF as a heading sensor input - Do not use this if a SLAM-based heading input is to be used

			/* Quaternion estimator selection */
			#define EnableSensorLPFfilters_ 	false
			bool EnableSensorLPFfilters = EnableSensorLPFfilters_;
			bool EnableSoftwareLPFfilters = false;
			float SoftwareLPFcoeffs_a[3] = {1.000000000000000, -1.870860377550659, 0.878777573775756};	// 20 Hz LPF
			float SoftwareLPFcoeffs_b[3] = {0.011353393934590, -0.014789591644084, 0.011353393934590};	// Created using:  [num, den] = cheby2(2,40,20/(Fs/2))
			bool CreateQdotFromQDifference = false;
			bool UseMadgwick = false;
			bool EstimateBias = false; // estimate gyroscope bias as part of QEKF - it is not recommended to enable this when using the Xsens IMU since it has internal bias correction

			/* Position estimate configuration */
			bool PositionEstimateDefinedInCoR = false; // at default the position estimate is defined in the center of the ball - enabling this flag will move it to the Center of Rotation (CoR)

			/* Velocity estimate configuration */
			bool UseCoRvelocity = false; // the velocity can conveniently be defined in the Center of Rotation to make it independent of tilt

			/* Velocity estimator parameters */
			bool UseVelocityEstimator = true;
			bool UseTiltForVelocityPrediction = true; // whether or not to propagate the velocity estimate with the predicted acceleration based on the current tilt
			bool UseQdotInVelocityEstimator = true;
			bool UseCOMestimateInVelocityEstimator = false;
			float Var_COM = 3.162277660168379e-06; // (10^(-5.5))  variance on COM estimate into velocity estimator
			float eta_encoder = 1.0f; // tuning factor for encoder measurement trust - decrease value to trust the encoder measurement more
			bool UseWheelSlipDetectorInVelocityEstimator = false;
			float VelocityEstimatorWheelSlipCovariance = 1e-10; // reduce velocity estimator covariance at wheel slip to reduce trust in sensor measurements in general

			/* Velocity LPF (if Velocity estimator is not used */
			bool EnableVelocityLPF = true; // Velocity LPF is only used if Velocity Estimator is disabled - OBS. This is necessary to avoid sudden angle reference changes due to noise!
			float VelocityLPFcoeffs_a[3] = {1.000000000000000,  -1.713116904140867,   0.749674566393451};	// 40 Hz LPF
			float VelocityLPFcoeffs_b[3] = {0.017796394239482,   0.000964873773620,   0.017796394239482};	// Created using:  [num, den] = cheby2(2,40,40/(Fs/2))

			/* Wheel slip detector parameters */
			bool EnableWheelSlipDetector = true;
			float WheelSlipAccelerationThreshold = 500; // rad/s
			float WheelSlipDetectionTime = 0.015; // 15 ms - wheel slip will be detected if wheel acceleration is above threshold for more than this time
			float WheelSlipIdleTime = 0.100; // after detecting a wheel slip, the wheel acceleration has to be below limit for an idle time before the detection flag is removed
			bool ReduceEquivalentControlAtWheelSlip = true; // uses the wheel slip detector
			bool ReduceQdotAtWheelSlip = true; // uses the wheel slip detector
			bool ReduceTorqueAtWheelSlip = true; // reduces torque for all motors at wheel slip before ramping up again
			bool EnableIndependentHeadingAtWheelSlip = true;
			float WheelSlipIncreaseTime = 0.2; // time to increase the equivalent control and q_dot back from 0% to 100% after wheel slip is no longer detected

			/* Center Of Mass estimator parameters */
			bool EstimateCOM = false;
			float EstimateCOMminVelocity = 0.05; // minimum velocity (checked against estimate) to run COM estimator
			float MaxCOMDeviation = 0.01; // maximum tolerated COM (XY) deviation estimated by COM estimator (given in meters)

			/* Madgwick filter parameters (if used for Quaternion estimation) */
			float MadgwickBeta = 0.02; // 0.02  accelerometer influence magnitude on qDot - the smaller the less accelerometer correction
											  // OBS. Depending on the accelerometer LPF this, increasing this value might feel like the system becomes less agressive,
											  //      since it is weighting the LPF filtered accelerometer more

			/* Accelerometer and Gyroscope sensor covariances */
			// Use these tuning parameters to trust the accelerometer or gyroscope more than the other - eg. to reduce trust in the accelerometer due to induced vibrational noise
			float GyroCov_Tuning_Factor = 1.0;
			float AccelCov_Tuning_Factor = 1.0;

			#if EnableSensorLPFfilters_
				// 250 Hz LPF
				float cov_gyro_mpu[9] = {0.5041E-05f*GyroCov_Tuning_Factor,    0.0094E-05f*GyroCov_Tuning_Factor,    0.0165E-05f*GyroCov_Tuning_Factor,
															0.0094E-05f*GyroCov_Tuning_Factor,    0.5200E-05f*GyroCov_Tuning_Factor,    0.0071E-05f*GyroCov_Tuning_Factor,
															0.0165E-05f*GyroCov_Tuning_Factor,    0.0071E-05f*GyroCov_Tuning_Factor,    0.6499E-05f*GyroCov_Tuning_Factor};
				// 92 Hz LPF
				float cov_acc_mpu[9] = {0.2155E-03f*AccelCov_Tuning_Factor,    0.0056E-03f*AccelCov_Tuning_Factor,    0.0033E-03f*AccelCov_Tuning_Factor,
																		 0.0056E-03f*AccelCov_Tuning_Factor,    0.2247E-03f*AccelCov_Tuning_Factor,    0.0018E-03f*AccelCov_Tuning_Factor,
																		 0.0033E-03f*AccelCov_Tuning_Factor,    0.0018E-03f*AccelCov_Tuning_Factor,    0.5446E-03f*AccelCov_Tuning_Factor};
			#else
				// LPF off
				float cov_gyro_mpu[9] = {0.000496942754176,   0.000020107488666,   0.000003512802761,
						   	   	   	     0.000020107488666,   0.000174919150389,  -0.000025989121108,
										 0.000003512802761,  -0.000025989121108,   0.001396990425282};
			    // LPF off
				float cov_acc_mpu[9] = {0.394508786413515E-03,   0.000603648730082E-03,  -0.023365964974750E-03,
						   	   	   	    0.000603648730082E-03,   0.392207026988784E-03,  -0.003560872957017E-03,
									   -0.023365964974750E-03,  -0.003560872957017E-03,   0.994086382318077E-03};
			#endif

			// MTI sample rate configured to 400 Hz but samples used for covariance estimation only captured at 200 Hz (hence downsampled)
			float cov_gyro_mti[9] = {0.767838569550055E-05,  -0.001550044758582E-05,   0.006121206040185E-05,
					  	  	  	    -0.001550044758582E-05,   0.744576444194164E-05,  -0.003516953093983E-05,
									 0.006121206040185E-05,  -0.003516953093983E-05,   0.795201715550991E-05};
			// MTI sample rate configured to 400 Hz but samples used for covariance estimation only captured at 200 Hz (hence downsampled)
			float cov_acc_mti[9] = {0.143168418480867E-03,   0.025720201380381E-03,   0.013511303535437E-03,
					   	   	   	    0.025720201380381E-03,   0.132103665088956E-03,   0.025679048752216E-03,
							   	    0.013511303535437E-03,   0.025679048752216E-03,   0.141723092884984E-03};

			/* QEKF (Quaternion estimator) tuning parameters */
			float sigma2_bias = 1E-9; // for MPU9250 use 1E-6 or 1E-7 works well, for MTI-200 use 1E-9 or disable bias estimation completely!
			float sigma2_omega = 3.16228e-07; //  (10^(-6.5)) for MPU9250 use 1E-5, for MTI-200 use 1E-2 due to the smaller gyroscope noise magnitude
			float sigma2_heading = 3.3846e-05; // 3*sigma == 1 degree
			float GyroscopeTrustFactor = 1.0; // the higher value the more trust is put into the gyroscope measurements by increasing the accelerometer covariance

			/* Estimator initialization covariances */
			// X_QEKF = {q0, q1, q2, q3,   dq0, dq1, dq2, dq3,   gyro_bias_x, gyro_bias_y}
			float QEKF_P_init_diagonal[11] = {1E-5, 1E-5, 1E-5, 1E-7,   1E-7, 1E-7, 1E-7,   1E-5, 1E-5, 1E-5}; // initialize q3 variance lower than others, since yaw can not be estimated so we are more certain on the initial value to let gyro integration (dead-reckoning) dominate the "yaw" estimate
			float VelocityEstimator_P_init_diagonal[2] = {1E-1, 1E-1}; // initialize velocity estimator covariance
			float COMEstimator_P_init_diagonal[2] = {1E-12, 1E-12}; // initialize COM estimator covariance
			/* Estimator Tuning parameters end */
		} estimator;
		
		struct sensor_t {
			float default_gyroscope_bias[3] = { 0.0,  0.0,  0.0 };

			float default_accelerometer_bias[3] = { 0.1892371,  0.1071601,  0.2585130 };  // 0.2492371,  0.3371601,  0.2585130
			float default_accelerometer_scale[3] = { 0.9829253,  0.9794390,  0.9615759 };

			float default_calibration_matrix[3*3] = {
					1.0,  0.0,  0.0,
					0.0,  1.0,  0.0,
					0.0,  0.0,  1.0
			};
		} sensor;

		struct model_t {
			/* Model parameters (defined in SI units) */
			double pi = 3.14159265358979323846264338327950288;
			float g = 9.82f;

			/* Ball constants */
			float rk = 0.129f;
			float Mk = 1.46f;
			float coating = 4e-3; // 4 mm rubber coating around ball
			float Jk = ((2.f * Mk * (rk-coating)*(rk-coating)) / 3.f);			

			/* Center of Mass */
			// Body center of mass defined with origin in ball center
			/*
			float COM_X = -0.02069e-3;
			float COM_Y = -3.20801e-3;
			float COM_Z = 550.23854e-3 - rk; // subtract rk since the values are extracted from OnShape with origin in contact point (bottom of ball)
			*/
			float l = 0.4213f; // norm(COM)

			float COM_X = 0;
			float COM_Y = 0;
			float COM_Z = l;

			/* Center of rotation - used for velocity estimation */
			float CoR = 0.8720f;

			/* Body constants */
			float Mb = ( 4.31f + 1.844f);
			float Jbx = 3.9096f;
			float Jby = 3.9212f;
			float Jbz = 0.1004f;
		
			/* Wheel and motor physical constants */
			float rw = 0.05f;
			float Mw = 0.270f;
			float i_gear = 13.0f / 3; // gear ratio = 4.3 : 1   (https://www.maxonmotor.com/maxon/view/product/223081)
			float Jow = 9.f * 1E-4;
			float Jm = 1.21f * 1E-4;
			float Jw = (Jow + i_gear*i_gear*Jm);

			/* Friction constants */
			float Bvk = 0*0.001f;
			float Bvm = 0*0.001f;
			float Bvb = 0*0.001f;
			
			/* Encoder constants */
			uint16_t EncoderTicksPrRev = 4*4096;	 // ticks/rev
			float TicksPrRev = i_gear * EncoderTicksPrRev;
			
			/* ESCON motor parameters */
			float MotorMaxCurrent = 15; // ESCON 50/5 motor driver (https://www.maxonmotor.com/maxon/view/product/control/4-Q-Servokontroller/438725)
			float MotorTorqueConstant = 30.5e-3; // Nm / A   (https://www.maxonmotor.com/maxon/view/product/412819)
			float MotorMaxTorque = MotorTorqueConstant * MotorMaxCurrent; // Nm
			float MotorMaxSpeed = 6000 * 2 * pi / 60;  // rad/s of motor (before gearing)  ==  6000 rpm
			float MaxOutputTorque = i_gear * MotorMaxTorque;
			float SaturationTorqueOfMaxOutputTorque = 0.8;
			/* Model parameters end */	
		} model;
		
		struct test_t {
			float tmp = 10;
			float tmp2 = 100;
		} test;


	public:
		Parameters(EEPROM * eeprom = 0, LSPC * com = 0);
		~Parameters();

		void AttachEEPROM(EEPROM * eeprom);
		void AttachLSPC(LSPC * com);

		void Refresh(void);
		void LockForChange(void);
		void UnlockAfterChange(void);

		uint32_t getParameterSizeBytes();

	private:
		void LoadParametersFromEEPROM(EEPROM * eeprom = 0);
		void StoreParameters(void); // stores to EEPROM
		void LookupParameter(uint8_t type, uint8_t param, void ** paramPtr, lspc::ParameterLookup::ValueType_t& valueType, uint8_t& arraySize);

		static void GetParameter_Callback(void * param, const std::vector<uint8_t>& payload);
		static void SetParameter_Callback(void * param, const std::vector<uint8_t>& payload);
		static void StoreParameters_Callback(void * param, const std::vector<uint8_t>& payload);
		static void DumpParameters_Callback(void * param, const std::vector<uint8_t>& payload);

	private:
		EEPROM * eeprom_;
		LSPC * com_;
		SemaphoreHandle_t readSemaphore_;
		SemaphoreHandle_t writeSemaphore_;
		uint32_t changeCounter_;
};
	
#endif
