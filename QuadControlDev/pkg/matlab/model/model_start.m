clc;clear all; close all;

%% Config path

addpath(genpath('..\..\matlab'));

%% uart data to be sent

UART_tstDataDisplayed = Simulink.Bus;
UART_tstDataDisplayed.Description = 'Uart data to be displayed ';
UART_tstDataDisplayed.HeaderFile = '';
saveVarsTmp{1} = Simulink.BusElement;
saveVarsTmp{1}.Name = 'data1';
saveVarsTmp{1}.DataType = 'double';
saveVarsTmp{1}.Complexity = 'real';
saveVarsTmp{1}.Dimensions = 1;
saveVarsTmp{1}.DimensionsMode = 'Fixed';
saveVarsTmp{1}.SamplingMode = 'Sample based';
saveVarsTmp{1}.SampleTime = -1;
saveVarsTmp{1}(2, 1) = Simulink.BusElement;
saveVarsTmp{1}(2, 1).Name = 'data2';
saveVarsTmp{1}(2, 1).DataType = 'double';
saveVarsTmp{1}(2, 1).Complexity = 'real';
saveVarsTmp{1}(2, 1).Dimensions = 1;
saveVarsTmp{1}(2, 1).DimensionsMode = 'Fixed';
saveVarsTmp{1}(2, 1).SamplingMode = 'Sample based';
saveVarsTmp{1}(2, 1).SampleTime = -1;
saveVarsTmp{1}(3, 1) = Simulink.BusElement;
saveVarsTmp{1}(3, 1).Name = 'data3';
saveVarsTmp{1}(3, 1).DataType = 'double';
saveVarsTmp{1}(3, 1).Complexity = 'real';
saveVarsTmp{1}(3, 1).Dimensions = 1;
saveVarsTmp{1}(3, 1).DimensionsMode = 'Fixed';
saveVarsTmp{1}(3, 1).SamplingMode = 'Sample based';
saveVarsTmp{1}(3, 1).SampleTime = -1;
saveVarsTmp{1}(4, 1) = Simulink.BusElement;
saveVarsTmp{1}(4, 1).Name = 'data4';
saveVarsTmp{1}(4, 1).DataType = 'double';
saveVarsTmp{1}(4, 1).Complexity = 'real';
saveVarsTmp{1}(4, 1).Dimensions = 1;
saveVarsTmp{1}(4, 1).DimensionsMode = 'Fixed';
saveVarsTmp{1}(4, 1).SamplingMode = 'Sample based';
saveVarsTmp{1}(4, 1).SampleTime = -1;
UART_tstDataDisplayed.Elements = saveVarsTmp{1};
clear saveVarsTmp;

%% controller output 1
Set_HMI_UartDataOut = mpt.Signal;
Set_HMI_UartDataOut.RTWInfo.StorageClass = 'Custom';
Set_HMI_UartDataOut.RTWInfo.Alias = '';
Set_HMI_UartDataOut.RTWInfo.CustomStorageClass = 'GetSet';
Set_HMI_UartDataOut.RTWInfo.CustomAttributes.HeaderFile = 'SimulinkAdapt.h';
Set_HMI_UartDataOut.RTWInfo.CustomAttributes.GetFunction = 'Get_vNotUsed';
Set_HMI_UartDataOut.RTWInfo.CustomAttributes.SetFunction = 'UART_DisplayData';
Set_HMI_UartDataOut.Description = '';
Set_HMI_UartDataOut.DataType = 'Bus: UART_tstDataDisplayed';
Set_HMI_UartDataOut.Min = -Inf;
Set_HMI_UartDataOut.Max = Inf;
Set_HMI_UartDataOut.DocUnits = '';
Set_HMI_UartDataOut.Dimensions = 1;
Set_HMI_UartDataOut.DimensionsMode = 'auto';
Set_HMI_UartDataOut.Complexity = 'auto';
Set_HMI_UartDataOut.SampleTime = -1;
Set_HMI_UartDataOut.SamplingMode = 'auto';
Set_HMI_UartDataOut.InitialValue = '';


%% controller output 2
SET_Rectangle = mpt.Signal;
SET_Rectangle.RTWInfo.StorageClass = 'Custom';
SET_Rectangle.RTWInfo.Alias = '';
SET_Rectangle.RTWInfo.CustomStorageClass = 'GetSet';
SET_Rectangle.RTWInfo.CustomAttributes.HeaderFile = 'uart_interface.h';
SET_Rectangle.RTWInfo.CustomAttributes.GetFunction = 'Get_vNotUsed';
SET_Rectangle.RTWInfo.CustomAttributes.SetFunction = 'UART_DisplayData';
SET_Rectangle.Description = '';
SET_Rectangle.DataType = 'double';
SET_Rectangle.Min = -Inf;
SET_Rectangle.Max = Inf;
SET_Rectangle.DocUnits = '';
SET_Rectangle.Dimensions = 2;
SET_Rectangle.DimensionsMode = 'auto';
SET_Rectangle.Complexity = 'auto';
SET_Rectangle.SampleTime = -1;
SET_Rectangle.SamplingMode = 'auto';
SET_Rectangle.InitialValue = '';

