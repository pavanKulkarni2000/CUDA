all:
	nvcc -lcuda -lcublas *.cu -o ResNet  -arch=sm_37 -Wno-deprecated-gpu-targets `pkg-config --cflags --libs opencv`

run:
	./ResNet
clean:
	rm ResNet
