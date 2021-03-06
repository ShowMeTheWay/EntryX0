clc;clear all; close all;

%% Config path

%% uart data to be sent

IMU_tstRawData = Simulink.Bus;
IMU_tstRawData.Description = 'Uart data to be displayed ';
IMU_tstRawData.DataScope = 'Auto';
IMU_tstRawData.HeaderFile = '';
saveVarsTmp{1} = Simulink.BusElement;
saveVarsTmp{1}.Name = 'AccXDataS';
saveVarsTmp{1}.DataType = 'double';
saveVarsTmp{1}.Complexity = 'real';
saveVarsTmp{1}.Dimensions = 1;
saveVarsTmp{1}.DimensionsMode = 'Fixed';
saveVarsTmp{1}.SamplingMode = 'Sample based';
saveVarsTmp{1}.SampleTime = -1;
saveVarsTmp{1}(2, 1) = Simulink.BusElement;
saveVarsTmp{1}(2, 1).Name = 'AccYDataS';
saveVarsTmp{1}(2, 1).DataType = 'double';
saveVarsTmp{1}(2, 1).Complexity = 'real';
saveVarsTmp{1}(2, 1).Dimensions = 1;
saveVarsTmp{1}(2, 1).DimensionsMode = 'Fixed';
saveVarsTmp{1}(2, 1).SamplingMode = 'Sample based';
saveVarsTmp{1}(2, 1).SampleTime = -1;
saveVarsTmp{1}(3, 1) = Simulink.BusElement;
saveVarsTmp{1}(3, 1).Name = 'AccZDataS';
saveVarsTmp{1}(3, 1).DataType = 'double';
saveVarsTmp{1}(3, 1).Complexity = 'real';
saveVarsTmp{1}(3, 1).Dimensions = 1;
saveVarsTmp{1}(3, 1).DimensionsMode = 'Fixed';
saveVarsTmp{1}(3, 1).SamplingMode = 'Sample based';
saveVarsTmp{1}(3, 1).SampleTime = -1;
saveVarsTmp{1}(4, 1) = Simulink.BusElement;
saveVarsTmp{1}(4, 1).Name = 'GyroXDataS';
saveVarsTmp{1}(4, 1).DataType = 'double';
saveVarsTmp{1}(4, 1).Complexity = 'real';
saveVarsTmp{1}(4, 1).Dimensions = 1;
saveVarsTmp{1}(4, 1).DimensionsMode = 'Fixed';
saveVarsTmp{1}(4, 1).SamplingMode = 'Sample based';
saveVarsTmp{1}(4, 1).SampleTime = -1;
saveVarsTmp{1}(5, 1) = Simulink.BusElement;
saveVarsTmp{1}(5, 1).Name = 'GyroYDataS';
saveVarsTmp{1}(5, 1).DataType = 'double';
saveVarsTmp{1}(5, 1).Complexity = 'real';
saveVarsTmp{1}(5, 1).Dimensions = 1;
saveVarsTmp{1}(5, 1).DimensionsMode = 'Fixed';
saveVarsTmp{1}(5, 1).SamplingMode = 'Sample based';
saveVarsTmp{1}(5, 1).SampleTime = -1;
saveVarsTmp{1}(6, 1) = Simulink.BusElement;
saveVarsTmp{1}(6, 1).Name = 'GyroZDataS';
saveVarsTmp{1}(6, 1).DataType = 'double';
saveVarsTmp{1}(6, 1).Complexity = 'real';
saveVarsTmp{1}(6, 1).Dimensions = 1;
saveVarsTmp{1}(6, 1).DimensionsMode = 'Fixed';
saveVarsTmp{1}(6, 1).SamplingMode = 'Sample based';
saveVarsTmp{1}(6, 1).SampleTime = -1;
saveVarsTmp{1}(7, 1) = Simulink.BusElement;
saveVarsTmp{1}(7, 1).Name = 'q0';
saveVarsTmp{1}(7, 1).DataType = 'double';
saveVarsTmp{1}(7, 1).Complexity = 'real';
saveVarsTmp{1}(7, 1).Dimensions = 1;
saveVarsTmp{1}(7, 1).DimensionsMode = 'Fixed';
saveVarsTmp{1}(7, 1).SamplingMode = 'Sample based';
saveVarsTmp{1}(7, 1).SampleTime = -1;
saveVarsTmp{1}(8, 1) = Simulink.BusElement;
saveVarsTmp{1}(8, 1).Name = 'q1';
saveVarsTmp{1}(8, 1).DataType = 'double';
saveVarsTmp{1}(8, 1).Complexity = 'real';
saveVarsTmp{1}(8, 1).Dimensions = 1;
saveVarsTmp{1}(8, 1).DimensionsMode = 'Fixed';
saveVarsTmp{1}(8, 1).SamplingMode = 'Sample based';
saveVarsTmp{1}(8, 1).SampleTime = -1;
saveVarsTmp{1}(9, 1) = Simulink.BusElement;
saveVarsTmp{1}(9, 1).Name = 'q2';
saveVarsTmp{1}(9, 1).DataType = 'double';
saveVarsTmp{1}(9, 1).Complexity = 'real';
saveVarsTmp{1}(9, 1).Dimensions = 1;
saveVarsTmp{1}(9, 1).DimensionsMode = 'Fixed';
saveVarsTmp{1}(9, 1).SamplingMode = 'Sample based';
saveVarsTmp{1}(9, 1).SampleTime = -1;
saveVarsTmp{1}(10, 1) = Simulink.BusElement;
saveVarsTmp{1}(10, 1).Name = 'q3';
saveVarsTmp{1}(10, 1).DataType = 'double';
saveVarsTmp{1}(10, 1).Complexity = 'real';
saveVarsTmp{1}(10, 1).Dimensions = 1;
saveVarsTmp{1}(10, 1).DimensionsMode = 'Fixed';
saveVarsTmp{1}(10, 1).SamplingMode = 'Sample based';
saveVarsTmp{1}(10, 1).SampleTime = -1;
saveVarsTmp{1}(11, 1) = Simulink.BusElement;
saveVarsTmp{1}(11, 1).Name = 'th';
saveVarsTmp{1}(11, 1).DataType = 'double';
saveVarsTmp{1}(11, 1).Complexity = 'real';
saveVarsTmp{1}(11, 1).Dimensions = 1;
saveVarsTmp{1}(11, 1).DimensionsMode = 'Fixed';
saveVarsTmp{1}(11, 1).SamplingMode = 'Sample based';
saveVarsTmp{1}(11, 1).SampleTime = -1;
saveVarsTmp{1}(12, 1) = Simulink.BusElement;
saveVarsTmp{1}(12, 1).Name = 'ch';
saveVarsTmp{1}(12, 1).DataType = 'double';
saveVarsTmp{1}(12, 1).Complexity = 'real';
saveVarsTmp{1}(12, 1).Dimensions = 1;
saveVarsTmp{1}(12, 1).DimensionsMode = 'Fixed';
saveVarsTmp{1}(12, 1).SamplingMode = 'Sample based';
saveVarsTmp{1}(12, 1).SampleTime = -1;
saveVarsTmp{1}(13, 1) = Simulink.BusElement;
saveVarsTmp{1}(13, 1).Name = 'ph';
saveVarsTmp{1}(13, 1).DataType = 'double';
saveVarsTmp{1}(13, 1).Complexity = 'real';
saveVarsTmp{1}(13, 1).Dimensions = 1;
saveVarsTmp{1}(13, 1).DimensionsMode = 'Fixed';
saveVarsTmp{1}(13, 1).SamplingMode = 'Sample based';
saveVarsTmp{1}(13, 1).SampleTime = -1;
IMU_tstRawData.Elements = saveVarsTmp{1};

clear saveVarsTmp;

IMU_tstInRawData = Simulink.Bus;
IMU_tstInRawData.Description = 'Uart data to be displayed ';
IMU_tstInRawData.DataScope = 'Imported'
IMU_tstInRawData.HeaderFile = 'genDigitsEst.h';
saveVarsTmp{1} = Simulink.BusElement;
saveVarsTmp{1}.Name = 'AccXData';
saveVarsTmp{1}.DataType = 'double';
saveVarsTmp{1}.Complexity = 'real';
saveVarsTmp{1}.Dimensions = 1;
saveVarsTmp{1}.DimensionsMode = 'Fixed';
saveVarsTmp{1}.SamplingMode = 'Sample based';
saveVarsTmp{1}.SampleTime = -1;
saveVarsTmp{1}(2, 1) = Simulink.BusElement;
saveVarsTmp{1}(2, 1).Name = 'AccYData';
saveVarsTmp{1}(2, 1).DataType = 'double';
saveVarsTmp{1}(2, 1).Complexity = 'real';
saveVarsTmp{1}(2, 1).Dimensions = 1;
saveVarsTmp{1}(2, 1).DimensionsMode = 'Fixed';
saveVarsTmp{1}(2, 1).SamplingMode = 'Sample based';
saveVarsTmp{1}(2, 1).SampleTime = -1;
saveVarsTmp{1}(3, 1) = Simulink.BusElement;
saveVarsTmp{1}(3, 1).Name = 'AccZData';
saveVarsTmp{1}(3, 1).DataType = 'double';
saveVarsTmp{1}(3, 1).Complexity = 'real';
saveVarsTmp{1}(3, 1).Dimensions = 1;
saveVarsTmp{1}(3, 1).DimensionsMode = 'Fixed';
saveVarsTmp{1}(3, 1).SamplingMode = 'Sample based';
saveVarsTmp{1}(3, 1).SampleTime = -1;
saveVarsTmp{1}(4, 1) = Simulink.BusElement;
saveVarsTmp{1}(4, 1).Name = 'GyroXData';
saveVarsTmp{1}(4, 1).DataType = 'double';
saveVarsTmp{1}(4, 1).Complexity = 'real';
saveVarsTmp{1}(4, 1).Dimensions = 1;
saveVarsTmp{1}(4, 1).DimensionsMode = 'Fixed';
saveVarsTmp{1}(4, 1).SamplingMode = 'Sample based';
saveVarsTmp{1}(4, 1).SampleTime = -1;
saveVarsTmp{1}(5, 1) = Simulink.BusElement;
saveVarsTmp{1}(5, 1).Name = 'GyroYData';
saveVarsTmp{1}(5, 1).DataType = 'double';
saveVarsTmp{1}(5, 1).Complexity = 'real';
saveVarsTmp{1}(5, 1).Dimensions = 1;
saveVarsTmp{1}(5, 1).DimensionsMode = 'Fixed';
saveVarsTmp{1}(5, 1).SamplingMode = 'Sample based';
saveVarsTmp{1}(5, 1).SampleTime = -1;
saveVarsTmp{1}(6, 1) = Simulink.BusElement;
saveVarsTmp{1}(6, 1).Name = 'GyroZData';
saveVarsTmp{1}(6, 1).DataType = 'double';
saveVarsTmp{1}(6, 1).Complexity = 'real';
saveVarsTmp{1}(6, 1).Dimensions = 1;
saveVarsTmp{1}(6, 1).DimensionsMode = 'Fixed';
saveVarsTmp{1}(6, 1).SamplingMode = 'Sample based';
saveVarsTmp{1}(6, 1).SampleTime = -1;
IMU_tstInRawData.Elements = saveVarsTmp{1};
clear saveVarsTmp;

IMU_tstQuaternion = Simulink.Bus;
IMU_tstQuaternion.Description = 'Quaternion format ';
IMU_tstQuaternion.HeaderFile = '';
saveVarsTmp{1} = Simulink.BusElement;
saveVarsTmp{1}.Name = 'q0';
saveVarsTmp{1}.DataType = 'double';
saveVarsTmp{1}.Complexity = 'real';
saveVarsTmp{1}.Dimensions = 1;
saveVarsTmp{1}.DimensionsMode = 'Fixed';
saveVarsTmp{1}.SamplingMode = 'Sample based';
saveVarsTmp{1}.SampleTime = -1;
saveVarsTmp{1}(2, 1) = Simulink.BusElement;
saveVarsTmp{1}(2, 1).Name = 'q1';
saveVarsTmp{1}(2, 1).DataType = 'double';
saveVarsTmp{1}(2, 1).Complexity = 'real';
saveVarsTmp{1}(2, 1).Dimensions = 1;
saveVarsTmp{1}(2, 1).DimensionsMode = 'Fixed';
saveVarsTmp{1}(2, 1).SamplingMode = 'Sample based';
saveVarsTmp{1}(2, 1).SampleTime = -1;
saveVarsTmp{1}(3, 1) = Simulink.BusElement;
saveVarsTmp{1}(3, 1).Name = 'q2';
saveVarsTmp{1}(3, 1).DataType = 'double';
saveVarsTmp{1}(3, 1).Complexity = 'real';
saveVarsTmp{1}(3, 1).Dimensions = 1;
saveVarsTmp{1}(3, 1).DimensionsMode = 'Fixed';
saveVarsTmp{1}(3, 1).SamplingMode = 'Sample based';
saveVarsTmp{1}(3, 1).SampleTime = -1;
saveVarsTmp{1}(4, 1) = Simulink.BusElement;
saveVarsTmp{1}(4, 1).Name = 'q3';
saveVarsTmp{1}(4, 1).DataType = 'double';
saveVarsTmp{1}(4, 1).Complexity = 'real';
saveVarsTmp{1}(4, 1).Dimensions = 1;
saveVarsTmp{1}(4, 1).DimensionsMode = 'Fixed';
saveVarsTmp{1}(4, 1).SamplingMode = 'Sample based';
saveVarsTmp{1}(4, 1).SampleTime = -1;
IMU_tstQuaternion.Elements = saveVarsTmp{1};
clear saveVarsTmp;

%% controller output 
Set_HMI_UartDataOut = mpt.Signal;
Set_HMI_UartDataOut.RTWInfo.StorageClass = 'Custom';
Set_HMI_UartDataOut.RTWInfo.Alias = '';
Set_HMI_UartDataOut.RTWInfo.CustomStorageClass = 'GetSet';
Set_HMI_UartDataOut.RTWInfo.CustomAttributes.HeaderFile = 'mdlSensInterface.h';
Set_HMI_UartDataOut.RTWInfo.CustomAttributes.GetFunction = 'Get_vNotUsed';
Set_HMI_UartDataOut.RTWInfo.CustomAttributes.SetFunction = 'UART_DisplayData';
Set_HMI_UartDataOut.Description = '';
Set_HMI_UartDataOut.DataType = 'Bus: IMU_tstRawData';
Set_HMI_UartDataOut.Min = -Inf;
Set_HMI_UartDataOut.Max = Inf;
Set_HMI_UartDataOut.DocUnits = '';
Set_HMI_UartDataOut.Dimensions = 1;
Set_HMI_UartDataOut.DimensionsMode = 'auto';
Set_HMI_UartDataOut.Complexity = 'auto';
Set_HMI_UartDataOut.SampleTime = -1;
Set_HMI_UartDataOut.SamplingMode = 'auto';
Set_HMI_UartDataOut.InitialValue = '';


%% controller in
GET_stIMUData_in = mpt.Signal;
GET_stIMUData_in.RTWInfo.StorageClass = 'Custom';
GET_stIMUData_in.RTWInfo.Alias = '';
GET_stIMUData_in.RTWInfo.CustomStorageClass = 'GetSet';
GET_stIMUData_in.RTWInfo.CustomAttributes.HeaderFile = 'imu.h';
GET_stIMUData_in.RTWInfo.CustomAttributes.GetFunction = 'GetData__stMPU_9255';
GET_stIMUData_in.RTWInfo.CustomAttributes.SetFunction = 'Set_vNotUsed';
GET_stIMUData_in.Description = '';
GET_stIMUData_in.DataType = 'Bus: IMU_tstInRawData';
GET_stIMUData_in.Min = -Inf;
GET_stIMUData_in.Max = Inf;
GET_stIMUData_in.DocUnits = '';
GET_stIMUData_in.Dimensions = 1;
GET_stIMUData_in.DimensionsMode = 'auto';
GET_stIMUData_in.Complexity = 'auto';
GET_stIMUData_in.SampleTime = -1;
GET_stIMUData_in.SamplingMode = 'auto';
GET_stIMUData_in.InitialValue = '';

%% quaternion madgwick
Set_Quaternion_UartDataOut = mpt.Signal;
Set_Quaternion_UartDataOut.RTWInfo.StorageClass = 'Custom';
Set_Quaternion_UartDataOut.RTWInfo.Alias = '';
Set_Quaternion_UartDataOut.RTWInfo.CustomStorageClass = 'GetSet';
Set_Quaternion_UartDataOut.RTWInfo.CustomAttributes.HeaderFile = 'mdlSensInterface.h';
Set_Quaternion_UartDataOut.RTWInfo.CustomAttributes.GetFunction = 'Get_vNotUsed';
Set_Quaternion_UartDataOut.RTWInfo.CustomAttributes.SetFunction = 'UART_DisplayData';
Set_Quaternion_UartDataOut.Description = '';
Set_Quaternion_UartDataOut.DataType = 'Bus: IMU_tstQuaternion';
Set_Quaternion_UartDataOut.Min = -Inf;
Set_Quaternion_UartDataOut.Max = Inf;
Set_Quaternion_UartDataOut.DocUnits = '';
Set_Quaternion_UartDataOut.Dimensions = 1;
Set_Quaternion_UartDataOut.DimensionsMode = 'auto';
Set_Quaternion_UartDataOut.Complexity = 'auto';
Set_Quaternion_UartDataOut.SampleTime = -1;
Set_Quaternion_UartDataOut.SamplingMode = 'auto';
Set_Quaternion_UartDataOut.InitialValue = '';

%%
GetBtnState = mpt.Signal;
GetBtnState.RTWInfo.StorageClass = 'Custom';
GetBtnState.RTWInfo.Alias = '';
GetBtnState.RTWInfo.CustomStorageClass = 'GetSet';
GetBtnState.RTWInfo.CustomAttributes.HeaderFile = 'mdlSensInterface.h';
GetBtnState.RTWInfo.CustomAttributes.GetFunction = 'GetButtonState';
GetBtnState.RTWInfo.CustomAttributes.SetFunction = 'Set_vNotUsed';
GetBtnState.Description = '';
GetBtnState.DataType = 'uint8';
GetBtnState.Min = -Inf;
GetBtnState.Max = Inf;
GetBtnState.DocUnits = '';
GetBtnState.Dimensions = 1;
GetBtnState.DimensionsMode = 'auto';
GetBtnState.Complexity = 'auto';
GetBtnState.SampleTime = -1;
GetBtnState.SamplingMode = 'auto';
GetBtnState.InitialValue = '';

%%
SetLedState = mpt.Signal;
SetLedState.RTWInfo.StorageClass = 'Custom';
SetLedState.RTWInfo.Alias = '';
SetLedState.RTWInfo.CustomStorageClass = 'GetSet';
SetLedState.RTWInfo.CustomAttributes.HeaderFile = 'mdlSensInterface.h';
SetLedState.RTWInfo.CustomAttributes.GetFunction = 'Get_vNotUsed';
SetLedState.RTWInfo.CustomAttributes.SetFunction = 'SetLedState';
SetLedState.Description = '';
SetLedState.DataType = 'uint8';
SetLedState.Min = -Inf;
SetLedState.Max = Inf;
SetLedState.DocUnits = '';
SetLedState.Dimensions = 1;
SetLedState.DimensionsMode = 'auto';
SetLedState.Complexity = 'auto';
SetLedState.SampleTime = -1;
SetLedState.SamplingMode = 'auto';
SetLedState.InitialValue = '';


