# Nama file output
OUTPUT = maple

# Kompile kode C++
$(OUTPUT): maple.cpp
	g++ -framework GLUT -framework OpenGL -Wno-deprecated-declarations maple.cpp -o $(OUTPUT)

# Bersihkan file output dan file objek
clean:
	rm -f $(OUTPUT)
	