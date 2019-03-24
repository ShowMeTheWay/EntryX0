clear all; close all;

addpath(genpath('..\..\scripts'));

%run all definitions for sens adapt
SensAdapt_start;

% generate code for sens adapt
ConfigureModel('mariusTest');


