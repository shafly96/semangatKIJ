
# Tugas 1 – Enkripsi DES menggunakan metode OFB
KIJ F Kelompok F12 :
-	Farhan Ramadhana 5114100078
-	Shafly Naufal Adianto 5114100114

## Pendahuluan

Penggunaan teknologi informasi dan telekomunikasi pada saat ini telah mengubah cara pandang masyarakat dalam berkumunikasi. Pada saat ini pertukaran informasi sering sekali melibatkan penggunaan internet. Namun dengan demikian perlu diperhatikan tingkat keamanan informasi tersebut, karena pada saat ini penggunaan jaringan internet yang merupakan infrastuktur telekomunikasi dengan standar terbuka yang dapat dipergunakan oleh banyak pihak. Penyadapan informasi merupakan hal yang sangat merugikan bagi pengguna jaringan komunikasi saat ini.
Pada tugas kali ini adalah membuat sebuah program yang dapat mengekripsi dan dekripsi data dengan DES (data encryption standart)  dengan menggunakan metode OFB (Output Feedback).
Dasar Teori

### Keamanan jaringan

Dalam jaringan computer sangat penting dilakukan untuk memonitor akses jaringan dan mencegah penyalahgunaan sumber daya jaringan yang tidak sah. Keamanan jaringan suatu cara atau suatu sistem yang digunakan untuk memberikan proteksi atau perlindungan pada suatu jaringan agar terhindar dari berbagai ancaman luar yang mampu merusak jaringan.

### Kriptografi

Kriptografi merupakan salah satu teknik yang dapat meningkatkan keamanan informasi antara lain otentikasi dan kerahasiaan. Untuk menjaga kerahasiaan adalah dengan menjaga agar pesan tidak dapat dibaca oleh pihak yang tidak berhak yaitu melalui proses enkripsi dan dekripsi.

### Enkripsi dan Dekripsi

Proses enkripsi yaitu mengubah pesan asli (plaintext) menjadi pesan dalam bentuk tersandi (ciphertext). Proses enkripsi akan menghasilkan data tersandi dan hanya dapat dibuka atau dibaca oleh pihak penerima yang memiliki kunci (key) sedangkan proses dekripsi adalah mengembalikan data tersandi menjadi bentuk asli.

### DES (Data Encryption Standart)

DES merupakan algoritma enkripsi yang dikembangkan oleh NIST (National Institute of Standards and Technology) sebagai standar pengolahan informasi Federal AS. Secara umum, Data Encryption Standard (DES) terbagi menjadi tiga kelompok, yaitu pemrosesan kunci, enkripsi data 64 bit dan deskripsi data 64 bit, dimana satu kelompok saling berinteraksi satu dengan yang lainnya. Data dienkripsi dalam blok-blok 64 bit menggunakan kunci 56 bit, DES mentransformasikan input 64 bit dalam beberapa tahap enkripsi ke dalam output 64 bit. Dengan demikian, DES termasuk lama block cipher dengan tahapan pemakaian kunci yang sama untuk deskripsinya.

### OFB (Output Feedback)
Mode OFB mirip dengan mode CFB, kecuali n-bit dari hasil enkripsi terhadap antrian disalin menjadi elemen posisi paling kanan di antrian. Dekripsi dilakukan sebagai kebalikan dari proses enkripsi.

Langkah Pengerjaan enkripsi dengan Algoritma DES :

1. Ubahlah bentuk plaintext dan key menjadi kedalam bentuk biner 8 bit

2. Lakukan Initial Permutation pada bit plaintext menggunakan tabel IP  

3. Generate kunci yang akan digunakan untuk mengenkripsi plaintext dengan menggunakan tabel permutasi kompresi PC-1, pada langkah ini terjadi kompresi dengan membuang 1 bit masing-masing blok kunci dari 64 bit menjadi 56 bit. lalu memecah menjadi dua sisi yaitu sisi kiri dan kanan dengan pembagian yang sama rata

4. Lakukan pergeseran kiri (Left Shift) pada C0 dan D0, sebanyak 1 atau 2 kali berdasarkan kali putaran yang ada pada tabel putaran sebagai berikut

5. Pada langkah ini, kita akan meng-ekspansi data Ri-1 32 bit menjadi Ri 48 bit sebanyak 16 kali putaran dengan nilai perputaran 1<= i <=16 menggunakan Tabel Ekspansi (E).

6. Setiap Vektor Ai disubstitusikan kedelapan buah S-Box(Substitution Box), dimana blok pertama disubstitusikan dengan S1, blok kedua dengan S2 dan seterusnya dan menghasilkan output vektor Bi 32 bit.

7. Setelah didapatkan nilai vektor Bi, langkah selanjutnya adalah memutasikan bit vektor Bi menggunakan tabel P-Box, kemudian dikelompokkan menjadi 4 blok dimana tiap-tiap blok memiliki 32 bit data.

8. Langkah terakhir adalah menggabungkan R16 dengan L16 kemudian dipermutasikan untuk terakhir kali dengan tabel Invers Initial Permutasi(IP-1).

Metode OFB untuk enkripsi sebagai berikut :

1. Masukkan plaintext dan key untuk enkripsi DES
2. Plaintext di XOR kan dengan hasil enkripsi sebelumnya menghasilkan ciphertext

Metode OFB untuk dekripsi sebagai berikut :

1. Cypher text akan di XOR kan dengan hasil dari DES

Contoh input plaintext : COMPUTER

Menghasilkan Output:
Cipher(dalam biner) :

01010110 11110001 11010101 11001000 01010010 10101111 10000001 00111111
=======
# Tugas 1 – Enkripsi DES menggunakan metode OBF
KIJ F Kelompok F12 :
-	Farhan Ramadhana 5114100078
-	Shafly Naufal Adianto 5114100114

## Pendahuluan

Penggunaan teknologi informasi dan telekomunikasi pada saat ini telah mengubah cara pandang masyarakat dalam berkumunikasi. Pada saat ini pertukaran informasi sering sekali melibatkan penggunaan internet. Namun dengan demikian perlu diperhatikan tingkat keamanan informasi tersebut, karena pada saat ini penggunaan jaringan internet yang merupakan infrastuktur telekomunikasi dengan standar terbuka yang dapat dipergunakan oleh banyak pihak. Penyadapan informasi merupakan hal yang sangat merugikan bagi pengguna jaringan komunikasi saat ini.
Pada tugas kali ini adalah membuat sebuah program yang dapat mengekripsi dan dekripsi data dengan DES (data encryption standart)  dengan menggunakan metode OFB (Output Feedback).
Dasar Teori

### Keamanan jaringan

Dalam jaringan computer sangat penting dilakukan untuk memonitor akses jaringan dan mencegah penyalahgunaan sumber daya jaringan yang tidak sah. Keamanan jaringan suatu cara atau suatu sistem yang digunakan untuk memberikan proteksi atau perlindungan pada suatu jaringan agar terhindar dari berbagai ancaman luar yang mampu merusak jaringan.

### Kriptografi

Kriptografi merupakan salah satu teknik yang dapat meningkatkan keamanan informasi antara lain otentikasi dan kerahasiaan. Untuk menjaga kerahasiaan adalah dengan menjaga agar pesan tidak dapat dibaca oleh pihak yang tidak berhak yaitu melalui proses enkripsi dan dekripsi.

### Enkripsi dan Dekripsi

Proses enkripsi yaitu mengubah pesan asli (plaintext) menjadi pesan dalam bentuk tersandi (ciphertext). Proses enkripsi akan menghasilkan data tersandi dan hanya dapat dibuka atau dibaca oleh pihak penerima yang memiliki kunci (key) sedangkan proses dekripsi adalah mengembalikan data tersandi menjadi bentuk asli.

### DES (Data Encryption Standart)

DES merupakan algoritma enkripsi yang dikembangkan oleh NIST (National Institute of Standards and Technology) sebagai standar pengolahan informasi Federal AS. Secara umum, Data Encryption Standard (DES) terbagi menjadi tiga kelompok, yaitu pemrosesan kunci, enkripsi data 64 bit dan deskripsi data 64 bit, dimana satu kelompok saling berinteraksi satu dengan yang lainnya. Data dienkripsi dalam blok-blok 64 bit menggunakan kunci 56 bit, DES mentransformasikan input 64 bit dalam beberapa tahap enkripsi ke dalam output 64 bit. Dengan demikian, DES termasuk lama block cipher dengan tahapan pemakaian kunci yang sama untuk deskripsinya.

### OFB (Output Feedback)
Mode OFB mirip dengan mode CFB, kecuali n-bit dari hasil enkripsi terhadap antrian disalin menjadi elemen posisi paling kanan di antrian. Dekripsi dilakukan sebagai kebalikan dari proses enkripsi.

Langkah Pengerjaan enkripsi dengan Algoritma DES :

1. Ubahlah bentuk plaintext dan key menjadi kedalam bentuk biner 8 bit

2. Lakukan Initial Permutation pada bit plaintext menggunakan tabel IP  

3. Generate kunci yang akan digunakan untuk mengenkripsi plaintext dengan menggunakan tabel permutasi kompresi PC-1, pada langkah ini terjadi kompresi dengan membuang 1 bit masing-masing blok kunci dari 64 bit menjadi 56 bit. lalu memecah menjadi dua sisi yaitu sisi kiri dan kanan dengan pembagian yang sama rata

4. Lakukan pergeseran kiri (Left Shift) pada C0 dan D0, sebanyak 1 atau 2 kali berdasarkan kali putaran yang ada pada tabel putaran sebagai berikut

5. Pada langkah ini, kita akan meng-ekspansi data Ri-1 32 bit menjadi Ri 48 bit sebanyak 16 kali putaran dengan nilai perputaran 1<= i <=16 menggunakan Tabel Ekspansi (E).

6. Setiap Vektor Ai disubstitusikan kedelapan buah S-Box(Substitution Box), dimana blok pertama disubstitusikan dengan S1, blok kedua dengan S2 dan seterusnya dan menghasilkan output vektor Bi 32 bit.

7. Setelah didapatkan nilai vektor Bi, langkah selanjutnya adalah memutasikan bit vektor Bi menggunakan tabel P-Box, kemudian dikelompokkan menjadi 4 blok dimana tiap-tiap blok memiliki 32 bit data.

8. Langkah terakhir adalah menggabungkan R16 dengan L16 kemudian dipermutasikan untuk terakhir kali dengan tabel Invers Initial Permutasi(IP-1).

Metode OFB untuk enkripsi sebagai berikut :

1. Masukkan plaintext dan key untuk enkripsi DES
2. Plaintext di XOR kan dengan hasil enkripsi sebelumnya menghasilkan ciphertext

Metode OFB untuk dekripsi sebagai berikut :

1. Cypher text akan di XOR kan dengan hasil dari DES

Contoh input plaintext : COMPUTER

Menghasilkan Output:
Cipher(dalam biner) :

01010110 11110001 11010101 11001000 01010010 10101111 10000001 00111111

referensi : http://octarapribadi.blogspot.co.id/2012/10/contoh-enkripsi-dengan-algoritma-des.html
