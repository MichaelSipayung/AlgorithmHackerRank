#!/bin/bash
for i in {1..100}
do
   ./build/AlgorithmTests
   if [ $? -eq 0 ]; then
      echo "Test Run $i: Pass"
   else
      echo "Test Run $i: Fail"
   fi
done