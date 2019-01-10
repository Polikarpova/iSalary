@echo off
echo %message%

set root=.
if "%~1" == "" ( echo "default dir ./") else ( set root=%1%)
if %root:~-1%==/ ( set root=%root:~0,-1%)
if %root:~-1%==\ ( set root=%root:~0,-1%)
echo %root%
echo " find in %root%/iSalary/"
echo " format to %root%/iSalary/formated"
mkdir "%root%/iSalary/formated"
for %%f in (%root%/iSalary/*.cpp %root%/iSalary/*.h) do (

    rem
    echo "%%f"
    "%root%/clang_format" "%root%/iSalary/%%f" > "%root%/iSalary/formated/%%f"
	xcopy /Y "%CD%\%root%\iSalary\formated\%%f" "%CD%\%root%\iSalary\%%f" 
)
rmdir /S /Q "%root%/iSalary/formated"