/*
 * mpu_6050.h
 *
 */

#ifndef MPU_6050_H_
#define MPU_6050_H_

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
#define mpu_6050_pwr_mgmnt_1 107
#define mpu_6050_user_ctrl 106
#define mpu_6050_sig_path_rst 104

#define mpu_6050_adress 0b1101000

#define init_byte_107 0b00001000
#define init_byte_106 0b00000001
#define init_byte_104 0b00000111

#endif /* MPU_6050_H_ */
