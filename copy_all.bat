@ECHO OFF

:INPUT_START
ECHO SET ABC???
SET ABC_STR=
SET /P ABC_STR=
IF "%ABC_STR%"=="" GOTO :INPUT_START

xcopy /e /y default ABC%ABC_STR%\
echo D | xcopy /e /y ABC%ABC_STR%\A ABC%ABC_STR%\B
echo D | xcopy /e /y ABC%ABC_STR%\A ABC%ABC_STR%\C
echo D | xcopy /e /y ABC%ABC_STR%\A ABC%ABC_STR%\D
echo D | xcopy /e /y ABC%ABC_STR%\A ABC%ABC_STR%\E 