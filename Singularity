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

apt-get install -y --no-install-recommends apt-utils

# Install cmake
cd /usr/local/
wget https://cmake.org/files/v3.4/cmake-3.4.1-Linux-x86_64.tar.gz
tar xvf cmake-3.4.1-Linux-x86_64.tar.gz
export PATH="`pwd`/cmake-3.4.1-Linux-x86_64/bin:$PATH"
rm -rf cmake-3.4.1-Linux-x86_64.tar.gz

#Install Python 3
#apt-get install -y python3
#pip3 install numpy scipy matplotlib sphinx
#export PATH="`pwd`/python3/bin:$PATH"

apt install build-essential checkinstall
apt install libreadline-gplv2-dev libncursesw5-dev libssl-dev libsqlite3-dev tk-dev libgdbm-dev libc6-dev libbz2-dev
wget https://www.python.org/ftp/python/3.6.0/Python-3.6.0.tar.xz
tar xvf Python-3.6.0.tar.xz
cd Python-3.6.0/
./configure
sudo make altinstall

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
