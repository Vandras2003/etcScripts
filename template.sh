#!/bin/sh
for FILENAME in $@
do
	cp basic.cpp $FILENAME.cpp
done
