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

contraste: contraste.o pgm.o fft.o
	gcc $^  -o $@ $(LDFLAGS)

%.o:%.c
	gcc $(CFLAGS) $<

compare: etirement egalisation filtrageRetinien create_histogramme contraste
	./etirement ../aquitain.pgm  etire_aquitain.pgm
	./etirement ../couchersoleil.pgm etire_couchersoleil.pgm 
	./etirement ../muscle.pgm  etire_muscle.pgm
	./etirement ../pont.pgm etire_pont.pgm
	./egalisation ../aquitain.pgm  egal_aquitain.pgm
	./egalisation ../couchersoleil.pgm egal_couchersoleil.pgm 
	./egalisation ../muscle.pgm egal_muscle.pgm 
	./egalisation ../pont.pgm egal_pont.pgm
	./filtrageRetinien ../aquitain.pgm fil_aquitain.pgm
	./filtrageRetinien ../couchersoleil.pgm fil_couchersoleil.pgm
	./filtrageRetinien ../muscle.pgm fil_muscle.pgm 
	./filtrageRetinien ../pont.pgm fil_pont.pgm

clean: 
	rm *.o
	rm *.pgm
	rm *.txt
