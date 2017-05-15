## Tugas 4 Dokumentasi Enkripsi Key Menggunakan Algoritma RSA

Pendahuluan

RSA merupakan algoritma untuk enkripsi public key. algoritma ini juga algoritma yang pertama kali yang cocok digunakan untuk digital signature seperti halnya enkripsi. RSA juga masih digunakan secara luas dalam protokol e-commerce dan dipercaya dalam mengamankan dengan menggunakan kunci yang cukup panjang. Algorita RSA ini ditemukan oleh peneliti dari MIT (Massachussets Institute of Technology) yaitu Ron Rivest, Adi Shamir, dan Len Adleman pada tahun 1976.

Keamanan algoritma ini terletak pada sulitnya memfaktorkan bilangan yang besar menjadi faktor-faktor prima.

Algoritma RSA yaitu seperti dibawah ini :

1. Menentukan dua bilangan prima yaitu p dan q (bersifat rahasia)
2. Hitung nilai n yang diperoleh dari n = pq
3. Hitung nilai phi yang diperoleh dari phi(n) = (p-1)(q-1)
4. Pilih nilai e dengan syarat e > 1, dan GCD(e,phi)=1
5. Pilih nilai d dengan syarat (d.e) mod phi = 1
6. Private key (n,d) dan public key (n,e)

Contoh :
A akan mengirimkan pesan kepada B, B akan membuat sebuah kunci private dan public dengan nilai p dan q yang telah ditentukan dan bersifat rahasia. kunci akan dibuat oleh orang yang akan menerima pesan dan mengirimkan kunci public kepada si A sebagai pengirim pesan sedankan kunci private hanya dimiliki oleh si B sebgai penerima pesan. A menggunakan public key untuk mengengkripsikan pesan lalu B akan decrypt pesan tersebut menggunakan kunci private.   


sumber :
* http://teknosian.blogspot.co.id/2014/06/5-langkah-mudah-membuat-kunci-algoritma.html
* https://www.slideshare.net/KuliahKita/kriptografi-algoritma-rsa
* http://octarapribadi.blogspot.co.id/2016/02/enkripsi-dan-dekripsi-menggunakan-rsa.html
