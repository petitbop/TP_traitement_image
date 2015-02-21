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
	./create_histogramme ../aquitain.pgm hist_aquitain.txt 
	./create_histogramme ../couchersoleil.pgm hist_couchersoleil.txt 
	./create_histogramme ../muscle.pgm hist_muscle.txt 
	./create_histogramme ../pont.pgm hist_pont.txt
	@echo "AQUITAIN \n" 
	./contraste ../aquitain.pgm
	@echo "etirement \n" 
	./contraste etire_aquitain.pgm
	@echo "egalisation \n"
	./contraste egal_aquitain.pgm
	@echo "filtrage retinien \n"
	./contraste fil_aquitain.pgm
	@echo "MUSCLE \n" 
	./contraste ../muscle.pgm
	@echo "etirement \n" 
	./contraste etire_muscle.pgm
	@echo "egalisation \n"
	./contraste egal_muscle.pgm
	@echo "filtrage retinien \n"
	./contraste fil_muscle.pgm
	@echo "PONT \n" 
	./contraste ../pont.pgm
	@echo "etirement \n" 
	./contraste etire_pont.pgm
	@echo "egalisation \n"
	./contraste egal_pont.pgm
	@echo "filtrage retinien \n"
	./contraste fil_pont.pgm
	@echo "COUCHERSOLEIL \n" 
	./contraste ../couchersoleil.pgm
	@echo "etirement \n" 
	./contraste etire_couchersoleil.pgm
	@echo "egalisation \n"
	./contraste egal_couchersoleil.pgm
	@echo "filtrage retinien \n"
	./contraste fil_couchersoleil.pgm

clean: 
	rm *.o
	rm *.pgm
	rm *.txt

valgrinds: etirement egalisation filtrageRetinien create_histogramme contraste
	valgrind ./etirement ../aquitain.pgm  etire_aquitain.pgm
	valgrind ./egalisation ../aquitain.pgm  egal_aquitain.pgm
	valgrind ./filtrageRetinien ../aquitain.pgm fil_aquitain.pgm
	valgrind ./create_histogramme ../aquitain.pgm hist_aquitain.txt
	valgrind ./contraste ../aquitain.pgm
