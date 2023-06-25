# Nama file output
OUTPUT = gambar3d

# Kompile kode C++
$(OUTPUT): gambar3d.cpp
	g++ -framework GLUT -framework OpenGL -Wno-deprecated-declarations gambar3d.cpp -o $(OUTPUT)

# Bersihkan file output dan file objek
clean:
	rm -f $(OUTPUT)
	