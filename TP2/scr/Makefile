CFLAGS=-c -g -std=gnu99
LDFLAGS=-lm

essai2: essai2.o pgm.o fft.o
	gcc $^  -o $@ $(LDFLAGS)

gaussian: gaussian.o pgm.o fft.o
	gcc $^ -o $@ $(LDFLAGS)

convolGaussian: convolGaussian.o pgm.o fft.o
	gcc $^ -o $@ $(LDFLAGS)

median: median.o pgm.o fft.o
	gcc $^ -o $@ $(LDFLAGS)

%.o:%.c
	gcc $(CFLAGS) $<


clean: 
	rm *.o
	rm *.pgm
	rm *.txt

valgrinds: 
