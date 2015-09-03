FROM ubuntu:14.04
MAINTAINER Tobias Haar

RUN apt-get update -qq
RUN apt-get install -y build-essential
RUN apt-get install -y software-properties-common

# CMake 3.2
RUN add-apt-repository -y ppa:george-edison55/cmake-3.x
RUN apt-get update -qq
RUN apt-get install -y cmake

# pkg-config
RUN apt-get install -y pkg-config
ENV PKG_CONFIG_PATH /usr/lib/pkgconfig:/usr/share/pkgconfig:/usr/local/lib/pkgconfig:/usr/local/share/pkgconfig

# OpenGL
RUN apt-get install -y xorg-dev libglu1-mesa-dev

# log4cxx
RUN apt-get install -y liblog4cxx10 liblog4cxx10-dev

# QT 5.4
RUN add-apt-repository -y ppa:beineri/opt-qt541-trusty
RUN apt-get update -qq
RUN apt-get install -y qt54base
ENV CMAKE_PREFIX_PATH /opt/qt54

# Doxygen
RUN apt-get install -y doxygen

RUN apt-get install -y git
RUN apt-get install -y libfreetype6 libfreetype6-dev
