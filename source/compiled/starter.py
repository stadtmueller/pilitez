#! /usr/bin/env python
#-*- coding: utf8 -*-

import os


returned = os.system( "./main" )
  
if returned == 0:
  print "\nProgram ended successfully. Returncode: " + str( returned )
else:
  print "\nProgram interrupted. Returncode: " + str( returned )
  

os.system( "./allof" )
