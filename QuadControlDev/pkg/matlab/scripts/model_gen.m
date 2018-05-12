%******************************************************************
% Description: Automatic code generation                         **
% Created by: Beniamin Costandin                                 ** 
% Revision: 1.0                                                  **
% Automatic code generation for Quad Entry                       **
%******************************************************************  
clc;clear all;
disp('Press 1 to generate code from Quad_model');
Text = 'Enter the number = ';
option_nr = input(Text);

if (option_nr == 1)
    disp('Preparing for code generation...');
   % addpath(genpath('../model'));  
    cd '../model'
    model_start; %run all definitions
    
    ConfigureModel('model');
else
    disp('Try again,please choose the corect input');
end




