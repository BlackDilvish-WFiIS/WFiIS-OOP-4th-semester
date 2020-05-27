#!/bin/bash

#=====================================
#=== My bash script that creates source files  ===
#===    for given classes (as a parameters)     ===
#=====================================

# Adding include directory if not exists
if ! find include 1>/dev/null 2>/dev/null
	then
		mkdir include
fi

#Adding src directory if not exists
if ! find src 1>/dev/null 2>/dev/null
	then
		mkdir src
fi

#Creating class's files in proper directories
for var in "$@"
do
	echo "Tworzenie klasy $var"
	touch include/$var.h
	touch src/$var.cpp
	
	#Filling *.h files
	echo -e "#pragma once\n\n#include<iostream>\n" > include/$var.h
	echo -e "class $var\n{\npublic:"	      >> include/$var.h
	echo -e "\t$var();\n\t~$var();\n"  	      >> include/$var.h
	echo -e "private:\n\n};"		      >> include/$var.h

	#Filling *.cpp files
	echo -e "#include\"$var.h\"\n" 		       > src/$var.cpp
	echo -e "$var::$var()\n{\n\n}\n"              >> src/$var.cpp
	echo -e "$var::~$var()\n{\n\n}\n"	      >> src/$var.cpp
done
