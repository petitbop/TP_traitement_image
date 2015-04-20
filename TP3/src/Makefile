CFLAGS=-c -g -std=gnu99
LDFLAGS=-lm
Prewitt = 0
Sobel = 1

gradient: gradient.o pgm.o fft.o gradient.h
	gcc $^ -o $@ $(LDFLAGS)

gradNaif: gradNaif.o pgm.o fft.o gradNaif.h
	gcc $^ -o $@ $(LDFLAGS)

laplacien: laplacien.o pgm.o fft.o laplacien.h
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
	./gradient ../img/lacornou.pgm ../imgObtenu/gradientPrewitt_lacornou.pgm $(Sobel)
	./gradient ../img/tangram.pgm ../imgObtenu/gradientPrewitt_tangram.pgm $(Sobel)

execGradNaif: gradNaif
	./gradNaif ../img/formes1bb5.pgm ../imgObtenu/gradNaif_formes1bb5.pgm $(Sobel)

execLaplacien: laplacien
	./laplacien ../img/formes1bb5.pgm ../imgObtenu/laplacien_formes1bb5.pgm
	./laplacien ../img/formes1bb10.pgm ../imgObtenu/laplacien_formes1bb10.pgm 
	./laplacien ../img/formes1bb25.pgm ../imgObtenu/laplacien_formes1bb25.pgm 
	./laplacien ../img/formes1c1.pgm ../imgObtenu/laplacien_formes1c1.pgm 
	./laplacien ../img/formes1c2.pgm ../imgObtenu/laplacien_formes1c2.pgm 
	./laplacien ../img/formes1sp.pgm ../imgObtenu/laplacien_formes1sp.pgm 
	./laplacien ../img/lacornou.pgm ../imgObtenu/laplacien_lacornou.pgm 
	./laplacien ../img/tangram.pgm ../imgObtenu/laplacien_tangram.pgm 

