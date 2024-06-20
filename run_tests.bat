@echo off
FOR /L %%i IN (1,1,1000) DO (
   .\msvc_build\AlgorithmTests
   IF ERRORLEVEL 1 (
      echo Test Run %%i: Fail
   ) ELSE (
      echo Test Run %%i: Pass
   )
)