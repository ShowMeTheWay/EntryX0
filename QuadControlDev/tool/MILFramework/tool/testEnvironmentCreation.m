% ***************************************************************************
% *=====================      Copyright by General Digits      ===============
% ****************************************************************************
% * Title        : testEnvironmentCreation.m
% *
% * Date:        : 01.02.2018
% *
% * Version      : Revision: 1.1
% *
% * Responsible  : Beniamin Costandin
% *
% * Departement  : Software Engineering
% *
% * Description  : This script will create a test harness using the original
%                  model as reference.
% * Implementation description:
%   
% *****************************************************************************

function testEnvironmentCreation( modelReference )

disp('Testharness model creation has been started,please wait...')
%Close open model
close_system([modelReference,'_Test_Harness']);
%% Create a new model to be included in Test Harness.slx
sys = 'TestModel'
new_system(sys)
open_system(sys)

%% Information about the referenced model
%open model
open_system(modelReference)
%get information about input and output blocks in modelReference
handlesIn = find_system(modelReference,'SearchDepth',1,'BlockType','Inport');
handlesOut = find_system(modelReference,'SearchDepth',1,'BlockType','Outport');

%Store the input and output names into arrays
InName = get_param(handlesIn,'Name');
OutName = get_param(handlesOut,'Name');

%get the position of the model
ModelPosition = [ 500   112   770   488];      

%Get the position of all input ports
InputPosition = get_param(handlesIn, 'Position'); 
% Converts the cell array into a matrix
InputPosition = cell2mat(InputPosition); 

%Get the position of all output ports
OutputPosition = get_param(handlesOut, 'Position'); 
% Converts the cell array output a matrix
OutputPosition = cell2mat(OutputPosition); 

%Delta for the position of Status and Data blocks from structs 
PosWorkspace =  [80 65 110 75];
PosDataType =   [225 65 250 75]; 
PosBusCre =     [395 65 430 145];
PosOut =        [485 98 515 112]; 
PosIn =         [55 223 85 237]; 
PosBusSel =     [130 185 165 280]; 
PosToWork =     [325 200 355 220]; 
delta =         [0 70 0 70]; 
deltaInConv =   [90 0 90 0];
            
allPos = {PosWorkspace,PosDataType,PosBusCre,PosOut,PosIn,PosBusSel,PosToWork,delta,deltaInConv};
%count the number of inputs and outputs
NumberOfInputs  = length(handlesIn);
NumberOfOutputs = length(handlesOut);

%% Construct the model
% 1. Create block of the to be referenced Model
add_block('built-in/ModelReference', [sys '/ModelReference'], 'Position', ModelPosition);
set_param('TestModel/ModelReference', 'ModelNameDialog', modelReference); 
set_param('TestModel/ModelReference', 'SimulationMode', 'Normal');

%2. Add blocks for inputs:type check
InputType = get_param(handlesIn,'OutDataTypeStr');

for Inidx=1:NumberOfInputs
    %check input for "Bus:" pattern
    if (strncmp(InputType(Inidx), 'Bus:', 4) == true)
        
        %Input signal with DataType Struct was detected:
        %process struct information
        stStructName = InputType(Inidx);
        stStructName = strsplit(stStructName{1}, 'Bus:');
        structName = stStructName{1,2};
        structContent = evalin('base',structName);
        structNoElements = numel(structContent.Elements);
        
        %-create a subsystem with a bus creator and all struct elements
        add_block('built-in/SubSystem', [sys ['/Subsystem' num2str(Inidx) ]], 'Position', InputPosition(Inidx,:));
        %add an out port
        add_block('built-in/Outport', [sys ['/Subsystem' num2str(Inidx)] ['/Outport' num2str(Inidx)]], 'Position', PosOut);
        %add a bus creator inside the created subsytem
        add_block('built-in/BusCreator', [sys ['/Subsystem' num2str(Inidx)] ['/BusCreator' num2str(Inidx)]], 'Position',PosBusCre,...
            'Inputs', num2str(structNoElements), 'NonVirtualBus', 'on', 'OutDataTypeStr' , [InputType{Inidx,1}]);
        %connect the bus creator with the output
        add_line([sys ['/Subsystem' num2str(Inidx) ] ], ['BusCreator' num2str(Inidx) '/1'],['Outport' num2str(Inidx) '/1'], 'autorouting', 'off'); 
        %recursive function which will complete the structure elements tree
        drawStructTree([sys ['/Subsystem' num2str(Inidx) ]],structContent,['BusCreator' num2str(Inidx)]);     
        
    end
end


end

