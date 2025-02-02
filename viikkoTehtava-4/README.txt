BANKA HESAP YÖNETİM SİSTEMİ
------------------------

Bu program basit bir banka hesap yönetim sistemidir.

Programı Derlemek İçin:
----------------------
Terminal veya komut isteminde aşağıdaki komutu yazın:

g++ -std=c++11 -o pankkiohjelma main.cpp Pankkitili.cpp Luottotili.cpp Asiakas.cpp

Programı Çalıştırmak İçin:
-------------------------
Derleme işleminden sonra aşağıdaki komutu yazın:

./pankkiohjelma

Program Kullanımı:
---------------
Program menü tabanlıdır ve şu seçenekleri sunar:
1: Yeni müşteri oluştur
2: Para yatır
3: Para çek
4: Bakiye göster
5: Kredi çek
6: Kredi öde
7: Para transferi yap
0: Programdan çık

Not: Program çıktıları Fince'dir:
- "saldo" = bakiye
- "talletus" = para yatırma
- "nosto" = para çekme
- "luotto" = kredi
- "tilisiirto" = para transferi
- "onnistui" = başarılı
- "epaonnistui" = başarısız

Uyarılar Hakkında:
----------------
Eğer derleme sırasında C++11 ile ilgili uyarılar görürseniz endişelenmeyin, 
bu uyarılar programın çalışmasını etkilemez. Bu uyarıları görmemek için 
yukarıdaki derleme komutunda belirtildiği gibi -std=c++11 parametresini kullanın. 