/*
 * mpu_6050.h
 *
 */

#ifndef MPU_6050_H_
#define MPU_6050_H_

//#define MPU_6050

#ifdef MPU_6050
	#define mpu_6050_smprt_div 25
	#define mpu_6050_config 26
	#define mpu_6050_gyro_config 27
	#define mpu_6050_accel_config 28
	#define mpu_6050_int_enable 56
	#define mpu_6050_int_status 58

	#define mpu_6050_accel_x_h 59
	#define mpu_6050_accel_x_l 60
	#define mpu_6050_accel_y_h 61
	#define mpu_6050_accel_y_l 62
	#define mpu_6050_accel_z_h 63
	#define mpu_6050_accel_z_l 64

	#define mpu_6050_temp_h 65
	#define mpu_6050_temp_l 66

	#define mpu_6050_gyro_x_h 67
	#define mpu_6050_gyro_x_l 68
	#define mpu_6050_gyro_y_h 69
	#define mpu_6050_gyro_y_l 70
	#define mpu_6050_gyro_z_h 71
	#define mpu_6050_gyro_z_l 72

	#define mpu_6050_who_am_I 117
	#define mpu_6050_pwr_mgmnt_1 107 //0x6B
	#define mpu_6050_user_ctrl 106
	#define mpu_6050_sig_path_rst 104

	#define mpu_6050_adress 0b1101000 // 0x68

	#define init_byte_107 0b00001000
	#define init_byte_106 0b00000001
	#define init_byte_104 0b00000111
#else
	#define mpu_6050_smprt_div 25
	#define MPU_6050_CONFIG 26 //0x1A
	#define MPU_9255_GYRO_CONFIG 27 //0x1B
	#define MPU_9255_ACCEL_CONFIG_1 28
	#define MPU_9255_ACCEL_CONFIG_2 29 //0x1D
	#define MPU_9255_INT_BYPASS_CONFIG 55 //0x37
	#define mpu_6050_int_enable 56
	#define mpu_6050_int_status 58
	#define MPU_9255_ACCEL_X_H 59
	#define mpu_6050_accel_x_l 60
	#define mpu_6050_accel_y_h 61
	#define mpu_6050_accel_y_l 62
	#define mpu_6050_accel_z_h 63
	#define mpu_6050_accel_z_l 64
	#define mpu_6050_temp_h 65
	#define mpu_6050_temp_l 66
	#define mpu_6050_gyro_x_h 67
	#define mpu_6050_gyro_x_l 68
	#define mpu_6050_gyro_y_h 69
	#define mpu_6050_gyro_y_l 70
	#define mpu_6050_gyro_z_h 71
	#define mpu_6050_gyro_z_l 72
	#define mpu_6050_who_am_I 117
	#define MPU_9255_PWR_MGMNT_1 107 //0x6B
	#define MPU_9255_USER_CTRL 106 //0x6A
	#define mpu_6050_sig_path_rst 104
	#define MPU_9255_MAG_CONTROL_CONFIG 10 //0x0A
	#define MPU_9255_MAG_ASAX_CONFIG 16 //0x10
	#define MPU_9255_MAG_STATUS_1_CONFIG 2 //0x02

	#define MPU_9255_ADDRESS 0x68 //0b1101000
	#define MPU_9255_AK8963_DEVICE_ID 0x0C//0x48
	#define MPU_9255_DATA_READY_MASK 0x01
	#define MPU_9255_DATA_READY 0x01
	#define MPU_9255_MAGIC_OVERFLOW_MASK 0x8
	#define MPU_9255_MAG_HXL_AD 0x03


	#define INIT_BYTE_107 0b00000001   //0b00000001
	#define INIT_BYTE_28 0b00001000
	#define init_byte_106 0b00000001
	#define init_byte_104 0b00000111
	#define INIT_BYTE_27 0b00001000
	#define INIT_BYTE_29 0b00000101
	#define INIT_BYTE_26 0b00000101
	#define INIT_BYTE_106 0b00000000
	#define INIT_BYTE_55 0b00000010
	#define INIT_BYTE_MAG_10 0b00011111 //fuse mode
	#define RESET_BYTE_MAG_10 0b00000000 //reset
	#define RESET_BYTE_MAG_MODE2_10 0b00010110 //continuous mode 2 at 100Hz and 16 bit output
#endif


#endif /* MPU_6050_H_ */

