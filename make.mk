#Make


grafica0.pdf : test.txt grafica.py
	python grafica.py

test.txt : a.out
	./a.out > test.txt

a.out : NicolasManrique_S13C2.cpp
	g++ NicolasManrique_S13C2.cpp
