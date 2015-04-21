CFLAGS=-c -g -std=gnu99
LDFLAGS=-lm
Prewitt = 0
Sobel = 1
Laplacien1 = 0
Laplacien2 = 1
Laplacien3 = 2

gradient: gradient.o pgm.o fft.o gradient.h
	gcc $^ -o $@ $(LDFLAGS)

gradNaif: gradNaif.o pgm.o fft.o gradNaif.h
	gcc $^ -o $@ $(LDFLAGS)

laplacien: laplacien.o pgm.o fft.o laplacien.h
	gcc $^ -o $@ $(LDFLAGS)

laplacienDoG: laplacienDoG.o pgm.o fft.o laplacienDoG.h
	gcc $^ -o $@ $(LDFLAGS)

laplacienCouronne: laplacienCouronne.o pgm.o fft.o laplacienCouronne.h
	gcc $^ -o $@ $(LDFLAGS)

%.o:%.c
	gcc $(CFLAGS) $<

execGradPrewitt: gradient
	./gradient ../img/formes1bb5.pgm ../imgObtenu/gradientPrewitt_formes1bb5.pgm $(Prewitt)
	./gradient ../img/formes1bb10.pgm ../imgObtenu/gradientPrewitt_formes1bb10.pgm $(Prewitt)
	./gradient ../img/formes1bb25.pgm ../imgObtenu/gradientPrewitt_formes1bb25.pgm $(Prewitt)
	./gradient ../img/formes1c1.pgm ../imgObtenu/gradientPrewitt_formes1c1.pgm $(Prewitt)
	./gradient ../img/formes1c2.pgm ../imgObtenu/gradientPrewitt_formes1c2.pgm $(Prewitt)
	./gradient ../img/formes1sp.pgm ../imgObtenu/gradientPrewitt_formes1sp.pgm $(Prewitt)
	./gradient ../img/lacornou.pgm ../imgObtenu/gradientPrewitt_lacornou.pgm $(Prewitt)
	./gradient ../img/tangram.pgm ../imgObtenu/gradientPrewitt_tangram.pgm $(Prewitt)

execGradSobel: gradient
	./gradient ../img/formes1bb5.pgm ../imgObtenu/gradientSobel_formes1bb5.pgm $(Sobel)
	./gradient ../img/formes1bb10.pgm ../imgObtenu/gradientSobel_formes1bb10.pgm $(Sobel)
	./gradient ../img/formes1bb25.pgm ../imgObtenu/gradientSobel_formes1bb25.pgm $(Sobel)
	./gradient ../img/formes1c1.pgm ../imgObtenu/gradientSobel_formes1c1.pgm $(Sobel)
	./gradient ../img/formes1c2.pgm ../imgObtenu/gradientSobel_formes1c2.pgm $(Sobel)
	./gradient ../img/formes1sp.pgm ../imgObtenu/gradientSobel_formes1sp.pgm $(Sobel)
	./gradient ../img/lacornou.pgm ../imgObtenu/gradientSobel_lacornou.pgm $(Sobel)
	./gradient ../img/tangram.pgm ../imgObtenu/gradientSobel_tangram.pgm $(Sobel)

execGradNaif: gradNaif
	./gradNaif ../img/formes1bb5.pgm ../imgObtenu/gradNaif_formes1bb5.pgm $(Sobel)
	./gradNaif ../img/formes1bb10.pgm ../imgObtenu/gradNaif_formes1bb10.pgm $(Sobel)

execLaplacienDoG: laplacienDoG
	./laplacienDoG ../img/formes1bb5.pgm ../imgObtenu/laplacienDoG_formes1bb5.pgm
	./laplacienDoG ../img/formes1bb10.pgm ../imgObtenu/laplacienDoG_formes1bb10.pgm 
	./laplacienDoG ../img/formes1bb25.pgm ../imgObtenu/laplacienDoG_formes1bb25.pgm 
	./laplacienDoG ../img/formes1c1.pgm ../imgObtenu/laplacienDoG_formes1c1.pgm 
	./laplacienDoG ../img/formes1c2.pgm ../imgObtenu/laplacienDoG_formes1c2.pgm 
	./laplacienDoG ../img/formes1sp.pgm ../imgObtenu/laplacienDoG_formes1sp.pgm 
	./laplacienDoG ../img/lacornou.pgm ../imgObtenu/laplacienDoG_lacornou.pgm 
	./laplacienDoG ../img/tangram.pgm ../imgObtenu/laplacienDoG_tangram.pgm 

execLaplacien1: laplacien
	./laplacien ../img/formes1bb5.pgm ../imgObtenu/laplacien1_formes1bb5.pgm $(Laplacien1)
	./laplacien ../img/formes1bb10.pgm ../imgObtenu/laplacien1_formes1bb10.pgm $(Laplacien1)
	./laplacien ../img/formes1bb25.pgm ../imgObtenu/laplacien1_formes1bb25.pgm $(Laplacien1)
	./laplacien ../img/formes1c1.pgm ../imgObtenu/laplacien1_formes1c1.pgm $(Laplacien1)
	./laplacien ../img/formes1c2.pgm ../imgObtenu/laplacien1_formes1c2.pgm $(Laplacien1)
	./laplacien ../img/formes1sp.pgm ../imgObtenu/laplacien1_formes1sp.pgm $(Laplacien1)
	./laplacien ../img/lacornou.pgm ../imgObtenu/laplacien1_lacornou.pgm $(Laplacien1)
	./laplacien ../img/tangram.pgm ../imgObtenu/laplacien1_tangram.pgm $(Laplacien1)

execLaplacien2: laplacien
	./laplacien ../img/formes1bb5.pgm ../imgObtenu/laplacien2_formes1bb5.pgm $(Laplacien2)
	./laplacien ../img/formes1bb10.pgm ../imgObtenu/laplacien2_formes1bb10.pgm $(Laplacien2)
	./laplacien ../img/formes1bb25.pgm ../imgObtenu/laplacien2_formes1bb25.pgm $(Laplacien2)
	./laplacien ../img/formes1c1.pgm ../imgObtenu/laplacien2_formes1c1.pgm $(Laplacien2)
	./laplacien ../img/formes1c2.pgm ../imgObtenu/laplacien2_formes1c2.pgm $(Laplacien2)
	./laplacien ../img/formes1sp.pgm ../imgObtenu/laplacien2_formes1sp.pgm $(Laplacien2)
	./laplacien ../img/lacornou.pgm ../imgObtenu/laplacien2_lacornou.pgm $(Laplacien2)
	./laplacien ../img/tangram.pgm ../imgObtenu/laplacien2_tangram.pgm $(Laplacien2)

execLaplacien3: laplacien
	./laplacien ../img/formes1bb5.pgm ../imgObtenu/laplacien3_formes1bb5.pgm $(Laplacien3)
	./laplacien ../img/formes1bb10.pgm ../imgObtenu/laplacien3_formes1bb10.pgm $(Laplacien3)
	./laplacien ../img/formes1bb25.pgm ../imgObtenu/laplacien3_formes1bb25.pgm $(Laplacien3)
	./laplacien ../img/formes1c1.pgm ../imgObtenu/laplacien3_formes1c1.pgm $(Laplacien3)
	./laplacien ../img/formes1c2.pgm ../imgObtenu/laplacien3_formes1c2.pgm $(Laplacien3)
	./laplacien ../img/formes1sp.pgm ../imgObtenu/laplacien3_formes1sp.pgm $(Laplacien3)
	./laplacien ../img/lacornou.pgm ../imgObtenu/laplacien3_lacornou.pgm $(Laplacien3)
	./laplacien ../img/tangram.pgm ../imgObtenu/laplacien3_tangram.pgm $(Laplacien3)

execLaplacienCouronne: laplacienCouronne
	./laplacienCouronne ../img/formes1bb5.pgm ../imgObtenu/laplacienCouronne_formes1bb5.pgm
	./laplacienCouronne ../img/formes1bb10.pgm ../imgObtenu/laplacienCouronne_formes1bb10.pgm
	./laplacienCouronne ../img/formes1bb25.pgm ../imgObtenu/laplacienCouronne_formes1bb25.pgm 
	./laplacienCouronne ../img/formes1c1.pgm ../imgObtenu/laplacienCouronne_formes1c1.pgm 
	./laplacienCouronne ../img/formes1c2.pgm ../imgObtenu/laplacienCouronne_formes1c2.pgm 
	./laplacienCouronne ../img/formes1sp.pgm ../imgObtenu/laplacienCouronne_formes1sp.pgm 
	./laplacienCouronne ../img/lacornou.pgm ../imgObtenu/laplacienCouronne_lacornou.pgm 
	./laplacienCouronne ../img/tangram.pgm ../imgObtenu/laplacienCouronne_tangram.pgm 

clean:
	rm *.o

