#!/bin/bash
adduser --ingroup user42 $1
usermod -G sudo,user42 $1
