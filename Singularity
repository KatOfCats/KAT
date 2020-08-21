Bootstrap: docker
From: gcc:5.5.0
IncludeCmd: yes

%setup
# Copy any necessary files 

%environment
 # Use bash as default shell
    SHELL=/bin/bash

    # Add paths
    PATH="/usr/local/KAT/bin:$PATH"

    # Export paths
    export PATH


%post
    # Make gpfs folder to hold mount
    mkdir /gpfs
    mkdir /shared
    mkdir /local
    mkdir /scratch
    # Create and move to build directory
    mkdir /root/build && cd /root/build

# run OS updates
apt-get update -y  && apt-get upgrade -y

# Install cmake
cd /usr/local/
wget https://cmake.org/files/v3.4/cmake-3.4.1-Linux-x86_64.tar.gz
tar xvf cmake-3.4.1-Linux-x86_64.tar.gz
export PATH="`pwd`/cmake-3.4.1-Linux-x86_64/bin:$PATH"
rm -rf cmake-3.4.1-Linux-x86_64.tar.gz

#Install Python 3
apt-get install -y python3

# Install KAT
git clone https://github.com/TGAC/KAT.git
cd KAT
./build_boost.sh
./autogen.sh
./configure
make
make install

%labels
 edited from HPC UEA Team  hpc.admin@uea.ac.uk