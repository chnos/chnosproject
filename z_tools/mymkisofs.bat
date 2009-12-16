@echo off
set _mkisofs_options=-J -joliet-long -D -input-charset sjis -verbose
set _is_udf=0
set  _has_V=0

:repeat
shift
if [%0]==[] goto end_repeat
if [%0]==[-udf] set _is_udf=1
if [%0]==[-V]   set  _has_V=1
set _mkisofs_options=%_mkisofs_options% %0
goto repeat
:end_repeat

if _is_udf==1 goto udf_ok
	echo Option '-udf', which is for a DVD, is not set. Are you sure?
	pause
:udf_ok

if _has_V==1 goto V_ok
	echo Volume title is not set with '-V'. Are you sure?
	pause
:V_ok

@echo on
mkisofs %_mkisofs_options%
