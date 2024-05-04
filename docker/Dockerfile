# build opencv
FROM gcc:latest

WORKDIR /src

RUN apt update && apt install -y cmake g++ wget unzip
RUN wget -O opencv.zip https://github.com/opencv/opencv/archive/4.x.zip
RUN unzip opencv.zip
RUN mkdir -p build && cd build && cmake -D OPENCV_GENERATE_PKGCONFIG=YES ../opencv-4.x && cmake --build .

RUN cd build && make install
# ENV LD_LIBRARY_PATH usr/lib
# TODO: this is probably a really weird place to be putting openCV lib files...

# missing step, this feels like a hack
# https://stackoverflow.com/questions/12335848/opencv-program-compile-error-libopencv-core-so-2-4-cannot-open-shared-object-f
RUN echo "/usr/local/lib" > /etc/ld.so.conf.d/opencv.conf
RUN ldconfig -v

# Set the working directory inside the container
WORKDIR /usr/src/program

# Copy everything from src/ on the host machine to /usr/src/program in the base image
# Copy everything from src into program dir
COPY src /usr/src/program

# Compile everything in /usr/src/program
RUN g++ -o out *.cpp `pkg-config opencv4 --cflags --libs`
# RUN g++ -o out *.cpp -Wl,-rpath,usr/lib -lopencv_core


# Run the executable
CMD ["./out"]