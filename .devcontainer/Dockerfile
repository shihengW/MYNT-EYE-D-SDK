FROM ros:kinetic-perception

# Install dependencies.
RUN apt-get update &&                                           \
    apt-get install -y ros-kinetic-rviz &&                      \
    git clone https://github.com/shihengW/MYNT-EYE-D-SDK.git && \
    make -C MYNT-EYE-D-SDK init &&                              \
    rm -rf MYNT-EYE-D-SDK 
    # Don't delete the lists due to required by 'make init'.
    # && rm -rf /var/lib/apt/lists/*
