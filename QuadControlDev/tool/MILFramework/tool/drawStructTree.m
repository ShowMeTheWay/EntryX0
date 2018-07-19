% ***************************************************************************
% *=====================      Copyright by General Digits      ===============
% ****************************************************************************
% * Title        : drawStructTree.m
% *
% * Date:        : 01.02.2018
% *
% * Version      : Revision: 1.1
% *
% * Responsible  : Beniamin Costandin
% *
% * Departement  : Software Engineering
% *
% * Description  : This is an recursive function which based on the
%                  structure elements will construct the necessary input
%                  blocks needed by the simulink model harness.
% Input: 1: simulink model name
%        2: structure content           
%        3: simulink bus creator name
% *****************************************************************************


function drawStructTree(sys,structContent,busName)

PosBusCre =     [395 65 430 145];
PosOut =        [485 98 515 112]; 
busBlockPOS = get_param([sys ['/' busName]], 'position');
structNoElements = numel(structContent.Elements);
%loop through all elements of the structure
d_h = (busBlockPOS(4)-busBlockPOS(2))/structNoElements;
for structLoopidx = 1:structNoElements
    
    elemName = structContent.Elements(structLoopidx,:).Name;
    elemData = structContent.Elements(structLoopidx,:).DataType;
    drawPos = [busBlockPOS(1)-70 busBlockPOS(2)+d_h*(structLoopidx-1) busBlockPOS(3)-50 busBlockPOS(2)+d_h*(structLoopidx)];
    if (strncmp(elemData, 'Bus:', 4) == true)
        
        add_block('built-in/SubSystem', [sys '/Subsystem_' elemName], 'Position',drawPos);
        
        newSys = [sys '/Subsystem_' elemName];

        newStructName = strsplit(elemData, 'Bus:');
        newStructName = newStructName{1,2};
        newStructContent = evalin('base',newStructName);
        newStructNoElements = numel(newStructContent.Elements);
            
        add_block('built-in/BusCreator',[ newSys ['/BusCreator_' elemName]], 'Position',PosBusCre,...
                  'Inputs', num2str(newStructNoElements), 'NonVirtualBus', 'on', 'OutDataTypeStr' ,elemData);
        add_block('built-in/Outport', [newSys '/Outport'], 'Position', PosOut);
        add_line(sys,[['Subsystem_' elemName] '/1'], [busName '/' num2str(structLoopidx)], 'autorouting', 'off');
        add_line(newSys,[['BusCreator_' elemName] '/1'], ['Outport' '/1'], 'autorouting', 'off');
        
        drawStructTree(newSys,newStructContent,['BusCreator_' elemName]);
    else
        add_block('built-in/From Workspace',[sys ['/From Workspace_' elemName '_box']] ,'Position',drawPos,...
          'VariableName', ['[t,' elemName '_in]'], 'SampleTime' , 'sim_tein', 'Interpolate', 'off', 'OutputAfterFinalValue', 'Holding final');
      add_line(sys,[['From Workspace_' elemName '_box'] '/1'], [busName '/' num2str(structLoopidx)], 'autorouting', 'off');
    end
end


end

