function  ConfigureModel( sys )


%open model
open_system(sys);
%set the target link file
set_param(sys, 'SystemTargetFile', 'ert.tlc');
%Set shared utils option to Auto (Code is generated into c-file and not into separate file.)
set_param(sys, 'UtilityFuncGeneration', 'Auto');



 %generate raport
 set_param(sys, 'GenerateReport', 'on');
 set_param(sys, 'IncludeHyperlinkInReport', 'on');
 set_param(sys, 'GenerateTraceInfo', 'on');
 set_param(sys, 'GenerateTraceReport', 'on');
 set_param(sys, 'GenerateTraceReportSl', 'on');
 set_param(sys, 'GenerateTraceReportSf', 'on');
 set_param(sys, 'GenerateTraceReportEml', 'on');
 
 disp('Setting configuration parameters...');

 %Save all configurations
 save_system(sys);

 %Generate code
 disp('Start code generation...');
 rtwbuild(sys);
 
 %Close sys
 close_system(sys);
 disp('Code has been generated successfully...');%% Copy generated file to 'core' directory
%Add upper directory path
addpath(genpath('../'));
%Check if folder core folder exists
if(exist('../source') ~= 7)
    %Create new folder
    mkdir('../source');
end;
%%Check if the expected code files are available
%Check if model.c file is available
if(exist([sys, '_ert_rtw/', sys,'.c']) == 2)
    copyfile([sys, '_ert_rtw/', sys,'.c'],'../source');
    delete([sys, '_ert_rtw/', sys,'.c']);
    disp([sys,'.c - successfully copied']);
else
    disp([sys,'.c not available - has not been copied']);
end;
%Check if model.h file is available
if(exist([sys, '_ert_rtw/', sys,'.h']) == 2)
    copyfile([sys, '_ert_rtw/', sys,'.h'],'../source/');
    delete([sys, '_ert_rtw/', sys,'.h']);
    disp([sys,'.h - successfully copied']);
else
    disp([sys,'.h not available - has not been copied']);
end;
%Check if model_data.c file is available
if(exist([sys, '_ert_rtw/', sys,'_data.c']) == 2)
    copyfile([sys, '_ert_rtw/', sys,'_data.c'],'../source');
    delete([sys, '_ert_rtw/', sys,'_data.c']);
    disp([sys,'_data.c - successfully copied']);
else
    %Check if from former code generation file was available
    if(exist(['../source/', sys,'_data.c']) == 2)
        delete(['../source', sys,'_data.c']);
        disp(['Old ', sys,'_data.c has been deleted.']);
        h = msgbox(['Old "_data.c" - file has been deleted']);
    end;
end;
%Check if model_private.h file is available
if(exist([sys, '_ert_rtw/', sys,'_private.h']) == 2)
    copyfile([sys, '_ert_rtw/', sys,'_private.h'],'../source');
    delete([sys, '_ert_rtw/', sys,'_private.h']);
    disp([sys,'_private.h - successfully copied']);
else
    %Check if from former code generation file was available
    if(exist(['../source/', sys,'_private.h']) == 2)
        delete(['../source', sys,'_private.h']);
        disp(['Old ', sys,'_private.h has been deleted.']);
        h = msgbox(['Old "_private.h" - file has been deleted']);
    end;
end;
%Check if model_types.h file is available
if(exist([sys, '_ert_rtw/', sys,'_types.h']) == 2)
    copyfile([sys, '_ert_rtw/', sys,'_types.h'],'../source');
    delete([sys, '_ert_rtw/', sys,'_types.h']);
    disp([sys,'_types.h - successfully copied']);
else
    %Check if from former code generation file was available
    if(exist(['../source/', sys,'_types.h']) == 2)
        delete(['../source/', sys,'_types.h']);
        disp(['Old ', sys,'_types.h has been deleted.']);
        h = msgbox(['Old "_types.h" - file has been deleted']);
    end;
end;

%Check if rtwtypes.h file is available
if(exist([sys, '_ert_rtw/', 'rtw','types.h']) == 2)
    copyfile([sys, '_ert_rtw/', 'rtw','types.h'],'../source');
    delete([sys, '_ert_rtw/', 'rtw','types.h']);
    disp(['rtw','types.h - successfully copied']);
else
    %Check if from former code generation file was available
    if(exist(['../source/', 'rtw','types.h']) == 2)
        delete(['../source/', 'rtw','types.h']);
        disp(['Old ', 'rtw','types.h has been deleted.']);
        h = msgbox(['Old "types.h" - file has been deleted']);
    end;
end;

delete([sys, '_ert_rtw/','ert_main.c']);
%Delete upper directory path
rmpath('../');
disp('All Files have been generated and successfully copied to ../source.');
end

