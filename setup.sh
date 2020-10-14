SCRIPT_PATH="$( cd "$(dirname "$0")" >/dev/null 2>&1 ; pwd -P )"
CALLER_PATH=$(pwd)

echo -e "\e[1;32m
############################################################
# This script will walk you through setting up the camera. #
# Note that some of the operations requiring plugging in   #
# or out the camera, which will be notified and will wait  #
# until complete.                                          #
############################################################\e[0m"

echo -e "\e[1;32m

# STEP 1: make init...\e[1;31m
# YOU MUST plugin the device before continue, press any
# buttom when you done...\e[0m"

read -n 1 # wait for keypress.
cd $SCRIPT_PATH
apt update && echo y | make init

echo -e "\e[1;32m

# STEP 2: make all...\e[1;31m
# MUST plugout and plugin again before continue, press
# any buttom when you done...\e[0m"

read -n 1 # wait for keypress.
cd $SCRIPT_PATH
source /opt/ros/kinetic/setup.bash
echo y | make all

echo -e "\e[1;32m
# STEP 3: Generate parameters.\e[0m"
cd $SCRIPT_PATH
./samples/_output/bin/get_img_params
./samples/_output/bin/get_imu_params
cd $CALLER_PATH