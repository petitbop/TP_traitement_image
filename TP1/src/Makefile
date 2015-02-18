CFLAGS=-c -g -std=gnu99
LDFLAGS=-lm

essai1: essai1.o pgm.o
	gcc $(LDFLAGS)  $^  -o $@

essai2: essai2.o pgm.o fft.o
	gcc $^  -o $@ $(LDFLAGS)

etirement: etirement.o pgm.o fft.o
	gcc $^  -o $@ $(LDFLAGS)  

egalisation: egalisation.o pgm.o histogramme.o fft.o
	gcc $^ -o $@ $(LDFLAGS)

filtrageRetinien: filtrageRetinien.o pgm.o fft.o
	gcc $^  -o $@ $(LDFLAGS)

create_histogramme: create_histogramme.o histogramme.o pgm.o fft.o 
	gcc $^  -o $@ $(LDFLAGS)

%.o:%.c
	gcc $(CFLAGS) $<

clean: 
	rm *.o
