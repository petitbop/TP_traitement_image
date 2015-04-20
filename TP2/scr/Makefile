EXEC=gaussian convolGaussianSeparable convolGaussian median adapt bilat
SIG1=20
SIG2=50
K=5
N=3
W=5
CFLAGS=-c -g -std=gnu99
LDFLAGS=-lm

compile: $(EXEC)

essai2: essai2.o pgm.o fft.o psnr.o
	gcc $^  -o $@ $(LDFLAGS)

gaussian: gaussian.o pgm.o fft.o psnr.o
	gcc $^ -o $@ $(LDFLAGS)

convolGaussianSeparable: convolGaussianSeparable.o pgm.o fft.o psnr.o
	gcc $^ -o $@ $(LDFLAGS)

convolGaussian: convolGaussian.o pgm.o fft.o psnr.o
	gcc $^ -o $@ $(LDFLAGS)

median: median.o pgm.o fft.o psnr.o
	gcc $^ -o $@ $(LDFLAGS)

adapt: adapt.o pgm.o fft.o psnr.o
	gcc $^ -o $@ $(LDFLAGS)

bilat: bilat.o pgm.o fft.o psnr.o 
	gcc $^ -o $@ $(LDFLAGS)

%.o:%.c
	gcc $(CFLAGS) $<

execbilat: bilat 
	./bilat ../formes1bb10.pgm bilat_formes1bb10_$(SIG1)_$(SIG2).pgm $(SIG1) $(SIG2)  
	./bilat ../formes1c2.pgm bilat_formes1c2_$(SIG1)_$(SIG2).pgm $(SIG1) $(SIG2)
	./bilat ../formes1pets5.pgm bilat_formes1pets5_$(SIG1)_$(SIG2).pgm $(SIG1) $(SIG2) 
	./bilat ../formes1bb25.pgm bilat_formes1bb25_$(SIG1)_$(SIG2).pgm $(SIG1) $(SIG2) 
	./bilat ../formes1g.pgm bilat_formes1g_$(SIG1)_$(SIG2).pgm $(SIG1) $(SIG2) 
	./bilat ../formes1.pgm bilat_formes1_$(SIG1)_$(SIG2).pgm $(SIG1) $(SIG2) 
	./bilat ../formes1bb5.pgm bilat_formes1bb5_$(SIG1)_$(SIG2).pgm $(SIG1) $(SIG2) 
	./bilat ../formes1pets10.pgm bilat_formes1pets10_$(SIG1)_$(SIG2).pgm $(SIG1) $(SIG2) 
	./bilat ../formes1sp.pgm bilat_formes1sp_$(SIG1)_$(SIG2).pgm $(SIG1) $(SIG2) 
	./bilat ../tangram.pgm bilat_tangram_$(SIG1)_$(SIG2).pgm $(SIG1) $(SIG2) 
	./bilat ../formes1c1.pgm bilat_formes1c1_$(SIG1)_$(SIG2).pgm $(SIG1) $(SIG2) 
	./bilat ../formes1pets1.pgm bilat_formes1pets1_$(SIG1)_$(SIG2).pgm $(SIG1) $(SIG2) 
	./bilat ../lacornou.pgm bilat_lacornou_$(SIG1)_$(SIG2).pgm $(SIG1) $(SIG2) 

execadapt: adapt
	./adapt ../formes1bb10.pgm adapt_formes1bb10_$(K).pgm $(K)  
	./adapt ../formes1c2.pgm adapt_formes1c2_$(K).pgm $(K)
	./adapt ../formes1pets5.pgm adapt_formes1pets5_$(K).pgm $(K) 
	./adapt ../formes1bb25.pgm adapt_formes1bb25_$(K).pgm $(K) 
	./adapt ../formes1g.pgm adapt_formes1g_$(K).pgm $(K) 
	./adapt ../formes1.pgm adapt_formes1_$(K).pgm $(K) 
	./adapt ../formes1bb5.pgm adapt_formes1bb5_$(K).pgm $(K) 
	./adapt ../formes1pets10.pgm adapt_formes1pets10_$(K).pgm $(K) 
	./adapt ../formes1sp.pgm adapt_formes1sp_$(K).pgm $(K) 
	./adapt ../tangram.pgm adapt_tangram_$(K).pgm $(K) 
	./adapt ../formes1c1.pgm adapt_formes1c1_$(K).pgm $(K) 
	./adapt ../formes1pets1.pgm adapt_formes1pets1_$(K).pgm $(K) 
	./adapt ../lacornou.pgm adapt_lacornou_$(K).pgm $(K)

execmedian: median
	./median ../formes1bb10.pgm median_formes1bb10_$(N).pgm $(N)  
	./median ../formes1c2.pgm median_formes1c2_$(N).pgm $(N)
	./median ../formes1pets5.pgm median_formes1pets5_$(N).pgm $(N) 
	./median ../formes1bb25.pgm median_formes1bb25_$(N).pgm $(N) 
	./median ../formes1g.pgm median_formes1g_$(N).pgm $(N) 
	./median ../formes1.pgm median_formes1_$(N).pgm $(N) 
	./median ../formes1bb5.pgm median_formes1bb5_$(N).pgm $(N) 
	./median ../formes1pets10.pgm median_formes1pets10_$(N).pgm $(N) 
	./median ../formes1sp.pgm median_formes1sp_$(N).pgm $(N) 
	./median ../tangram.pgm median_tangram_$(N).pgm $(N) 
	./median ../formes1c1.pgm median_formes1c1_$(N).pgm $(N) 
	./median ../formes1pets1.pgm median_formes1pets1_$(N).pgm $(N) 
	./median ../lacornou.pgm median_lacornou_$(N).pgm $(N)
execconvolGaussian: convolGaussian
	./convolGaussian ../formes1bb10.pgm convolGaussian_formes1bb10.pgm $(SIG1) $(W)  
	./convolGaussian ../formes1c2.pgm convolGaussian_formes1c2.pgm $(SIG1) $(W) 
	./convolGaussian ../formes1pets5.pgm convolGaussian_formes1pets5.pgm $(SIG1) $(W)  
	./convolGaussian ../formes1bb25.pgm convolGaussian_formes1bb25.pgm $(SIG1) $(W) 
	./convolGaussian ../formes1g.pgm convolGaussian_formes1g.pgm $(SIG1) $(W) 
	./convolGaussian ../formes1.pgm convolGaussian_formes1.pgm $(SIG1) $(W) 
	./convolGaussian ../formes1bb5.pgm convolGaussian_formes1bb5.pgm $(SIG1) $(W) 
	./convolGaussian ../formes1pets10.pgm convolGaussian_formes1pets10.pgm $(SIG1) $(W) 
	./convolGaussian ../formes1sp.pgm convolGaussian_formes1sp.pgm $(SIG1) $(W) 
	./convolGaussian ../tangram.pgm convolGaussian_tangram.pgm $(SIG1) $(W) 
	./convolGaussian ../formes1c1.pgm convolGaussian_formes1c1.pgm $(SIG1) $(W) 
	./convolGaussian ../formes1pets1.pgm convolGaussian_formes1pets1.pgm $(SIG1) $(W)  
	./convolGaussian ../lacornou.pgm convolGaussian_lacornou.pgm $(SIG1) $(W) 

execconvolGaussianSeparable: convolGaussianSeparable
	./convolGaussianSeparable ../formes1bb10.pgm convolGaussianSeparable_formes1bb10.pgm $(SIG1) $(W) 
	./convolGaussianSeparable ../formes1c2.pgm convolGaussianSeparable_formes1c2.pgm $(SIG1) $(W) 
	./convolGaussianSeparable ../formes1pets5.pgm convolGaussianSeparable_formes1pets5.pgm $(SIG1) $(W)  
	./convolGaussianSeparable ../formes1bb25.pgm convolGaussianSeparable_formes1bb25.pgm $(SIG1) $(W)  
	./convolGaussianSeparable ../formes1g.pgm convolGaussianSeparable_formes1g.pgm $(SIG1) $(W) 
	./convolGaussianSeparable ../formes1.pgm convolGaussianSeparable_formes1.pgm $(SIG1) $(W)
	./convolGaussianSeparable ../formes1bb5.pgm convolGaussianSeparable_formes1bb5.pgm $(SIG1) $(W)
	./convolGaussianSeparable ../formes1pets10.pgm convolGaussianSeparable_formes1pets10.pgm $(SIG1) $(W)  
	./convolGaussianSeparable ../formes1sp.pgm convolGaussianSeparable_formes1sp.pgm $(SIG1) $(W)
	./convolGaussianSeparable ../tangram.pgm convolGaussianSeparable_tangram.pgm $(SIG1) $(W)
	./convolGaussianSeparable ../formes1c1.pgm convolGaussianSeparable_formes1c1.pgm $(SIG1) $(W)
	./convolGaussianSeparable ../formes1pets1.pgm convolGaussianSeparable_formes1pets1.pgm $(SIG1) $(W)  
	./convolGaussianSeparable ../lacornou.pgm convolGaussianSeparable_lacornou.pgm $(SIG1) $(W)

execgaussian: gaussian
	./gaussian ../formes1bb10.pgm gaussian_formes1bb10.pgm $(SIG1)   
	./gaussian ../formes1c2.pgm gaussian_formes1c2.pgm $(SIG1)  
	./gaussian ../formes1pets5.pgm gaussian_formes1pets5.pgm $(SIG1)   
	./gaussian ../formes1bb25.pgm gaussian_formes1bb25.pgm $(SIG1)  
	./gaussian ../formes1g.pgm gaussian_formes1g.pgm $(SIG1)  
	./gaussian ../formes1.pgm gaussian_formes1.pgm $(SIG1)  
	./gaussian ../formes1bb5.pgm gaussian_formes1bb5.pgm $(SIG1) 
	./gaussian ../formes1pets10.pgm gaussian_formes1pets10.pgm $(SIG1) 
	./gaussian ../formes1sp.pgm gaussian_formes1sp.pgm $(SIG1)  
	./gaussian ../tangram.pgm gaussian_tangram.pgm $(SIG1)  
	./gaussian ../formes1c1.pgm gaussian_formes1c1.pgm $(SIG1) 
	./gaussian ../formes1pets1.pgm gaussian_formes1pets1.pgm $(SIG1) 
	./gaussian ../lacornou.pgm gaussian_lacornou.pgm $(SIG1)

execall: execmedian execconvolGaussian execconvolGaussianSeparable execgaussian execbilat execadapt 

displaygaussian : execgaussian
	display gaussian_formes1bb10.pgm &
	display gaussian_formes1c2.pgm & 
	display gaussian_formes1pets5.pgm &
	display gaussian_formes1bb25.pgm &
	display gaussian_formes1g.pgm &
	display gaussian_formes1.pgm &
	display gaussian_formes1bb5.pgm &
	display gaussian_formes1pets10.pgm &
	display gaussian_formes1sp.pgm &
	display gaussian_tangram.pgm &
	display gaussian_formes1c1.pgm &
	display gaussian_formes1pets1.pgm &
	display gaussian_lacornou.pgm &

clean: 
	rm $(EXEC)
	rm *.o
	rm *.pgm
	rm *.txt

valgrinds: 
